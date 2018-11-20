#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Using Ellipse Function + Arithmetic mean to calculate natural logarithm
// reference:
// 1) "Practically Fast Multiple-Precision Evaluation of LOG(X)", https://ci.nii.ac.jp/naid/110002673332
// 2) http://www.cnblogs.com/skyivben/archive/2013/02/15/2912914.html
//
long double pi2 = 6.283185307179586476925286766559;
long double ln10 = 2.30258509299404568401799145468;
long double eps2 = 0.00000000000001; // 1e-14
long double eps1 = eps2 * eps2;       // 1e-28

long double Sqrt(long double x)
{
    if (x == 0) return 0;
    long double y = sqrt(x);
    return (y + x / y) / 2;
}

long double NegativeLog(long double q)
{   // q in ( 0.01, 0.1 ]

    long double r = q, s = q, n = q, q2 = q * q, q1 = q2 * q;

    for (bool p = true; (n *= q1) > eps1; s += n, q1 *= q2)
        r += (p = !p) ? n : -n;

    long double u = 1 - 2 * r, v = 1 + 2 * s, t = u / v;
    long double a = 1, b = Sqrt(1 - t * t * t * t);

    for (; a - b > eps2; b = Sqrt(a * b), a = t)
        t = (a + b) / 2;

    return pi2 / (a + b) / v / v;
}

long double LogAlgo1(long double x)
{
    if (x == 1) return 0;
    int k = 0;
    for (; x > 0.1; k++) x /= 10;
    for (; x <= 0.01; k--) x *= 10;
    return k * ln10 - NegativeLog(x);
}