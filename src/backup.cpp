
//int main()
//{
//    ChistmasTree *tree = createTreeOrSubTree();
//    ChistmasTree *branches = createTreeOrSubTree();
//    ChistmasTree *node;
//    int spacing = 0;
//    int n = 6;
//
//    //0 0 1 2
//    insertNode(tree,0, 1, 2);
//    //1 1 2 -6
//    node = searchNode(tree, 0);
//    insertNode(node,1, 2, -6);
//    //2 2 3 -2
//    node = searchNode(tree, 2);
//    insertNode(node, 2,3, -2);
//    //3 4 2 8
//    node = searchNode(tree, 2);
//    insertNode(node,3, 4, 8);
//    //
//    //4 0 5 5
//    node = searchNode(tree, 0);
//    insertNode(node, 4,5, 5);
//    //5 5 6 -5
//    node = searchNode(tree, 5);
//    insertNode(node, 5,6, -5);
//    //6 6 7 2
//    node = searchNode(tree, 6);
//    insertNode(node, 6,7, 2);
//    //7 8 6 2
//    node = searchNode(tree, 6);
//    insertNode(node, 7,8, -6);
//    //8 5 9 3
//    node = searchNode(tree, 5);
//    insertNode(node, 8,9, -3);
//    //9 5 10 3
//    node = searchNode(tree, 5);
//    insertNode(node, 9,10, -3);
//    //10 10 11 -2
//    node = searchNode(tree, 10);
//    insertNode(node, 10,10, 10);
//
//
////    cutBranches(tree);
////    cout << "\n\n";
//    cout << calculateChristmasTreeBeauty(tree) << " " << getNumberOfNodesToRemove(tree) << "\n";
//    nodesThatMustBeRemoved(tree);
//
//    cout << "\n\n";
//    cout << "\n";
//    showTree(tree);
//    freeTree(tree);
//    return 0;
//}


//int main()
//{
//    ChistmasTree *tree = createTreeOrSubTree();
//    ChistmasTree *branches = createTreeOrSubTree();
//    ChistmasTree *node;
//    int spacing = 0;
//    int n = 6;
//
//    //0 0 1 3
//    insertNode(tree,0, 1, 3);
//    //1 0 2 3
//    node = searchNode(tree, 0);
//    insertNode(node,1, 2, 3);
//    //2 1 5 -3
//    node = searchNode(tree, 1);
//    insertNode(node, 2,5, -3);
//    //3 1 3 -8
//    node = searchNode(tree, 1);
//    insertNode(node,3, 3, -8);
//    //
//    //4 3 4 -7
//    node = searchNode(tree, 3);
//    insertNode(node, 4,4, -7);
//
//
////    cutBranches(tree);
////    cout << "\n\n";
//    cout << calculateChristmasTreeBeauty(tree) << " " << getNumberOfNodesToRemove(tree) << "\n";
//    nodesThatMustBeRemoved(tree);
//
//    cout << "\n\n";
//    cout << "\n";
//    showTree(tree);
//    freeTree(tree);
//    return 0;
//}

//int main()
//{
//    ChistmasTree *tree = createTreeOrSubTree();
//    ChistmasTree *branches = createTreeOrSubTree();
//    ChistmasTree *node;
//    int spacing = 0;
//    int n = 6;
//
//    //0 0 1 5
//    insertNode(tree,0, 1, 15);
//    //1 0 2 3
//    node = searchNode(tree, 1);
//    insertNode(node,1, 2, -1);
//    //2 1 5 -3
//    node = searchNode(tree, 2);
//    insertNode(node, 3,3, 5);
//    //3 1 3 -8
//    node = searchNode(tree, 3);
//    insertNode(node,4, 5, -9);
//    //
//    //4 3 4 -7
//    node = searchNode(tree, 4);
//    insertNode(node, 5,5, 5);
//    //4 3 4 -7
//    node = searchNode(tree, 2);
//    insertNode(node, 6,7, -5);
//    //4 3 4 -7
//    node = searchNode(tree, 3);
//    insertNode(node, 7,9, 10);
//
//
//    cout << calculateChristmasTreeBeauty(tree) << " " << getNumberOfNodesToRemove(tree) << "\n";
//    nodesThatMustBeRemoved(tree);
//
//    cout << "\n\n";
//    cout << "\n";
//    showTree(tree);
//    freeTree(tree);
//    return 0;
//}
