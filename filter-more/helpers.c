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
    // haha now that i think of it 9 if statements might be more efficient but i'm lazy
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
            avg_red = round(avg_red / (float)pixel_count);
            avg_green = round(avg_green / (float)pixel_count);
            avg_blue = round(avg_blue / (float)pixel_count);
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
    // if...
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE Gx, Gy;
            if (i > 0 && i < height - 1 && j > 0 && j < width - 1)
            {
                Gx.rgbtRed = image[i - 1][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed - (image[i - 1][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed) + 2(image[i][j + 1].rgbtRed - image[i][j - 1].rgbtRed);
                Gx.rgbtGreen = image[i - 1][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen - (image[i - 1][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen) + 2(image[i][j + 1].rgbtGreen - image[i][j - 1].rgbtGreen);
                Gx.rgbtBlue = image[i - 1][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue - (image[i - 1][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue) + 2(image[i][j + 1].rgbtBlue - image[i][j - 1].rgbtBlue);
                Gy.rgbtRed = image[i + 1][j - 1].rgbtRed + image[i + 1][j + 1].rgbtRed + 2 * image[i + 1][j].rgbtRed - (image[i - 1][j - 1].rgbtRed + image[i - 1][j + 1].rgbtRed + 2 * image[i - 1][j].rgbtRed);
                Gy.rgbtGreen = image[i + 1][j - 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + 2 * image[i + 1][j].rgbtGreen - (image[i - 1][j - 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen + 2 * image[i - 1][j].rgbtGreen);
                Gy.rgbtBlue = image[i + 1][j - 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + 2 * image[i + 1][j].rgbtBlue - (image[i - 1][j - 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue + 2 * image[i - 1][j].rgbtBlue);
            }
            else if (i == 0 && j == 0)
            {
                Gx.rgbtRed = 2 * image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed;
                Gx.rgbtGreen = 2 * image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen;
                Gx.rgbtBlue = 2 * image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue;
            }
            else if (i == 0 && j > 0 && j < width - 1)
            {
                Gx.rgbtRed = 2 * image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed - (2 * image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed);
                Gx.rgbtGreen = 2 * image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen - (2 * image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen);
                Gx.rgbtBlue = 2 * image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue - (2 * image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue);
            }
            else if (i == 0 && j == width - 1)
            {
                Gx.rgbtRed = -1 * (2 * image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed);
                Gx.rgbtGreen = -1 * (2 * image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen);
                Gx.rgbtBlue = -1 * (2 * image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue);
            }
            else if (i > 0 && i < height - 1 && j == 0)
            {
                
            }
        }
    }
    return;
}
