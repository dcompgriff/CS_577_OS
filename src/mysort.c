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
	int print_number_lines = -1;
	char* fileName[];

	//Parse

	//qsort();



	return EXIT_SUCCESS;
}
