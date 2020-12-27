// Convolution of two sequences.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
int main()
{

    int seqA[5];//for now keep the program simple and have two arrays
    int seqB[5]; 
    int length = 5;
    
    cout << "Please enter the first sequence\n";
    for (int i = 0; i <= length - 1; i++) {
        cin >> seqA[i];
    }
    cout << "The first sequence you entered was:\n";
    for (int x : seqA) {
        cout << x << " ";
    } cout << endl;
    //I know these sections can be grouped into functions but for now just keep it monolith
    cout << "Please enter the second sequence\n";
    for (int i = 0; i <= length - 1; i++) {
        cin >> seqB[i];
    } cout << endl;
    cout << "The second sequence you entered was:\n";
    for (int x : seqB) {
        cout << x << " ";
    } cout << endl;
    
    //~~~~~~~~~~~~~~~~ now implement Convolution~~~~~~~~~~~~ dont worry about OOP for now
    int n = length + length - 1; //length of convolution, update length later to work dynamicly 
    //https://stackoverflow.com/questions/24518989/how-to-perform-1-dimensional-valid-convolution
    //review recursion tommorrow 


    


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
