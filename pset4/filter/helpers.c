#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float gray;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            gray = round((image[j][i].rgbtRed + image[j][i].rgbtBlue + image[j][i].rgbtGreen) / 3.000);

            image[j][i].rgbtRed = gray;
            image[j][i].rgbtBlue = gray;
            image[j][i].rgbtGreen = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepia[3];
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sepia[0] = round(0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189 * image[j][i].rgbtBlue);
            sepia[1] = round(0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131 * image[j][i].rgbtBlue);
            sepia[2] = round(0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168 * image[j][i].rgbtBlue);

            if (sepia[0] > 255)
            {
                sepia[0] = 255;
            }
            if (sepia[1] > 255)
            {
                sepia[1] = 255;
            }
            if (sepia[2] > 255)
            {
                sepia[2] = 255;
            }

            image[j][i].rgbtRed = sepia[0];
            image[j][i].rgbtBlue = sepia[1];
            image[j][i].rgbtGreen = sepia[2];
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width / 2; i++)
        {
            temp[0] = image[j][i].rgbtRed;
            temp[1] = image[j][i].rgbtBlue;
            temp[2] = image[j][i].rgbtGreen;

            image[j][i].rgbtRed = image[j][width - i - 1].rgbtRed;
            image[j][i].rgbtBlue = image[j][width - i - 1].rgbtBlue;
            image[j][i].rgbtGreen = image[j][width - i - 1].rgbtGreen;

            image[j][width - i - 1].rgbtRed = temp[0];
            image[j][width - i - 1].rgbtBlue = temp[1];
            image[j][width - i - 1].rgbtGreen = temp[2];
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sum[3];
    float counter;

    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sum[0] = 0;
            sum[1] = 0;
            sum[2] = 0;
            counter = 0.00;

            //Sum the values of the current and 8 neighboring pixels

            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    sum[0] += image[j + k][i + h].rgbtRed;
                    sum[1] += image[j + k][i + h].rgbtBlue;
                    sum[2] += image[j + k][i + h].rgbtGreen;
                    counter++;
                }
            }

            //Average the summed up pixels
            temp[j][i].rgbtRed = round(sum[0] / counter);
            temp[j][i].rgbtBlue = round(sum[1] / counter);
            temp[j][i].rgbtGreen = round(sum[2] / counter);
        }
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
        }
    }
    return;
}
