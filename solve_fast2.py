from posblock2 import PosBlock

def solve_fast(a, m, k):
    n = len(a)
    if k == 1:
        return 0
    b = sorted(a)
    if m >= k - 1:
        return min(b[i + k - 1] - b[i] for i in range(0, n - k + 1))
    pos_of_val = {}
    for idx, v in enumerate(a):
        pos_of_val.setdefault(v, []).append(idx)
    cnt_val = {}
    pb = PosBlock(n)
    j = -1
    ans = None
    t = m + 1
    for i in range(n):
        if j < i:
            j = i - 1
        while j + 1 < n and pb.top_t_sum(t) < k:
            v = b[j + 1]
            cnt_val[v] = cnt_val.get(v, 0) + 1
            if cnt_val[v] == 1:
                for p in pos_of_val[v]:
                    pb.insert(p)
            j += 1
        if pb.top_t_sum(t) >= k:
            d = b[j] - b[i]
            if ans is None or d < ans:
                ans = d
        v = b[i]
        cnt_val[v] -= 1
        if cnt_val[v] == 0:
            for p in pos_of_val[v]:
                pb.remove(p)
    return ans

if __name__ == '__main__':
    import random, time
    import sys
    sys.path.insert(0, '.')
    from explore_verify import formula_ans
    random.seed(2024)
    bad = 0
    for trial in range(2000):
        n = random.randint(1, 14)
        k = random.randint(1, n)
        m = random.randint(0, n)
        a = [random.randint(1, 8) for _ in range(n)]
        f = solve_fast(a, m, k)
        g = formula_ans(a, k, m)
        if f != g:
            bad += 1
            print('MISMATCH a=%s k=%d m=%d fast=%s formula=%s' % (a, k, m, f, g))
            if bad > 10:
                break
    print('fast vs formula: tested, mismatches', bad)

    # 性能
    random.seed(1)
    n = 200000
    a = [random.randint(1, 10**9) for _ in range(n)]
    for k, m in [(1000, 500), (1000, 5), (50000, 100)]:
        t0 = time.time()
        r = solve_fast(a, m, k)
        print('n=%d k=%d m=%d -> %s  (%.2fs)' % (n, k, m, r, time.time() - t0))
