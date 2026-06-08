#ifndef SPLITWISE_H
#define SPLITWISE_H

#include <vector>
#include "Expense.h"
#include <unordered_map>

class Splitwise
{
private:
    vector<Expense> expenses;
    unordered_map<string,double> balances;
public:
    void addExpense();
    void showExpenses();
    void showBalances();
    void simplifyDebts();
};

#endif
