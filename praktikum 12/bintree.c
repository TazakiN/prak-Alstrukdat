#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree(ElType root, BinTree left_tree, BinTree right_tree)
{
    BinTree t = newTreeNode(root);
    if (t != NULL)
    {
        LEFT(t) = left_tree;
        RIGHT(t) = right_tree;
    }
    return t;
}

void CreateTree(ElType root, BinTree left_tree, BinTree right_tree, BinTree *p)
{
    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val)
{
    Address p = (Address)malloc(sizeof(TreeNode));
    if (p != NULL)
    {
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}

void deallocTreeNode(Address p)
{
    free(p);
}

boolean isTreeEmpty(BinTree p)
{
    return p == NULL;
}

boolean isOneElmt(BinTree p)
{
    if (!isTreeEmpty(p))
    {
        return (LEFT(p) == NULL && RIGHT(p) == NULL);
    }
    return false;
}

boolean isUnerLeft(BinTree p)
{
    if (!isTreeEmpty(p))
    {
        return (LEFT(p) != NULL && RIGHT(p) == NULL);
    }
    return false;
}

boolean isUnerRight(BinTree p)
{
    if (!isTreeEmpty(p))
    {
        return (LEFT(p) == NULL && RIGHT(p) != NULL);
    }
    return false;
}

boolean isBinary(BinTree p)
{
    if (!isTreeEmpty(p))
    {
        return (LEFT(p) != NULL && RIGHT(p) != NULL);
    }
    return false;
}

void printPreorder(BinTree p)
{
    printf("(");
    if (!isTreeEmpty(p))
    {
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}

void printInorder(BinTree p)
{
    printf("(");
    if (!isTreeEmpty(p))
    {
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}

void printPostorder(BinTree p)
{
    printf("(");
    if (!isTreeEmpty(p))
    {
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}

void printTreeDepth(BinTree p, int h, int depth)
{
    if (!isTreeEmpty(p))
    {
        int i;
        for (i = 0; i < (h * depth); i++)
        {
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        printTreeDepth(LEFT(p), h, depth + 1);
        printTreeDepth(RIGHT(p), h, depth + 1);
    }
}

void printTree(BinTree p, int h)
{
    printTreeDepth(p, h, 0);
}

// int hitungNode(BinTree root) {

//     if (!isOneElmt(root)) {
//         if (isUnerRight(root)) {
//             return 1 + hitungNode(RIGHT(root));
//         } else if (isUnerLeft(root)) {
//             return 1 + hitungNode(LEFT(root));
//         } else {
//             return hitungNode(LEFT(root)) + hitungNode(RIGHT(root));
//         }
//     }

//     return 0;
// }

// int hitungBebek(BinTree root, int n) {
//     return 0;
// }

// int hitungUang(BinTree root) {
//     if (isTreeEmpty(root)) return 0;

//     int nilaiNode, nilaiKiri, nilaiKanan;

//     if (isBinary(root)){
//         nilaiNode = ROOT(root); nilaiKanan = ROOT(RIGHT(root)); nilaiKiri = ROOT(LEFT(root));
//         if (nilaiKanan == NULL) nilaiKanan = 0;
//         if (nilaiKiri == NULL) nilaiKiri = 0;
//         if (nilaiNode > nilaiKanan + nilaiKiri) {
//             if (isBinary(LEFT(root)) && isBinary(RIGHT(root))) {
//                 return nilaiNode + hitungUang(LEFT(LEFT(root))) + hitungUang(RIGHT(LEFT(root))) + hitungUang(RIGHT(RIGHT(root))) + hitungUang(LEFT(RIGHT(root)));
//             } else if (isBinary(LEFT(root)) && isUnerLeft(RIGHT(root))) {
//                 return nilaiNode + hitungUang(LEFT(LEFT(root))) + hitungUang(RIGHT(LEFT(root))) + hitungUang(LEFT(RIGHT(root)));
//             } else if (isBinary(LEFT(root)) && isUnerRight(RIGHT(root))) {
//                 return nilaiNode + hitungUang(LEFT(LEFT(root))) + hitungUang(RIGHT(LEFT(root))) + hitungUang(RIGHT(RIGHT(root)));
//             } else if (isUnerLeft(LEFT(root)) && isBinary(RIGHT(root))) {
//                 return nilaiNode + hitungUang(LEFT(LEFT(root))) + hitungUang(RIGHT(RIGHT(root))) + hitungUang(LEFT(RIGHT(root)));
//             } else if (isUnerLeft(LEFT(root)) && isUnerLeft(RIGHT(root))) {
//                 return nilaiNode + hitungUang(LEFT(LEFT(root))) + hitungUang(LEFT(RIGHT(root)));
//             } else if (isUnerLeft(LEFT(root)) && isUnerRight(RIGHT(root))) {
//                 return nilaiNode + hitungUang(LEFT(LEFT(root))) + hitungUang(RIGHT(RIGHT(root)));
//             } else if (isUnerRight(LEFT(root)) && isBinary(RIGHT(root))) {
//                 return nilaiNode + hitungUang(RIGHT(LEFT(root))) + hitungUang(RIGHT(RIGHT(root))) + hitungUang(LEFT(RIGHT(root)));
//             } else if (isUnerRight(LEFT(root)) && isUnerLeft(RIGHT(root))) {
//                 return nilaiNode + hitungUang(RIGHT(LEFT(root))) + hitungUang(LEFT(RIGHT(root)));
//             } else if (isUnerRight(LEFT(root)) && isUnerRight(RIGHT(root))) {
//                 return nilaiNode + hitungUang(RIGHT(LEFT(root))) + hitungUang(RIGHT(RIGHT(root)));
//             }

//         } else {
//             if (isBinary(LEFT(root)) && isBinary(RIGHT(root))) {
//                 return nilaiKanan + nilaiKiri + hitungUang(LEFT(LEFT(root))) + hitungUang(RIGHT(LEFT(root))) + hitungUang(RIGHT(RIGHT(root))) + hitungUang(LEFT(RIGHT(root)));
//             } else if (isBinary(LEFT(root)) && isUnerLeft(RIGHT(root))) {
//                 return nilaiKanan + nilaiKiri + hitungUang(LEFT(LEFT(root))) + hitungUang(RIGHT(LEFT(root))) + hitungUang(LEFT(RIGHT(root)));
//             } else if (isBinary(LEFT(root)) && isUnerRight(RIGHT(root))) {
//                 return nilaiKanan + nilaiKiri + hitungUang(LEFT(LEFT(root))) + hitungUang(RIGHT(LEFT(root))) + hitungUang(RIGHT(RIGHT(root)));
//             } else if (isUnerLeft(LEFT(root)) && isBinary(RIGHT(root))) {
//                 return nilaiKanan + nilaiKiri + hitungUang(LEFT(LEFT(root))) + hitungUang(RIGHT(RIGHT(root))) + hitungUang(LEFT(RIGHT(root)));
//             } else if (isUnerLeft(LEFT(root)) && isUnerLeft(RIGHT(root))) {
//                 return nilaiKanan + nilaiKiri + hitungUang(LEFT(LEFT(root))) + hitungUang(LEFT(RIGHT(root)));
//             } else if (isUnerLeft(LEFT(root)) && isUnerRight(RIGHT(root))) {
//                 return nilaiKanan + nilaiKiri + hitungUang(LEFT(LEFT(root))) + hitungUang(RIGHT(RIGHT(root)));
//             } else if (isUnerRight(LEFT(root)) && isBinary(RIGHT(root))) {
//                 return nilaiKanan + nilaiKiri + hitungUang(RIGHT(LEFT(root))) + hitungUang(RIGHT(RIGHT(root))) + hitungUang(LEFT(RIGHT(root)));
//             } else if (isUnerRight(LEFT(root)) && isUnerLeft(RIGHT(root))) {
//                 return nilaiKanan + nilaiKiri + hitungUang(RIGHT(LEFT(root))) + hitungUang(LEFT(RIGHT(root)));
//             } else if (isUnerRight(LEFT(root)) && isUnerRight(RIGHT(root))) {
//                 return nilaiKanan + nilaiKiri + hitungUang(RIGHT(LEFT(root))) + hitungUang(RIGHT(RIGHT(root)));
//             }
//         }
//     } else if (isUnerLeft(root)) {
//         nilaiNode = ROOT(root); nilaiKiri = ROOT(LEFT(root));
//         if (nilaiKiri == NULL) nilaiKiri = 0;

//         if (nilaiNode > nilaiKiri) {
//             if (isBinary(LEFT(root))) {
//                 return nilaiNode + hitungUang(LEFT(LEFT(root))) + hitungUang(RIGHT(LEFT(root)));
//             } else if (isUnerLeft(LEFT(root))) {
//                 return nilaiNode + hitungUang(LEFT(LEFT(root)));
//             } else if (isUnerRight(LEFT(root))) {
//                 return nilaiNode + hitungUang(RIGHT(LEFT(root)));
//             }
//         } else {
//             if (isBinary(LEFT(root))) {
//                 return nilaiKiri + hitungUang(LEFT(LEFT(root))) + hitungUang(RIGHT(LEFT(root)));
//             } else if (isUnerLeft(LEFT(root))) {
//                 return nilaiKiri + hitungUang(LEFT(LEFT(root)));
//             } else if (isUnerRight(LEFT(root))) {
//                 return nilaiKiri + hitungUang(RIGHT(LEFT(root)));
//             }
//         }
//     } else if (isUnerRight(root)) {
//         nilaiNode = ROOT(root); nilaiKanan = ROOT(RIGHT(root));
//         if (nilaiKanan == NULL) nilaiKanan = 0;
//         if (nilaiNode > nilaiKanan) {
//             if (isBinary(RIGHT(root))) {
//                 return nilaiNode + hitungUang(LEFT(RIGHT(root))) + hitungUang(RIGHT(RIGHT(root)));
//             } else if (isUnerLeft(RIGHT(root))) {
//                 return nilaiNode + hitungUang(LEFT(RIGHT(root)));
//             } else if (isUnerRight(RIGHT(root))) {
//                 return nilaiNode + hitungUang(RIGHT(RIGHT(root)));
//             }
//         } else {
//             if (isBinary(RIGHT(root))) {
//                 return nilaiKanan + hitungUang(LEFT(RIGHT(root))) + hitungUang(RIGHT(RIGHT(root)));
//             } else if (isUnerLeft(RIGHT(root))) {
//                 return nilaiKanan + hitungUang(LEFT(RIGHT(root)));
//             } else if (isUnerRight(RIGHT(root))) {
//                 return nilaiKanan + hitungUang(RIGHT(RIGHT(root)));
//             }
//         }
//     }
// }