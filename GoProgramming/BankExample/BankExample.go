package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define type alias for convenience
type Scanner = *bufio.Scanner

// Define structures
type Customer struct {
	Name     string
	Age      int
	Accounts []Account
}

type Account struct {
	AccountNumber int
	Balance       float32
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	display(scanner)
}

func display(scanner Scanner) {
	var currentCustomer *Customer = nil

	for {
		fmt.Println()
		fmt.Println("------------------------------------------------------")
		fmt.Println("Welcome to the bank, please select an option below: ")
		fmt.Println("0. Exit")
		fmt.Println("1. Create a new user account")
		fmt.Println("2. Create a new bank account")
		fmt.Println("3. Deposit money into a bank account")
		fmt.Println("4. Withdraw money from a bank account")
		fmt.Println("------------------------------------------------------")
		fmt.Println()

		// Handle user choice
		fmt.Print("Choice: \t")
		scanner.Scan()
		choice, err := strconv.Atoi(scanner.Text())
		if err != nil {
			fmt.Println("Error: ", err.Error())
		}

		if choice == 0 {
			fmt.Println()
			fmt.Println("Thank you for using the bank, goodbye!")
			return
		} else if choice == 1 {
			currentCustomer = createCustomer(scanner)
		} else if choice == 2 {
			if currentCustomer == nil {
				fmt.Println()
				fmt.Println("No existing user account found. Please create a new user account first.")
				continue
			}
			currentCustomer.Accounts = append(currentCustomer.Accounts, createAccount(scanner))
		} else if choice == 3 {
			fmt.Println()
			if currentCustomer == nil {
				fmt.Println("No existing user account found. Please create a new user account first.")
				continue
			}

			fmt.Println("Select user account from the list below: ")
			displayAccounts(currentCustomer.Accounts)
			fmt.Println()

			fmt.Print("Choice: \t")
			scanner.Scan()
			accountNumber, err := strconv.Atoi(scanner.Text())
			if err != nil {
				fmt.Println("Error: ", err.Error())
			}

			deposit(scanner, getAccount(accountNumber, currentCustomer.Accounts))
		} else if choice == 4 {
			fmt.Println()
			if currentCustomer == nil {
				fmt.Println("No existing user account found. Please create a new user account first.")
				continue
			}

			fmt.Println("Select user account from the list below: ")
			displayAccounts(currentCustomer.Accounts)
			fmt.Println()

			fmt.Print("Choice: \t")
			scanner.Scan()
			accountNumber, err := strconv.Atoi(scanner.Text())
			if err != nil {
				fmt.Println("Error: ", err.Error())
			}

			withdraw(scanner, getAccount(accountNumber, currentCustomer.Accounts))
		} else {
			fmt.Println()
			fmt.Println("Invalid choice, please try again.")
		}
	}
}

func createCustomer(scanner Scanner) *Customer {
	var account []Account

	fmt.Println()
	fmt.Println("------------------------------------------------------")

	fmt.Println("Please enter your name: ")
	scanner.Scan()
	name := scanner.Text()
	fmt.Println()

	fmt.Println("Please enter your age: ")
	scanner.Scan()
	age, err := strconv.Atoi(scanner.Text())
	if err != nil {
		fmt.Println("Error: ", err.Error())
	}

	account = append(account, createAccount(scanner))
	fmt.Println()

	return &Customer{name, age, account}
}

func createAccount(scanner Scanner) Account {
	fmt.Println()
	fmt.Println("------------------------------------------------------")

	fmt.Println("Please enter your account number: ")
	scanner.Scan()
	fmt.Println()
	accountNumber, err := strconv.Atoi(scanner.Text())
	if err != nil {
		fmt.Println("Error: ", err.Error())
	}

	fmt.Println("Please enter your starting balance: ")
	scanner.Scan()
	balance, err := strconv.ParseFloat(scanner.Text(), 32)
	if err != nil {
		fmt.Println("Error: ", err.Error())
	}

	fmt.Println("------------------------------------------------------")
	fmt.Println()

	fmt.Println("Account number: ", accountNumber, "Successfully created!")
	return Account{accountNumber, float32(balance)}
}

func deposit(scanner Scanner, account *Account) {

	if account == nil {
		fmt.Println("Cannot deposit, account not found.")
		return
	}

	fmt.Println()
	fmt.Println("------------------------------------------------------")

	fmt.Println("Please enter the amount you wish to deposit: ")
	scanner.Scan()
	fmt.Println()
	amount, err := strconv.ParseFloat(scanner.Text(), 32)
	if err != nil {
		fmt.Println("Error: ", err.Error())
	}

	fmt.Println("------------------------------------------------------")
	fmt.Println()

	account.Balance += float32(amount)
	fmt.Println("New balance: ", account.Balance)
}

func withdraw(scanner Scanner, account *Account) {

	if account == nil {
		fmt.Println("Cannot withdraw, account not found.")
		return
	}

	fmt.Println()
	fmt.Println("------------------------------------------------------")

	fmt.Println("Please enter the amount you wish to withdraw: ")
	scanner.Scan()
	fmt.Println()
	amount, err := strconv.ParseFloat(scanner.Text(), 32)
	if err != nil {
		fmt.Println("Error: ", err.Error())
	}

	fmt.Println("------------------------------------------------------")
	fmt.Println()

	account.Balance -= float32(amount)
	fmt.Println("New balance: ", account.Balance)
}

func displayAccounts(accounts []Account) {
	for _, account := range accounts {
		fmt.Println("Account number: ", account.AccountNumber, "\tBalance: ", account.Balance)
	}
}

func getAccount(accountNumber int, accounts []Account) *Account {
	var result *Account = nil
	for _, account := range accounts {
		if account.AccountNumber == accountNumber {
			result = &account
		}
	}

	// Check if account is not found
	if result == nil {
		return nil
	}
	return result
}
