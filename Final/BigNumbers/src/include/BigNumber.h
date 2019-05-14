#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>

/**
 * BigNums namspace\n
 * Namspace in which the BigNumber class and\n
 * library functions are contained
 */
namespace BigNums
{

/**
 * BigNumber class\n
 * Digits of the number are stored in a vector of characters\n
 * representing the different digits of the numbers
 */
    class BigNumber
    {

    private:
        std::vector<char> numberValue; /** Vector holding digits of the current instance */

    public:
        //@{
        /**
         * BigNumber constructor\n
         * Support for all data types
         * @param number  The initial value of the BigNumber
         */
        BigNumber();

        explicit BigNumber(char number);

        explicit BigNumber(unsigned char number);

        explicit BigNumber(const char *number);

        explicit BigNumber(std::string number);

        explicit BigNumber(short number);

        explicit BigNumber(unsigned short number);

        explicit BigNumber(int number);

        explicit BigNumber(unsigned int number);

        explicit BigNumber(long long number);

        explicit BigNumber(unsigned long long number);

        explicit BigNumber(float number);

        explicit BigNumber(double number);

        explicit BigNumber(long double number);

        explicit BigNumber(const std::vector<char> &number);

        BigNumber(const BigNumber &number);

        ~BigNumber() = default;

        //@}

        /**
         * Add another BigNumber to the current instance
         * @param _addend The BigNumber being added by
         * @return The sum of the two BigNumbers
         */
        BigNumber Add(const BigNumber& _addend);

        /**
         * Subtract another BigNumber from the current instance
         * @param _subtrahend - The BigNumber subtracted by
         * @return The difference of the two BigNumbers
         */
        BigNumber Subtract(const BigNumber &_subtrahend);

        /**
         * Multiply the current instance by another BigNumber
         * @param _multiplier The BigNumber being multiplied by
         * @return The product of the two BigNumbers
         */
        BigNumber Multiply(const BigNumber &_multiplier);

        /**
         * Divide the current instance by another BigNumber
         * @param _divisor The BigNumber being divided by
         * @return The quotient of the two BigNumbers
         */
        BigNumber Divide(const BigNumber &_divisor);

        /**
         * Mod the current instance by another BigNumber
         * @param _divisor The Big Number being divided by
         * @return The remainder of the two BigNumbers
         */
        BigNumber Mod(const BigNumber &_divisor);

        /**
         * Raise the current instance to the power of an exponent
         * @param exponent The power to be raised by
         * @return - The BigNumber calculated
         */
        BigNumber Pow(int _exponent);

        /**
         * Get the string value of the current instance
         * @return The BigNumber value as a string
         */
        const std::string GetString() const;

        /**
         * Get the integer value of the current instance
         * @return The BigNumber value as a long long int
         */
        long long int GetInteger() const;

        /**
         * Get the value of current instance as a vector of chars
         * @return The BigNumber value as a vector
         */
        std::vector<char> GetNumberValue() const;

        /**
         * Get the value of the current instance as bits
         * @return The BigNumber value represented as bits
         */
        BigNumber GetBinaryValue() const;


        /**
         * Set the value of the current instance with a new value
         * @param _newNum The new value for the BigNumber
         * @return The BigNumber with the new value
         */
        template <typename T>
        BigNumber SetNumber(const T& _newNum)
        {
            this->numberValue = BigNumber(_newNum).numberValue;
            return *this;
        }

        /**
         * Negates the value of the current instance
         * @return The BigNumber after negation
         */
        BigNumber Negate();

        /**
         * Removes the zeros in front of the BigNumber
         * @return The BigNumber without leading zeros
         */
        BigNumber RemoveLeadingZeros();

        /**
         * Check if another BigNumber is equal to the current instance
         * @param _comparedNum The BigNumber being compared
         * @return True if equal, false if not
         */
        bool Equals(const BigNumber& _comparedNum) const;

        /**
         * Get the number of digits in the current instance
         * @return The number of digits
         */
        unsigned long long int Digits() const;

