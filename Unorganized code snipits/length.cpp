//finds length of array by dividing the total mem size of array by mem size of first entry
int len1(int* sample){
	int len = sizeof(sample)/sizeof(sample[0]);
	return len
}


//finds length of array by subtracting subtracting the adress of the last element with the adress of the first 
int len2(int* sample){
	int len = *(&sample + 1) - arr;
	return len
}