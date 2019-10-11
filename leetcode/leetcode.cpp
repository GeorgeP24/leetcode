//
//  leetcode.cpp
//  leetcode
//
//  Created by 郭毅 on 2018/10/6.
//  Copyright © 2019 郭毅. All rights reserved.
//

#include "leetcode.hpp"
#include "datasturct.hpp"

#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <string>
#include<numeric>
#include <algorithm>

int uniquePath(int m, int n) {
        if(m == 0 || n==0)
            return 0;
        if(m == 1 || n ==1)
            return 1;
        else
            return uniquePath(m-2,n-1)+uniquePath(m-1,n-2);
    }
    //唯一路径
int uniquePaths(int m, int n){
        vector<vector<int> > x(n,vector<int>(m));
        x[0][0] = 0;
        while ((m-1)>=0) {
            x[0][m] = 1;
            m--;
        }
        while ((n-1>=0)) {
            x[n][0] = 1;
            n--;
        }
        return uniquePaths(m,n);
    }
    
ListNode *Solution::addTwoNumbers(ListNode* l1, ListNode*l2){
    ListNode *pHead = new ListNode(0);
    ListNode *p1 = l1,*p2 = l2, *p3=pHead;
    int sum = 0,temp = 0;
    while (p1!=nullptr||p2!=nullptr) {
        int x = (p1!=nullptr)?p1->val:0;
        int y = (p2!=nullptr)?p2->val:0;
        sum = x+ y+temp;
        temp = sum/10;
        p3->next = new ListNode(sum%10);
        p3 = p3->next;
        if (p1!=nullptr) p1 = p1->next;
        if (p2!=nullptr) p2 = p2->next;
    }
    if (temp == 1) {
        p3->next = new ListNode(1);
    }
    return pHead->next;
}
ListNode *Solution::rotateRight(ListNode *head, int k){
    if(head==nullptr||k == 0)return head;
    int count = 1;
    ListNode *p = head;
    while (p->next!=nullptr) {
        p = p->next;
        count++;
    }
    int rot = k%count;
    if(rot == 0) return head;
    int m = count-rot;
    ListNode *q = head;
    while (m>1) {
        q = q->next;
        m--;
    }
    ListNode *x = q->next;
    ListNode *y = q->next;
    q->next = nullptr;
    while (x!=nullptr && x->next != nullptr) {
        x = x->next;
    }
    x->next = head;
    return y;
}
Node* Solution::flatten(Node* head){
    if (!head) return head;
    Node*p = head;
    stack<Node*> s;
    while (p) {
        if (p->child) {
            s.push(p->next);
            p->next = p->child;
            if(p->next) p->next->prev =p;
            p->child = nullptr;
        }
        else if(p->next==nullptr&&!s.empty()){
           p->next = s.top();
            s.pop();
            if(p->next) p->next->prev = p;
        }
        p = p->next;
    }
    return head;
}
vector<int> Solution::inorder(TreeNode* root){
    vector<int> m;
    if (root) {
        inorder(root->left);
        m.push_back(root->val);
        inorder(root->right);
    }
    return m;
}
vector<int> Solution::preorder(TreeNode* root){
    vector<int> m;
    if (root) {
        m.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    return m;
}
vector<int> Solution::posorder(TreeNode* root){
    vector<int> m;
    if (root) {
        posorder(root->left);
        posorder(root->right);
        m.push_back(root->val);
    }
    return m;
}

int Solution::maxDepth(TreeNode* root){
    int res = 0;
    if (root) {
        res++;
        int max_left = maxDepth(root->left);
        int max_right = maxDepth(root->right);
        res += max_left>max_right?max_left:max_right;
    }
    return res;
}
//bool Solution::isValidBST(TreeNode* root){
//    return isvalid(root,LONG_MIN,LONG_MAX);
//}
//bool Solution::isvalid(TreeNode* root,int min,long int max){
//    if (!root) return true;
//    return (root->val>min)&&root->val<max&&isvalid(root->left, min, root->val)&&isvalid(root->right, root->val,max);
//}
int Solution::numIslands(vector<vector<char>>& grid){
    int count = 0,rows = grid.size(), cols = rows>0?grid[0].size():0;
    if(rows==0||cols==0) return count;
    vector<vector<bool>>visited(rows,vector<bool>(cols,false));
    queue<int> q;
    int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};
    int x = 0,y = 0, xx = 0,yy = 0;
    for (int i = 0; i<rows; ++i) {
        for (int j = 0; j<cols; ++j) {
            if (grid[i][j] == '1'&&!visited[i][j]) {
                q.push(i);
                q.push(j);
                visited[i][j] =true;
                ++count;
                while (!q.empty()) {
                    x = q.front();
                    q.pop();
                    y = q.front();
                    q.pop();
                    for (int k = 0; k<4; ++k) {
                        xx = x+dx[k];
                        yy = y+dy[k];
                        if (xx<0||xx>=rows||yy<0||yy>=cols) continue;
                        if (grid[xx][yy] == '1'&&visited[xx][yy]) {
                            visited[xx][yy] = true;
                            q.push(xx);
                            q.push(yy);
                        }
                    }
                }
            }
        }
    }
    return count;
}
//int Solution::firstBadVersion(int n){
//    int left = 1, right = n;
//    while (left<right) {
//        int mid = left+(right-left)/2;
//        if (isBadVersion(mid)) {
//            right = mid;
//        }
//        else left = mid+1;
//    }
//    return left;
//}
int Solution::rob(vector<int>& nums){
    int n = nums.size();
    if(n == 0) return 0;
    int roblast = nums[0],passlast = 0;
    int rob,pass;
    for (int i = 1; i<n ; i++) {
        rob = nums[i]+passlast;
        pass = max(roblast,passlast);
        roblast = rob;
        passlast = pass;
    }
    return max(roblast,passlast);
}
bool Solution::isPowerOfThree(int n){
    double logAns = log10(n)/log10(3);
    return (logAns - int(logAns)==0)?true:false;
}
int Solution::countPrimes(int n){
    if(!n||n==1) return 0;
    vector<bool> m;
    
    for (int i = 2; i*i<n; i++) {
        if(!m[i]) continue;
        for (int j = i*i; j<n; j+=i) {
            m[j] = false;
        }
    }
    int count = 0;
    for (int i = 2; i<n; i++) {
        if(m[i]) ++count;
    }
    return count;
}
//vector<string> Solution::fizzBuzz(int n){
//    vector<string> m;
//    if(n == 1){
//        m.insert(m.begin(), "1");
//        return m;
//    }
//    while (n>1) {
//        turnString(m, n);
//        n--;
//    }
//}
void Solution::turnString(vector<string>& m,int n){
    if(n%15==0)
        m.insert(m.begin(), "FizzBuzz");
    if(n%5==0)
        m.insert(m.begin(), "Buzz");
    if(n%3==0)
        m.insert(m.begin(), "Fizz");
    else m.insert(m.begin(), to_string(n));
}
bool Solution::isSymmetric(TreeNode* root){
    if(!root)return true;
    return symmetric(root->left,root->right);
}
bool Solution::symmetric(TreeNode* p,TreeNode* q){
    if(!p&&!q) return true;
    if(!p||!q) return false;
    return (p->val==q->val)&&symmetric(p->left, q->right)&&symmetric(p->right,q->left);
}
vector<vector<int>> Solution::levelOrder(TreeNode* root){
    queue<TreeNode*> temp;
    vector<vector<int>> res;
    if(!root) return res;
    temp.push(root);
    temp.push(nullptr);
    int n = 0;
    while (!temp.empty()) {
        TreeNode* p = temp.front();
        temp.pop();
        TreeNode* q = temp.front();
        temp.pop();
        if(p){
            res[n].push_back(p->val);
            temp.push(p->left);
            temp.push(p->right);
        }
        if(q)
        {
            res[n].push_back(p->val);
            temp.push(q->left);
            temp.push(q->right);
        }
        n++;
    }
    return res;
}




