//
//  test.cpp
//  interviewer
//
//  Created by 郭毅 on 2018/10/6.
//  Copyright © 2019 郭毅. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    enum n {a = 100};
    const type_info &nInfo = typeid(n);
    cout<<nInfo.name();
    return 0;
}

