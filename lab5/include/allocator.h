#pragma once

#include <array>
#include <stdexcept>
#include <cstdint>
#include <vector>


#define MAX_SIZE 1e5

template<class T>
class Allocator {
    private:
        static constexpr size_t POOL_SIZE = 20000;
        std::vector<T> _pool;
        std::vector<T*> _free;
    public:

        template <class U>
        struct rebind {
            using other = Allocator<U>;
        };

        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = std::size_t;

        Allocator();
        Allocator(Allocator &&other) noexcept;

        pointer allocate();
        pointer allocate(size_t n);
        void deallocate(pointer ptr);
        void deallocate(pointer ptr, size_type n);
    
        template<class T1, class ... ARGS>
        void construct(T1 *p, ARGS... args);
        void destroy(pointer p);

        Allocator &operator=(Allocator &&other) noexcept;

};

template <typename T>
Allocator<T>::Allocator(){
    _pool.reserve(POOL_SIZE);
    for (int i = 0; i < POOL_SIZE; ++i) {
        _free.push_back(&_pool[i]);
    }
}

template <typename T>
Allocator<T>::Allocator(Allocator &&other) noexcept{
    _pool = std::move(other._pool);
    _free = std::move(other._free);
}

template <typename T>
Allocator<T> &Allocator<T>::operator =(Allocator &&other) noexcept{
    _pool = std::move(other._pool);
    _free = std::move(other._free);
    return *this;
}

template <typename T>
T* Allocator<T>::allocate(){
    if (_free.empty()) {
        throw std::bad_alloc();
    }
    T* tmp = _free.back();
    _free.pop_back();
    return tmp;
}

template <typename T>
T* Allocator<T>::allocate(size_t n){
    if (_free.empty()) {
        throw std::bad_alloc();
    }
    for (size_t i = 0; i < n - 1; ++i) {
        _free.pop_back();
    }
    T* tmp = _free.back();
    _free.pop_back();
    return tmp;
}

template <typename T>
void Allocator<T>::deallocate(pointer ptr) {
    if (ptr < &_pool[0] || ptr > &_pool[0] + POOL_SIZE) {
        throw std::bad_alloc();
    }
    _free.push_back(ptr);
}

template <typename T>
void Allocator<T>::deallocate(pointer ptr, size_type n) {
    if (ptr < &_pool[0] || ptr > &_pool[0] + POOL_SIZE) {
        throw std::logic_error("Allocator does not own this pointer");
    }
    for (int i = 0; i < n; i++) {
        _free.push_back(ptr);
    }
}

template<class T>
template<class T1, class ... ARGS>
void Allocator<T>::construct(T1 *p, ARGS... args) 
{
    new (p) T1(std::forward<ARGS>(args)...);
};

template<class T>
void Allocator<T>::destroy(T* p) 
{
    p->~T();
}