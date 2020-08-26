#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int g = round((float)(image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3);
            image[i][j].rgbtRed = g;
            image[i][j].rgbtBlue = g;
            image[i][j].rgbtGreen = g;
        }
    }

}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaR = round((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue));
            int sepiaG = round((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            int sepiaB = round((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));
            if (sepiaR > 255)
            {
                sepiaR = 255;
            }
            if (sepiaG > 255)
            {
                sepiaG = 255;
            }
            if (sepiaB > 255)
            {
                sepiaB = 255;
            }
            image[i][j].rgbtRed = sepiaR;
            image[i][j].rgbtBlue = sepiaB;
            image[i][j].rgbtGreen = sepiaG;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        int half = round((float).5 * width);

        for (int j = 0; j < width; j++)
        {
            while (j < half)
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][(width - 1) - j];
                image[i][(width - 1) - j] = temp;
                break;
            }

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Top Row
            if (i == 0)
            {
                //Left Corner
                if (j == 0)
                {
                    int a = round((float)(temp[i][j].rgbtRed + temp[i + 1][j].rgbtRed + temp[i][j + 1].rgbtRed + temp[i + 1][j + 1].rgbtRed) / 4);
                    int b = round((float)(temp[i][j].rgbtBlue + temp[i + 1][j].rgbtBlue + temp[i][j + 1].rgbtBlue + temp[i + 1][j + 1].rgbtBlue) / 4);
                    int c = round((float)(temp[i][j].rgbtGreen + temp[i + 1][j].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i + 1][j + 1].rgbtGreen) /
                                  4);

                    image[i][j].rgbtRed = a;
                    image[i][j].rgbtBlue = b;
                    image[i][j].rgbtGreen = c;
                }
                //Right Corner
                else if (j == width - 1)
                {
                    int a = round((float)(temp[i][j].rgbtRed + temp[i + 1][j].rgbtRed + temp[i][j - 1].rgbtRed + temp[i + 1][j - 1].rgbtRed) / 4);
                    int b = round((float)(temp[i][j].rgbtBlue + temp[i + 1][j].rgbtBlue + temp[i][j - 1].rgbtBlue + temp[i + 1][j - 1].rgbtBlue) / 4);
                    int c = round((float)(temp[i][j].rgbtGreen + temp[i + 1][j].rgbtGreen + temp[i][j - 1].rgbtGreen + temp[i + 1][j - 1].rgbtGreen) /
                                  4);
                    image[i][j].rgbtRed = a;
                    image[i][j].rgbtBlue = b;
                    image[i][j].rgbtGreen = c;

                }
                //Rest Of Top Row
                else if (j > 0 && j < width - 1)
                {
                    int a = round((float)(temp[i][j].rgbtRed + temp[i + 1][j].rgbtRed + temp[i][j + 1].rgbtRed + temp[i + 1][j + 1].rgbtRed + temp[i][j
                                          - 1].rgbtRed + temp[i + 1][j - 1].rgbtRed) / 6);
                    int b = round((float)(temp[i][j].rgbtBlue + temp[i + 1][j].rgbtBlue + temp[i][j + 1].rgbtBlue +
                                          temp[i + 1][j + 1].rgbtBlue + temp[i][j - 1].rgbtBlue + temp[i + 1][j - 1].rgbtBlue) / 6);
                    int c = round((float)(temp[i][j].rgbtGreen + temp[i + 1][j].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i + 1][j + 1].rgbtGreen +
                                          temp[i][j - 1].rgbtGreen + temp[i + 1][j - 1].rgbtGreen) / 6);
                    image[i][j].rgbtRed = a;
                    image[i][j].rgbtBlue = b;
                    image[i][j].rgbtGreen = c;
                }

            }
            //Bottom Row
            if (i == height - 1)
            {
                //Bottom Left
                if (j == 0)
                {
                    int a = round((float)(temp[i][j].rgbtRed + temp[i - 1][j].rgbtRed + temp[i][j + 1].rgbtRed + temp[i - 1][j + 1].rgbtRed) / 4);
                    int b = round((float)(temp[i][j].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i][j + 1].rgbtBlue + temp[i - 1][j + 1].rgbtBlue) / 4);
                    int c = round((float)(temp[i][j].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i - 1][j + 1].rgbtGreen) /
                                  4);
                    image[i][j].rgbtRed = a;
                    image[i][j].rgbtBlue = b;
                    image[i][j].rgbtGreen = c;
                }
                //Bottom Right
                if (j == width - 1)
                {
                    int a = round((float)(temp[i][j].rgbtRed + temp[i - 1][j].rgbtRed + temp[i][j - 1].rgbtRed + temp[i - 1][j - 1].rgbtRed) / 4);
                    int b = round((float)(temp[i][j].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i][j - 1].rgbtBlue + temp[i - 1][j - 1].rgbtBlue) / 4);
                    int c = round((float)(temp[i][j].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i][j - 1].rgbtGreen + temp[i - 1][j - 1].rgbtGreen) /
                                  4);
                    image[i][j].rgbtRed = a;
                    image[i][j].rgbtBlue = b;
                    image[i][j].rgbtGreen = c;

                }
                //Rest Of Bottom Row
                else if (j > 0 && j < width - 1)
                {
                    int a = round((float)(temp[i][j].rgbtRed + temp[i - 1][j].rgbtRed + temp[i][j + 1].rgbtRed + temp[i - 1][j + 1].rgbtRed + temp[i][j
                                          - 1].rgbtRed + temp[i - 1][j - 1].rgbtRed) / 6);
                    int b = round((float)(temp[i][j].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i][j + 1].rgbtBlue + temp[i - 1][j + 1].rgbtBlue +
                                          temp[i][j - 1].rgbtBlue + temp[i - 1][j - 1].rgbtBlue) / 6);
                    int c = round((float)(temp[i][j].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i][j + 1].rgbtGreen +
                                          temp[i - 1][j + 1].rgbtGreen + temp[i][j - 1].rgbtGreen + temp[i - 1][j - 1].rgbtGreen) / 6);
                    image[i][j].rgbtRed = a;
                    image[i][j].rgbtBlue = b;
                    image[i][j].rgbtGreen = c;
                }
            }
            //Left Side
            else if (j == 0)
            {
                if (i > 0 && i < height - 1)
                {
                    int a = round((float)(temp[i][j].rgbtRed + temp[i - 1][j + 1].rgbtRed + temp[i][j + 1].rgbtRed + temp[i + 1][j].rgbtRed + temp[i +
                                          1][j + 1].rgbtRed + temp[i - 1][j].rgbtRed) / 6);
                    int b = round((float)(temp[i][j].rgbtBlue + temp[i - 1][j + 1].rgbtBlue + temp[i][j + 1].rgbtBlue + temp[i + 1][j].rgbtBlue + temp[i
                                          + 1][j + 1].rgbtBlue + temp[i - 1][j].rgbtBlue) / 6);
                    int c = round((float)(temp[i][j].rgbtGreen + temp[i - 1][j + 1].rgbtGreen + temp[i][j + 1].rgbtGreen + temp[i + 1][j].rgbtGreen +
                                          temp[i + 1][j + 1].rgbtGreen + temp[i - 1][j].rgbtGreen) / 6);
                    image[i][j].rgbtRed = a;
                    image[i][j].rgbtBlue = b;
                    image[i][j].rgbtGreen = c;
                }
            }
            //Right Side
            else if (j == width - 1)
            {
                if (i > 0 && i < height - 1)
                {
                    int a = round((float)(temp[i][j].rgbtRed + temp[i - 1][j].rgbtRed + temp[i - 1][j - 1].rgbtRed + temp[i][j - 1].rgbtRed + temp[i +
                                          1][j].rgbtRed + temp[i + 1][j - 1].rgbtRed) / 6);
                    int b = round((float)(temp[i][j].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i - 1][j - 1].rgbtBlue + temp[i][j - 1].rgbtBlue + temp[i
                                          + 1][j].rgbtBlue + temp[i + 1][j - 1].rgbtBlue) / 6);
                    int c = round((float)(temp[i][j].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i - 1][j - 1].rgbtGreen + temp[i][j - 1].rgbtGreen +
                                          temp[i + 1][j].rgbtGreen + temp[i + 1][j - 1].rgbtGreen) / 6);
                    image[i][j].rgbtRed = a;
                    image[i][j].rgbtBlue = b;
                    image[i][j].rgbtGreen = c;
                }
            }
            //The Rest
            else if (i > 0 && i < height - 1)
            {
                if (j > 0 && j < width - 1)
                {
                    int a = round((float)(temp[i][j].rgbtRed + temp[i - 1][j].rgbtRed + temp[i - 1][j + 1].rgbtRed + temp[i - 1][j - 1].rgbtRed +
                                          temp[i][j - 1].rgbtRed + temp[i + 1][j - 1].rgbtRed + temp[i + 1][j + 1].rgbtRed + temp[i][j + 1].rgbtRed +
                                          temp[i + 1][j].rgbtRed) / 9);
                    int b = round((float)(temp[i][j].rgbtBlue + temp[i - 1][j].rgbtBlue + temp[i - 1][j + 1].rgbtBlue +
                                          temp[i - 1][j - 1].rgbtBlue + temp[i][j - 1].rgbtBlue + temp[i + 1][j - 1].rgbtBlue + temp[i + 1][j + 1].rgbtBlue +
                                          temp[i][j + 1].rgbtBlue + temp[i + 1][j].rgbtBlue) / 9);
                    int c = round((float)(temp[i][j].rgbtGreen + temp[i - 1][j].rgbtGreen + temp[i - 1][j + 1].rgbtGreen + temp[i - 1][j - 1].rgbtGreen
                                          + temp[i][j - 1].rgbtGreen + temp[i + 1][j - 1].rgbtGreen + temp[i + 1][j + 1].rgbtGreen + temp[i][j + 1].rgbtGreen
                                          + temp[i + 1][j].rgbtGreen) / 9);
                    image[i][j].rgbtRed = a;
                    image[i][j].rgbtBlue = b;
                    image[i][j].rgbtGreen = c;
                }
            }
        }
    }
    return;
}
