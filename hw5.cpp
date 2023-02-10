//5.  As variables are added to the stack, do the addresses get smaller or larger?
//6.  Do variables stored on the stack ever have the same address as other variables? Why or why not?
//7.  Where would you expect variables (or arguments) in recursive functions to be stored (stack, heap, or other data
//segment)? When you finish step 8 below, comment on whether your expectations were correct or not.

//5:addrs lessen becuase growth of stack is about adding vars into it.New entries go in lower and lower memory addr 
//6:no, two vars have same addr at same point in stack. Memory is removed after funcs return. No such guarentee 
//that the value stored will remain the same.
//7:stack - i find it easir to think in memeoy growing down. In recursive func local vars go in stack and global 
//vars in data segments. 
//+------------------+
//|  TEXT            | x10000?
//|                  |
//|  instructions in |  = proc1
//|  machine code    |  = proc2
//                  |
//+------------------+  = etext
//  DATA            |  = g1   global initialized
//  - initialized   |  = g3
//    variables     |  = ls1  static initialized
//|                  |  = ls3
//|                  |
//| ---------------  |  = edata
//|                  |  = g0   global uninitialized
//|                  |  = g2   big array
//|                  |  = g4
//|  - uninitialized |  = ls0  static uninitialized
//|    variables     |  = ls2
//|                  |
//|                  |
//| ---------------  |  = end
//|  - heap for      |  pointed to by heap1
//|  dynamic         |  pointed to by heap2
//|  allocation      |
//|                  |
//|                  |
//+------------------+
//|
//|
//V
//.
//.
//.
//^
//|
//|
//+------------------+
//|  STACK           |  = lc4, lc6   | Activation record for
//|  - function      |  = lc3, lc5   | proc1 or proc2
//|    activation    
//|    records       |
//|  - local         |  = lc2       | Activation record for
//|    automatic     |  = lc1       | main
//|    variables     |    xffbe2880 = lc0       |
//+------------------+


// memory_segments.cpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int g0; /* global variable, uninitialized */

int g1 = 14; /* global variable, initialized */

int g2[1500]; /* global variable, uninitialized */

int g3 = 16; /* global variable, initialized */

int g4; /* global variable, uninitialized */

void proc1();

void proc2();

int main()

{

 extern int etext[], edata[], end[];

 int lc0; /* local variable, stored on stack */

 int lc1 = 27; /* local variable, stored on stack; mix init and uninit */

 int lc2; /* local variable, stored on stack */

 static int ls0; /* local static variable, uninitialized data */

 static int ls1 = 19; /* local static variable, initialized data */

 int *pheap1;

 int *pheap2;

 pheap1 = new int[10];

 pheap2 = new int[100];

 printf("\n\n---------- main -------------------\n\n");
 printf("%14p (%15lu): Last address\n", 0xffffffffffff, 999999999999999);

 printf("%14p (%15lu): Address etext\n",

 etext, etext);

 printf("%14p (%15lu): Address edata\n",

 edata, edata);

 printf("%14p (%15lu): Address end\n",

 end, end);

 printf("%14p (%15lu): Address of code for proc1\n", &proc1, &proc1);

 printf("%14p (%15lu): Address of code for proc2\n", &proc2, &proc2);

 printf("%14p (%15lu): Address of uninitialized global variable g0\n", &g0, &g0);

 printf("%14p (%15lu): Address of initialized global variable g1\n", &g1, &g1);

 printf("%14p (%15lu): Address of uninitialized global array g2\n", &g2[0], &g2[0]);

 printf("%14p (%15lu): Address of initialized global variable g3\n", &g3, &g3);

 printf("%14p (%15lu): Address of uninitialized global variable g4\n", &g4, &g4);

 printf("%14p (%15lu): Address heap1 in heap space\n", pheap1, (unsigned long) pheap1);

 printf("%14p (%15lu): Address heap2 in heap space\n", pheap2, (unsigned long) pheap2);

 printf("%14p (%15lu): Address of local variable lc0\n", &lc0, &lc0);

 printf("%14p (%15lu): Address of local variable lc1\n", &lc1, &lc1);

 printf("%14p (%15lu): Address of local variable lc2\n", &lc2, &lc2);

 printf("%14p (%15lu): Address of local uninitialized static var ls0\n", &ls0, &ls0);

 printf("%14p (%15lu): Address of local initialized static var ls1\n", &ls1, &ls1);

 proc1();

 proc2();
 int i, fact = 1, number;
 std::cout << "Enter num:";
 std:: cin>> number;

 for( i = 1; i <= number; i++){
 	fact = fact*i;
 }
std::cout << "Factorial of" << number << "is:" << fact <<std::endl;

 return 0;

}

void proc1() {

 int lc3;

 int lc4 = 37;

 printf("\n\n----------- proc1 ------------------\n\n");

 printf("%14p (%15lu): Address of code for proc1\n", &proc1, &proc1);

 printf("%14p (%15lu): Address of global variable g0\n", &g0, &g0);

 printf("%14p (%15lu): Address of global variable g1\n", &g1, &g1);

 printf("%14p (%15lu): Address of global variable g2\n", &g2[0], &g2[0]);

 printf("%14p (%15lu): Address of global variable g3\n", &g3, &g3);

 printf("%14p (%15lu): Address of global variable g4\n", &g4, &g4);

 printf("%14p (%15lu): Address of local variable lc3\n", &lc3, &lc3);

 printf("%14p (%15lu): Address of local variable lc4\n", &lc4, &lc4);

}

void proc2() {

 int lc5;

 int lc6 = 51;

 static int ls2;

 static int ls3 = 47;

 printf("\n\n------------ proc2 -----------------\n\n");

 printf("%14p (%15lu): Address of code for proc2\n", &proc2, &proc2);

 printf("%14p (%15lu): Address of global variable g0\n", &g0, &g0);

 printf("%14p (%15lu): Address of global variable g1\n", &g1, &g1);

 printf("%14p (%15lu): Address of global variable g2\n", &g2[0], &g2[0]);

 printf("%14p (%15lu): Address of global variable g3\n", &g3, &g3);

 printf("%14p (%15lu): Address of global variable g4\n", &g4, &g4);
 
 printf("%14p (%15lu): Address of local variable lc5\n", &lc5, &lc5);

 printf("%14p (%15lu): Address of local variable lc6\n", &lc6, &lc6);

 printf("%14p (%15lu): Address of local uninitialized static var ls2\n", &ls2, &ls2);

 printf("%14p (%15lu): Address of local initialized static var ls3\n", &ls3, &ls3);

}

// Place the following picture as a comment at the beginning of

// your memory_segments.cpp file.

// Add the significant addresses to diagram to the right of the boxes.

// Add text, edata, end, and the names of the variables to right as well.

