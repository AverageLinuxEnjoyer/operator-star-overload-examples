#include "../include/vector.hpp"
#include <exception>

template<class T>
Vector<T>::Vector(int size_)
    : data(nullptr),
      size(size_),
      capacity(10)
{
    data = new T[capacity];
}

template<class T>
Vector<T>::Vector(const Vector& other)
    : data(nullptr),
      size(other.size),
      capacity(other.capacity)
{
    this->data = new T[this->capacity];
    for (int i = 0; i < this->size; ++i) {
        this->data[i] = other.data[i];
    }
}

template<class T>
Vector<T>::~Vector()
{
    if (this->data)
        delete[] this->data;
}


template<class T>
void Vector<T>::resize(int size_) {
    if (size_ < 0)
        throw std::exception();

    if (size_ > this->capacity)
    {
        this->capacity = size_;
        T* newData = new T[this->capacity];
        for (int i = 0; i < this->size; ++i)
            newData[i] = this->data[i];

        delete[] this->data;
        this->data = newData;
    }

    this->size = size_;
}


template<class T>
void Vector<T>::push_back(const T& element) {
    if (this->size == this->capacity)
        this->resize(this->capacity * 2);

    this->data[this->size++] = element;    
}

template<class T>
void Vector<T>::pop_back() {
    if (this->size == 0)
        throw std::exception();

    this->size--;    
}

template<class T>
Iterator<T> Vector<T>::begin() const {
    return Iterator<T>(*this, 0);
}

template<class T>
Iterator<T> Vector<T>::end() const {
    return Iterator<T>(*this, this->size);
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other)
    {
        if (this->data)
            delete[] this->data;

        this->size = other.size;
        this->capacity = other.capacity;

        this->data = new T[this->capacity];
        for (int i = 0; i < this->size; ++i)
            this->data[i] = other.data[i];
    }   

    return *this;
}

template<class T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= this->size)
        throw std::exception();

    return this->data[index];
}

template<class T>
T* Vector<T>::getData() const {
    return this->data;
}

template<class T>
int Vector<T>::getSize() const {
    return this->size;    
}

template<class T>
int Vector<T>::getCapacity() const {
    return this->capacity;
}

template class Vector<int>;