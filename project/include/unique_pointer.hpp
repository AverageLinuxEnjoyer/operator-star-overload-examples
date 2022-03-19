#ifndef SMART_POINTER_HPP
#define SMART_POINTER_HPP

template<class T>
class UniquePointer {
public:
    UniquePointer(T* pointer_);
    UniquePointer(const UniquePointer& other) = delete;
    ~UniquePointer();

    UniquePointer& operator=(const UniquePointer& other) = delete;

    T* operator->();
    T& operator*();

private:
    T* pointer;
};

#endif // SMART_POINTER_HPP
