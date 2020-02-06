

#pragma once

#ifndef DLINKLIST_H
#define DLINKLIST_H

#include <iostream>

using namespace std;

template <class T>
class DLinkedList {

	//PROVIDED
	friend ostream & operator<<(ostream & out, const DLinkedList<T> & rhs) {
		DNode * curr = rhs.header->next;
		while (curr != rhs.header) {
			out << curr->data << " ";
			curr = curr->next;
		}
		return out;
	}

public:

	//inner class DNode PROVIDED
	class DNode {
	public:
		DNode * next;
		DNode * prev;
		T data;

		DNode(T val = T()) {
			data = val;
			next = prev = this;
		}

	};

	//create an empty list:  PROVIDED
	DLinkedList() {
		//create the header
		header = new DNode();
	}

	//add method  PROVIDED
	DNode * add(T item) {
		//add a new node and return a 
		//pointer to this node
		DNode * newNode = new DNode(item);
		newNode->prev = header;
		newNode->next = header->next;
		header->next->prev = newNode;
		header->next = newNode;
		return newNode;
	}

	/**
	* ASSIGNED
	* remove val from the list
	*
	* @param val
	* @return true if successful, false otherwise
	*/
	bool remove(T val) {
		DNode * curr = header->next;  //start at head
		while (curr != header && val != curr->data) { //searches after header for value
			
			curr = curr->next; //takes next pointer
		}

		if (val != curr->data){ //if value inserted not found return 0
			return 0;
		}

		if (curr->next != header){  //if removed from middle of list, change nodes
		
			curr->next->prev = curr->prev;
			curr->prev->next = curr->next;
		
		}

		else {
			curr->prev->next = header; //if not, place at end of loop back to head

		}

		return true;
	}


	/**
	* ASSIGNED
	*
	* @param item
	*/
	void insertOrder(T item) {

		if (header->next == header){ //if list is empty just insert value

			DNode * newNode = new DNode(item);
			newNode->prev = header;
			newNode->next = header;
			header->next->prev = newNode;
			header->next = newNode;
			


		}
		else {

			DNode * curr = header; //start at head


			DNode * newNode = new DNode(item); //create new node with input
			while (compare(newNode->data, curr->next->data) == 1 && curr->next != header){
				curr = curr->next; //compares data of new node and next in line
			}

			newNode->next = curr->next; //inserts node accordingly to order
			curr->next->prev = newNode;
			newNode->prev = curr;
			curr->next = newNode;
			

		}

	}

	/**
	* ASSIGNED
	*
	* @param item
	*/
	bool insertOrderUnique(T item) {
		
		if (header->next == header) { // if list is empty

			DNode * newNode = new DNode(item); //create new node with value entered
			newNode->prev = header; //place after header
			newNode->next = header;//point to header to loop back to head
			header->next->prev = newNode;//header points to new node
			header->next = newNode;
			

		
		}
		else {
			
			DNode * curr = header;//start at head traversing
	       
			while (compare(item, curr->next->data ) == 1 && curr->next != header){
			curr = curr->next; //travers through list 
			}//if double found, just finish traversing

			if (compare(item, curr->next->data) != 0){ //if no double is found
				DNode * newNode = new DNode(item);//new node with input
				newNode->next = curr->next;//set ptrs accordingly to fit in order
				curr->next->prev = newNode;
				newNode->prev = curr;
				curr->next = newNode;
				

			}
			
		}
		
		return true;
	}

	/**
	* ASSIGNED
	* PRE:  this and rhs are sorted lists
	* @param rhs
	* @return list that contains this and rhs merged into a sorted list
	* POST:  returned list will not contain duplicates, both rhs and this
	* will have no elements
	*/
	DLinkedList merge(DLinkedList rhs) {
		DLinkedList<string> result; //create a list for the merged version
		
		DNode * currList1 = header->next; //take ptrs for heads of both lists
		DNode * currList2 = rhs.header->next;
		DNode * currResult = result.header; //create ptr for head of merged
		DNode * temp = NULL;// temporary holders for lists
		DNode * temp1 = NULL;
		
		while (currList1 != header && currList2 != rhs.header) {//compares the values of each list
			if (compare(currList1->data, currList2->data) == -1){//makes sure they are not similar
				

				    DNode * newNode = new DNode(currList1->data);//new node with list one data
					newNode->prev = currResult; 
					newNode->next = result.header;//loop back to head
					currResult->next = newNode;
					currResult = newNode; //new node is place holder
		
					currList1 = currList1->next;//keep moving down list
					
			}

			else if (compare(currList1->data, currList2->data) == 1){
				//if values are equal, takes only one copy
                DNode * newNode = new DNode(currList2->data);//new node with list2 data
				newNode->prev = currResult;
				newNode->next = result.header;//places nodes in order
				currResult->next = newNode;
				currResult = newNode;
				currList2 = currList2->next;
				

			}
			
			else if (compare(currList1->data, currList2->data) == 0){
				DNode * newNode = new DNode(currList2->data);//if different, take both nodes
				newNode->prev = currResult;
				newNode->next = result.header;
				currResult->next = newNode;
				currResult = newNode;
			

				

				temp = currList1->next; //create temporary holders for the values
				free(currList1);
				currList1 = temp;

				temp = currList2->next;
				free(currList2);
				currList2 = temp;
			}

			
		}
		/*free(temp);
		if (temp1 != NULL){
			free(temp1);
		}*/


		
		cout << currList1->data << endl;
		
		if (currList1 != header){ //checks if empty
			currResult->next = currList1;
			currList1->prev = currResult;

			while (currList1->next != header){//traverse through list
				currList1 = currList1->next;
			
			}

			currList1->next = result.header;// point to new header
			

		}
		else if (currList2 != header){//traverse thorugh list
			currResult->next = currList2;
			currList2->prev = currResult;

			while (currList2->next != header){
				currList2 = currList1->next;

			}

			currList2->next = result.header; //if list2value  is lower, create as header


		}
		

		return result;
	}

int compare (T aString, T bString) {//compares string values for sorting
		
		
		char a, b;
		for (int i = 0; i <= aString.size() && i <= bString.size() - 1; i++){
			//traverse lengths of strings
			
			a = aString[i];
			b = bString[i]; //add characters to char a and b

			
			if (a >= 65 && a <= 90){//checks a for uppercase 
				a += 32;
			}

			if (b >= 65 && b <= 90){//checks b for uppercase
				b += 32;
			}

			if (a < b){     //compares each letter in the strings
				return -1;
			}
			else if (a > b){
				
			return 1;
			}

			}

		if ( aString.size() < bString.size()){//compares sizes of each string length
			return -1;
		}
		else if (aString.size() > bString.size() ){
			return 1;
		}
		else if (aString.size() == bString.size()){
			return 0;
		}
	}


private:
	//DLinkedList fields:  PROVIDED
	DNode * header;

};


#endif