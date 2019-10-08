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
using std::cout;
using std::endl;
using std::vector;
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution a;
    vector<int> e{1,7,3,6,5,6};
    vector<int> x3{-1,-1,-1,-1,-1,0};
    vector<int> x4{-1,-1,-1,-1,0,1};
    
    cout<<a.pivotIndex(e)<<endl;
    cout<<a.pivotIndex(x3)<<endl;
    cout<<a.pivotIndex(x4)<<endl;
//    cout<<a.pivotIndex(x)<<endl;
//    cout<<a.pivotIndex(x2)<<endl;
}
