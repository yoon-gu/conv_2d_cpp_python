#pragma once
#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#ifdef __cplusplus
extern "C"
{
#endif
    DLLEXPORT void add(double* in1, double* in2, double* out, int n);
    DLLEXPORT void conv_2d(int kCols, int kRows, double* kernel, int rows, int cols, double* in, double* out);

#ifdef __cplusplus
}
#endif