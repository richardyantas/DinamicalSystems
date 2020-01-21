## Solar Water Heating Code

#### Compiling and Running


``` cmd
mkdir build
cd build
cmake ..
make && ./out
```

#### Example 1.- 

I have verified the correct functionality of `ivp_ode` for modes(differential equation with `sign` function). 

``` c++
    cout << 5*sign( Interval(0.3) - Interval(0.5) ) << endl;
    Function m1 = Function(x, Return( 0.005*x[0],0.001*sign(0.001) ));
    Function m2 = Function(x, Return( -0.005*x[0],0.001*sign(0.001) ));
    Function m3 = Function(x, Return( +0.005*x[0],0.001*sign(-0.001) ));
    Function m4 = Function(x, Return( -0.005*x[0],0.001*sign(-0.001) ));
    Function m5 = Function(x, Return( +0.005*x[0],0.001*sign(0.001) ));
    Function m6 = Function(x, Return( -0.005*x[0],0.001*sign(0.001) ));

```
Results:

 ![temperature](https://github.com/richardyantas/DinamicalSystems/blob/master/solarWaterHeating/img/example1_t.png){ width=50% height=50% }
 ![volume](https://github.com/richardyantas/DinamicalSystems/blob/master/solarWaterHeating/img/example1_v.png){ width=50% height=50% }


#### Example 2.-

However when I introduce values like sign(x[0]-1) it crash. That term is something I need.


``` c++
    cout << 5*sign( Interval(0.3) - Interval(0.5) ) << endl;
    Function m1 = Function(x, Return( 0.005*x[0], 0.001*sign(0.001) ));
    Function m2 = Function(x, Return( -0.005*x[0] + Interval(0.001), 0.001*sign(0.001) ));
    Function m3 = Function(x, Return( +0.005*x[0], 0.001*sign(-0.001) ));
    Function m4 = Function(x, Return( -0.005*x[0], 0.001*sign(-0.001) ));
    Function m5 = Function(x, Return( +0.005*x[0]+(sign(x[0]-1)+1)/2, 0.001*sign(0.001) ));
    Function m6 = Function(x, Return( -0.005*x[0], 0.001*sign(0.001) ));

```
Results:

Thanks for read!
 ![Minion](https://octodex.github.com/images/minion.png)
