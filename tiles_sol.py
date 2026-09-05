import sys

MOD = 998244353


def solve_case(n, s):
    cnt = 0
    for a in range(2):
        for b in range(2):
            ok = True
            for i, ch in enumerate(s):
                if ch == '?':
                    continue
                # s[i] must equal (a if i even else b) ^ (i//2 & 1)
                val = (a if i % 2 == 0 else b) ^ ((i // 2) & 1)
                if val != int(ch):
                    ok = False
                    break
            if ok:
                cnt += 1
    return cnt % MOD


def main():
    data = sys.stdin.buffer.read().split()
    t = int(data[0])
    out = []
    idx = 1
    for _ in range(t):
        n = int(data[idx]); idx += 1
        s = data[idx].decode(); idx += 1
        out.append(str(solve_case(n, s)))
    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
