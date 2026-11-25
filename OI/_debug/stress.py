#!/usr/bin/env python3
# 对拍器（通用）。用法：
#   python stress.py <你的.exe> <暴力.exe> <数据生成器.py> [轮数]
# 生成器每次用 "种子" 作参数，输出一整个输入文件（可以是多组 T）。
import subprocess, sys, os

USAGE = "python stress.py <sol.exe> <brute.exe> <gen.py> [rounds=300]"


def run(exe, inp):
    # 暴力可以直接用 .py 写（python 跑），不用为了对拍专门编一个 exe
    cmd = [sys.executable, exe] if exe.lower().endswith(".py") else [exe]
    p = subprocess.run(cmd, input=inp, capture_output=True, text=True)
    return p.returncode, p.stdout.split()


def main():
    if len(sys.argv) < 4:
        print(USAGE); return 2
    sol, brute, gen = sys.argv[1], sys.argv[2], sys.argv[3]
    rounds = int(sys.argv[4]) if len(sys.argv) > 4 else 300
    here = os.path.dirname(os.path.abspath(__file__))
    bad_rounds = bad_cases = total = 0
    first = None
    for seed in range(1, rounds + 1):
        inp = subprocess.run([sys.executable, os.path.join(here, gen), str(seed)],
                             capture_output=True, text=True).stdout
        if not inp.strip():
            print("生成器没输出数据，检查生成器", gen); return 2
        rc, a = run(sol, inp)
        _, b = run(brute, inp)
        if rc != 0:                      # 你的程序崩了
            bad_rounds += 1
            if first is None:
                first = (seed, "种子 %d：程序崩了 rc=%d" % (seed, rc), inp, ["<crash>"], b)
            continue
        if len(a) != len(b):
            bad_rounds += 1
            if first is None:
                first = (seed, "种子 %d：输出个数 %d vs %d" % (seed, len(a), len(b)), inp, a, b)
            continue
        for i, (x, y) in enumerate(zip(a, b)):
            total += 1
            if x != y:
                bad_cases += 1
                bad_rounds += 1
                if first is None:
                    first = (seed, "种子 %d，第 %d 个询问：你的答案 %s，暴力 %s"
                             % (seed, i + 1, x, y), inp, a, b)
                break
    print("轮数 %d，出错轮数 %d，逐组对比 %d 组，错的 %d 组" %
          (rounds, bad_rounds, total, bad_cases))
    if first:
        first_seed, tag, inp, a, b = first
        print("=" * 50)
        print("第一个反例：", tag)
        print("--- 输入 ---");  print(inp.rstrip())
        print("--- 你的输出 ---"); print(" ".join(a[:40]))
        print("--- 暴力输出 ---"); print(" ".join(b[:40]))
        print("=" * 50)
        print("复现这一份数据（在 _debug/p8779 目录下）：")
        print("  python gen.py %d > case.txt" % first_seed)
        print("  .\\mine.exe < case.txt")
        print("  python brute.py < case.txt")
    return 0


if __name__ == "__main__":
    sys.exit(main())
