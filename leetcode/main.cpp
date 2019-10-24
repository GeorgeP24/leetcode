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
    auto *a = new Solution();
    vector<int> nums{1,0,1,1,0,1};
    string s = "1 24432 fds abc cba";
    string s2 = "Let's take LeetCode contest";
    string s1 = " ";
    cout<<a->reverseWords2_2(s2)<<endl;
    delete a;
    return 0;
}
    
