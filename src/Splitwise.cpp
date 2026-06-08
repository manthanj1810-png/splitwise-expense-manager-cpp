#include "../include/Splitwise.h"
#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

void Splitwise::addExpense()
{
    Expense expense;

    int n;
    double share;

    cout << "Enter payer: ";
    cin >> expense.payer;

    cout << "Enter amount: ";
    cin >> expense.amount;

    cout << "Enter number of participants: ";
    cin >> n;
    share= expense.amount/n;
    balances[expense.payer]+= expense.amount;
    for(int i = 0; i < n; i++)
    {
        string name;

        cout << "Participant " << i + 1 << ": ";
        cin >> name;
        balances[name]-=share;
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
void Splitwise::showBalances()
{
    if(balances.empty())
    {
        cout << "No balances available.\n";
        return;
    }

    cout << "\nBalances:\n";

    for(auto &entry : balances)
    {
        cout << entry.first
             << " : "
             << entry.second
             << endl;
    }
}
void Splitwise::simplifyDebts()
{
    priority_queue<pair<double,string>> creditors;
    priority_queue<pair<double,string>> debtors;
    
    for(auto &entry : balances)
    {
        if(entry.second > 0)
        {
            creditors.push({entry.second, entry.first});
        }
        else if(entry.second < 0)
        {
            debtors.push({-entry.second, entry.first});
        }
    }
    while(!creditors.empty() &&
      !debtors.empty())
{
    auto creditor = creditors.top();
    creditors.pop();

    auto debtor = debtors.top();
    debtors.pop();

    double amount =
        min(creditor.first,
            debtor.first);
    
    Settlement s;
    s.debtor = debtor.second;
    s.creditor = creditor.second;
    s.amount = amount;
    
    settlements.push_back(s);

    cout << debtor.second
         << " pays "
         << creditor.second
         << " : "
         << amount
         << endl;

    double remainingCreditor =
        creditor.first - amount;

    double remainingDebtor =
        debtor.first - amount;

    if(remainingCreditor > 0)
    {
        creditors.push({
            remainingCreditor,
            creditor.second
        });
    }

    if(remainingDebtor > 0)
    {
        debtors.push({
            remainingDebtor,
            debtor.second
        });
    }
}
}
void Splitwise::showSettlements()
{
    if(settlements.empty())
    {
        cout << "No settlements generated.\n";
        return;
    }

    cout << "\nSettlement History\n";

    for(auto &s : settlements)
    {
        cout << s.debtor
             << " pays "
             << s.creditor
             << " : "
             << s.amount
             << endl;
    }
}
