#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>

uint32_t getPrio(std::string &fst, std::string &snd, std::string &thd)
{
  for (auto &i1 : fst)
    for (auto &i2 : snd)
      for (auto &i3 : thd)
        if (i1 == i2 && i2 == i3)
        {
          if (std::isupper(i1))
          {
            return 27 + (i1 % 65);
          }
          else
          {
            return 1 + (i1 % 97);
          }
        }

  return 0;
}

int main()
{
  std::ifstream file{"../d3/input.txt"};
  std::vector<std::string> input;
  std::string line;
  while (std::getline(file, line))
    input.push_back(line);

  uint32_t sum{0};
  std::string fst{""}, snd{""}, thd{""};

  for (int i{2}; i < input.size(); i += 3)
  {
    fst = input[i - 2];
    snd = input[i - 1];
    thd = input[i];

    sum += getPrio(fst, snd, thd);
  }

  std::cout << sum << std::endl;

  return 0;
}