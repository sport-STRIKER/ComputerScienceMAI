#include "../include/array.h"
#include "../include/figure.h"

Array::operator double() {
    if (_size == 0) {
        throw std::invalid_argument("No figures");
    }
    double sum = 0;
    for (int i = 0; i < _size; ++i) {
        sum += double(*_array[i]);
    }
    return sum;
}

void Array::squareOfEachFigure() const {
    for (int i = 0; i < _size; ++i) {
        double s = double(*_array[i]);
        std::cout << s << ' ';
    }
    std::cout << std::endl;
}

void Array::center() const {
    for (int i = 0; i < _size; ++i) {
        std::cout << (*_array[i]).center().x << ' ' << (*_array[i]).center().y << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Array& other) {
    for (int i = 0; i < other._size; ++i) {
        out << other._array[i] << std::endl;
    }
    return out;
}

size_t Array::size() {
    return _size;
}

void Array::erase(int ind) {
    if (ind >= _size || ind < 0) {
        throw std::range_error("Invalid index\n");
    }
    for (int i = ind; i < _size - 1; ++i) {
        _array[i] = _array[i + 1];
    }
    --_size;
}

void Array::insert(int ind, Figure* elem) {
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
        Figure** new_array = new Figure*[_size];
        for (int i = 0; i < ind; ++i) {
            new_array[i] = _array[i];
        }
        new_array[ind] = elem;
        for (int i = ind + 1; i < _size; ++i) {
            new_array[i] = _array[i - 1];
        }
        delete[] _array;
        _array = new_array;
    }
}
