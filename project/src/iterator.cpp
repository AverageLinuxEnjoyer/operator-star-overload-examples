#include "../include/iterator.hpp"
#include "../include/vector.hpp"

template<typename T>
Iterator<T>::Iterator(const Vector<T> &vector, int index_)
    : data(vector.getData()),
      size(vector.getSize()),
      capacity(vector.getCapacity()),
      index(index_)
{}


template<typename T>
Iterator<T>::Iterator(const Iterator& other)
    : data(other.data),
      size(other.size),
      capacity(other.capacity),
      index(other.index)
{}

template<typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator& other) {
    if (this != &other)
    {
        this->data = other.data;
        this->size = other.size;
        this->capacity = other.capacity;
        this->index = other.index;
    }

    return *this;
}


template<typename T>
Iterator<T>& Iterator<T>::operator++() {
    if (this->index == this->size)
        throw std::exception();

    this->index++;
    return *this;
}


template<typename T>
Iterator<T> Iterator<T>::operator++(int) {
    Iterator<T> temp(*this);
    ++(*this);
    return temp;   
}

template<typename T>
Iterator<T>& Iterator<T>::operator--() {
    if (this->index == 0)
        throw std::exception();

    this->index--;
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator--(int) {
    Iterator<T> temp(*this);
    --(*this);
    return temp;
}

template<typename T>
T& Iterator<T>::operator*() {
    return this->data[this->index];
}

template<typename T>
bool Iterator<T>::operator==(const Iterator& other) const {
    if (this->data != other.data)
        return false;
    else if (this->capacity != other.capacity)
        return false;
    else if (this->size != other.size)
        return false;
    else if (this->index != other.index)
        return false;
    else
        return true;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator& other) const {
    return !(*this == other);    
}

template class Iterator<int>;