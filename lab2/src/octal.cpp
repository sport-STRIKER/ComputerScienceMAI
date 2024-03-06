#include "octal.h"

Octal::Octal()   // Default constructor
{
    _size = 1;
    _array = new unsigned char[1];
    _array[0] = '0';
}

Octal::Octal(const size_t &n, unsigned char t)  // Fill constructor
{
    if (t >= '8' || t < '0')
        throw std::underflow_error("invalid symbol");
    _array = new unsigned char[n];
    for (size_t i = 0; i < n; ++i)
        _array[n - i - 1] = t;
    _size = n;
}

Octal::Octal(const std::initializer_list<unsigned char> &t)  // Initializer list constructor
{
    _array = new unsigned char[t.size()];
    size_t i{t.size() - 1};
    for (auto &c : t) { 
        if (c >= '8' || c < '0')
            throw std::underflow_error("invalid symbol");
        _array[i--] = c;
    }
    _size = t.size();
}

Octal::Octal(const std::string &t)  // Copy string constructor
{
    _array = new unsigned char[t.size()];
    _size  = t.size();

    for(size_t i{0}; i < _size; ++i) {
        if (t[i] >= '8' || t[i] < '0')
            throw std::underflow_error("invalid symbol");
        _array[_size - i - 1] = t[i];
    }
}

Octal::Octal(const Octal &other)  // Copy constructor
{
    _size  = other._size;
    _array = new unsigned char[_size];

    for(size_t i{0}; i < _size; ++i)
        _array[i] = other._array[i];
}

Octal::Octal(Octal &&other) noexcept  // Move constructor
{
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

int Octal::size() const {
    return _size;
}

void Octal::convertToString(std::string & s) {
    this->removeZeros();
    for (int i = _size - 1; i >= 0; --i) {
        // s += _array[i];
        s.append(1, static_cast<char>(_array[i]));
    }
}

void Octal::addZeros(int n) {
    unsigned char * array = new unsigned char[n + this->_size];
    for (size_t i = 0; i < this->_size; ++i) {
        array[i] = this->_array[i];
    }
    for (size_t i = 0; i < n; ++i) {
        array[i + this->_size] = '0';
    }
    this->_size = n + this->_size;
    this->_array = array;
}

void Octal::removeZeros() {
    if (_array == nullptr) {
        return;
    }
    int t = -1;
    for (size_t i = 0; i < _size; ++i) {
        if (_array[_size - i - 1] != '0') {
            t = i;
            break;
        }
    }
    if (t == -1) {
        this->~Octal();
        this->_size = 1;
        this->_array = new unsigned char[1]{'0'};
    } else {
        unsigned char * array = new unsigned char[this->_size - t];
        for (size_t i = 0; i < this->_size - t; ++i) {
            array[i] = _array[i];
        }
        _size -= t;
        _array = array;
    }
}

bool Octal::equals(const Octal &other) const
{
    if (_size!=other._size) {
        return false;
    }
    for (size_t i = 0; i < _size; ++i) {
        if (this->_array[i] != other._array[i]) {
            return false;
        }
    }
    return true;
}

bool Octal::more(const Octal &other) const
{
    if (_size > other._size)
        return true;
    else if (_size == other._size)
        for (size_t i = 0; i < _size; ++i)
            if (_array[_size - i - 1] > other._array[_size - i - 1])
                return true;

    return false;
}

bool Octal::less(const Octal &other) const
{
    return !(this->equals(other) || this->more(other));
}

Octal Octal::sum(const Octal &other)
{
    size_t size;

    if (this->_size > other._size)
        size = this->_size + 1;
    else
        size = other._size + 1;

    Octal res(size);
    bool move = false;
    int notDiv;

    for (size_t i = 0; i < size - 1; ++i) {
        if (move) {
            if (this->_size <= i) {
                notDiv = other._array[i] - '0' + 1;
            } else if (other._size <= i) {
                notDiv = this->_array[i] - '0' + 1;
            } else {
                notDiv = (this->_array[i] - '0') + (other._array[i] - '0') + 1;
            }
            if (notDiv < 8)
                move = false;
            res._array[i] = (notDiv % 8) + '0';
        } else {
            if (this->_size <= i) {
                notDiv = other._array[i] - '0';
            } else if (other._size <= i) {
                notDiv = this->_array[i] - '0';
            } else {
                notDiv = (this->_array[i] - '0') + (other._array[i] - '0');
            }
            if (notDiv >= 8)
                move = true;
            res._array[i] = (notDiv % 8) + '0';
        }
    }

    if (move)
        res._array[size - 1] = '1';

    res.removeZeros();

    return res;
}

void Octal::add(const Octal &other) 
{
    if (this->_size > other._size)
        this->addZeros(1);
    else
        this->addZeros(other._size - this->_size + 1);

    bool move = false;
    int notDiv;

    for (size_t i = 0; i < _size - 1; ++i) {
        if (move) {
            if (other._size <= i) {
                notDiv = this->_array[i] - '0' + 1;
            } else {
                notDiv = (this->_array[i] - '0') + (other._array[i] - '0') + 1;
            }
            if (notDiv < 8)
                move = false;
            _array[i] = (notDiv % 8) + '0';
        } else {
            if (other._size <= i) {
                notDiv = this->_array[i] - '0';
            } else {
                notDiv = (this->_array[i] - '0') + (other._array[i] - '0');
            }
            if (notDiv >= 8)
                move = true;
            _array[i] = (notDiv % 8) + '0';
        }
    }

    if (move)
        _array[_size - 1] = '1';

    this->removeZeros();
}

Octal Octal::subtraction(const Octal &other)
{
    if(this->less(other))
        throw std::underflow_error("octal elem can't be negative");

    Octal res(*this);

    for (size_t i = 0; i < res._size; ++i) {
        if (i >= other._size)
            break;

        if (res._array[i] >= other._array[i])
            res._array[i] = (res._array[i] - other._array[i]) + '0';
        else {
            size_t j = i + 1;
            while (res._array[j] == '0') {
                res._array[j] += 7;
                ++j;
            }
            res._array[j] = res._array[j] - 1;
            res._array[i] += 8;
            res._array[i] = (res._array[i] - other._array[i]) + '0';
        }
    }

    res.removeZeros();

    return res;
}

void Octal::remove(const Octal &other) {
    if(this->less(other))
        throw std::underflow_error("three elem can't be negative");

    for (size_t i = 0; i < _size; ++i) {
        if (i >= other._size)
            break;
        if (_array[i] >= other._array[i])
            _array[i] = (_array[i] - other._array[i]) + '0';
        else {
            size_t j = i + 1;
            while (_array[j] == '0') {
                _array[j] += 7;
                ++j;
            }
            _array[j] = _array[j] - 1;
            _array[i] += 8;
            _array[i] = (_array[i] - other._array[i]) + '0';
        }
    }
    this->removeZeros();
}

std::ostream &Octal::print(std::ostream &os)
{
    this->removeZeros();
    for (size_t i = 0; i < _size; ++i)
        os << _array[_size - i - 1];
    
    os << '\n';

    return os;
}

Octal::~Octal() noexcept  // Destructor
{
    if (_array != nullptr)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}
