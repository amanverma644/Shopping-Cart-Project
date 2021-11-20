#include <iostream>
#include <vector>
#include "datamodel.h"

using namespace std;

vector<Product> allProducts = {
    Product(1, "apple", 26),
    Product(3, "mango", 16),
    Product(2, "guava", 36),
    Product(5, "banana", 56),
    Product(4, "strawberry", 29),
    Product(6, "pineapple", 20),
};

Product *chooseProduct()
{
    //Display the list of products
    string productLists;
    cout << "Available Products" << endl;

    for (auto product : allProducts)
    {
        productLists.append(product.getDisplayName());
    }
    cout << productLists << endl;

    cout << "------------------" << endl;
    string choice;
    cin >> choice;

    for (int i = 0; i < allProducts.size(); i++)
    {
        if (choice == allProducts[i].getShortName())
        {
            return &allProducts[i];
        }
    }

    cout << "Product Not Found!" << endl;
    return NULL;
}

bool checkout(Cart &cart)
{
    if (cart.isEmpty())
    {
        return false;
    }

    int total = cart.getTotal();

    cout << "Pay in Cash: ";
    int paid;
    cin >> paid;

    if (paid >= total)
    {
        cout << "Change " << paid - total << endl;
        cout << "Thank you for Shopping!";
        return true;
    }
    else
    {
        cout << "Not enough Cash";
        return false;
    }
}

int main()
{
    char action;
    Cart cart;
    while (true)
    {
        cout << "Select an action -  (a)dd item, (v)iew cart, (c)heckout" << endl;
        cin >> action;
        if (action == 'a')
        {
            //ToDo Add to Cart
            //View All Products + Choose Product + Add to Cart
            Product *product = chooseProduct();
            if (product != NULL)
            {
                cout << "Added to Cart " << product->getDisplayName() << endl;
                cart.addProduct(*product);
            }
        }
        else if (action == 'v')
        {
            //View the cart
            cout << "----------------------" << endl;
            cout << cart.viewCart();
            cout << "----------------------" << endl;
        }
        else if (action == 'c')
        {
            //Checkout
            if (checkout(cart))
            {
                break;
            }
        }
    }
    return 0;
}