#ifndef ARRAY_H
#define ARRAY_H

#include "figure.h"

class Array
{ 
public:
    Array() : _array(nullptr), _size(0), _capacity(0) {};
    Array(const std::initializer_list<Figure*> &t) 
    {
        _size = t.size();
        _capacity = _size;
        _array = new Figure*[_size];
        int i = 0;
        for (Figure* elem : t) { 
            _array[i] = elem;
            ++i;
        }
    };
    Array(const Array& other) {
        _size  = other._size;
        _capacity = other._capacity;
        _array = new Figure*[_capacity];
        for(size_t i = 0; i < _size; ++i) _array[i] = other._array[i];
    };
    Array(Array&& other) noexcept {
        _size = other._size;
        _capacity = other._capacity;
        _array = other._array;

        other._size = 0;
        other._capacity = 0;
        other._array = nullptr;
    };

    operator double();
    void squareOfEachFigure() const;
    void center() const;
    friend std::ostream& operator<<(std::ostream&, const Array&);
    size_t size();
    void erase(int ind);
    void insert(int ind, Figure* elem);

    virtual ~Array() = default;

protected:
    size_t _size;
    size_t _capacity;
    Figure** _array;
};

#endif