import random
import subprocess

INF = 10 ** 10
def generate_random (n, reale):
    a = []
    if reale:
        a = [random.random () * INF for _ in range (n)]
    else:
        a = [random.randint (-INF, INF) for _ in range (n)]
    return [n] + a

def generate_sorted (n, reale):
    a = []
    if reale:
        a = [random.random() * INF for _ in range(n)]
    else:
        a = [random.randint(-INF, INF) for _ in range(n)]
    a.sort ()
    return [n] + a

def generate_reversed_sorted (n, reale):
    a = []
    if reale:
        a = [random.random() * INF for _ in range(n)]
    else:
        a = [random.randint(-INF, INF) for _ in range(n)]
    a.sort ()
    a.reverse()

    return [n] + a
def generate_toate_egale (n, reale):
    a = []
    if reale:
        x = random.random () * INF
        a = [x for _ in range(n)]
    else:
        x = random.randint (-INF, INF)
        a = [x for _ in range(n)]
    return [n] + a

def generate_partial_sortat (n, reale):
    a = []
    if reale:
        a = [random.random() * INF for _ in range(n)]
    else:
        a = [random.randint(-INF, INF) for _ in range(n)]

    for _ in range (n):
        idx = random.randint (0, n - 2)
        a[idx], a[idx + 1] = a[idx + 1], a[idx]
    return [n] + a


teste = [generate_sorted, generate_reversed_sorted, generate_toate_egale, generate_random, generate_partial_sortat]
nume_teste = ["sortat", "sortat_invers", "toate_egale", "random", "partial_sortat"]
suff = [".txt", "_reale.txt"]

list_n = [10000, 1000000, 10000000]

fisier_cpp = input ()

g = open ("fisiere_int.txt", "r")

for fisier in g.readline().split (' '):
    if fisier == "":
        continue
    with open(fisier, "r") as infile:
        subprocess.run (["g++", fisier_cpp, "-o", "a"])
        result = subprocess.run(f"./a", stdin=infile, capture_output=True, text=True)
        float
        print (f"Programul {fisier_cpp} a rulat in {float (result.stdout) * 1000} milisecunde pe {fisier}")


    subprocess