#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char pic[4];
    //jpg count
    int c = 0;
    //if jpeg
    int f = 0;

    FILE *img = NULL;
    if (argc != 2)
    {
        printf("Usage: ./recover\n");
        return 1;

    }

    //open file
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Usage: ./recover\n");
        return 1;
    }

    unsigned char bytes [512];
    while (fread(bytes, 512, 1, file) == 1)
    {
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
        {
            if (f == 1)
            {
                fclose(img);
            }

            else
            {
                f = 1;
            }

            sprintf(pic, "%03i.jpg", c);
            img = fopen(pic, "w");
            c++;

        }
        if (f == 1)
        {
            fwrite(bytes, 512, 1, img);
        }
    }
    fclose(img);
    fclose(file);
}
