#include <algorithm>
#include <cmath>
#include <climits>

#include "../headers/BigNumber.h"

namespace BigNums 
{

    BigNumber::BigNumber()
    {
        this->numberValue.push_back('0');
    }

    BigNumber::BigNumber(char number)
    {
        this->numberValue.push_back(number);
    }

    BigNumber::BigNumber(unsigned char number)
    {
        this->numberValue.push_back(number);
    }

    BigNumber::BigNumber(const char *number)
    {
        std::string numberValueString = std::string(number);
        this->numberValue = std::vector<char>(numberValueString.begin(), numberValueString.end());
    }

    BigNumber::BigNumber(std::string number)
    {
        this->numberValue = std::vector<char>(number.begin(), number.end());
    }

    BigNumber::BigNumber(short number)
    {
        std::string numberValueString = std::to_string(number);
        this->numberValue = std::vector<char>(numberValueString.begin(), numberValueString.end());
    }

    BigNumber::BigNumber(unsigned short number)
    {
        std::string numberValueString = std::to_string(number);
        this->numberValue = std::vector<char>(numberValueString.begin(), numberValueString.end());
    }

    BigNumber::BigNumber(int number)
    {
        std::string numberValueString = std::to_string(number);
        this->numberValue = std::vector<char>(numberValueString.begin(), numberValueString.end());
    }

    BigNumber::BigNumber(unsigned int number)
    {
        std::string numberValueString = std::to_string(number);
        this->numberValue = std::vector<char>(numberValueString.begin(), numberValueString.end());
    }

    BigNumber::BigNumber(long long number)
    {
        std::string numberValueString = std::to_string(number);
        this->numberValue = std::vector<char>(numberValueString.begin(), numberValueString.end());
    }

    BigNumber::BigNumber(unsigned long long number)
    {
        std::string numberValueString = std::to_string(number);
        this->numberValue = std::vector<char>(numberValueString.begin(), numberValueString.end());
    }

    BigNumber::BigNumber(float number)
    {
        std::string numberValueString = std::to_string((long long)roundf(number));
        this->numberValue = std::vector<char>(numberValueString.begin(), numberValueString.end());
    }

    BigNumber::BigNumber(double number)
    {
        std::string numberValueString = std::to_string((long long)round(number));
        this->numberValue = std::vector<char>(numberValueString.begin(), numberValueString.end());
    }

    BigNumber::BigNumber(long double number)
    {
        std::string numberValueString = std::to_string((long long)roundl(number));
        this->numberValue = std::vector<char>(numberValueString.begin(), numberValueString.end());
    }

    BigNumber::BigNumber(const std::vector<char> &number)
    {
        this->numberValue = number;
    }

    BigNumber::BigNumber(BigNumber const &number)
    {
        this->numberValue = number.numberValue;
    }

    BigNumber BigNumber::Add(const BigNumber& _addend)
    {
        BigNumber largerNum = _addend > *this ? _addend : *this;
        BigNumber smallerNum = _addend > *this ? *this : _addend;

        //This block handles addition if any of the numbers are a negative value
        if (largerNum.IsNegative() || smallerNum.IsNegative())
        {
            if (largerNum.IsNegative() && smallerNum.IsNegative())
            {
                largerNum.Negate();
                smallerNum.Negate();

                BigNumber sum = largerNum.Add(smallerNum);
                sum.Negate();

                return sum;
            }
            else if (largerNum.IsNegative() && smallerNum.IsPositive())
            {
                largerNum.Negate();

                BigNumber sum = largerNum.Subtract(smallerNum);
                sum.Negate();

                return sum;
            }
            else
            {
                smallerNum.Negate();

                BigNumber sum = smallerNum.Subtract(largerNum);
                sum.Negate();

                return sum;
            }
        }

        std::vector<char> sumValue;
        int carry = 0;
        long long int diff = largerNum.numberValue.size() - smallerNum.numberValue.size();
        for (long long int i = 0; i < diff; ++i) //Add zeros to smaller number until it is same size as larger number
        {
            smallerNum.numberValue.insert(smallerNum.numberValue.begin(), '0');
        }

        //traverse through both numbers by digit
        for (long long int i = largerNum.numberValue.size() - 1 ; i >= 0; --i)
        {
            int addend1 = largerNum.numberValue[i] - '0';
            int addend2 = smallerNum.numberValue[i] - '0';

            int sum = addend1 + addend2 + carry; //Add up the current digit of each number 
            std::string sumStr; //String used to avoid char addition overflow

            carry = 0;
            if (sum <= 9 || i == 0) //Adds the sum directly to the vector if less than 10 or if it is the first digit in the number
            {
                sumStr = std::to_string(sum);
                sumValue.insert(sumValue.begin(), sumStr.begin(), sumStr.end());
            }
            else //Adds the remainder of the sum divided by 10 to the vector if sum is greater than 10 and not the first digit 
            {
                sumStr = std::to_string(sum % 10);
                sumValue.insert(sumValue.begin(), sumStr.begin(), sumStr.end());
                carry = 1; //The carry for the next digit sum calculation
            }
        }

        return BigNumber(sumValue); //Returns a new BigNumber intialized with a vector contating digits of the sum
    }

