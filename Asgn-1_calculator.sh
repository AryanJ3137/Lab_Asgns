#!/bin/bash

while true
do
    
    echo "1. add"
    echo "2. Sub"
    echo "3. Multiply"
    echo "4. Division"
    echo "5. Exit"
    

    read -p "Enter your choice: " choice

    case $choice in
        1)
            read -p "Enter first number: " a
            read -p "Enter second number: " b
            echo "Result = $((a + b))"
            ;;
        2)
            read -p "Enter first number: " a
            read -p "Enter second number: " b
            echo "Result = $((a - b))"
            ;;
        3)
            read -p "Enter first number: " a
            read -p "Enter second number: " b
            echo "Result = $((a * b))"
            ;;
        4)
            read -p "Enter first number: " a
            read -p "Enter second number: " b

            if [ $b -eq 0 ]; then
                echo "Error: Division by zero!"
            else
                echo "Result = $((a / b))"
            fi
            ;;
        5)
            echo "complete"
            exit 0
            ;;
        *)
            echo "Invalid choice!"
            ;;
    esac

    echo
done
