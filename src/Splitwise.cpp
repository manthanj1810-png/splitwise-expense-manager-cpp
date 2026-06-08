#include "../include/Splitwise.h"
#include <iostream>

using namespace std;

void Splitwise::addExpense()
{
    Expense expense;

    int n;

    cout << "Enter payer: ";
    cin >> expense.payer;

    cout << "Enter amount: ";
    cin >> expense.amount;

    cout << "Enter number of participants: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string name;

        cout << "Participant " << i + 1 << ": ";
        cin >> name;

        expense.participants.push_back(name);
    }

    expenses.push_back(expense);

    cout << "Expense added successfully!\n";
}

void Splitwise::showExpenses()
{
    if(expenses.empty())
    {
        cout << "No expenses found.\n";
        return;
    }

    for(int i = 0; i < expenses.size(); i++)
    {
        cout << "\nExpense " << i + 1 << endl;

        cout << "Payer: "
             << expenses[i].payer
             << endl;

        cout << "Amount: "
             << expenses[i].amount
             << endl;

        cout << "Participants: ";

        for(string person : expenses[i].participants)
        {
            cout << person << " ";
        }

        cout << endl;
    }
}
