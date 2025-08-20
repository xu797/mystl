#include"myvector.h"
class test
{
public:
    test()
    {
        std::cout << "test()" << std::endl;
    }
    test(const test&)
    {
        std::cout << "test&" << std::endl;
    }
    ~test()
    {
        std::cout << "~test()" << std::endl;
    }
};
int main()
{
    mystl::MyVector<test> vec;
    test test1;
    test test2;
    vec.push_back(test1);
    vec.push_back(test2);
    vec.push_back(test1);
    vec.push_back(test2);
    
    return 0;
}