    BigNumber BigNumber::Subtract(const BigNumber &_subtrahend)
    {
        BigNumber minuend = *this;
        BigNumber subtrahend = _subtrahend;

        //Handles subtraction if dealing with a negative value
        if (minuend.IsNegative() || subtrahend.IsNegative())
        {
            if (minuend.IsNegative() && subtrahend.IsNegative())
            {
                minuend.Negate();
                subtrahend.Negate();

                BigNumber difference = minuend.Add(subtrahend);
                difference.Negate();

                return difference;
            }
            else if (minuend.IsNegative() && subtrahend.IsPositive())
            {
                minuend.Negate();

                BigNumber difference = minuend.Add(subtrahend);
                difference.Negate();

                return difference;
            }
            else
            {
                subtrahend.Negate();

                BigNumber difference = subtrahend.Add(minuend);

                return difference;
            }
        }

        std::vector<char> differenceValue;
        int currentCalculatedDigit = 0; // The value of the current working digit which takes into account borrowing from the next digit
        int nextDigit = 0; // The calculated value of the next digit
        bool borrowedFromNextDigit = false; // Flag to remember if current calculation borrowed from the next digit
        bool increaseToTen = false; // Flag to remember if current digits next digit borrowed from it's next digit

        //Deals with subtraction when first number is smaller than the second. A negative difference.
        if (minuend < subtrahend)
        {
            //Subtracts the second number from the first number, resulting in the absolute value of the difference
            BigNumber diff = subtrahend.Subtract(minuend);
            diff.Negate(); //Negate the absolute value difference since value must be negative
            for (unsigned long long int i = 1; i < diff.numberValue.size(); ++i) //Removes any leading zeros
            {
                if (diff.numberValue[i] != '0') 
                {
                    break;
                }

                diff.numberValue.erase(diff.numberValue.begin()+1);
            }

            return diff;
        }

        //Adds 0's to front of small untill vector is size of larger number
        long long int bigNumSizeDiff = minuend.numberValue.size() - subtrahend.numberValue.size();
        if (bigNumSizeDiff > 1)
        {
            for (unsigned long long int i = 0; i < bigNumSizeDiff - 1; ++i)
            {
                subtrahend.numberValue.insert(subtrahend.numberValue.begin(), '0');
            }
        }


        long long int minuIndex = minuend.numberValue.size() - 1; //Keeps track of current digit in first number
        long long int subtIndex = subtrahend.numberValue.size() - 1; //Keeps track of current digit in second number
        for (; subtIndex >= 0; --subtIndex) //Iterates through second number from right to left
        {
            // Checks if the current digit of second number is greater than the current first number digit and if current first number digit is not the front digit
            if (((minuend.numberValue[minuIndex] - '0') < (subtrahend.numberValue[subtIndex] - '0')) && (minuIndex > 0)) 
            {
                currentCalculatedDigit = (minuend.numberValue[minuIndex] - '0') + 10; //Increase the current digit value of the first number by 10 since we are borrowing from the next digit 
                borrowedFromNextDigit = true; 
                //Checks if current second number digit is not the front digit or if the next digit of the first number does not equal zero
                if (subtIndex > 0 || minuend.numberValue[minuIndex - 1] != '0')
                {
                    nextDigit = (minuend.numberValue[minuIndex - 1] - '0') - 1; //The next digit in the first number is subtracted by 1 since the current digit borowed from it
                    if (nextDigit == -1)
                    {
                        nextDigit = 9; //If the next digit was 0 when borrowed, it must borrow from the it's next digit to become 10
                        increaseToTen = true;
                    }

                    borrowedFromNextDigit = false;
                }

                if (increaseToTen) //Run if the current digits next digit borrowed from it's next digit
                {
                    long long int nextDigitIndex = minuIndex - 1; //Index the next digit
                    long long int minuNext = minuIndex - 1; //Index of the current next digit next digit's

                    while((minuend.numberValue[minuNext] - '0') == 0) //Adds the value of the next digit while all digits in front are 0
                    {
                        minuend.numberValue[minuNext--] = (nextDigit + '0'); //It does this because if the values infront are 0 as well, then those digits are also borrowing from their next digits
                        --nextDigitIndex;
                    }

                   long long int tempDigit = (minuend.numberValue[nextDigitIndex] - '0') - 1; //Once a non zero number is reached, subtract 1 from it since the current numbers next number is borrowing from this current digit
                    minuend.numberValue[nextDigitIndex] = (tempDigit + '0');
                }

                minuend.numberValue[minuIndex - 1] = (nextDigit + '0');
                increaseToTen = false;
            }

            std::vector<char> iterationDiffValue;

            int digitDiff = ((minuend.numberValue[minuIndex] - '0') - (subtrahend.numberValue[subtIndex] - '0')); // The difference of both numbers current digits
            if (digitDiff == 0) //If both digits are equal
            {
                iterationDiffValue.push_back('0');
            }
            else
            {
                if (currentCalculatedDigit <= 0) //If the current first number digit did not borrow to increase its value, calculate difference based in current digits
                {
                    int dif = (minuend.numberValue[minuIndex] - '0') - (subtrahend.numberValue[subtIndex] - '0');
                    iterationDiffValue.push_back(dif + '0');
                }
                else //If the current first number digit borrowed from it's next digit, calculate difference based on incrased borrowed value
                {
                    int dif = currentCalculatedDigit - (subtrahend.numberValue[subtIndex] - '0');
                    iterationDiffValue.push_back(dif + '0');
                }
            }

            differenceValue.insert(differenceValue.begin(), iterationDiffValue.begin(), iterationDiffValue.end()); //insert the calculated difference value of the current current number digits
            --minuIndex; //Move index to of the first number to its next digit
            currentCalculatedDigit = 0;
        }

        if (borrowedFromNextDigit) //Runs if the current first number borrowed a digit from it's next number
        {
            std::vector<char> newNumber;
            //Runs for the amount of digit difference between the first number and scond number
            for (long long int remainingDigitsIndex = minuend.numberValue.size() - subtrahend.numberValue.size() - 1; remainingDigitsIndex >= 0; --remainingDigitsIndex)
            {
                if (minuend.numberValue[remainingDigitsIndex] == '0')
                {
                    newNumber.push_back('0');
                }
                else //if first number digit does is not 0
                {
                    newNumber.insert(newNumber.begin(), minuend.numberValue[remainingDigitsIndex]); //inserts that digit into the new number vector that represents the nubmer before it was borrowed from

                    long long int tempNum = std::stoll(&newNumber[0]);//Subtract that new calculated number by 1 since it was borrowed be previous to increase by 10
                    --tempNum; 

                    std::string tempNumValue = std::to_string(tempNum);
                    std::copy(tempNumValue.begin(), tempNumValue.end(), numberValue.begin()); //Copy the new borrowed value into the difference value, overiding the right digit places while doing so

                    break;
                }
            }
        }

        while (minuIndex >= 0) //Compies the remaining first number digits not affected into the difference value 
        {
            std::vector<char> remainingDigits;
            if (minuIndex == 0) //Copies the digit that unless the first numbers front digit if it is 0. Done to avoid placing digits in wrong place
            {
                if (minuend.numberValue[minuIndex] - '0' != 0) //
                {
                    remainingDigits.push_back(minuend.numberValue[minuIndex]);

                    differenceValue.insert(differenceValue.begin(), remainingDigits.begin(), remainingDigits.end());
                }
            }
            else
            {
                remainingDigits.push_back(minuend.numberValue[minuIndex]);

                differenceValue.insert(differenceValue.begin(), remainingDigits.begin(), remainingDigits.end());
            }

            --minuIndex;
        }

        //Checks if all digits are 0. If so, change difference value to a vector of one 0
        bool isAllZeros = std::all_of(differenceValue.begin(), differenceValue.end(), [](char digit) { return digit == '0'; });
        if (isAllZeros)
        {
            differenceValue.clear();
            differenceValue.push_back('0');
        }
        else if (differenceValue[0] == '0') //Removes any leading 0's
        {
            auto firstNonZero = std::find_if(differenceValue.begin(), differenceValue.end(), [](char digit) { return digit != 0; });

            differenceValue.erase(differenceValue.begin(), firstNonZero + 1);
        }

        return BigNumber(differenceValue); //Returns a new BigNumber with the difference value 
    }

