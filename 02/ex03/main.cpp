#include "Point.hpp"

static void test(const char *name,
                 const Point &a,
                 const Point &b,
                 const Point &c,
                 const Point &point,
                 bool expected,
                 int &failures)
{
    bool result = bsp(a, b, c, point);

    std::cout << (result == expected ? "[PASS] " : "[FAIL] ")
              << name
              << " | expected: " << expected
              << ", got: " << result << '\n';

    if (result != expected)
        ++failures;
}

int main()
{
    int failures = 0;
    std::cout << std::boolalpha;

    try
    {
        const Point a(0.0f, 0.0f);
        const Point b(4.0f, 0.0f);
        const Point c(0.0f, 4.0f);

        test("Inside", a, b, c,
             Point(1.0f, 1.0f), true, failures);

        test("Outside beyond diagonal", a, b, c,
             Point(3.0f, 3.0f), false, failures);

        test("Outside below AB", a, b, c,
             Point(1.0f, -1.0f), false, failures);

        test("Outside left of CA", a, b, c,
             Point(-1.0f, 1.0f), false, failures);

        test("On edge AB", a, b, c,
             Point(2.0f, 0.0f), false, failures);

        test("On edge BC", a, b, c,
             Point(2.0f, 2.0f), false, failures);

        test("On edge CA", a, b, c,
             Point(0.0f, 2.0f), false, failures);

        test("At vertex A", a, b, c, a, false, failures);
        test("At vertex B", a, b, c, b, false, failures);
        test("At vertex C", a, b, c, c, false, failures);

        test("On extension of AB", a, b, c,
             Point(5.0f, 0.0f), false, failures);

        test("Clockwise triangle: inside", a, c, b,
             Point(1.0f, 1.0f), true, failures);

        test("Clockwise triangle: outside", a, c, b,
             Point(3.0f, 3.0f), false, failures);

        test("Collinear vertices",
             Point(0.0f, 0.0f),
             Point(2.0f, 2.0f),
             Point(4.0f, 4.0f),
             Point(1.0f, 1.0f), false, failures);

        test("Repeated vertex", a, a, c,
             Point(1.0f, 1.0f), false, failures);

        test("Negative coordinates",
             Point(-4.0f, -4.0f),
             Point(0.0f, -4.0f),
             Point(-4.0f, 0.0f),
             Point(-3.0f, -3.0f), true, failures);

        test("Fractional coordinates",
             Point(0.5f, 0.5f),
             Point(2.5f, 0.5f),
             Point(0.5f, 2.5f),
             Point(1.0f, 1.0f), true, failures);

        // One Fixed step above or below AB.
        const float step = 1.0f / 256.0f;

        test("Just inside AB", a, b, c,
             Point(1.0f, step), true, failures);

        test("Just outside AB", a, b, c,
             Point(1.0f, -step), false, failures);

        test("Just inside diagonal", a, b, c,
             Point(2.0f, 2.0f - step), true, failures);

        test("Just outside diagonal", a, b, c,
             Point(2.0f, 2.0f + step), false, failures);

        // Checks that Point's copy constructor preserves coordinates.
        const Point copiedB(b);
        test("Copied vertex", a, copiedB, c,
             Point(1.0f, 1.0f), true, failures);
    }
    catch (const std::exception &error)
    {
        std::cerr << "Unexpected exception: "
                  << error.what() << '\n';
        return 1;
    }

    std::cout << "\nFailed tests: " << failures << std::endl;
    return failures == 0 ? 0 : 1;
}