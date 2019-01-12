/*
#pragma once
#include <gtest\gtest.h>
#include <AVL.h>
 
 TEST(AVL_Tree, TestPush_value)
{
    Tree test;
    test.push(3);
    test.push(5);
    test.push(23);
    EXPECT_TRUE(test.get_top()->value == 5);
}

TEST(AVL_Tree, TestPush)
{
    Tree test;
    for (int i = 15; i >= -15; i--)
    {
        test.push(i);
    }
    EXPECT_TRUE(test.isBalanced(test.get_top()));
}


TEST(AVL_Tree, TestBalance)
{
    Tree test;
    for (int i = 1; i <= 20; ++i)
    {
        test.push(i);
    }
    EXPECT_TRUE(test.isBalanced(test.get_top()));
}
*/
