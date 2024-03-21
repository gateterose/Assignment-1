#!/bin/bash
echo "Enter Customer ID:"
read customerID

echo "Enter Customer Name:"
read customerName

echo "Enter Units Consumed:"
read unitsConsumed
if [ $unitsConsumed -lt 200 ]; then
    totalBill=$(( $unitsConsumed * 120 ))
elif [ $unitsConsumed -ge 200 ] && [ $unitsConsumed -lt 400 ]; then
    totalBill=$(( $unitsConsumed * 150 ))
elif [ $unitsConsumed -ge 400 ] && [ $unitsConsumed -lt 600 ]; then
    totalBill=$(( $unitsConsumed * 180 ))
else
    totalBill=$(( $unitsConsumed * 200 ))
fi
echo "Customer ID: $customerID"
echo "Customer Name: $customerName"
echo "Units Consumed: $unitsConsumed"
echo "Total Bill: Ksh $totalBill"
#Save the file and make it executable using the following command: chmod +x electricity_bill_calculator.sh
# Run the script using the following command: ./electricity_bill_calculator.sh
