#include<concepts>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>

struct Foo {
    std::string str;
    int val = 0;
};

// these funcitons are required to satisfy tottaly_ordered
auto operator <=>(const Foo &a1, const Foo &a2) { return a1.val <=> a2.val; }
auto operator ==(const Foo &a1, const Foo &a2) { return a1.val == a2.val; }

//concept tottaly_ordered used as type for T
template<std::totally_ordered T, std::size_t SIZE>
struct vec {
    T data[SIZE];
    T* begin() { return data; }
    T* end() { return data + SIZE; }
};

int main() {
    vec<Foo, 2> v{Foo{"hello", 1}, Foo{"goodbye", 2}};
    return 0;
}