        /**
         * Get if the current instance is negative
         * @return True if negative, False if positive
         */
        bool IsNegative() const;

        /**
         * Get if the current instance is positive
         * @return True if positive, False if negative
         */
        bool IsPositive() const;

        /**
         * Get if the current instance is even
         * @return True if even, False if odd
         */
        bool IsEven() const;

        /**
         * Get if the current instance is odd
         * @return True if odd, False if even
         */
        bool IsOdd() const;

        /**
         * Get the absolute value of the current instance
         * @return The BigNumber absolute value
         */
        BigNumber Abs() const;

        /**
         * Output stream operator
         * @param outputStream The output stream
         * @param _bigNum The current instance
         * @return The output stream with the current instance
         */
        friend std::ostream &operator<<(std::ostream &outputStream, const BigNumber &_bigNum);

        /**
         * Input stream operator
         * @param inputStream The input stream
         * @param _bigNum The current instance
         * @return The input stream with the current instance
         */
        friend std::istream &operator>>(std::istream &inputStream, BigNumber &_bigNum);

        //@{
        /**
         * Addition operator
         * @param _addend1 The current instance
         * @param _addend2 The number being added
         * @return The sum of the two BigNumbers
         */
        friend BigNumber operator + (BigNumber _addend1, const BigNumber &_addend2);

        template <typename T, typename U>
        friend BigNumber operator + (const T &_addend1, const U &_addend2)
        {
            return BigNumber(_addend1) + BigNumber(_addend2);

        }
        //@}


        //@{
        /**
         * Subtraction operator
         * @param _minuend The current instance
         * @param _subtrahend The number being subtracted
         * @return The difference of the two BigNumbers
         */
        friend BigNumber operator - (BigNumber _minuend, const BigNumber &_subtrahend);

        template <typename T, typename U>
        friend BigNumber operator - (const T &_minuend, const U &_subtrahend )
        {
            return BigNumber(_minuend) - BigNumber(_subtrahend);
        }

        //@}

        //@{
        /**
         * Negation operator
         * @param _bigNum The current instance
         * @return The negated value of the number
         */
        friend BigNumber operator - (const BigNumber &_bigNum);

        //@}

        //@{
        /**
         * Multiplication operator
         * @param _multiplicand The current instance
         * @param _multiplier The number being multiplied by
         * @return The product of the two BigNumbers
         */
        friend BigNumber operator * (BigNumber _multiplicand, const BigNumber &_multiplier);

        template <typename T, typename U>
        friend BigNumber operator * (const T &_multiplicand, const U &_multiplier)
        {
            return BigNumber(_multiplicand) * BigNumber(_multiplier);
        }
        //@}

        //@{
        /**
         * Division operator
         * @param _dividend The current instance
         * @param _divisor The number being divided by
         * @return The quotient of the two BigNumbers
         */
        friend BigNumber operator / (BigNumber _dividend, const BigNumber &_divisor);

        template <typename T, typename U>
        friend BigNumber operator / (const T &_dividend, const U &_divisor)
        {
            return BigNumber(_dividend) / BigNumber(_divisor);
        }

        //@}


        //@{
        /**
         * Mod operator
         * @param _dividend The current instance
         * @param _divisor The number being divided by
         * @return The remainder of the two BigNumbers
         */
        friend BigNumber operator % (BigNumber _dividend, const BigNumber &_divisor);

        template <typename T, typename U>
        friend BigNumber operator % (const T &_dividend, const U &_divisor)
        {
            return BigNumber(_dividend) % BigNumber(_divisor);
        }
        //@}

        /**
         * Exponent operator
         * @param _base The current instance
         * @param _power The exponent
         * @return The value calculated raising by exponent
         */
        friend BigNumber operator ^ (BigNumber _base, int _power);

        //@{
        /**
         * Equals operator
         * @param _bigNum1 The current instance
         * @param _bigNum2 Another number value
         * @return True if equal, False if not
         */
        friend bool operator == (const BigNumber &_bigNum1, const BigNumber& _bigNum2);

