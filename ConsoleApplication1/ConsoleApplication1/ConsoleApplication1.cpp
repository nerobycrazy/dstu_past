
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float *x){
	return (2 * x[0] * x[0] - 2 * x[0] * x[1] + 3 * x[1] * x[1] + x[0] - 3 * x[1]);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i, n, t = 0;
	float eps, h, f0, m, grad, s, df1, dx = 0.0001;
	float* x;
	float* df;

	printf("Enter n = "); scanf_s("%d", &n);

	x = (float*)malloc(sizeof(float)*n);
	df = (float*)malloc(sizeof(float)*n);

	printf("Enter eps = "); scanf_s("%f", &eps);
	printf("Enter h = "); scanf_s("%f", &h);
	printf("Enter m = "); scanf_s("%f", &m);
	for (i = 0; i<n; i++){
		printf("x[%d] = ", i + 1); scanf_s("%f", &x[i]);
	}
	do
	{
		f0 = f(x);
		s = 0;
		t++;
		for (i = 0; i<n; i++)
		{
			x[i] += dx;
			df[i] = (f(x) - f0) / dx;
			x[i] -= dx;
		}
		for (i = 0; i<n; i++)
			x[i] -= h*df[i];

		df1 = f(x) - f0;
		if (df1>0) h /= 2;

		for (i = 0; i<n; i++)
			s += (df[i])*(df[i]);
		grad = sqrt(s);
	} while (grad>eps&&t <= m);

	if (grad<eps&&t <= m)
	{
		for (i = 0; i<n; i++)
			printf("\nx[%d]=%5.10f", i + 1, x[i]);
		printf("\nFunction result = %f\n", f0);
		printf("\nIter count = %d\n", t);
		printf("\nSize of h = %f\n", h);
	}
	return 0;
}