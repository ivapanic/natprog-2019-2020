#include <iostream>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>

int num_factors(int input)
{
    int total_number = 0;
    for (int i = 1; i * i <= input; ++i)
    {
        if (0 == input % i)
        {
            if (input / i == i)
            {
                ++total_number;
            }
            else
            {
                total_number += 2;
            }
        }
    }
    return total_number;
}



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::unordered_map<int, std::set<int>> factors;
    const int the_magic_constant = 100000;
    for (int i = 1; i <= the_magic_constant; ++i)
    {
        const int result = num_factors(i);
        auto it = factors.find(result);
        if (it != factors.end())
        {
            it->second.insert(i);
        }
        else
        {
            factors.emplace(std::make_pair(result, std::set<int>({ i })));
        }
    }

    int num_requests;
    std::cin >> num_requests;

    for (int i = 0; i < num_requests; ++i)
    {
        int a, b, k;
        std::cin >> a >> b >> k;
        std::set<int> const& range = factors[k];
//        auto first = range.lower_bound(a);
//        auto last = range.upper_bound(b);

        int distance = 0;
        for(int r : range) {
            if(r >= a && r <= b)
                distance++;
        }
        std::cout << distance << '\n';
    }
}