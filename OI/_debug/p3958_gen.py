#!/usr/bin/env python3
# P3958 奶酪 的随机数据生成器：python p3958_gen.py <种子>
# 约定：第一个参数是种子，输出一整个输入文件（多组 T）。
import random, sys

seed = int(sys.argv[1])
random.seed(seed)

T = 30
print(T)
for _ in range(T):
    n = random.randint(1, 5)              # 小 n，保证暴力跑得动
    r = random.randint(1, 3)
    h = random.randint(1, 8)
    print(n, h, r)
    for _ in range(n):
        # 坐标故意带负号：很多人的特判只在第一象限下成立
        print(random.randint(-3, 3), random.randint(-3, 3), random.randint(0, 6))
