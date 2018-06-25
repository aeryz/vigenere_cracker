//
//  main.cpp
//  vigenere
//
//  Created by Abdullah Eryuzlu on 14.05.2018.
//  Copyright © 2018 abdullaheryuzlu. All rights reserved.
//

#include <iostream>
#include "vigenere.hpp"
#include "vigenere_cracker.hpp"
#include "pair.cpp"

#define m_DEFAULT_PATH "./default_freq_table.txt"

static void show_usage(std::string name) {
    std::cerr << "Usage: " << name << " <option(s)> SOURCES\n"
    << "Options:\n"
    << "\t-h, --help\t\tShow this help message\n"
    << "\t-f, --freq-table\tSpecify frequency table path, if not default freq table will be used\n"
    << "\t-M, --max-kl\t\tSpecify max key length(Default: cipher length - 1)\n"
    << "\t-m, --min-kl\t\tSpecify min key length(Default: 2)\n"
    << "\t-c, --cipher\t\tSpecify decrypted cipher text\n"
    << "\t-d, --cipher-file\tSpecify the destination path to cipher text\n";
}

static bool is_args_valid(int argc, char* argv[]) {
    bool is_valid = false;
    for (int i = 0; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-c" || arg == "--cipher" ||
            arg == "-d" || arg == "--cipher-file") {
                is_valid = true;
            }
    }
    return is_valid;
}

int main(int argc, char* argv[]) {

    if (!is_args_valid(argc, argv)) {
        show_usage(argv[0]);
        return 1;
    }

    std::string max_kl;
    std::string min_kl;
    std::string cipher;
    bool cipher_is_file = false;
    std::string freq_table_path;
    std::string out;

    for (int i = 0; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
            show_usage(argv[0]);
            return 0;
        } else if (arg == "-m" || arg == "--min-kl") {
            if (i + 1 < argc) min_kl = argv[i + 1];
            else {
                std::cerr << arg << " option requires one argument." << std::endl;
                return 1;
            }
        } else if (arg == "-M" || arg == "--max-kl") {
            if (i + 1 < argc) max_kl = argv[i + 1];
            else {
                std::cerr << arg << " option requires one argument." << std::endl;
                return 1;
            }
        } else if (arg == "-c" || arg == "--cipher") {
            if (i + 1 < argc) cipher = argv[i + 1];
            else {
                std::cerr << arg << " option requires one argument." << std::endl;
                return 1;
            }
        } else if (arg == "-d" || arg == "--cipher-file") {
            if (i + 1 < argc) {
                cipher = argv[i + 1];
                cipher_is_file = true;
            }
            else {
                std::cerr << arg << " option requires one argument." << std::endl;
                return 1;
            }
        } else if (arg == "-o" || arg == "--output") {
            if (i + 1 < argc) out = argv[i + 1];
            else {
                std::cerr << arg << " option requires one argument." << std::endl;
                return 1;
            }
        } else if (arg == "-f" || arg == "--freq-table") {
            if (i + 1 < argc) freq_table_path = argv[i + 1];
            else {
                std::cerr << arg << " option requires one argument." << std::endl;
                return 1;
            }
        }
    }

   UnsignedPair<float> freqs;
   freq_table_path = freq_table_path == "" ? m_DEFAULT_PATH : freq_table_path;
   std::ifstream infile(freq_table_path);
   char a; float b;
   while (infile >> a >> b) {
       freqs.set_value(a, b);
   }
   infile.close();

   if (cipher_is_file) {
       std::ifstream c_file(cipher);
       std::string buffer;
       std::string line;
       while (c_file) {
           std::getline(c_file, line);
           buffer += line;
       }
       c_file.close();
       cipher = buffer;
   }
   VigenereCracker vc(cipher, freqs, min_kl, max_kl);
   vc.crack();

   return 0;
}
