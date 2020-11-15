#include<stdio.h>
#include<stdlib.h>
int studentNumber [] = { 1111,2222,3333};
char* studentName [] = { "AAAA","BBBB","CCCC"};
struct student{
	int studentNumber;
	char* studentName;
	struct student* nextStudent;
};
typedef struct student Student ;
// sona ekleme
 void addStudent(Student** headOfList,int studentNumber,char* studentName);
 void deleteStudent(Student** headOfList,int studentNumber);
 void printStudent(Student* headOfList);
 int searchStudent(Student* headOfList,int studentNumber);
int main (){
 	Student* headOfList = NULL;
 	printStudent(headOfList);
	addStudent(&headOfList,*(studentNumber + 0 ),*(studentName + 0 ));
	addStudent(&headOfList,*(studentNumber + 1 ),*(studentName + 1 ));
 	addStudent(&headOfList,*(studentNumber + 2 ),*(studentName + 2 ));
 	printStudent(headOfList);
 	printf("\n");
 	deleteStudent(&headOfList,4444);
 	printStudent(headOfList);
 	return 0 ;
}
 
 
 
 void printStudent(Student* headOfList){
 	Student* currentStudent = headOfList;
 	if ( currentStudent == NULL){
 		printf("bos liste .... !!!\n");
	 }
	 else{
	 	while(currentStudent != NULL){
	printf("Student NUMBER : %-6d , Student NAME : %-6s\n",currentStudent -> studentNumber,currentStudent -> studentName);
	 	currentStudent = currentStudent -> nextStudent;
		 }
	 	
	 	
	 }
 }
int searchStudent(Student* headOfList,int studentNumber){
 	if ( headOfList == NULL){
 		return 0 ;
	 }
	 else{
	 Student* currentStudent = headOfList;
 	while(currentStudent != NULL && currentStudent -> studentNumber != studentNumber){
 		currentStudent = currentStudent -> nextStudent;
	 }
	if ( currentStudent == NULL){
		return 0 ;
		
	}
	else{
		return 1 ;
		
	}
 }
}
 
 
 
 
 
 
 void deleteStudent(Student** headOfList,int studentNumber){
 	if ( searchStudent(*headOfList,studentNumber) == 0 ){
 		printf("listede silinecek eleman yok\n");
		 }
	else {
		 Student* currentStudent = (*headOfList);
 		if(currentStudent -> nextStudent == NULL || currentStudent -> studentNumber == studentNumber){
 			(*headOfList) = currentStudent -> nextStudent;
 			free(currentStudent);
 			
		 }
		 Student* previousStudent = (*headOfList);

		
		 while(currentStudent != NULL && currentStudent -> studentNumber != studentNumber){
		 	previousStudent = currentStudent;
		 	currentStudent = currentStudent -> nextStudent;
		 }			
		 if ( currentStudent != NULL){
		previousStudent -> nextStudent = currentStudent -> nextStudent;
		 free(currentStudent);
 		}
	 
}
}

void addStudent(Student** headOfList,int studentNumber,char* studentName){
 	 Student* newStudent = (Student*)malloc(sizeof(Student));
	 Student* currentStudent =(*headOfList);
		if(newStudent == NULL){
	 		printf(" ram dolu \n");
	 		exit(EXIT_FAILURE);
	 	}
		 else{
		  if(currentStudent == NULL){
				newStudent -> studentNumber = studentNumber;
	 			newStudent -> studentName = studentName;
	 			newStudent -> nextStudent = NULL;
	 			(*headOfList) = newStudent;
	 	}
		else{
			newStudent -> studentNumber = studentNumber;
			newStudent -> studentName = studentName ;
			newStudent -> nextStudent = NULL;
			while(currentStudent -> nextStudent != NULL){
				currentStudent = currentStudent -> nextStudent;
			}
			currentStudent -> nextStudent = newStudent;
		}		 
}
}
