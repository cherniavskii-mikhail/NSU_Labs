#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<malloc.h>

typedef struct node 
{
    struct node* left; 
    struct node* right;
    int height;
    int value;
} node;

node* make_node(int add_numb, node** frst_pos)
{
    node* new_node = malloc(sizeof(node)); 

    new_node -> value = add_numb;
    new_node -> left = NULL;
    new_node -> right = NULL;
    new_node -> height = 1;

    return new_node;
}

int tree_height(node* tree)
{
    return(tree == NULL) ? 0 : tree->height;
}

void height_fix(node* tree)
{
    int left_height = tree_height(tree->left);
    int right_height = tree_height(tree->right);

    if (left_height > right_height)
        tree->height = tree_height(tree->left) + 1;
    else
        tree->height = tree_height(tree->right) + 1;
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
    height_fix(tree);
    
    node* right_tree = tree->right;
    node* left_tree = tree->left;

    if (tree_height(tree->left) - tree_height(left_tree) == 2)
    {
        if (tree_height(right_tree->right) < tree_height(right_tree->left))
            tree->right = rotate_right(right_tree);

        return rotate_left(tree);
    }

    if (tree_height(right_tree) - tree_height(left_tree) == -2)
    {
        if(tree_height(left_tree->right)> tree_height(left_tree->left))
            tree->left = rotate_left(left_tree);

        return rotate_right(tree);
    }

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

int main()
{
    int numb_vrtx = 0;
    int add_numb = 0;

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

    printf("%d", tree_height(tree));
	
    free(nodes_buffer);
	return 0;
}