int Solution::evalRPN(vector<string>& tokens){
    if (tokens.size() == 1) return stoi(tokens[0]);
    stack<int> m;
    int x = 0;
    while (x<tokens.size()) {
        while (tokens[x]!="+"&&tokens[x]!="-"&&tokens[x]!="*"&&tokens[x]!="/") {
            m.push(stoi(tokens[x]));
            x++;
        }
        int j = m.top();
        m.pop();
        int k = m.top();
        m.pop();
     if(tokens[x]=="+")m.push(k+j);
     if(tokens[x]=="-")m.push(k-j);
     if(tokens[x]=="*")m.push(k*j);
     if(tokens[x]=="/")m.push(k/j);
        x++;
    }
    return m.top();
}
//bool Solution::isValidBST(TreeNode* root){
//    return isvalid(root,LONG_MIN,LONG_MAX);
//}
//bool Solution::isvalid(TreeNode* root,int min,long int max){
//    if (!root) return true;
//    return (root->val>min)&&root->val<max&&isvalid(root->left, min, root->val)&&isvalid(root->right, root->val,max);
//}

vector<string> Solution::fizzBuzz(int n){
    vector<string> m;
    if(n == 1){
        m.insert(m.begin(), "1");
        return m;
    }
    while (n>1) {
        turnString(m, n);
        n--;
    }
    return m;
}



