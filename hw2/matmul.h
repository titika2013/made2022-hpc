#include "iostream"
#include <chrono>

template <class T>
T **random_square_matrix(size_t N);

template <class T>
T **mat_mul_ijk(T **A, T **B, size_t N);

template <class T>
T **mat_mul_jik(T **A, T **B, size_t N);

template <class T>
T **mat_mul_kij(T **A, T **B, size_t N);

void show_matrix(int **A, int n, int m);

float calc_time(size_t matr_shape, char func_name);