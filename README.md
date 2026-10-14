# JoyeeCode

编程练习仓库，主要放 C / C++ / Python 的学习代码。

## 文件说明

| 文件 | 内容 |
| --- | --- |
| `Hello.c` | 最基础的 C 语言输出练习 |
| `Hello.cpp` | C++ 练习合集：输入输出、循环与判断、数组与地址、冒泡排序、快速排序、递归二分查找 |
| `start matrix.py` | NumPy 矩阵运算练习：矩阵乘法、逐元素相乘、转置相乘 |

## 运行方式

```bash
gcc Hello.c -o Hello_c && ./Hello_c
g++ Hello.cpp -o Hello_cpp && ./Hello_cpp
python "start matrix.py"
```

Python 部分需要 NumPy：`pip install numpy`。

## 说明

编译产生的可执行文件、目标文件等不会进入仓库，具体规则见 `.gitignore`。
