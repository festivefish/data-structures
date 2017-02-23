// Matthew Jonas
// CSCI 2270 Assignment 4
// Rhonda Hoenigman

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "CommunicationNetwork.h"

using namespace std;

CommunicationNetwork::CommunicationNetwork() {

}


void CommunicationNetwork::buildNetwork(){
	string citylist[10] = {"Los Angeles","Phoenix","Denver","Dallas","St. Louis","Chicago","Atlanta","Washington, D.C.","New York","Boston"};
	
	City *previousCity = NULL;
	for(int i=0;i<10;i++){
		City *temp = new City;
		temp->cityName = citylist[9-i];
		temp->next = previousCity;
		previousCity = temp;
		if(i == 0){
			tail = temp;
		}
		if(i == 9){
			head = temp;
			//cout<<head<<endl;
			//cout<<head->next<<endl;
		}
	}
	printNetwork();
}

void CommunicationNetwork::addCity(string cityNew, string cityPrevious){

	City *temp2 = head;
	City *cityToAdd = new City;
	while(temp2->cityName != cityPrevious){
		temp2 = temp2->next;
	}
	City *temp3 = temp2->next;
	cityToAdd->next = temp3;
	cityToAdd->cityName = cityNew;
	temp2->next = cityToAdd;

}
        
void CommunicationNetwork::transmitMsg(char* filename){
	
	string line;
	string messageline;
	ifstream myfile;
	myfile.open (filename);

	while (myfile >> line){
		messageline = line;
		if(head == NULL){
			cout << "Empty list" << endl;
		}
		else{
			City *sender = head;
			sender->message = messageline;
			while(sender->next != NULL){
				cout<<sender->cityName<<" received "<<sender->message<<endl;
				sender->next->message = sender->message;
				sender->message = "";
				sender = sender->next;
			}
			cout<<sender->cityName<<" received "<<sender->message<<endl;
		}
	}
	
}
        
void CommunicationNetwork::printNetwork(){
	City *currentCity = head;
	cout << "===CURRENT PATH===" << endl;	
	while(currentCity->next != NULL){
		cout << currentCity->cityName << " -> ";
		currentCity = currentCity->next;
	}	
	cout << currentCity->cityName << " -> ";			
	cout << "NULL" << endl;	
	cout << "==================" << endl;	
}


CommunicationNetwork::~CommunicationNetwork(){

}