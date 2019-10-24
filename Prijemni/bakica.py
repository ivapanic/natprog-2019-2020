import sys

def slice(matrix, x, y):
    result = matrix[x[0]:x[1]]
    result = [row[y[0]:y[1]] for row in result]
    return result

def main():
    trows, tcols = [int(x) for x in sys.stdin.readline().rstrip().split()]
    prows, pcols = [int(x) for x in sys.stdin.readline().rstrip().split()]
    array = []
    for i in range(0, trows):
        array.append(list(sys.stdin.readline().rstrip()))
    pattern = []
    for i in range(0, prows):
        pattern.append(list(sys.stdin.readline().rstrip()))

    for i in range(0, trows - prows + 1):
        for j in range(0, tcols - pcols + 1):
            if slice(array, (i,prows+i), (j,pcols+j)) == pattern:
                print("DA")
                return
    print("NE")

if __name__ == "__main__":
    main()
