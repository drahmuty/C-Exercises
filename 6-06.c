/*
scan entire program (first pass)
if #define is encountered
install new key-value pair in hash table
first word after #define is key
second word is value

scan entire program (second pass)
if any word matches a key in the hash table
replace that word with the key's value
*/

#include <stdio.h>

int main(void)
{
    int c;
    
    // while getword != EOF
    // if word == #define
    // get next word and set it as key
    // get next word and set it as val
    // install key-val in hash table
    
    // while getword != EOF
    // if lookup(word)
    // replace word with val
    // else write word to output
    
    return 0;
}