        template <typename T, typename U>
        friend bool operator == (const T& _bigNum1, const U& _bigNum2)
        {
            return BigNumber(_bigNum1) == BigNumber(_bigNum2);
        }
        //@}


        //@{
        /**
         * Not equals operator
         * @param _bigNum1 The current instance
         * @param _bigNum2 Another number value
         * @return True if not equal, False if equal
         */
        template <typename T, typename U>
        friend bool operator != (const BigNumber &_bigNum1, const BigNumber& _bigNum2);

        template <typename T, typename U>
        friend bool operator != (const T& _bigNum1, const U& _bigNum2)
        {
            return !(BigNumber(_bigNum1) == BigNumber(_bigNum2));
        }
        //@}

        //@{
        /**
         * Greater than operator
         * @param _bigNum1 The current instance
         * @param _bigNum2 Another BigNumber
         * @return True if current instance is greater, False if not
         */
        friend bool operator>(const BigNumber &_bigNum1, const BigNumber &_bigNum2);

        template <typename T, typename U>
        friend bool operator > (const T &_bigNum1, const U &_bigNum2)
        {
            return BigNumber(_bigNum1) > BigNumber(_bigNum2);
        }
        //@}

        //@{
        /**
         * Less than operator
         * @param _bigNum1 The current instance
         * @param _bigNum2 Another BigNumber
         * @return True if current instance is less, False if not
         */
        friend bool operator<(const BigNumber &_bigNum1, const BigNumber &_bigNum2);

        template <typename T, typename U>
        friend bool operator < (const T &_bigNum1, const U &_bigNum2)
        {
            return BigNumber(_bigNum1) < BigNumber(_bigNum2);
        }
        //@}

        //@{
        /**
         * Greater than or equal to operator
         * @param _bigNum1 The current instance
         * @param _bigNum2 Another BigNumber
         * @return True if current instance is greater or equal, False if not
         */
        friend bool operator>=(const BigNumber &_bigNum1, const BigNumber &_bigNum2);

        template <typename T, typename U>
        friend bool operator >= (const T &_bigNum1, const U &_bigNum2)
        {
            return BigNumber(_bigNum1) >= BigNumber(_bigNum2);
        }
        //@}

        //@{
        /**
         * Less than or equal to operator
         * @param _bigNum1 The current instance
         * @param _bigNum2 Another BigNumber
         * @return True if current instance is less or equal, False if not
         */
        friend bool operator<=(const BigNumber &_bigNum1, const BigNumber &_bigNum2);

        template <typename T, typename U>
        friend bool operator <= (T _bigNum1, const U &_bigNum2)
        {
            return BigNumber(_bigNum1) <= BigNumber(_bigNum2);
        }
        //@}

        /**
         * Bitwise AND operator
         * @param _bigNum1 The current instance
         * @param _bigNum2 Another BigNumber
         * @return BigNumber value of AND operation
         */
        friend BigNumber operator & (const BigNumber &_bigNum1, const BigNumber &_bigNum2);

        /**
         * Bitwise OR operator
         * @param _bigNum1 The current instance
         * @param _bigNum2 Another BigNumber
         * @return BigNumber value of OR operation
         */
        friend BigNumber operator | (const BigNumber &_bigNum1, const BigNumber &_bigNum2);

        /**
         * Bitwise XOR operator
         * @param _bigNum1 The current instance
         * @param _bigNum2 Another BigNumber
         * @return BigNumber value of XOR operation
         */
        friend BigNumber operator ^ (const BigNumber &_bigNum1, const BigNumber &_bigNum2);

        /**
         * Bitwise left shift
         * @param _bigNum The current instance
         * @param numOfPlaces amount of places to shift
         * @return BigNumber value of shifting bits to the left
         */
        friend BigNumber operator << (const BigNumber &_bigNum, int numOfPlaces);

        /**
         * Bitwise right shift
         * @param _bigNum The current instance
         * @param numOfPlaces amount of places to shift
         * @return BigNumber value of shifting bits to the right
         */
        friend BigNumber operator >> (const BigNumber &_bigNum, int numOfPlaces);

