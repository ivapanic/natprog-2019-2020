

int count_all_paths(int x1, int y1, int x2, int y2, int m, int n) {

    int path = 1;
    for(int i = y2; i < (x2 + y2 - 1); i++) {
        path *= i;
        path /= (i - y2 + 1);
    }
    return path;
}



int main() {
    int m, n, p;
    std::cin >> m >> n >> p;

    std::vector<int[]> traps;

    for(int i = 0; i < p; ++i) {
        int pair[2];
        std::cin >> x >> y;
        pair[0] = x;
        pair[1] = y;
        traps.push_back(pair);
    }

    int x1 = 0; int y1 = 0;
    int x2 = m; int y2 = n;

    int total paths = count_all_paths(x1, y1, x2, y2, m, n);

    for(int i = 0; i < p; ++i) {
        int x2 = traps[i][0];
        int y2 = traps[i][1];
        total_paths -= count_all_paths(x1, y1, x2, y2, m, n);
        x1 = x2;
        y1 = y2;
    }

    std::cout >> total_paths;


}