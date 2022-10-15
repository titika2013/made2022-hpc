#include "matmul.h"

using namespace std;
int sizes[6] = {500, 512, 1000, 1024, 2000, 2048};
char indexes[3] = {'i', 'j', 'k'};

int main()
{

    for (size_t i = 0; i < 3; i++)
    {
        cout << indexes[i] << endl;
        for (size_t j = 0; j < 6; j++)
        {
            cout << calc_time(sizes[j], indexes[i]) << "s  ";
        }
        cout << endl;
    }

    return 0;
}

/*
OUTPUT:
-O3
i
0.606902s  0.706408s  8.83438s  9.66026s  104.168s  111.343s
j
0.596841s  0.716593s  7.05389s  7.55449s  77.6031s  85.6804s
k
0.464415s  0.497731s  3.86175s  4.1625s  30.7785s  34.1438s
-g
i
0.611003s  0.711856s  8.96426s  9.60425s  100.451s  107.297s
j
0.595031s  0.635684s  7.00475s  7.59103s  77.4268s  83.4521s
k
0.459544s  0.497289s  4.24919s  4.17354s  33.0947s  35.4331s
*/