    BigNumber BigNumber::Multiply(const BigNumber &_multiplier)
    {
        BigNumber largerNum = _multiplier > *this ? _multiplier : *this;
        BigNumber smallerNum = _multiplier > *this ? *this : _multiplier;

        //Deals with multiplication if any are negative numbers
        if (largerNum.IsNegative() || smallerNum.IsNegative())
        {
            if (largerNum.IsNegative() && smallerNum.IsNegative())
            {
                largerNum.Negate();
                smallerNum.Negate();

                BigNumber product = largerNum.Multiply(smallerNum);

                return product;
            }
            else if (largerNum.IsNegative() && smallerNum.IsPositive())
            {
                largerNum.Negate();

                BigNumber product = largerNum.Multiply(smallerNum);
                product.Negate();

                return product;
            }
            else
            {
                smallerNum.Negate();

                BigNumber product = smallerNum.Multiply(largerNum);
                product.Negate();

                return product;
            }
        }

        if (largerNum == BigNumber(0) || smallerNum == BigNumber(0))
        {
            return BigNumber(0);
        }

        if(largerNum == BigNumber(1) || smallerNum == BigNumber(1))
        {
            if(largerNum == BigNumber(1) && smallerNum == BigNumber(1))
            {
                return BigNumber(1);
            }

            return largerNum > smallerNum ? largerNum : smallerNum;
        }

        int carry = 0; 
        long long int zeroCounter = 0;
        BigNumber product;

        for (unsigned long long int i = 0; i < (largerNum.numberValue.size() - smallerNum.numberValue.size()); ++i) // Adds 0's to smaller number to match larger number length
        {
            smallerNum.numberValue.insert(smallerNum.numberValue.begin(), '0');
        }

        //Multiplies every digit in the smaller number by everydigit in the larger nuber and adds the product of those calculations to the priduct
        for (long long int i = (smallerNum.numberValue.size() - 1); i >= 0; --i)
        {
            std::string productValue;
            for (long long int j = (largerNum.numberValue.size() - 1); j >= 0; --j)
            {
                long long int val = ((smallerNum.numberValue[i] - '0') * (largerNum.numberValue[j] - '0')) + carry; //Product of current second digit with current first digit
                carry = 0;

                //If the product is greater than 10, add the last digit to the product and set the carry to the value of the remaining digits
                if (val > 9 && j != 0)
                {
                    carry = val / 10;
                    productValue.insert(0, std::to_string(val % 10));
                }
                else //Add value of digit product to product
                {
                    productValue.insert(0, std::to_string(val));
                }
            }

            // zeros to keep track of place and have accurete value based on digit placement
            if (zeroCounter > 0)
            {
                for (unsigned long long int sizeDiff = 0; sizeDiff < zeroCounter; ++sizeDiff)
                {
                    productValue.append("0");
                }
            }

            ++zeroCounter;
            product += BigNumber(productValue); //Add calculated product to the overall product
        }

        //Remove any leading zeros
        bool isAllZeros = std::all_of(product.numberValue.begin(), product.numberValue.end(), [](char digit) { return digit == '0'; });
        if (isAllZeros)
        {
            product.numberValue.clear();
            product.numberValue.push_back('0');
        }
        else if(product.numberValue[0] == '0')
        {
            auto firstNonZero = std::find_if(product.numberValue.begin(), product.numberValue.end(), [](char digit) { return digit != 0; });

            product.numberValue.erase(product.numberValue.begin(), firstNonZero + 1);
        }

        return product;
    }

