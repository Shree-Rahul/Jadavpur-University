#!/bin/bash

# Ask the user for the basic salary
echo "Enter the basic salary:"
read basic_salary

# Calculate the allowances as a percentage of the basic salary
house_rent=$(echo "scale=2; 0.25 * $basic_salary" | bc)
medical=$(echo "scale=2; 0.10 * $basic_salary" | bc)

# Calculate the gross salary
gross_salary=$(echo "$basic_salary + $house_rent + $medical" | bc)

# Calculate the income tax
if [ "$gross_salary" -gt 50000 ];
then
  tax=$(echo "scale=2; 0.20 * $gross_salary" | bc)
else
  tax=$(echo "scale=2; 0.15 * $gross_salary" | bc)
fi

# Calculate the net salary
net_salary=$(echo "$gross_salary - $tax" | bc)

# Print the salary slip
echo "Salary Slip"
echo "-----------"
echo "Basic Salary: $basic_salary"
echo "House Rent Allowance: $house_rent"
echo "Medical Allowance: $medical"
echo "Gross Salary: $gross_salary"
echo "Income Tax: $tax"
echo "Net Salary: $net_salary"
