
## Compiling and Running


``` cmd
mkdir build
cd build
cmake ..
make && ./out
```

``` c++
    cout << 5*sign( Interval(0.3) - Interval(0.5) ) << endl;
    Function m1 = Function(x, Return( 0.005*x[0], 0.001*sign(0.001) ));
    Function m2 = Function(x, Return( -0.005*x[0] + Interval(0.001), 0.001*sign(0.001) ));
    Function m3 = Function(x, Return( +0.005*x[0], 0.001*sign(-0.001) ));
    Function m4 = Function(x, Return( -0.005*x[0], 0.001*sign(-0.001) ));
    Function m5 = Function(x, Return( +0.005*x[0]+(sign(x[0]-1)+1)/2, 0.001*sign(0.001) ));
    Function m6 = Function(x, Return( -0.005*x[0], 0.001*sign(0.001) ));

```