    BigNumber BigNumber::Divide(const BigNumber &_divisor)
    {
        if (_divisor == BigNumber(0))
        {
            throw std::invalid_argument("No Division by 0");
        }

        BigNumber dividend = *this;
        BigNumber divisor = _divisor;
        bool quotientIsNegative = false; //Boolean flag to remember if the quotient needs to be negated

        //Handles division if any of the numbers are negative
        if(dividend.IsNegative() || divisor.IsNegative())
        {
            if (dividend.IsNegative() && divisor.IsNegative())
            {
                dividend.Negate();
                divisor.Negate();
            }
            else if (dividend.IsNegative() && divisor.IsPositive())
            {
                dividend.Negate();
                quotientIsNegative = true;
            }
            else if (dividend.IsPositive() && divisor.IsNegative())
            {
                divisor.Negate();
                quotientIsNegative = true;
            }
        }

        //Subtracts the first numbr from the second number until it is less than 0, each time teh quotient is incremented
        BigNumber quotient;
        while (dividend >= divisor)
        {
            dividend -= divisor;
            ++quotient;
        }

        if (quotientIsNegative)
        {
            quotient.Negate();
        }

        return quotient;
    }

    //Same thing as division but returns the remainder instead
    BigNumber BigNumber::Mod(const BigNumber &_divisor)
    {
        if (_divisor == BigNumber(0)) {
            throw std::invalid_argument("No Division by 0");
        }

        BigNumber dividend = *this;
        BigNumber divisor = _divisor;
        bool remainderIsNegative = false;

        if(dividend.IsNegative() || divisor.IsNegative())
        {
            if (dividend.IsNegative() && divisor.IsNegative())
            {
                dividend.Negate();
                divisor.Negate();
            }
            else if (dividend.IsNegative() && divisor.IsPositive())
            {
                dividend.Negate();
                remainderIsNegative = true;
            }
            else if (dividend.IsPositive() && divisor.IsNegative())
            {
                divisor.Negate();
                remainderIsNegative = true;
            }
        }

        BigNumber remainder = dividend;
        while (dividend >= divisor)
        {
            dividend -= divisor;
            remainder -= divisor;
        }

        if (remainderIsNegative)
        {
            remainder.Negate();
        }

        return remainder;
    }

