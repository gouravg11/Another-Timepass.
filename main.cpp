#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> v = {-1,38,-1,14,-1,-1,-1,-1,31,-1,-1,-1,-1,-1,-1,-1,7,-1,-1,-1,42,-1,-1,-1,-1,-1,-1,84,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
                 -1,-1,-1,-1,-1,-1,-1,-1,-1,67,-1,-1,34,-1,-1,-1,-1,-1,-1,-1,19,-1,60,-1,-1,-1,-1,-1,-1,-1,91,-1,-1,-1,-1,-1,-1,-1,99,-1,-1,
                 -1,-1,-1,-1,36,-1,-1,-1,-1,-1,73,-1,75,-1,-1,79,-1,-1};

void Play()
{
    srand(time(0));
    cout << "Snake and Ladders" << endl;
    cout << "Press 1 to Start the Game : " << endl;
    cout << "For Exit Press 0 :" << endl;
    int start;
    cin >> start;

    if(start == 0)
        return;

    string name1, name2;
    cout << "Player 1 name : ";
    cin >> name1;
    cout << "Player 2 name : ";
    cin >> name2;
    cout << endl;

    int n = 1, m = 1;

    cout << "To roll a dice, Press 1" << endl;
    int temp = 0;

    while(true)
    {
        cout << "Current Status : " << endl << name1 << " is at " << n << " And " << name2 << " is at " << m << endl;

        cout << endl;
        cout << name1 << "'s move : ";
        cin >> temp;
        int dice = (rand() % 150 + rand() % 800) % 6 + 1;
        bool movee = true;
        cout << "You got " << dice << " on dice" << endl;

        if(n + dice > 100)
        {
            cout << "You can only move atmost " << 100 - n << " moves." << endl;
            n -= dice;
            movee = false;
        }

        n += dice;

        if(n == 100)
        {
            cout << "Congratulations! " << name1 << " is win the game " << endl;
            return;
        }
        bool flag = true;


        while(movee && n < 100 && v[n] != -1)
        {
            flag = false;
            if(v[n] > n)
            {
                cout << "Hurray! you got a Ladder, And you moved to " << v[n] << endl;
            }
            else
            {
                cout << "Oops! The snake is bitten you. And you moved to " << v[n] << endl;
            }
            n = v[n];
        }

        if(n == 100)
        {
            cout << "Congratulations! " << name1 << " is win the game " << endl;
            return;
        }

        if(flag && movee)
            cout << "You moved to " << n << endl;

        cout << endl;
        cout << name2 << "'s move : ";
        cin >> temp;

        dice = (rand() % 500 + rand() % 300) % 6 + 1;
        cout << "You got " << dice << " on dice" << endl;
        movee = true;

        if(m + dice > 100)
        {
            cout << "You can only move atmost " << 100 - m << " moves." << endl;
            m -= dice;
            movee = false;
        }

        m += dice;

        if(m == 100)
        {
            cout << "Congratulations " << name2 << " is win the game " << endl;
            return;
        }
        flag = true;

        while(movee && m < 100 && v[m] != -1)
        {
            flag = false;
            if(v[m] > m)
            {
                cout << "Hurray! you got a Ladder, And you moved to " << v[m] << endl;
            }
            else
            {
                cout << "Oops! The snake is bitten you. And you moved to " << v[m] << endl;
            }
            m = v[m];
        }
        if(m == 100)
        {
            cout << "Congratulations " << name2 << " is win the game " << endl;
            return;
        }
        if(flag && movee)
            cout << "You moved to " << m << endl;

        cout << endl;
    }
}
int32_t main()
{
    cout << "Hi! Do you want to define your Snakes and Ladders positions (for this Press 1), or are you okay with the predefined positions (for this Press 0)? " << endl;
    int check;
    cin >> check;

    if(check == 0)
    {
        cout << "Let's Start the Game -> ";
        Play();
    }
    else
    {
        cout << "How many snakes is present ? ";
        int snake;
        cin >> snake;

        cout << "Write from which position Snake is start and end" << endl;
        for(int i = 0; i < snake; i++)
        {
            int x, y;
            cin >> x >> y;

            v[x] = y;
        }

        cout << "How many Ladders is present ?" << endl;
        int ladders;
        cin >> ladders;

        cout << "Write from which position Ladder is start and end" << endl;

        for(int i = 0; i < ladders; i++)
        {
            int x, y;
            cin >> x >> y;

            v[x] = y;
        }

        cout << "Let's Start the Game" << endl;
        Play();
    }
}
