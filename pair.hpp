#ifndef pair_hpp
#define pair_hpp

#include <iostream>
#include <vector>
#include <fstream>

template <class T>
class UnsignedPair {
private:
    std::vector<std::vector<T>> m_elements;
    T* get_pointer(const T key);
    
public:
    void sort();
    T get_value(const T key);
    void set_value(const T key, const T value);
    std::vector<T> get_nth_element(const size_t n);
    std::string to_string();
    size_t size();
    void sum_value(const T key, const unsigned int amount);
    float sum_of_values();
    void fixed_merge(UnsignedPair<T>& other);
};

#endif

