#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
  std::ifstream file{"../d4/input.txt"};

  uint32_t pairs{0};

  std::string line;
  while (std::getline(file, line))
  {
    std::string fst{line.substr(0, line.find(','))}, snd{line.substr(line.find(',') + 1)};

    fst = fst.replace(fst.find("-"), 1, " ");
    snd = snd.replace(snd.find("-"), 1, " ");

    uint32_t fl, fh, sl, sh;
    std::stringstream fstSs(fst), sndSs(snd);

    fstSs >> fl >> fh;
    sndSs >> sl >> sh;

    if (!(fh < sl || sh < fl))
      pairs++;
  }

  std::cout << pairs << std::endl;

  return 0;
}