#include "mylist.h"
int main()
{
    mystl::MyList<int> myList;
    for(int i = 0; i < 5; ++i){
        myList.insert(myList.end(), i + 1);
    }

    mystl::MyList<int>::Iterator it = myList.begin();
    while (it != myList.end())
    {
        /* code */
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    myList.insert(myList.end(), 10, 2);
    it = myList.begin();
    while (it != myList.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    std::cout << myList.front() << " " << myList.back() << std::endl;
    myList.clear();
    it = myList.begin();
    while (it != myList.end())
    {
        /* code */
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    
    return 0;
}