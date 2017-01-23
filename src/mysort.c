/*
 ============================================================================
 Name        : mysort.c
 Author      : Daniel Griffin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>


/*
 * Linked List Code.
 * */
typedef struct ListNode_ {
    char *value;
    struct ListNode_ *next;
}ListNode;

typedef struct LinkedList_ {
	ListNode *head;
	ListNode *tail;
	int length;
}LinkedList;

/**
 * Initialize list.
 * */
void linkedListInit(LinkedList *list){
	list->head = NULL;
	list->tail = list->head;
	list->length = 0;
}

/**
 * Frees each linked list node, and also frees the LinkedList structure passed to the function.
 * */
void linkedListDestroy(LinkedList *list){
	ListNode *currNode = list->head;
	while(currNode){
		ListNode *delNode = currNode;
		currNode = currNode->next;
		free(delNode);
	}
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	free(list);
}

/**
 * Append new list node to the end of the list.
 * */
void linkedListAdd(LinkedList *list, char *value){

	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->value = value;
	newNode->next = NULL;

	if(list->length == 0){
		list->head = newNode;
		list->tail = newNode;
	}else{
		list->tail->next = newNode;
		list->tail = list->tail->next;
	}
	list->length += 1;
}


/*
 * Sorting functions.
 * */
int strCmpFunc(const void * a, const void * b){
	return strcmp((char*)a, (char*)b);
}

int strCmpFuncRev(const void * a, const void * b){
   return -1*strcmp((char*)a, (char*)b);
}

int getFileLength(char fileName[]){
	int numberOfLines = 0;
	char buffer[1024];
	FILE* fp = fopen(fileName, "r");
	if(fp == NULL){
		return -1;
	}else{
		while(fgets(buffer , 1024 , fp) != NULL){
			numberOfLines += 1;
		}
	}
	fclose(fp);
	return numberOfLines;
}


void readFile(int length, char fileName[], char* stringList[]){
	FILE* fp = fopen(fileName, "r");
	int i = 0;
	printf("Opened file second time!\n");
	while(fgets(stringList[i] , 1024 , fp) != NULL){
		i += 1;
	}
	fclose(fp);
}


int main(int argc, char* argv[]) {
	printf("Beginning.\n");

	//Parse input options.
	int reverse_sort = 0;
	int print_number_lines = 0;
	int read_from_file = 0;
	char* fileName;
	char c;
	LinkedList *stringList = (LinkedList*)malloc(sizeof(LinkedList));
	linkedListInit(stringList);


	//Read in command line options, and set corresponding flags.
	while ((c = getopt (argc, argv, "rn::")) != -1){
		switch (c){
	    	case 'r':
	    		//Reverse sorting order.
	    		reverse_sort = 1;
	    		break;
	    	case 'n':
	    		//Convert option value to number. (Returns 0 if invalid conversion)
	    		print_number_lines = atoi(optarg);
	    		//If invalid argument, return negative.
	    		if(print_number_lines < 0){
	    			fprintf(stderr, "Option error `-%d'.\n", print_number_lines);
	    			return 1;
	    		}
	    		break;
	    	case '?':
	    		//Unknown option encountered.
	    		if(isprint(optopt)){
	    			fprintf(stderr, "Unknown option `-%c'.\n", optopt);
	    		}else{
	    			fprintf(stderr,"Unknown option character `\\x%x'.\n", optopt);
	    		}
	    		//Return with exit error.
	    		return 1;
	    	default:
	    		abort();
	      }
	}

	//If extra, non-command line argument passed (Aka, file name), then set the file name flag to true, and set file name reference pointer.
	if(optind < argc){
		//Get a reference to the file.
		fileName = argv[optind];
		read_from_file = 1;
	}

	//Read Data From File Into Linked List.
	if(read_from_file){
		FILE* fp = fopen(fileName, "r");
		int i = 0;
		char *mString = (char*)malloc(1024 * sizeof(char));
		printf("Opened file to read!\n");
		while(fgets(mString , 1024, fp) != NULL){
			//Add string to list
			linkedListAdd(stringList, mString);
			//Allocate new memory.
			mString = (char*)malloc(1024 * sizeof(char));
			i += 1;
		}
		//Unallocate last, unused string memory block.
		free(mString);
		fclose(fp);
		printf("Finished reading file! Length of List is %d, # Lines Read is %d.\n", stringList->length, i);
	}

	//Iterate through list items, and store them in an array for the qsort function.
	char *staticStringList[stringList->length];
	ListNode *currNode = stringList->head;
	int i = 0;
	int fileLength = stringList->length;
	while(currNode){
		staticStringList[i] = currNode->value;
		currNode = currNode->next;
		i++;
	}
	//Destroy the linked list structure.
	linkedListDestroy(stringList);

	for(i=0; i<10; i++){
		printf("Static string list: %s", staticStringList[i]);
	}

//	//Set up string array pointer, and allocate 1024 characters for each string.
//	char* stringTable[fileLength];
//	for (int i=0; i<=fileLength; i++)
//		stringTable[i] = (char*)malloc(1024 * sizeof(char));
//	//Read strings from file.
//	readFile(fileLength, fileName, stringTable);

	//Sort string data.


	//Output

	//qsort();



	return EXIT_SUCCESS;
}
