#include <iostream>
#include "../include/Splitwise.h"

using namespace std;

int main()
{
    Splitwise app;

    int choice;

    do
    {
        cout << "\n===== Splitwise Expense Manager =====\n";

        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                app.addExpense();
                break;

            case 2:
                app.showExpenses();
                break;

            case 3:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 3);

    return 0;
}
