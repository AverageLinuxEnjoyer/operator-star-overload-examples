#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP

template<class T>
class SharedPointer {
public:
    // constructori
    SharedPointer(T* pointer_);
    SharedPointer(const SharedPointer& other);

    // destructor
    ~SharedPointer();

    // copy assignment operator
    SharedPointer& operator=(const SharedPointer& other);

    // operator de acces/dereferentiere
    T* operator->();
    T& operator*();

    // getter numar de referinte
    int getCount() const;

    // reseteaza pointer-ul
    void reset(T* pointer_);

private:
    T* pointer;
    int* count;
};

// constructori
template<class T>
inline SharedPointer<T>::SharedPointer(T* pointer_) 
    : pointer(pointer_), count(new int(1)) {}

template<class T>
inline SharedPointer<T>::SharedPointer(const SharedPointer& other) {
    pointer = other.pointer;
    count = other.count;
    ++(*count);
};

// destructor
template<class T>
inline SharedPointer<T>::~SharedPointer() {
    if (--(*count) == 0) {
        delete pointer;
        delete count;
    }
};

// operator de acces/dereferentiere
template<class T>
inline T* SharedPointer<T>::operator->() {
    return pointer;
};

template<class T>
inline T& SharedPointer<T>::operator*() {
    return *pointer;
};

// getter pentru numarul de referinte
template<class T>
inline int SharedPointer<T>::getCount() const {
    return *count;
};

template<class T>
inline void SharedPointer<T>::reset(T* pointer_) {
    delete pointer;
    delete count;

    pointer = pointer_;
    count = new int(1);
}

// copy assignment operator
template<class T>
inline SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer& other) {
    if (this != &other) {
        if (--(*count) == 0) {
            delete pointer;
            delete count;
        }

        pointer = other.pointer;
        count = other.count;
        ++(*count);
    }

    return *this;
};



#endif // SHARED_POINTER_HPP
