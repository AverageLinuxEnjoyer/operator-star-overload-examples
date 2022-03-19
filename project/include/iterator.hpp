#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <exception>

template<class T>
class Vector;

template<typename T>
class Iterator {
public:
    Iterator(const Vector<T> &vector, int index_);
    Iterator(const Iterator& other);
    ~Iterator() = default;

    Iterator& operator=(const Iterator& other);

    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);

    T& operator*();

    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;

private:
    T* data;
    int size;
    int capacity;
    int index;
};

#endif // ITERATOR_HPP
