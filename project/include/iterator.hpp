#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <exception>

template<class T>
class Vector;

template<typename T>
class Iterator {
public:
    // construtori
    Iterator(const Vector<T> &vector, int index_);
    Iterator(const Iterator& other);

    // destructor default, nu face nimic
    ~Iterator() = default;

    // copy assignment operator
    Iterator& operator=(const Iterator& other);

    // incrementare si decrementare iterator
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);

    // operator de acces/dereferentiere
    T& operator*();

    // operatori de comparare
    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;

private:
    T* data;
    int size;
    int capacity;
    int index;
};

#endif // ITERATOR_HPP
