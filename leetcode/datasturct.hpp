//
//  datasturct.hpp
//  leetcode
//
//  Created by 郭毅 on 2018/10/6.
//  Copyright © 2019 郭毅. All rights reserved.
//

#ifndef datasturct_hpp
#define datasturct_hpp
#include <stdio.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :val(x),next(NULL){}
};
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;
    Node() {}
    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
class MyLinkedList {
public:
    MyLinkedList();
    int get(int index);
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);
};

enum Color{RED,BLACK};
template <class T>
class RBTnode{
public:
    Color color;
    T key;
    RBTnode *left;
    RBTnode *right;
    RBTnode *parent;
    RBTnode(T value,RBTnode c,RBTnode* p,RBTnode* l,RBTnode* r):key(value),
    color(c),parent(),left(l),right(r){}
};


#endif /* datasturct_hpp */
