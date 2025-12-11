#include <stdio.h>
#include <stdlib.h>

struct Account {
    int acc_no;
    char name[50];
    int pin;
    float balance;
};

FILE *fp;

/* Function declarations */
void createAccount();
void displayAll();
void atmLogin();
void checkBalance(int acc);
void deposit(int acc);
void withdraw(int acc);
void changePin(int acc);

int main() {
    int choice;

    while (1) {
        printf("\n======= BANKING SYSTEM =======");
        printf("\n1. Create Account");
        printf("\n2. ATM Login");
        printf("\n3. Display All Accounts (Admin)");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            createAccount();
        else if (choice == 2)
            atmLogin();
        else if (choice == 3)
            displayAll();
        else if (choice == 4)
            return 0;
        else
            printf("Invalid Choice!\n");
    }
}

/* ------------------ CREATE NEW ACCOUNT ------------------ */
void createAccount() {
    struct Account a;
    fp = fopen("bank.dat", "ab");

    if (fp == NULL) {
        printf("File Error!");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &a.acc_no);

    printf("Enter Name: ");
    scanf(" %[^\n]s", a.name);

    printf("Set ATM PIN: ");
    scanf("%d", &a.pin);

    a.balance = 0;

    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);

    printf("\nAccount Created Successfully!\n");
}
/* ------------------ DISPLAY ALL ACCOUNTS (Admin Only) ------------------ */
void displayAll() {
    int adminPin;
    struct Account a;

    printf("\nEnter Admin PIN to view all accounts: ");
    scanf("%d", &adminPin);

    if (adminPin != 9999) {
        printf("\nIncorrect Admin PIN! Access Denied.\n");
        return;
    }

    fp = fopen("bank.dat", "rb");

    if (fp == NULL) {
        printf("\nNo Accounts Found!\n");
        return;
    }

    printf("\n======= ACCOUNT LIST =======\n");

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        printf("\nAccount No : %d", a.acc_no);
        printf("\nName       : %s", a.name);
        printf("\nPIN        : %d", a.pin);
        printf("\nBalance    : %.2f\n", a.balance);
    }

    fclose(fp);
}


/* ------------------ ATM LOGIN ------------------ */
void atmLogin() {
    struct Account a;
    int acc, pin, found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &acc);
    printf("Enter PIN: ");
    scanf("%d", &pin);

    fp = fopen("bank.dat", "rb");
    if (fp == NULL) {
        printf("No Accounts Found!\n");
        return;
    }

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (a.acc_no == acc && a.pin == pin) {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (found == 0) {
        printf("\nInvalid Account or PIN!\n");
        return;
    }

    int choice;

    do {
        printf("\n======= ATM MENU =======");
        printf("\n1. Check Balance");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Change PIN");
        printf("\n5. Logout");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            checkBalance(acc);
        else if (choice == 2)
            deposit(acc);
        else if (choice == 3)
            withdraw(acc);
        else if (choice == 4)
            changePin(acc);
        else if (choice == 5)
            printf("\nLogging out...\n");
        else
            printf("\nInvalid Choice!\n");

    } while (choice != 5);
}

/* ------------------ CHECK BALANCE ------------------ */
void checkBalance(int acc) {
    struct Account a;
    fp = fopen("bank.dat", "rb");

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (a.acc_no == acc) {
            printf("\nYour Balance = %.2f\n", a.balance);
        }
    }
    fclose(fp);
}

/* ------------------ DEPOSIT MONEY ------------------ */
void deposit(int acc) {
    struct Account a;
    float amt;
    long pos;

    fp = fopen("bank.dat", "rb+");

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (a.acc_no == acc) {
            printf("\nEnter amount to deposit: ");
            scanf("%f", &amt);

            a.balance += amt;

            pos = ftell(fp) - sizeof(a);
            fseek(fp, pos, 0);
            fwrite(&a, sizeof(a), 1, fp);

            printf("\nAmount Deposited Successfully!\n");
            break;
        }
    }

    fclose(fp);
}
/* ------------------ WITHDRAW MONEY (PIN verification) ------------------ */
void withdraw(int acc) {
    struct Account a;
    float amt;
    long pos;
    int pinEnter;

    fp = fopen("bank.dat", "rb+");

    if (fp == NULL) {
        printf("\nFile Error!");
        return;
    }

    while (fread(&a, sizeof(a), 1, fp) == 1) {

        if (a.acc_no == acc) {

            /* PIN verification */
            printf("\nEnter PIN to continue withdrawal: ");
            scanf("%d", &pinEnter);

            if (pinEnter != a.pin) {
                printf("\nIncorrect PIN! Withdrawal cancelled.\n");
                fclose(fp);
                return;
            }

            printf("Enter amount to withdraw: ");
            scanf("%f", &amt);

            if (amt > a.balance) {
                printf("\nInsufficient Balance!\n");
            } else {
                a.balance -= amt;

                /* Move back and update the record */
                pos = ftell(fp) - sizeof(a);
                fseek(fp, pos, 0);
                fwrite(&a, sizeof(a), 1, fp);

                printf("\nWithdrawal Successful!");
                printf("\nRemaining Balance: %.2f\n", a.balance);
            }

            break;  // stop loop after found
        }
    }

    fclose(fp);
}

/* ------------------ CHANGE PIN ------------------ */
void changePin(int acc) {
    struct Account a;
    int newpin;
    long pos;

    fp = fopen("bank.dat", "rb+");

    while (fread(&a, sizeof(a), 1, fp) == 1) {
        if (a.acc_no == acc) {
            printf("\nEnter New PIN: ");
            scanf("%d", &newpin);

            a.pin = newpin;

            pos = ftell(fp) - sizeof(a);
            fseek(fp, pos, 0);
            fwrite(&a, sizeof(a), 1, fp);

            printf("\nPIN Changed Successfully!\n");
            break;
        }
    }

    fclose(fp);
}
