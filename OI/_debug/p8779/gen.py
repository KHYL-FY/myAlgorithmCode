#!/usr/bin/env python3
# P8779 推导部分和 的随机数据生成器：python gen.py <种子>
#
# 关键点：题目保证「数据无矛盾」。所以 S 不能随便随机，
#   必须先随机一个真实数列 A，再用它的前缀和反推出每条已知部分和。
#   （如果直接 random 一个 S，就会出现 A1=3 和 A1=5 这种自我打脸的数据，
#     暴力和你自己的程序谁对谁错都说不清。）
import random
import sys

# 没给种子也能跑（VS Code 直接点运行不会传参）：
#   无参 -> 默认种子 0；想换数据在终端里写 python gen.py 7
if len(sys.argv) > 1:
    seed = int(sys.argv[1])
else:
    seed = 0
    print("[gen] 没给种子，用默认 0。换数据：python gen.py 7", file=sys.stderr)
random.seed(seed)

n = random.randint(1, 6)                 # 小 n：暴力跑得动，逻辑错在小数据上一样现形
A = [random.randint(-4, 4) for _ in range(n)]
pre = [0] * (n + 1)
for i in range(n):
    pre[i + 1] = pre[i] + A[i]

edges = []                               # 每条是 (l, r)，S 由 pre 反推

if random.random() < 0.45:
    # 长链模式：先放单元素约束 A[i]=...，再随机打乱顺序，
    # 逼出「father 里套 father」的多层结构 —— 纯随机边很容易一次就并到根，测不出路径压缩的错。
    chain = [(i + 1, i + 1) for i in range(n)]
    random.shuffle(chain)
    edges += chain
    for _ in range(random.randint(0, 3)):
        l = random.randint(1, n)
        edges.append((l, random.randint(l, n)))
else:
    # 自由模式：随便取区间，边多了自然会出环和分叉
    for _ in range(random.randint(1, n + 6)):
        l = random.randint(1, n)
        edges.append((l, random.randint(l, n)))

random.shuffle(edges)

q = random.randint(1, 6)
queries = []
for _ in range(q):
    l = random.randint(1, n)
    queries.append((l, random.randint(l, n)))

out = ["%d %d %d" % (n, len(edges), q)]
for l, r in edges:
    out.append("%d %d %d" % (l, r, pre[r] - pre[l - 1]))
for l, r in queries:
    out.append("%d %d" % (l, r))
print("\n".join(out))
