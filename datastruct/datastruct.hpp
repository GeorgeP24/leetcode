//
//  datasturct.hpp
//  interviewer
//
//  Created by 郭毅 on 2018/10/6.
//  Copyright © 2019 郭毅. All rights reserved.
//

#ifndef datastruct_hpp
#define datastruct_hpp

#include <stack>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
namespace datastruct {

    template<class T>
    struct ListNode {
        T val;
        ListNode<T> *next;

        ListNode(T x) : val(x), next(nullptr) {}

    };

    template<class T>
    class LinkList {
    public:
        LinkList(const vector<T> &vec) {
            assert(!vec.empty());
            _head->val(vec[0]);
            ListNode<T> *work = _head;
            for (int i = 1; i < vec.size(); ++i) {
                ListNode<T> *temp = new ListNode<T>(vec[i]);
                work->next = temp;
                work = temp;
                delete temp;
            }
        };

        LinkList() = delete;

        ListNode<T> *getHeadNode() {
            return _head;
        }

        void pushBack(const T &value) {
            ListNode<T> *temp = new ListNode<T>(value);
            if (_head == nullptr)
                _head = temp;
            else {
                ListNode<T> *node = _head;
                while (node->next != nullptr)
                    node = node->next;
                node->next = temp;
            }
        }

        void pushBack(ListNode<T> *node) {
            assert(node);
            if (_head == nullptr)
                _head = node;
            else {
                ListNode<T> *temp = _head;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = node;
            }
        }

        void pushFront(const T &value) {
            ListNode<T> *temp = new ListNode<T>(value);
            if (_head)
                temp->next = _head;
            _head = temp;
            delete temp;
        }

        void pushFront(ListNode<T> *node) {
            assert(node);
            if (_head)
                node->next = _head;
            _head = node;
        }


        ListNode<T> *findNodeValuve(const T &value) {
            {
                if (_head == nullptr)
                    return nullptr;
                ListNode<T> *temp = _head;
                while (temp) {
                    if (temp->val == value)
                        return temp;
                    temp = temp->next;
                }
                return nullptr;
            }
        }

        bool removeNodeValue(const T &value) {
            {
                if (_head != nullptr && _head->val == value) {
                    _head = _head->next;
                    return true;
                }
                ListNode<T> *res = _head;
                while (res->next != nullptr) {
                    if (res->next->val == value) {
                        res->next = res->next->next;
                        return true;
                    } else res = res->next;
                }
                return false;
            }
        }

    private:
        ListNode<T> *_head = nullptr;

    };

    template<class T>
    struct biTreeNode {
        T val;
        biTreeNode<T> *left;
        biTreeNode<T> *right;

        biTreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    };

    template<class T>
    class TreeList {
    public:
        TreeList() = delete;

        TreeList(const vector<T> &res) {
            assert(!res.empty());
            _head->val = res.front();
            queue<biTreeNode<T> *> que;
            que.push(_head);
            int len = res.size();
            for (int i = 2; i < len; i += 2) {
                levelInitTreeList(res[i - 1], res[i], que.front());
                que.push(que.front()->left);
                que.push(que.front()->right);
                que.pop();
            }
            if (len%2==0)
                que.front() = new biTreeNode<T>(res.back());
        }

        void levelInitTreeList(const T &a, const T &b, biTreeNode<T> *temp) {
            biTreeNode<T> *work = new biTreeNode<T>(a);
            biTreeNode<T> *work1 = new biTreeNode<T>(b);
            temp->left = work;
            temp->right = work1;
        }
        biTreeNode<T> *getHeadNode(){
            return _head;
        }
//        void preInitTreeList(biTreeNode<T> *p) {
//            if (_res.size() == 0)
//                return;
//            biTreeNode<T> *tree(_res.back());
//            _res.pop_back();
//            p = tree;
//            preInitTreeList(p->left);
//            initTreeList(p->right);
//        }


        static void deleteValue(biTreeNode<T> *head);

        static bool searchValue(biTreeNode<T> *head, const T &value);


        static void mirrorRecursively(biTreeNode<T> *head) {
            if (head == nullptr)
                return;
            if (head->left == nullptr && head->right == nullptr)
                return;
            biTreeNode<T> *temp = head->left;
            head->left = head->right;
            head->right = temp;
            mirrorRecursively(head->left);
            mirrorRecursively(head->right);
        }


        void insertTreeNode(biTreeNode<T> *p) {
            deque<biTreeNode<T> *> que;
            if (_head) {
                que.push_back(_head);
            }
            while (!que.empty()) {
                biTreeNode<T> *cur = que.front();
                que.pop_front();
                if (cur->left)
                    que.push_back(cur->left);
                if (cur->right)
                    que.push_back(cur->right);
            }

        }

