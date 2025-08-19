#ifndef MYARRAY_CONST_REVERSE_ITERATOR_H
#define MYARRAY_CONST_REVERSE_ITERATOR_H

namespace mystl
{
template<typename _T>
class ArrayConstReverseIterator
{
public:
    typedef ArrayConstReverseIterator<_T> iterator;

    ArrayConstReverseIterator() : m_pointer(nullptr) {}
    ArrayConstReverseIterator(_T* p) : m_pointer(p) {}
    ~ArrayConstReverseIterator(){}

    bool operator == (const iterator& array) const
    {
        return m_pointer == array.m_pointer;
    }

    bool operator != (const iterator& array) const
    {
        return m_pointer != array.m_pointer;
    }

    iterator& operator = (const iterator& array)
    {
        if(this == &array){
            return *this;
        }
        m_pointer = array.m_pointer;
        return *this;
    }

    iterator& operator ++ ()
    {
        m_pointer--;
        return *this;
    }

    iterator operator ++ (int)
    {
        iterator it = *this;
        ++(*this);
        return it;
    }
    
    iterator& operator -- ()
    {
        m_pointer++;
        return *this;
    }

    iterator operator -- (int)
    {
        iterator it = *this;
        --(*this);
        return it;
    }

    iterator operator + (int n)
    {
        iterator it = *this;
        it.m_pointer -= n;
        return it;
    }

    iterator operator - (int n)
    {
        iterator it = *this;
        it.m_pointer += n;
        return it;
    }

    iterator& operator += (int n)
    {
        m_pointer -= n;
        return *this;
    }

    iterator& operator -= (int n)
    {
        m_pointer += n;
        return *this;
    }

    int operator - (const iterator& other) const
    {
        return this->m_pointer - other.m_pointer;
    }

    const _T& operator * ()
    {
        return *m_pointer;
    }

    const _T* operator -> ()
    {
        return m_pointer;
    }
private:
    _T* m_pointer;
};
}

#endif