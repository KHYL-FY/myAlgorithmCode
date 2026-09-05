class Fenwick:
    __slots__ = ('n', 't')
    def __init__(self, n):
        self.n = n
        self.t = [0] * (n + 2)
    def add(self, i, v):
        i += 1
        n = self.n
        t = self.t
        while i <= n:
            t[i] += v
            i += i & (-i)
    def sum(self, i):
        s = 0
        t = self.t
        while i > 0:
            s += t[i]
            i -= i & (-i)
        return s
    def find_kth(self, k):
        idx = 0
        bitmask = 1 << (self.n.bit_length())
        t = self.t
        n = self.n
        while bitmask:
            nxt = idx + bitmask
            if nxt <= n and t[nxt] < k:
                idx = nxt
                k -= t[nxt]
            bitmask >>= 1
        return idx

class PosBlock:
    """维护 0/1 位置集合的连续块; 插入 O(1)+Fenwick, 删除端点 O(1), 中间点删除用二分找端点"""
    def __init__(self, n):
        self.n = n
        self.occ = [0] * n
        self.pos_bit = Fenwick(n)          # 位置占用 0/1
        self.empty_bit = Fenwick(n)        # 位置空 0/1 (补集)
        self.cnt_bit = Fenwick(n + 2)      # 0-based 下标 = 大小-1, 值 = 块数
        self.sum_bit = Fenwick(n + 2)      # 0-based 下标 = 大小-1, 值 = 大小*块数
        self.l2r = {}                      # 块左端 -> 块右端
        self.r2l = {}                      # 块右端 -> 块左端
        self.total_blocks = 0
        self.total_occ = 0
        # 初始全空
        for i in range(n):
            self.empty_bit.add(i, 1)

    def _add_block(self, sz, d):
        if sz <= 0:
            return
        self.cnt_bit.add(sz - 1, d)
        self.sum_bit.add(sz - 1, d * sz)

    def block_of(self, p):
        # p 所在块 [l, r] (p 必须 occupied) — 用"空位" Fenwick find_kth, O(log n)
        S = self.pos_bit.sum(p + 1)           # [0, p] 占用数
        e_before = (p + 1) - S                # [0, p] 空位数
        if e_before >= 1:
            lm1 = self.empty_bit.find_kth(e_before)   # 最后一个 <= p 的空位 = l-1
            l = lm1 + 1
        else:
            l = 0                             # 块从位置 0 开始
        total_empty = self.empty_bit.sum(self.n)
        if e_before + 1 <= total_empty:
            rp1 = self.empty_bit.find_kth(e_before + 1)
            r = rp1 - 1
        else:
            r = self.n - 1
        return l, r

    def insert(self, p):
        assert self.occ[p] == 0
        hasL = p > 0 and self.occ[p - 1]
        hasR = p < self.n - 1 and self.occ[p + 1]
        if hasL and hasR:
            l1 = self.r2l[p - 1]
            r2 = self.l2r[p + 1]
            s1 = (p - 1) - l1 + 1
            s2 = r2 - (p + 1) + 1
            self._add_block(s1, -1)
            self._add_block(s2, -1)
            self._add_block(s1 + s2 + 1, 1)
            del self.r2l[p - 1]
            del self.l2r[p + 1]
            self.l2r[l1] = r2
            self.r2l[r2] = l1
            self.total_blocks -= 1
        elif hasL:
            l1 = self.r2l[p - 1]
            s = (p - 1) - l1 + 1
            self._add_block(s, -1)
            self._add_block(s + 1, 1)
            del self.r2l[p - 1]
            self.l2r[l1] = p
            self.r2l[p] = l1
        elif hasR:
            r2 = self.l2r[p + 1]
            s = r2 - (p + 1) + 1
            self._add_block(s, -1)
            self._add_block(s + 1, 1)
            del self.l2r[p + 1]
            self.l2r[p] = r2
            self.r2l[r2] = p
        else:
            self._add_block(1, 1)
            self.l2r[p] = p
            self.r2l[p] = p
            self.total_blocks += 1
        self.occ[p] = 1
        self.pos_bit.add(p, 1)
        self.empty_bit.add(p, -1)
        self.total_occ += 1

    def remove(self, p):
        assert self.occ[p] == 1
        if p in self.l2r and p in self.r2l:
            # 孤立块
            self.occ[p] = 0
            self.pos_bit.add(p, -1)
            self.empty_bit.add(p, 1)
            self.total_occ -= 1
            self._add_block(1, -1)
            del self.l2r[p]
            del self.r2l[p]
            self.total_blocks -= 1
        elif p in self.l2r:
            # 块左端, 块为 [p, r]
            r = self.l2r[p]
            s = r - p + 1
            self.occ[p] = 0
            self.pos_bit.add(p, -1)
            self.empty_bit.add(p, 1)
            self.total_occ -= 1
            self._add_block(s, -1)
            if p + 1 <= r:
                self._add_block(s - 1, 1)
                del self.l2r[p]
                self.l2r[p + 1] = r
                self.r2l[r] = p + 1
            else:
                # 不可能: p 是左端且不是孤立 => r > p
                raise RuntimeError('unreachable')
        elif p in self.r2l:
            # 块右端, 块为 [l, p]
            l = self.r2l[p]
            s = p - l + 1
            self.occ[p] = 0
            self.pos_bit.add(p, -1)
            self.empty_bit.add(p, 1)
            self.total_occ -= 1
            self._add_block(s, -1)
            if l <= p - 1:
                self._add_block(s - 1, 1)
                del self.r2l[p]
                self.r2l[p - 1] = l
                self.l2r[l] = p - 1
            else:
                raise RuntimeError('unreachable')
        else:
            # 中间点: 二分找块 [l, r], 分裂
            l, r = self.block_of(p)
            s = r - l + 1
            self.occ[p] = 0
            self.pos_bit.add(p, -1)
            self.empty_bit.add(p, 1)
            self.total_occ -= 1
            self._add_block(s, -1)
            self._add_block(p - l, 1)
            self._add_block(r - p, 1)
            # 更新端点映射: 旧块 [l, r] -> [l, p-1] 和 [p+1, r]
            self.l2r[l] = p - 1
            self.r2l[p - 1] = l
            self.l2r[p + 1] = r
            self.r2l[r] = p + 1
            self.total_blocks += 1

    def top_t_sum(self, t):
        if t >= self.total_blocks:
            return self.total_occ
        x = self.total_blocks - t
        s = self.cnt_bit.find_kth(x) + 1
        cnt_less = self.cnt_bit.sum(s - 1)
        sum_less = self.sum_bit.sum(s - 1)
        need = x - cnt_less
        return self.total_occ - (sum_less + need * s)