        static void levelPrint(biTreeNode<T> *p) {
            deque<biTreeNode<T> *> que;
            if (p)
                que.push_back(p);

            while (!que.empty()) {
                biTreeNode<T> *cur = que.front();
                que.pop_front();
                cout << "data: " << cur->val << endl;
                if (cur->left)
                    que.push_back(cur->left);
                if (cur->right)
                    que.push_back(cur->right);
            }
        }


        biTreeNode<T> *_insertTreeNode(biTreeNode<T> *root) {
        }
        ~TreeList(){
            delete _head;
        }

    private:
        biTreeNode<T> *_head = new biTreeNode<T>(0);
    };

    template<class T>
    class biSearchTree {
    public:
        void insertValue(biTreeNode<T> *head, const T &value) {
            if (!head)
                return;
            biTreeNode<T> *work = head;
            while (work) {
                if (work->val > value) {
                    if (work->left == nullptr) {
                        biTreeNode<T> *res = new biTreeNode<T>(value);
                        work->left = res;
                        return;
                    }
                    work = work->left;
                } else {
                    if (work->right == nullptr) {
                        biTreeNode<T> *res = new biTreeNode<T>(value);
                        work->right = res;
                        return;
                    }
                    work = work->right;
                }
            }
        }

        void deleteValue(biTreeNode<T> *head, const T &value);
    };

    template<class T>
    struct balanceBiTreeNode {
        T val;
        int bf;
        balanceBiTreeNode *left, *right;

        balanceBiTreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    };

    template<class T>
    class balanceBiTree {
    public:
        const static int LH = 1;
        const static int RH = -1;
        const static int EH = 0;
    public:
        void insertNode(balanceBiTreeNode<T> *root, balanceBiTreeNode<T> *node);

        void insertNode(balanceBiTreeNode<T> *root, T value);

        void rRotate(balanceBiTreeNode<T> *tree) {
            //tree的左孩的右孩子作为tree的左孩子。
            //tree的左孩子作为新的根节点。
            balanceBiTreeNode<T> *work = tree->left;
            tree->left = work->right;
            work->right = tree;
            tree = work;
        }

        void lRotate(balanceBiTreeNode<T> *tree) {
            //tree的右孩子作为新的根节点。
            //tree右孩子的左孩子作为tree的右孩子。
            balanceBiTreeNode<T> *work = tree->right;
            tree->right = work->left;
            work->left = tree;
            tree = work;
        }

        T serachValue(balanceBiTreeNode<T> *tree, T value);

        void deleteValue(balanceBiTreeNode<T> *tree, T value);

        void rBalance(balanceBiTreeNode<T> *tree) {
            balanceBiTreeNode<T> *work, *lwork;
            work = tree->right;
            switch (work->bf) {
                case RH:
                    tree->bf = work->bf = EH;
                    lRotate(tree);
                    break;
                case LH:
                    lwork = work->left;
                    switch (lwork->bf) {
                        case RH:
                            tree->bf = LH;
                            work->bf = EH;
                            break;
                        case EH:
                            tree->bf = work->bf = EH;
                        case LH:
                            tree->bf = EH;
                            work->bf = RH;
                            break;
                    }
                    lwork->bf = EH;
                    rRotate(tree->right);
                    lRotate(tree);
            }
        }

        void lBalance(balanceBiTreeNode<T> *tree) {
            balanceBiTreeNode<T> *work, *rwork;
            work = tree->left;
            switch (work->bf) {
                case LH:
                    tree->bf = work->bf = EH;
                    rRotate(tree);
                    break;
                case RH:
                    rwork = work->right;
                    switch (rwork->bf) {
                        case LH:
                            tree->bf = RH;
                            work->bf = EH;
                            break;
                        case EH:
                            tree->bf = work->bf = EH;
                        case RH:
                            tree->bf = EH;
                            work->bf = LH;
                            break;
                    }
                    rwork->bf = EH;
                    lRotate(tree->left);
                    rRotate(tree);
            }
        }


    };

    template<class T>
    class CQueue {
    public:
        CQueue(void);

        ~CQueue(void);

        void appendTail(const T &node) {
            stack1.push(node);
        }

        T deleteHead() {
            if (stack2.size() <= 0) {
                while (stack1.size() > 0) {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            T res = stack2.top();
            stack2.pop();
            return res;
        }

    private:
        stack<T> stack1;
        stack<T> stack2;
    };


    enum Color {
        RED, BLACK
    };

    template<class T>
    class RBTnode {
    public:
        Color color;
        T key;
        RBTnode *left;
        RBTnode *right;
        RBTnode *parent;

        RBTnode(T value, RBTnode c, RBTnode *p, RBTnode *l, RBTnode *r) : key(value),
                                                                          color(c), parent(), left(l), right(r) {}
    };
}

#endif /* datasturct_hpp */
