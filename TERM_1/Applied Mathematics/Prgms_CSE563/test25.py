def minor(m, i, j):
    return [row[:j] + row[j+1:] for row in (m[:i] + m[i+1:])]
 
 
def determinantOfMatrix(mat):
    total = 0

    for col in range(len(mat)):

        sin = (-1)**(col)

        sub_list = determinantOfMatrix(minor(mat, 0, col))
 
        total = total + (sin * mat[0][col] * sub_list)
 

    return total

def main():
    
    mat = [
            [1, 2, 3],
            [3, 4, 5],
            [2, 1, 7],
          ]

    print('Determinant of the matrix is :', determinantOfMatrix(mat))


if __name__ == '__main__':
    main()
