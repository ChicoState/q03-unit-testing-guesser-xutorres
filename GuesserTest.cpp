/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};


// Test case for Guesser::match method with exact match
TEST(GuesserTest, MatchExactMatch) {
    Guesser guesser("secret");
    EXPECT_TRUE(guesser.match("secret"));
}

// Test case for Guesser::match method with one character difference
TEST(GuesserTest, MatchOneCharDifference) {
    Guesser guesser("secret");
    EXPECT_FALSE(guesser.match("secrey"));
}

// Test case for Guesser::match method with longer guess
TEST(GuesserTest, MatchLongerGuess) {
    Guesser guesser("secret");
    EXPECT_FALSE(guesser.match("secrett"));
}

// Test case for Guesser::match method with more than 2 characters difference
TEST(GuesserTest, MatchTooManyCharsDifferent) {
    Guesser guesser("secret");
    EXPECT_FALSE(guesser.match("secrecy"));
}

// Test case for Guesser::match method with too short guess
TEST(GuesserTest, MatchTooShortGuess) {
    Guesser guesser("secret");
    EXPECT_FALSE(guesser.match("sec"));
}

// Test case for Guesser::remaining method after initial guesses
TEST(GuesserTest, RemainingInitialGuesses) {
    Guesser guesser("secret");
    EXPECT_EQ(guesser.remaining(), 3);
}

// Test case for Guesser::remaining method after one incorrect guess
TEST(GuesserTest, RemainingOneIncorrectGuess) {
    Guesser guesser("secret");
    guesser.match("secrecy");
    EXPECT_EQ(guesser.remaining(), 2);
}

// Test case for Guesser::remaining method after two incorrect guesses
TEST(GuesserTest, RemainingTwoIncorrectGuesses) {
    Guesser guesser("secret");
    guesser.match("secrecy");
    guesser.match("secrecy");
    EXPECT_EQ(guesser.remaining(), 1);
}

// Test case for Guesser::remaining method after maximum incorrect guesses
TEST(GuesserTest, RemainingMaxGuessesReached) {
    Guesser guesser("secret");
    guesser.match("secrecy");
    guesser.match("secrecy");
    guesser.match("secrecy");
    EXPECT_EQ(guesser.remaining(), 0);
}

// Test case for Guesser::remaining method after secret is locked
TEST(GuesserTest, RemainingLockedSecret) {
    Guesser guesser("secret");
    guesser.match("secrecy");
    guesser.match("secrecy");
    guesser.match("secrecy");
    EXPECT_FALSE(guesser.match("secret"));
    EXPECT_EQ(guesser.remaining(), 0);
}

// Test case for Guesser constructor for an empty string
TEST(GuesserTest, EmptyString) {
    EXPECT_NO_THROW({
        Guesser guesser("");
        EXPECT_TRUE(guesser.match(""));
    });
}

// Test case for Guesser::match method after secret is locked by brute force
TEST(GuesserTest, BruteForceLock) {
    Guesser guesser("secret");
    guesser.match("very_wrong");
    EXPECT_FALSE(guesser.match("secret"));
}

// Test case for Guesser constructor after a secret of more than 32 is passed
TEST(GuesserTest, SecretOver32Char) {
    Guesser guesser("abcdefghijklmnopqrstuvwxyz0123456789");
    EXPECT_TRUE(guesser.match("abcdefghijklmnopqrstuvwxyz012345"));
}





