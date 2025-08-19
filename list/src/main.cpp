#include<iostream>
#include"mylist.h"
int main()
{
    mystl::List<int> list;
    for(int i = 1; i <= 5; ++i){
        list.insert(list.end(), i);
    }
    for(int i = 6; i <= 10; ++i){
        list.insert(list.begin(), i);
    }
    for(auto it = list.begin(); it != list.end(); ++it){
        std::cout << *(it) << std::endl;
    }
    return 0;
}