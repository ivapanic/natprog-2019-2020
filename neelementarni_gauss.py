import sys


def main():
    n = int(sys.stdin.readline())
    #Sn = (n/2)*(2*a1 + (n-1)*d)
    sum = (n/2)*(1+n)
    number_of_divisible_by_thirteen = int(n/13)
    sum_of_thirteens = (number_of_divisible_by_thirteen/2)*(2*13 + (number_of_divisible_by_thirteen-1)*13)
    sum += sum_of_thirteens
    print(int(sum))



    
    


if __name__ == "__main__":
    main()