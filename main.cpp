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
	int N = 5;

	double* a = new double[N];
	double* b = new double[N];

	// Initialize arrays
	for (int i = 0; i < N; ++i)
	{
		a[i] = i;
		b[i] = 2 * i;
	}

	// Initialize output array
	double* c = new double[N];
	for (int i = 0; i < N; ++i)
		c[i] = 0.0;

	for (int i = 0; i < N; ++i)
		printf("c[%d] = %4.4f\n", i, c[i]);

	printf("\n\n");

	// add
	add(a, b, c, N);

	for (int i = 0; i < N; ++i)
		printf("c[%d] = %4.4f\n", i, c[i]);

	delete[] a;
	delete[] b;
	delete[] c;

	return 0;
}