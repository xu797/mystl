#ifndef LIST_NODE_H
#define LIST_NODE_H
namespace mystl
{
template<class _Ty>
struct _ListNode
{
    _ListNode* _Next;
    _ListNode* _Prev;
    _Ty _Value;
};
}
#endif 