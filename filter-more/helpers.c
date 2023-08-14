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
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg_red = 0, avg_green = 0, avg_blue = 0, pixel_count = 0;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if (i + k < 0 || i + k >= height|| j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    avg_red += image[i + k][j + l].rgbtRed;
                    avg_green += image[i + k][j + l].rgbtGreen;
                    avg_blue += image[i + k][j + l].rgbtBlue;
                    pixel_count++;
                }
            }
            avg_red = avg_red / pixel_count;
            avg_green = avg_green / pixel_count;
            avg_blue = avg_blue / pixel_count;
            copy[i][j].rgbtRed = avg_red;
            copy[i][j].rgbtGreen = avg_green;
            copy[i][j].rgbtBlue = avg_blue;
        }
    }
    memcpy(image, copy, sizeof copy);
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