        /**
         * Bitwise NOT operator
         * @param _bigNum The current instance
         * @return BigNumber value of inverted bits
         */
        friend BigNumber operator ~ (const BigNumber &_bigNum);

        /**
         * Assignment operator
         * @param _difBigNum The new value for the BigNumber
         * @return BigNumber containing the new value
         */
        template <typename T>
        BigNumber& operator = (const T& _difBigNum)
        {
            BigNumber newNum = BigNumber(_difBigNum);
            this->numberValue = newNum.numberValue;
            return *this;
        }

        /**
         * Addition assignment operator\n
         * Assigns the sum of the current instance and _difBigNum to current instance
         * @param _difBigNum The value being added
         * @return The new value after addition and assignment
         */
        template <typename T>
        BigNumber& operator += (const T &_difBigNum)
        {
            *this = *this + BigNumber(_difBigNum);
            return *this;
        }

        /**
         * Subtraction assignment operator\n
         * Assigns the difference of the current instance and _difBigNum to current instance
         * @param _difBigNum The value being subtracted
         * @return The new value after subtraction and assignment
         */
        template <typename T>
        BigNumber &operator -= (const T &_difBigNum)
        {
            *this = *this - BigNumber(_difBigNum);
            return *this;
        }

        /**
         * Multiplication assignment operator\n
         * Assigns the product of the current instance and _difBigNum to current instance
         * @param _difBigNum The value being multiplied
         * @return The new value after multiplication and assignment
         */
        template <typename T>
        BigNumber &operator *= (const T &_difBigNum)
        {
            *this = *this * BigNumber(_difBigNum);
            return *this;
        }

        /**
         * Division assignment operator\n
         * Assigns the quotient of the current instance and _difBigNum to current instance
         * @param _difBigNum The value being divided
         * @return The new value after division and assignment
         */
        template <typename T>
        BigNumber &operator /= (const T &_difBigNum)
        {
            *this = *this / BigNumber(_difBigNum);
            return *this;
        }

        /**
         * Mod assignment operator\n
         * Assigns the remainder of the current instance and _difBigNum to current instance
         * @param _difBigNum The value being divided
         * @return The new value after division and assignment
         */
        template <typename T>
        BigNumber &operator %= (const T &_difBigNum)
        {
            *this = *this % BigNumber(_difBigNum);
            return *this;
        }

        /**
         * AND assignment operator\n
         * Assigns the AND value of the current instance and _difBigNum to current instance
         * @param _difBigNum The value being ANDed
         * @return The new value after AND and assignment
         */
        template <typename T>
        BigNumber &operator &= (const T &_difBigNum)
        {
            *this = *this & BigNumber(_difBigNum);
            return *this;
        }

        /**
        * OR assignment operator\n
         * Assigns the OR value of the current instance and _difBigNum to current instance
         * @param _difBigNum The value being ORed
         * @return The new value after OR and assignment
         */
        template <typename T>
        BigNumber &operator |= (const T &_difBigNum)
        {
            *this = *this | BigNumber(_difBigNum);
            return *this;
        }

        /**
        * XOR assignment operator\n
         * Assigns the XOR value of the current instance and _difBigNum to current instance
         * @param _difBigNum The value being XORed
         * @return The new value after XOR and assignment
         */
        template <typename T>
        BigNumber &operator ^= (const T &_difBigNum)
        {
            *this = *this ^ BigNumber(_difBigNum);
            return *this;
        }

        /**
         * Left shift assignment operator\n
         * Assigns the left shift value of the current instance and _difBigNum to current instance
         * @param _places The value being left shifted
         * @return The new value after left shift and assignment
         */
        template <typename T>
        BigNumber &operator <<= (const T &_places)
        {
            *this = *this << int(_places);
            return *this;
        }

        /**
         * Right shift assignment operator\n
         * Assigns the right shift value of the current instance and _difBigNum to current instance
         * @param _places The value right shift
         * @return The new value after right shift and assignment
         */
        template <typename T>
        BigNumber &operator >>= (const T &_places)
        {
            *this = *this % int(_places);
            return *this;
        }

