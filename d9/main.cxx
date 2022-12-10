#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

typedef std::pair<int, int> Pos;
struct PosHash
{
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &pair) const
  {
    return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
  }
};

int signum(int n)
{
  return (0 < n) - (n < 0);
}

int main()
{
  std::ifstream file{"../d9/input.txt"};
  std::string line;

  Pos h{0, 0};
  std::vector<Pos> knots(9);
  std::fill(knots.begin(), knots.end(), std::pair<int, int>{0, 0});

  std::unordered_set<Pos, PosHash> visited;

  visited.insert(knots.back());
  while (std::getline(file, line))
  {
    std::stringstream iss(line);
    char dir;
    int dis;
    iss >> dir >> dis;

    for (int i{0}; i < dis; i++)
    {
      switch (dir)
      {
      case 'U':
        h.second++;
        break;
      case 'D':
        h.second--;
        break;
      case 'L':
        h.first--;
        break;
      case 'R':
        h.first++;
        break;
      }

      Pos *prev = &h;
      for (int j{0}; j < knots.size(); j++)
      {
        Pos deltaPos{prev->first - knots[j].first, prev->second - knots[j].second};
        if (std::abs(deltaPos.second) == 2 || std::abs(deltaPos.first) == 2)
        {
          knots[j].first += signum(deltaPos.first);
          knots[j].second += signum(deltaPos.second);
        }
        prev = &knots[j];
      }

      visited.insert(knots.back());
    }
  }

  std::cout << visited.size() << std::endl;

  return 0;
}