#include<iostream>
#include<fstream>
#include<ctime>
#include<string>
using namespace std;

const string OUT_DIR = "outputs";
const string INP_DIR = "codes";
const string MAPPER_FILE_NAME = "mapper.txt";

ofstream outFile;
long fileNumber=0,dirNumber=0,errorNumber=0;

string get_file_name(){
	return "CODES_"+to_string(time(NULL))+".txt";
}

void dumpFileContents(string dirName, string fileName){
	if(fileName.length()<0){
		return ;
	}
	
	string filePath;
	
	if(dirName.length()>0){
		filePath=dirName + "\\" + fileName;
	}
	else{
		filePath= ".\\" + fileName;
	}
	cout<<"\tDUMPING FILE("<<(++fileNumber)<<"): "<<filePath<<endl;
	ifstream codeFile;
	codeFile.open(filePath);
	if(codeFile != NULL){
		outFile<<"// __________________________"<<endl<<endl;
		outFile<<"// "<<filePath<<endl;
		
		string contents;
		
		while(!codeFile.eof()){
			getline(codeFile,contents);
			outFile<<contents<<endl;
		}
		
		outFile<<"// __________________________"<<endl<<endl;
	}
	else{
		errorNumber++;
		cout<<"ERROR: opening file : "<<filePath<<endl;
	}
}

void recurseProcessDirectory(string dirName){
	if(dirName.length()>0){
		ifstream dirMapper;
		dirMapper.open(dirName + "\\" + MAPPER_FILE_NAME);
		if(dirMapper==NULL){
			errorNumber++;
			cout<<"ERROR: failed to find mapper file at : "+dirName<<endl;
		}
		else{
			cout<<"Processing directory("<<(++dirNumber)<<"): "<<dirName<<endl;
			string entityName;
			while(!dirMapper.eof()){
			   dirMapper>>entityName;
			   if(entityName.length()<=0) continue;
			   
			   if(entityName.find(".")>=0 && entityName.find(".")<entityName.length()){
				dumpFileContents(dirName,entityName);
			   }
			   else{
			   	recurseProcessDirectory(dirName + "\\" + entityName);
			   }
			}
			dirMapper.close();
		}
	}
}

int main(){
	
	string filename=get_file_name();
	cout<<"output at file : "<<filename<<endl;
	
	string outputPath=".\\" + OUT_DIR + "\\" + filename;
	outFile.open(outputPath);
	
	if(outFile != NULL){
		recurseProcessDirectory(".\\" + INP_DIR);
		outFile.close();
		cout<<endl<<"Writing Completed !"<<endl;
	}
	else{
		cout<<"Error opening file : "<<outputPath<<endl;
		cout<<endl<<"Program failed!"<<endl;
	}
	cout<<errorNumber<<" errors ."<<endl<<dirNumber<<" directorie(s) and "<<fileNumber<<" file(s) processed."<<endl;
	return 0;
}