    BigNumber BigNumber::Pow(int _exponent)
    {
        if (_exponent < 0)
        {
             throw std::invalid_argument("Exponent must be greater than 0");
        }

        if (_exponent == 0)
        {
            return BigNumber(1);
        }

        if (_exponent == 1)
        {
            return *this;
        }

        BigNumber result = BigNumber(1);
        BigNumber base = *this;

        //Multiplies the base by itself as many times as the exponent
        for (unsigned long long int i = 0; i <= _exponent; ++i)
        {
            result *= base;
        }

        return result;
    }

    const std::string BigNumber::GetString() const
    {
        std::string numberValueString;
        if(this->numberValue.size() > numberValueString.max_size())
        {
            throw std::out_of_range("Number Value exceeds std::string size limit");
        }

        numberValueString = std::string(this->numberValue.begin(), this->numberValue.end());

        return numberValueString;
    }

    long long int BigNumber::GetInteger() const
    {

        if(*this > BigNumber(LLONG_MAX) || *this < BigNumber(LLONG_MIN))
        {
          throw std::out_of_range("Number Value exceeds long long int range");
        }

        return std::stoll(std::string(this->numberValue.begin(), this->numberValue.end()));
    }

    std::vector<char> BigNumber::GetNumberValue() const
    {
        return this->numberValue;
    }

