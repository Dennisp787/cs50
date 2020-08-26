#include <stdio.h>
#include <cs50.h>
# include <math.h>

int main(void)
{
    float c;
    int cash = 0;

    do
    {
        c = get_float("How much change? ");
    }

    while (c < 0);
    float q = .25;
    float d = .10;
    float n = .05;
    float p = .01;
    if (c > .24)
    {
        do
        {
            c = c - q;
            cash++;
        }

        while (c > .24);
    }

    if (c > .09)
    {
        do
        {
            c = c - d;
            cash++;
        }
        while (c > .09);
    }

    if (c > .04)
    {
        do
        {
            c = c - n;
            cash++;
        }
        while (c > .04);
    }

    int r = round(c * 100);

    if (r <= 0)
    {
        printf("%i\n", cash);
    }
    else
    {
        do
        {
            r = r - 1;
            cash++;
        }
        while (r > 0);

        printf("%i\n", cash);
    }
}
