// g++ main.cpp -o main.x
#include <stdio.h>
#include <stdlib.h>

void add(double* in1, double* in2, double* out, int n)
{
	for (int i = 0; i < n; ++i)
		out[i] = in1[i] + in2[i];
}

void conv_2d(int kCols, int kRows, double* kernel, int rows, int cols, double* in, double* out)
{
	int kCenterX = kCols / 2;
	int kCenterY = kRows / 2;

	for(int i=0; i < rows; ++i)
	{
	    for(int j=0; j < cols; ++j)
	    {
	        for(int m=0; m < kRows; ++m)
	        {
	            int mm = kRows - 1 - m;

	            for(int n=0; n < kCols; ++n)
	            {
	                int nn = kCols - 1 - n;

	                int ii = i + (kCenterY - mm);
	                int jj = j + (kCenterX - nn);

	                if( ii >= 0 && ii < rows && jj >= 0 && jj < cols )
	                    out[ i * cols + j] += in[ ii * cols + jj] * kernel[mm * kCols + nn];
	            }
	        }
	    }
	}
}

int main(int argc, char const *argv[])
{
	int rows = 28;
	int cols = 28;

	int kernel_rows = 3;
	int kernel_cols = 3;

	double* inImage = new double[rows * cols];
	double* outImage = new double[rows * cols];
	double* kernel = new double[kernel_rows * kernel_cols];

	// Initialize arrays
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			inImage[i * rows + j] = 1.0;
			outImage[i * rows + j] = 0.0;
		}
	}

	for (int i = 0; i < kernel_rows; ++i)
	{
		for (int j = 0; j < kernel_cols; ++j)
		{
			kernel[i * kernel_rows + j] = 1.0 / 9.0;
		}
	}

	for (int i = 0; i < rows*cols; ++i)
		printf("outImage[%d] = %4.4f\n", i, outImage[i]);

	printf("\n\n");

	// conv2d
	conv_2d(kernel_rows, kernel_cols, kernel, rows, cols, inImage, outImage);

	for (int i = 0; i < rows*cols; ++i)
		printf("outImage[%d] = %4.4f\n", i, outImage[i]);

	delete[] inImage;
	delete[] outImage;
	delete[] kernel;

	return 0;
}