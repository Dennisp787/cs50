#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    float word = 1;
    float sentence = 0;
    float letter = 0;
    string text = get_string("Text: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            word++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }

        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            letter++;
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            letter++;
        }

    }

    float L = (float)letter / (float)word * 100;
    float S = (float)sentence / (float)word * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index < 16)
    {
        printf("Grade %.0f\n", index);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
}