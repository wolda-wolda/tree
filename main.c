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

void loeschen(Baum *root);

Baum *loeschen2(Baum *root, int x);

int main() {
    int x = 5, ret = 1;
    Baum *root = NULL;
    root = createRoot(root);
    while (ret == 1) {
        printf("Gib deine Zahl ein:\n");
        ret = scanf("%d", &x);
        fflush(stdin);
        if (ret == 1) {
            insert(x, root);
        }
    }

    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    loeschen(root);
    return 0;
}

void loeschen(Baum *root) {
    int x = 0, ret = 1;
    while (ret == 1 && root != NULL) {
        printf("Welche Zahl moechten sie loeschen?:\n");
        ret = scanf("%d", &x);
        fflush(stdin);
        if (ret == 1) {
            root = loeschen2(root, x);
        }
        preorder(root);
        printf("\n");
        postorder(root);
        printf("\n");
        inorder(root);
        printf("\n");
        if (root == NULL) {
            printf("Baum ist leer");
        }
    }
}

Baum *loeschen2(Baum *root, int x) {
    if (root == NULL) {
        return root;
    }
    if (root->id > x) {
        root->left = loeschen2(root->left, x);
    } else if (root->id < x) {
        root->right = loeschen2(root->right, x);
    } else if (root->id == x) {
        Baum *temp = NULL;
        Baum *temp2 = NULL;
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        } else {
            temp = root->right;
            temp2 = root->left;
            free(root);
            root = temp;
            root->left = temp2;
        }
    }
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