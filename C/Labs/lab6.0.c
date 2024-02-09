#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<malloc.h>

typedef struct node // typedef is needed to create new type
{
    struct node* left; 
    struct node* right;
    int height;
    int value;
} node;

node* make_node(int number_to_add, node** first_position)
{
    node* new_node = malloc(sizeof(node)); // get pointer to the next position (to create new node)

    new_node -> value = number_to_add;
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

node* add_node(node* tree, int number_to_add, node** first_position)
{
    if (tree == NULL)
        return make_node(number_to_add, first_position);
    else
    {
        if (tree->value >= number_to_add)
        
            if (tree->left == NULL)
                tree->left = make_node(number_to_add, first_position);
            else
                tree->left = add_node(tree->left, number_to_add, first_position);
        else
            if (tree->right == NULL)
                tree->right = make_node(number_to_add, first_position);
            else
                tree->right = add_node(tree->right, number_to_add, first_position);
        
        return tree_balance(tree);
    }
}

int main()
{
    int numb_vertexes = 0;
    int number_to_add = 0;

    node* tree = NULL;
    
    scanf_s("%d", &numb_vertexes);

    node* nodes_buffer = (node*)malloc(numb_vertexes * sizeof(node));
    node* m = nodes_buffer;
    node** first_position = &m;

    for (int i = 0; i < numb_vertexes; i++)
    {
        scanf_s("%d", &number_to_add); 

        tree = add_node(tree, number_to_add, first_position);
    }

    printf("%d", tree_height(tree));
	
    free(nodes_buffer);
	return 0;
}
