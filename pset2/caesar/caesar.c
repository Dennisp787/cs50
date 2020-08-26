#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //save variable as the key
    int a;
    //if the second arg exist
    if (argc == 2)
    {

        //iterate through the first argument to see its valid
        //if not valid ends program
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }

        }
        //save the key & change it into an iteger
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]))
            {
                a = atoi(argv[1]);
            }

        }
        //get the text to use
        string plain = get_string("plaintext: ");
        //print the text on this line
        printf("ciphertext: ");
        //interate through the plaintext
        for (int i = 0, n = strlen(plain); i < n; i++)
        {
            //make variable for new keys to use
            int c;
            int w;

            if (islower(plain[i]) + a > 'z')
            {
                do
                {
                    c = (25 + (plain[i] + a) - 'z') % 26;
                    w = c + 'a';

                }

                while (w > 'z');
                printf("%c", w);
            }
            else if (isupper(plain[i]) + a > 'Z')
            {
                do
                {
                    c = (25 + (plain[i] + a) - 'Z') % 26;
                    w = c + 'A';

                }

                while (w > 'Z');
                printf("%c", toupper(w));
            }

            else if (islower(plain[i]) || isupper(plain[i]))
            {
                printf("%c", plain[i] + a);
            }

            else
            {
                printf("%c", plain[i]);
            }

        }

    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    printf("\n");
}