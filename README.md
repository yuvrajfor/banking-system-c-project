# banking-system-c-project
Banking System in C using Binary File Handling and ATM features.
-----------------------------------------------------
              BANKING SYSTEM IN C
             (BINARY FILE HANDLING)
               Author: Yuvraj Singh
             Roll No: AP25110010259
-----------------------------------------------------

# 📌 PROJECT TITLE
## *Banking System in C (ATM + Binary File Handling)*

---

# 📘 PROJECT OVERVIEW

This mini–project is a complete *Banking Management System* written in C 
All account information is stored securely using a **binary file (bank.dat).

### The system includes:
- Account Creation  
- Secure ATM Login (Account Number + PIN)  
- PIN Verification before Withdrawal  
- Deposit Money  
- Withdraw Money  
- Check Balance  
- Change PIN  
- Admin Panel (Protected with Admin PIN = *9999*)  

Binary file handling ensures that all data is *permanent, secure, and efficient*.

---

# ⭐ FEATURES

## 🔹 USER / ATM FEATURES

### 1. Create Account  
- Enter Account Number, Name, PIN  
- Balance starts from 0  
- Data stored in bank.dat

### 2. ATM Login  
Requires:
- Account Number  
- PIN  

### 3. Check Balance  
Shows the current account balance.

### 4. Deposit Money  
- Adds the entered amount  
- Updates the binary file  

### 5. Withdraw Money  
- *PIN is verified again (added security layer)*  
- Checks for sufficient balance  
- Updates the file  

### 6. Change PIN  
Allows user to update their ATM PIN.

---

## 🔹 ADMIN FEATURES

Admin PIN → *9999*

Admin can:
- View all accounts  
- See Account Number, Name, PIN, Balance  
- Admin view is *PIN-protected*  

---

# 🛠 TECHNOLOGY USED

| Component      | Details                       |
|----------------|-------------------------------|
| Language       | C                             |
| Storage File   | Binary File (bank.dat)        |
| Compiler       | GCC / MinGW / Turbo C         |
| Platforms      | Windows / Linux / Mac         |

---

# 🔧 PROGRAM WORKING

## 📌 Structure Used (Account Model)
c
struct Account {
    int acc_no;
    char name[50];
    int pin;
    float balance;
};


## 📌 File Operations Used
- *fwrite()* → Write account data  
- *fread()* → Read account data  
- *fseek()* → Move to specific record  
- *ftell()* → Track file position  

### File Modes:
- ab  → Append (New Account)  
- rb  → Read Mode  
- rb+ → Read + Update Mode  

---

# 📁 PROJECT FILE STRUCTURE


BankingSystemProject/
│
├── banking_system.c
├── bank.dat
├── README.md
│
└── screenshots/
      ├── Home.png
      ├── Admin_login.png
      ├── Atm_login.png
      ├── Deposit_withdrawal.png
      ├── Pin_change.png
      └── Create_account.png


---

# ▶ HOW TO COMPILE & RUN

## Windows (GCC / MinGW)

gcc banking_system.c -o bank
bank.exe


## Linux / macOS

gcc banking_system.c -o bank
./bank


---

# 🖼 SCREENSHOTS

Screenshots included:
- Home  
- Admin Login  
- ATM Login  
- Deposit / Withdrawal  
- PIN Change  
- Create Account  

Located in: screenshots/ folder.

---

# 🚀 FUTURE IMPROVEMENTS

- Hide PIN input (**** masking)  
- Delete account feature  
- Transfer money between accounts  
- Transaction history  
- OTP verification  
- GUI version (Python/Java)  
- Encrypted PIN storage  

---

# 🔐 ADMIN PIN
Admin PIN to access all records:


9999


---

# 📌 IMPORTANT NOTES

- Ensure bank.dat is in the same folder as the executable.  
- Do *not* open bank.dat manually (it is a binary file).  
- File auto-creates if not found.  

---

# 📜 LICENSE
This project is created for *educational and academic purposes* to demonstrate the concepts of:
- C programming  
- File handling  
- Struct usage  
- Menu-driven system  
- ATM simulation  

---

# 🔚 END OF README
-----------------------------------------------------
