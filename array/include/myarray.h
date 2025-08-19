#ifndef MYARRAY_H
#define MYARRAY_H
#include<iostream>
namespace mystl
{
template<typename _T, size_t _N>
class Array
{
public:
    typedef _T value_type;
    typedef _T& reference;
    typedef const _T& const_reference;
    typedef _T* pointer;
    typedef const _T* const_pointer;
    typedef size_t size_type;
    typedef int difference_type;

    Array(){
        for(int i = 0; i < _N; ++i){
            m_data[i] = 0;
        }
    }
    ~Array(){}

    size_type size() const{
        return _N;
    }
    size_type max_size() const{
        return _N;
    }

    bool empty() const{
        return _N == 0;
    }

    pointer data(){
        return m_data;
    }
    const_pointer data() const{
        return m_data;
    }
    void swap(Array<_T, _N>& other){
        if(this == &other){
            return;
        }
        for(int i = 0; i < _N; ++i){
            auto tmp = m_data[i];
            m_data[i] = other.m_data[i];
            other.m_data[i] = tmp;
        }
    }
    void fill(const_reference val){
        for(int i = 0; i < _N; ++i){
            m_data[i] = val;
        }
    }

    reference front(){
        return m_data[0];
    }
    const_reference front() const{
        return m_data[0];
    }

    reference back(){
        return m_data[_N - 1];
    }
    const_reference back() const{
        return m_data[_N -1];
    }

    reference at(size_type index){
        if(index < 0 || index >= _N){
            throw "out of range";
        }
        return m_data[index];
    }
    const_reference at(size_type index) const{
        if(index < 0 || index >= _N){
            throw "out of range";
        }
        return m_data[index];
    }

    reference operator[](size_type index){
        if(index < 0 || index >= _N){
            throw "out of range";
        }
        return m_data[index];
    }
    const_reference operator[](size_type index) const{
        if(index < 0 || index >= _N){
            throw "out of range";
        }
        return m_data[index];
    }
    void show() const{
        std::cout << size() << std::endl;
        for(int i = 0; i < _N; i++){
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }
private:
    _T m_data[_N];
};
}
#endif