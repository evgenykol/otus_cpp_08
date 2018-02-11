//http://acm.timus.ru/problem.aspx?space=1&num=1837

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <queue>

using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("1837_input.txt", "rt", stdin);
    //freopen("h_output.txt", "wt", stdout);
#endif
    map<string, set<string>> persons;
    int commands = 0;

    cin >> commands;

    for(int i = 0; i < commands; ++i)
    {
        string names[3];
        cin >> names[0] >> names[1] >> names[2]; 

        persons[names[0]].insert({names[1], names[2]});
        persons[names[1]].insert({names[0], names[2]});
        persons[names[2]].insert({names[0], names[1]});
    }
    // for(auto p : persons)
    // {
    //     cout << p.first << ": ";
    //     for(auto tm : p.second)
    //     {
    //         cout << tm << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    string top;
    map<string, int> rating;

    if(persons.count("Isenbaev"))
    {
        top = "Isenbaev";

        queue<string> q;
        q.push(top);

        map<string, bool> used;


        used[top] = true; 

        while(!q.empty())
        {
            auto v = q.front();
            q.pop();
            for(auto vv : persons[v])
            {
                if(!used[vv])
                {
                    used[vv] = true;
                    q.push(vv);
                    rating[vv] = rating[v]+1;
                }
            }
        }
    }
    
    for(auto p : persons)
    {
        cout << p.first << " ";
        if (p.first == "Isenbaev")
        {
            cout << "0";
        }
        else if(rating[p.first])
        {
            cout << rating[p.first];
        }
        else
        {
            cout << "undefined";
        }

         cout << endl;
    }

   return 0;
}