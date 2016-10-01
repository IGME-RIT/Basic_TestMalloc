/*
TestMalloc
(c) 2016
original authors:  David I. Schwartz
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*	This tutorial introduced the way of allocation memory in heap using malloc function.
*	It covers concepts of array and pointer as well.
*/

#pragma region Setup
#include <iostream>
using namespace std;

// not mandatory, but helpful:
// http://msdn.microsoft.com/en-us/library/x98tx3cf%28v=vs.100%29.aspx
#define _CRTDBG_MAP_ALLOC	// Compare with another example in project 2D Array, it uses operator new 
#include <stdlib.h>
#include <crtdbg.h>
#pragma endregion

int* makeIntArray(int size);	// declare function (prototype) which returns to a pointer points to int
void print(int* a, int size);	

const int SIZE = 4;	

int main() {
    int* a = makeIntArray(SIZE);	// initialize pointer a and assign the return value of funtion
    print(a,SIZE);					// call funtion, pass the value of a and SIZE as its arguments
									// output: [0,1,2,3]
    free(a); // what happens if you don't free the memory?

    _CrtDumpMemoryLeaks();			// see Output window (set it to show Debug) 
									// uncomment the line using free() to see the data
}


#pragma region Define Functions
int* makeIntArray(int size) {
    int* a = (int*) malloc(size*sizeof(int));	// allocate memory blocks in heap, pass SIZE*4 byte into funstion as parameter
												// cast the value(a void pointer) to a pointer to int
    for (int i=0; i < size; i++) 
        *(a+i) = i;								// make deference of the pointer as followed: 0,1,2,3 
    return a;
}

void print(int* a, int size) {
    cout << '[';
    for(int i = 0; i < size; i++)				
        cout << a[i] << ( i == size-1 ? ']' : ',' );	// output the value of pointer a
    cout << endl;
}
#pragma endregion

