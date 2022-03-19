#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP

template<class T>
class SharedPointer {
public:
    SharedPointer(T* pointer_);
    SharedPointer(const SharedPointer& other);
    ~SharedPointer();

    SharedPointer& operator=(const SharedPointer& other);

    T* operator->();
    T& operator*();

    int getCount() const;

private:
    T* pointer;
    int* count;
};



#endif // SHARED_POINTER_HPP
