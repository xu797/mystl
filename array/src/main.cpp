#include"myarray.h"
int main()
{
    mystl::Array<int, 10> a;
    a.fill(1);
    a[0] = 2;
    a.at(1) = 3;
    std::cout << a.back() << std::endl;
    std::cout << a.front() << std::endl;
    for(auto it = a.begin(); it != a.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for(auto it = a.cbegin(); it != a.cend(); ++it)
    {
        std::cout << *it << " ";
        // *it = 
    }
    std::cout << std::endl;
    for(auto it = a.rbegin(); it != a.rend(); ++it)
    {
        std::cout << *it << " ";
        // *it = 
    }
    std::cout << std::endl;

    for(auto it = a.crbegin(); it != a.crend(); ++it)
    {
        std::cout << *it << " ";
        // *it = 
    }
    std::cout << std::endl;
}