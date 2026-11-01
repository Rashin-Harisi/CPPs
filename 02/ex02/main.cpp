#include "Fixed.hpp"

/*
int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
*/

void check(const char *name, bool condition)
{
    std::cout << (condition ? "[PASS] " : "[FAIL] ")
              << name << std::endl;
}

void testComparisons()
{
    Fixed a(2);
    Fixed b(3);
    Fixed same(2);

    check("operator <", a < b && !(b < a));
    check("operator >", b > a && !(a > b));
    check("operator <=", a <= b && a <= same && !(b <= a));
    check("operator >=", b >= a && a >= same && !(a >= b));
    check("operator ==", a == same && !(a == b));
    check("operator !=", a != b && !(a != same));
}

void testArithmetic()
{
    Fixed a(5.5f);
    Fixed b(2);

    check("operator +", (a + b) == Fixed(7.5f));
    check("operator -", (a - b) == Fixed(3.5f));
    check("operator *", (a * b) == Fixed(11));
    check("operator /", (a / b) == Fixed(2.75f));

    check("negative multiplication",
          (Fixed(-1.5f) * b) == Fixed(-3));
    check("negative division",
          (Fixed(-5.5f) / b) == Fixed(-2.75f));

    check("operands remain unchanged",
          a == Fixed(5.5f) && b == Fixed(2));

    // Raw result is exactly halfway between two representable values.
    Fixed small;
    small.setRawBits(3);
    check("positive multiplication rounding",
          (small * Fixed(0.5f)).getRawBits() == 2);

    small.setRawBits(-3);
    check("negative multiplication rounding",
          (small * Fixed(0.5f)).getRawBits() == -2);

    small.setRawBits(3);
    check("positive division rounding",
          (small / Fixed(2)).getRawBits() == 2);

    small.setRawBits(-3);
    check("negative division rounding",
          (small / Fixed(2)).getRawBits() == -2);
}

void testIncrementDecrement()
{
    Fixed a(1);
    Fixed &incremented = ++a;

    check("prefix ++ changes raw value by one",
          a.getRawBits() == 257);
    check("prefix ++ returns the same object",
          &incremented == &a);

    Fixed previous = a++;
    check("postfix ++ returns previous value",
          previous.getRawBits() == 257);
    check("postfix ++ updates original",
          a.getRawBits() == 258);

    Fixed &decremented = --a;
    check("prefix -- changes raw value by one",
          a.getRawBits() == 257);
    check("prefix -- returns the same object",
          &decremented == &a);

    previous = a--;
    check("postfix -- returns previous value",
          previous.getRawBits() == 257);
    check("postfix -- updates original",
          a.getRawBits() == 256);
}

void testMinMax()
{
    Fixed a(2);
    Fixed b(5);

    check("mutable min returns reference to smaller object",
          &Fixed::min(a, b) == &a);
    check("mutable max returns reference to larger object",
          &Fixed::max(a, b) == &b);

    Fixed::min(a, b).setRawBits(256);
    check("mutable min allows modifying selected object",
          a == Fixed(1));

    const Fixed c(-2);
    const Fixed d(4);

    check("const min returns reference to smaller object",
          &Fixed::min(c, d) == &c);
    check("const max returns reference to larger object",
          &Fixed::max(c, d) == &d);

    check("mixed const and mutable arguments",
          &Fixed::min(a, c) == &c);

    Fixed same(1);
    check("min with equal values", Fixed::min(a, same) == a);
    check("max with equal values", Fixed::max(a, same) == a);
}

void testErrors()
{
    Fixed highest;
    Fixed lowest;
    Fixed step;
    Fixed zero;

    highest.setRawBits(INT_MAX);
    lowest.setRawBits(INT_MIN);
    step.setRawBits(1);

    try
    {
        Fixed result = highest + step;
        (void)result;
        check("addition overflow throws", false);
    }
    catch (const std::overflow_error &error)
    {
        check("addition overflow throws", true);
        std::cout << "  " << error.what() << std::endl;
    }

    try
    {
        Fixed result = lowest - step;
        (void)result;
        check("subtraction overflow throws", false);
    }
    catch (const std::overflow_error &error)
    {
        check("subtraction overflow throws", true);
        std::cout << "  " << error.what() << std::endl;
    }

    try
    {
        Fixed result = highest * Fixed(2);
        (void)result;
        check("multiplication overflow throws", false);
    }
    catch (const std::overflow_error &error)
    {
        check("multiplication overflow throws", true);
        std::cout << "  " << error.what() << std::endl;
    }

    try
    {
        Fixed result = highest / Fixed(0.5f);
        (void)result;
        check("division overflow throws", false);
    }
    catch (const std::overflow_error &error)
    {
        check("division overflow throws", true);
        std::cout << "  " << error.what() << std::endl;
    }

    try
    {
        Fixed result = step / zero;
        (void)result;
        check("division by zero throws", false);
    }
    catch (const std::domain_error &error)
    {
        check("division by zero throws", true);
        std::cout << "  " << error.what() << std::endl;
    }

    try
    {
        ++highest;
        check("prefix increment overflow throws", false);
    }
    catch (const std::overflow_error &)
    {
        check("prefix increment overflow throws", true);
    }

    try
    {
        highest++;
        check("postfix increment overflow throws", false);
    }
    catch (const std::overflow_error &)
    {
        check("postfix increment overflow throws", true);
    }

    try
    {
        --lowest;
        check("prefix decrement overflow throws", false);
    }
    catch (const std::overflow_error &)
    {
        check("prefix decrement overflow throws", true);
    }

    try
    {
        lowest--;
        check("postfix decrement overflow throws", false);
    }
    catch (const std::overflow_error &)
    {
        check("postfix decrement overflow throws", true);
    }

    check("failed operations preserve original values",
          highest.getRawBits() == INT_MAX
          && lowest.getRawBits() == INT_MIN);
}

int main()
{
    try
    {
        std::cout << std::boolalpha;

        Fixed original(2.5f);
        Fixed copied(original);
        Fixed assigned;
        assigned = original;

        check("copy constructor", copied == original);
        check("copy assignment", assigned == original);

        copied.setRawBits(0);
        check("copies are independent", original == Fixed(2.5f));

        std::cout << "Stream insertion: expected 2.5, got "
                  << original << std::endl;

        testComparisons();
        testArithmetic();
        testIncrementDecrement();
        testMinMax();
        testErrors();
    }
    catch (const std::exception &error)
    {
        std::cerr << "Unexpected exception: "
                  << error.what() << std::endl;
        return 1;
    }

    return 0;
}