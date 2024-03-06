#pragma once

#include <string>
#include <iostream>

class Octal
{ 
public:
    Octal();
    Octal(const size_t & n, unsigned char t = '0');
    Octal(const std::initializer_list< unsigned char> &t);
    Octal(const std::string &t);
    Octal(const Octal& other);
    Octal(Octal&& other) noexcept;      

    int size() const;
    void convertToString(std::string & s);    

    bool equals(const Octal& other) const;
    bool more(const Octal &other) const;
    bool less(const Octal &other) const;
    Octal sum(const Octal& other);
    void add(const Octal& other);
    Octal subtraction(const Octal& other);
    void remove(const Octal& other);
    std::ostream& print(std::ostream& os);

    virtual ~Octal() noexcept;

private:
    void addZeros(int n);
    void removeZeros();

private:
    size_t _size;
    unsigned char *_array;
};
