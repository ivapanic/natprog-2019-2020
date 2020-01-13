#include <iostream>
#include <vector>
#include <algorithm>

int max(int a, int b, int c, int d)
{
  return std::max(a, std::max(b, std::max(c, d)));
}

using std::max;

int main()
{
  int n, m;
  std::cin >> n >> m;
  // alociranje 1 reda i 1 stupca vise da se izbjegne range check
  std::vector<int> garden((n+1) * (m+1), 0);
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= m; ++j)
    {
      char input;
      std::cin >> input;
      if ('X' == input)
      {
        garden[i * m + j] = 1;
      }
    }
  }

  std::vector<int> max_down(garden.size(), 0);
  std::vector<int> max_right(garden.size(), 0);
  std::vector<int> max_down_right(garden.size(), 0);
  int maximum = 0;
  for (int i = 1; i <= n ; ++i)
  {
    for (int j = 1; j <= m ; ++j)
    {
      // uzastopni pokreti nisu moguci; krajnji slucaj je naizmjenicno dolje, dijagonalno (ili desno pa dijagonalno)
      // sto znaci da se nikada ne moze pomaknuti vise od 2 puta vise po jednoj osi nego po drugoj
      if (j > i + i  || i > j + j)
      {
        continue;
      }
      const int curr_idx = i * m + j;
      max_down[curr_idx] = max(max_right[(i - 1) * m + j], max_down_right[(i - 1) * m + j]) + garden[i * m + j];
      max_right[curr_idx] = max(max_down[i * m + j - 1], max_down_right[i * m + j - 1]) + garden[i * m + j];
      max_down_right[curr_idx] = max(max_down[(i - 1) * m + j - 1], max_right[(i - 1) * m + j - 1]) + garden[i * m + j];
      maximum = max(maximum, max_down[curr_idx], max_right[curr_idx], max_down_right[curr_idx]);
    }
  }

  std::cout << maximum << std::endl;
}