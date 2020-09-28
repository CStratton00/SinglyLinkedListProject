//
// Collin Stratton
// This is my work
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList name;
    LinkedList abby;

    cout << "Is Empty: " << name.isEmpty() << endl;

    name.InsertFront(20);
    cout << "First: " << name.First() << endl;
    cout << "Last: " << name.Last() << endl;
    name.InsertFront(30);
    cout << "First: " << name.First() << endl;
    cout << "Last: " << name.Last() << endl;
    name.InsertFront(50);
    cout << "First: " << name.First() << endl;
    cout << "Last: " << name.Last() << endl;
    name.InsertEnd(10);
    cout << "First: " << name.First() << endl;
    cout << "Last: " << name.Last() << endl;

    abby.InsertFront(50);
    abby.InsertEnd(60);
    abby.InsertEnd(70);

    name.InsertPos(2, 40);
    name.display();
    cout << "Is Empty: " << name.isEmpty() << endl;

    name.ReverseList();
    name.display();

    name.RemoveFirst();
    name.display();
    name.RemoveLast();
    name.display();

    abby.display();

    name.Merge(abby);
    name.display();

    cout << "Size of List: " << name.Size() << endl;

    return 0;
}