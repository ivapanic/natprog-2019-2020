#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>

int main()
{
    std::size_t n, q;
    std::cin >> n >> q;
    std::vector<int64_t> temperatures;
    temperatures.reserve(n);

    std::copy_n(std::istream_iterator<int64_t>(std::cin), n, std::back_inserter(temperatures));
    int64_t current_val = temperatures.front();

    for (std::size_t i = 1; i <= n; ++i)
    {
        temperatures[i] -= current_val;
        current_val += temperatures[i];
    }


    for (std::size_t i = 0; i < q; ++i)
    {
        int type;
        std::cin >> type;
        if (1 == type)
        {
            std::size_t l, r;
            int64_t diff;
            std::cin >> l >> r >> diff;
            temperatures[l - 1] += diff;
            temperatures[r] -= diff;
        }
        else
        {
            std::size_t idx;
            std::cin >> idx;
            std::cout << std::accumulate(temperatures.begin(), temperatures.begin() + idx, 0LL, std::plus<>()) << std::endl;
        }
    }
}