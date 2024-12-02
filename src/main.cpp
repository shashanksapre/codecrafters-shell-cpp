#include <iostream>

int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // Uncomment this block to pass the first stage
  std::cout << "$ ";

  bool isExit = false;

  while (isExit == false)
  {
    std::string input;
    std::getline(std::cin, input);
    if (input.substr(0, 4) == "exit")
    {
      isExit = true;
      continue;
    }
    else
    {
      std::cout << input << ": command not found\n";
      std::cout << "$ ";
    }
  }
}
