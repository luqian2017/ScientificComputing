
// Algorithm: Using Adaptive Simpson to calculate natual logarithm
// Reference:
// 1) https://www.zhihu.com/question/30517151/answer/48419639

long double fabs(long double x)
{
    return x > 0 ? x :(-x);
}

long double F(long double x)
{
    return 1.0 / x;
}

long double simpson(long double a, long double b)
{
  long double c = a + (b - a) / 2;
  
  return (F(a) + 4 * F(c) + F(b)) * (b - a) / 6;
}

long double asr(long double a, long double b, long double eps, long double A)
{
  long double c = a + (b-a)/2;
  long double L = simpson(a, c), R = simpson(c, b);
  
  if(fabs(L + R - A) <= 15 * eps) return L + R + (L + R - A) / 15.0;
  
  return asr(a, c, eps / 2, L) + asr(c, b, eps / 2, R);
}

long long double AdaptiveSimpson(long long double x, long long double eps)
{
  return asr(1, x, 1e-8, simpson(1, x));
}