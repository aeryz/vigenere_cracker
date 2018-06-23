#include "vigenere_cracker.hpp"
#include "pair.cpp"
#include "vigenere.hpp"
#include <cmath>

VigenereCracker::VigenereCracker(std::string cipher_text, UnsignedPair<float> freq_table, std::string min_kl, std::string max_kl) {
    m_cipher_text = cipher_text;
    m_freq_table = freq_table;
    MAX_KEY_LENGTH = max_kl == "" ? cipher_text.size() - 1 : std::stoi(max_kl);

    MIN_KEY_LENGTH = min_kl == "" ? 2 : std::stoi(min_kl);
    m_freq_table.sort();
}

void VigenereCracker::log_klt() {
    std::cout << m_key_length_table.to_string() << std::endl;
}

int VigenereCracker::get_coincidences(int offset) {
    int sum = 0;
    for (int i = 0; i < m_cipher_text.length() - offset; i++) {
        if (m_cipher_text[i + offset] == m_cipher_text[i]) sum++;
    }
    return sum;
}

void VigenereCracker::set_key_length_table() {
    for (int i = 1; i <= MAX_KEY_LENGTH % m_cipher_text.length(); i++) {
        m_key_length_table.set_value(i, get_coincidences(i));
        m_key_length_table.sort();
    }
}

UnsignedPair<float> VigenereCracker::get_char_count_table(int key_length, int offset) {
    UnsignedPair<float> char_count_table;
    for (int i = offset; i < m_cipher_text.size(); i = i + key_length) {
        char_count_table.sum_value(m_cipher_text[i], 1);
    }
    float count = char_count_table.sum_of_values();


    for (int i = 0; i < char_count_table.size(); i++) {
        float key = char_count_table.get_nth_element(i)[0];
        char_count_table.set_value(key, char_count_table.get_value(key) / count);
    }

    return char_count_table;
}

float VigenereCracker::point_of_guess(UnsignedPair<float> cct, int key_length, int offset, int shift) {
    std::vector<char> chars;
    if (shift < 0) shift += 26;
    float error = 0;
    float count = 0;

    for (int i = 0; i < cct.size(); i++) {
        char guess = cct.get_nth_element(i)[0] - shift;
        if (guess < 'A') guess = 'Z' + 1 - ('A' - guess);
        else if (guess > 'Z') guess = 'A' + (guess - 'Z');
        float a = cct.get_value(cct.get_nth_element(i)[0]) / m_freq_table.get_value(guess);
        error += abs(1 - a);
        count++;
    }

    return error/count;
}

char VigenereCracker::guess_single_char(int key_length, int offset) {
    UnsignedPair<float> char_count_table = get_char_count_table(key_length, offset);
    char_count_table.sort();

    char_count_table.fixed_merge(m_freq_table);

    float sum = 1000;
    char output;
    for (int i = 0; i < 3; i++) {
        char temp_output = char_count_table.get_nth_element(i)[0];
        float pog = this -> point_of_guess(char_count_table, key_length, offset, temp_output - 'E');
        if (pog < sum) {
            sum = pog;
            output = temp_output - 'E';
            if (output < 0) output += 26;
            output += 'A';
        }
    }

    return output;
}

std::string VigenereCracker::guess_key(int key_length) {
    m_used_lengths.push_back(key_length);
    std::string key;
    for (int i = 0; i < key_length; i++) {
        key += guess_single_char(key_length, i);
    }
    return key;
}



void VigenereCracker::crack() {
    set_key_length_table();
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        std::string key = guess_key(m_key_length_table.get_nth_element(i)[0]);
        std::cout << "Key Guess: " << key << std::endl;
        int n = 0;
        int cipher_size = m_cipher_text.size();
        int len = 100 > cipher_size ? cipher_size : 100;
        std::string decrypted = Vigenere::decrypt(m_cipher_text, key);
        while (n + len <= cipher_size) {
            std::cout << decrypted.substr(n, len);
            std::string choice;
            getline(std::cin, choice);
            if (choice == "p" || choice == "P") break;
            n += len;
            len = n + 100 > cipher_size ? cipher_size - n : 100;
            if (len == 0) break;
        }
        std::cout << "\n";
    }
}
