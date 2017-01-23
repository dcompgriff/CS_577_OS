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
	}

	//Read file length. (If file doesn't exist, print error)
	printf("Before file length.\n");
	int fileLength = 0;
	fileLength = getFileLength(fileName);
	printf("After file length, length is %d.\n", fileLength);
	if(fileLength == -1){
		fprintf(stderr,"File not found err.\n");
		return 1;
	}
	//Set up string array, and read string data.
	//char stringTable[fileLength][1024];
	printf("Before string allocation.\n");
	char* stringTable[fileLength];
	for (int i=0; i<=fileLength; i++)
		stringTable[i] = (char*)malloc(1024 * sizeof(char));
	printf("After string allocation.\n");


	printf("Before second file read.\n");
	readFile(fileLength, fileName, stringTable);
	printf("After second file read.\n");

	//Sort string data.
	for(int i = 0; i < 10; i++){
		printf("Line: %s", stringTable[i]);
	}
	//Output

	//qsort();



	return EXIT_SUCCESS;
}
