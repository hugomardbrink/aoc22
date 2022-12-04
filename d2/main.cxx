#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
  std::ifstream file{"../d2/input.txt"};

  uint32_t tot{0};
  uint8_t e, y;

  std::string line;
  while (std::getline(file, line))
  {
    std::stringstream iss{line};

    iss >> e >> y;
    int es{(e % 65)}, ys{(y % 88)};

    if (y == 'Z')
      tot += 7 + ((es + 1) % 3);
    else if (y == 'Y')
      tot += 4 + es;
    else
      tot += 1 + ((es + 2) % 3);
  }

  std::cout << tot << std::endl;
  return 0;
}