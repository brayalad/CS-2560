#include <algorithm>
#include <cmath>
#include <climits>

#include "include/BigNumber.h"

namespace BigNums {

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
        for (long long int i = 0; i < diff; ++i)
        {
            smallerNum.numberValue.insert(smallerNum.numberValue.begin(), '0');
        }


        for (long long int i = largerNum.numberValue.size() - 1 ; i >= 0; --i)
        {
            int addend1 = largerNum.numberValue[i] - '0';
            int addend2 = smallerNum.numberValue[i] - '0';

            int sum = addend1 + addend2 + carry;
            std::string sumStr;

            carry = 0;
            if (sum <= 9 || i == 0)
            {
                sumStr = std::to_string(sum);
                sumValue.insert(sumValue.begin(), sumStr.begin(), sumStr.end());
            }
            else
            {
                sumStr = std::to_string(sum % 10);
                sumValue.insert(sumValue.begin(), sumStr.begin(), sumStr.end());
                carry = 1;
            }
        }

        return BigNumber(sumValue);
    }

    BigNumber BigNumber::Subtract(const BigNumber &_subtrahend)
    {
        BigNumber minuend = *this;
        BigNumber subtrahend = _subtrahend;

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
        int currentCalculatedDigit = 0;
        int nextDigit = 0;
        bool borrowedFromNextDigit = false;
        bool increaseToTen = false;

        if (minuend < subtrahend)
        {
            BigNumber diff = subtrahend.Subtract(minuend);
            diff.Negate();
            for (unsigned long long int i = 1; i < diff.numberValue.size(); ++i)
            {
                if (diff.numberValue[i] != '0')
                {
                    break;
                }

                diff.numberValue.erase(diff.numberValue.begin()+1);
            }

            return diff;
        }


        long long int bigNumSizeDiff = minuend.numberValue.size() - subtrahend.numberValue.size();
        if (bigNumSizeDiff > 1)
        {
            for (unsigned long long int i = 0; i < bigNumSizeDiff - 1; ++i)
            {
                subtrahend.numberValue.insert(subtrahend.numberValue.begin(), '0');
            }
        }


        long long int minuIndex = minuend.numberValue.size() - 1;
        long long int subtIndex = subtrahend.numberValue.size() - 1;
        for (; subtIndex >= 0; --subtIndex)
        {
            if (((minuend.numberValue[minuIndex] - '0') < (subtrahend.numberValue[subtIndex] - '0')) && (minuIndex > 0))
            {
                currentCalculatedDigit = (minuend.numberValue[minuIndex] - '0') + 10;
                borrowedFromNextDigit = true;
                if (subtIndex > 0 || minuend.numberValue[minuIndex - 1] != '0')
                {
                    nextDigit = (minuend.numberValue[minuIndex - 1] - '0') - 1;
                    if (nextDigit == -1)
                    {
                        nextDigit = 9;
                        increaseToTen = true;
                    }

                    borrowedFromNextDigit = false;
                }

                if (increaseToTen)
                {
                    long long int nextDigitIndex = minuIndex - 1;
                    long long int minuNext = minuIndex - 1;

                    while((minuend.numberValue[minuNext] - '0') == 0)
                    {
                        minuend.numberValue[minuNext--] = (nextDigit + '0');
                        --nextDigitIndex;
                    }

                   long long int tempDigit = (minuend.numberValue[nextDigitIndex] - '0') - 1;
                    minuend.numberValue[nextDigitIndex] = (tempDigit + '0');
                }

                minuend.numberValue[minuIndex - 1] = (nextDigit + '0');
                increaseToTen = false;
            }

            std::vector<char> iterationDiffValue;

            int digitDiff = ((minuend.numberValue[minuIndex] - '0') - (subtrahend.numberValue[subtIndex] - '0'));
            if (digitDiff == 0)
            {
                iterationDiffValue.push_back('0');
            }
            else
            {
                if (currentCalculatedDigit <= 0)
                {
                    int dif = (minuend.numberValue[minuIndex] - '0') - (subtrahend.numberValue[subtIndex] - '0');
                    iterationDiffValue.push_back(dif + '0');
                }
                else
                {
                    int dif = currentCalculatedDigit - (subtrahend.numberValue[subtIndex] - '0');
                    iterationDiffValue.push_back(dif + '0');
                }
            }

            differenceValue.insert(differenceValue.begin(), iterationDiffValue.begin(), iterationDiffValue.end());
            --minuIndex;
            currentCalculatedDigit = 0;
        }

        if (borrowedFromNextDigit)
        {
            std::vector<char> newNumber;
            for (long long int remainingDigitsIndex = minuend.numberValue.size() - subtrahend.numberValue.size() - 1; remainingDigitsIndex >= 0; --remainingDigitsIndex)
            {
                if (minuend.numberValue[remainingDigitsIndex] == '0')
                {
                    newNumber.push_back('0');
                }
                else
                {
                    newNumber.insert(newNumber.begin(), minuend.numberValue[remainingDigitsIndex]);

                    long long int tempNum = std::stoll(&newNumber[0]);
                    --tempNum;

                    std::string tempNumValue = std::to_string(tempNum);
                    std::copy(tempNumValue.begin(), tempNumValue.end(), numberValue.begin());

                    break;
                }
            }
        }

        while (minuIndex >= 0)
        {
            std::vector<char> remainingDigits;
            if (minuIndex == 0)
            {
                if (minuend.numberValue[minuIndex] - '0' != 0)
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


        bool isAllZeros = std::all_of(differenceValue.begin(), differenceValue.end(), [](char digit) { return digit == '0'; });
        if (isAllZeros)
        {
            differenceValue.clear();
            differenceValue.push_back('0');
        }
        else if (differenceValue[0] == '0')
        {
            auto firstNonZero = std::find_if(differenceValue.begin(), differenceValue.end(), [](char digit) { return digit != 0; });

            differenceValue.erase(differenceValue.begin(), firstNonZero + 1);
        }

        return BigNumber(differenceValue);
    }

    BigNumber BigNumber::Multiply(const BigNumber &_multiplier)
    {
        BigNumber largerNum = _multiplier > *this ? _multiplier : *this;
        BigNumber smallerNum = _multiplier > *this ? *this : _multiplier;


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

        int carry = 0;
        long long int zeroCounter = 0;
        BigNumber product;

        for (unsigned long long int i = 0; i < (largerNum.numberValue.size() - smallerNum.numberValue.size()); ++i)
        {
            smallerNum.numberValue.insert(smallerNum.numberValue.begin(), '0');
        }

        for (long long int i = (smallerNum.numberValue.size() - 1); i >= 0; --i)
        {
            std::string productValue;
            for (long long int j = (largerNum.numberValue.size() - 1); j >= 0; --j)
            {
                long long int val = ((smallerNum.numberValue[i] - '0') * (largerNum.numberValue[j] - '0')) + carry;
                carry = 0;

                if (val > 9 && j != 0)
                {
                    carry = val / 10;
                    productValue.insert(0, std::to_string(val % 10));
                }
                else
                {
                    productValue.insert(0, std::to_string(val));
                }
            }

            if (zeroCounter > 0)
            {
                for (unsigned long long int sizeDiff = 0; sizeDiff < zeroCounter; ++sizeDiff)
                {
                    productValue.append("0");
                }
            }

            ++zeroCounter;
            product += BigNumber(productValue);
        }

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
        bool quotientIsNegative = false;

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

        if (compBigNum1.numberValue == compBigNum2.numberValue)
        {
            return false;
        }

        if (compBigNum1.numberValue.size() != compBigNum2.numberValue.size())
        {
            return compBigNum1.numberValue.size() > compBigNum2.numberValue.size();
        }
        else
        {
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
            shiftedNum *= 2;
        }

        return shiftedNum;
    }

    BigNumber operator >> (const BigNumber &_bigNum, int numOfPlaces)
    {
        BigNumber shiftedNum = _bigNum;
        for(int i = 0; i < numOfPlaces; ++i)
        {
            shiftedNum /= 2;
        }

        return shiftedNum;
    }

    BigNumber operator ~ (const BigNumber &_bigNum)
    {
        std::vector<char> xorBinary;
        BigNumber xorNum = _bigNum.GetBinaryValue();

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