    BigNumber BigNumber::GetBinaryValue() const
    {
        if(this->IsNegative())
        {
            throw std::invalid_argument("Negative Binary Values Not Allowed");
        }

        std::vector<char> binaryValue;
        BigNumber ogNum = *this;

        //Calculates the binary number by getting mod of 2
        while(ogNum > 0)
        {
            std::string remainder = (ogNum % 2).GetString();
            binaryValue.push_back(remainder[0]);
            ogNum /= 2;
        }
        std::reverse(binaryValue.begin(), binaryValue.end());

        return BigNumber(binaryValue);
    }

    BigNumber BigNumber::Negate()
    {
        if (this->numberValue[0] == '-')
        {
            this->numberValue.erase(numberValue.begin());
        }
        else
        {
            this->numberValue.insert(this->numberValue.begin(), '-');
        }

        return *this;
    }

    BigNumber BigNumber::RemoveLeadingZeros()
    {

        BigNumber bigNum = *this;
        bool isAllZeros = std::all_of(bigNum.numberValue.begin(), bigNum.numberValue.end(), [](char digit) { return digit == '0'; });

        if(isAllZeros)
        {
            return BigNumber(0);
        }
        else if(bigNum.numberValue[0] == '0')
        {
            auto firstNonZero = std::find_if(bigNum.numberValue.begin(), bigNum.numberValue.end(), [](char digit) { return digit != '0'; });

            bigNum.numberValue.erase(bigNum.numberValue.begin(), firstNonZero + 1);
        }

        return bigNum;
    }

    bool BigNumber::Equals(const BigNumber& _comparedNum) const
    {
        return this->numberValue == _comparedNum.numberValue;
    }

    unsigned long long int BigNumber::Digits() const
    {
        if (this->IsNegative())
        {
            return this->numberValue.size() - 1;
        }

        return this->numberValue.size();
    }

    bool BigNumber::IsNegative() const
    {
        return this->numberValue[0] == '-';
    }

    bool BigNumber::IsPositive() const
    {
        return this->numberValue[0] != '-';
    }

    bool BigNumber::IsEven() const
    {
        return (((this->numberValue.back() - '0') % 2) == 0);
    }

    bool BigNumber::IsOdd() const
    {
        return (((this->numberValue.back() - '0') % 2) != 0);
    }

    BigNumber BigNumber::Abs() const
    {

        BigNumber abs = *this;

        if (abs.numberValue[0] == '-')
        {
            abs.numberValue.erase(abs.numberValue.begin());
        }

        return abs;
    }

    std::ostream &operator << (std::ostream &outputStream, const BigNumber &_bigNum)
    {
        for (char digit : _bigNum.numberValue)
        {
            outputStream << digit;
        }

        return outputStream;
    }

    std::istream &operator >> (std::istream &inputStream, BigNumber &_bigNum)
    {
        std::string numberValueString;
        inputStream >> numberValueString;
        _bigNum.numberValue = std::vector<char>(numberValueString.begin(), numberValueString.end());

        return inputStream;
    }

    BigNumber operator + (BigNumber _addend1, const BigNumber &_addend2)
    {
        return _addend1.Add(_addend2);
    }

    BigNumber operator - (BigNumber _minuend, const BigNumber &_subtrahend)
    {
        return _minuend.Subtract(_subtrahend);
    }

    BigNumber operator - (const BigNumber &_bigNum)
    {
        return BigNumber(_bigNum).Negate();
    }

    BigNumber operator * (BigNumber _multiplicand, const BigNumber &_multiplier)
    {
        return _multiplicand.Multiply(_multiplier);
    }

    BigNumber operator / (BigNumber _dividend, const BigNumber &_divisor)
    {
        return _dividend.Divide(_divisor);
    }

    BigNumber operator % (BigNumber _dividend, const BigNumber &_divisor)
    {
        return _dividend.Mod(_divisor);
    }

    BigNumber operator ^ (BigNumber _base, int _power)
    {
        return _base.Pow(_power);
    }

    bool operator == (const BigNumber &_bigNum1, const BigNumber& _bigNum2)
    {
        return _bigNum1.Equals(_bigNum2);
    }

    bool operator != (const BigNumber &_bigNum1, const BigNumber& _bigNum2)
    {
        return !(_bigNum1.Equals(_bigNum2));
    }

