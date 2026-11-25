#!/usr/bin/env python3
# 一键对拍：
#   python run.py                # 编译 ../../luogu/P8779.cpp，跑 300 轮
#   python run.py 50             # 跑 50 轮
#   python run.py 50 --src x.cpp # 编译别的文件（自测用）
#
# 为什么用 .py 当入口而不是 .bat：cmd 对引号/中文/反斜杠的处理很不稳，
# python 拼路径不会出这种岔子。
import os
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
DEFAULT_SRC = os.path.normpath(os.path.join(HERE, "..", "..", "luogu", "P8779.cpp"))

argv = sys.argv[1:]
rounds = "300"
src = DEFAULT_SRC
if "--src" in argv:
    i = argv.index("--src")
    src = os.path.abspath(argv[i + 1])
    del argv[i:i + 2]
if argv:
    rounds = argv[0]

exe = os.path.join(HERE, "mine.exe")

print("[1/2] 编译 %s（-O2，和评测机同级别）" % src)
r = subprocess.run(["g++", "-O2", "-std=c++14", "-Wall", "-o", exe, src],
                   capture_output=True, text=True)
if r.returncode != 0:
    print(r.stderr[:3000])
    print("编译失败，先修语法错")
    sys.exit(1)
if r.stderr.strip():
    print("有编译警告（-Wall），值得看一眼：")
    print(r.stderr[:2000])

print("[2/2] 对拍 %s 轮" % rounds)
stress = os.path.normpath(os.path.join(HERE, "..", "stress.py"))
sys.exit(subprocess.run([sys.executable, stress, exe,
                         os.path.join(HERE, "brute.py"),
                         os.path.join(HERE, "gen.py"), rounds]).returncode)
