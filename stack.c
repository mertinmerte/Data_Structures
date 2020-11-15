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
void stackPush(Student** headOfStack,int studentNumber,char* studentName);
void stackPop(Student** headOfStack,Student* temporaryStudent);
void stackprint(Student* headOfStack);
int main (){
	Student* headOfStack = NULL;
	Student* temporaryStudent = (Student*)malloc(sizeof(Student));
	stackprint(headOfStack);
	stackPush(&headOfStack,*(studentNumber + 1 ),*(studentName + 1 ));
	stackPush(&headOfStack,*(studentNumber + 2 ),*(studentName + 2 ));
	stackPush(&headOfStack,*(studentNumber + 0 ),*(studentName + 0 ));
	stackprint(headOfStack);
	printf("\n");
	stackPop(&headOfStack,temporaryStudent);
printf("POP STUDENT --> STUDENT NUMBER : %-6d   STUDENT NAME : %-6s\n",temporaryStudent -> studentNumber,temporaryStudent -> studentName);
	stackprint(headOfStack);
	return 0;
}





void stackprint(Student* headOfStack){
	Student* currentStudent = headOfStack;
	if(currentStudent == NULL){
		printf("STACK EMTY \n");
	
	}
	else{
		int i = 1;
		while(currentStudent != NULL){
			printf("%d .inci STUDENT NUMBER : %-6d  STUDENT NAME : %-6s\n",i,currentStudent -> studentNumber,currentStudent -> studentName);
			currentStudent = currentStudent -> nextStudent;
			i++;
		}
		
		
	}
	
}






void stackPush(Student** headOfStack,int studentNumber,char* studentName){
	Student* newStudent = (Student*)malloc(sizeof(Student));
	if (newStudent == NULL){
		printf("bos ram\n");
		exit(EXIT_FAILURE);
	}
	else{
		Student* currentStudent = (*headOfStack);
		newStudent -> studentNumber = studentNumber;
		newStudent -> studentName = studentName;
		if(currentStudent == NULL){
			(*headOfStack) = newStudent;
			newStudent -> nextStudent = NULL;
		}
		else{
			while(currentStudent -> nextStudent != NULL){
				currentStudent = currentStudent -> nextStudent;
			}
			currentStudent -> nextStudent = newStudent ;
			newStudent -> nextStudent = NULL;
			}
}
}


void stackPop(Student** headOfStack,Student* temporaryStudent){
	Student* currentStudent = (*headOfStack);
	if(currentStudent == NULL){
		printf("STACK EMPTY\n");
		exit(EXIT_FAILURE);
	}
	else{
		if(currentStudent -> nextStudent == NULL){
			temporaryStudent -> studentNumber = currentStudent -> studentNumber;
			temporaryStudent -> studentName = currentStudent -> studentName;
			(*headOfStack) = currentStudent -> nextStudent;	
			free(currentStudent);
		}
		Student* previousStudent = (*headOfStack);
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
