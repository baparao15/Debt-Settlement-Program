#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to represent a transaction between two people
struct Transaction {
    string from;   // Name of the person who owes money
    string to;     // Name of the person to be paid
    int amount;    // Amount owed
};

// Structure to hold net balance information
struct Balance {
    string person; // Name of the person
    int amount;    // Net balance (positive if they are owed, negative if they owe)
};

// Custom min-heap class to manage balances
class MinHeap {
    vector<Balance> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent].amount <= heap[index].amount) break;
            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left].amount < heap[smallest].amount)
                smallest = left;
            if (right < size && heap[right].amount < heap[smallest].amount)
                smallest = right;

            if (smallest == index) break;

            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

public:
    void push(Balance balance) {
        heap.push_back(balance);
        heapifyUp(heap.size() - 1);
    }

    Balance pop() {
        Balance minBalance = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minBalance;
    }

    bool empty() const {
        return heap.empty();
    }
};

void updateBalance(vector<Balance>& balances, const string& person, int amount) {
    for (auto& balance : balances) {
        if (balance.person == person) {
            balance.amount += amount;
            return;
        }
    }
    balances.push_back({person, amount});
}

void minimizeTransactions(vector<Transaction>& transactions) {
    vector<Balance> balances;

    for (const auto& transaction : transactions) {
        updateBalance(balances, transaction.from, -transaction.amount);
        updateBalance(balances, transaction.to, transaction.amount);
    }

    MinHeap debit, credit;

    for (const auto& balance : balances) {
        if (balance.amount < 0) {
            debit.push({balance.person, -balance.amount});
        } else if (balance.amount > 0) {
            credit.push({balance.person, balance.amount});
        }
    }

    int transactionCount = 0;

    while (!debit.empty() && !credit.empty()) {
        Balance debtor = debit.pop();
        Balance creditor = credit.pop();

        int settlementAmount = min(debtor.amount, creditor.amount);

        cout << debtor.person << " will pay " << settlementAmount << " to " << creditor.person << endl;

        debtor.amount -= settlementAmount;
        creditor.amount -= settlementAmount;

        if (debtor.amount > 0) debit.push(debtor);
        if (creditor.amount > 0) credit.push(creditor);

        transactionCount++;
    }

    cout << "\nTotal transactions minimized to: " << transactionCount << endl;
}

int main() {
    int numTransactions;

    cout << "Welcome to the Debt Settlement Program!\n";
    cout << "This program helps minimize the number of transactions needed to settle debts.\n\n";

    cout << "Please enter the number of transactions: ";
    cin >> numTransactions;
    cin.ignore(); // Ignore newline after number input

    vector<Transaction> transactions(numTransactions);

    for (int i = 0; i < numTransactions; ++i) {
        cout << "\nTransaction " << i + 1 << ":\n";
        
        cout << "Enter the name of the person who owes money: ";
        getline(cin, transactions[i].from);
        
        cout << "Enter the name of the person to be paid: ";
        getline(cin, transactions[i].to);
        
        cout << "Enter the amount owed: ";
        cin >> transactions[i].amount;
        cin.ignore(); // Ignore newline after amount
    }

    cout << "\nProcessing transactions to minimize the number of payments needed...\n\n";
    minimizeTransactions(transactions);

    return 0;
}
