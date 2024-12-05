
# 💳 Debt Settlement Program  

This program is designed to **minimize the number of transactions** required to settle debts among a group of people. By using **custom heap structures** and efficient algorithms, the program ensures that all debts are resolved with the fewest possible payments.

---

## 🚀 Features  
- Calculates net balances for each person involved in the transactions.  
- Minimizes the number of payments using **custom Min-Heap data structures**.  
- Provides a clear and user-friendly console output showing who needs to pay whom and how much.  
- Offers an efficient and scalable solution for debt reconciliation.  

---

## 🛠️ Technologies Used  
- **Language**: C++  
- **Libraries**:  
  - `<iostream>`: For input and output operations.  
  - `<vector>`: To store and manage lists of transactions and balances.  
  - `<string>`: For handling user input and names.  
  - `<algorithm>`: To perform operations like finding the minimum.  

---

## 📋 How It Works  
1. **Input**:  
   - The user provides the number of transactions and details for each transaction (who owes, to whom, and how much).  

2. **Net Balances**:  
   - The program calculates the net balance for each individual (positive if they are owed, negative if they owe).  

3. **Optimization**:  
   - A **Min-Heap** is used to prioritize the smallest debts, ensuring efficient settlement.  
   - Transactions are minimized by matching creditors and debtors to settle balances efficiently.  

4. **Output**:  
   - A list of minimized transactions showing who pays whom and the total number of transactions required.  

---

## 🎯 Example Output  
```
Welcome to the Debt Settlement Program!
This program helps minimize the number of transactions needed to settle debts.

Please enter the number of transactions: 3

Transaction 1:
Enter the name of the person who owes money: Alice
Enter the name of the person to be paid: Bob
Enter the amount owed: 50

Transaction 2:
Enter the name of the person who owes money: Bob
Enter the name of the person to be paid: Charlie
Enter the amount owed: 30

Transaction 3:
Enter the name of the person who owes money: Alice
Enter the name of the person to be paid: Charlie
Enter the amount owed: 20

Processing transactions to minimize the number of payments needed...

Alice will pay 50 to Charlie
Bob will pay 30 to Charlie

Total transactions minimized to: 2
```

---

## 🧑‍💻 Usage Instructions  
1. Clone this repository or copy the code to your local environment.  
2. Compile the program using any C++ compiler, such as:  
   ```bash
   g++ -o DebtSettlement DebtSettlement.cpp
   ```  
3. Run the compiled program:  
   ```bash
   ./DebtSettlement
   ```  
4. Follow the on-screen instructions to input transaction details.  

---

## 📂 File Structure  
- **`source code.cpp`**: Contains the main code for the program.  
- No external dependencies are required; everything is handled in a single file.  

---

## 🛡️ Advantages of the Program  
- Reduces unnecessary transactions, saving time and effort.  
- Handles edge cases like multiple creditors or debtors efficiently.  
- Uses **Min-Heap**, ensuring optimal performance for large datasets.  

---

## 🚀 Future Enhancements  
- Add file input/output support for batch processing of transactions.  
- Implement a graphical user interface (GUI) for better user experience.  
- Extend the program to handle multi-currency settlements.  

---

## 🤝 Contributing  
Contributions are welcome! Feel free to fork this repository and submit pull requests with improvements or new features.  

---


### ⭐ If you find this program helpful, please consider starring this repository!  

