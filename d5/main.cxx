#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
  std::ifstream file{"../d5/input.txt"};

  std::vector<std::string> input;
  std::string line, ignore;
  while (std::getline(file, line))
    input.push_back(line);

  const auto it = std::find_if(input.begin(), input.end(), [&](const auto &l)
                               { return l[1] == '1'; });
  const int crateVerLen = it - input.begin();
  const int crateHorLen = input[0].size();
  std::map<int, std::stack<char>> crates{};

  for (int i{crateVerLen - 1}; i >= 0; i--)
    for (int j{1}; j < crateHorLen; j += 4)
      if (input[i][j] != ' ')
        crates[(j / 4) + 1].push(input[i][j]);

  for (int i{crateVerLen + 2}; i < input.size(); i++)
  {
    std::stringstream iss(input[i]);
    int amount, from, to;
    iss >> ignore >> amount >> ignore >> from >> ignore >> to;

    std::vector<char> cs{};
    for (int j{0}; j < amount; j++)
    {
      cs.push_back(crates[from].top());
      crates[from].pop();
    }
    for (int j = cs.size() - 1; j >= 0; j--)
      crates[to].push(cs[j]);
  }

  for (auto &[_, cs] : crates)
    std::cout << cs.top();

  std::cout << std::endl;

  return 0;
}