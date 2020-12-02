#include <iostream>

using namespace std;

void findpk(int* sample, int length){
	//this version assume length of sample has been calculated
	cout << "The length is: " << length <<" the 5th sample is: "<< sample[4];
    
    bool t[length]; 
    
    
}


int main()
{
    
    
    int sample[10] = {1,2,3,4,5,4,3,2,1,0};
    int* s=  sample;
    
    int length = sizeof(sample)/sizeof(sample[0]);
    
    findpk(s , length);
    
    return 0;
}
