#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    struct Node *left;
    struct Node *right;
} typedef Baum;

Baum *createRoot(Baum *root);

void insert(int x, Baum *root);


void preorder(Baum *root);

void inorder(Baum *root);

void postorder(Baum *root);

int main() {
    int x = 5;
    Baum *root = NULL;
    root = createRoot(root);
    while (x != -1) {
        printf("Gib deine Zahl ein:\n");
        scanf("%d", &x);
        if (x != -1) {
            insert(x, root);
        }
    }
    printf("Dies ist ein Baum: https://bit.ly/2Rcj4Qg\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}

void postorder(Baum *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\n", root->id);
}

void inorder(Baum *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d\n", root->id);
    inorder(root->right);
}

void preorder(Baum *root) {
    if (root == NULL) {
        return;
    }
    printf("%d\n", root->id);
    preorder(root->left);
    preorder(root->right);
}


void insert(int x, Baum *root) {
    if (root->id == 0) {
        root->id = x;
    } else {
        Baum *temp = root;
        while (x != -1) {
            if (x < temp->id && temp->left == NULL) {
                Baum *node = (Baum *) malloc(sizeof(Baum));
                node->left = NULL;
                node->right = NULL;
                node->id = x;
                temp->left = node;
                x = -1;
            } else if (x < temp->id && temp->left != NULL) {
                temp = temp->left;
            }
            if (x >= temp->id && temp->right == NULL) {
                Baum *node = (Baum *) malloc(sizeof(Baum));
                node->left = NULL;
                node->right = NULL;
                node->id = x;
                x = -1;
                temp->right = node;
            } else if (x >= temp->id && temp->right != NULL) {
                temp = temp->right;
            }
        }
    }
}

Baum *createRoot(Baum *root) {
    if (root != NULL) {
        return root;
    } else {
        root = (Baum *) malloc(sizeof(Baum));
        root->left = NULL;
        root->right = NULL;
        root->id = 0;
        return root;
    }
}
