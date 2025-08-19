#ifndef MYLIST_H
#define MYLIST_H
#include"myallocator.h"
#include"list_node.h"
#include"list_iterator.h"
namespace mystl
{
template<class _Ty, class Alloc = MyAllocator<_ListNode<_Ty>>>
class List
{
public:
    typedef     _Ty            value_type;
    typedef     _Ty&           reference;
    typedef     const _Ty&     const_reference;
    typedef     _Ty*           pointer;
    typedef     const _Ty*     const_pointer;
    typedef     size_t         size_type;
    typedef     int            difference_type;

    typedef     Iterator<_Ty>  iterator;
    typedef     _ListNode<_Ty> node;
    typedef     node*          _NodePtr;

    List()
    {
        _Head = _BuyNode();
        _Head->_Next = _Head;
        _Head->_Prev = _Head;
    }
    iterator begin()
    {
        return iterator(_Head->_Next);
    }
    iterator end()
    {
        return iterator(_Head);
    }
    //insert
    iterator insert(iterator it, const value_type& val)
    {
        _NodePtr tmp = _BuyNode();
        tmp->_Value = val;
        tmp->_Next = it._Node;
        tmp->_Prev = it._Node->_Prev;
        tmp->_Prev->_Next = tmp;
        it._Node->_Prev = tmp;
        return iterator(tmp);
    }
    //https://www.bilibili.com/video/BV1UTcBe1Egi/?spm_id_from=333.337.search-card.all.click&vd_source=2f952035f10e5522a8ae5d16228272bc
private:
    _NodePtr _BuyNode() const
    {
        return alloc.allocate(1);
    }
    _NodePtr _FreeNode(_NodePtr _P) const
    {
        alloc.desallocate(_P);
    }
private:
    _NodePtr _Head;
    Alloc alloc;
};
}

#endif