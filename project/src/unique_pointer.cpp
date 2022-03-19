#include "../include/unique_pointer.hpp"


template<class T>
UniquePointer<T>::UniquePointer(T* pointer_)
    : pointer(pointer_)
{
    
}

template<class T>
UniquePointer<T>::~UniquePointer()
{
    delete this->pointer;
}

template<class T>
T* UniquePointer<T>::operator->()
{
    return this->pointer;
}

template<class T>
T& UniquePointer<T>::operator*()
{
    return *this->pointer;
}

#include <string>
template class UniquePointer<std::string>;