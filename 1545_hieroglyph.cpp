//http://acm.timus.ru/problem.aspx?num=1545

#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
   	freopen("h_input.txt", "rt", stdin);
   	//freopen("h_output.txt", "wt", stdout);
#endif
   	auto count = 0;
   	cin >> count;

   	vector<string> strings;
   	strings.reserve(count);

	for(int i = 0; i < count+1; ++i)
   	{
   		string line;
   		getline(std::cin, line);
   		strings.push_back(line);
   	}

   	string letter;
   	cin >> letter;

   	sort(strings.begin(), strings.end());

   	auto pred = [](string a, string b) {return a[0] < b[0];};
   	auto p = equal_range(strings.begin(), strings.end(), letter, pred);

   	for(auto i = p.first; i < p.second; ++i)
   	{
   		cout << *i << endl;
   	}
   	return 0;
}