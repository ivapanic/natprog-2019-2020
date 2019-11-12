#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

std::vector<std::tuple<int, std::vector<int>>> neighbour_positions(int x, int y) {
    //0 - new direction: right
    //1 - new direction: down
    //2 - new direction: down-right
    std::vector<std::tuple<int, std::vector<int>>> neighbourhood;
    std::vector<int> new_position(2);

    if(x - 1 >= 0 && y - 1 >= 0) {
        new_position[0] = x - 1; new_position[1] = y - 1;
        neighbourhood.push_back(std::make_tuple(2, new_position));
        new_position[0] = x - 1; new_position[1] = y;
        neighbourhood.push_back(std::make_tuple(0, new_position));
        new_position[0] = x; new_position[1] = y - 1;
        neighbourhood.push_back(std::make_tuple(1, new_position));
    }
    else if (x - 1 < 0) {
        new_position[0] = x; new_position[1] = y - 1;
        neighbourhood.push_back(std::make_tuple(1, new_position));
    }
    else if (y - 1 < 0) {
        new_position[0] = x - 1; new_position[1] = y;
        neighbourhood.push_back(std::make_tuple(0, new_position));
    }

    return neighbourhood;
}

int find_best_path(int n, int m, std::vector<std::vector<std::vector<int>>> &sum, std::vector<std::vector<int>> &garden) {
    sum[0][0][0] = garden[0][0];
    sum[1][0][0] = garden[0][0];
    sum[2][0][0] = garden[0][0];

    for(int x = 0; x < n; ++x) {
        for(int y = 0; y < m; ++y) {
            if(x == 0 && y == 0) continue;

            for(auto [move, position] : neighbour_positions(x, y)) {
                int result = -50;
                for(int i = 0; i < 2; ++i) {
                    if (i == move) continue;
                    result = std::max(sum[i][position[0]][position[1]], result);
                }
                if(result >= 0) sum[move][x][y] = garden[x][y] + result;
            }
        }
    }

    int final_result = 0;

    for(int x = 0; x <= 2; ++x) {
        for(int y = 0; y < n; ++y) {
            for(int z = 0; z < m; ++z) {
                final_result = std::max(final_result, sum[x][y][z]);
            }
        }
    }

    return final_result;
}


int main() {

   //dvodimenzionalna matrica s n redaka i m stupaca
   //prazna polja: '.', cvijece 'X'
   //ciprijan mora skupiti max cvijeca tako da se krece samo desno, dolje, dolje-desno bez ponavljanja pokreta

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> garden(n, std::vector<int>(m, 0));
    std::vector<std::vector<std::vector<int>>> sum(3, std::vector<std::vector<int>>(n, std::vector<int>(m, -50)));

    for(int x = 0; x < n; ++x) {
        for(int y = 0; y < m; ++y) {
            char input;
            std::cin >> input;
            if(input == 'X')
                garden[x][y] = 1;

            std::vector<int> element(2);
            element.push_back(-1);
            element.push_back(garden[x][y]);
        }
    }
    int result = find_best_path(n, m, sum, garden);
    std::cout << result;
}