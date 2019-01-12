/*#pragma once
 #include <gtest/gtest.h>
 #include "set.h"
 //
 TEST(SetTest, add)
 {
	Set s;
	s.add('f');
	EXPECT_EQ(s.is_in_set('f'), true);
 };
 
 TEST(SetTest, remove )
 {
	Set s;
	s.add('f');
	s.remove('f');
	EXPECT_EQ(s.is_in_set('f'), false);
 };
 
 TEST(SetTest, find_min)
 {
	Set s;
	s.add('f');
	s.add('m');
	s.add('x');
	s.add('d');
	EXPECT_EQ(s.find_min() == 'd', true);
 };
 TEST(SetTest, union_of_set)
 {
	Set s;
	Set s1;
	s1.add('f');
	s1.add('m');
	Set s2;
	s2.add('a');
	s2.add('b');
	s=s1.union_of_set(s2);
	EXPECT_EQ(s.is_in_set('f'), true);
	EXPECT_EQ(s.is_in_set('a'), true);
 };
 
 TEST(SetTest, intersection)
 {
	Set s1;
	s1.add('a');
	s1.add('m');
	s1.add('g');
	s1.add('d');
	Set s2;
	s2.add('a');
	s2.add('b');
	s2.add('m');
	s2.add('n');
	Set s;
	s=s1.intersection(s2);
	EXPECT_EQ(s.is_in_set('a'), true);
	EXPECT_EQ(s.is_in_set('m'), true);
	EXPECT_EQ(s.is_in_set('b'), false);
	EXPECT_EQ(s.is_in_set('d'), false);
 };
 
 TEST(SetTest, division)
 {
	Set s;
	Set s1;
	Set s2;
	s.add('a');
	s.add('b');
	s.add('c');
	s.add('d');
	s.add('e');
	s.add('f');
	s.add('g');
	s.add('k');
	s.division(s1, s2, 'e');
	EXPECT_EQ(s1.is_in_set('a'), true);
	EXPECT_EQ(s2.is_in_set('k'), true);
	EXPECT_EQ(s1.is_in_set('g'), false);
	EXPECT_EQ(s2.is_in_set('b'), false);
 };
 
 

*/
