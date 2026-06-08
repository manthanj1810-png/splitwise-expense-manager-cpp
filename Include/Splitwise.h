#ifndef SPLITWISE_H
#define SPLITWISE_H

#include <vector>
#include "Expense.h"

class Splitwise
{
private:
    vector<Expense> expenses;

public:
    void addExpense();
    void showExpenses();
};

#endif
