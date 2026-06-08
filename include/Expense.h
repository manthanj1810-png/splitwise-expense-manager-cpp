#ifndef EXPENSE_H
#define EXPENSE_H
#include <string>
#include <vector>

using namespace std;

struct Expense
{
    string payer;
    double amount;
    vector<string> participants;
};

#endif
