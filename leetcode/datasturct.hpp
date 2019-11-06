//
//  datasturct.hpp
//  leetcode
//
//  Created by 郭毅 on 2018/10/6.
//  Copyright © 2019 郭毅. All rights reserved.
//

#ifndef datasturct_hpp
#define datasturct_hpp

#include <stack>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
namespace _datasturct {

    template <class T>
    struct listNode{
        T m_value;
        listNode<T> *m_next;
        listNode(T x):m_value(x),m_next(nullptr){}

    };


    template <class T>
    class linkList{
    public:
        void addTotAial(listNode<T> *head,const T &value){
            listNode<T> *m_head = new listNode<T>(value);
            if(head== nullptr) head = m_head;
            else{
                listNode<T> *node = m_head;
                while(node->m_next!= nullptr)
                    node=node->m_next;
                node->m_next = m_head;
            }
        }
        listNode<T> *findListNodeValuve(listNode<T> *head,const T &value){
            {
                if(head == nullptr) return nullptr;
                else{
                    while(head  != nullptr){
                        if(head->m_value==value)
                            return head;
                        else if(head->m_next!= nullptr)
                            head = head->m_next;
                        return nullptr;
                    }
                }
            }
        }
        void removeValue(listNode<T> *head,const T &value){
            {
                if(head != nullptr && head->m_value == value)
                    head = head->m_next;
                listNode<T> *res = head;
                while(res->m_next!= nullptr){
                    if(res->m_next->m_value == value)
                        res->m_next = res->m_next->m_next;
                    else res = res->m_next;
                }
            }
        }
        linkList(listNode<T> *head, int &nums);
    };

template <class T>
    struct biTreeNode{
        T m_value;
        biTreeNode<T> *m_left;
        biTreeNode<T> *m_right;
        biTreeNode(T x):m_value(x),m_left(nullptr),m_right(nullptr){}
    };
template <class T>
    class treeList{
    public:
        static void deleteValue(biTreeNode<T> *head);
        static bool searchValue(biTreeNode<T> *head,const T &value);
        static void mirrorRecursively(biTreeNode<T> *head){
            if(head == nullptr)
                return;
            if(head->m_left == nullptr && head->m_right == nullptr)
                return;
            biTreeNode<T> *temp = head->m_left;
            head->m_left = head->m_right;
            head->m_right = temp;
            mirrorRecursively(head->m_left);
            mirrorRecursively(head->m_right);
        }

        treeList()=delete;
        treeList(vector<T> &res) {
            int len = res.size();
            m_res = res;
            try {
                if(len==0)
                    throw -1;
                else{
                        preInitTreeList(m_head);
                }
            }
            catch (...){}
        }
        void preInitTreeList(biTreeNode<T> *p){
                if(m_res.size()==0)
                    return;
                biTreeNode<T> *tree(m_res.back());
                m_res.pop_back();
                p = tree;
                initTreeList(p->m_left);
                initTreeList(p->m_right);
            }

            void levelInitTreeList(biTreeNode<T> *p){
            deque<biTreeNode<T>*> que;
            if(p){
                que.push_back(p);
            }
            while (!que.empty()){
                biTreeNode<T> *cur = que.front();
                que.pop_front();
                m_head = cur;

            }
        }


        void insertTreeNode(biTreeNode<T> *p){
            deque<biTreeNode<T>*> que;
            if(m_head){
                que.push_back(m_head);
            }
            while (!que.empty()){
                biTreeNode<T> *cur = que.front();
                que.pop_front();
                if(cur->m_left)
                    que.push_back(cur->m_left);
                if(cur->m_right)
                    que.push_back(cur->m_right);
            }

        }
        static void levelPrint(biTreeNode<T> *p){
            deque<biTreeNode<T>*> que;
            if(p)
                que.push_back(p);

            while (!que.empty()){
                biTreeNode<T> *cur = que.front();
                que.pop_front();
                cout<<"data: "<<cur->m_value<<endl;
                if(cur->m_left)
                    que.push_back(cur->m_left);
                if(cur->m_right)
                    que.push_back(cur->m_right);
            }
        }


        biTreeNode<T> *_insertTreeNode(biTreeNode<T>*root){
        }

    private:
        biTreeNode<T> *m_head = nullptr;
        vector<T> m_res;
    };

template <class T>
    class biSearchTree{
    public:
        void insertValue(biTreeNode<T> *head,const T& value);
        void deleteValue(biTreeNode<T> *head,const T&value);
        void insertValue(biTreeNode <T> *head, T value);
    };

    template<class T>
    struct balanceBiTreeNode {
        T val;
        int bf;
        balanceBiTreeNode *left, *right;
        balanceBiTreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    };
    template <class T>
    class balanceBiTree {
    public:
        const static int LH = 1;
        const static int RH = -1;
        const static int EH =0;
    public:
        void insertNode(balanceBiTreeNode<T> *root,balanceBiTreeNode<T> *node);
        void insertNode(balanceBiTreeNode<T> *root,T value);
        void rRotate(balanceBiTreeNode<T>* tree){
            //tree的左孩的右孩子作为tree的左孩子。
            //tree的左孩子作为新的根节点。
            balanceBiTreeNode<T> *work = tree->left;
            tree->left = work->right;
            work->right = tree;
            tree = work;
        }
        void lRotate(balanceBiTreeNode<T>* tree){
            //tree的右孩子作为新的根节点。
            //tree右孩子的左孩子作为tree的右孩子。
            balanceBiTreeNode<T> *work = tree->right;
            tree->right = work->left;
            work->left = tree;
            tree = work;
        }
        T serachValue(balanceBiTreeNode<T>* tree,T value);
        void deleteValue(balanceBiTreeNode<T>* tree,T value);
        void rBalance(balanceBiTreeNode<T>* tree){
            balanceBiTreeNode<T> *work,*lwork;
            work = tree->right;
            switch(work->bf){
                case RH:
                    tree->bf = work->bf = EH;
                    lRotate(tree);
                    break;
                case LH:
                    lwork = work->left;
                    switch (lwork->bf){
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
            }}
        void lBalance(balanceBiTreeNode<T>* tree){
            balanceBiTreeNode<T> *work,*rwork;
            work = tree->left;
            switch(work->bf){
                case LH:
                    tree->bf = work->bf = EH;
                    rRotate(tree);
                    break;
                case RH:
                    rwork = work->right;
                    switch (rwork->bf){
                        case LH:
                            tree->bf = RH;
                            work->bf = EH;
                            break;
                        case EH:
                            tree->bf=work->bf = EH;
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

    template <class T>
            class CQueue{
            public:
                CQueue(void);
                ~CQueue(void);

                void appendTail(const T& node) {
                    stack1.push(node);
                }
                T deleteHead() {
                    if(stack2.size()<=0) {
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
