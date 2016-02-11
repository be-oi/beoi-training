#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;
    list<int>::iterator it;

    l.push_back(3);
    it = l.begin();  // points to 3
    l.push_back(4);
    l.push_front(1);
    l.insert(it, 2); // inserts before 3
    
    for (it = l.begin(); it != l.end(); it++)
        cout << *it << endl;
}
