This folder collects the following three methods that can realize high-precision natural logarithm function.


1) Ellipse Function
Reference:
I. Practically Fast Multiple-Precision Evaluation of LOG(X), https://ci.nii.ac.jp/naid/110002673332
II. http://www.cnblogs.com/skyivben/archive/2013/02/15/2912914.html

2) Taylor Series
Reference:
I. https://blog.csdn.net/jiao1197018093/article/details/50365299

3) Adaptive Simpson
Reference:
I. https://www.zhihu.com/question/30517151/answer/48419639


Precision test:
We can see all of three methods shows high precision (1e-10) for both small (17) and large input (10000000).

Output:
Log(17)=
2.8332133440562162     // C++ 11 math.lib
2.8332133440562171     // Ellipse Function
2.8332133440562166     // Taylor Series
2.8332133440623486     // Adaptive Simpson, eps = 1e-10

Log(10000000)=
16.11809565095832      // C++ 11 math.lib
16.11809565095832      // Ellipse Function
16.11809565095832      // Taylor Series
16.118095650963408     // Adaptive Simpson, eps = 1e-10

Running time test:
The test uses the loop below to obtain the total time:
//    begin_time = clock();
//    for (long long i = 1; i < 1000000; i += 10) {
//        test_function(i);
//    }
//    cout<<clock() - begin_time <<endl;

From the output we can see that the C++ math.lib and Taylor Series are very quick, next is the Ellipse Function. The Adaptive Simpson is very time consuming, as it involved a bunch of recursion. 

Output:
16        // C++ 11 math.lib
47        // Ellipse Function
16        // Taylor Series
22652     // Adaptive Simpson, eps = 1e-10