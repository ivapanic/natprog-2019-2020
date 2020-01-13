#include <vector>
#include <iostream>
#include <cmath>


inline long long int pos_mod(long long int i, long long int n)
{
    return (i%n + n) % n;
}


auto matrix_1(int n)
{
    std::vector<std::vector<int>> matrix_1(n, std::vector<int>(n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if (i == j)
                matrix_1[i][j] = 1;
            else
                continue;
        }
    }
    return matrix_1;
}


auto multiply_matrices(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> kn)
{
    long long temp;
    int n = matrix1[0].size();
    std::vector<std::vector<int>> temp_mul(n, std::vector<int> (n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; k++){
                temp = pos_mod((long long int)matrix1[i][k] * (long long int) (kn[k][j]), pow(10, 9) + 7);
                temp_mul[i][j] += int(pos_mod(temp, pow(10, 9) + 7));
                temp_mul[i][j] =  int(pos_mod(temp_mul[i][j], pow(10, 9) + 7));
            }

        }

    }
    return temp_mul;
}

auto pow_matrix(std::vector<std::vector<int>> matrix1, int n)
{
    auto temp = matrix_1(matrix1[0].size());
    while(n > 0){
        if(n % 2 == 1){
            temp = multiply_matrices(temp, matrix1);
        }
        matrix1 = multiply_matrices(matrix1, matrix1);
        n = n/2;
    }

    return temp;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    auto matrix1 = matrix_1(n);

    for(int i = 0; i < m; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        matrix1[b - 1][a - 1] = 1;
    }

    std::vector<std::vector<int>> kn(n, std::vector<int>(1));
    for(int i = 0; i < n; ++i) {
        std::cin >> kn[i][0];
    }


    long long int t;
    std::cin >> t;

    matrix1 = pow_matrix(matrix1, t);
    auto result = multiply_matrices(matrix1, kn);

    for(int i = 0; i < n; ++i)
        std::cout << pos_mod(result[i][0], pow(10, 9) +7)  << " ";


}