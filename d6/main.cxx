#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
  std::ifstream file{"../d6/input.txt"};
  std::string buffer;
  std::getline(file, buffer);
  int markerLen{14};

  for (int i{markerLen - 1}; i < buffer.size(); i++)
  {
    std::string marker{};
    for (int j{0}; j < markerLen; j++)
      if (std::find(marker.begin(), marker.end(), buffer[i - j]) == marker.end())
        marker.push_back(buffer[i - j]);

    if (marker.size() == markerLen)
    {
      std::cout << i + 1 << std::endl;
      break;
    }
  }

  return 0;
}