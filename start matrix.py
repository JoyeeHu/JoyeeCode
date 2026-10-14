import numpy as np
matrix1 = np.array([[2,0,0],[0,2,0],[0,0,2]])
matrix2 = np.array([[1,2,3],[4,5,6],[7,8,9]])
matrix_product1 = matrix1 @ matrix2
print(matrix_product1)
matrix3 = np.array([[1,2,3]])
matrix4 = np.array([[4,5,6]])
matrix_product2 = matrix3 * matrix4
matrix_product3 = matrix3 @ matrix4.T
print("//",matrix_product2,"&",matrix_product3)