        /**
         * Pre-increment operator
         * @return The incremented BigNumber
         */
        BigNumber &operator++();

        /**
         * Pre-decrement operator
         * @return The decremented BigNumber
         */
        BigNumber &operator--();

        /**
         * Post-increment operator
         * @return The pre-incremented BigNumber
         */
        const BigNumber operator++(int);

        /**
         * Post-decrement operator
         * @return The pre-decremented BigNumber
         */
        const BigNumber operator--(int);

        //@{
        /**
         * The index operator
         * @param index The position in the BigNumber digit vector
         * @return The value at the indexed position
         */
        char operator[](int index) const;
        char &operator[](int index);
        //@}



    };

    /**
     * Takes two values and returns the sum
     * @tparam T Data type of _addend1
     * @tparam U Data type of _addend2
     * @param _addend1 Value being added
     * @param _addend2 Value to add by
     * @return Sum of values as a BigNumber
     */
    template <typename T, typename U>
    BigNumber Add(const T& _addend1, const U& _addend2)
    {
        return BigNumber(_addend1) + BigNumber(_addend2);
    }

    /**
     * Takes two values and returns the difference
     * @tparam T Data type of _minuend
     * @tparam U Data type of _subtrahend
     * @param _minuend Value being subtracted
     * @param _subtrahend Value to subtract by
     * @return Difference of values as a BigNumber
     */
    template <typename T, typename U>
    BigNumber Subtract(const T& _minuend, const U& _subtrahend)
    {
        return BigNumber(_minuend) - BigNumber(_subtrahend);
    }

    /**
     * Takes two values and returns the product
     * @tparam T Data type of _multiplicand
     * @tparam U Data type of _multiplier
     * @param _multiplicand Value being multiplied
     * @param _multiplier Value to multiply by
     * @return Product of values as a BigNumber
     */
    template <typename T, typename U>
    BigNumber Multiply(const T& _multiplicand, const U& _multiplier)
    {
        return BigNumber(_multiplicand) * BigNumber(_multiplier);
    }

    /**
     * Takes two values and returns the quotient
     * @tparam T Data type of _dividend
     * @tparam U Data type of _divisor
     * @param _dividend Value being divided
     * @param _divisor Value to divide by
     * @return Quotient of values as a BigNumber
     */
    template <typename T, typename U>
    BigNumber Divide(const T& _dividend, const U& _divisor)
    {
        return BigNumber(_dividend) / BigNumber(_divisor);
    }

    /**
     * Takes two values and returns the remainder
     * @tparam T Data type of _dividend
     * @tparam U Data type of _divisor
     * @param _dividend Value being added
     * @param _divisor Value to divide by
     * @return Remainder of values as a BigNumber
     */
    template <typename T, typename U>
    BigNumber GetRemainder(const T& _dividend, const U& _divisor)
    {
        return BigNumber(_dividend) % BigNumber(_divisor);
    }

    /**
     * Increments _bigNum by _amount
     * @tparam T Data type of _bigNum
     * @tparam U Data type of _amount
     * @param _bigNum Initial BigNumber
     * @param _amount Value to increment by
     * @return The new incremented BigNumber
     */
    template <typename T, typename U>
    BigNumber Increment(BigNumber& _bigNum, const U& _amount)
    {
        _bigNum += _amount;
        return _bigNum;
    }

    /**
     * Decrements _bigNum by _amount
     * @tparam T Data type of _bigNum
     * @tparam U Data type of _amount
     * @param _bigNum Initial BigNumber
     * @param _amount Value to decrement by
     * @return The new decremented BigNumber
     */
    template <typename T, typename U>
    BigNumber Decrement(T& _bigNum, const U& _amount)
    {
        _bigNum -= _amount;
        return _bigNum;
    }

    /**
     * Takes two values and returns the larger value
     * @tparam T Data type of _bigNum1
     * @tparam U Data type of _bigNum2
     * @param _bigNum1 First value compared
     * @param _bigNum2 Second value compared
     * @return The larger value as a BigNumber
     */
    template <typename T, typename U>
    BigNumber Max(const T& _bigNum1, const U& _bigNum2)
    {
        return _bigNum1 > _bigNum2 ? BigNumber(_bigNum1) : BigNumber(_bigNum2);
    }

