#include <iostream>
#include <algorithm>

long n, c;


int check_function(long num, long stalls[])  {
    long placed_cows = 1;
    long stall = stalls[0];

    for(int i = 1; i < n; i++) {
        if(stalls[i] - stall >= num) {
            stall = stalls[i];
            placed_cows++;

            if(placed_cows == c) return 1;
        }
    }

    return 0;
}

long binary_search(long stalls[]) {
    long start = 0;
    long end = stalls[n-1];
    long max = -1;

    while(end > start) {
        long mid = (start+end)/2;
        if( check_function(mid, stalls) == 1) {
            if(mid > max) max = mid;
            start = mid+1;
        }
        else end = mid;
    }
    return max;

}



int main() {
    std::cin >> n >> c;
    long stalls[n];

    long solution;

    for(long i = 0; i < n; i++) {
        std::cin >> stalls[i];
    }

    std::sort(stalls, stalls+n);
    solution = binary_search(stalls);

    std::cout << solution;

    return 0;

}
