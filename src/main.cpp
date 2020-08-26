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

typedef struct Queue
{
    struct ChistmasTree *value;
    struct Queue *next;
} Queue;

void freeTree(ChistmasTree *tree);
void showTree(ChistmasTree *tree);
void setSubTreeWithCut(ChistmasTree *tree);
void getNodesThatValuesIsNegative(ChistmasTree *tree, Queue *queue);
void nodesThatMustBeRemoved(ChistmasTree *tree, int beauty);
void insertNode(ChistmasTree *root, int branch, int value, int beauty);
void nodeForEachOnQueueAndInsertNodeOnTree(Queue *queue, int branch, int value, int beauty);
int calculateChristmasTreeBeauty(ChistmasTree *tree);
int getNumberOfNodesToRemove(ChistmasTree *tree, int beauty);
Queue *createNodeOnQueue();
Queue *insertNodeOnQueue(Queue *queue, ChistmasTree *value);
ChistmasTree *createTreeOrSubTree();
ChistmasTree *searchNodeAndInsertNode(ChistmasTree *tree, int search, Queue *queue);

Queue *createNodeOnQueue()
{
    Queue *node = (Queue *)malloc(sizeof(Queue));
    node->value = NULL;
    node->next = NULL;
    return node;
}

Queue *insertNodeOnQueue(Queue *queue, ChistmasTree *value)
{
    Queue *node = createNodeOnQueue();
    node->value = value;
    node->next = NULL;

    if (queue->next == NULL)
        queue->next = node;
    else
    {
        Queue *temporaryNode = queue->next;

        while (temporaryNode->next != NULL)
            temporaryNode = temporaryNode->next;

        temporaryNode->next = node;
    }
}

void nodeForEachOnQueueAndInsertNodeOnTree(Queue *queue, int branch, int value, int beauty)
{
    if (queue->next == NULL)
        return;

    Queue *temporaryNode = queue->next;

    do
    {
        if (temporaryNode != NULL && temporaryNode->value != NULL)
            insertNode(temporaryNode->value, branch, value, beauty);

        temporaryNode = temporaryNode->next;
    } while (temporaryNode != NULL);
}

void freeQueue(Queue *queue)
{
    if (queue->next != NULL)
    {
        Queue *next, *actual;
        actual = queue->next;
        while (actual != NULL)
        {
            next = actual->next;
            free(actual);
            actual = next;
        }
    }
}

ChistmasTree *createTreeOrSubTree()
{
    ChistmasTree *tree = (ChistmasTree *)malloc(sizeof(ChistmasTree));
    tree->value = 0;
    tree->beauty = 0;
    tree->branch = 0;
    tree->cut = 0;
    tree->root = tree->first = tree->next = NULL;
    return tree;
}

int calculateChristmasTreeBeauty(ChistmasTree *tree)
{
    if (tree != NULL)
    {
        return (tree->cut == 1 ? 0 : tree->beauty) + calculateChristmasTreeBeauty(tree->first) + calculateChristmasTreeBeauty(tree->next);
    }
    return 0;
}

void freeTree(ChistmasTree *tree)
{
    if (tree != NULL)
    {
        freeTree(tree->first);
        freeTree(tree->next);
        free(tree);
    }
}
void showTree(ChistmasTree *tree)
{
    if (tree != NULL)
    {
        int root = tree->root != NULL ? tree->root->value : -1;
        int branch = tree->root != NULL ? tree->root->branch : -1;
        cout << tree->value
             << " (" << root << " - " << branch << ")"
             << " (" << tree->branch << ")"
             << " (" << tree->cut << ")"
             << " (" << tree->beauty << ")\n";
        showTree(tree->first);
        showTree(tree->next);
    }
}

void insertNode(ChistmasTree *root, int branch, int value, int beauty)
{
    if (root != NULL)
    {
        ChistmasTree *subTree = createTreeOrSubTree();
        subTree->beauty = beauty;
        if (beauty <= 0)
            subTree->cut = 1;
        subTree->value = value;
        subTree->branch = branch;
        root->cut = 0;
        subTree->next = root->first;
        root->first = subTree;
        subTree->root = root;
    }
}

ChistmasTree *searchNode(ChistmasTree *tree, int value)
{
    if (tree == NULL)
        return NULL;
    else if (tree->value == value)
        return tree;

    ChistmasTree *subTreeFirst = searchNode(tree->first, value);
    if (subTreeFirst != NULL)
        return subTreeFirst;

    ChistmasTree *subTreeNext = searchNode(tree->next, value);
    if (subTreeNext != NULL)
        return subTreeNext;
}

ChistmasTree *searchNodeAndInsertNode(ChistmasTree *tree, int search, Queue *queue)
{
    if (tree == NULL)
        return NULL;
    else if (tree->value == search)
        insertNodeOnQueue(queue, tree);

    searchNodeAndInsertNode(tree->first, search, queue);

    searchNodeAndInsertNode(tree->next, search, queue);
}

