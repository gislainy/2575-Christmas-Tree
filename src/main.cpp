#include "iostream"
#include <algorithm>

using namespace std;

typedef struct ChistmasTree {
    int beauty;
    int value;
    int cut;
    int branch;
    struct ChistmasTree *root;
    struct ChistmasTree *first;
    struct ChistmasTree *next;
} ChistmasTree;

typedef struct Queue {
    struct ChistmasTree *value;
    struct Queue *next;
} Queue;

void freeTree(ChistmasTree *tree);

void freeQueue(Queue *queue);

void showTree(ChistmasTree *tree);

void getNodesThatValuesIsNegative(ChistmasTree *tree, Queue *queue);

void setSubTreeWithCut(ChistmasTree *tree, int branchRoot);

void insertNodeOnTree(ChistmasTree *root, int branch, int value, int beauty);

void searchNodeAndInsertNodeOnQueue(ChistmasTree *tree, int search, Queue *queue);

void nodeForEachOnQueueAndInsertNodeOnTree(Queue *queue, int branch, int value, int beauty);

int calculateChristmasTreeBeauty(ChistmasTree *tree);

int calculateChristmasTreeBeautyCut(ChistmasTree *tree, int branchRoot);

int getNumberOfNodesToRemove(ChistmasTree *tree, int beauty);

Queue *createNodeOnQueue();

Queue *insertNodeOnQueue(Queue *queue, ChistmasTree *value);

ChistmasTree *createTreeOrSubTree();


/**
 * Clears the references of the tree created in memory
 * @param tree
 */
void freeTree(ChistmasTree *tree) {
    if (tree != NULL) {
        freeTree(tree->first);
        freeTree(tree->next);
        free(tree);
    }
}

/**
 * Prints a tree
 * @param tree
 */

