#ifndef MYVECTOR_H
#define MYVECTOR_H
#include<iostream>
#include"myallocate.h"
namespace mystl
{
template<typename _Ty, typename _A = MyAllocate<_Ty>>
class MyVector
{
public:
    typedef _Ty* pointer;
    MyVector(int size = 10) 
    {
        std::cout << "constructor of MyVector" << std::endl;
        first_ = alloc_.allocate(size);
        // first_ = new _Ty[size];
        last_ = first_;
        end_ = first_ + size;
    } 
    MyVector(const MyVector<_Ty>& vec)
    {
        int size = vec.capacity();
        int num = vec.size();
        this->first_ = alloc_.allocate(size);
        this->last_ = this->first_ + num;
        this->end_ = this->first_ + size;
        for(int i = 0; i < num; ++i){
            // this->first_[i] = vec.first_[i];
            alloc_.construct(first_ + i, vec.first_[i]);
        }
    }
    MyVector<_Ty>& operator=(const MyVector<_Ty>& vec)
    {
        if(&vec == this)
        {
            return *this;
        }
        for(int i = 0; i < size(); ++i){
            alloc_.destroy(first_ + i);
        }
        alloc_.deallocate(first_);
        int size = vec.capacity();
        int num = vec.size();
        this->first_ = alloc_.allocate(size);
        this->last_ = this->first_ + num;
        this->end_ = this->first_ + size;
        for(int i = 0; i < num; ++i){
            alloc_.construct(first_ + i, vec.first_[i]);
        }
        return *this;
    }
    ~MyVector()
    {   
        std::cout << "destructor of MyVector" << std::endl;
        // delete []first_;
        int num = size();
        for(int i = 0; i < num; i++)
        {
            alloc_.destroy(first_ + i);
        }
        alloc_.deallocate(first_);
        first_ = nullptr;
        last_ = nullptr;
        end_ = nullptr;
    }
    void push_back(const _Ty& _T)
    {
        if(full()){
            expand();
        }
        // *last_ = _T;
        alloc_.construct(last_, _T);
        last_++;
    }
    void pop_back()
    {
        if(empty())
        {
            return;
        }
        last_--;
        alloc_.destroy(last_);
    }
    int size() const
    {
        return last_ - first_;
    }
    int capacity() const
    {
        return end_ - first_;
    }
    _Ty back() const
    {
        if(empty())
        {
            throw "vector is empty!";
        }
        return *(last_ - 1);
    } 
private:
    bool empty()const
    {
        return last_ == first_;
    }
    bool full()const
    {
        return last_ == end_;
    } 
    void expand()
    {
        int len = capacity();
        // pointer tmp = new _Ty[2 * len];
        pointer tmp = alloc_.allocate(2 * len);
        for(int i = 0; i < len; i++){
            // tmp[i] = first_[i];
            alloc_.construct(tmp + i, first_[i]);
            alloc_.destroy(first_ + i);
        }
        // delete []first_;
        alloc_.deallocate(first_);
        first_ = tmp;
        last_ = first_ + len;
        end_ = first_ + len * 2;
    }
private:
    pointer first_;
    pointer last_;
    pointer end_;
    _A alloc_;
};
}
#endif