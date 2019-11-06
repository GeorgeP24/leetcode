//
//  main.cpp
//  leetcode
//
//  Created by 郭毅 on 2018/10/6.
//  Copyright © 2019 郭毅. All rights reserved.
//

#include <iostream>
#include "datasturct.hpp"
#include "leetcode.hpp"
#include <stack>

//class example{
//private:
//    struct data{
//        unsigned long miles;
//        char type;
//    };
//    union{
//        data rep;
//        example *next;
//    };
//    static const int BLOCK_SIZE;
//    static example *headOfFreeList;
//public:
//    unsigned long getMiles(){return rep.miles;}
//    char getChar(){return rep.type;}
//    void set(unsigned long m,char t){
//        rep.miles = m;
//        rep.type = t;
//    }
//    static void * operator new(size_t size);
//    static void operator delete(void *deadObject,size_t size);
//};
//
//void *example::operator new(size_t size){
//    if(size!=sizeof(example))
//        return ::operator new(size);
//    example *p = headOfFreeList;
//    if(p)   headOfFreeList = p->next;
//    else{
//        example* newBlock = static_cast<example*>(::operator new(BLOCK_SIZE*sizeof(example)));
//        for (int i = 1; i<BLOCK_SIZE-1; i++) {
//            newBlock[i].next = &newBlock[i+1];
//        }
//        newBlock[BLOCK_SIZE-1].next = nullptr;
//        p = newBlock;
//        headOfFreeList = &newBlock[1];
//    }
//    return p;
//}


int main() {
    Solution a;
    listNode<int>* p1 = new listNode<int>(1);
    listNode<int>* p2 = new listNode<int>(2);
    listNode<int>* p3 = new listNode<int>(23);
    listNode<int>* p4 = new listNode<int>(2);
    listNode<int>* p5 = new listNode<int>(21);
    listNode<int>* p6 = new listNode<int>(2);
    listNode<int>* p7 =new listNode<int>(25);
    listNode<int>* p8 = new listNode<int>(2);
    p1->m_next = p2;
    p2->m_next = p3;
    p3->m_next = p4;
    p4->m_next = p5;
    p5->m_next = p6;
    p6->m_next = p7;
    p7->m_next = p8;
    p8->m_next = nullptr;

    listNode<int>* print = a.sortList(p1);
    while (print){
        cout<<print->m_value<<endl;
        print = print->m_next;
    }
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
    delete p7;
    delete p8;
    return 0;
}
    
