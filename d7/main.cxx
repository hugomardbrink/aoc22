#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

constexpr unsigned int hash(const char *s, int off = 0)
{
  return !s[off] ? 5381 : (hash(s, off + 1) * 33) ^ s[off];
}

std::string topDir(std::string &path)
{
  std::string dir;
  for (int i = path.size() - 1; i >= 0; i--)
  {
    if (path[i] != ' ')
      dir.push_back(path[i]);
    else
      break;
  }
  std::reverse(dir.begin(), dir.end());
  return dir;
}

void handleComd(const std::string &operation, std::string &path, std::map<unsigned int, long> &dirs)
{
  std::stringstream iss(operation);
  std::string comd;
  iss >> comd;

  switch (hash(comd.c_str()))
  {
  case hash("$"):
    iss >> comd;
    if (comd != "cd")
      return;

    iss >> comd;
    if (comd == "..")
    {
      for (int i = topDir(path).length(); i >= 0; i--)
        path.pop_back();
    }
    else if (comd != "/")
      path.append(" " + comd);
    return;

  case hash("dir"):
    return;

  default:
    std::stringstream pathss(path);
    std::string tmpPath, dir;
    int pathLen = std::count(path.begin(), path.end(), ' ');
    for (int i{0}; i < pathLen; i++)
    {
      pathss >> dir;
      tmpPath += " " + dir;
      dirs[hash(tmpPath.c_str())] += std::stoi(comd);
    }
    dirs[hash(" ")] += std::stoi(comd);

    return;
  }
}

int main()
{
  std::ifstream file{"../d7/input.txt"};
  std::map<unsigned int, long> dirs{};

  std::string line, path;
  while (std::getline(file, line))
    handleComd(line, path, dirs);

  int sum{0};
  for (auto &[_, size] : dirs)
    if (size <= 100000)
      sum += size;

  long toDelete = 30000000 - (70000000 - dirs[hash(" ")]);

  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  for (auto &[_, size] : dirs)
    if (size >= toDelete)
      pq.push(size);

  std::cout << pq.top() << std::endl;
  return 0;
}