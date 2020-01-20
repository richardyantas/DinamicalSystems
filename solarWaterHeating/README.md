
## Compiling and Running


``` c++
var foo = function (bar) {
  return bar++;
};

console.log(foo(5));
```

mkdir build
cd build
cmake ..
make && ./out

