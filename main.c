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

void dasBaum();

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
    dasBaum();
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


void dasBaum() {
    printf("Dies ist ein Baum: Susie\n"
           "Susie@netcom.com, Susie@genie.geis.com\n"
           "\n"
           "                              $\n"
           "                              :$$\n"
           "                         seeee$$$Neeee\n"
           "                           R$$$F$$$$F\n"
           "                             $$$$$$\n"
           "                            @$$P*$$B\n"
           "                           z$#\"  $#$b\n"
           "                           \" d   'N \"\n"
           "                            @\"     ?r\n"
           "                          xF .       \"N\n"
           "                       .$> P54.R       `$\n"
           "                     $*   '*\"$$$  uoP***~\n"
           "                      #Noo \"?$N\"   #oL\n"
           "                         f       o$#$$\"e.\n"
           "                        $  @b    hoR$$r ^\"$$b\n"
           "                     .M   ?B$E   *.B$$       .R\n"
           "                   .*     *\\ *.4*R         ..*\n"
           "                oo#     ooL    d#R.     P##~\n"
           "                $c    .\"\"P#$  @   P     k\n"
           "                  R$r ''?L$$  P  \"r     'N\n"
           "                    ^$ \"$$$` $.....JL     \"N.\n"
           "                  .$\\           * P5\"LR      $..\n"
           "               ..* 4*R     xr    'PFN$$   .k    \"*****.\n"
           "            od#\"   d#*.  \"*$$P~   \"?$*\" '#$$$\"       u\"\n"
           "         e\"\"      f   M   @F\"$  ec       x$\"$.     :\"\n"
           "         M        >  \"d       $$$$?$           .$$F`\n"
           "          \"P..  .$.....$L $$.4$$. \"   @#3$$   $E.\n"
           "             '**..  *   R..$$ `R$*k.  fdM$$>     *..\n"
           "               J\"       *k$$$~  \"*$**o$o$$P        '*oo.\n"
           "              P           #        \"$$$#*o          >  '####*oooo\n"
           "           .e\"            :e$$e.  F3  ^\"$P  :$$s :e@$ee        s\"\n"
           "         $P` M7>    $P$$k \"$\"?$3 @\"#N      CxN$$> .$$$       .P\n"
           "      M$~   J\\##   44N>$$  .d$.$d   @&      `$$$  F  .8..$$$*\n"
           "  .***     :   JM   *d$$*.$$.P  M  .P5     M          **.\n"
           "  \"oo      J  .dP    ud$$od#   $oooooo$  oo$oo           ###ou\n"
           "     \"####$beeeee$.'$eeP#~        \"\"      $$$.    e$$$o       #heeee\n"
           "        :\"    \" z$r ^            o$N     '\"  \"   4$z>$$             \"\"\"#$$$\n"
           "       .~      F$4$B       r    F @#$.       ..   $8$$P M7                $\n"
           "     .*  $     8 $$B     .J$..  hP$$$F     .'PB$       J~##             .d~\n"
           "   .P  *$$$*    \"*\"       $$$    #**~      hdM$$>     <   JM.......*****\n"
           " .P     $#*k       .o#>  P\" \"k   ..         '$$P      d  .JP'h\n"
           "\"\"\"hr ^        xe\"\"  >          \"\"c           ee    @beeeee$.)\n"
           "      \"\"\"t$$$$F\"      M        $`   R          > \"$r     \"     \"c\n"
           "                              oooooooooo\n"
           "                              z        z\n"
           "                              z.,ze.$$$z\n"
           "\n"
           "------------------------------------------------\n");
}
