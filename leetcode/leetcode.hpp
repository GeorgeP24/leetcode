//
//  interviewer.hpp
//  interviewer
//
//  Created by 郭毅 on 2018/10/6.
//  Copyright © 2019 郭毅. All rights reserved.
//

#ifndef leetcode_hpp
#define leetcode_hpp

#include <cstdio>
#include <vector>
#include "../datastruct/datastruct.hpp"
using namespace datastruct;
using std::vector;
class Solution{
public:
    ListNode<int>* addTwoNumbers(ListNode<int>* l1, ListNode<int>* l2);
    ListNode<int>* rotateRight(ListNode<int>* head, int k);
    ListNode<int>* flatten(ListNode<int>* head);
    vector<int> inorder(biTreeNode<int>* root);
    vector<int> preorder(biTreeNode<int>* root);
    vector<int> posorder(biTreeNode<int>* root);
    int evalRPN(vector<string>& tokens);
    int maxDepth(biTreeNode<int>* root);
    bool isValidBST(biTreeNode<int>* root);
    bool isvalid(biTreeNode<int>* root,int min,int max);
    int numIslands(vector<vector<char>>& grid);
    int firstBadVersion(int n);
    int rob(vector<int>& nums);
    bool isPowerOfThree(int n);
    int countPrimes(int n);
    vector<string> fizzBuzz(int n);
    void turnString(vector<string>&,int);
    bool isSymmetric(biTreeNode<int>* root);
    bool symmetric(biTreeNode<int>*,biTreeNode<int>*);
    vector<vector<int>> levelOrder(biTreeNode<int>* root);
    int maxWidthRamp(vector<int>& );
    void backtrade(vector<int> candidates,int start,int target,vector<int> item,vector<vector<int>>& res);
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    int searchInsert(vector<int>& nums, int target);
    int firstMissingPositive(vector<int>& nums);
    int lengthOfLongestSubstring(string s);
    //给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。解集不能包含重复的子集。
    vector<vector<int> > subsets(vector<int> &nums);
   //杨辉三角1
    vector<vector<int> > generate(int numRows);
    // 杨辉三角2
    vector<int> getRow(int rowIndex);
    int kthGrammar(int N, int K);
//    Catalan数的定义令h(1)=1，Catalan数满足递归式：h(n) = h(1)*h(n-1) + h(2)*h(n-2) + ... + h(n-1)h(1)，n>=2该递推关系的解为：h(n) = C(2n-2,n-1)/n，n=1,2,3,...（其中C(2n-2,n-1)表示2n-2个中取n-1个的组合数）
//    不同的二叉搜索树个数2
    vector<biTreeNode<int>*> generateTrees(int n);
    vector<biTreeNode<int>*> *generateTreesDFS(int start,int end);
    ListNode<int>* swapPairs(ListNode<int>* head);
    //寻找数组的中心索引
    int pivotIndex(vector<int>& nums);
    //数组中重复数字 size = n, -1<nums[i]<n
    int duplicate(vector<int> nums);
    //不修改数组 寻找重复数字 size = n+1 0<nums[i]<n+1
    int cDuplicate(const vector<int> &nums);
    int aid_cDuplicate(const vector<int> &nums,int,int );
    //二维数组查找
    bool searchNumber(vector<vector<int>> nums,int k);
    //对角线遍历
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix);
    //替换字符
    void replaceChar(string &str,char ch);
    //给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
    vector<int> spiralOrder(vector<vector<int>>& matrix);
    // 二进制求和
    string addBinary(string a, string b);
    //寻找子串 //KMP
    int strStr(string haystack, string needle);
    //next 数组 优化版
    vector<int> getNext(string a);
    // 编写一个函数来查找字符串数组中的最长公共前缀。
    //    如果不存在公共前缀，返回空字符串 ""
    string longestCommonPrefix(vector<string>& strs);
    string commonPrefix(const string &a,const string& b);
    // 给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。
    int arrayPairSum(vector<int>& nums);
    //给定一个二进制数组， 计算其中最大连续1的个数。
    int findMaxConsecutiveOnes(vector<int>& nums);
    //翻转字符串里的单词
    string reverseWords(string s);
//    给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//    注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
    string reverseWords2(string s);
    //第二版本
    string reverseWords2_2(string s);
//    从头到尾打印单链表
    void printRverseList(ListNode<int>*head);
//    根据前序遍历和中序遍历，重建二叉树
    biTreeNode<int>* rebuildBiTree(vector<int>pre,vector<int>mid);
//    input：二叉树，一个节点。
//    output：中序遍历的下一个节点。 节点含有一个指向父亲的指针。
    struct sTreeNode{
        int val;
        sTreeNode *parent;
        sTreeNode *right;
        sTreeNode *left;
        sTreeNode(int x):val(x),parent(nullptr),right(nullptr),left(nullptr){}
    };
    sTreeNode *preNextNode(sTreeNode *p);
//num1 和 num2 的长度小于110。
//num1 和 num2 只包含数字 0-9。
//num1 和 num2 均不以零开头，除非是数字 0 本身。
//不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
//    字符串相乘
    string multiply(string num1, string num2);
//    寻找两个有序数组的中位数
//    不同时为空
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k);
//    2的幂
    bool isPowerOfTwo(int n);
//    全排列
    vector<vector<int>> permute(vector<int>& nums);
    void _permute(vector<int>& nums,vector<vector<int>>& res,int i);
//    归并排序
    ListNode<int>* sortList(ListNode<int>* head);
    ListNode<int>* getMid(ListNode<int>* head);
    ListNode<int>* merge(ListNode<int>* p,ListNode<int>* q);
    //回文数
    bool isPalindrome(int x);
    //众数 个数大于等于n/2
    int majorityElement(vector<int>& nums);
    //排序后 中位数为该数
    int majorityElement_1(vector<int>& nums);
    //排序数组中，N的次数 O(logN)
    int timesInSortArr(vector<int>& nums,int n);
    int findFristN(vector<int>& nums,int start,int end,int n);
    int findLastN(vector<int>& nums,int start,int end,int n);
    //满足四数平方和定理的数n（这里要满足由四个数构成，小于四个不行），必定满足 n=4^a(8b+7)
    //Lagrange 四平方定理： 任何一个正整数都可以表示成不超过四个整数的平方之和。
    int numSquares(int n);
    //给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
    //返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
    //数组非空，且长度不会超过20。
    //初始的数组的和不会超过1000。
    //保证返回的最终结果能被32位整数存下。
    int findTargetSumWays(vector<int>& nums, int S);
    void helper(vector<int>& nums,int S,int start, int &res);
    //编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
    //
    //你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
    //
    //此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入
    string decodeString(string s);
    //计算1+...+n 不使用乘法，for，while等逻辑运算。1.构造函数。2.虚函数。
//    unsigned int addN(int n);
//    class add{
//    public:
//        add(){++i;n+=i;};
//        static unsigned int get(){return n;}
//        static void reset(){n = 0; i = 0;}
//    private:
//        static unsigned int n;
//        static unsigned int i;
//    };
//    unsigned int addFinal(unsigned int n){
//        add::reset();
//        add *a = new add[n];
//        delete []a;
//        a = nullptr;
//        return add::get();
//    }
 int add(int num1,int num2);
};


#endif /* leetcode_hpp */
