//
// Created by 郭毅 on 2019/12/24.
//
#ifndef LEETCODE_OFFTER_H
#define LEETCODE_OFFTER_H

#include <vector>
#include "../datastruct/datastruct.hpp"
namespace offter {
    using std::vector;
    using namespace datastruct;

    bool Find(int target, vector<vector<int> > array);

    //请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
    void replaceSpace(char *str, int length);

//    输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
    vector<int> printListFromTailToHead(ListNode<int> *head);

    //输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
    //例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
    biTreeNode<int> *reConstructBinaryTree(vector<int> pre, vector<int> vin);

//    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//    输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//    例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
//    int minNumberInRotateArray(vector<int> rotateArray);
    int minNumberInRotateArray(const vector<int> &arr);

    int Fibonacci(int n);

    int jumpFloor(int number);

    //递推公式F(n) = 2F(n-1)
    int jumpFloorII(int number);

//    我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
    int rectCover(int number);

//    输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
    int NumberOf1(int n);

//    输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
//    并保证奇数和奇数，偶数和偶数之间的相对位置不变。
    void reOrderArray(vector<int> &array);

    //倒数第k个链表
    ListNode<int> *FindKthToTail(ListNode<int> *pListHead, unsigned int k);

//    输入一个链表，反转链表后，输出新链表的表头。
    ListNode<int> *ReverseList(ListNode<int> *pHead);

//    合并单链表
    ListNode<int> *Merge(ListNode<int> *pHead1, ListNode<int> *pHead2);

//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
    bool HasSubtree(biTreeNode<int> *pRoot1, biTreeNode<int> *pRoot2);

    bool AuxSubtree(biTreeNode<int> *p, biTreeNode<int> *q);

//    镜像二叉树
    void Mirror(biTreeNode<int> *pRoot);

//    输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵：
//    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
    vector<int> printMatrix(vector<vector<int> > matrix);

//    输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
//    假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
//    序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
    bool IsPopOrder(vector<int> pushV, vector<int> popV);
//    从上往下打印出二叉树的每个节点，同层节点从左至右打印。
    vector<int> PrintFromTopToBottom(biTreeNode<int>* root);
//    请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
//    第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
    vector<vector<int> > Print(biTreeNode<int>* pRoot);
    //层次打印；
    vector<vector<int> > Print1(biTreeNode<int>* pRoot);
//    数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//    例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
    int MoreThanHalfNum_Solution(vector<int> numbers);
//    输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k);
//    HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
//    今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
//    但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},
//    连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，
//    你会不会被他忽悠住？(子向量的长度至少是1)
    int FindGreatestSumOfSubArray(vector<int> array);
//    求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字
//    有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
//    ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
    int NumberOf1Between1AndN_Solution(int n);




}
#endif //LEETCODE_OFFTER_H