    bool operator > (const BigNumber &_bigNum1, const BigNumber &_bigNum2)
    {

        BigNumber compBigNum1 = _bigNum1;
        BigNumber compBigNum2 = _bigNum2;

        // Handles if a number is negative
        if (compBigNum1.IsNegative() || compBigNum2.IsNegative())
        {
            if (compBigNum1.IsNegative() && compBigNum2.IsNegative())
            {
                compBigNum1.Negate();
                compBigNum2.Negate();

                return compBigNum1 < compBigNum2;
            }
            else
            {
                return (compBigNum1.IsPositive() && compBigNum2.IsNegative());
            }
        }

        compBigNum1 = compBigNum1.RemoveLeadingZeros();
        compBigNum2 = compBigNum2.RemoveLeadingZeros();

        if (compBigNum1.numberValue == compBigNum2.numberValue) //Checks if the numbers' digit vectors are equal
        {
            return false;
        }

        if (compBigNum1.numberValue.size() != compBigNum2.numberValue.size())//If the vectors are different size, return if size of number one is larger than that of two
        {
            return compBigNum1.numberValue.size() > compBigNum2.numberValue.size();
        }
        else
        {   //If both vectors are same size, compare each digit from left to right
            for (unsigned long long int i = 0; i <  compBigNum1.numberValue.size(); ++i)
            {
                if((compBigNum1.numberValue[i] - '0') != (compBigNum2.numberValue[i] - '0'))
                {
                    return ((compBigNum1.numberValue[i] - '0') > (compBigNum2.numberValue[i] - '0'));
                }
            }
        }

        return false;
    }

    bool operator < (const BigNumber &_bigNum1, const BigNumber &_bigNum2)
    {
        return (!(_bigNum1.Equals(_bigNum2)) && !(_bigNum1 > _bigNum2));
    }

    bool operator >= (const BigNumber &_bigNum1, const BigNumber &_bigNum2)
    {
        return ((_bigNum1 > _bigNum2) || (_bigNum1.Equals(_bigNum2)));
    }

    bool operator <= (const BigNumber &_bigNum1, const BigNumber &_bigNum2)
    {
        return ((_bigNum1 < _bigNum2) || (_bigNum1.Equals(_bigNum2)));
    }

    BigNumber operator & (const BigNumber &_bigNum1, const BigNumber &_bigNum2)
    {
        BigNumber largerNum = _bigNum1 > _bigNum2 ? _bigNum1 : _bigNum2;
        BigNumber smallerNum = _bigNum1 > _bigNum2 ? _bigNum2 : _bigNum1;

        largerNum = largerNum.GetBinaryValue();
        smallerNum = smallerNum.GetBinaryValue();

        std::vector<char> bitAndValue;
        int diff = largerNum.numberValue.size() - smallerNum.numberValue.size();
        for (unsigned long long int i = 0; i < diff; ++i)
        {
            smallerNum.numberValue.insert(smallerNum.numberValue.begin(), '0');
        }

        for (long long int i = largerNum.numberValue.size() - 1 ; i >= 0; --i)
        {
            if(largerNum.numberValue[i] == smallerNum.numberValue[i])
            {
                bitAndValue.insert(bitAndValue.begin(),'1');
            }
            else
            {
                bitAndValue.insert(bitAndValue.begin(),'0');
            }
        }

        return ConvertBinaryValue(BigNumber(bitAndValue));
    }

    BigNumber operator | (const BigNumber &_bigNum1, const BigNumber &_bigNum2)
    {
        BigNumber largerNum = _bigNum1 > _bigNum2 ? _bigNum1 : _bigNum2;
        BigNumber smallerNum = _bigNum1 > _bigNum2 ? _bigNum2 : _bigNum1;

        largerNum = largerNum.GetBinaryValue();
        smallerNum = smallerNum.GetBinaryValue();

        std::vector<char> bitOrValue;
        int diff = largerNum.numberValue.size() - smallerNum.numberValue.size();
        for (unsigned long long int i = 0; i < diff; ++i)
        {
            smallerNum.numberValue.insert(smallerNum.numberValue.begin(), '0');
        }

        for (long long int i = largerNum.numberValue.size() - 1 ; i >= 0; --i)
        {
            if(largerNum.numberValue[i] == '1' || smallerNum.numberValue[i] == '1')
            {
                bitOrValue.insert(bitOrValue.begin(),'1');
            }
            else
            {
                bitOrValue.insert(bitOrValue.begin(),'0');
            }
        }

        return ConvertBinaryValue(BigNumber(bitOrValue));
    }

