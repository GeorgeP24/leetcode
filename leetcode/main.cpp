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
using std::cout;
using std::endl;
using std::vector;
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution a;
    vector<int> e{1,0,1,3,3,5,6,4,3};
    vector<int> x3{-1,-1,-1,-1,-1,0};
    vector<int> x4{-1,-1,-1,-1,0,1};
    vector<vector<int>> m{{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    vector<vector<int>> m2 = {{1,2,3},{4,5,6},{7,8,9}};
    if(1%2==0)
        cout<<0<<endl;
    cout<<1<<endl;
//    a.findDiagonalOrder(m2);
}