int Solution::maxWidthRamp(vector<int>& A){
    int sz = A.size();
    int dis[50005],clo[50005],ma[50005],mi[50005];
    memset(dis,-1,sizeof (dis));
    memset(clo,-1,sizeof (clo));
    memset(ma,-1,sizeof(ma));
    memset(mi,-1,sizeof(mi));
    for (int i = 0;i<sz ; i++) {
        if(dis[A[i]]!=-1)dis[A[i]] = max(dis[A[i]],i);
        else dis[A[i]] = i;
         if(clo[A[i]]!=-1)clo[A[i]] = min(clo[A[i]],i);
                    else clo[A[i]] = i;
    }
    sort(A.begin(),A.end());
           mi[A[0]] = clo[A[0]];
           for(int i=1;i<sz;i++){
               if(clo[A[i]]<mi[A[i-1]])mi[A[i]] = clo[A[i]];
               else mi[A[i]] = mi[A[i-1]];
           }
           ma[A[sz-1]] = dis[A[sz-1]];
           for(int i=sz-2;i>=0;i--){
               if(dis[A[i]]>ma[A[i+1]])ma[A[i]] = dis[A[i]];
               else ma[A[i]] = ma[A[i+1]];
           }
           int ans = 0;
           for(int i=0;i<sz;i++){
               // cout<<A[i]<<"  "<<ma[A[i]]<<"  "<<mi[A[i]]<<endl;
               ans = max(ans,ma[A[i]]-mi[A[i]]);
           }
           return ans;
       }
