#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"




char **read_words(const char *input_filename, int *nPtr){

	
    char **word_list;

    /*write your implementation here*/

    //open file and read it
    FILE *file_input = fopen(input_filename, "r");

    //look at the first line in the file and have nPtr be the value that represents the number of words in the list
    fscanf(file_input, "%d", nPtr);

    //create a memory location initialized to 0 with size of the number of words in the list provided in the first line of the list
    word_list = calloc(*nPtr, sizeof(char *));

    //loop through each line in the file and add each word found into the word list
    for(int i = 0; i < nPtr; i++){
    	fscanf(file_input, "%s", &word_list[i]);
    }

    fclose(file_input); //close file

    return word_list;

}

int compare_str(const char *str1,const char *str2){

	/*this is a helper function that you can implement and use to facilitate your development*/
   	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/

	/*write your implementation here and update the return accordingly*/

	while(*str1 != "\0" && *str1 == *str2){ // while str1 has not reached the end and str1 is equal to str2
		++str1;
		++str2;
	}

	int diff = *str1 - *str2;

	if (diff > 0){ // check if str1 is "greater" than str2
		return 1;
	} else {
		return 0;
	}
    
}

void sort_words(char **words, int size){
   
	/*write your implementation here*/

	//Insertion sort is a sorting algorithm that places an unsorted element
	//at its suitable place in each iteration.

	char *temp;
	int j;

	for(int i = 1; i < size; i++){
		temp = words[i];
		j = i-1;

		while(j >= 0 && compare_str(temp, words[j]) <= 0){
			words[j + 1] = words[j];
			j = j - 1;
		}
		words[j + 1] = temp;
	}


}

void swap(char **str1, char **str2){
 
	/*this is a helper function that you can implement and use to facilitate your development*/


}

void sort2_words(char **words, int size){

   
	/*write your implementation here*/

	//This is bubble sort and is the simplest sorting algorithm that works by repeatedly
	//swapping the adjacent elements if they are in wrong order

	char *temp;

	for(int i = 0; words[i]; i++){
		for(int j = 0; words[j]; j++){
			if (compare_str(words[i], words[j]) <= 0){
				temp = words[i];
				words[i] = words[j];
				words[j] = temp;
			}
		}
	}



    
}

