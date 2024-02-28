#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<malloc.h>
#include <stdbool.h>

typedef struct node 
{
    struct node* left; 
    struct node* right;
    int value;
} node;

node* make_node(int add_numb, node** frst_pos)
{
    node* new_node = malloc(sizeof(node)); 

    new_node -> value = add_numb;
    new_node -> left = NULL;
    new_node -> right = NULL;

    return new_node;
}

int max(int frst_numb, int sec_numb)
{
    if (frst_numb > sec_numb)
        return frst_numb;
    return sec_numb;
}


int get_height(node* tree)
{
    if (tree == NULL)
        return -1;
    return max(get_height(tree->left), get_height(tree->right)) + 1;
}

node* rotate_left(node* tree)
{
    node* rotated_tree = tree->right;
    tree->right = rotated_tree->left;
    rotated_tree->left = tree;

    height_fix(rotated_tree); 
    height_fix(tree);

    return rotated_tree;
}

node* rotate_right(node* tree)
{
    node* rotated_tree = tree->left;
    tree->left = rotated_tree->right;
    rotated_tree->right = tree;
    
    height_fix(rotated_tree); 
    height_fix(tree);

    return rotated_tree;
}

node* tree_balance(node* tree)
{
    
    node* right_tree = tree->right;
    node* left_tree = tree->left;

    if (right_tree->right < right_tree->left)
        tree->right = rotate_right(right_tree);

    return rotate_left(tree);

    if(left_tree->right> left_tree->left)
        tree->left = rotate_left(left_tree);

   return rotate_right(tree);

    return tree;
}

node* add_node(node* tree, int add_numb, node** frst_pos)
{
    if (tree == NULL)
        return make_node(add_numb, frst_pos);
    else
    {
        if (tree->value >= add_numb)
        
            if (tree->left == NULL)
                tree->left = make_node(add_numb, frst_pos);
            else
                tree->left = add_node(tree->left, add_numb, frst_pos);
        else
            if (tree->right == NULL)
                tree->right = make_node(add_numb, frst_pos);
            else
                tree->right = add_node(tree->right, add_numb, frst_pos);
        
        return tree_balance(tree);
    }
}

void inorder(node* tree) {
    if (tree) {
        inorder(tree->left);
        printf("%d ", tree->value);
        inorder(tree->right);
    }
}

bool find_numb(node* tree, int fnd_numb)
{
    bool find = false;

    while (!tree || !find)
    {
        if (tree->value == fnd_numb)
            find = true;
        else if (fnd_numb > tree->value)
            tree = tree->right;
        else
            tree = tree->left;
    }

    return find;
}

int main()
{
    int numb_vrtx = 0;
    int add_numb = 0;
    int fnd_numb = 0;
    bool find = false;

    node* tree = NULL;
    
    scanf_s("%d", &numb_vrtx);

    node* nodes_buffer = (node*)malloc(numb_vrtx * sizeof(node));
    node* m = nodes_buffer;
    node** frst_pos = &m;

    for (int i = 0; i < numb_vrtx; i++)
    {
        scanf_s("%d", &add_numb); 

        tree = add_node(tree, add_numb, frst_pos);
    }

    inorder(tree);

    scanf_s("%d", &fnd_numb);
	
    find = find_numb(tree, fnd_numb);

    if (find == true)
        printf("There is such number!");
    else 
        printf("There is not such number!");
    
    printf("%d\n", get_height(tree) + 1);

    free(nodes_buffer);
	return 0;
}
