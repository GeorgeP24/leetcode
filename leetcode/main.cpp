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
    vector<vector<int>> m = a.generate(5);
    cout<<m[1][1];
    return 0;
}
