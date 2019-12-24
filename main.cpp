//
//  main.cpp
//  interviewer
//
//  Created by 郭毅 on 2018/10/6.
//  Copyright © 2019 郭毅. All rights reserved.
//

#include <iostream>
#include "datastruct/datasturct.hpp"
#include "leetcode/leetcode.hpp"

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

class test{
public:
    test(){
        cout<<"cstr"<<endl;
    }
    test(const test&){
        cout<<"copy cstr"<<endl;
    }
private:
    int a;
    int b;
};

int main() {
    Solution a;
    return 0;
}
    
