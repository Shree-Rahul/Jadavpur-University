#!/bin/bash

echo "Please, Enter a username"
read username

if grep -q "^$username:" /etc/passwd
then
	echo "Found $username in /etc/passwd"

	info=$(grep "^$username:" /etc/passwd)

	IFS=':' read -ra fields <<< "$info"

	echo "User Information:"
	echo "Username:${fields[0]}"
	echo "Password:${fields[1]}"
	echo "User ID:${fields[2]}"
	echo "Group ID:${fields[3]}"
	echo "User ID info:${fields[4]}"
	echo "Home Directory:${fields[5]}"
	echo "Login Shell:${fields[6]}"
	

else
echo "Could not found $username in /etc/passwd"
fi
