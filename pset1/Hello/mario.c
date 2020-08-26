#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }

    while (h <= 0 || h >= 9);
    for (int s = 0; s < h; s++)
    {
        for (int n = h - 1; n > s; n--)
        {
            printf(" ");
        }
        for (int a = 0; a <= s; a++)
        {
            printf("#");
        }
        printf("\n");
    }
}
