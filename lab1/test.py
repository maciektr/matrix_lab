import numpy as np
from os import system
from random import randint
from time import sleep

MSIZE = 1e3
MVAL = 1e4
SEP = ' '
VERBOSE = False #True

def matrix_to_str(A):
    return SEP.join([' '.join(map(str, v)) for v in A])


i = 0
while True:
    n = randint(1,MSIZE)
    k = randint(1,MSIZE)
    m = randint(1,MSIZE)
    A = np.random.randint(MVAL, size=(n,k))
    B = np.random.randint(MVAL, size=(k,m))
    rep = f'{n} {k}{SEP}{matrix_to_str(A)}{SEP}{k} {m}{SEP}{matrix_to_str(B)}'
    with open('in.txt', 'w') as f:
        f.write(rep)
    system(f'./zad > out.txt < in.txt')
    with open('out.txt', 'r') as f:
        mat = [list(map(int, line.strip().split(' '))) for line in f.readlines()]
        M = np.array(mat)
        C = A @ B
        if VERBOSE:
            print('----')
            print(np.max(M), np.min(M), np.max(C))
            print(n,k,m, len(mat))
            print(M.shape, A.shape, B.shape)
            print('====')
        assert np.all(M == C)
        print(i, 'OK')
    system('rm out.txt in.txt')
    i+=1
