#include <iostream>
#include <math.h>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

void input();
void hope();
// Matrix 1 Columns !!Must == Matrix n Rows
/*
    char str[100]; // declare the size of string      
    cout << " Enter a string: " <<endl;  
    cin.getline(str, 100); // use getline() function to read a string from input stream  
      
    char *ptr; // declare a ptr pointer  
    ptr = strtok(str, " , "); // use strtok() function to separate string using comma (,) delimiter.  
    cout << " \n Split string using strtok() function: " << endl;  
    // use while loop to check ptr is not null  
    while (ptr != NULL)  
    {  
        cout << ptr  << endl; // print the string token  
        ptr = strtok (NULL, " , ");  
    }  
*/

int main() {
    hope();
    return 0;
}

void hope() {
    int matrix[count];
    char testChar[100];
    cout << "Enter: ";
    cin.getline(testChar, 100);
    char *testString;
    testString = strtok(testChar, " , ");
    for (int i = 0; i < 10; i++) {
        test[i] = atoi(testString);
        testString = strtok(NULL, " , ");
        cout << test[i] << "\n";
    }
}

void input() {
    int count;
    cout << "Please Enter # of Matrices You Wish to Multiply: ";
    cin >> count;
    int matrices[count];

    for (int i = 0; i < count; i++) {
        int rows;
        int cols;
        int matrix[rows][cols];
        cout << "Enter # of Rows in Matrix " << i << ": ";
        cin >> rows;
        cout << "Enter # of Cols in Matrix " << i << ": ";
        cin >> cols;
    }



}