//int main() {
//    char *y="yes";
//    char *s=new char(3);
//    for(int i=0;i<3;i++)
//    {
//        s[i]=*(y+i);
//    }
//    cout<<s;
//    delete s;
//    return 0;
//}

//int l(int *n)
//{
//    *n=3;
//    return *n+10;
//}
//int main()
//{
//    int x=1;
//    x=l(&x);
//    cout<<x;
//    return 0;
//}
//13

//class A
//{
//public:
//    A(){cout<<"A";}
//    ~A(){cout<<"~A";}
//};
//class B:public A
//{
//public:
//    B(){cout<<"B";}
//    ~B(){cout<<"~B";}
//};
//class C:public B
//{
//public:
//    C(){cout<<"C";}
//    ~C(){cout<<"~C";}
//};
//class D: public B,public A,public C
//{
//public:
//    D(){cout<<"D";}
//    ~D(){cout<<"~D";}
//};
//int main()
//{
//    D d;
//    return 0;
//    return 0;
//}
//ABAABCD~D~C~B~A~A~B~A

//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//    void f() { };
//};
//class B:public A
//{
//public:
//    
//};
//class C:public A
//{
//public:
//    
//};
//class D:public B,public C
//{
//public:
//    
//};
//int main()
//{
//    D d;
//    d.B::f();
//    //+ d.C::f();-A,-D;
//    return 0;
//}



