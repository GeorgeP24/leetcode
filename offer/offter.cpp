//
// Created by 郭毅 on 2019/12/24.
//

#include <string>
#include <queue>
#include <algorithm>
#include "offter.h"

namespace offter {
    bool Find(int target, vector<vector<int>> array) {
        int line = array.size();
        if (line <= 0)
            return false;
        int row = array[0].size();
        if (row <= 0)
            return false;
        int i = 0;
        int j = 0;
        while (i < line) {
            if (target > array[i][row - 1]) {
                ++i;
            } else if (target < array[i][row - 1]) {
                j = (row - 1) / 2;
                int end = row - 1;
                int begin = 0;
                while (true) {
                    if (target > array[i][j]) {
                        begin = j;
                        j = (end + j) / 2;
                        if (end == begin + 1)
                            break;
                    } else if (target < array[i][j]) {
                        end = j;
                        j = (j + begin) / 2;
                        if (end == begin)
                            break;
                    } else return true;
                }
                ++i;
            } else {
                return true;
            }
        }
        return false;
    }

    void replaceSpace(char *str, int length) {
        if (length == 0 && str == nullptr) {
            return;
        }
        int numBlock = 0;
        int i = 0;
        char *str1 = str;
        while (*str1 != '\0') {
            if (*str1 == ' ')
                ++numBlock;
            ++str1;
            ++i;
        }
        int newLen = i + 2 * numBlock;
        if (newLen > length)
            return;
        int oldLen = i;
        while (newLen > oldLen && oldLen >= 0) {
            if (str[oldLen] == ' ') {
                str[newLen--] = '0';
                str[newLen--] = '2';
                str[newLen--] = '%';
            } else
                str[newLen--] = str[oldLen];
            --oldLen;
        }
    }

    vector<int> printListFromTailToHead(ListNode<int> *head) {
        vector<int> res;
        vector<int> res1;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        while (res.size() != 0) {
            res1.push_back(res.back());
            res.pop_back();
        }
        return res1;
    }

