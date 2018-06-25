# vigenere_cracker

#Vigenere Cracker
Vigenere Cracker is a vigenere cipher cracking tool based on frequency analysis.

##Usage
###Parameters:
-h, --help:         Print usage message.
-f, --freq-table:   Specify a frequency table. If not specified, default frequency
table will be used.
-M, --max-kl:       Specify maximum key length. Default is cipher length - 1.
-m, --min-kl:       Specify minimum key length. Default is 2.
-c, --cipher:       Specify cipher text.
-d, --cipher-file:  Specify the file path which includes cipher text.

**Note:** Cipher or cipher file path should be specified.

##How Vigenere Cracker Works (Step by Step):
###**Step 1:** Parsing arguments
###**Step 2:** Finding Coincidences
Program iterates through minimum key length to maximum key length and finds
coincidences for each key length. Then it creates a table.
###**Step 3:** Guessing Key
Starting from the key length which has the most coincidences, program creates
a char count pair. It's key is a character and it's value is count of that character.
Eg. E -> 20. For more accurate result, program assumes the most frequent three characters
of the char count pair is the most frequent character of the frequency table.
Then it computes it's chisquare's and decides on the one which has the smallest chisquare
score.
###**Step 4:** Decryption
Program decrypts the cipher by using the guessed key. If the guessed key is wrong,
program continues to guessing keys and decrypting ciphers.
