#include <iostream>
#include <cstdlib>
#include <matrix.h>


using namespace std;

int main()
{
    Matrix test(10, 10);
    test.random(0, 1);
    cout << test;
    return 0;
}
