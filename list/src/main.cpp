#include"mylist.h"
int main()
{
    mystl::MyList<int> list;
    for(int i = 0; i < 5; ++i)
    {
        list.insert(list.begin(), i);
    }
    for(int i = 0; i < 5; ++i)
    {
        list.insert(list.end(), i);
    }
    for(auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    list.erase(list.begin());   
    list.erase(--list.end());
    for(auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    list.erase(list.begin(), list.end());
    for(auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}