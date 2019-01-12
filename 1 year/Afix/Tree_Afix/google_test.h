TEST(GetLength, CanGetLength)
{
    Postfix test("2.76 ^ 3 - 5 * 2.5");
    EXPECT_TRUE(test.convert() == "2.76  3  ^ 5  2.5  * -" && test.calculate() == (pow(2.76, 3) - 5 * 2.5));
}

TEST(GetLengtdh, CanGetLengdth)
{
    Postfix test("11 ^ 2 - 400 * 1.2");
    EXPECT_TRUE(test.convert() == "11  2  ^ 400  1.2  * -" && test.calculate() == (pow(11, 2) - 400 * 1.2));
}

TEST(GetdLength, CanGetLesngth)
{
    Postfix test("log 2 8 + cos ( 9 ) / sin ( 0.5 )");
    EXPECT_TRUE(test.convert() == " 2 8  log  9  cos sin 0.5  / +");
}

//int main(int ac, char* av[])
//{
//    testing::InitGoogleTest(&ac, av);
//    return RUN_ALL_TESTS();
//}
