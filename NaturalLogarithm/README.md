Ellipse Function
Reference:
1) Practically Fast Multiple-Precision Evaluation of LOG(X), https://ci.nii.ac.jp/naid/110002673332
2) http://www.cnblogs.com/skyivben/archive/2013/02/15/2912914.html

Taylor Series
Reference:
1) https://blog.csdn.net/jiao1197018093/article/details/50365299

Adaptive Simpson
Reference:
1) https://www.zhihu.com/question/30517151/answer/48419639



//precision test:
Output:
Log(17)=
2.8332133440562162     // Math Library
2.8332133440562171     // Ellipse Function
2.8332133440562166     // Taylor Series
2.8332133440623486     // Adaptive Simpson

Log(10000000)=
16.11809565095832      // Math Library
16.11809565095832      // Ellipse Function
16.11809565095832      // Taylor Series
16.118095650963408     // Adaptive Simpson

//Execution time test: 
//    begin_time = clock();
//    for (long long i = 1; i < 1000000; i += 10) {
//        test_function(i);
//    }
//    cout<<clock() - begin_time <<endl;
Output:
16        // Math Library
47        // Ellipse Function
16        // Taylor Series
22652     // Adaptive Simpson