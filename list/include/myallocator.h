#ifndef MYALLOCATOR_H
#define MYALLOCATOR_H
namespace mystl
{
template<class _Ty>
class MyAllocator
{
public:
    typedef     _Ty            value_type;
    typedef     _Ty&           reference;
    typedef     const _Ty&     const_reference;
    typedef     _Ty*           pointer;
    typedef     const _Ty*     const_pointer;
    typedef     size_t         size_type;
    typedef     int            difference_type;
    pointer allocate(size_type _N) const
    {
        return (pointer)operator new(_N * sizeof(value_type));
    }

    void deallocate(pointer _P)
    {
        operator delete(_P);
    }
private:
    
};
}
#endif