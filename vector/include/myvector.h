#ifndef MYVECTOR_H
#define MYVECTOR_H
#include<iostream>
namespace my
{
template<typename _Ty>
class myVector
{
public:
    typedef _Ty* pointer;
    myVector(int size = 10) 
    {
        std::cout << "constructor of MyVector" << std::endl;
        first_ = new _Ty[size];
        last_ = first_;
        end_ = first_ + size;
    } 
    myVector(const myVector<_Ty>& vec)
    {
        int size = vec.capacity();
        int num = vec.size();
        this->first_ = new _Ty[size];
        this->last_ = this->first_ + num;
        this->end_ = this->first_ + size;
        for(int i = 0; i < num; ++i){
            this->first_[i] = vec.first_[i];
        }
    }
    myVector<_Ty>& operator=(const myVector<_Ty>& vec)
    {
        if(&vec == this)
        {
            return *this;
        }
        delete []first_;
        int size = vec.capacity();
        int num = vec.size();
        this->first_ = new _Ty[size];
        this->last_ = this->first_ + num;
        this->end_ = this->first_ + size;
        for(int i = 0; i < num; ++i){
            this->first_[i] = vec.first_[i];
        }
        return *this;
    }
    ~myVector()
    {   
        std::cout << "destructor of MyVector" << std::endl;
        delete []first_;
        first_ = nullptr;
        last_ = nullptr;
        end_ = nullptr;
    }
    void push_back(const _Ty& _T)
    {
        if(full()){
            expand();
        }
        *last_ = _T;
        last_++;
    }
    void pop_back()
    {
        if(empty())
        {
            return;
        }
        last_--;
    }
    int size()const
    {
        return last_ - first_;
    }
    _Ty back()const
    {
        if(empty())
        {
            throw "vector is empty!";
        }
        return *(last_ - 1);
    }
    int capacity()const
    {
        return end_ - first_;
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
        pointer tmp = new _Ty[2 * len];
        for(int i = 0; i < len; i++){
            tmp[i] = first_[i];
        }
        delete []first_;
        first_ = tmp;
        last_ = first_ + len;
        end_ = first_ + len * 2;
    }
private:
    pointer first_;
    pointer last_;
    pointer end_;
};
}
#endif