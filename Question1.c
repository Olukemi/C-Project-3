#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	/*write your implementation here*/

	//get length of str1 and str2
	int str1len = strlen(str1);
	int str2len = strlen(str2);
	//find the total string length
	int totalstrlen = str1len + str2len;

	//memory location for the length of concatenated string
	z = malloc(totalstrlen);

	//point z to each char str1 points to
	for (int i = 0; i <= str1len; i++){
	    z[i] = str1[i];
	}

	//start at the last char z points to and repeat to point z to each char str2 points to
	for (int j = strlen(z), i = 0; j <= totalstrlen; j++){
	    z[j] = str2[i];
	    i++;
	}

	/* finally, return the string*/
	return z;
	
}
