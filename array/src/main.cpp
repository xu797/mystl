#include"myarray.h"
int main()
{
    mystl::Array<int, 10> a;
    a.fill(1);

    a.show();
    a[0] = 2;
    a.at(1) = 3;
    a.show();
    std::cout << a.back() << std::endl;
    std::cout << a.front() << std::endl;
    for(auto it = a.begin(); it != a.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}