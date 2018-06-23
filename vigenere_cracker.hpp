#ifndef vigenere_cracker_hpp
#define vigenere_cracker_hpp

#include <iostream>
#include <vector>
#include "pair.hpp"

class VigenereCracker {
public:
    VigenereCracker(std::string cipher_text, UnsignedPair<float> freq_table, std::string min_kl, std::string max_kl);

    void log_klt();
    void crack();

private:
    std::string m_cipher_text;
    UnsignedPair<int> m_key_length_table;
    UnsignedPair<float> m_freq_table;
    std::vector<int> m_used_lengths;
    int MAX_KEY_LENGTH;
    int MIN_KEY_LENGTH;
    int get_coincidences(int offset);
    void set_key_length_table();
    float point_of_guess(UnsignedPair<float> cct, int key_length, int offset, int shift);
    std::string guess_key(int key_length);
    UnsignedPair<float> get_char_count_table(int key_length, int offset);
    char guess_single_char(int key_length, int offset);

};

#endif /* vigenere_cracker_hpp */
