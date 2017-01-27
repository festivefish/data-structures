// Matthew Jonas
// CSCI 2270 Assignment 1
// Rhonda Hoenigman


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

	struct product {
		string itemtype;
		string forsale;
		int price;
	};


int deleteElement( product List[100], int index, int itemnum){
	int shiftCounter = 0;
	for (int x=index; index < itemnum; x++){
		List[x] = List[x+1];

		shiftCounter++;
	}
	itemnum = itemnum - 1;
	return shiftCounter;
}

int main(){
	string filename;
	cin >> filename;
	


	product List[100];
	product leftovers[100];

	ifstream myfile;
	myfile.open (filename); 

	/*if (myfile.is_open()){
    	while ( getline (myfile,line) ){
    		product i = 
    	}
    myfile.close();
    }
    */

    product item;
    int itemnum = 0;
    int fileCounter = 0;
    int shiftCounter = 0;
    int searchCounter = 0;
    string line;
    string str = (" meme");
    //string str2 = " ";

	//ifstream infile(filename);
    string token;
	while (getline(myfile,line)){
		//str.append(str2);
		str.append(line);
		istringstream ss(line);
		while (getline(ss, token, ',')){
			str.erase (str.begin());
		cout<<token<<endl;
    	//process the data
    	int foundmatch = 0;
    	fileCounter++;
    	for (int i=0; i<itemnum; i++){
    		if (item.itemtype == List[i].itemtype && item.forsale != List[i].forsale  && foundmatch == 0){
    			if ( item.forsale == "wanted" && item.price >= List[i].price || item.forsale == "for sale" && item.price <= List[i].price){
    				//indexes match and deletes matching item
    				int index = i;
    				shiftCounter = deleteElement(List, index, itemnum);
    				//outputs match
    				cout<<List[i].itemtype<<" "<<List[i].price<<endl;
    				//indicates that the program has found a match and can move on
    				foundmatch = 1;
    				cout<<"meme2"<<endl;
    			}
    			cout<<"meme3"<<endl;
    		}
    		else if (foundmatch !=1){
    			List[itemnum] = item;
    			itemnum++;
    		}
    		searchCounter++;
    		cout<<"meme3"<<endl;
    	}
    	}
	}
	cout<<"#"<<endl;
	for (int i=0; i<itemnum; i++){
		if (List[i].forsale == "for sale"){
			cout<<List[i].itemtype<<", "<<"for sale"<<", "<<List[i].price<<endl;
		}
		else{
			cout<<List[i].itemtype<<", "<<"wanted"<<", "<<List[i].price<<endl;
		}
	}
	cout<<"#"<<endl;
	cout<<"file read:"<<fileCounter<<endl;
	cout<<"search array:"<<searchCounter<<endl;
	cout<<"shift array:"<<shiftCounter<<endl;
	return 0;
}
