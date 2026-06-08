#ifndef SPLITWISE_H
#define SPLITWISE_H

#include <vector>
#include "Expense.h"
#include "Settlement.h"
#include <unordered_map>

class Splitwise
{
private:
    vector<Expense> expenses;
    unordered_map<string,double> balances;
    vector<Settlement> settlements;
    
public:
    void addExpense();
    void showExpenses();
    void showBalances();
    void simplifyDebts();
};

#endif
