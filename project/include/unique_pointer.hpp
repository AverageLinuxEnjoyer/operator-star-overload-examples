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

private:
    T* pointer;
};

#endif // UNIQUE_POINTER_HPP