void Solution::backtrade(vector<int> candidates, int start, int target, vector<int> item, vector<vector<int>>& res){
    if(target<0)
        return;
    if(target==0)
    {
        res.push_back(item);
        return;
    }
    for (int i = start;i<candidates.size();i++) {
        item.push_back(candidates[i]);
        backtrade(candidates,i,target-candidates[i],item,res);
        item.pop_back();
    }
}
vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> res;
    vector<int> item;
    backtrade(candidates,0,target,item,res);
    return res;
}
int Solution::firstMissingPositive(vector<int>& nums){
    vector<int> m;
    vector<int> n;
    for (int i = 0;i<nums.size();i++) {
        if(nums[i]<1)
         {
            m.push_back(nums[i]);
        }else{
            n.push_back(nums[i]);
    }}
    sort(n.begin(),n.end()+1);
    for (int j = 1;j<n.size();j++) {
        if(n[j-1]!=j)
            return j;
    }
    return 0;
}
int Solution::lengthOfLongestSubstring(string s){
    string res;
    if(!s.empty())
        res = s[0];
    else
        return 0;
    vector<int> n;
    n[0] = 1;
    for (int i = 1;i<s.size();i++) {
            int j = 0;
            while(true)
            {
               if(res[j]==s[i])
               {
                   n.insert(n.end(),res.size());
                   res.clear();
                   break;
               }
               else {
                   res+=s[i];
                   j++;
               }
            }
    }
    int temp = 0;
    for (int x = 1;x<n.size();x++) {
        if(n[x-1]>n[x])
            temp = n[x-1];
        temp = n[x];
    }
    return temp;
}
vector<vector<int> > Solution::subsets(vector<int> &nums){
    vector<vector<int> > res;
    int temp = 0;
    int count = 0;
    if (nums.size() == 0){
        res.push_back({});
        return res;
    }
    while (nums.size() > 0)
    {
        temp = nums.back();
        count = res.size();
        while (count>0)
        {
            res[count - 1].push_back(temp);
            if (count>0)
                count--;
        }
        res.push_back({temp});
        nums.pop_back();
    }
    return res;
}

vector<vector<int>> Solution::generate(int numRows)
{
    vector<vector<int>> m;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> x(i + 1, 1);
        m.push_back(x);
    }
    for (int j = 2; j < numRows; j++)
        for (int k = 1; k < m[j].size() - 1; k++)
            m[j][k] = m[j - 1][k - 1] + m[j - 1][k];
    return m;
}
//二逼方法 使用generate
vector<int> Solution::getRow(int rowIndex) { 
    vector<vector<int>> m = generate(rowIndex+1);
    return m.back();
}

int Solution::kthGrammar(int N, int K) {
    if (K==1)
        return 0;
    else if (K>pow(2, N-2))
        return kthGrammar(N-1, K-pow(2, N-2))^1;
    return kthGrammar(N-1, K);
}

vector<TreeNode*> Solution::generateTrees(int n) {
    if(n<1) return {};
        return *generateTreesDFS(1,n);
}

vector<TreeNode*> *Solution::generateTreesDFS(int start,int end){
    vector<TreeNode*> *trees=new vector<TreeNode*>();
        if(start>end){
            trees->push_back(nullptr);
            return trees;
        }
        for (int i = start; i <= end; i++){
            vector<TreeNode*> *left_trees = generateTreesDFS(start, i-1);
            vector<TreeNode*> *right_trees = generateTreesDFS(i+1, end);
            for(int j = 0;j<left_trees->size();j++){
                for (int k = 0; k<right_trees->size(); k++) {
                    TreeNode *current_tree = new TreeNode(i);
                    current_tree->left = (*left_trees)[j];
                    current_tree->right = (*right_trees)[k];
                    trees->push_back(current_tree);
                }}}
        return trees;
}

ListNode *Solution::swapPairs(ListNode *head) {
if(head==nullptr||head->next==nullptr) return head;
    ListNode *temp = head->next;
    head->next = swapPairs(temp->next);
    temp->next = head;
    return temp;
}

int Solution::pivotIndex(vector<int> &nums) {
    if(nums.size()==0)
        return -1;
    int begin = 0;
    int end = accumulate(nums.begin(), nums.end(), 0)-nums[0]; //<numeric>
    if(begin==end)
        return 0;
    for(int i = 1;i<nums.size();i++){
        begin += nums[i-1];
        end -= nums[i];
        if (begin ==end) {
            return i;
        }
    }
    return -1;
}

int Solution::duplicate(vector<int> nums) { 
    if (nums.size()<=1) {
        return -1;
    }
    for (int i = 0; i<nums.size(); i++) {
        while (nums[i] != i) {
            if (nums[nums[i]] == nums[i])
            return nums[i];
            else{
                nums[i] = nums[i] + nums[nums[i]];
                nums[nums[i]] = nums[i] - nums[nums[i]];
                nums[i] = nums[i] - nums[nums[i]];
            }
        }
    }
    return -1;
}

