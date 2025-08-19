#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H
#include"list_node.h"
namespace mystl
{
template<class _Ty>
class Iterator
{
public:
    Iterator() : _Node(nullptr) {}
    Iterator(_ListNode<_Ty>* const node) : _Node(node) {}
    Iterator(const Iterator& other) : _Node(other._Node) {}
    Iterator& operator = (const Iterator& other)
    {
        if(this == &other)
        {
            return *this;
        }
        _Node = other._Node;
        return *this;
    }
    Iterator& operator ++ ()
    {
        _Node = _Node->_Next; 
        return *this;
    }
    Iterator operator ++ (int)
    {
        Iterator it = *this;
        this->_Node = this->_Node->_Next;
        return it;
    }
    Iterator& operator -- ()
    {
        _Node = _Node->_Prev; 
        return *this;
    }
    Iterator operator -- (int)
    {
        Iterator it = *this;
        this->_Node = this->_Node->_Prev;
        return it;
    }
    bool operator == (const Iterator& other) const 
    {
        return _Node == other._Node;
    }
    bool operator != (const Iterator& other) const
    {
        return !(*this == other);
    }
    _Ty& operator * () const
    {
        return _Node->_Value;
    }
    _Ty* operator -> () const
    {
        return _Node;
    }
public:
    _ListNode<_Ty>* _Node;
};
}
#endif