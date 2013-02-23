/**
 * gaussian_blur.h
 *
 * 'Gaussian Blur' alogrithm base on OpenCV.
 */
#ifndef GAUSSIAN_BLUR_H
#define GAUSSIAN_BLUR_H

#include <opencv/cv.h>

int gaussian_blur_2D(IplImage *src, IplImage *dst, float sigma);

/**
 * function to blur a image using 'Gaussian Blur'.This function is faster than
 * gaussian_blur_2D benefit from the special property of 'Gaussian Blur' called
 * separability.
 *
 * @param src point of a image to be blurred.
 * @param dst point of a image to store the blurred image.
 * @param sigma blurring factor, control the gaussian kernel's size, the larger
 *              this number is, the smoother the image becomes.
 *
 * @return diameter of gaussian kernel.
 *
 * NOTE
 *     src and dst CAN point to a same image, because function create a 
 * temporary image to store the source image during the process.
 */
int gaussian_blur_1D(IplImage *src, IplImage *dst, float sigma);

/**
 * macro to use gaussian_blur_1D.
 */
#define gaussian_blur(src, dst, sigma) gaussian_blur_1D(src, dst, sigma)

#endif
