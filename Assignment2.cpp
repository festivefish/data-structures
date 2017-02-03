// Matthew Jonas
// CSCI 2270 Assignment 1
// Rhonda Hoenigman


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool Commonfilter(string wordn, string *commonWords){
	bool isCommon = 0;
	for (int i=0;i<50;i++){
		if (wordn == commonWords[i]){
			isCommon = 1;
			break;
		}
	}
	return isCommon;
}

struct WordStruct{
		string word;
		int numListings;
	};

WordStruct currentWord;

//initialize commonwords array
string commonWords[50] = ("the", "you", "one", "be", "do", "all", "to", "at", "would", "of", "this", "there", "and", "but", "their", "a", "his", "what", "in", "by", "so", "that", "from", "up", "have", "they", "out", "i", "we", "if", "it", "say", "about", "for", "her", "who", "not", "she", "get", "on", "or", "which", "with", "an", "go", "he", "will", "me", "as", "my"); 

int main(int argc, char *argv[]){

cout<<"memes"<<endl;
int size = 100;
WordStruct *uniqueWords = new WordStruct[100];
WordStruct *x;
string line;
bool common;
int numUniqueWords = 0;
int numDoublings = 0;
int numCount = 0;

char* filename = argv[1];   // filename = "HungerGames_edit.txt"
int count = atoi(argv[2]);  // count = 20

ifstream myfile;
myfile.open (filename);

while (getline(myfile,line,' ')){
	currentWord.word = line;

	cout<<line<<endl;

	//checks if word is a common word
	common = Commonfilter(currentWord.word, commonWords);

	bool unique = 1;

	//if word is not common
	if (common == 0){
		//iterates through Unique words
		for (int a=0;a<numUniqueWords;a++){
			//checks if word is already listed as a unique word
			if (currentWord.word == uniqueWords[a].word){
				//increases the number of times that word has been found
				uniqueWords[a].numListings++;
				//identifies the word as non-unique
				unique = 0;
				break;
			}
		}
		//if word is unique
		if (unique == 1){
			//creates a new unique word
			numUniqueWords++;
			uniqueWords[numUniqueWords].numListings = 1;
			uniqueWords[numUniqueWords].word = currentWord.word;

			//tests if array needs to be doubled
			if (numUniqueWords == size) {
				//doubles array
				x = new WordStruct[size*2];
				for (int j=0;j<size;j++){
					x[j] = uniqueWords[j];
				}
				delete []uniqueWords;
				uniqueWords = x;

				size = size*2;

				numDoublings++;
			}
		}

		numCount++;
	}
}

//sort unique words using insertion sort
for (int b = 0; b<numUniqueWords;b++){
	int c = 0;
	WordStruct temp;

	while(c>0 && uniqueWords[c].numListings > uniqueWords[c-1].numListings ){
		temp = uniqueWords[c];
		uniqueWords[c] = uniqueWords[c-1];
		uniqueWords[c-1] = temp;
		c--;
	}
}
//output n most common unique words
for (int d=0; d<count; d++){
	cout<<uniqueWords[d].numListings<<" – "<<uniqueWords[d].word<<endl;
}

cout<<"#"<<endl;
cout<<"Array doubled: "<<numDoublings<<endl;
cout<<"#"<<endl;
cout<<"Unique non-common words: "<<numUniqueWords<<endl;
cout<<"#"<<endl;
cout<<"Total non-common words: "<<numCount<<endl;


	return 0;
}
