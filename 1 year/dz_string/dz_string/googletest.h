/*#pragma once
 #include"../gtest/gtest.h"
 #include "string.h"
 #include "Markov.h"
 //
 TEST(StringTest, is_equal)
 {
	MyString str("1234");
	EXPECT_EQ(str == ("6576765"), false);
	EXPECT_EQ(str == ("1234"), true);
 }
 //
 TEST(StringTest, can_be_substitute)
 {
	MyString str("18fdf4");
	EXPECT_EQ(str.can_be_substitute("fdf4"), true);
	EXPECT_EQ(str.can_be_substitute("fd23"), false);
	EXPECT_EQ(str.can_be_substitute("fd1f"), false);
	EXPECT_EQ(str.can_be_substitute("18789"), false);
 }
 
 TEST(StringTest, my_strlen)
 {
	MyString str("166dfg");
	EXPECT_EQ(str.my_strlen("166dfg"), 6);
	MyString str2("12345678");
	EXPECT_EQ(str2.my_strlen("12345678"), 8);
 }
 //
 TEST(StringTest, concatination)
 {
	MyString str("166dfg");
	MyString str2("777");
	str += str2;
	EXPECT_EQ(str == ("166dfg777"), true);
 }
 
 TEST(StringTest, insert)
 {
	MyString str("mama");
	MyString str2("tato");
	str.insert(2, str2);
	EXPECT_EQ(str==("matatoma"), true);
 }
 
 
 TEST(StringTest, assign)
 {
	MyString str("abcdefg53");
	MyString str1("bcd");
	MyString str2("888777");
 str.assing(str1, str2);
	EXPECT_EQ(str==("a888777efg53"), true);
	EXPECT_EQ(str == ("ae888777fg53"), false);
 }
 
 TEST(StringTest, find_shablon)
 {
	MyString str("abcdefg53");
	MyString str2("defg");
	MyString str3("d1defg");
 
	EXPECT_EQ(str.find_shablon(str2), 3);
	EXPECT_EQ(str.find_shablon(str3), -1);
 }
 TEST(Markov, result_of_Markov_algor)
 {
 int size = 1;
	RuleString algor[2] = { RuleString("ab" , "a") };
	MyString str("aababa");
	MyString expected;
	expected =change_for_rules(str ,size, algor);
	EXPECT_EQ(expected ==("aaaa"), true);
	EXPECT_EQ(expected ==("aavd"), false);
 }
 TEST(Markov, Markov_for_my_string)
 {
	Markov markov;
	MyString str1 = "aabbccaa";
	RuleString* array = new RuleString[3];
	array[0] = RuleString("aa", "a");
	array[1] = RuleString("bb", "b");
	array[2] = RuleString("cc", "c");
	MyString expected = "abca";
	MyString result = change_for_rules(str1, 3, array);
	EXPECT_EQ(expected==result,true);
 }
 TEST(StandardMarkov, result_of_Markov_algor_in_STL_string)
 {
	int size = 2;
	string str("111+11+11");
	Rule algor[2] = { Rule("1+1" , "11+") , Rule("+","") };
	string result;
	result=change_for_rules( str ,size,algor);
 
	EXPECT_EQ(result == "1111111", true);
	EXPECT_EQ(result == "1++11", false);
 }
 
 void compareTimeOfMarkovAlgor()
 {
	cout << "\n\n\t Test time of algor Markov  \n";
	const int size = 2;
 
	long start;
	start = clock();
	RuleString algor[size] = { RuleString("1+1" , "11+") , RuleString("+","") };
 
	MyString str("111+11+11");
	MyString result;
	result = change_for_rules(str, size, algor);
 
	cout << "run time of algor Markov with my class string  : ";
	cout << clock() - start << "\n";
	long start2;
	start2 = clock();
	string str1("111+11+11");
	Rule algor1[2] = { Rule("1+1" , "11+") , Rule("+","") };
	string result1;
	result1 = change_for_rules(str1, size, algor1);
 
	cout << "run time of standard class string : ";
	cout << clock() - start2 << "\n";
 }*/
