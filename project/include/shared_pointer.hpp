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

    // getter pentru numarul de referinte
    int getCount() const;

private:
    T* pointer;
    int* count;
};



#endif // SHARED_POINTER_HPP
