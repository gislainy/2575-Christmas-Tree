#include "iostream"
using namespace std;

typedef struct ChistmasTree
{
    int beauty;
    int value;
    int cut;
    int branch;
    struct ChistmasTree *root;
    struct ChistmasTree *first;
    struct ChistmasTree *next;
} ChistmasTree;


ChistmasTree *createTreeOrSubTree()
{
    ChistmasTree* tree = (ChistmasTree*)malloc(sizeof(ChistmasTree));
    tree->value = 0;
    tree->beauty = 0;
    tree->branch = 0;
    tree->cut = 0;
    tree->root = tree->first = tree->next = NULL;
    return tree;
}

int calculateChristmasTreeBeauty(ChistmasTree *tree) {
    if (tree != NULL)
    {
        return (tree->cut == 1 ? 0 : tree->beauty)
                                    + calculateChristmasTreeBeauty(tree->first)
                                    + calculateChristmasTreeBeauty(tree->next);
    }
    return 0;
}

void freeTree(ChistmasTree *tree)
{
    if(tree != NULL)
    {
        freeTree(tree->first);
        freeTree(tree->next);
        free(tree);
    }
}
void showTree(ChistmasTree *tree)
{
    if(tree != NULL)
    {
        cout << tree->value << " (" << tree->branch << ")" << " (" << tree->cut << ")" << " (" << tree->beauty << ")\n";
        showTree(tree->first);
        showTree(tree->next);
    }
}

void insertNode(ChistmasTree *root, int branch, int value, int beauty)
{
    if(root != NULL)
    {
        ChistmasTree *subTree = createTreeOrSubTree();
        subTree->beauty = beauty;
        if (beauty <= 0)
            subTree->cut = 1;
        subTree->value = value;
        subTree->branch = branch;
        if (root != NULL && root->cut == 1 && root->beauty <= 0) {
            if((beauty + root->beauty) > 0) {
                root->cut = 0;
                if (root->first != NULL && root->first->beauty > 0) {
                    root->first->cut = 0;
                }
                if (root->next != NULL && root->next->beauty > 0) {
                    root->next->cut = 0;
                }
            }
        }

        if(root->cut == 1) {
          subTree->cut = 1;
        }
        subTree->next = root->first;
        root->first = subTree;
        subTree->root = root;
    }
}



ChistmasTree *searchNode(ChistmasTree *tree, int value)
{
    if(tree == NULL)
        return NULL;
    else if(tree->value == value)
        return tree;

    ChistmasTree* subTreeFirst = searchNode(tree->first, value);
    if (subTreeFirst != NULL)
        return subTreeFirst;

    ChistmasTree* subTreeNext = searchNode(tree->next, value);
    if (subTreeNext != NULL)
        return subTreeNext;

}

int getNumberOfNodesToRemove(ChistmasTree *tree)
{
    if (tree != NULL)
    {
        int cut = 0;
        if(tree->root == NULL && tree->cut)
            cut = 1;
        else if(tree->root != NULL && tree->root->cut == 0 && tree->cut)
            cut = 1;
        return cut
               + getNumberOfNodesToRemove(tree->first)
               + getNumberOfNodesToRemove(tree->next);
    }
    return 0;
}
int spacing = 0;
void nodesThatMustBeRemoved(ChistmasTree *tree)
{
    if(tree != NULL)
    {
        nodesThatMustBeRemoved(tree->next);
        nodesThatMustBeRemoved(tree->first);
        if (tree->cut && tree->root->cut == 0)
        {
            if(spacing == 1)
                cout << " ";
            cout << tree->branch;
            spacing = 1;
        }
    }
}

int main()
{
    ChistmasTree *tree = createTreeOrSubTree();
    ChistmasTree *node;
    int n;
    int di, ai, bi, wi;
    cin >> n;
    cin.ignore(100,'\n');
    /**
     * Verifica se a entrada é válida N (2 < N < 10^6)
     */
    if ((n <= 1) || (n >= (10000000))) {
        cout << "0 0" << "\n";
        return 0;
    }
    for (int i = 0; i < n-1; i++)
    {
        if (scanf("%d %d %d %d", &di, &ai, &bi, &wi) != EOF)
        {

            if ((di >= 0 && di <= n - 2)
                && (ai >= 0 && ai <= n - 1)
                && (bi >= 0 && bi <= n - 1)
                && (wi >= -1000 && wi <= 1000) == false)
            {
                cout << "0 0" << "\n";
                return 0;
            }

            if (ai < bi)
            {
                node = searchNode(tree, ai);
                if (node != NULL)
                    insertNode(node, di, bi, wi);
            }
            else
            {
                node = searchNode(tree, bi);
                if (node != NULL)
                    insertNode(node, di, ai, wi);
            }
        }
    }
    cout << calculateChristmasTreeBeauty(tree) << " " << getNumberOfNodesToRemove(tree) << "\n";
    nodesThatMustBeRemoved(tree);
    freeTree(tree);
    cout << "\n";
    return 0;
}
