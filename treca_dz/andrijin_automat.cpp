#include <iostream>
#include <algorithm>
#include <vector>

#define BIG_NUMBER 10000

int solve(int m, int n, std::vector<int> &values, std::vector<char> &colours, std::vector<char> &all_colours, std::vector<std::vector<int>> &states, int last_used_colour) {
    if (m < 0) return BIG_NUMBER;
    if (m == 0) return 0;
    int best = BIG_NUMBER;
    if(last_used_colour != -1)
        if (states[m][last_used_colour] != -1)
            return states[m][last_used_colour];

    int new_colour = last_used_colour;

    for(int i = 0; i < n; ++i) {
        new_colour = std::distance(all_colours.begin(), std::find(all_colours.begin(), all_colours.end(), colours[i]));
        if (last_used_colour != new_colour) {
            best = std::min(best, solve(m - values[i], n, values, colours, all_colours, states, new_colour) + 1);
        }
        continue;
    }
    states[m][last_used_colour] = best;
    return best;

}


int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int m;
    //n - broj svih vrsta kovanica, m - iznos koji je potrebno isplatiti
    //u sljedecih n redaka: v - vrijednost kovanice, c - boja kovanice
    //trazi se: najmanji potreban broj kovanica da se isplati cjelokupan iznos (bez ponavljanja kovanica iste boje!)

    std::cin >> n >> m;
    std::vector<int> values;
    std::vector<char> colours;

    for(int i = 0; i < n; ++i) {

        int v;
        char col;

        std::cin >> v >> col;
        values.push_back(v);
        colours.push_back(col);
    }

    std::vector<std::vector<int>> states(m + 1, std::vector(5, -1));

    std::vector<char> all_colours;
    all_colours.push_back('B');
    all_colours.push_back('C');
    all_colours.push_back('P');
    all_colours.push_back('Z');
    all_colours.push_back('S');

    int last_used_colour = -1;
    int final_solution = solve(m, n, values, colours, all_colours, states, last_used_colour);
    std::cout << final_solution << "\n";

}