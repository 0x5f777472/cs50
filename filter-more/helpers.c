#include "helpers.h"
#include <math.h>
#include <string.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int a_mean = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = a_mean;
            image[i][j].rgbtGreen = a_mean;
            image[i][j].rgbtBlue = a_mean;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE flipped[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            flipped[i][j] = image[i][width - j - 1];
        }
    }
    memcpy(image, flipped, sizeof flipped);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int avg = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg_red = 0, avg_green = 0, avg_blue = 0;
            if (i != 0 && i != height && j != 0 && j != width)
            {
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        avg_red += image[i + k][j + l].rgbtRed;
                        avg_green += image[i + k][j + l].rgbtGreen;
                        avg_blue += image[i + k][j + l].rgbtBlue;
                    }
                }
                avg_red = round(avg_red / 9);
                avg_green = round(avg_green / 9);
                avg_blue = round(avg_blue / 9);
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        image[i + k][j + l].rgbtRed = avg_red;
                        image[i + k][j + l].rgbtGreen = avg_green;
                        image[i + k][j + l].rgbtBlue = avg_blue;
                    }
                }
            }

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
