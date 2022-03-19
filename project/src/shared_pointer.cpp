#include "../include/shared_pointer.hpp"

template<class T>
SharedPointer<T>::SharedPointer(T* pointer)
    : pointer(pointer),
      count(new int(1))
{}

template<class T>
SharedPointer<T>::SharedPointer(const SharedPointer<T>& other)
    : pointer(other.pointer),
      count(other.count)
{
    (*count)++;
}

template<class T>
SharedPointer<T>::~SharedPointer()
{
    (*count)--;
    if (*count == 0)
    {
        delete pointer;
        delete count;
    }
}


template<class T>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer& other) {
    if (this != &other)
    {
        pointer = other.pointer;
        count = other.count;
        (*count)++;
    }

    return *this;
}

template<class T>
T* SharedPointer<T>::operator->() {
    return pointer;    
}

template<class T>
T& SharedPointer<T>::operator*() {
    return *pointer;
}

template<class T>
int SharedPointer<T>::getCount() const {
    return *count;
}

#include <string>
template class SharedPointer<std::string>;