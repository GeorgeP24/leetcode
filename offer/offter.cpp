//
// Created by 郭毅 on 2019/12/24.
//

#include "offter.h"
namespace offter{
    bool Find(int target, vector<vector<int> > array){
        while (true){
            if(target>array[0].back()){
                vector<vector<int> > arr(array.begin()+1,array.end());
                Find(target,arr);
            } else if (target < array[0].back()){
                vector<int> arr(array[0]);
            }
            else
            {
                return true;
            }
        }
    }
    bool auxFind(int target,vector<int> array){
        int len = array.size();
        if(len<0)
            return false;
        int temp = len/2;
        int begin = 0;
        int end = len;
        while (true){
            if(target > array[temp]){
                begin = temp;
                temp = (end+temp)/2;
            }
            else if(target < array[temp]){
                end = temp;
                temp = (temp-begin)/2;
            }
            else
                return true;
        }
    }

}