#include "barcode.h"
#include <stdio.h>

void fill_digit(struct image* image, int start_x, int digit, int right) {

    char* patterns[] = {
        "1110010",
        "1100110",
        "1101100",
        "1010000",
        "1011100",
        "1001110",
        "1000010",
        "1000100",
        "1001000",
        "1110100"
    };
    for (int j = 0; j < 7; j++) {

        int bit = patterns[digit][j] - '0';

        if (right) {
            bit = 1 - bit;
        }

        int color;

        if (bit == 1) {
            color = 255;
        } else {
            color = 0;
        }

        for (int i = 0; i < image->height; i++) {
            image->pixels[i * image->width + start_x + j].r = color;
            image->pixels[i * image->width + start_x + j].g = color;
            image->pixels[i * image->width + start_x + j].b = color;
        }
    }
}

struct image* barcode(char* data, int width, int height) {

    struct image* new_image=malloc(sizeof(struct image));
    new_image->width=width;
    new_image->height=height;

    new_image->pixels=malloc(sizeof(struct pixel)*width*height);

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            new_image->pixels[i*width+j].r=255;
            new_image->pixels[i*width+j].g=255;
            new_image->pixels[i*width+j].b=255;
        }
    }

    for (int i = 0; i < height; i++) {
    new_image->pixels[i * width + 9].r = 0;
    new_image->pixels[i * width + 9].g = 0;
    new_image->pixels[i * width + 9].b = 0;

    new_image->pixels[i * width + 11].r = 0;
    new_image->pixels[i * width + 11].g = 0;
    new_image->pixels[i * width + 11].b = 0;
    }

    for(int d=0; d<6; d++){
        int digit=data[d]-'0';
        fill_digit(new_image, 12+d*7, digit, 0);
    }

    for (int i = 0; i < height; i++) {
    new_image->pixels[i * width + 55].r = 0;
    new_image->pixels[i * width + 55].g = 0;
    new_image->pixels[i * width + 55].b = 0;

    new_image->pixels[i * width + 57].r = 0;
    new_image->pixels[i * width + 57].g = 0;
    new_image->pixels[i * width + 57].b = 0;
}

 for(int d=0; d<6; d++){
        int digit=data[d+6]-'0';
        fill_digit(new_image, 59+d*7, digit, 1);
    }

    for (int i = 0; i < height; i++) {
    new_image->pixels[i * width + 101].r = 0;
    new_image->pixels[i * width + 101].g = 0;
    new_image->pixels[i * width + 101].b = 0;

    new_image->pixels[i * width + 103].r = 0;
    new_image->pixels[i * width + 103].g = 0;
    new_image->pixels[i * width + 103].b = 0;
}


    return new_image;

}