int Solution::cDuplicate(const vector<int>& nums) {
    if (nums.size()<2) {
        return -1;
    }
    int begin = 0;
    int end = nums.size()-1;
    while (end>=begin) {
        int mid = ((end - begin )>>1) + begin;
        int count = aid_cDuplicate(nums, begin, mid);
        if (begin == end){
            if (count>1)
                return begin;
            break;
        }
        if (count>(mid-begin+1))
            end = mid;
        else
            begin = mid+1;
    }
    return -1;
}
int Solution::aid_cDuplicate(const vector<int> &nums,int begin,int end) {
    if (nums.size()==0) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i<nums.size(); i++) {
        if (nums[i]>=begin && nums[i]<=end)
            count++;
    };
    return count;
}

bool Solution::searchNumber(vector<vector<int>> nums, int k) {
    auto res = false;
    while(nums.size()!=0) {
        if (k == nums[0].back()) {
            return true;
        }
        else if(k>nums[0].back()){
            nums.erase(nums.begin());
        }
        else if(k<nums[0].back()){
            for(auto &temp:nums){
                temp.pop_back();
            }
        }
    }
    return res;
}

vector<int> Solution::findDiagonalOrder(vector<vector<int> > &matrix) {
    if(matrix.size()==0)
        return {};
    vector<int> res;
    vector<vector<int>> temp;
    int i = 1;
    for(auto x:matrix){
        if(i%2==0){
        for(auto &n: temp){
            if(n.size()!=0){
            res.push_back(*(n.begin()));
            n.erase(n.begin());
            }
        }
        res.push_back(*(x.begin()));
        x.erase(x.begin());
        if(x.size()>0)
        temp.push_back(x);
        i++;
        }
        else {
        res.push_back(*(x.begin()));
            x.erase(x.begin());
            int len = temp.size()-1;
            for(int j = len;j>=0;j--){
                if(temp[j].size()!=0){
            res.push_back(*(temp[j].begin()));
            temp[j].erase(temp[j].begin());
            }}
            if(x.size()>0)
            temp.push_back(x);
            i++;
        }
    }
    int const_len = temp.size();
    while (res.size()!=matrix.size()*matrix.back().size()) {
    if(i%2==0){
        for(int k = 0;k<const_len;k++){
            if(temp[k].size()!=0){
        res.push_back(*(temp[k].begin()));
        temp[k].erase(temp[k].begin());
            }
        }
    }
    else{
    for(int j = const_len-1;j>=0;j--){
        if(temp[j].size()!=0){
        res.push_back(*(temp[j].begin()));
        temp[j].erase(temp[j].begin());
        }
    }
    }
    i++;
    }
    return res;
}

void Solution::replaceChar(std::string &str,char ch) {
    if (str.size()==0) {
        return;
    }
    for(int i = 0;i<str.size();i++){
        if(str[i]==ch){
            str.erase(i,1);
            str.insert(i, "%20");
        }
    }
}

vector<int> Solution::spiralOrder(vector<vector<int> > &matrix) { 
    vector<int> res;
    if (matrix.size()==0) {
        return {};
    }
    while(matrix.size()!=0){
    for(auto val : matrix[0]){
        res.push_back(val);
    }
    matrix.erase(matrix.begin());
    for(auto &arr:matrix){
        if(arr.size()==0)
            break;
        res.push_back(arr.back());
        arr.erase(arr.end()-1);
    }
    if(matrix.size()==0)
        break;
    for(int i = matrix.back().size()-1;i>-1;i--){
        res.push_back(matrix.back()[i]);
    }
    matrix.erase(matrix.end()-1);
    
    for (int j = matrix.size()-1; j>-1; j--) {
        if(matrix[j].size()==0)
            break;
        res.push_back(matrix[j][0]);
        matrix[j].erase(matrix[j].begin());
    }
    }
    return res;
}


   





















