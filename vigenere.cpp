#include "vigenere.hpp"

std::string Vigenere::shift_text(std::string text, std::string key, bool is_encrypt) {
    key = get_eliminated_text(key, !is_encrypt);
    text = get_eliminated_text(text, false);
    std::string shifted;
    for (int i = 0; i < text.size(); i++) {
//        int t = ((int) text[i] + (int) key[i % key.size()] - (int) 'A') % ('Z');
//        t = t < (int) 'A' ? t + (int) 'A': t;
        int t = ((text[i] - 'A') + (key[i%key.size()] - 'A')) % ('Z' - 'A' + 1) +  'A';
        shifted += t;
    }
    return shifted;
}

std::string Vigenere::encrypt(std::string text, std::string key) {
    return shift_text(text, key, true);
}

std::string Vigenere::decrypt(std::string text, std::string key) {
    return shift_text(text, key, false);
}

std::string Vigenere::get_eliminated_text(std::string text, bool is_reversed) {
    std::string eliminated_text;
    for (char c: text) {
        if (c >= 'A' && c <= 'Z') eliminated_text += is_reversed ? (int)'Z' - c + (int)'A' + 1 : c;
        else if (c >= 'a' && c <= 'z') eliminated_text += is_reversed ? (int)'Z'-(c - (int)'a' + (int)'A')+(int)'A' + 1 : c - (int)'a' + (int)'A';
    }
    return eliminated_text;
}
