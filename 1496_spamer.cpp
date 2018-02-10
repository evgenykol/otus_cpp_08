//http://acm.timus.ru/problem.aspx?num=1496

#include <iostream>
#include <map>
#include <string>

int main()
{

#ifndef ONLINE_JUDGE
   	freopen("1496.input.txt", "rt", stdin);
   	//freopen("h_output.txt", "wt", stdout);
#endif
  	std::map<std::string, int> words;
   	std::string word;

	std::getline(std::cin, word); //Количество записей

   	while (std::getline(std::cin, word))
   	{
      	words[word]++;
   	}

  	for(auto w : words)
  	{
  		if(w.second > 1)
  		{
  			std::cout << w.first << std::endl;
  		}
  	}

   return 0;
}