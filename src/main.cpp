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
        cout << "4. Generate Settlement Plan\n";
        cout << "5. Execute Settlements\n";
        cout << "6. Show Settlements history\n";
        cout << "7. Exit\n";

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
                app.generateSettlementPlan();
                break;
            
            case 5:
                app.executeSettlements();
                break;
            
            case 6:
                app.showSettlement();
                break;
            
            case 7:
                cout << "Goodbye!\n";
                break;
            
            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 7);

    return 0;
}
