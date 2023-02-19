#include <stdio.h>
#include <cs50.h>
#include <math.h>

int get_digits_count(long number);
int get_digit(long number, int n);
bool is_valid_amex(long number);
bool is_valid_mastercard(long number);
bool is_valid_visa(long number);

int main(void)
{
    // Prompt user for credit card number
    long number = get_long("Number: ");

    // Determine the type of the credit card
    if (is_valid_amex(number))
    {
        printf("AMEX\n");
    }
    else if (is_valid_mastercard(number))
    {
        printf("MASTERCARD\n");
    }
    else if (is_valid_visa(number))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

// Returns the number of digits in a number
int get_digits_count(long number)
{
    int count = 0;
    while (number != 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

// Returns the nth digit of a number
int get_digit(long number, int n)
{
    for (int i = 0; i < n; i++)
    {
        number /= 10;
    }
    return number % 10;
}

// Returns true if the credit card number is a valid American Express number
bool is_valid_amex(long number)
{
    int digits_count = get_digits_count(number);

    // Check that the number has the correct number of digits
    if (digits_count != 15)
    {
        return false;
    }

    // Check that the first two digits are 34 or 37
    int first_two_digits = number / 10000000000000;
    if (first_two_digits != 34 && first_two_digits != 37)
    {
        return false;
    }

    // Check the card number using Luhn's algorithm
    int sum = 0;
    for (int i = 0; i < digits_count; i++)
    {
        int digit = get_digit(number, i);
        if (i % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            digit *= 2;
            sum += digit / 10 + digit % 10;
        }
    }
    return sum % 10 == 0;
}

// Returns true if the credit card number is a valid MasterCard number
bool is_valid_mastercard(long number)
{
    int digits_count = get_digits_count(number);

    // Check that the number has the correct number of digits
    if (digits_count != 16)
    {
        return false;
    }

    // Check that the first two digits are in the range 51-55
    int first_two_digits = number / 100000000000000;
    if (first_two_digits < 51 || first_two_digits > 55)
    {
        return false;
    }

    // Check the card number using Luhn's algorithm
    int sum = 0;
    for (int i = 0; i < digits_count; i++)
    {
        int digit = get_digit(number, i);
        if (i % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            digit *= 2;
            sum += digit / 10 + digit % 10;
        }
    }
    return sum % 10 == 0;
}

// Returns true if the credit card number is a valid Visa number
bool is_valid_visa(long number)
{
    // Check number length
    int len = 0;
    long temp = number;
    while (temp > 0)
    {
        temp /= 10;
        len++;
    }
    if (len != 13 && len != 16)
    {
        return false;
    }

    // Check starting digit
    int start_digit = number / pow(10, len - 1);
    if (start_digit != 4)
    {
        return false;
    }

    // Calculate checksum
    int sum = 0;
    int digit = 0;
    for (int i = 1; i <= len; i++)
    {
        if (i % 2 == 0)
        {
            digit = ((number / (int) pow(10, i - 1)) % 10) * 2;
            sum += digit / 10 + digit % 10;
        }
        else
        {
            sum += (number / (int) pow(10, i - 1)) % 10;
        }
    }
    if (sum % 10 != 0)
    {
        return false;
    }

    return true;
}
