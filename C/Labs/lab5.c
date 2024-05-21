#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define BYTE_SIZE 8
#define TWO_BYTE_SIZE 16

typedef struct Huffman_tree {
    wchar_t symbol;
    unsigned long long code;
    int length;
} Huffman_tree;

typedef struct Bit_stream {
    FILE *file;
    wchar_t data;
    int pos;
} Bit_stream;

typedef struct Node {
    wchar_t symbol;
    int freq;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct pqueue {
    int size;
    struct Node **heap;
} Prior_queue;

typedef enum error {
    noError,
    readingError,
} Error;

Bit_stream *create_stream(FILE *file) {
    Bit_stream *stream = malloc(sizeof(Bit_stream));
    if (!stream) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    stream->file = file;
    stream->data = 0;
    stream->pos = 0;
    return stream;
}

void write_bit(int bit, Bit_stream *stream) {
    if (stream->pos == BYTE_SIZE) {
        fwrite(&(stream->data), sizeof(char), 1, stream->file);
        stream->pos = 0;
        stream->data = 0;
    }
    stream->data = bit | (stream->data << 1);
    stream->pos++;
}

void write_symbol(wchar_t symbol, Bit_stream *stream) {
    for (int i = TWO_BYTE_SIZE - 1; i >= 0; i--) {
        int bit = (symbol >> i) & 1;
        write_bit(bit, stream);
    }
}

Error read_bit(int *bit, Bit_stream *stream) {
    if (stream->pos == 0) {
        if (fread(&stream->data, sizeof(char), 1, stream->file) != 1)
            return readingError;
        stream->pos = BYTE_SIZE;
    }
    stream->pos -= 1;
    *bit = (stream->data >> stream->pos) & 1;
    return noError;
}

Error read_symbol(wchar_t *symbol, Bit_stream *stream) {
    *symbol = 0;
    for (int i = 0; i < TWO_BYTE_SIZE; i++) {
        *symbol = *symbol << 1;
        int bit;
        if (read_bit(&bit, stream) == readingError)
            return readingError;
        *symbol = *symbol | bit;
    }
    return noError;
}

void clear_stream(Bit_stream *stream) {
    stream->data = stream->data << (BYTE_SIZE - stream->pos);
    fwrite(&(stream->data), sizeof(char), 1, stream->file);
}

Prior_queue *create_queue() {
    Prior_queue *queue = malloc(sizeof(Prior_queue));
    if (!queue) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    queue->size = 0;
    queue->heap = NULL;
    return queue;
}

Node *create_node(wchar_t symbol, int freq, Node *left, Node *right) {
    Node *Node = malloc(sizeof(Node));
    if (!Node) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    Node->symbol = symbol;
    Node->freq = freq;
    Node->left = left;
    Node->right = right;
    return Node;
}

void resize(Prior_queue *queue, int size) {
    queue->heap = realloc(queue->heap, size * sizeof(Node *));
    if (!queue->heap && size > 0) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    queue->size = size;
}

void enqueue(Prior_queue *queue, Node *Node) {
    resize(queue, queue->size + 1);
    int index = queue->size - 1;

    while (index > 0 && Node->freq >= queue->heap[index - 1]->freq) {
        queue->heap[index] = queue->heap[index - 1];
        index--;
    }
    queue->heap[index] = Node;
}

Prior_queue *init_queue(FILE *fin) {
    wchar_t symbol;
    Prior_queue *queue = create_queue();
    fseek(fin, 0, SEEK_END);
    long numBytes = ftell(fin);
    rewind(fin);

    for (int i = 0; i < (numBytes / sizeof(wchar_t)); i++) {
        symbol = fgetwc(fin);
        int inQueue = 0;
        for (int i = 0; i < queue->size; i++) {
            if (queue->heap[i]->symbol == symbol) {
                queue->heap[i]->freq++;
                while (i > 0 && queue->heap[i]->freq >= queue->heap[i - 1]->freq) {
                    Node *temp = queue->heap[i];
                    queue->heap[i] = queue->heap[i - 1];
                    queue->heap[i - 1] = temp;
                    i--;
                }
                inQueue = 1;
                break;
            }
        }
        if (!inQueue) {
            enqueue(queue, create_node(symbol, 1, NULL, NULL));
        }
    }
    rewind(fin);
    return queue;
}

Node *create_tree(Prior_queue *queue) {
    while (queue->size > 1) {
        Node *left = queue->heap[--queue->size];
        Node *right = queue->heap[--queue->size];
        Node *Node = create_node(0, left->freq + right->freq, left, right);
        enqueue(queue, Node);
    }
    return queue->heap[0];
}

int last_leaf(Node *root) {
    return !root->left;
}

void get_codes(Node *root,  unsigned long long code, int length, Huffman_tree *codes, int *index) {
    if (last_leaf(root)) {
        codes[*index].symbol = root->symbol;
        codes[*index].length = length;
        codes[*index].code = code;
        (*index)++;
        return;
    }
    get_codes(root->left, code << 1, length + 1, codes, index);
    get_codes(root->right, (code << 1) | 1, length + 1, codes, index);
}


void code_fin(wchar_t symbol, Huffman_tree *codes, Bit_stream *stream, int codesLen) {
    int i;
    for (i = 0; i < codesLen; i++) {
        if (codes[i].symbol == symbol) {
            break;
        }
    }
    for (int j = codes[i].length - 1; j >= 0; j--) {
        int bit = (codes[i].code >> j) & 1;
        write_bit(bit, stream);
    }
}


void destroy_tree(Node *root) {
    if (root == NULL) {
        return;
    }

    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

void tree_to_file(Node *root, Bit_stream *stream) {
    if (last_leaf(root)) {
        write_bit(1, stream);
        write_symbol(root->symbol, stream);
        return;
    }
    write_bit(0, stream);
    tree_to_file(root->left, stream);
    tree_to_file(root->right, stream);
}

void code(FILE *fin, FILE *fout) {
    Prior_queue *queue = init_queue(fin);

    Bit_stream *stream = create_stream(fout);
    
    Huffman_tree *codes = malloc(queue->size * sizeof(Huffman_tree));
    Node *root = create_tree(queue);

    fwrite(&(root->freq), sizeof(int), 1, stream->file);

    tree_to_file(root, stream);
    int index = 0;
    get_codes(root, 0, 0, codes, &index);

    fseek(fin, 0, SEEK_END);
    long numBytes = ftell(fin);
    rewind(fin); //return pointer to file start
    wchar_t symbol;
    for (int i = 0; i < (numBytes / sizeof(wchar_t)); i++) {
        symbol = fgetwc(fin);
        code_fin(symbol, codes, stream, index);
    }
    clear_stream(stream);
    free(codes);
    free(queue->heap);
    free(queue);
    free(stream);
    destroy_tree(root);
}


Node *get_tree(Bit_stream *stream) {
    int bit;
    if (read_bit(&bit, stream) == readingError)
        return NULL;
    if (bit == 1) {
        wchar_t symbol;
        if (read_symbol(&symbol, stream) == readingError)
            return NULL;
        return create_node(symbol, 0, NULL, NULL);
    }
    Node *left = get_tree(stream);
    Node *right = get_tree(stream);
    return create_node(0, 0, left, right);
}

Error unzip(Node *root, Bit_stream *stream, wchar_t *symbol) {
    Node *current = root;
    while (!last_leaf(current)) {
        int bit;
        if (read_bit(&bit, stream) == readingError)
            return readingError;
        if (bit == 0)
            current = current->left;
        else
            current = current->right;
    }
    *symbol = current->symbol;
    return noError;
}

void decode(FILE *fin, FILE *fout) {
    Bit_stream *stream = create_stream(fin);
    int length;
    fread(&length, sizeof(int), 1, stream->file);
    Node *root = get_tree(stream);

    for (int i = 0; i < length; i++) {
        wchar_t symbol;
        if (unzip(root, stream, &symbol) == readingError) {
            fclose(stream->file);
            free(stream);
            return;
        }
        fwrite(&symbol, sizeof(wchar_t), 1, fout);
    }
    destroy_tree(root);
    free(stream);

}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");

    char *action = argv[1];
    char *frst_file = argv[2];
    char *scnd_file = argv[3];

    FILE *fin = fopen(frst_file, "rb");
    FILE *fout = fopen(scnd_file, "wb");

    if (strcmp(action, "c") == 0)
        code(fin, fout);
    else if (strcmp(action, "d") == 0)
        decode(fin, fout);

    fclose(fin);
    fclose(fout);    
    return 0;
}
