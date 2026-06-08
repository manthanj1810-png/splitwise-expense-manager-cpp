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
        cout << "3. Show balances\n";
        cout << "4. Exit\n";

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
                app.showBalances();
                break;

            case 4:
                cout << "Goodbye!\n";
                break;
            
            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}
