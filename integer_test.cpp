#include <gtest/gtest.h>
#include "integer.h"

using kasner::integer;

struct integer_test : public testing::Test {
    integer bi;
};

TEST_F(integer_test, isDefaultConstructedToZero) {
    auto zero_si = integer{0l};
    auto zero_ui = integer{0ul};
    auto zero_d = integer{0.0};

    EXPECT_EQ(0, bi);
    EXPECT_EQ(0, zero_si);
    EXPECT_EQ(0, zero_ui);
    EXPECT_EQ(0, zero_d);
}

TEST_F(integer_test, equal) {
    auto twenty = integer{20};
    auto other_twenty = integer{20};
    auto twenty_one = integer{21};

    EXPECT_TRUE(twenty == other_twenty);
    EXPECT_FALSE(twenty == twenty_one);
}

TEST_F(integer_test, different) {
    auto twenty = integer{20};
    auto other_twenty = integer{20};
    auto not_twenty = integer{21};

    EXPECT_FALSE(twenty != other_twenty);
    EXPECT_TRUE(twenty != not_twenty);
}

TEST_F(integer_test, greaterThan) {
    auto twenty = integer{20};
    auto twenty_one = integer{21};

    EXPECT_TRUE(twenty_one > twenty);
}

TEST_F(integer_test, lessThan) {
    auto twenty = integer{20};
    auto twenty_one = integer{21};

    EXPECT_TRUE(twenty < twenty_one);
}

TEST_F(integer_test, greaterThanOrEqual) {
    auto twenty = integer{20};
    auto twenty_one = integer{21};

    EXPECT_TRUE(twenty_one >= twenty);
}

TEST_F(integer_test, lessThanOrEqual) {
    auto twenty = integer{20};
    auto twenty_one = integer{21};

    EXPECT_TRUE(twenty <= twenty_one);
}

TEST_F(integer_test, assignFundamental) {
    auto twenty = integer{20};

    twenty = -20;
    EXPECT_EQ(-20, twenty);

    twenty = 20;
    EXPECT_EQ(20, twenty);

    twenty = -20.0;
    EXPECT_EQ(-20, twenty);
}

TEST_F(integer_test, assignCopy) {
    auto twenty = integer{20};
    auto minus_twenty = integer{-20};
    twenty = minus_twenty;

    EXPECT_EQ(minus_twenty, twenty);
}

TEST_F(integer_test, assignMove) {
    auto twenty = integer{20};
    auto minus_twenty = integer{-20};
    twenty = std::move(minus_twenty);

    EXPECT_EQ(-20, twenty);
}

TEST_F(integer_test, swap) {
    auto twenty = integer{20};
    auto minus_twenty = integer{-20};
    std::swap(twenty, minus_twenty);

    EXPECT_EQ(-20, twenty);
}

TEST_F(integer_test, negate) {
    auto twenty = integer{20};
    auto minus_twenty = integer{-20};

    EXPECT_EQ(minus_twenty, -twenty);
}

TEST_F(integer_test, addition) {
    auto twenty = integer{20};
    auto fifty = integer{50};
    auto seventy = integer{70};

    EXPECT_EQ(seventy, twenty + fifty);
}

TEST_F(integer_test, subtraction) {
    auto twenty = integer{20};
    auto fifty = integer{50};
    auto minus_thirty = integer{-30};
    auto thirty = integer{30};

    EXPECT_EQ(minus_thirty, twenty - fifty);
    EXPECT_EQ(thirty, fifty - twenty);
}

TEST_F(integer_test, multiplication) {
    auto twenty = integer{20};
    auto fifty = integer{50};
    auto thousand = integer{1000};

    EXPECT_EQ(thousand, twenty * fifty);
}

TEST_F(integer_test, division) {
    auto twenty = integer{20};
    auto fifty = integer{50};
    auto thousand = integer{1000};

    EXPECT_EQ(twenty, thousand / fifty);
}

TEST_F(integer_test, modulus) {
    auto ten = integer{10};
    auto twenty = integer{20};
    auto fifty = integer{50};

    EXPECT_EQ(ten, fifty % twenty);
}

TEST_F(integer_test, power) {
    auto two = integer{2};
    auto one_mega = integer{1048576};

    EXPECT_EQ(one_mega, two.pow(20));
}

TEST_F(integer_test, increment) {
    auto twenty = integer{20};
    auto other_twenty = twenty;
    auto twenty_one = integer{21};
    auto twenty_two = integer{22};

    EXPECT_EQ(other_twenty, twenty++);
    EXPECT_EQ(twenty_one, twenty);
    EXPECT_EQ(twenty_two, ++twenty);
    EXPECT_EQ(twenty_two, twenty);
}

TEST_F(integer_test, decrement) {
    auto twenty = integer{20};
    auto other_twenty = twenty;
    auto nineteen = integer{19};
    auto eighteen = integer{18};

    EXPECT_EQ(other_twenty, twenty--);
    EXPECT_EQ(nineteen, twenty);
    EXPECT_EQ(eighteen, --twenty);
    EXPECT_EQ(eighteen, twenty);
}

TEST_F(integer_test, booleanCast) {
    auto zero = integer{0};
    auto twenty = integer{20};

    EXPECT_FALSE(!twenty);
    EXPECT_TRUE(!zero);
}

TEST_F(integer_test, bitAnd) {
    auto twenty_one = integer{21}; // 10101
    auto twenty_two = integer{22}; // 10110
    auto twenty = integer{20};     // 10100

    EXPECT_EQ(twenty, twenty_one & twenty_two);
}

TEST_F(integer_test, bitOr) {
    auto twenty_one = integer{21};   // 10101
    auto twenty_two = integer{22};   // 10110
    auto twenty_three = integer{23}; // 10111

    EXPECT_EQ(twenty_three, twenty_one | twenty_two);
}

TEST_F(integer_test, bitXor) {
    auto twenty_one = integer{21}; // 10101
    auto twenty_two = integer{22}; // 10110
    auto three = integer{3};       // 00011

    EXPECT_EQ(three, twenty_one ^ twenty_two);
}

TEST_F(integer_test, bitLeftShift) {
    auto twenty_one = integer{21};  // 10101
    auto eighty_four = integer{84}; // 1010100

    EXPECT_EQ(eighty_four, twenty_one << 2);
}

TEST_F(integer_test, bitRightShift) {
    auto twenty_one = integer{21};  // 10101
    auto five = integer{5}; // 101

    EXPECT_EQ(five, twenty_one >> 2);
}

TEST_F(integer_test, bitComplement) {
    auto twenty = integer{20};            // 10101
    auto minus_twenty_one = integer{-21}; // 10101

    EXPECT_EQ(minus_twenty_one, ~twenty);
}

TEST_F(integer_test, intCasting) {
    auto twenty = integer{20};
    int twenty_int = static_cast<int>(twenty);

    EXPECT_EQ(20, twenty_int);
}

TEST_F(integer_test, uintCasting) {
    auto twenty = integer{20};
    int twenty_uint = static_cast<unsigned int>(twenty);

    EXPECT_EQ(20, twenty_uint);
}

TEST_F(integer_test, doubleCasting) {
    auto twenty = integer{20};
    auto twenty_dbl = double(twenty);

    EXPECT_DOUBLE_EQ(20.0, twenty_dbl);
}

TEST_F(integer_test, stringCasting) {
    auto twenty = integer{20};
    auto twenty_str = std::string(twenty);

    EXPECT_EQ("20", twenty_str);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
