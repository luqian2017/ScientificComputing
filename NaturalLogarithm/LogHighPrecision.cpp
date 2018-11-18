#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Algorithm 1: Ellipse Function + Arithmetic mean
// reference:
//  Practically Fast Multiple-Precision Evaluation of LOG(X), https://ci.nii.ac.jp/naid/110002673332
//  http://www.cnblogs.com/skyivben/archive/2013/02/15/2912914.html
//
long double pi2 = 6.283185307179586476925286766559;
long double ln10 = 2.30258509299404568401799145468;
long double eps2 = 0.00000000000001; // 1e-14
long double eps1 = eps2 * eps2;       // 1e-28

long double Sqrt(long double x)
{
    //if (x < 0) throw runtime_error("x must be nonnegative");
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
    //if (x <= 0) throw runtime_error(" input must be positive");
    if (x == 1) return 0;
    int k = 0;
    for (; x > 0.1; k++) x /= 10;
    for (; x <= 0.01; k--) x *= 10;
    return k * ln10 - NegativeLog(x);
}

//Algorithm 2: Taylor Series
//reference:
//https://blog.csdn.net/jiao1197018093/article/details/50365299

long double lnr = 0.2002433314278771112016301167;

long double Log01(long double y)
{
    long double v = 1.0, y2 = y * y, t = y2, z = t / 3;
    for (int i = 3; z > eps1; z = (t *= y2) / (i += 2)) {
        v += z;
    }

    return v * y * 2;
}

long double LogAlgo2(long double x)
{
    //if (x <= 0) throw runtime_error("input must be positive");
    int k = 0, l = 0;
    for (; x > 1; k++) x /= 10;
    for (; x <= 0.1; k--) x *= 10;       // ( 0.1, 1 ]
    for (; x < 0.9047; l--) x *= 1.2217; // [ 0.9047, 1.10527199 )
        return k * ln10 + l * lnr + Log01((x - 1) / (x + 1));
}

int main()
{
//test small input
    cout<<setprecision(20)<<log(17)<<endl;             //Math Library
    cout<<setprecision(20)<<LogAlgo1(17)<<endl;        //Ellipse Function
    cout<<setprecision(20)<<LogAlgo2(17)<<endl;        //Taylor Series

//test large input
    cout<<setprecision(20)<<log(10000000)<<endl;       //Math Library
    cout<<setprecision(20)<<LogAlgo1(10000000)<<endl;  //Ellipse Function
    cout<<setprecision(20)<<LogAlgo2(10000000)<<endl;  //Taylor Series

    return 0;
}
