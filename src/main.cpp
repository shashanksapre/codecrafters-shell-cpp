#include <cstdlib>
#include <vector>
#include <map>
#include <functional>
#include <iostream>

int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  const char *path = std::getenv("PATH");

  std::vector<std::string> dirs;

  for (const char *p = path; *p != '\0'; p++)
  {
    if (*p == ':')
    {
    }
  }

  if (path != nullptr)
  {
    std::string pathStr(path);
  }

  // Uncomment this block to pass the first stage
  std::cout << "$ ";

  std::string input;
  bool isExit = false;

  std::map<std::string, std::function<void()>> commands = {
      {"echo", [&input]()
       {
         std::cout << input.substr(5) << "\n";
         std::cout << "$ ";
       }},
      {"type", [&input]()
       {
         if (input.substr(5) == "echo" || input.substr(5) == "type" || input.substr(5) == "exit")
         {
           std::cout << input.substr(5) << " is a shell builtin" << "\n";
         }
         else
         {
           std::cout << input.substr(5) << ": not found\n";
         }
         std::cout << "$ ";
       }},
      {"exit", [&isExit]()
       {
         isExit = true;
       }}};

  while (isExit == false)
  {
    std::getline(std::cin, input);
    auto it = commands.find(input.substr(0, input.find(' ')));
    if (it != commands.end())
    {
      it->second();
    }
    else
    {
      std::cout << input << ": command not found\n";
      std::cout << "$ ";
    }
  }
}
