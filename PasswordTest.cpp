/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, long_repeating_leading_characters_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAAAAAAAAAAAuidshbkjr32bjk23");
	ASSERT_EQ(12, actual);
}
TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}
TEST(PasswordTest, single_leading_many_trailing)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ABBBBBB");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, very_long_password_with_some_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAAAAhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823hhsukfhuisdhfuisyfui32hrv23238472hfuiheuif378823h");
	ASSERT_EQ(5, actual);
}


TEST(PasswordTest, empty_password_no_mixed)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, no_mixed_case_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("kfhwenfj");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, no_mixed_case_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("KJKJKSDKJWEKJ");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("hHhHhHhHhHhhHJHJ");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, no_mixed_case_numbers)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ggg728934784");
	ASSERT_EQ(false, actual);
}
TEST(PasswordTest, mixed_case_numbers)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("gggHJ728934784");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, only_numbers)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("728934784");
	ASSERT_EQ(false, actual);
}