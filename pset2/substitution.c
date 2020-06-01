#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    string input = argv[1];
    if (argc != 2 || strlen(input) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char plain[26];
    char key[26];

    for (int i = 0; i < 26; i++)
    {
        //convert the char to UPPERCASE
        key[i] = toupper(input[i]);

        //Check for non-alphabets in the key
        if (key[i] >= 65 && key[i] <= 90)
        {
            plain[i] = 65 + i - key[i];
        }
        else
        {
            //non-alphabet found
            printf("Usage: ./substitution key\n");
            return 1;
        }

        // Check for Duplicate
        for (int j = 0; j < i; j++)
        {
            if (key[i] == key[j])
            {
                //duplicate alphabet found
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    string text = get_string("plaintext: ");

    // Convert to cipher text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //uppercase alphabets
        if (text[i] >= 65 && text[i] <= 90)
        {
            text[i] = text[i] - plain[text[i] - 65];
        }
        //lowercase alphabets
        else if (text[i] >= 97 && text[i] <= 122)
        {
            text[i] = text[i] - plain[text[i] - 97];
        }
    }

    printf("ciphertext: %s\n", text);
    return 0;
}