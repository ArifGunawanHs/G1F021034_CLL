#include <iostream>
using namespace std;

struct filim{
	string judul, sutradara, tempat_tayang;
	
	filim *next;
};

filim *head, *tail, *cur, *newNode, *del, *after;


void createCircularSingleLinkedList(string dataBaru[3]){
	head = new filim();
	head->judul = dataBaru[0];
	head->sutradara= dataBaru[1];
	head->tempat_tayang = dataBaru[2];
	tail = head;
	tail->next = head;
}

void insertFirst(string data[3]){
	if(head == NULL){
		cout <<"Buat Link List Dulu"<<endl;
	}else{
	newNode = new filim();
	newNode->judul = data[0];
	newNode->sutradara= data[1];
	newNode->tempat_tayang = data[2];
	newNode->next = head;
	tail->next = newNode;
	head = newNode;
	}
}


void insertLast(string data2[3]){
	if(head == NULL){
		cout <<"Buat Link List Dulu"<<endl;
	}else{
	newNode = new filim ();
	newNode->judul = data2[0];
	newNode-> sutradara = data2[1];
	newNode->tempat_tayang = data2[2];
	newNode->next = head;
	tail->next = newNode;
	tail = newNode;
	}
}


void insertAfter(string data[3], int posisi){
	if(head == NULL){
		cout <<"Buat Link List Dulu"<<endl;
	}else{
		if(posisi == 1){
			cout<<"Posisi satu Bukan posisi tengah"<<endl;
		}else{
			newNode = new filim();
			newNode->judul = data[0];
			newNode->sutradara = data[1];
			newNode->tempat_tayang = data[2];
			
			int nomor =1;
			cur = head;
			while(nomor < posisi -1){
				cur = cur->next;
				nomor++;
			}
			
			newNode->next = cur->next;
			cur->next = newNode;
		}
	}
}

void deleteFirst(){
	if(head == NULL){
		cout <<"Buat Link List Dulu"<<endl;
	}else{
	del = head;
	head = head->next;
	tail->next = head;
	delete del;
	}
}

void deleteLast(){
	if(head == NULL){
		cout <<"Buat Link List Dulu"<<endl;
	}else{
	del = tail;
	cur = head;
	
	while(cur->next != tail){
		cur = cur->next;
	}
	
	tail = cur;
	tail->next = head;
	
	delete del;
	}
}

void deleteAfter(int posisi){
	if(head == NULL){
		cout <<"Buat Link List Dulu"<<endl;
	}else{
		
		int nomor = 1;
		cur = head;
		while(nomor < posisi -1){
		cur = cur->next;
		nomor++;
		}
	
		del = cur->next;
		cur->next = del->next;
		delete del;
		
	}
}

void printCircular(){
	if(head == NULL){
		cout <<"BUat Link List Dulu"<<endl;
	}else{
	cout<<"--Data filim ---"<<endl;
	cur = head;
	while(cur-> next!= head){
		cout<<"Judul filim : "<<cur->judul<<endl;
		cout<<"sutradara filim : "<<cur->sutradara<<endl;
		cout<<"tempat tayang filim : "<<cur->tempat_tayang<<endl;
		
		cur = cur->next;
	}
	cout<<"Judul filim : "<<cur->judul<<endl;
	cout<<"sutradara filim: "<<cur->sutradara<<endl;
	cout<<"Tempat tayang filim : "<<cur->tempat_tayang<<endl;
	}
}
void searchNode(filim **head, int id){
    int currentID = 1;
    filim *cur = *head;
    while (cur->next != 0 && currentID != id){
        cur = cur->next;
        currentID++;
    }
    cout << cur->judul << " ditemukan pada data ke " << currentID;
}

int main(){
	
	string dataBaru[3] = {"Makmum 2","Guntur Soeharjanto", "BENGKULU"};
	createCircularSingleLinkedList(dataBaru);
	printCircular();
	cout<<"\n\n"<<endl;
	
	string data[3] = {"spiderman no way home", "Jon Watts", "SERANG"};
	insertFirst(data);
	printCircular();
	cout<<"\n\n"<<endl;
	
	string data2[3] = {"Jhon Wick", "Chad Stahelski""Batam"};
	insertLast(data2);
	printCircular();
	cout<<"\n\n"<<endl;
	
	string data3[3] = {"Laskar Pelangi", "Riri Riza", "MANADO"};
	insertAfter(data3, 5);
	printCircular();
	cout<<"\n\n"<<endl;
	
	deleteFirst();
	printCircular();
	cout<<"\n\n"<<endl;
	
	deleteLast();
	printCircular();
	cout<<"\n\n"<<endl;
	
	deleteAfter(6);
	printCircular();
	cout<<"\n\n"<<endl;
	
	cout << "\nSearching judul : Laskar Pelangi" << endl;  
	searchNode(&head, 2);
	
	return 0;

}
