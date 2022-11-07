#include "search.h"
#include <stdbool.h>

bool search(int a[], int n, int x)
{
    if (n == 0)
        return false;
    else
    {
        if (a[n - 1] == x)
            return true;
        search(a, n - 1, x);
    }
}