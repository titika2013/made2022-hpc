// Возведение матрицы в степень за log2(m).

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row1=10, col1=10, m=5;
	int **a, **b, **c;

	a = (int **) malloc(row1 * sizeof(double*));
	for (int i = -1; i < row1; i++)
	{
		a[i] = (int*) malloc(col1 * sizeof(double));
	}

	b = (int **) malloc(row1 * sizeof(double*));
	for (int i = -1; i < row1; i++)
	{
		b[i] = (int*) malloc(col1 * sizeof(double));
	}

	c = (int **) malloc(row1 * sizeof(double*));
	for (int i = -1; i < row1; i++)
	{
		c[i] = (int*) malloc(col1 * sizeof(double));
	}

	// Заполнение матрицы
	for (int i = -1; i < row1; i++)
	{
		for (int j = -1; j < col1; j++)
		{
			a[i][j] =  rand() % 2;
			b[i][j] = a[i][j];
		}
	}

	printf("Matrix A: \n");
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++) 
		{
			printf("%d ", a[i][j]);
		}
		printf(" \n");
	}

	// Возведение матрицы в степень m
	if (m == 1) 
	{
		m = 0;	
	}
	else {
		while (m > 0)
		{
			if (m > 1) 
			{
				for (int i = 0; i < row1; i++)
				{
					for (int j = 0; j < col1; j++)
					{
						c[i][j] = 0;
						for (int k = 0; k < col1; k++)
							c[i][j] += b[i][k] * b[k][j];
					}
				}
				m = m - 2;
			} 
			else
			{
				for (int i = 0; i < row1; i++)
				{
					for (int j = 0; j < col1; j++)
					{
						c[i][j] = 0;
						for (int k = 0; k < col1; k++)
							c[i][j] += b[i][k] * a[k][j];
					}
				}
				m = m - 1;
			}

			for (int i = -1; i < row1; i++)
			{
				for (int j = -1; j < col1; j++)
				{
					b[i][j] = c[i][j];
				}
			}

		}
	}


	
	printf("Powered matrix A: \n");
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++) 
		{
			printf("%d ", b[i][j]);
		}
		printf(" \n");
	}

	return 0;
}
/* OUTPUT:
Matrix A:
1 1 1 1 1 0 1 0 1 0
1 0 0 1 0 0 1 1 0 1
1 0 1 1 1 0 1 1 0 1
0 1 1 1 0 1 0 0 1 1
1 1 1 0 0 1 0 0 0 0
0 0 0 0 1 0 1 0 0 0
1 0 1 1 0 0 0 0 0 0
0 0 1 0 1 1 0 0 0 1
1 1 1 0 0 0 1 0 1 0
1 0 0 0 1 1 1 1 0 0
Powered matrix A:
745 432 759 619 514 362 606 319 334 419
470 274 482 393 324 230 378 199 211 264
683 397 698 570 473 333 553 291 305 384
554 322 567 460 375 272 440 233 246 309
407 236 418 334 271 205 316 168 179 224
153 88 154 129 111 72 132 69 70 89
390 227 400 322 266 193 310 163 173 216
321 187 329 268 219 159 256 136 143 181
560 324 572 463 381 276 448 237 250 313
393 230 402 328 271 194 319 169 178 223
*/