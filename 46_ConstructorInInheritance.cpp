// /******************************************************************************

//                               Online C++ Compiler.
//                Code, Compile, Run and Debug C++ program online.
// Write your code in this editor and press "Run" button to compile and execute it.

// *******************************************************************************/







/*
Case1:
class B: public A{
   // Order of execution of constructor -> first A() then B()
};

Case2:
class A: public B, public C{
    // Order of execution of constructor -> B() then C() and A()
};

Case3:
class A: public B, virtual public C{
    // Order of execution of constructor -> C() then B() and A()
};

*/









// #include <iostream>

// using namespace std;
// class A{
//    public:
//    A(){
//        std::cout << "hii a" << std::endl;
//   }   
// };
// class B : public A{
//    public:
//    B(){
//        std::cout << "hii b" << std::endl;
//   }   
// };
// class C : public B{
//    public:
//    C(){
//        std::cout << "hii c" << std::endl;
//   }   
// };

// int main()
// {
//    C gaju;
    

//    return 0;
// }








/* C++ Program to illustrates the use of Constructors in multilevel inheritance  */

#include<iostream>
using namespace std;

class A
{
        protected:
                int x ;
        public:
                A( )  // Constructor without argument
                {
                     x = 0 ;
                     cout << "\n Constructor of class A without any argument is invoked" ;
                }
                A(int X) // Constructor with one argument
                {
                      x = X ;
                      cout << "\n Constructor of class A with one argument is invoked" ;
                }
                void Enter_x(void)
                {  cout << "\n\t Enter the value of x: " ; cin >> x ; }
                void Display_x(void)
                { cout << "\n\t x = " << x ; }
};

class B : public A
{
        protected:
                int y ;
        public:
                B( ) : A( )  // Constructor without argument
                {
                       y = 0;
                       cout << "\n Constructor of class B without any argument is invoked" ;
                }
                  // Constructor with two arguments
                B( int X,  // Argument for constructor A
                         int Y )   // Argument for constructor B
                                 : A(X)   // Call for constructor A
                {
                       y = Y;
                       cout << "\n Constructor of class B with two arguments in invoked" ;
                }
                void Enter_y(void)
                { cout << "\t Enter the value of y: " ; cin >> y ;  }
                void Display_y(void)
                { cout << "\n\t y = " << y ;  }
};

class C : public B
{
        private:
                int z ;
        public:
                C( ) : B( )   // Constructor without argument
                {
                       z = 0;
                       cout << "\n Constructor of class C without any argument is invoked\n" ;
                }
                // Constructor with three arguments
                C(int X, int Y,   // Arguments for constructor B
                                int Z)     // Argument for constructor C
                                              : B(X, Y)    // Call for constructor B
                {
                       z = Z ;
                       cout << "\n Constructor of class C with three arguments is invoked" ;
                }
                void Enter_z(void)
                { cout << "\t Enter the value of z: " ; cin >> z ; }
                void Display_z(void)
                { cout << "\n\t z = " << z ; }
};


int main()
{
                cout << "\n The first object is in use now******** \n " ;
                C c1 ;
                c1.Enter_x( );
                c1.Enter_y( );
                c1.Enter_z( );
                c1.Display_x( );
                c1.Display_y( );
                c1.Display_z( );
                cout << "\n\n The second object is in use now******** \n" ;
                C c2(5, 6, 7) ;
                c2.Display_x( );
                c2.Display_y( );
                c2.Display_z( );
return 0;
}
