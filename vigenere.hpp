//
//  vigenere.hpp
//  vigenere
//
//  Created by Abdullah Eryuzlu on 14.05.2018.
//  Copyright © 2018 abdullaheryuzlu. All rights reserved.
//

#ifndef vigenere_hpp
#define vigenere_hpp

#include <iostream>

class Vigenere {
private:
    Vigenere() {}
    static std::string get_eliminated_text(std::string text, bool is_reversed);
    static std::string shift_text(std::string text, std::string key, bool is_encrypt);
    
public:
    static std::string encrypt(std::string text, std::string key);
    static std::string decrypt(std::string text, std::string key);
};

#endif /* vigenere_hpp */

