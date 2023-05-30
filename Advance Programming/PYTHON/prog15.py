class BankAccount:
    def __init__(self, account_number, pin):
        self.account_number = account_number
        self.pin = pin
        self.balance = 0

    def deposit(self, amount):
        self.balance += amount

    def withdraw(self, amount):
        if self.balance >= amount:
            self.balance -= amount
        else:
            print("Insufficient balance.")

    def get_balance(self):
        return self.balance

    def change_pin(self, new_pin):
        self.pin = new_pin


class SavingsAccount(BankAccount):
    def __init__(self, account_number, pin, interest_rate):
        super().__init__(account_number, pin)
        self.interest_rate = interest_rate

    def calculate_interest(self):
        interest = self.balance * self.interest_rate
        self.balance += interest


class FeeSavingsAccount(SavingsAccount):
    def __init__(self, account_number, pin, interest_rate, withdrawal_fee):
        super().__init__(account_number, pin, interest_rate)
        self.withdrawal_fee = withdrawal_fee

    def withdraw(self, amount):
        if self.balance >= amount + self.withdrawal_fee:
            self.balance -= (amount + self.withdrawal_fee)
        else:
            print("Insufficient balance.")



# ## Create a BankAccount
# account1 = BankAccount("123456789", "1234")
# account1.deposit(1000)
# print(account1.get_balance())  # Output: 1000

# account1.withdraw(500)
# print(account1.get_balance())  # Output: 500

# account1.change_pin("4321")

# #*Create a SavingsAccount
# savings_account = SavingsAccount("987654321", "5678", 0.05)
# savings_account.deposit(2000)
# print(savings_account.get_balance())  # Output: 2000

# savings_account.calculate_interest()
# print(savings_account.get_balance())  # Output: 2100 (after adding interest)

# # Create a FeeSavingsAccount
# fee_savings_account = FeeSavingsAccount("654321987", "9876", 0.03, 10)
# fee_savings_account.deposit(3000)
# print(fee_savings_account.get_balance())  # Output: 3000

# fee_savings_account.withdraw(500)
# print(fee_savings_account.get_balance())  # Output: 2490 (after deducting fee)#