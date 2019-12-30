//
//  main.cpp
//  interviewer
//
//  Created by 郭毅 on 2018/10/6.
//  Copyright © 2019 郭毅. All rights reserved.
//

#include <iostream>
#include "leetcode/leetcode.hpp"
#include "offer/offter.h"


int main() {
    using namespace offter;
    using namespace datastruct;
    const vector<int> v2{6, 7, 8};
    const vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
    auto *tree = new TreeList<int>(v1);
    auto h1 = tree->getHeadNode();
    auto *tree1 = new TreeList<int>(v2);
    auto h2 = tree1->getHeadNode();
    bool a = HasSubtree(h1,h2);

    //    ["PSH3","MIN","PSH4","MIN","PSH2","MIN","PSH3","MIN","POP","MIN","POP","MIN","POP","MIN","PSH0","MIN"]

    return 0;
}
    
