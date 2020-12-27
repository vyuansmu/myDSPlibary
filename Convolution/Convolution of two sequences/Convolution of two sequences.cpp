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
    int i,j,k,temp;
    int lengthA = length;
    int lengthB = length;
    int n = lengthA + lengthB - 1; //length of convolution, update length later to work dynamicly 
    int* z = new int[n]; //using new to dynamiclly allocate n-amt * int memory for my z array malloc in C
    
    for (k = 0; k < n; k++) { // loop that will loop through the values of z from 0 to n
        i = k; //tempoary counter since I need to do arithmatic on the counter but dont want to interupt the 
               // main counter which is k
        temp = 0; //temp is a temporary register to hold and accumulate A*B pairs
        for (j = 0; j < lengthB; j++) { //this loop calculates each sum
            if (i >= 0 && i < lengthA) {
                //this condition checks to make sure only a limited set of numbers are calculated
                temp = temp + (seqA[i] * seqB[j]); //accumulate
            }

            i = i - 1; //the position of this decremental counter is important for the first z element to pass
        }
        z[k] = temp;//once the second for loop exists, the tempoary i counter is no longer needed 
                    //and you can once again resume using k to store the temp value into z-array
                    //once it loops back the i-counter will be reset with a new value of k
                    //and the temp register will also be reset back to 0 to accumulate data once again
    }
    cout << "The convolution result is " << n << " units long. The sequence is:\n";
    for (int i = 0; i < n; i++) {
        cout << z[i]<< " ";
     }

    
}

