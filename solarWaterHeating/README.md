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
    IntervalVector x_initial(2);
    x_initial[0]= Interval(40.0,45.1);
    x_initial[1]= Interval(0.1,0.11);
    
    double period = 1*60;

```

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

 ![state](https://github.com/richardyantas/DinamicalSystems/blob/master/solarWaterHeating/img/x0x1.png)

 In the pictures we can see the upper values (RED) and de lower values(BLACK), about x[0] and x[1] respectively, it start with an interval with a distance 5 of separation and it the algorithm has not problem to solve it, it works perfectly.


`problem`
 However mantaining the same initial condition and period, when is introduced values x[0] as an input in the sign function  like `sign(x[0]-1)` it crash. 


``` c++
    cout << 5*sign( Interval(0.3) - Interval(0.5) ) << endl;
    Function m1 = Function(x, Return( +0.005*x[0]+(sign(x[0]-1)+1)/2, 0.001*sign(0.001) ));
    Function m2 = Function(x, Return( -0.005*x[0]+(sign(x[0]-1)+1)/2, 0.001*sign(0.001) ));
    Function m3 = Function(x, Return( +0.005*x[0]+(sign(x[0]-1)+1)/2, 0.001*sign(-0.001) ));
    Function m4 = Function(x, Return( -0.005*x[0]+(sign(x[0]-1)+1)/2, 0.001*sign(-0.001) ));
    Function m5 = Function(x, Return( +0.005*x[0]+(sign(x[0]-1)+1)/2, 0.001*sign(0.001) ));
    Function m6 = Function(x, Return( -0.005*x[0]+(sign(x[0]-1)+1)/2, 0.001*sign(0.001) ));

```
Results:


***********************************************************************
IBEX has crashed because the following feature is not implemented yet:
diff with chi
Please, submit a new feature request.
***********************************************************************

 
#### Example 2.-

In order to simplify the big main equation for solar water heating I start with simple forms.

When I try to run equation with this form x[0]/x[1].

``` c++
    IntervalVector x_initial(2);
    x_initial[0]= Interval(40.0,40.1);
    x_initial[1]= Interval(0.1,0.11);
```

The initial conditions was changued from  x_initial[0] = Interval(40.0,45.1) to x_initial[0] = Interval(40.0,40.1) 
but it still does not work.

``` c++
    Function m1 = Function(x, Return( x[0]/x[1], Interval(0.001) ));
    Function m2 = Function(x, Return( -x[0]/x[1], Interval(0.001) ));
    Function m3 = Function(x, Return( x[0]/x[1], Interval(0.001) ));
    Function m4 = Function(x, Return( -x[0]/x[1], Interval(0.001) ));
    Function m5 = Function(x, Return( x[0]/x[1], Interval(0.001) ));
    Function m6 = Function(x, Return( -x[0]/x[1], Interval(0.001) ));

```

output:

Unacceptable solution!
Step:5 refused !
Unacceptable solution!
Step:5 refused !
Unacceptable solution!
Step:5 refused !


#### Example 3.-


This is the main model I want to run but I am having many problems.



``` c++
    Function m1 = Function(x, Return( -2.8811059759131854e-6*(x[0]-Te)/x[1] + 
    -9.34673995175876e-05*(x[0]-Ti)/x[1] - sign(0.1 - x[1])*9.34673995175876e-05*(x[0]-Ti)/x[1]
    + 0.7*0.7*8.403225763080125e-07*I/x[1] + 0.0048018432931886426/x[1]
    ,0.1*( Interval(0.1) - x[1]) ) );

    Function m2 = Function(x, Return( -2.8811059759131854e-6*(x[0]-Te)/x[1] + 
    -9.34673995175876e-05*(x[0]-Ti)/x[1] - sign(0.1 - x[1])*9.34673995175876e-05*(x[0]-Ti)/x[1]
    + 0.7*0.7*8.403225763080125e-07*I/x[1]
    ,0.1*( Interval(0.1) - x[1]) ) );

    Function m3 = Function(x, Return( -2.8811059759131854e-6*(x[0]-Te)/x[1] + 
    -9.34673995175876e-05*(x[0]-Ti)/x[1] - sign(0.2 - x[1])*9.34673995175876e-05*(x[0]-Ti)/x[1]
    + 0.7*0.7*8.403225763080125e-07*I/x[1] + 0.0048018432931886426/x[1]
    ,0.1*( Interval(0.2) - x[1]) ) );

    Function m4 = Function(x, Return( -2.8811059759131854e-6*(x[0]-Te)/x[1] + 
    -9.34673995175876e-05*(x[0]-Ti)/x[1] - sign(0.2 - x[1])*9.34673995175876e-05*(x[0]-Ti)/x[1]
    + 0.7*0.7*8.403225763080125e-07*I/x[1] 
    ,0.1*( Interval(0.2) - x[1]) ) );

    Function m5 = Function(x, Return( -2.8811059759131854e-6*(x[0]-Te)/x[1] + 
    -9.34673995175876e-05*(x[0]-Ti)/x[1] - sign(0.3 - x[1])*9.34673995175876e-05*(x[0]-Ti)/x[1]
    + 0.7*0.7*8.403225763080125e-07*I/x[1] + 0.0048018432931886426/x[1]
    ,0.1*( Interval(0.3) - x[1]) ) );

    Function m6 = Function(x, Return( -2.8811059759131854e-6*(x[0]-Te)/x[1] + 
    -9.34673995175876e-05*(x[0]-Ti)/x[1] - sign(0.3 - x[1])*9.34673995175876e-05*(x[0]-Ti)/x[1]
    + 0.7*0.7*8.403225763080125e-07*I/x[1] 
    ,0.1*( Interval(0.3) - x[1]) ) );

```









Thanks for read!
 ![Minion](https://octodex.github.com/images/minion.png)
