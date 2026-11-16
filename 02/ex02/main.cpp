
#include "Fixed.hpp"
#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <string>

/*

static int passed = 0;
static int failed = 0;

void check(bool condition, const std::string &name)
{
    if (condition)
    {
        ++passed;
        std::cout << "[PASS] " << name << std::endl;
    }
    else
    {
        ++failed;
        std::cout << "[FAIL] " << name << std::endl;
    }
}

bool closeEnough(float a, float b)
{
    return std::fabs(a - b) < 0.00001f;
}

void title(const std::string &name)
{
    std::cout << "\n========== " << name
              << " ==========" << std::endl;
}

void testConstructors()
{
    title("CONSTRUCTORS AND CONVERSIONS");

    Fixed a;
    check(a.getRawBits() == 0, "Default constructor");

    Fixed b(42);
    check(b.getRawBits() == 42 * 256, "Integer constructor");
    check(b.toInt() == 42, "Integer conversion");
    check(closeEnough(b.toFloat(), 42.0f), "Float conversion");

    Fixed c(-42);
    check(c.toInt() == -42, "Negative integer");

    Fixed d(3.14f);
    check(d.getRawBits() == 804, "Float 3.14 raw value");
    check(closeEnough(d.toFloat(), 3.140625f),
          "Float 3.14 conversion");

    Fixed e(-3.14f);
    check(e.getRawBits() == -804, "Negative float");

    Fixed f(0.5f);
    check(f.getRawBits() == 128, "Float 0.5");

    Fixed g(-0.5f);
    check(g.getRawBits() == -128, "Float -0.5");

    Fixed h(0.0f);
    check(h.getRawBits() == 0, "Zero");

    Fixed i(-0.0f);
    check(i.getRawBits() == 0, "Negative zero");

    Fixed copy(d);
    check(copy == d, "Copy constructor");

    Fixed assigned;
    assigned = e;
    check(assigned == e, "Copy assignment");

    assigned = assigned;
    check(assigned == e, "Self assignment");

    Fixed truncPositive(3.99f);
    Fixed truncNegative(-3.99f);
    check(truncPositive.toInt() == 3, "toInt truncates positive");
    check(truncNegative.toInt() == -3, "toInt truncates negative");

    Fixed small(0.001f);
    check(small.getRawBits() == 0, "Tiny positive rounds to zero");

    Fixed smallNegative(-0.001f);
    check(smallNegative.getRawBits() == 0,
          "Tiny negative rounds to zero");
}

void testIntegerLimits()
{
    title("INTEGER CONSTRUCTOR LIMITS");

    Fixed maximum(8388607);
    check(maximum.getRawBits() == INT_MAX - 255,
          "Largest valid positive integer");

    Fixed minimum(-8388608);
    check(minimum.getRawBits() == INT_MIN,
          "Smallest valid negative integer");

    try
    {
        Fixed x(8388608);
        (void)x;
        check(false, "Positive integer overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Positive integer overflow");
    }
    catch (...)
    {
        check(false, "Positive integer overflow wrong exception");
    }

    try
    {
        Fixed x(-8388609);
        (void)x;
        check(false, "Negative integer overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Negative integer overflow");
    }
    catch (...)
    {
        check(false, "Negative integer overflow wrong exception");
    }

    try
    {
        Fixed x(INT_MAX);
        (void)x;
        check(false, "INT_MAX constructor overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "INT_MAX constructor overflow");
    }
    catch (...)
    {
        check(false, "INT_MAX constructor wrong exception");
    }

    try
    {
        Fixed x(INT_MIN);
        (void)x;
        check(false, "INT_MIN constructor overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "INT_MIN constructor overflow");
    }
    catch (...)
    {
        check(false, "INT_MIN constructor wrong exception");
    }
}

void testFloatLimits()
{
    title("FLOAT CONSTRUCTOR LIMITS");

    try
    {
        Fixed x(1e20f);
        (void)x;
        check(false, "Huge positive float overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Huge positive float overflow");
    }
    catch (...)
    {
        check(false, "Huge positive float wrong exception");
    }

    try
    {
        Fixed x(-1e20f);
        (void)x;
        check(false, "Huge negative float overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Huge negative float overflow");
    }
    catch (...)
    {
        check(false, "Huge negative float wrong exception");
    }

    try
    {
        Fixed x(std::numeric_limits<float>::infinity());
        (void)x;
        check(false, "Positive infinity rejected");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Positive infinity rejected");
    }
    catch (...)
    {
        check(false, "Positive infinity wrong exception");
    }

    try
    {
        Fixed x(-std::numeric_limits<float>::infinity());
        (void)x;
        check(false, "Negative infinity rejected");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Negative infinity rejected");
    }
    catch (...)
    {
        check(false, "Negative infinity wrong exception");
    }

    try
    {
        Fixed x(std::numeric_limits<float>::quiet_NaN());
        (void)x;
        check(false, "NaN rejected");
    }
    catch (const std::overflow_error &)
    {
        check(true, "NaN rejected");
    }
    catch (...)
    {
        check(false, "NaN wrong exception");
    }

    // This should succeed: -8388608 * 256 == INT_MIN.
    try
    {
        Fixed x(-8388608.0f);
        check(x.getRawBits() == INT_MIN,
              "Float exact negative boundary");
    }
    catch (...)
    {
        check(false, "Float exact negative boundary");
    }

    // The next representable float above 8388608.0f
    // is not needed to test the positive overflow boundary.
    try
    {
        Fixed x(8388608.0f);
        (void)x;
        check(false, "Float positive boundary overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Float positive boundary overflow");
    }
    catch (...)
    {
        check(false, "Float positive boundary wrong exception");
    }
}

void testComparisons()
{
    title("COMPARISON OPERATORS");

    Fixed a(10);
    Fixed b(20);
    Fixed c(10);

    check(a < b, "Less than");
    check(b > a, "Greater than");
    check(a <= b, "Less or equal");
    check(a <= c, "Less or equal when equal");
    check(b >= a, "Greater or equal");
    check(a >= c, "Greater or equal when equal");
    check(a == c, "Equality");
    check(a != b, "Inequality");
    check(!(a != c), "Inequality false");
    check(!(a == b), "Equality false");

    Fixed negative(-10);
    Fixed zero(0);
    check(negative < zero, "Negative less than zero");
    check(zero < a, "Zero less than positive");
}

void testArithmetic()
{
    title("ARITHMETIC OPERATORS");

    Fixed a(10);
    Fixed b(3);

    check((a + b).toInt() == 13, "Addition");
    check((a - b).toInt() == 7, "Subtraction");
    check((a * b).toInt() == 30, "Multiplication");
    check(closeEnough((a / b).toFloat(), 3.33203125f),
          "Division 10 / 3");

    Fixed negative(-3);
    check((a + negative).toInt() == 7,
          "Addition with negative");
    check((negative - a).toInt() == -13,
          "Negative subtraction");
    check((negative * b).toInt() == -9,
          "Negative multiplication");
    check((negative / b).toInt() == -1,
          "Negative division");

    Fixed zero(0);
    check((a + zero) == a, "Add zero");
    check((a - zero) == a, "Subtract zero");
    check((a * zero) == zero, "Multiply by zero");
    check((zero / a) == zero, "Zero divided by nonzero");

    Fixed half(0.5f);
    check(closeEnough((half * half).toFloat(), 0.25f),
          "Fraction multiplication");
    check(closeEnough((half / half).toFloat(), 1.0f),
          "Fraction division");

    Fixed small;
    small.setRawBits(1);
    check((small * small).getRawBits() == 0,
          "Multiplication rounds tiny result to zero");

    Fixed one(1);
    check((small / one).getRawBits() == 1,
          "Smallest raw value divided by one");
}

void testArithmeticOverflow()
{
    title("ARITHMETIC OVERFLOW");

    Fixed maximum;
    maximum.setRawBits(INT_MAX);

    Fixed minimum;
    minimum.setRawBits(INT_MIN);

    Fixed oneRaw;
    oneRaw.setRawBits(1);

    try
    {
        Fixed x = maximum + oneRaw;
        (void)x;
        check(false, "Addition positive overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Addition positive overflow");
    }
    catch (...)
    {
        check(false, "Addition wrong exception");
    }

    try
    {
        Fixed x = minimum - oneRaw;
        (void)x;
        check(false, "Subtraction negative overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Subtraction negative overflow");
    }
    catch (...)
    {
        check(false, "Subtraction wrong exception");
    }

    try
    {
        Fixed x = maximum * Fixed(2);
        (void)x;
        check(false, "Multiplication overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Multiplication overflow");
    }
    catch (...)
    {
        check(false, "Multiplication wrong exception");
    }

    try
    {
        Fixed x = maximum / oneRaw;
        (void)x;
        check(false, "Division overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Division overflow");
    }
    catch (...)
    {
        check(false, "Division overflow wrong exception");
    }

    try
    {
        Fixed x = Fixed(10) / Fixed(0);
        (void)x;
        check(false, "Division by zero");
    }
    catch (const std::domain_error &)
    {
        check(true, "Division by zero");
    }
    catch (...)
    {
        check(false, "Division by zero wrong exception");
    }

    // These are valid operations at the raw-value boundaries.
    check((maximum + Fixed(0)).getRawBits() == INT_MAX,
          "Addition exactly INT_MAX");
    check((minimum - Fixed(0)).getRawBits() == INT_MIN,
          "Subtraction exactly INT_MIN");
}

void testIncrementDecrement()
{
    title("INCREMENT AND DECREMENT");

    Fixed a(1);
    int original = a.getRawBits();

    Fixed before = a++;
    check(before.getRawBits() == original,
          "Post-increment returns old value");
    check(a.getRawBits() == original + 1,
          "Post-increment changes object");

    Fixed &ref = ++a;
    check(a.getRawBits() == original + 2,
          "Pre-increment changes object");
    check(&ref == &a, "Pre-increment returns reference");

    before = a--;
    check(before.getRawBits() == original + 2,
          "Post-decrement returns old value");
    check(a.getRawBits() == original + 1,
          "Post-decrement changes object");

    Fixed &decRef = --a;
    check(a.getRawBits() == original,
          "Pre-decrement changes object");
    check(&decRef == &a,
          "Pre-decrement returns reference");

    Fixed maximum;
    maximum.setRawBits(INT_MAX);

    try
    {
        ++maximum;
        check(false, "Pre-increment overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Pre-increment overflow");
    }
    catch (...)
    {
        check(false, "Pre-increment wrong exception");
    }

    check(maximum.getRawBits() == INT_MAX,
          "Failed pre-increment preserves value");

    try
    {
        maximum++;
        check(false, "Post-increment overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Post-increment overflow");
    }
    catch (...)
    {
        check(false, "Post-increment wrong exception");
    }

    Fixed minimum;
    minimum.setRawBits(INT_MIN);

    try
    {
        --minimum;
        check(false, "Pre-decrement overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Pre-decrement overflow");
    }
    catch (...)
    {
        check(false, "Pre-decrement wrong exception");
    }

    try
    {
        minimum--;
        check(false, "Post-decrement overflow");
    }
    catch (const std::overflow_error &)
    {
        check(true, "Post-decrement overflow");
    }
    catch (...)
    {
        check(false, "Post-decrement wrong exception");
    }
}

void testMinMax()
{
    title("MIN AND MAX");

    Fixed a(10);
    Fixed b(20);
    Fixed equal(10);

    check(Fixed::min(a, b) == a, "Min normal");
    check(Fixed::max(a, b) == b, "Max normal");
    check(Fixed::min(b, a) == a, "Min reversed");
    check(Fixed::max(b, a) == b, "Max reversed");

    Fixed negative(-10);
    check(Fixed::min(negative, a) == negative,
          "Min with negative");
    check(Fixed::max(negative, a) == a,
          "Max with negative");

    check(Fixed::min(a, equal) == a,
          "Min equal values");
    check(Fixed::max(a, equal) == a,
          "Max equal values");

    Fixed &minRef = Fixed::min(a, b);
    Fixed &maxRef = Fixed::max(a, b);

    check(&minRef == &a, "Min returns reference");
    check(&maxRef == &b, "Max returns reference");

    const Fixed ca(5);
    const Fixed cb(8);

    const Fixed &cmin = Fixed::min(ca, cb);
    const Fixed &cmax = Fixed::max(ca, cb);

    check(&cmin == &ca, "Const min overload");
    check(&cmax == &cb, "Const max overload");

    // Check that non-const min really returns a modifiable reference.
    Fixed::min(a, b) = Fixed(7);
    check(a.toInt() == 7, "Min reference is modifiable");
}

void testStream()
{
    title("STREAM INSERTION");

    Fixed a(3.5f);
    std::cout << "Fixed(3.5f) prints: " << a << std::endl;
    check(closeEnough(a.toFloat(), 3.5f),
          "Stream test value");

    Fixed negative(-2.25f);
    std::cout << "Fixed(-2.25f) prints: "
              << negative << std::endl;
}

int main()
{
    std::cout << "CPP02 EX02 - FIXED CLASS TESTS\n";

    testConstructors();
    testIntegerLimits();
    testFloatLimits();
    testComparisons();
    testArithmetic();
    testArithmeticOverflow();
    testIncrementDecrement();
    testMinMax();
    testStream();

    title("FINAL RESULTS");

    std::cout << "Passed: " << passed << std::endl;
    std::cout << "Failed: " << failed << std::endl;
    std::cout << "Total:  " << passed + failed << std::endl;

    return failed == 0 ? 0 : 1;
}
    */
int main()
{
    std::cout << std::fixed << std::setprecision(1);

    Fixed a(8388607.5f);
    std::cout << a.toFloat() << std::endl;
    std::cout << a.getRawBits() << std::endl;

    Fixed a1(-8388608.0f);
    std::cout << a1.toFloat() << std::endl;
    std::cout << a1.getRawBits() << std::endl;
    
    try
    {
        Fixed b(524.5f);
        std::cout << a + b << std::endl;
    }
    catch (const std::overflow_error &e)
    {
        std::cout << "Cought: " << e.what() << std::endl;
    }

    try
    {
        Fixed a2(8388608.0f);
        std::cout << a2.toFloat() << std::endl;
        std::cout << a2.getRawBits() << std::endl;

    }
    catch (const std::overflow_error &e)
    {
        std::cout << "Cought: " << e.what() << std::endl;
    }
    try
    {
        Fixed a3(-8388609.0f);
        std::cout << a3.toFloat() << std::endl;
        std::cout << a3.getRawBits() << std::endl;
    }
    catch (const std::overflow_error &e)
    {
        std::cout << "Cought: " << e.what() << std::endl;
    }
    return 0;
}
