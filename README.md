## 2575-Christmas-Tree
Resolution of the problem 2575 Christmas Tree of https://www.urionlinejudge.com.br/judge/en/problems/view/2575

The implementation report is in this repository in Portuguese https://github.com/gislainy/RelatorioImplementacaoArvoreDeNatal 


# Christmas Tree

Roberto is in love with Christmas trees. Every year, he adorns the trees of Itajubá with the most beautiful ornaments. Therefore, this year he was invited by the mayor of Belo Horizonte to decorate the Christmas trees that will be placed at the end of the year. For this, Roberto will prune branches from the trees that he thinks are ugly. For each branch i of the tree, Roberto defined how beautiful he is by a number wi. Negative values ​​represent that the branch is ugly. The beauty of a Christmas tree is then defined by the sum of the beauties of its branches.

The process of pruning a tree is simple. Roberto cuts a branch from the tree, and all the branches that leave it fall also. In figure 1 we have an example of a tree and a pruning done by Roberto. In each branch of the tree in the figure we have the value wi which describes how beautiful the branch is. In the tree to the right, the branches cut by Roberto are dotted, while the knots and twigs that fell after the cut are dashed. In the example of figure 1, both the blunt and cut tree have a value of beauty

![Figure 1: Cut of Roberto](https://resources.urionlinejudge.com.br/gallery/images/problems/UOJ_2575_a.png "Figure 1: Cut of Roberto")

Figure 2 shows the optimal cut of the example case. Note that fewer cuts have been made to obtain this beauty tree 15.

![Figure 2: Great cut](https://resources.urionlinejudge.com.br/gallery/images/problems/UOJ_2575_b.png "Figure 2: Great cut")

Knowing about the VI Programming Marathon, Roberto asked you to make a program that would help you to define which branches he should cut from the tree so that it is as beautiful as possible according to its definition.

### Input

The input consists of an integer N (2 < N < 106) which is the number of nodes in the tree. In the next N-1 lines, we have four integers di (0 < di < N-2), ai (0 < ai < N-1), bi (0 < bi < N-1), and wi  (-1000 < wi < 1000) representing the branch identifier i,  which connects the node ai to the bi, and that it has beaty wi by the Robert classification. The tree is always rooted at node 0. It is guaranteed that the input graph is connected and has no cycles.

### Output

The output should contain two integers, D and M, which represent how beautiful the tree is with the optimal cut and how many cuts need to be made, respectively. If the number of slices is greater than 0 on the next line, print M integers dj in ascending order and separated by space, where dj represents the identifier of each branch j to be cut.

If there is more than one tree with the same degree of beauty, print the one with the least branches. If there is still more than one tree that satisfies the same criteria, print the tree with the least cuts.

| Input Sample | Output Sample |
|--------------|---------------|
| 12           | 15 3          |
| 0 0 1 2      | 2 5 10        |
| 2 2 3 -2     |               |
| 3 4 2 8      |               |
| 4 0 5 5      |               |
| 5 5 6 -5     |               |
| 6 6 7 2      |               |
| 7 8 6 2      |               |
| 8 5 9 3      |               |
| 9 5 10 3         |               |
| 10 10 11 -2      |               |

VI Maratona Mineira de programação