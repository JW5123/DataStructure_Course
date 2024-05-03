#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

typedef struct TreeNode{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* buildTree(TreeNode* node[], int n, int size){
    if(n < size){
        if(node[n] != NULL){
            TreeNode* root = node[n];
            root->left = buildTree(node, 2 * n + 1, size);
            root->right = buildTree(node, 2 * n + 2, size);
            return root;
        }
    }
    return NULL;
}

TreeNode* inputNode() {
    TreeNode* temp[MAX_NODES];
    TreeNode* node = NULL;
    char input[10];
    int i = 0;

    while(1){
        scanf("%s", input);
        if(input[0] == 'e'){
            printf("OK\n");
            break;
        }
        if(input[0] == 'x'){
            temp[i++] = NULL;
        } else {
            node = createNode(atoi(input));
            temp[i++] = node;
        }
    }

    return buildTree(temp, 0, i);
}

bool DFS(TreeNode* root, int sum) {
    if (!root)
        return false;
    if (!root->left && !root->right && root->value == sum)
        return true;
    return DFS(root->left, sum - root->value) || DFS(root->right, sum - root->value);
}

void findNumber(TreeNode* root) {
    if (root == NULL) {
        printf("ERROR\n");
        return;
    }
    int target;
    scanf("%d", &target);
    printf(DFS(root, target) ? "YES\n" : "NO\n");
}

void Quit(){
    printf("quit\n");
    exit(0);
}

int main() {
    TreeNode* root = NULL;
    int option;

    while (1) {
        scanf("%d", &option);
        switch (option) {
            case 1:
                root = inputNode();
                break;
            case 2:
                findNumber(root);
                break;
            case 0:
                Quit();
                break;
            default:
                printf("ERROR\n");
                break;
        }
    }

    return 0;
}