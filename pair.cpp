#include "pair.hpp"

template <class T>
void UnsignedPair<T>::sort() {
    if (m_elements.size() == 0) return;
    int index = 0;
    while (index != m_elements.size() - 1) {
        for (int i = index; i < m_elements.size(); i++) {
            std::vector<T> temp_value;
            if (m_elements[i][1] > m_elements[index][1]) {
                temp_value = m_elements[i];
                m_elements[i] = m_elements[index];
                m_elements[index] = temp_value;
            }
        }
        index++;
    }
}

template <class T>
T UnsignedPair<T>::get_value(const T key) {
    for (std::vector<T> &element: m_elements) {
        if (key == element[0]) return element[1];
    }
    return -1;
}

template <class T>
void UnsignedPair<T>::sum_value(const T key, const unsigned int amount) {
    T* m_key = this -> get_pointer(key);
    if (m_key) *m_key += amount;
    else this -> set_value(key, amount);
}

template <class T>
std::vector<T> UnsignedPair<T>::get_nth_element(const size_t n) {
    return m_elements[n];
}

template <class T>
T* UnsignedPair<T>::get_pointer(const T key) {
    for (std::vector<T> &element: m_elements) {
        if (key == element[0]) return &element[1];
    }
    return nullptr;
}

template <class T>
void UnsignedPair<T>::set_value(T key, T value) {
    T* current_value = this -> get_pointer(key);
    if (current_value) *current_value = value;
    else m_elements.push_back({ key, value });
}

template <class T>
size_t UnsignedPair<T>::size() {
    return m_elements.size();
}

template <class T>
float UnsignedPair<T>::sum_of_values() {
    float sum = 0;
    for (std::vector<T> v: m_elements) {
        sum += v[1];
    }
    return sum;
}

template <class T>
std::string UnsignedPair<T>::to_string() {
    std::string output;
    for (std::vector<T> v: m_elements) {
        output += std::to_string((char) v[0]) + " " + std::to_string(v[1]) + "\n";
    }
    return output;
}

template <class T>
void UnsignedPair<T>::fixed_merge(UnsignedPair<T>& other) {
    float sum = 0;
    std::vector<std::vector<T>> temp;
    for (int i = 0; i < other.size(); i++) {
        T other_key = other.get_nth_element(i)[0];
        if (this -> get_value(other_key) == -1) {
            sum += other.get_value(other_key);
            temp.push_back({ other_key, other.get_value(other_key) });
        }
    }
    for (int i = 0; i < m_elements.size(); i++) {
        this -> set_value(m_elements[i][0], m_elements[i][1] - m_elements[i][1] * sum);
    }
    for (int i = 0; i < temp.size(); i++)
        m_elements.push_back(temp[i]);
    
    this -> sort();
}

