import java.util.ArrayList;
public class prog1{
    public class Customer {
        private int customerId;
        private String name;
        private double currentLoanAmount;
        private String phoneNumber;
        private boolean privileged;
        private static final double creditLimit = 10000; 
        private static final double privilegedCreditLimit = 20000; 
    
        public Customer(int customerId, String name, double currentLoanAmount, String phoneNumber, boolean privileged) {
            this.customerId = customerId;
            this.name = name;
            this.currentLoanAmount = currentLoanAmount;
            this.phoneNumber = phoneNumber;
            this.privileged = privileged;
        }
    
        // Getter and setter methods for all attributes
    
        public int getCustomerId() {
            return customerId;
        }
    
        public void setCustomerId(int customerId) {
            this.customerId = customerId;
        }
    
        public String getName() {
            return name;
        }
    
        public void setName(String name) {
            this.name = name;
        }
    
        public double getCurrentLoanAmount() {
            return currentLoanAmount;
        }
    
        public void setCurrentLoanAmount(double currentLoanAmount) {
            this.currentLoanAmount = currentLoanAmount;
        }
    
        public String getPhoneNumber() {
            return phoneNumber;
        }
    
        public void setPhoneNumber(String phoneNumber) {
            this.phoneNumber = phoneNumber;
        }
    
        public boolean isPrivileged() {
            return privileged;
        }
    
        public void setPrivileged(boolean privileged) {
            this.privileged = privileged;
        }
    
        // Method to request a loan
        public boolean requestLoan(double amount) {
            double totalLoanAmount = currentLoanAmount + amount;
            double availableCreditLimit = privileged ? privilegedCreditLimit : creditLimit;
    
            if (totalLoanAmount <= availableCreditLimit) {
                currentLoanAmount = totalLoanAmount;
                return true;
            } else {
                return false;
            }
        }
    
        // Method to get the credit limit
        public double getCreditLimit() {
            return privileged ? privilegedCreditLimit : creditLimit;
        }
    }
    

    public class Bank {
        private ArrayList<Customer> customers;

        public Bank() {
            customers = new ArrayList<>();
        }

        // Method to add a customer to the bank
        public void addCustomer(Customer customer) {
            customers.add(customer);
        }

        // Method to find a customer by their customerId
        public Customer findCustomer(int customerId) {
            for (Customer customer : customers) {
                if (customer.getCustomerId() == customerId) {
                    return customer;
                }
            }
            return null; // Customer not found
        }
    }

    
    public static void main(String[] args) {
        // Create instances of customers
        Customer customer1 = new Customer(1, "John Doe", 5000, "1234567890", false);
        Customer customer2 = new Customer(2, "Jane Smith", 10000, "9876543210", true);

        // Request a loan for customers
        boolean loanGranted1 = customer1.requestLoan(3000);
        boolean loanGranted2 = customer2.requestLoan(15000);

        // Print loan status
        System.out.println("Loan granted for customer1: " + loanGranted1);
        System.out.println("Loan granted for customer2: " + loanGranted2);

        // Print customer information
        System.out.println("Customer 1:");
        System.out.println("Name: " + customer1.getName());
        System.out.println("Current Loan Amount: " + customer1.getCurrentLoanAmount());
        System.out.println("Credit Limit: " + customer1.getCreditLimit());

        System.out.println("Customer 2:");
        System.out.println("Name: " + customer2.getName());
        System.out.println("Current Loan Amount: " + customer2.getCurrentLoanAmount());
        System.out.println("Credit Limit: " + customer2.getCreditLimit());
    }
    

}