#include <iostream>
#include "datamodel.h"

using namespace std;

int main()
{
    Product p(12, "apple", 28);
    cout << p.getDisplayName();

    Item fruit(p, 3);
    cout << fruit.getItemInfo();
    return 0;
}