    BigNumber operator ^ (const BigNumber &_bigNum1, const BigNumber &_bigNum2)
    {
        BigNumber largerNum = _bigNum1 > _bigNum2 ? _bigNum1 : _bigNum2;
        BigNumber smallerNum = _bigNum1 > _bigNum2 ? _bigNum2 : _bigNum1;

        largerNum = largerNum.GetBinaryValue();
        smallerNum = smallerNum.GetBinaryValue();

        std::vector<char> bitAndValue;
        int diff = largerNum.numberValue.size() - smallerNum.numberValue.size();
        for (unsigned long long int i = 0; i < diff; ++i)
        {
            smallerNum.numberValue.insert(smallerNum.numberValue.begin(), '0');
        }

        for (long long int i = largerNum.numberValue.size() - 1 ; i >= 0; --i)
        {
            if(largerNum.numberValue[i] != smallerNum.numberValue[i])
            {
                bitAndValue.insert(bitAndValue.begin(),'1');
            }
            else
            {
                bitAndValue.insert(bitAndValue.begin(),'0');
            }
        }

        return ConvertBinaryValue(BigNumber(bitAndValue));
    }

    BigNumber operator << (const BigNumber &_bigNum, int numOfPlaces)
    {
        BigNumber shiftedNum = _bigNum;
        for(int i = 0; i < numOfPlaces; ++i)
        {
            shiftedNum *= 2; //Each left shift is equivilent to muliplying by 2
        }

        return shiftedNum;
    }

    BigNumber operator >> (const BigNumber &_bigNum, int numOfPlaces)
    {
        BigNumber shiftedNum = _bigNum;
        for(int i = 0; i < numOfPlaces; ++i)
        {
            shiftedNum /= 2; //Each right shift is equivilent to dividing by 2
        }

        return shiftedNum;
    }

    BigNumber operator ~ (const BigNumber &_bigNum)
    {
        std::vector<char> xorBinary;
        BigNumber xorNum = _bigNum.GetBinaryValue();

        //Inverts each bit
        for(char bit : xorNum.GetNumberValue())
        {
            if(bit == '0')
            {
                xorBinary.push_back('1');
            }
            else
            {
                xorBinary.push_back('0');
            }
        }

        return ConvertBinaryValue(BigNumber(xorBinary));
    }

    char BigNumber::operator [] (int index) const
    {
        if((index >= this->numberValue.size()) || (index < 0))
        {
            throw std::out_of_range("Index out of range");
        }

        if (this->numberValue[index] == '-')
        {
            throw std::invalid_argument("You cannot get the negative sign from the number");
        }

        return this->numberValue[index];
    }

    char &BigNumber::operator [] (int index)
    {
        if((index >= this->numberValue.size()) || (index < 0))
        {
            throw std::out_of_range("Index out of range");
        }

        if (this->numberValue[index] == '-')
        {
            throw std::invalid_argument("You cannot get the negative sign from the number");
        }

        return this->numberValue[index];
    }

    BigNumber &BigNumber::operator++()
    {
        *this += BigNumber(1);
        return *this;
    }

    BigNumber &BigNumber::operator--()
    {
        *this -= BigNumber(1);
        return *this;
    }

    const BigNumber BigNumber::operator++(int)
    {
        BigNumber tempBigNum = *this;
        ++(*this);
        return tempBigNum;
    }

    const BigNumber BigNumber::operator--(int)
    {
        BigNumber tempBigNum = *this;
        --(*this);
        return tempBigNum;
    }

    BigNumber ConvertBinaryValue(const BigNumber &_binaryNum)
    {
        BigNumber convertedNum;
        std::vector<char> binaryValue = _binaryNum.GetNumberValue();
        unsigned long long int bitPlace = 1;
        std::reverse(binaryValue.begin(), binaryValue.end());

        for(char bit : binaryValue)
        {
            if(bit == '1')
            {
                convertedNum += bitPlace;
            }
            bitPlace *= 2;
        }

        return convertedNum;
    }

}