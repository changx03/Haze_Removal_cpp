# Haze Removal

## Introduction

Implementing:

```
@article{he2010single,
  title={Single image haze removal using dark channel prior},
  author={He, Kaiming and Sun, Jian and Tang, Xiaoou},
  journal={IEEE transactions on pattern analysis and machine intelligence},
  volume={33},
  number={12},
  pages={2341--2353},
  year={2010},
  publisher={IEEE}
}
```

## Parameters by default
- radius=7
- omega=0.95
- t0=0.1
- r=60
- eps=0.001

## Dependencies

- `OpenCV=4.5.4`
- Build with CMake

## Compile

```bash
cd cpp_code/src
g++ main.cpp hazeremoval.cpp guidedfilter.cpp -o ../dehaze `pkg-config --libs --cflags opencv`
```



## DEMO

<figure class="half">
    <img src="demo/canon3.bmp">
    <img src="demo/canon3_rev.jpg">
</figure>

