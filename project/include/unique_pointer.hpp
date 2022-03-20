#ifndef UNIQUE_POINTER_HPP
#define UNIQUE_POINTER_HPP

template<class T>
class UniquePointer {
public:
    // constructor
    UniquePointer(T* pointer_);

    // constructor de copiere sters, unique pointer-ul nu trebuie copiat
    UniquePointer(const UniquePointer& other) = delete;

    // destructor
    ~UniquePointer();

    // copy assignment operator sters, unique pointer-ul nu trebuie copiat
    UniquePointer& operator=(const UniquePointer& other) = delete;

    // operator de acces/dereferentiere
    T* operator->();
    T& operator*();

    // reseteaza pointer-ul
    void reset(T* pointer_);

private:
    T* pointer;
};

template<class T>
inline UniquePointer<T>::UniquePointer(T* pointer_)
    : pointer(pointer_) {}

template<class T>
inline UniquePointer<T>::~UniquePointer() {
    delete pointer;
}

template<class T>
inline T* UniquePointer<T>::operator->() {
    return pointer;
}

template<class T>
inline T& UniquePointer<T>::operator*() {
    return *pointer;
}

template<class T>
inline void UniquePointer<T>::reset(T* pointer_) {
    delete pointer;
    pointer = pointer_;
}


#endif // UNIQUE_POINTER_HPP
