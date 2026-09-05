from itertools import product
from tiles_sol import solve_case


def brute(s):
    n = len(s)
    qs = [i for i, c in enumerate(s) if c == '?']
    cnt = 0
    for rep in product('01', repeat=len(qs)):
        t = list(s)
        for i, c in zip(qs, rep):
            t[i] = c
        ok = True
        for i in range(n - 2):
            # dominoes i,i+1 share tile i+1; weights equal <=> t[i] == t[i+2]
            if t[i] == t[i + 2]:
                ok = False
                break
        if ok:
            cnt += 1
    return cnt


for n in range(2, 9):
    for tup in product('01?', repeat=n):
        s = ''.join(tup)
        f = solve_case(n, s)
        b = brute(s)
        if f != b:
            print("MISMATCH", s, f, b)
            raise SystemExit(1)
print("all ok")
