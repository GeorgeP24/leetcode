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
    vector<vector<int>> m{{1,2,8,9},{4,7,10,13},{6,8,11,15}};
    vector<vector<int>> m2 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> m3 = {{3},{2},{1},{1},{3},{2},{1},{1},{3},{2},{1},{1}};

            
    a.spiralOrder(m3);
    

}
    
