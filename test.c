#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "gaussian_blur.h"

int
main(int argc, char *argv[])
{
    IplImage *img = 0;
    int height, width, channels;

    fprintf(stdout, "sizeof(long)=%lu\n", sizeof(long));
    if (argc < 2) {
        fprintf(stdout, "Usage: main <image-file-name>\n\7");
        exit(0);
    }
    /* load an image */
    img = cvLoadImage(argv[1], CV_LOAD_IMAGE_COLOR);
    if (!img) {
        fprintf(stdout, "Could not load image file: %s\n", argv[1]);
        exit(0);
    }
    /* get the image data */
    height = img->height;
    width = img->width;
    channels = img->nChannels;
    fprintf(stdout, "Processing a %dx%d image with %d channels\n", width, height, channels);
    /* create a window */
    cvNamedWindow("src", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("src", 100, 100);
    cvNamedWindow("dst", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("dst", 102 + img->width, 100);

    IplImage *old_img = img;
    double sigma = 5;
    img = cvCreateImage(cvGetSize(img), img->depth, img->nChannels);
    fprintf(stdout, "diameter=%d\n", gaussian_blur(old_img, img, sigma));
    cvShowImage("src", old_img);
    cvShowImage("dst", img);
    cvWaitKey(0);

    cvReleaseImage(&old_img);
    cvReleaseImage(&img);
    return 0;
}
