#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
using namespace std;

int main(){
ifstream inputfile;
ofstream outputfile;
string buffer;
string item;
inputfile.open("input",ios::in);
outputfile.open("output");

if(inputfile){
while(!inputfile.eof()){
	getline(inputfile,buffer,'\n');
	stringstream input(buffer);
	while(!input.eof()){
		getline(input,item,'\t');
		if(item == "douyin"){
			outputfile << buffer << "\n";
		}
	}
}
return 0;
}
}
