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


int main(int argc, char* argv[]) {


	puts("My Sort Program!");


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

	//If non-negative number input, print error.
	//If unknown option, print error.

	//Read file length. (If file doesn't exist, print error)

	//Set up string array, and read string data.

	//Sort string data.

	//Output

	//qsort();



	return EXIT_SUCCESS;
}