    /**
     * Takes two values and returns the smaller value
     * @tparam T Data type of_bigNum1
     * @tparam U Data type of _bigNum2
     * @param _bigNum1 First value compared
     * @param _bigNum2 Second value compared
     * @return The smaller value as a BigNumber
     */
    template <typename T, typename U>
    BigNumber Min(const T& _bigNum1, const U& _bigNum2)
    {
        return _bigNum1 > _bigNum2 ? BigNumber(_bigNum2) : BigNumber(_bigNum1);
    }

    /**
     * Returns the absolute value of _bigNum
     * @tparam T Data type of_bigNum
     * @param _bigNum Initial value
     * @return The absolute value as a BigNumber
     */
    template <typename T>
    BigNumber Abs(const T& _bigNum)
    {
        return BigNumber(_bigNum).Abs();
    }

    /**
     * Computes the sum of _bigNum3 and the product of the _bigNum1 and _bigNum2
     * @tparam T Data type of _bigNum1
     * @tparam U Data type of _bigNum2
     * @tparam V Data type of _bigNum3
     * @param _bigNum1 First value being added
     * @param _bigNum2 Second value being added
     * @param _bigNum3 Value to add by
     * @return The calculation results as a BigNumber
     */
    template <typename T, typename U, typename V>
    BigNumber MultAdd(const T& _bigNum1, const U& _bigNum2, const V& _bigNum3)
    {
        return (BigNumber(_bigNum1) * BigNumber(_bigNum2)) + BigNumber(_bigNum3);
    }

    /**
     * Takes two values and computes their difference
     * @tparam T Data type of _bigNum1
     * @tparam U Data type of _bigNum2
     * @param _bigNum1 First value
     * @param _bigNum2 Second Value
     * @return Absolute value of difference as a BigNumber
     */
    template <typename T, typename U>
    BigNumber Difference(const T& _bigNum1, const U& _bigNum2)
    {
        return (BigNumber(_bigNum1) - BigNumber(_bigNum2)).Abs();
    }

    /**
     * Returns if value is a valid number
     * @tparam T Data type of BigNumber
     * @param _bigNumber Initial value
     * @return True if value is a valid number, False if not
     */
    template <typename T>
    bool IsNumber(const T& _bigNumber)
    {
        BigNumber num = BigNumber(_bigNumber);
        unsigned long long int index = 0;
        if(num.IsNegative())
        {
            ++index;
        }

        std::vector<char> numVal = num.GetNumberValue();
        for(; index <= num.Digits(); ++index)
        {
            if(!isdigit(numVal[index]))
            {
                return false;
            }
        }

        return true;
    }

    /**
     * Returns if _number is of BigNumber type
     * @tparam T Data type of _number
     * @param _number Initial number
     * @return True if _number is a BigNumber, False if not
     */
    template <typename T>
    bool IsBigNumber(const T& _number)
    {
        return typeid(_number) == typeid(BigNumber);
    }

    /**
     * Returns if _bigNumber is negative
     * @tparam T Datatype of _bigNumber
     * @param _bigNumber Number being checked
     * @return True if negative, False if positive
     */
    template <typename T>
    bool IsNegative(const T& _bigNumber)
    {
        return BigNumber(_bigNumber).IsNegative();
    }

    /**
    * Returns if _bigNumber is positive
    * @tparam T Datatype of _bigNumber
    * @param _bigNumber Number being checked
    * @return True if positive, False if negitive
    */
    template <typename T>
    bool IsPositive(const T& _bigNumber)
    {
        return BigNumber(_bigNumber).IsPositive();
    }

    /**
     * Calculates Decimal representation of _binaryNumber
     * @param _binaryNum Bits representing a BigNumber
     * @return Decimal value of bits as a BigNumber
     */
    BigNumber ConvertBinaryValue(const BigNumber &_binaryNum);

}