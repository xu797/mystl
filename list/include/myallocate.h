#ifndef MYALLOCATE_H
#define MYALLOCATE_H
#include<iostream>
namespace mystl
{
template<class _Ty>
_Ty* _MyAllocate(int _N, _Ty*)
{
    if(_N < 0)
    {
        _N = 0;
    }
    return (_Ty*)operator new(sizeof(_Ty) * (size_t)_N);
}
template<class _T1, class _T2>
void _MyConstruct(_T1* _P, const _T2& _V)
{
    new ((void*)_P) _T1(_V);
}
template<class _Ty>
void _MyDestroy(_Ty* _P)
{
    _P->~_Ty();
}
template<class _Ty>
class MyAllocate
{
public: 
    typedef     _Ty            value_type;
    typedef     _Ty&           reference;
    typedef     _Ty*           pointer;
    typedef     const _Ty&     const_reference;
    typedef     const _Ty*     const_pointer;
    typedef     size_t         size_type;
    typedef     int            difference_type;

    pointer allocate(size_type _N) const
    {
        return _MyAllocate((difference_type)_N, (pointer)0);
    }
    char* _Charalloc(size_type _N) const
    {
        return _MyAllocate((difference_type)_N, (char*)0);
    }
    void deallocate(void* _P)
    {
        operator delete(_P);
    }

    void construct(pointer _P, const_reference _V)
    {
        // new (_P) value_type(val);
        _MyConstruct(_P, _V);
    }
    void destroy(_Ty* _P)
    {
        _MyDestroy(_P);
    }
};
}
#endif