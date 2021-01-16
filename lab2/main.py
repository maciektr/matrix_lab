from math import sqrt
from numpy.linalg import inv
import numpy as np


def ldlt(matrix):
    result = [[0] * len(matrix) for _ in range(len(matrix))]
    for i in range(len(matrix)):
        for j in range(i+1):
            tmp = 0
            for k in range(j):
                tmp += result[i][k] * result[j][k]
            if (i == j):
                result[i][j] = sqrt(matrix[i][i] - tmp)
            else:
                result[i][j] = (1 / result[j][j] * (matrix[i][j] - tmp))
    c = np.array(result)
    s = np.diag(np.diag(c))
    return c @ inv(s), s @ s

A = [[4, 12, -16],
     [12, 37, -43],
     [-16, -43, 98]]
l,d = ldlt(A)
print(l @ d @ l.T)
