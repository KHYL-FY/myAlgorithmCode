#!/usr/bin/env python3
# P8779 的暴力：python brute.py < 输入 > 输出
#
# 故意不用并查集。用「前缀和图 + 每次询问重跑一遍 BFS」：
#   记 S[i] = A1+...+Ai（S[0]=0），那么「l..r 的和是 v」就是一条边 S[r] = S[l-1] + v。
#   询问 (l,r) 就是问 S[r]-S[l-1]；从 l-1 出发 BFS 推值，r 能推到就有答案，否则 UNKNOWN。
# 算法完全不同，所以带权并查集里的错（合并方向、dist 累加顺序、符号）不会在两边同时犯。
import sys
from collections import defaultdict, deque


def main():
    data = sys.stdin.read().split()
    if not data:
        return
    it = iter(data)
    n = int(next(it)); m = int(next(it)); q = int(next(it))

    adj = defaultdict(list)              # adj[x] = [(y, d)]  表示 S[y] = S[x] + d
    for _ in range(m):
        l = int(next(it)); r = int(next(it)); v = int(next(it))
        adj[l - 1].append((r, v))
        adj[r].append((l - 1, -v))

    out = []
    for _ in range(q):
        l = int(next(it)); r = int(next(it))
        src, dst = l - 1, r
        val = {src: 0}                   # 以 src 为 0 基准，BFS 推出所有可达点的相对值
        dq = deque([src])
        while dq:
            u = dq.popleft()
            for w, d in adj[u]:
                if w not in val:
                    val[w] = val[u] + d
                    dq.append(w)
        out.append(str(val[dst]) if dst in val else "UNKNOWN")

    sys.stdout.write("\n".join(out) + "\n")


main()
