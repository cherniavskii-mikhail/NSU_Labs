#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define LENGHT 50

typedef struct node
{
    struct node* left;
    struct node* right;
    int height;
    char question[LENGHT];
    int answr;
} node;

node* make_node(char str[LENGHT], node** frst_pos)
{
    node* new_node = malloc(sizeof(node)); // get pointer to the next position (to create new node)

    new_node->question = str;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;

    return new_node;
}

node* add_node(node* tree, char str[LENGHT], node** frst_pos, FILE* text)
{
    if (tree == NULL)
    {
        return make_node(str, frst_pos);
    }
    else
    {
        if (tree->answr == true)
        {
            if (tree->left == NULL)
            {
                str = fgets(str, LENGHT, text);
                tree->left = make_node(str, frst_pos);
                tree->left->answr = 1;
            }
            else
            {
                str = fgets(str, LENGHT, text);
                tree->left = add_node(tree->left, str, frst_pos, text);
                tree->left->answr = 1;
            }
        }
        else
        {
            if (tree->right == NULL)
            {
                str = fgets(str, LENGHT, text);
                tree->right = make_node(str, frst_pos);
                tree->right->answr = 2;
            }
            else
            {
                str = fgets(str, LENGHT, text);
                tree->left = add_node(tree->left, str, frst_pos, text);
                tree->right->answr = 2;
            }
        }

        return tree_balance(tree);
    }
}

void start_game(node* tree, int answer)
{
    for (int i = 0; i < LENGHT; i++)
        printf("%c", tree->question[i]);

    scanf_s("%d", &answer);

    if (answer == 1)
        start_game(tree->left, answer);
    else if (answer == 2)
        start_game(tree->right, answer);
    else
        return 0;

}

int main()
{
    FILE* text;
    node* tree = NULL;
    int answer = 0;

    char* str;

    text = fopen(text, ”r”);

    node* nodes_buffer = (node*)malloc(LENGHT * sizeof(node));
    node* m = nodes_buffer;
    node** frst_pos = &m;

   
    str = fgets(str, LENGHT, text);
        
    if (str == NULL)
        add_node(tree, str, frst_pos, text);
    
    start_game(tree, answer);

    return 0;
}
