#include "datasturct.hpp"
//
//  leetcode.cpp
//  leetcode
//
//  Created by 郭毅 on 2018/10/6.
//  Copyright © 2019 郭毅. All rights reserved.
//

#include "leetcode.hpp"
#include "datasturct.hpp"


#include<iostream>
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
    
listNode<int> *Solution::addTwoNumbers(listNode<int>* l1, listNode<int>*l2){
    listNode<int> *pHead = new listNode<int>(0);
    listNode<int> *p1 = l1,*p2 = l2, *p3=pHead;
    int sum = 0,temp = 0;
    while (p1!=nullptr||p2!=nullptr) {
        int x = (p1!=nullptr)?p1->m_value:0;
        int y = (p2!=nullptr)?p2->m_value:0;
        sum = x+ y+temp;
        temp = sum/10;
        p3->m_next = new listNode<int>(sum%10);
        p3 = p3->m_next;
        if (p1!=nullptr) p1 = p1->m_next;
        if (p2!=nullptr) p2 = p2->m_next;
    }
    if (temp == 1) {
        p3->m_next = new listNode<int>(1);
    }
    return pHead->m_next;
}
listNode<int> *Solution::rotateRight(listNode<int> *head, int k){
    if(head==nullptr||k == 0)return head;
    int count = 1;
    listNode<int> *p = head;
    while (p->m_next!=nullptr) {
        p = p->m_next;
        count++;
    }
    int rot = k%count;
    if(rot == 0) return head;
    int m = count-rot;
    listNode<int> *q = head;
    while (m>1) {
        q = q->m_next;
        m--;
    }
    listNode<int> *x = q->m_next;
    listNode<int> *y = q->m_next;
    q->m_next = nullptr;
    while (x!=nullptr && x->m_next != nullptr) {
        x = x->m_next;
    }
    x->m_next = head;
    return y;
}
//listNode<int>* Solution::flatten(listNode<int>* head){
//    if (!head) return head;
//    listNode<int>*p = head;
//    stack<listNode<int>*> s;
//    while (p) {
//        if (p->child) {
//            s.push(p->next);
//            p->next = p->child;
//            if(p->next) p->next->prev =p;
//            p->child = nullptr;
//        }
//        else if(p->next==nullptr&&!s.empty()){
//           p->next = s.top();
//            s.pop();
//            if(p->next) p->next->prev = p;
//        }
//        p = p->next;
//    }
//    return head;
//}
vector<int> Solution::inorder(biTreeNode<int>* root){
    vector<int> m;
    if (root) {
        inorder(root->m_left);
        m.push_back(root->m_value);
        inorder(root->m_right);
    }
    return m;
}
vector<int> Solution::preorder(biTreeNode<int>* root){
    vector<int> m;
    if (root) {
        m.push_back(root->m_value);
        preorder(root->m_left);
        preorder(root->m_right);
    }
    return m;
}
vector<int> Solution::posorder(biTreeNode<int>* root){
    vector<int> m;
    if (root) {
        posorder(root->m_left);
        posorder(root->m_right);
        m.push_back(root->m_value);
    }
    return m;
}

