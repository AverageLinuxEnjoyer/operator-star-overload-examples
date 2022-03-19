#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"

template<class T>
class Vector {
public:
    // constructori
    Vector(int size_ = 0);

    // copy constructor
    Vector(const Vector& other);

    // destructor
    ~Vector();

    // operatii vector
    void resize(int size_);
    void push_back(const T& element);
    void pop_back();

    Iterator<T> begin() const;
    Iterator<T> end() const;

    // copy assignment operator
    Vector& operator=(const Vector& other);

    // operator[]
    T& operator[](int index);

    // getteri
    T* getData() const;
    int getSize() const;
    int getCapacity() const;

private:
    T* data;
    int size;
    int capacity;
};





#endif // VECTOR_HPP
