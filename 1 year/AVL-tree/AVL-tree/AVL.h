#pragma once 
#include <iostream>
//#include <gtest\gtest.h>
using namespace std;
struct Node
{
    int value;
    Node* left;
    Node* right;
    Node* root;
    int balance;
    
    Node() :
    value(),
    root(nullptr),
    left(nullptr),
    right(nullptr),
    balance(0)
    {
    }
    
    Node(int val, Node* father) :
    value(val),
    root(father),
    left(nullptr),
    right(nullptr),
    balance(0)
    {
    }
};

class AVL
{
public:
    Node* top;//creates a root
public:
    AVL() :
    top(nullptr)
    {
    }
    
    ~AVL()
    {
        if (top != nullptr)
        {
            destroy_tree(top);
        }
    }
    
    void destroy_tree(Node* node)
    {
        if (node->right != nullptr)
        {
            destroy_tree(node->right);
        }
        if (node->left != nullptr)
        {
            destroy_tree(node->left);
        }
        delete node;
    }
    
    int height(Node* node)
    {
        int result = 0;
        if (node != nullptr)
        {
            result = 1 + ((height(node->right) > height(node->left)) ? height(node->right) : height(node->left));
            //? 1:2 (true return 1 , false return 2)
        }
        return result;
    }
    
    void calculate_balance(Node* node)
    {
        node->balance = height(node->right) - height(node->left);
        //compares the heights of sons to determine the balance.balance should always be equal to 1 or 0
    }
    
    void rebalance(Node* node)
    {
        calculate_balance(node);
        if (node->balance == 2)
        {
            if (height(node->right->right) >= height(node->right->left))
            {
                node = to_left(node);
            }
            else
            {
                node->right = to_right(node->right);
                node = to_left(node);
            }
        }
        else if (node->balance == -2)
        {
            if (height(node->left->left) >= height(node->left->right))
            {
                node = to_right(node);
            }
            else
            {
                node->left = to_left(node->left);
                node = to_right(node);
            }
        }
        if (node->root != nullptr)
        {
            rebalance(node->root);
        }
        else
        {
            top = node;
        }
    }
    
    Node* to_left(Node* a)
    {
        Node *b = a->right;
        b->root = a->root;
        a->right = b->left;
        if (a->right != nullptr)
        {
            a->right->root = a;
        }
        b->left = a;
        a->root = b;
        if (b->root != nullptr)
        {
            if (b->root->right == a)
            {
                b->root->right = b;
            }
            else
            {
                b->root->left = b;
            }
        }
        calculate_balance(a);
        calculate_balance(b);
        return b;
    }
    
    Node* to_right(Node* a)
    {
        Node *b = a->left;
        b->root = a->root;
        a->left = b->right;
        if (a->left != nullptr)
        {
            a->left->root = a;
        }
        b->right = a;
        a->root = b;
        if (b->root != nullptr)
        {
            if (b->root->right == a)
            {
                b->root->right = b;
            }
            else
            {
                b->root->left = b;
            }
        }
        calculate_balance(a);
        calculate_balance(b);
        return b;
    }

    bool is_balanced(Node* node)//recursivly
    {
        bool balanced = false;
        if (node->right != nullptr)
        {
            balanced = is_balanced(node->right);
        }
        if (node->left != nullptr)
        {
            balanced = is_balanced(node->left);
        }
        if (abs(node->balance) <= 1)
        {
            balanced = true;
        }
        else
        {
            balanced = false;
        }
        return balanced;
    }
    
    void add(int val)
    {
        if (top == nullptr)
        {
            top = new Node(val, nullptr);
        }
        else
        {
            Node* element = top;
            Node* parent;
            while (true)
            {
                parent = element;
                bool add_left = (element->value > val);
                element = (add_left) ? element->left : element->right;
                
                if (element == nullptr)
                {
                    if (add_left)
                    {
                        parent->left = new Node(val, parent);
                    }
                    else
                    {
                        parent->right = new Node(val, parent);
                    }
                    
                    rebalance(parent);
                    //after adding  a new element we must calculate the balance for the perent again, cause it could change
                    break;
                }
            }
        }
    }
    
    void delete_node(int val)
    {
        if (top == nullptr)
        {
            throw "Tree is empty";
        }
        Node* node = top;
        Node* parent = top;
        Node* del_node = nullptr;
        Node* child = top;
        while (child != nullptr)
        {
            parent = node;
            node = child;
            child = (val >= node->value) ? node->right : node->left;
            if (val == node->value)
            {
                del_node = node;
            }
        }
        if (del_node != nullptr)
        {
            del_node->value = node->value;
            child = (node->left != nullptr) ? node->left : node->right;
            if (top->value == val)
            {
                top = child;
            }
            else
            {
                if (parent->left == node)
                {
                    parent->left = child;
                }
                else
                {
                    parent->right = child;
                }
                rebalance(parent);
            }
        }
        delete node;
    }
    
    Node* get_top()
    {
        return top;
    }
    
//    void preorder(Node* p)
//    {
//        if (p!=NULL)
//        {
//            cout<<p->value<<"\t";
//            preorder(p->left);
//            preorder(p->right);
//        }
//    }
//    void inorder(Node* p)
//    {
//        if (p!=NULL)
//        {
//            inorder(p->left);
//            cout<<p->value<<"\t";
//            inorder(p->right);
//        }
//    }
//    void postorder(Node* p)
//    {
//        if (p!=NULL)
//        {
//            postorder(p->left);
//            postorder(p->right);
//            cout<<p->value<<"\t";
//        }
//    }
};
