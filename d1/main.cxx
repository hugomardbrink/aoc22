#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

int main()
{
  std::ifstream file{"../d1/input.txt"};
  std::priority_queue<int> calories{};

  std::uint32_t tot{0}, cur{0}, n;
  std::string line;
  while (std::getline(file, line))
  {
    std::stringstream iss(line);
    if (line.length())
    {
      iss >> n;
      cur += n;
    }
    else
    {
      calories.emplace(cur);
      cur = 0;
    }
  }
  tot = calories.top();

  for (std::uint32_t i{0}; i < 2; i++)
  {
    calories.pop();
    tot += calories.top();
  }

  std::cout << tot << std::endl;

  return 0;
}