void showTree(ChistmasTree *tree) {
    if (tree != NULL) {
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

/**
 * Clears the references of the queue created in memory
 * @param tree
 */
void freeQueue(Queue *queue) {
    if (queue->next != NULL) {
        Queue *next, *actual;
        actual = queue->next;
        while (actual != NULL) {
            next = actual->next;
            free(actual);
            actual = next;
        }
    }
}

/**
 * Scroll through the queue and calculate the beauty of the subtree
 * Case for minor equal to zero is marked for remover
 * @param queue
 */
void nodeForEachOnQueue(Queue *queue) {
    if (queue->next == NULL)
        return;

    Queue *temporaryNode = queue->next;

    do {
        if (temporaryNode != NULL && temporaryNode->value != NULL) {
            ChistmasTree *tree = temporaryNode->value;
            int beauty = calculateChristmasTreeBeautyCut(tree, tree->branch);
            if (beauty <= 0)
                setSubTreeWithCut(tree, tree->branch);
        }
        temporaryNode = temporaryNode->next;
    } while (temporaryNode != NULL);
}

/**
 * Search for nodes with negative values and not a leaf
 * @param tree
 * @param queue
 */
void getNodesThatValuesIsNegative(ChistmasTree *tree, Queue *queue) {
    if (tree != NULL) {
        getNodesThatValuesIsNegative(tree->first, queue);
        getNodesThatValuesIsNegative(tree->next, queue);
        if (tree->beauty <= 0 && tree->cut != 1) {
            insertNodeOnQueue(queue, tree);
        }
    }
}

/**
 * Marks all children of this subtree as removed
 * @param tree
 * @param branchRoot
 */
void setSubTreeWithCut(ChistmasTree *tree, int branchRoot) {
    if (tree != NULL && branchRoot <= tree->branch) {
        tree->cut = 1;
        setSubTreeWithCut(tree->first, branchRoot);
        setSubTreeWithCut(tree->next, branchRoot);
    }
}


int position = 0;
/**
 * Searches the tree for all parent nodes that have been removed
 * @param tree
 * @param beauty
 * @param result
 */
void nodesThatMustBeRemoved(ChistmasTree *tree, int beauty, int *result) {
    if (tree != NULL) {
        nodesThatMustBeRemoved(tree->next, beauty, result);
        nodesThatMustBeRemoved(tree->first, beauty, result);
        if ((tree->cut && tree->root->cut == 0) || beauty == 0) {
            result[position++] = tree->branch;
        }
    }
}

/**
 * Insert a node into the tree
 * If it is a leaf with negative beauty it is already marked for removal
 * @param root
 * @param branch
 * @param value
 * @param beauty
 */

void insertNodeOnTree(ChistmasTree *root, int branch, int value, int beauty) {
    if (root != NULL) {
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

/**
 * Search the tree for all nodes that match search and insert in a queue
 * @param tree
 * @param search
 * @param queue
 */
void searchNodeAndInsertNodeOnQueue(ChistmasTree *tree, int search, Queue *queue) {
    if (tree != NULL) {
        if (tree->value == search) {
            insertNodeOnQueue(queue, tree);
        }
        searchNodeAndInsertNodeOnQueue(tree->first, search, queue);

        searchNodeAndInsertNodeOnQueue(tree->next, search, queue);
    }
}

/**
 * Scroll through each element of the queue and send for insertion
 * @param queue
 * @param branch
 * @param value
 * @param beauty
 */
void nodeForEachOnQueueAndInsertNodeOnTree(Queue *queue, int branch, int value, int beauty) {
    if (queue->next == NULL)
        return;

    Queue *temporaryNode = queue->next;

    do {
        if (temporaryNode != NULL && temporaryNode->value != NULL)
            insertNodeOnTree(temporaryNode->value, branch, value, beauty);

        temporaryNode = temporaryNode->next;
    } while (temporaryNode != NULL);
}


/**
 * Calculates the beauty of the resulting tree
 * @param tree
 * @return int
 */
int calculateChristmasTreeBeauty(ChistmasTree *tree) {
    if (tree != NULL) {
        return (tree->cut == 1 ? 0 : tree->beauty) + calculateChristmasTreeBeauty(tree->first) +
               calculateChristmasTreeBeauty(tree->next);
    }
    return 0;
}

/**
 * Calculates the beauty of the subtree
 * @param tree
 * @param branchRoot
 * @return int
 */
int calculateChristmasTreeBeautyCut(ChistmasTree *tree, int branchRoot) {
    if (tree != NULL && branchRoot <= tree->branch) {
        return (tree->cut == 1 ? 0 : tree->beauty) + calculateChristmasTreeBeautyCut(tree->first, branchRoot) +
               calculateChristmasTreeBeautyCut(tree->next, branchRoot);
    }
    return 0;
}

/**
 * Search for nodes that have been removed without sorting
 * @param tree
 * @param beauty
 * @return
 */

int getNumberOfNodesToRemove(ChistmasTree *tree, int beauty) {
    if (tree != NULL) {
        int cut = 0;
        if ((tree->root == NULL && tree->cut) || beauty == 0)
            cut = 1;
        else if ((tree->root != NULL && tree->root->cut == 0 && tree->cut) || beauty == 0)
            cut = 1;
        return cut + getNumberOfNodesToRemove(tree->first, beauty) + getNumberOfNodesToRemove(tree->next, beauty);
    }
    return 0;
}

/**
 * Create a queue element
 * @return Queue
 */
Queue *createNodeOnQueue() {
    Queue *node = (Queue *) malloc(sizeof(Queue));
    node->value = NULL;
    node->next = NULL;
    return node;
}

/**
 * Insert a new element in the queue
 * @param queue
 * @param value
 * @return
 */
Queue *insertNodeOnQueue(Queue *queue, ChistmasTree *value) {
    Queue *node = createNodeOnQueue();
    node->value = value;
    node->next = NULL;

    if (queue->next == NULL)
        queue->next = node;
    else {
        Queue *temporaryNode = queue->next;

        while (temporaryNode->next != NULL)
            temporaryNode = temporaryNode->next;

        temporaryNode->next = node;
    }
}

/**
 * Create a tree element
 * @return ChistmasTree
 */
ChistmasTree *createTreeOrSubTree() {
    ChistmasTree *tree = (ChistmasTree *) malloc(sizeof(ChistmasTree));
    tree->value = 0;
    tree->beauty = 0;
    tree->branch = 0;
    tree->cut = 0;
    tree->root = tree->first = tree->next = NULL;
    return tree;
}


int main() {
    ChistmasTree *tree = createTreeOrSubTree();
    Queue *queue;
    int n;
    int di, ai, bi, wi;
    scanf("%d", &n);
    /**
     * Check if the entry is valid
     * (2 < N < 10^6)
     */
    if ((n <= 1) || (n >= (10000000))) {
        cout << "0 0" << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d %d", &di, &ai, &bi, &wi);
        /**
         * Check if the entry is valid
         * di (0 < di < N-2)
         * ai (0 < ai < N-1)
         * bi (0 < bi < N-1)
         * wi  (-1000 < wi < 1000)
         */
        if ((di >= 0 && di <= n - 2) && (ai >= 0 && ai <= n - 1) && (bi >= 0 && bi <= n - 1) &&
            (wi >= -1000 && wi <= 1000)) {
            queue = createNodeOnQueue();
            int search = ai;
            int value = bi;
            /**
             * Search the tree for the position of the node to be inserted
             * Use ai as a first attempt
             */
            if ((di == 0 && ai == 0 && bi == 0 && wi == 0) == false)
                searchNodeAndInsertNodeOnQueue(tree, search, queue);

            /**
             * If you have not found any results with ai as a search, use the value of bi
             */
            if (queue->next == NULL) {
                search = bi;
                value = ai;
                searchNodeAndInsertNodeOnQueue(tree, search, queue);
            }
            /**
             * If have repeated values in the tree
             * And this child is inserted for each value found
             */
            nodeForEachOnQueueAndInsertNodeOnTree(queue, di, value, wi);
            freeQueue(queue);
        }

    }

    /**
     * Check if a valid tree
     * If not, print a default output value
     */
    if (tree->first != NULL || tree->next != NULL) {
        queue = createNodeOnQueue();
        /**
         * Search for nodes with negative values and not a leaf
         */
        getNodesThatValuesIsNegative(tree, queue);

        /**
         * For each node found, check if a removal candidate, if so, check to remove
         */
        nodeForEachOnQueue(queue);
        /**
         * Calculates the beauty of the resulting tree
         */
        int beautyTree = calculateChristmasTreeBeauty(tree);
        /**
         * Search for nodes that have been removed without sorting
         * After, sort the values in ascending order
         */
        int numberOfNodesToRemove = getNumberOfNodesToRemove(tree, beautyTree);

        if (beautyTree > 0) {
            cout << beautyTree << " " << numberOfNodesToRemove << endl;
            if (numberOfNodesToRemove) {
                int result[numberOfNodesToRemove];
                nodesThatMustBeRemoved(tree, beautyTree, result);
                int size = sizeof(result) / sizeof(result[0]);

                sort(result, result + size);
                for (int i = 0; i < numberOfNodesToRemove; ++i) {
                    if (i > 0) cout << " ";
                    cout << result[i];
                }
                cout << endl;
            }
        } else {
            cout << "0 1" << endl;
            cout << "0" << endl;
        }
        freeQueue(queue);
    } else
        cout << "0 0" << endl;

    freeTree(tree);
    return 0;
}