int getNumberOfNodesToRemove(ChistmasTree *tree, int beauty)
{
    if (tree != NULL)
    {
        int cut = 0;
        if ((tree->root == NULL && tree->cut) || beauty == 0)
            cut = 1;
        else if ((tree->root != NULL && tree->root->cut == 0 && tree->cut) || beauty == 0)
            cut = 1;
        return cut + getNumberOfNodesToRemove(tree->first, beauty) + getNumberOfNodesToRemove(tree->next, beauty);
    }
    return 0;
}
int spacing = 0;
void nodesThatMustBeRemoved(ChistmasTree *tree, int beauty)
{
    if (tree != NULL)
    {
        nodesThatMustBeRemoved(tree->next, beauty);
        nodesThatMustBeRemoved(tree->first, beauty);
        if ((tree->cut && tree->root->cut == 0) || beauty == 0)
        {
            if (spacing == 1)
                cout << " ";
            cout << tree->branch;
            spacing = 1;
        }
    }
}

void setSubTreeWithCut(ChistmasTree *tree)
{
    if (tree != NULL)
    {
        tree->cut = 1;
        setSubTreeWithCut(tree->first);
        setSubTreeWithCut(tree->next);
    }
}

void nodeForEachOnQueue(Queue *queue)
{
    if (queue->next == NULL)
        return;

    Queue *temporaryNode = queue->next;

    do
    {
        if (temporaryNode != NULL && temporaryNode->value != NULL) {
            ChistmasTree *tree = temporaryNode->value;
//            int root = tree->root != NULL ? tree->root->value : -1;
//            int branch = tree->root != NULL ? tree->root->branch : -1;
            int beauty = calculateChristmasTreeBeauty(tree);
            if (beauty < 0)
                setSubTreeWithCut(tree);

//            cout << tree->value
//                 << " (" << root << " - " << branch << ")"
//                 << " ( Branch:" << tree->branch << ")"
//                 << " ( Cut: " << tree->cut << ")"
//                 << " ( Beleza: " << beauty << ")"
//                 << " (" << tree->beauty << ")\n";
        }
        temporaryNode = temporaryNode->next;
    } while (temporaryNode != NULL);
}

void getNodesThatValuesIsNegative(ChistmasTree *tree, Queue *queue)
{
    if (tree != NULL)
    {
        if (tree->beauty < 0 && tree->cut != 1) {
            insertNodeOnQueue(queue, tree);
        }
        getNodesThatValuesIsNegative(tree->first, queue);
        getNodesThatValuesIsNegative(tree->next, queue);
    }
}

int main()
{
    ChistmasTree *tree = createTreeOrSubTree();
    ChistmasTree *alternativeTree = createTreeOrSubTree();
    Queue *queue;
    int n;
    int di, ai, bi, wi;
    scanf("%d", &n);
    /**
     * Verifica se a entrada é válida N (2 < N < 10^6)
     */
    if ((n <= 1) || (n >= (10000000)))
    {
        cout << "0 0" << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d %d %d", &di, &ai, &bi, &wi);


//            if ((di >= 0 && di <= n - 2) && (ai >= 0 && ai <= n - 1) && (bi >= 0 && bi <= n - 1) && (wi >= -1000 && wi <= 1000))
//            {
                queue = createNodeOnQueue();
                int search = ai < bi ? ai : bi;
                int value = ai < bi ? bi : ai;
                if ((di == 0 && ai == 0 && bi == 0 && wi == 0))
                    searchNodeAndInsertNode(alternativeTree, search, queue);
                else
                    searchNodeAndInsertNode(tree, search, queue);

                nodeForEachOnQueueAndInsertNodeOnTree(queue, di, value, wi);
                freeQueue(queue);
//            }

    }

    if (tree->first != NULL || tree->next != NULL)
    {
        queue = createNodeOnQueue();

        getNodesThatValuesIsNegative(tree, queue);
        nodeForEachOnQueue(queue);
        int beautyTree = calculateChristmasTreeBeauty(tree);
        int numberOfNodesToRemove = getNumberOfNodesToRemove(tree, beautyTree);

        if (beautyTree > 0)
        {
            cout << beautyTree << " " << numberOfNodesToRemove << endl;
            nodesThatMustBeRemoved(tree, beautyTree);
            cout << endl;
        }  else
        {
            cout << "0 1" << endl;
            cout << "0" << endl;
        }
        freeQueue(queue);
    }
    else
    {
        int beautyAlternative = calculateChristmasTreeBeauty(alternativeTree);
        int numberOfNodesToRemove = getNumberOfNodesToRemove(alternativeTree, beautyAlternative);

        if (beautyAlternative > 0)
        {
            cout << beautyAlternative << " " << numberOfNodesToRemove << endl;
            nodesThatMustBeRemoved(alternativeTree, beautyAlternative);
            cout << endl;
        } else {
            cout << "0 1" << endl;
            cout << "0" << endl;
        }
    }
//        cout << endl;
//        showTree(tree);
    //    cout << endl;
    //    showTree(alternativeTree);
    freeTree(tree);
    freeTree(alternativeTree);
    //    cout << endl;
    return 0;
}