def brute_blocks(occ, n):
    blocks = []
    i = 0
    while i < n:
        if occ[i]:
            j = i
            while j + 1 < n and occ[j + 1]:
                j += 1
            blocks.append(j - i + 1)
            i = j + 1
        else:
            i += 1
    return blocks

if __name__ == '__main__':
    import random
    random.seed(5)
    bad = 0
    for trial in range(300):
        n = random.randint(1, 12)
        pb = PosBlock(n)
        occ = [0] * n
        for step in range(40):
            if random.random() < 0.6:
                cand = [p for p in range(n) if not occ[p]]
                if not cand:
                    continue
                p = random.choice(cand)
                pb.insert(p)
                occ[p] = 1
            else:
                cand = [p for p in range(n) if occ[p]]
                if not cand:
                    continue
                p = random.choice(cand)
                pb.remove(p)
                occ[p] = 0
            blocks = sorted(brute_blocks(occ, n), reverse=True)
            if pb.total_occ != sum(occ) or pb.total_blocks != len(blocks):
                print('COUNT BUG', occ, blocks, pb.total_occ, pb.total_blocks)
                bad += 1
                break
            for t in range(1, len(blocks) + 2):
                expect = sum(blocks[:t])
                got = pb.top_t_sum(t)
                if got != expect:
                    print('TOP BUG occ=%s blocks=%s t=%d expect=%d got=%d' % (occ, blocks, t, expect, got))
                    bad += 1
                    break
            if bad:
                break
        if bad:
            break
    print('PosBlock(hybrid) unit test done, bad =', bad)
