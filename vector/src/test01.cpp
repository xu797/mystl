#include "myvector.h"

// 测试基本功能
void testBasicOperations() {
    std::cout << "=== 测试基本操作 ===" << std::endl;
    my::myVector<int> vec;
    
    // 测试初始状态
    std::cout << "初始状态 - 大小: " << vec.size() 
              << ", 容量: " << vec.capacity() << std::endl;
    
    // 测试push_back
    for (int i = 0; i < 12; ++i) {
        vec.push_back(i * 10);
        std::cout << "添加 " << i*10 << " 后 - 大小: " << vec.size() 
                  << ", 容量: " << vec.capacity() << std::endl;
    }
    
    // 测试back()
    std::cout << "最后一个元素: " << vec.back() << std::endl;
    
    // 测试pop_back
    for (int i = 0; i < 5; ++i) {
        vec.pop_back();
        std::cout << "删除后 - 大小: " << vec.size() 
                  << ", 最后元素: " << vec.back() << std::endl;
    }
    std::cout << std::endl;
}

// 测试拷贝构造和赋值
void testCopyAndAssign() {
    std::cout << "=== 测试拷贝和赋值 ===" << std::endl;
    my::myVector<std::string> vec;
    vec.push_back("Hello");
    vec.push_back("World");
    vec.push_back("myVector");
    
    // 测试拷贝构造
    my::myVector<std::string> vec2(vec);
    std::cout << "拷贝构造的vec2 - 大小: " << vec2.size() 
              << ", 最后元素: " << vec2.back() << std::endl;
    
    // 测试赋值运算符
    my::myVector<std::string> vec3;
    vec3 = vec;
    std::cout << "赋值后的vec3 - 大小: " << vec3.size() 
              << ", 最后元素: " << vec3.back() << std::endl;
    
    // 修改原向量，验证深拷贝
    vec.push_back("Test");
    std::cout << "原向量添加元素后 - vec大小: " << vec.size() 
              << ", vec2大小: " << vec2.size() << std::endl;
    std::cout << std::endl;
}

// 测试空向量和扩容边界
void testEdgeCases() {
    std::cout << "=== 测试边界情况 ===" << std::endl;
    // 测试空向量pop_back
    my::myVector<double> emptyVec;
    std::cout << "空向量删除元素前 - 大小: " << emptyVec.size() << std::endl;
    emptyVec.pop_back(); // 应该无操作
    std::cout << "空向量删除元素后 - 大小: " << emptyVec.size() << std::endl;
    
    // 测试空向量push_back
    emptyVec.push_back(3.14);
    emptyVec.push_back(2.718);
    std::cout << "空向量添加元素后 - 大小: " << emptyVec.size() 
              << ", 元素: " << emptyVec.back() << std::endl;
    
    // 测试扩容机制（从初始容量10开始）
    my::myVector<char> charVec(5); // 自定义初始容量
    std::cout << "charVec初始容量: " << charVec.capacity() << std::endl;
    for (char c = 'a'; c <= 'k'; ++c) { // 添加11个元素
        charVec.push_back(c);
    }
    std::cout << "添加11个元素后 - 大小: " << charVec.size() 
              << ", 容量: " << charVec.capacity() << std::endl;
    std::cout << std::endl;
}

// 测试异常情况
void testExceptions() {
    std::cout << "=== 测试异常处理 ===" << std::endl;
    my::myVector<int> vec;
    try {
        vec.back(); // 空向量调用back()
    } catch (const char* msg) {
        std::cout << "捕获异常: " << msg << std::endl;
    }
}

int main() {
    testBasicOperations();
    testCopyAndAssign();
    testEdgeCases();
    testExceptions();
    
    return 0;
}
