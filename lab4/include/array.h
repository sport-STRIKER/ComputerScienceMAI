#pragma once

#include <memory>

#include <figure.h>

template<class T>
class Array
{ 
public:
    Array();
    Array(const std::initializer_list<T> &t) ;
    Array(size_t size);
    Array(const Array<T>& other);
    Array(Array<T>&& other) noexcept;
    
    T& operator[](int ind) const;
    Array<T>& operator=(const Array<T>& other);
    Array<T>& operator=(Array<T>&& other);

    template<class U>
    friend std::ostream& operator<<(std::ostream&, const Array<U>&);

    int size() const;
    void erase(int ind);
    void insert(int ind, T elem);

    virtual ~Array() = default;

protected:
    void copy(const Array<T>& other);
    void move(Array<T>&& other);

protected:
    size_t _size;
    size_t _capacity;
    std::shared_ptr<T[]> _array;
};

template<class T>
Array<T>::Array() {
    _size = 0;
    _capacity = 0;
    std::shared_ptr<T[]> _array = std::shared_ptr<T[]>();
}

template<class T>
Array<T>::Array(const std::initializer_list<T> &t) 
{
    _size = t.size();
    _capacity = _size;
    _array = std::shared_ptr<T[]>(new T[_capacity]);
    int i = 0;
    for (T elem : t) { 
        _array[i] = elem;
        ++i;
    }
}

template<class T>
Array<T>::Array(size_t size) {
    _size = size;
    _capacity = size;
    _array = std::shared_ptr<T[]>(new T[_capacity]);
}

template<class T>
void Array<T>::copy(const Array<T>& other) {
    _size  = other._size;
    _capacity = other._capacity;
    _array = std::shared_ptr<T[]>( new T[_capacity]);
    for(size_t i = 0; i < _size; ++i) _array[i] = other._array[i];
}

template<class T>
void Array<T>::move(Array<T>&& other) {
    _size = other._size;
    _capacity = other._capacity;
    _array = other._array;

    other._size = 0;
    other._capacity = 0;
}

template<class T>
Array<T>::Array(const Array<T>& other) {
    copy(other);
}

template<class T>
Array<T>::Array(Array<T>&& other) noexcept {
    move(std::move(other));
}

template<class T>
T& Array<T>::operator[](int ind) const {
    return _array[ind];
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    copy(other);
    return *this;
}

template<class T>
Array<T>& Array<T>::operator=(Array<T>&& other) {
    move(std::move(other));
    return *this;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Array<T>& other) {
    for (int i = 0; i < other._size; ++i) {
        out << other._array[i] << std::endl;
    }
    return out;
}

template<class T>
int Array<T>::size() const {
    return _size;
}

template<class T>
void Array<T>::erase(int ind) {
    if (ind >= _size || ind < 0) {
        throw std::range_error("Invalid index\n");
    }
    for (int i = ind; i < _size - 1; ++i) {
        _array[i] = _array[i + 1];
    }
    --_size;
}

template<class T>
void Array<T>::insert(int ind, T elem) {
    if (ind > _size || ind < 0) {
        throw std::range_error("Invalid index\n");
    }
    ++_size;
    if (_capacity >= _size) {
        for (int i = ind + 1; i < _size; ++i) {
            _array[i] = _array[i - 1];
        }
        _array[ind] = elem;
    } else {
        _capacity = _size;
        std::shared_ptr<T[]> new_array (new T[_capacity]);
        for (int i = 0; i < ind; ++i) {
            new_array[i] = _array[i];
        }
        new_array[ind] = elem;
        for (int i = ind + 1; i < _size; ++i) {
            new_array[i] = _array[i - 1];
        }
        _array = new_array;
    }
}
