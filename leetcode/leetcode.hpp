//
//  leetcode.hpp
//  leetcode
//
//  Created by 郭毅 on 2018/10/6.
//  Copyright © 2019 郭毅. All rights reserved.
//

#ifndef leetcode_hpp
#define leetcode_hpp

#include <stdio.h>
#include <vector>
#include "datasturct.hpp"
using std::vector;
class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    ListNode* rotateRight(ListNode* head, int k);
    Node* flatten(Node* head);
    vector<int> inorder(TreeNode* root);
    vector<int> preorder(TreeNode* root);
    vector<int> posorder(TreeNode* root);
    int evalRPN(vector<string>& tokens);
    int maxDepth(TreeNode* root);
    bool isValidBST(TreeNode* root);
    bool isvalid(TreeNode* root,int min,int max);
    int numIslands(vector<vector<char>>& grid);
    int firstBadVersion(int n);
    int rob(vector<int>& nums);
    bool isPowerOfThree(int n);
    int countPrimes(int n);
    vector<string> fizzBuzz(int n);
    void turnString(vector<string>&,int);
    bool isSymmetric(TreeNode* root);
    bool symmetric(TreeNode*,TreeNode*);
    vector<vector<int>> levelOrder(TreeNode* root);
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

};
#endif /* leetcode_hpp */
