#include<iostream>
#include<fstream>
#include<ctime>
#include<cstring>
using namespace std;

const string OUT_DIR = "outputs";

string get_file_name(){
	return "CODES_"+to_string(time(NULL))+".txt";
}

int main(){
	
	string filename=get_file_name();
	cout<<"output at file : "<<filename<<endl;
	
	string outputPath=".\\" + OUT_DIR + "\\" + filename;
	ofstream outFile;
	outFile.open(outputPath);
	
	if(outFile != NULL){
		
		//process files of codes
		
		outFile.close();
		cout<<"Writing Completed !";
	}
	else{
		cout<<"Error opening file : "<<outputPath<<endl;
		cout<<"Progream failed!";
	}
	return 0;
}
