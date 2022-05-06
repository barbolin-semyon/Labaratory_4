#include <iostream>
#include <ctime>
#include <utility>
#include <vector>
#include <algorithm>
#include <list>
#include <set>

int sizeContainers = 100000;

int myRand() {
    return rand();
}

using namespace std;

template <typename Container>
void fillRandom(Container &cont, int n)
{
    for (int i = 0, r; i < n; i++)
    {
        r = myRand();
        cont.insert(cont.end(), r);
    }
}

template<typename Container>
void print(Container container) {
    typename Container::iterator iterator = container.begin();
    while (iterator != container.end())
    {
        cout << *iterator << " ";
        ++iterator;
    }
    cout << endl;
}

void workWithVector() {
    cout << "vector:" << endl << "------------" << endl;

    long start = clock();

    vector<int> vec;
    fillRandom(vec, sizeContainers);
    sort(vec.begin(), vec.end(), [](unsigned f, unsigned s) -> bool {return f < s;});

    int i = myRand();
    vec.insert(upper_bound(vec.begin(), vec.end(), i), i);

    long end = clock();

    cout << "Время: " << end - start << endl;
    //print(vec);
}

void workWithList() {
    cout << "list:" << endl << "------------" << endl;

    long start = clock();

    list<int> list;
    fillRandom(list, sizeContainers);
    list.sort();

    int i = myRand();
    list.insert(upper_bound(list.begin(), list.end(), i), i);

    long end = clock();

    cout << "Время: " << end - start << endl;
    //print(list);
}

void workWithMultiset() {
    cout << "multiSet:" << endl << "------------" << endl;

    long start = clock();

    multiset<int> setik;
    fillRandom(setik, sizeContainers);
    int i = myRand();
    setik.insert( i);

    long end = clock();

    cout << "Время: " << end - start << endl;
    //print(setik);
}

int main() {
    srand (time(NULL));
    system("chcp 65001");

    workWithVector();
    cout << endl;
    workWithList();
    cout << endl;
    workWithMultiset();

    return 0;
}
