#include "../include/Splitwise.h"
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <fstream>

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
    saveData();
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

    if(creditors.empty() && debtors.empty())
    {
        cout << "No settlements required.\n";
        return;
    }

    cout << "\nSettlement Transactions:\n";

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

        // Save settlement history
        Settlement s;

        s.debtor = debtor.second;
        s.creditor = creditor.second;
        s.amount = amount;

        settlements.push_back(s);

        // Print transaction
        cout << debtor.second
             << " pays "
             << creditor.second
             << " : "
             << amount
             << endl;

        // Update balances
        balances[debtor.second] += amount;
        balances[creditor.second] -= amount;

        // Fix floating point noise
        if(abs(balances[debtor.second]) < 0.01)
            balances[debtor.second] = 0;

        if(abs(balances[creditor.second]) < 0.01)
            balances[creditor.second] = 0;

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

    cout << "\nAll debts settled successfully.\n";
}
void Splitwise::saveData()
{
    ofstream file("data.txt");

    for(auto &expense : expenses)
    {
        file << expense.payer << " ";
        file << expense.amount << " ";
        file << expense.participants.size() << " ";

        for(auto &person : expense.participants)
        {
            file << person << " ";
        }

        file << endl;
    }

    file.close();
}
void Splitwise::loadData()
{
    ifstream file("data.txt");

    if(!file.is_open())
    {
        return;
    }

    expenses.clear();
    balances.clear();

    string payer;
    double amount;
    int n;

    while(file >> payer >> amount >> n)
    {
        Expense expense;

        expense.payer = payer;
        expense.amount = amount;

        double share = amount / n;

        balances[payer] += amount;

        for(int i = 0; i < n; i++)
        {
            string participant;

            file >> participant;

            expense.participants.push_back(participant);

            balances[participant] -= share;
        }

        expenses.push_back(expense);
    }

    file.close();
}
