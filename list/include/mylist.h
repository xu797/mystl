#ifndef MYLIST_H
#define MYLIST_H
#include"myallocate.h"
namespace mystl
{
template<class _Ty, class _A = MyAllocate<_Ty>>
class MyList
{
public:
    typedef typename _A::difference_type      difference_type;
    typedef typename _A::size_type            size_type;
    typedef typename _A::value_type           value_type;
    typedef typename _A::pointer              pointer;
    typedef typename _A::reference            reference;
    typedef typename _A::const_pointer        const_pointer;
    typedef typename _A::const_reference      const_reference;
    
    //----------------list_node------------------------------
    struct _Node;
    typedef    _Node*   _NodePtr;
    struct _Node
    {
        _NodePtr _Next;
        _NodePtr _Prev;
        value_type _Value;
    };
    //----------------ACC------------------------------------
    struct _Acc
    {
        typedef     _NodePtr&       _Nodepref;
        typedef     value_type&     _Vref;
        static _Nodepref _Next(_Nodepref _P)
        {
            return (_Nodepref)((*_P)._Next);
        }
        static _Nodepref _Prev(_Nodepref _P)
        {
            return (_Nodepref)((*_P)._Prev);
        }
        static _Vref _Value(_Nodepref _P)
        {
            return (_Vref)((*_P)._Value);
        }
    };
    //----------------list_iterator----------------------------
    class Iterator
    {
    public:
        Iterator(_NodePtr node = nullptr) : _Node(node) {}
        ~Iterator() {}
        Iterator(const Iterator& it) : _Node(it._Node) {}
        Iterator& operator = (const Iterator& it) 
        {
            if(this == &it) { return *this; }
            _Node = it._Node;
            return *this;
        }
        bool operator == (const Iterator& other) const
        {
            return _Node == other._Node;
        }
        bool operator != (const Iterator& other) const
        {
            return _Node != other._Node;
        }
        reference operator * ()
        {
            return _Acc::_Value(_Node);
        }
        Iterator& operator ++ ()
        {
            this->_Node = _Acc::_Next(_Node);
            return *this;
        }
        Iterator operator ++ (int)
        {
            Iterator it = *this;
            ++(*this);
            return it;
        }
        Iterator& operator -- ()
        {
            this->_Node = _Acc::_Prev(_Node);
            return *this;
        }
        Iterator operator -- (int)
        {
            Iterator it = *this;
            --(*this);
            return it;
        }
        _NodePtr _MyNode() const
        {
            return _Node;
        }
    protected:
        _NodePtr _Node;
    };
    //--------------------construct/destruct---------------------
    explicit MyList() : _Head(_BuyNode()), _Size(0) 
    {}
    explicit MyList(size_type _N, const_reference _Val) : _Head(_BuyNode()), _Size(0)
    {
        insert(end(), _N, _Val);
    }
    // MyList(const_pointer _F, const_pointer _L) : _Head(_BuyNode()), _Size(0)
    // {
    //     insert(end(), _F, _L);
    // }
    // MyList(_It _F, _It _L) : _Head(_BuyNode()), _Size(0)
    // {
    //     insert(end(), _F, _L);
    // }
    //-------------------begin()/end()----------------------
    Iterator begin()
    {
        return Iterator(_Acc::_Next(_Head));
    }
    Iterator end() const
    {
        return Iterator(_Head);
    }
    //------------------------insert------------------------
    Iterator insert(Iterator _P, const_reference _V = _Ty())
    {
        _NodePtr _S = _P._MyNode();
        _Acc::_Prev(_S) = _BuyNode(_S, _Acc::_Prev(_S));
        _S = _Acc::_Prev(_S);
        _Acc::_Next(_Acc::_Prev(_S)) = _S;
        _Alloc.construct(&_Acc::_Value(_S), _V);
        _Size++;
        return Iterator(_S);
    }
    void insert(Iterator _P, size_type _N ,const_reference _V = _Ty())
    {
        for(int i = 0; i < _N; ++i)
        {
            insert(_P, _V);
        }
    }
    void insert(Iterator _P, Iterator _F, Iterator _L)
    {
        while (_F != _L)
        {
            insert(_P, *_F);
            ++_F;
        } 
    }
    //------------------------erase------------------------
    Iterator erase(Iterator _P)
    {
        _NodePtr ptr = (_P++)._MyNode();
        _Acc::_Next(_Acc::_Prev(ptr)) = _Acc::_Next(ptr);
        _Acc::_Prev(_Acc::_Next(ptr)) = _Acc::_Prev(ptr);
        _Alloc.destroy(&_Acc::_Value(ptr));
        _FreeNode(ptr);
        _Size--;
        return _P;
    }
    Iterator erase(Iterator _F, Iterator _L)
    {
        while (_F != _L)
        {
            erase(_F++);
        }
        return _F;
    }
    size_type size() const
    {
        return _Size;
    }
    bool empty() const
    {
        return size() == 0;
    }
    void push_back(const_reference _V)
    {
        insert(end(), _V);
    }
    void push_front(const_reference _V)
    {
        insert(begin(), _V);
    }
    void pop_back()
    {
        erase(--end());
    }
    void pop_front()
    {
        erase(begin());
    }
    void clear()
    {
        erase(begin(), end());
    }
    reference front(){
        return *(begin());
    }
    reference back(){
        return *(--end());
    }
private:
    _NodePtr _BuyNode(_NodePtr _Narg = nullptr, _NodePtr _Parg = nullptr)
    {
        _NodePtr _S = (_NodePtr)_Alloc._Charalloc(sizeof(_Node));
        _Acc::_Next(_S) = (_Narg != nullptr ? _Narg : _S);
        _Acc::_Prev(_S) = (_Parg != nullptr ? _Parg : _S);
        return _S;
    }
    void _FreeNode(_NodePtr _P)
    {
        _Alloc.deallocate(_P);
    }
private:
    _NodePtr _Head;
    size_type _Size;
    _A _Alloc;
};
}
#endif