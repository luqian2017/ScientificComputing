//Using Taylor Series to calculate natural logarithm
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
