#include <cassert>

#include "../include/tests.hpp"

#include "../include/shared_pointer.hpp"
#include "../include/unique_pointer.hpp"
#include "../include/vector.hpp"

#include <vector>

void test_vector() {
    Vector<int> v;
    assert(v.getSize() == 0);
    assert(v.getCapacity() == 10);
    assert(v.getData() != nullptr);

    v.push_front(1);
    assert(v.getSize() == 1);
    assert(v.getCapacity() == 10);
    assert(v.getData() != nullptr);
    assert(*v.begin() == 1);

    v.push_back(2);
    assert(v.getSize() == 2);
    assert(v.getCapacity() == 10);
    assert(v.getData() != nullptr);
    assert(*v.begin() == 1);
    assert(*(v.begin() + 1) == 2);

    v[0] = 3;
    assert(v.getSize() == 2);
    assert(v.getCapacity() == 10);
    assert(v.getData() != nullptr);
    assert(*v.begin() == 3);
    assert(*(v.begin() + 1) == 2);

    v.pop_back();
    assert(v.getSize() == 1);
    assert(v.getCapacity() == 10);
    assert(v.getData() != nullptr);
    assert(*v.begin() == 3);

    v.pop_front();
    assert(v.getSize() == 0);
    assert(v.getCapacity() == 10);
    assert(v.getData() != nullptr);
}

void test_unique_ptr() {
    UniquePointer<int> up(new int(1));
    assert(*up == 1);
    
    *up = 6;
    assert(*up == 6);

    up.reset(new int(7));

    assert(*up == 7);
}

void test_shared_ptr() {
    SharedPointer<int> sp(new int(1));
    assert(*sp == 1);
    
    *sp = 6;
    assert(*sp == 6);

    sp.reset(new int(7));

    assert(*sp == 7);
}
