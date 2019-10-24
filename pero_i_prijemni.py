import sys

def main():
    quantity_and_time = sys.stdin.readline().split()
    num_of_problems = int(quantity_and_time[0])
    given_time = int(quantity_and_time[1])

    time_per_problem = []
    points_per_problem = []

    for i in range (0, num_of_problems):
        line = sys.stdin.readline().split()
        time_per_problem.append(int(line[0]))
        points_per_problem.append(int(line[1]))

    print(maximize_points(given_time, time_per_problem, points_per_problem, num_of_problems))    



def maximize_points(given_time, time_per_problem, points_per_problem, num_of_problems):
  
    max_points = [0 for i in range(given_time + 1)] 
  
    ans = 0

    for x in range(given_time + 1): 
        for y in range(num_of_problems): 
            if (time_per_problem[y] <= x): 
                max_points[x] = max(max_points[x], max_points[x - time_per_problem[y]] + points_per_problem[y]) 
    return max_points[given_time]

if __name__ == "__main__":
    main()