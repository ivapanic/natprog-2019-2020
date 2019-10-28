#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<iterator>




struct Q {
    int index;
    std::vector<long> data;
    std::string res;

    //Q(Q&&) noexcept = default;
};

int search(std::vector<int> const& numbers, long given_number, int interval, int index)
{
    if(std::find(numbers.begin(), numbers.end(), given_number) != numbers.end())
    {
        if(index >= interval)
            return 0;
        return 1;
    }
    return 0;
}

int main(void) {

    int length, number_of_queries;
    std::cin >> length >> number_of_queries;

    std::vector<int> numbers;
    std::copy_n(std::istream_iterator<int>(std::cin), length, std::back_inserter(numbers));

    std::vector<Q> queries;
    queries.reserve(number_of_queries);
    for (int i = 0; i < number_of_queries; ++i) {
        Q q;
        q.index = i;
        std::copy_n(std::istream_iterator<long>(std::cin), 2, std::back_inserter(q.data));
        queries.emplace_back(std::move(q));
    }

    const int num = queries.size();
    const Q *pointer = (num > 0) ? queries.data() : nullptr;

    for (int i = 0; i < num; i++) {
        int query_answer;
        int given_number = queries[i].data[1];
        int index = std::distance(numbers.begin(), std::find(numbers.begin(), numbers.end(), given_number));
        query_answer = search(numbers, given_number, queries[i].data[0], index);
        query_answer == 1 ? queries[i].res = std::string("DA") : queries[i].res = std::string("NE");
    }

    for (int i = 0; i < num; i++) {
        std::cout << queries[i].res << std::endl;
    }
}
