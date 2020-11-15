#include<stdio.h>
#include<stdlib.h>
int studentNumber [] = {1111,2222,3333};
char* studentName [] = {"AAAA","BBBB","CCCC"};
struct student{
	int studentNumber ;
	char* studentName;
	struct student* nextStudent;
};
typedef struct student Student;
void enQueue(Student** headOfQueue,int studentNumber,char* studentName);
void deQueue(Student** headOfQueue,Student* temporaryStudent);
void printQueue(Student* headOfQueue);

int main (){
	Student* headOfQueue= NULL;
	Student* temporaryStudent = (Student*)malloc(sizeof(Student));
	printQueue(headOfQueue);
	enQueue(&headOfQueue,*(studentNumber + 0 ),*(studentName + 0 ));
	enQueue(&headOfQueue,*(studentNumber + 1 ),*(studentName + 1 ));
	enQueue(&headOfQueue,*(studentNumber + 2 ),*(studentName + 2 ));
	printQueue(headOfQueue);
	
	deQueue(&headOfQueue,temporaryStudent);
printf("DELETE STUDENT --> STUDENT NUMBER : %-6d STUDENT NAME : %-6s\n",temporaryStudent -> studentNumber , temporaryStudent -> studentName);
	printQueue(headOfQueue);
	printf("\n");
	deQueue(&headOfQueue,temporaryStudent);
printf("DELETE STUDENT --> STUDENT NUMBER : %-6d STUDENT NAME : %-6s\n",temporaryStudent -> studentNumber , temporaryStudent -> studentName);
	printQueue(headOfQueue);
	printf("\n");
	
	return 0 ;
}

void enQueue(Student** headOfQueue,int studentNumber,char* studentName){
	Student* newStudent = (Student*)malloc(sizeof(Student));
	if(newStudent == NULL){
		printf(" not empty ram\n");
		exit(EXIT_FAILURE);
	}
	else{
		Student* currentStudent = (*headOfQueue);
		newStudent -> studentNumber = studentNumber;
		newStudent -> studentName = studentName;
		if(currentStudent == NULL){
			(*headOfQueue) = newStudent;
			newStudent -> nextStudent = NULL;
		}
		else{
			newStudent -> nextStudent = currentStudent;
			(*headOfQueue) = newStudent;
		}
	}
}


void deQueue(Student** headOfQueue,Student* temporaryStudent){
	Student* currentStudent = (*headOfQueue);
	if(currentStudent == NULL){
		printf("Empty Queue\n");
	}	
	else{
		Student* previousStudent = (*headOfQueue);
		while(currentStudent -> nextStudent != NULL){
			previousStudent = currentStudent;
			currentStudent = currentStudent -> nextStudent;
		}
		temporaryStudent -> studentNumber = currentStudent -> studentNumber;
		temporaryStudent -> studentName = currentStudent -> studentName;
		previousStudent -> nextStudent = currentStudent -> nextStudent;
		free(currentStudent);
	}
	
	
}


void printQueue(Student* headOfQueue){
	Student* currentStudent = headOfQueue;
	if(currentStudent == NULL){
		printf("EMPTY QUEUE\n");
	}
	else{
		int i = 3 ;
		while(currentStudent != NULL){
printf(" %d .inci STUDENT NUMBER : %-6d STUDENT NAME : %-6s\n",i,currentStudent -> studentNumber , currentStudent -> studentName);
			currentStudent = currentStudent -> nextStudent;
			i--;
	}
	}
}
