//http://acm.timus.ru/problem.aspx?num=1196

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
   	freopen("1196.input.txt", "rt", stdin);
   	//freopen("h_output.txt", "wt", stdout);
#endif

    using value = unsigned long;
    std::vector<value> teachers_list;
    std::vector<value> students_list;

    value count = 0;
    cin >> count;
    teachers_list.reserve(count);

    for (int i = 0; i < count; ++i)
    {
        value year = 0;
        cin >> year;
        teachers_list.push_back(year);
    }

    cin >> count;
    students_list.reserve(count);
    
    for (int i = 0; i < count; ++i)
    {
        value year = 0;
        cin >> year;
        students_list.push_back(year);
    }

    auto matches_count = 0;

    for(auto s : students_list)
    {
        matches_count += binary_search(teachers_list.begin(), teachers_list.end(), s);
    }

    cout << endl << matches_count << endl;
    return 0;
}