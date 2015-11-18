#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int binArray[7];

void getBytes(int num)
{
	for (int j = 0; j < 7; ++j) {  // assuming a 32 bit int
		binArray[j] = num & (1 << j) ? 1 : 0;
	}
	//return binArray;
}

void makeSound(int bit)
{
	if(bit==1)
		{Beep(700, 100);}
	else if(bit==0)
		{Beep(700, 400);}
	Beep(0,400);
		
}

int main()
{
	string file_name = "D:/pocketcpp/pros/s1.txt";
    ifstream file(file_name);
	string line;
	while( getline(file, line)) {
		for (int i=0; i < line.length(); i++) {
			 if (line[i]) {
				getBytes((int)line[i]);
				for(int j=0;j<7;j++){
					makeSound(binArray[j]);
					Beep(700, 800);
					Beep(0, 400);
					cout<<binArray[j];
				}
			}
		}
    }
	//cout << '\a'; //for linux
	/*Beep( 600, 300 );  for windows
						pass freq, duration. 
						success --> returns non zero. 
						failure --> returns zero
						*/
	
		
}