int Solution::maxDepth(biTreeNode<int>* root){
    int res = 0;
    if (root) {
        res++;
        int max_left = maxDepth(root->m_left);
        int max_right = maxDepth(root->m_right);
        res += max_left>max_right?max_left:max_right;
    }
    return res;
}
//bool Solution::isValidBST(biTreeNode<int>* root){
//    return isvalid(root,LONG_MIN,LONG_MAX);
//}
//bool Solution::isvalid(biTreeNode<int>* root,int min,long int max){
//    if (!root) return true;
//    return (root->val>min)&&root->val<max&&isvalid(root->m_left, min, root->val)&&isvalid(root->m_right, root->val,max);
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
//    int m_left = 1, m_right = n;
//    while (m_left<m_right) {
//        int mid = m_left+(m_right-m_left)/2;
//        if (isBadVersion(mid)) {
//            m_right = mid;
//        }
//        else m_left = mid+1;
//    }
//    return m_left;
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
bool Solution::isSymmetric(biTreeNode<int>* root){
    if(!root)return true;
    return symmetric(root->m_left,root->m_right);
}
bool Solution::symmetric(biTreeNode<int>* p,biTreeNode<int>* q){
    if(!p&&!q) return true;
    if(!p||!q) return false;
    return (p->m_value==q->m_value)&&symmetric(p->m_left, q->m_right)&&symmetric(p->m_right,q->m_left);
}
vector<vector<int>> Solution::levelOrder(biTreeNode<int>* root){
    queue<biTreeNode<int>*> temp;
    vector<vector<int>> res;
    if(!root) return res;
    temp.push(root);
    temp.push(nullptr);
    int n = 0;
    while (!temp.empty()) {
        biTreeNode<int>* p = temp.front();
        temp.pop();
        biTreeNode<int>* q = temp.front();
        temp.pop();
        if(p){
            res[n].push_back(p->m_value);
            temp.push(p->m_left);
            temp.push(p->m_right);
        }
        if(q)
        {
            res[n].push_back(p->m_value);
            temp.push(q->m_left);
            temp.push(q->m_right);
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
//bool Solution::isValidBST(biTreeNode<int>* root){
//    return isvalid(root,LONG_MIN,LONG_MAX);
//}
//bool Solution::isvalid(biTreeNode<int>* root,int min,long int max){
//    if (!root) return true;
//    return (root->val>min)&&root->val<max&&isvalid(root->m_left, min, root->val)&&isvalid(root->m_right, root->val,max);
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

vector<biTreeNode<int>*> Solution::generateTrees(int n) {
    if(n<1) return {};
        return *generateTreesDFS(1,n);
}

vector<biTreeNode<int>*> *Solution::generateTreesDFS(int start,int end){
    vector<biTreeNode<int>*> *trees=new vector<biTreeNode<int>*>();
        if(start>end){
            trees->push_back(nullptr);
            return trees;
        }
        for (int i = start; i <= end; i++){
            vector<biTreeNode<int>*> *left_trees = generateTreesDFS(start, i-1);
            vector<biTreeNode<int>*> *right_trees = generateTreesDFS(i+1, end);
            for(int j = 0;j<left_trees->size();j++){
                for (int k = 0; k<right_trees->size(); k++) {
                    biTreeNode<int> *current_tree = new biTreeNode<int>(i);
                    current_tree->m_left = (*left_trees)[j];
                    current_tree->m_right = (*right_trees)[k];
                    trees->push_back(current_tree);
                }}}
        return trees;
}

listNode<int> *Solution::swapPairs(listNode<int> *head) {
if(head==nullptr||head->m_next==nullptr) return head;
    listNode<int> *temp = head->m_next;
    head->m_next = swapPairs(temp->m_next);
    temp->m_next = head;
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

std::string Solution::addBinary(std::string a, std::string b) { 
    if(a.size()==0&&b.size()==0)
        return "";
    if(a.size()==0&&b.size()!=0)
        return b;
    if(a.size()==0&&b.size()!=0)
        return a;
    string res = "";
    int temp = 0;
    int count = 0;
    while (a.size()!=0&&b.size()!=0) {
        temp = a.back()+b.back();
        if(count == 0){
        if(temp == 98)
        {
            res.push_back('0');
            count = 1;
        }
        else if(temp == 97) res.push_back('1');
        else if(temp == 96) res.push_back('0');
        }
        else{
            if(temp == 98) res.push_back('1');
            else if(temp == 97) res.push_back('0');
            else if(temp == 96){
                res.push_back('1');
                count = 0;
            }
        }
        a.pop_back();
        b.pop_back();
    }
    string r_res(res.rbegin(),res.rend());
    if(count == 0){
    if (a.size()!=0)
        return a.append(r_res);
    if (b.size()!=0)
        return b.append(r_res);
    }
    else{
        if(a.size()!=0) {
            for (int i = a.size() - 1; i>0; i--) {
                if (a[i] == '1') {
                    a[i] = '0';
                }
                else{
                    a[i] ='1';
                    count = 0;
                    break;
                }
            }
            if(a[0]=='1'&& count ==1){
                a[0] = '0';
                a.insert(a.begin(), '1');
            }
            return a.append(r_res);
    }
        if(b.size()!=0){
            for (int i = b.size()-1; i>0; i--) {
                if(b[i]=='1') b[i] = '0';
                else {
                    b[i] = '1';
                    count = 0;
                    break;
                }
            }
            if(b[0] == '1' && count == 1){
                b[0] = '0';
                b.insert(b.begin(), '1');
            }
            return b.append(r_res);
        }
        r_res.insert(r_res.begin(), '1');
    }
    return r_res;
}

int Solution::strStr(std::string haystack, std::string needle) {
    if(needle.size()==0)
        return 0;
    vector<int> next = getNext(needle);
    int i = 0;
    int j = 0;
    int h_len = haystack.size();
    int n_len = needle.size();
    while (i<h_len&&j<n_len) {
        if (j==-1||haystack[i]==needle[j]) {
            i++;
            j++;
        }
        else{
            j = next[j];
        }
        if(j==n_len)
            return i-j;
    }
    return -1;
}

vector<int> Solution::getNext(std::string a) {
    vector<int> next(a.size());
    int a_len = a.size();
    int i = 0;
    int j = -1;
    next[0] = -1;
    while (i<a_len-1) {
        if(j==-1||a[i]==a[j]){
            i++;
            j++;
            if(a[i]!=a[j])
                next[i] = j;
            else next[i] = next[j];
        }
        else j = next[j];
    }
    return next;
}

int Solution::arrayPairSum(vector<int> &nums) {
    if(nums.size()<1)
        return 0;
    std::sort(nums.begin(),nums.end());
    int res = 0;
    for(int i = 0;i<nums.size();i++){
        if(i%2==0)
            res += nums[i];
    }
    return res;
}

int Solution::findMaxConsecutiveOnes(vector<int> &nums) {
    int count = 0;
    int max = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i]==1)
            count++;
        else if(count>max) {
            max = count;
            count = 0;
        }
        else count = 0;
    }
    if(count>max)
        count = max;
    return max;
}

string Solution::reverseWords(string s) {
    if (s.size() < 2) {
        if(s.size()==1 && s[0] != ' ')
            return s;
        else
            return "";
    }
    string res = "";
    string::iterator ch;
    ch = s.begin();
    stack<string> stc;
    string m = "";
    while(ch!=s.end()){
        if(*ch != ' ') {
            m.push_back(*ch);
            ch++;
        }
        else if(m.size()!=0){
            stc.push(m);
            stc.push(" ");
            m = "";
            ch++;
        }
        else
            ch++;
    }
    if(m.size()!=0)
        stc.push(m);
    if(stc.size()==0)
        return " ";
    if(stc.top()==" ")
        stc.pop();
    while(stc.size()!=0){
        res += stc.top();
        stc.pop();
    }
    return res;
}

string Solution::reverseWords2(string s) {
    if(s.size()<2)
        return s;
    vector<string> temp;
    string res;
    string str= "";
    for(auto _s:s){
        if(_s!=' '){
            str.push_back(_s);
        }
        else if(str.size()!=0) {
            temp.push_back(str);
            str = "";
        }
    }
    if(str.size()!=0)
        temp.push_back(str);
    if(temp.size() == 0)
        return "";
    for(auto t: temp){
        reverse(t.begin(),t.end());
        res += t;
        res += " ";
    }
    if(res[res.size()-1]== ' ')
        res.pop_back();
    return res;
}

string Solution::reverseWords2_2(string s) {
    if(s.size()<2)
        return s;
    int i = 0;
    int j = 0;
    int temp = 0;
    char t = ' ';
    int len = s.size();
    for(;i<len;){
        while (j<len&&s[j]!=' ')
            j++;
        int temp = j+1;
        j = j-1;
        while(i<j){
            s[i] = s[i] + s[j];
            s[j] = s[i] - s[j];
            s[i] = s[i] - s[j];
            i++;
            j--;
        }
        i = temp;
        j = temp;
    }
    string m(s);
    return m;
}

std::string Solution::longestCommonPrefix(vector<std::string> &strs) {
    if(strs.size()<2)
        return "";
    int i = 0;
    int len = strs.size();
    string str = strs[i];
    while (i<len-1){
        str = commonPrefix(str,strs[i+1]);
        i++;
    }
    return str;
}

string Solution::commonPrefix(const string &a, const string &b) {
    if(a.size()==0||b.size()==0)
        return "";
    string res = "";
    int i = 0;
    for (int i = 0; i < a.size()&&i<b.size(); ++i) {
        if(a[i]==b[i])
            res +=a[i];
        else
            break;
    }
    return res;
}

void Solution::printRverseList(listNode<int> *head) {
    stack<int> temp;
    while(head!= nullptr)
    {
        temp.push(head->m_value);
        head = head->m_next;
    }
    while (temp.size()!=0){
        std::cout<<temp.top()<<std::endl;
        temp.pop();
    }
    return;
}

biTreeNode<int> *Solution::rebuildBiTree(vector<int> pre, vector<int> mid) {
    if(pre.size()!=mid.size())
        return nullptr;
    if(pre.size()==0)
        return nullptr;
    if(pre.size()==1)
    {
        biTreeNode<int>*head = new biTreeNode<int>(pre[0]);
        return head;
    }
    biTreeNode<int>* head = new biTreeNode<int>(pre[0]);
    vector<int> mid_left;
    for(auto x: mid){
        if(x == pre[0])
            break;
        else
            mid_left.push_back(x);
    }
    vector<int> mid_right(mid.begin()+mid_left.size()+1,mid.end());
    vector<int> pre_left(pre.begin()+1,pre.begin()+mid_left.size()+1);
    vector<int> pre_right(pre.begin()+1+mid_left.size()+1,pre.end());
    head->m_left = rebuildBiTree(pre_left,mid_left);
    head->m_right = rebuildBiTree(pre_right,mid_right);
}

Solution::sTreeNode *Solution::preNextNode(Solution::sTreeNode *p) {
    if(!p)
        return nullptr;
    sTreeNode *temp = nullptr;
    if(p->right){
        auto _right = p->right;
        while(_right->left)
            _right = _right->left;
        temp = _right;
    }
    else if(p->parent){
        auto *_Current = p;
        auto *_parent = p->parent;
        while(_parent &&_Current ==_parent->right){
            _Current = _parent;
            _parent = _parent->parent;
        }
        temp = _parent;
    }
    return temp;
}

//string Solution::multiply(string num1, string num2) {
//    int len1 = num1.size();
//    int len2 = num2.size();
//    vector<int> temp1;
//    vector<string> temp2(len1,"");
//    int x = 0;
//    temp1.push_back(0);
//    int temp = 0;
//    for(auto i: num1){
//        for (int j = len2 - 1; j >= 0; --j) {
//            temp = (i-'0')*(num2[j]-'0');
//            temp1.push_back(temp/10);
//            int y = temp%10+temp1[j-len2];
//            if(y>10){
//                temp1[j-len+1] += 1;
//                y%=10;
//            }
//            temp2[x]+=to_string(temp%10+y);
//        }
//        if(temp1.size()>len1&&temp1.back()>9)
//            temp2[x] +=to_string(temp1.back()%10);
//        x++;
//    }
//    for (int k = temp2.size()-1; k >=0 ; --k) {
//
//    }
//}

bool Solution::isPowerOfTwo(int n) {
    if(n<=0)
        return false;
    if((n&n-1)==0)
        return true;
    return false;
}

vector<vector<int>> Solution::permute(vector<int> &nums) {
vector<vector<int>> res;
_permute(nums,res,0);
return res;

}

void Solution::_permute(vector<int> &nums, vector<vector<int>>& res, int i) {
if (i == nums.size())
{
    res.push_back(nums);
    return;
}
    for (int j = i; j <nums.size() ; ++j) {
        if(i!=j)  swap(nums[i],nums[j]);
        _permute(nums,res,i+1);
        if(i!=j) swap(nums[i],nums[j]);
    }
}

listNode<int> *Solution::sortList(listNode<int> *head) {
    if(!head||!head->m_next)
        return head;
//    bool temp = true;
//    while(temp) {
//        temp = false;
//        listNode<int> *work = head;
//
//        while (work->m_next && work) {
//            while (work->m_value > work->m_next->m_value) {
//                 work->m_value = work->m_value + work->m_next->m_value;
//                 work->m_next->m_value = work->m_value - work->m_next->m_value;
//                 work->m_value = work->m_value - work->m_next->m_value;
//                 temp = true;
//            }
//            work = work->m_next;
//        }
//    }
    listNode<int> *p = head;
    listNode<int> *k = nullptr;
    listNode<int> *q = getMid(head);
    k = q->m_next;
    q->m_next = nullptr;
    p = sortList(p);
    k = sortList(k);
    return merge(p,k);
}
listNode<int> *Solution::getMid(listNode<int> *head) {
    listNode<int> *fast= head->m_next;
    listNode<int> *slow= head;
    while(fast != nullptr && fast->m_next!= nullptr){
        fast = fast->m_next->m_next;
        slow = slow->m_next;
    }
    return slow;
}


listNode<int> *Solution::merge(listNode<int> *p, listNode<int> *q) {
    if (p == nullptr) {
        return q;
    }
    if (q == nullptr) {
        return p;
    }
    listNode<int>* head = new listNode<int>(0);
    listNode<int> *work = head;
    while (p != nullptr && q != nullptr) {
        if (p->m_value >= q->m_value) {
            work->m_next = q;
            q = q->m_next;
        } else {
            work->m_next = p;
            p = p->m_next;
        }
        work = work->m_next;
    }
    if (p != nullptr)
        work->m_next = p;
    if( q != nullptr)
        work->m_next = q;
    return head->m_next;
}
bool Solution::isPalindrome(int x) {
    if(x<0)
        return false;
    int y = x;
    stack<int> temp;
    while(true){
        int t = x%10;
        temp.push(t);
        if(x<10)
            break;
        x /= 10;
    }
    int z = 0;
    int len = temp.size();
    for (int i = 0; i < len; ++i) {
        z += (temp.top())*pow(10,i);
        temp.pop();
    }
    if(y == z)
        return true;
    return false;
}

int Solution::majorityElement(vector<int> &nums) {
    sort(nums.begin(),nums.end());
    int len = nums.size();
    int count = 0;
    int i = 0;
    for(auto n:nums){
        if(n!=i) {
            i = n;
            count = 0;
        }
        count++;
        if(count>len/2)
            return i;
    }
    return -1;
}




double Solution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
    return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
}

int Solution::findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
    if (i >= nums1.size()) return nums2[j + k - 1];
    if (j >= nums2.size()) return nums1[i + k - 1];
    if (k == 1) return min(nums1[i], nums2[j]);
    int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
    int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
    if (midVal1 < midVal2) {
        return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
    } else {
        return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
    }
}








   





















