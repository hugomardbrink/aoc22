#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

bool isTreeVisible(std::vector<std::string> &treeGrid, int row, int col, std::priority_queue<int> &scenicScores)
{
  char tree = treeGrid[row][col];
  std::tuple<bool, int> l{true, 0}, r{true, 0}, u{true, 0}, d{true, 0};

  for (int i{row - 1}; i >= 0; i--)
  {
    if (treeGrid[i][col] >= tree)
    {
      std::get<0>(l) = false;
      std::get<1>(l)++;
      break;
    }
    else
      std::get<1>(l)++;
  }

  for (int i{row + 1}; i < treeGrid[row].size(); i++)
  {
    if (treeGrid[i][col] >= tree)
    {
      std::get<0>(r) = false;
      std::get<1>(r)++;
      break;
    }
    else
      std::get<1>(r)++;
  }

  for (int i{col - 1}; i >= 0; i--)
  {
    if (treeGrid[row][i] >= tree)
    {
      std::get<0>(u) = false;
      std::get<1>(u)++;
      break;
    }
    else
      std::get<1>(u)++;
  }

  for (int i{col + 1}; i < treeGrid.size(); i++)
  {
    if (treeGrid[row][i] >= tree)
    {
      std::get<0>(d) = false;
      std::get<1>(d)++;
      break;
    }
    else
      std::get<1>(d)++;
  }

  scenicScores.push(std::get<1>(l) * std::get<1>(r) * std::get<1>(u) * std::get<1>(d));
  return std::get<0>(l) || std::get<0>(r) || std::get<0>(u) || std::get<0>(d);
}

int main()
{
  std::ifstream file{"../d8/input.txt"};

  std::string line;
  std::vector<std::string> treeGrid{};
  while (std::getline(file, line))
    treeGrid.push_back(line);

  std::priority_queue<int> scenicScores{};

  int visible{0};
  for (int i{0}; i < treeGrid.size(); i++)
    for (int j{0}; j < treeGrid[i].size(); j++)
      if (isTreeVisible(treeGrid, i, j, scenicScores))
        visible++;

  std::cout << visible << std::endl;
  std::cout << scenicScores.top() << std::endl;
  return 0;
}