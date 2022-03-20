#ifndef VECTOR_HPP
#define VECTOR_HPP

template<class T>
class Vector {
public:
    // iterator vector
    class Iterator {
    public:
        Iterator(T* ptr);

        Iterator& operator++();
        Iterator operator++(int);
        Iterator operator--();
        Iterator operator--(int);
        Iterator operator+(int n);

        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        T& operator*();
        T* operator->();

    private:
        T* ptr_;
    };

    // constructor fara parametrii/cu parametrii
    Vector(int size_ = 0, int capacity_ = 10);

    // copy constructor
    Vector(const Vector& other);
    ~Vector();

    // modifica numarul de elemente
    void resize(int size_);

    // chestii de insertie
    void push_back(const T& element);
    void push_front(const T& element);
    void insert(int index, const T& element);

    // chestii de stergere
    void pop_back();
    void pop_front();
    void erase(int index);

    // getter iteratori begin/end
    Iterator begin() const;
    Iterator end() const;

    // copy assignment operator
    Vector& operator=(const Vector& other);

    // operator de acces
    T& operator[](int index);

    // getteri
    T* getData() const;
    int getSize() const;
    int getCapacity() const;

private:
    T* data;
    int size;
    int capacity;
};

// constructori
template<class T>
inline Vector<T>::Vector(int size_, int capacity_) 
    : size(size_), capacity(capacity_) {
    data = new T[capacity];
}

// destructor
template<class T>
inline Vector<T>::~Vector() {
    if (data)
        delete[] data;
};

template<class T>
inline void Vector<T>::resize(int size_) {
    if (size_ < capacity)
        return;

    while (size_ > capacity)
        capacity *= 2;

    T* newData = new T[capacity];
    for (int i = 0; i < size; ++i)
        newData[i] = data[i];

    delete[] data;
    data = newData;

    size = size_;
}

template<class T>
inline void Vector<T>::push_back(const T& element)  {
    if (size == capacity)
        resize(size + 1);

    data[size++] = element;
}

template<class T>
inline void Vector<T>::push_front(const T& element) {
    this->insert(0, element);
}

template<class T>
inline void Vector<T>::insert(int index, const T& element) {
    if (index < 0 || index > size)
        return;

    if (size == capacity)
        resize(size + 1);

    for (int i = size; i > index; --i)
        data[i] = data[i - 1];

    data[index] = element;

    ++size;
}

template<class T>
inline void Vector<T>::erase(int index) {
    if (index < 0 || index >= size)
        return;

    for (int i = index; i < size - 1; ++i)
        data[i] = data[i + 1];

    --size;
}

template<class T>
inline void Vector<T>::pop_back()  {
    if (size == 0)
        return;

    --size;
}

template<class T>
inline void Vector<T>::pop_front() {
    this->erase(0);
}

template<class T>
inline typename Vector<T>::Iterator Vector<T>::end() const {
    return Iterator(data + size);
};

template<class T>
inline T& Vector<T>::operator[](int index) {
    return data[index];
};

template<class T>
inline T* Vector<T>::getData() const {
    return this->data;
};

template<class T>
inline int Vector<T>::getSize() const  {
    return this->size;
};

template<class T>
inline int Vector<T>::getCapacity() const  {
    return this->capacity;
};

template<class T>
inline typename Vector<T>::Iterator Vector<T>::begin() const {
    return Iterator(data);
};

template<class T>
inline Vector<T>::Iterator::Iterator(T* ptr) : ptr_(ptr) {}

template<class T>
inline typename Vector<T>::Iterator& Vector<T>::Iterator::operator++() {
    ++ptr_;
    return *this;
}

template<class T>
inline typename Vector<T>::Iterator Vector<T>::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++ptr_;
    return tmp;
}

template<class T>
inline typename Vector<T>::Iterator Vector<T>::Iterator::operator--() {
    --ptr_;
    return *this;
}

template<class T>
inline typename Vector<T>::Iterator Vector<T>::Iterator::operator--(int) {
    Iterator tmp = *this;
    --ptr_;
    return tmp;
}

template<class T>
inline typename Vector<T>::Iterator Vector<T>::Iterator::operator+(int n) {
    return Iterator(ptr_ + n);
}

template<class T>
inline bool Vector<T>::Iterator::operator==(const Iterator& other) const {
    return ptr_ == other.ptr_;
}

template<class T>
inline bool Vector<T>::Iterator::operator!=(const Iterator& other) const {
    return ptr_ != other.ptr_;
}

template<class T>
inline T& Vector<T>::Iterator::operator*() {
    return *ptr_;
}

template<class T>
inline T* Vector<T>::Iterator::operator->() {
    return ptr_;
}

#endif // VECTOR_HPP