#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "lib_ppm.h"

struct image_s data;
struct image_s *image = &data;

void threshold(int weigth)
{
    int r = read_ppm("images/lena.ppm", image);

    if (r == 0)
    {
        for (int j = 0; j < image->height; j++)
        {
            for (int i = 0; i < image->width; i++)
            {
                int greyScaleR = image->pix[j * image->width + i].r * 0.299;
                int greyScaleG = image->pix[j * image->width + i].g * 0.587;
                int greyScaleB = image->pix[j * image->width + i].b * 0.114;
                int result = (greyScaleR + greyScaleG + greyScaleB) > 50 ? 0 : 255;
                image->pix[j * image->width + i].r = result;
                image->pix[j * image->width + i].g = result;
                image->pix[j * image->width + i].b = result;
            }
        }

        write_ppm("2-threshold_test.ppm", image);
        free_ppm(image);
    }

    return 0;
}