    biTreeNode<int> *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty() || vin.empty())
            return nullptr;
        auto *root = new biTreeNode<int>(pre[0]);
        auto vin_it = vin.begin();
        auto pre_it = pre.begin();
        ++pre_it;
        while (*vin_it != root->val) {
            ++vin_it;
            ++pre_it;
        }
        vector<int> pre1(pre.begin() + 1, pre_it);
        vector<int> pre2(pre_it, pre.end());
        vector<int> vin1(vin.begin(), vin_it);
        vector<int> vin2(vin_it + 1, vin.end());
        root->left = reConstructBinaryTree(pre1, vin1);
        root->right = reConstructBinaryTree(pre2, vin2);
        return root;
    }

    int minNumberInRotateArray(vector<int> rotateArray) {
        int len = rotateArray.size();
        if (len <= 0)
            return 0;
        if (len == 1)
            return rotateArray[0];
        for (int i = 1; i < len; ++i) {
            if (rotateArray[i] < rotateArray[i - 1])
                return rotateArray[i];
        }
        return rotateArray[0];
    }

    int minNumberInRotateArray(const vector<int> &arr) {
        int len = arr.size();
        if (len <= 0)
            return 0;
        if (len == 1 || arr[0] < arr.back())
            return arr[0];
        else {
            int mid = len / 2;
            int begin = 0;
            int end = len - 1;
            if (arr[begin] == arr[end] && arr[end] == arr[mid]) {
                for (int i = 1; i < len; ++i) {
                    if (arr[i] < arr[i - 1])
                        return arr[i];
                }
                return arr[0];
            } else {
                while (begin + 1 != end) {
                    if (arr[begin] <= arr[mid]) {
                        begin = mid;
                        mid = (begin + end) / 2;
                    } else {
                        end = mid;
                        mid = (end + begin) / 2;
                    }
                }
                return arr[end];
            }
        }
    }

    int Fibonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int res0 = 0;
        int res1 = 1;
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            res = res1 + res0;
            res0 = res1;
            res1 = res;
        }
        return res;
    }

    int jumpFloor(int number) {
        if (number == 0)
            return 0;
        if (number == 1)
            return 1;
        if (number == 2)
            return 2;
        int m1 = 1;
        int m2 = 2;
        int res = 0;
        for (int i = 3; i <= number; ++i) {
            res = m1 + m2;
            m1 = m2;
            m2 = res;
        }
        return res;
    }

    int jumpFloorII(int number) {
        if (number == 1)
            return 1;
        assert(number > 1);
        return 2 << (number - 2);
    }

    int rectCover(int number) {
        if (number < 1)
            return 0;
        if (number == 1)
            return 1;
        if (number == 2)
            return 2;
        int res = 0;
        int m1 = 1;
        int m2 = 2;
        for (int i = 3; i <= number; ++i) {
            res = m1 + m2;
            m1 = m2;
            m2 = res;
        }
        return res;
    }

    int NumberOf1(int n) {
        return 0;
    }

    void reOrderArray(vector<int> &array) {
        int odd = 0;
        int even = 0;
        int len = array.size();
        int memo = 0;
        while (odd < len && even < len) {
            while (odd < len && array[odd] % 2 != 0)
                ++odd;
            even = odd;
            while (even < len && array[even] % 2 == 0) {
                ++memo;
                ++even;
            }
            if (even == len && array[even - 1] % 2 == 0)
                return;
            while (memo > 0) {
                array[even] = array[even - 1] + array[even];
                array[even - 1] = array[even] - array[even - 1];
                array[even] = array[even] - array[even - 1];
                --even;
                --memo;
            }
            ++odd;
        }
    }

    ListNode<int> *FindKthToTail(ListNode<int> *pListHead, unsigned int k) {
        if (!pListHead || k <= 0)
            return nullptr;
        ListNode<int> *kNode = pListHead;
        while (kNode->next && k > 1) {
            kNode = kNode->next;
            --k;
        }
        if (k != 1)
            return nullptr;
        while (kNode->next) {
            pListHead = pListHead->next;
            kNode = kNode->next;
        }
        return pListHead;
    }

    ListNode<int> *ReverseList(ListNode<int> *pHead) {
        if (!pHead)
            return nullptr;
        if (!pHead->next)
            return nullptr;
        ListNode<int> *work = pHead->next;
        ListNode<int> *res = work->next;
        if (!res) {
            work->next = pHead;
            pHead->next = nullptr;
        }
        pHead->next = nullptr;
        while (res->next) {
            work->next = pHead;
            pHead = work;
            work = res;
            res = res->next;
        }
        work->next = pHead;
        res->next = work;
        return res;
    }

    bool HasSubtree(biTreeNode<int> *pRoot1, biTreeNode<int> *pRoot2) {
        if (pRoot2&&pRoot1)
            return AuxSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot2->right, pRoot2);
        return false;
    }

    bool AuxSubtree(biTreeNode<int> *pRoot1, biTreeNode<int> *pRoot2) {
        if (!pRoot2)
            return true;
        if (!pRoot1)
            return false;
        return pRoot1->val == pRoot2->val && AuxSubtree(pRoot1->left, pRoot2->left) &&
               AuxSubtree(pRoot1->right, pRoot2->right);
    }

    ListNode<int> *Merge(ListNode<int> *p, ListNode<int> *q) {
        if (p == nullptr) {
            return q;
        }
        if (q == nullptr) {
            return p;
        }
        ListNode<int> *head = new ListNode<int>(0);
        ListNode<int> *work = head;
        while (p != nullptr && q != nullptr) {
            if (p->val >= q->val) {
                work->next = q;
                q = q->next;
            } else {
                work->next = p;
                p = p->next;
            }
            work = work->next;
        }
        if (p != nullptr)
            work->next = p;
        if (q != nullptr)
            work->next = q;
        return head->next;

    }

    void Mirror(biTreeNode<int> *pRoot) {
        if (!pRoot)
            return;
        biTreeNode<int> *temp;
        temp = pRoot->right;
        pRoot->right = pRoot->left;
        pRoot->left = temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }

    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if (matrix.size() == 0) {
            return {};
        }
        while (matrix.size() != 0) {
            for (auto val : matrix[0]) {
                res.push_back(val);
            }
            matrix.erase(matrix.begin());
            for (auto &arr:matrix) {
                if (arr.size() == 0)
                    break;
                res.push_back(arr.back());
                arr.erase(arr.end() - 1);
            }
            if (matrix.size() == 0)
                break;
            for (int i = matrix.back().size() - 1; i > -1; i--) {
                res.push_back(matrix.back()[i]);
            }
            matrix.erase(matrix.end() - 1);

            for (int j = matrix.size() - 1; j > -1; j--) {
                if (matrix[j].size() == 0)
                    break;
                res.push_back(matrix[j][0]);
                matrix[j].erase(matrix[j].begin());
            }
        }
        return res;

    }

    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        vector<int> work;
        for (auto pv:popV) {
            if (!work.empty() && pv == work.back())
                work.pop_back();
            else if (!pushV.empty()) {
                bool res = false;
                for (auto it = pushV.begin(); it < pushV.end();) {
                    if (pv == *it) {
                        work.push_back(*it);
                        pushV.erase(it);
                        res = true;
                        break;
                    } else {
                        work.push_back(*it);
                        pushV.erase(it);
                    }
                }
                if (res)
                    work.pop_back();
                else
                    return false;
            } else
                return false;
        }
        return true;
    }

    vector<int> PrintFromTopToBottom(biTreeNode<int> *root) {
        if (!root)
            return {};
        queue<biTreeNode<int> *> work;
        vector<int> res;
        work.push(root);

        while (!work.empty()) {
            res.push_back(work.front()->val);
            if (work.front()->left)
                work.push(work.front()->left);
            if (work.front()->right)
                work.push(work.front()->right);
            work.pop();
        }
    }

    vector<vector<int> > Print(biTreeNode<int> *pRoot) {
        if (!pRoot)
            return {};
        vector<vector<int>> res;
        deque<biTreeNode<int> *> work1;
        deque<biTreeNode<int> *> work2;
        vector<int> res1;
        int i = 1;
        work1.push_back(pRoot);
        while (true) {
            while (!work1.empty() && i % 2 != 0) {
                res1.push_back(work1.front()->val);
                if (work1.front()->left)
                    work2.push_back(work1.front()->left);
                if (work1.front()->right)
                    work2.push_back(work1.front()->right);
                work1.pop_front();
                if (work1.empty()) {
                    res.push_back(res1);
                    res1.clear();
                    ++i;
                }
            }
            while (!work2.empty() && i % 2 == 0) {
                res1.push_back(work2.back()->val);
                if (work2.back()->right)
                    work1.push_front(work2.back()->right);
                if (work2.back()->left)
                    work1.push_front(work2.back()->left);
                work2.pop_back();
                if (work2.empty()) {
                    res.push_back(res1);
                    res1.clear();
                    ++i;
                }
            }
            if (work2.empty() && work1.empty())
                break;
        }
        return res;
    }

    vector<vector<int> > Print1(biTreeNode<int> *pRoot) {
        if (!pRoot)
            return {{}};
        vector<vector<int>> res;
        vector<int> res1;
        vector<biTreeNode<int> *> work1;
        vector<biTreeNode<int> *> work2;
        work1.push_back(pRoot);
        while (!work1.empty()) {
            for (auto i : work1) {
                work2.push_back(i);
                res1.push_back(i->val);
            }
            work1.clear();
            res.push_back(res1);
            res1.clear();
            for (auto a:work2) {
                if (a->left)
                    work1.push_back(a->left);
                if (a->right)
                    work1.push_back(a->right);
            }
            work2.clear();
        }
        return res;
    }

    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        int len = numbers.size();
        if (len == 0)
            return 0;
        int index = len / 2;
        int res = numbers[index];
        int count = 1;
        for (int i = index + 1; i < len; ++i) {
            if (res == numbers[i])
                ++count;
        }
        int j = index - 1;
        while (j >= 0) {
            if (res == numbers[j])
                ++count;
            --j;
        }
        if (count > index)
            return numbers[index];
        return 0;
    }

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.empty() || k > input.size())
            return {};
        vector<int> res;
        sort(input.begin(), input.end());
        auto it = input.begin();
        while (k-- > 0)
            res.push_back(*it++);
        return res;
    }

    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty())
            return 0;
        int res = array[0];
        int temp = array[0];
        int len = array.size();
        for (int i = 1; i < len; ++i) {
            temp = max(temp + array[i], array[i]);
            res = max(res, temp);
        }
        return res;
    }

    int NumberOf1Between1AndN_Solution(int n) {

    }
}