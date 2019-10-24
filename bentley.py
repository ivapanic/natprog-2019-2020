import sys
from functools import reduce
import operator

def main():
   num_employees, num_requests = sys.stdin.readline().split()
   num_employees = int(num_employees)
   num_requests = int(num_requests)
   to_print = []
   

   salaries = [int(x) for x in sys.stdin.readline().split()]
   for i in range(0, num_requests):
       request = sys.stdin.readline().split()
       if request[0][0] == "s":
           sum = reduce(operator.add, salaries[int(request[1])-1:int(request[2])])
           to_print.append(str(sum))
           last_line = request
       elif request[0][0] == "r":
           new_salaries = [x+int(request[3]) for x in salaries[int(request[1])-1:int(request[2])]]
           salaries[int(request[1])-1:int(request[2])] = new_salaries
           last_line = request
   print("\n".join(to_print))

       
           
        


if __name__ == "__main__":
    main()