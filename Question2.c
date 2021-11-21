#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;


	/*write your implementation here*/

	//open file and read it
	FILE *file_input = fopen(filename, "r");

	//scan file and take the input from the first line in the file and set sizePtr equal to size input which is the number of students in the list
	fscanf(file_input, "%d", sizePtr);

	//create a memory location for the class list initialized to 0 for the class list with sizePtr that represents the number of students
	class_list = calloc(*sizePtr, sizeof(student));

	//scan the rest of the file and set each student along with student id, first and last name to a placeholder in the class list
	for(int i = 0; i < *sizePtr; i++){
		student *s = calloc(1, sizeof(student)); //create a memory location of size structure 'student' for 's' to store all the data for each student
		fscanf(file_input, "%d", &s->student_id); //set the id at this file line to the student id for this student
		fscanf(file_input, "%s", s->first_name); //set the first name at this file line to the first_name for this student
		fscanf(file_input, "%s", s->last_name); //set the last name at this file line to the last_name for this student
		class_list[i] = s; //add each student (holding the student id, first and last name) to a placeholder in the class list
	}

	fclose(file_input); //close file

	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	
	/*write your implementation here and update the return accordingly*/

	for(int i = 0; i < size; i++){ //loop through the class list
		int id = list[i]->student_id; // set id equal to the student id in the list for this student
		if (id == idNo){
			return i; //if the id for this student is equal to idNo return the position of the student in the list
		}
	}


	return -1;
}

void input_grades(char *filename, student **list, int size)
{

	/*write your implementation here*/

	//open grade file and read it
	FILE *file_input = fopen(filename, "r");

	int id;
	int pos;

	for(int i = 0; i < size; i++){
		fscanf(file_input, "%d", &id); //scan the next line file for the student id and set it to the memory location of id
		pos = find(id, list, size); //call the find function to find the position of the student based on the id
		fscanf(file_input, "%d", &list[pos]->project1_grade); //scan the next line for the project 1 grade and have the list at the index set the grade for that student
		fscanf(file_input, "%d", &list[pos]->project2_grade); //scan the next line and repeat for project 2
	}

	fclose(file_input); //close file

}

void compute_final_course_grades(student **list, int size)
{
	
	/*write your implementation here*/

	//loop through the list and for each student, find the average of the two projects
	for (int i = 0; i < size; i++){
		list[i]->final_grade = (list[i]->project1_grade + list[i]->project2_grade) / 2.0; // set the final grade for each student to be the average of project 1 and 2
	}


}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write your implementation here*/

	//open a file and write in it
	FILE *file_output = fopen(filename, "w");

	fprintf(file_output, "%d\n", size); // write and print the number of students in the first line

	//for each student write and print their student id along with their final grade in the same line. Print these 2 pieces of info in a new line for each student
	for(int i = 0; i < size; i++){
		fprintf(file_output, "%d %f\n", list[i]->student_id, list[i]->final_grade);
	}

	fclose(file_output); //close file

}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/

	//find the position of idNo
	int pos = find(idNo, list, *sizePtr);

	if (pos != -1){ //if the position "exists" in the list
		(*sizePtr)--; //reduce the number of students by one
		free(list[pos]); //release and deallocate the student stored in memory in the list at position

		for(int i = pos; i < *sizePtr; i++){
			list[i] = list[i + 1]; // bump all the students in the list down starting from the position of the removed student
		}

	} else {
		printf("The student does not exist in the list.");
	}


}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/

	for(int i = 0; i < *sizePtr; i++){
		free(list[i]); //deallocate the student stored in memory in the list at i
	}

	free(list); //deallocate the list
	*sizePtr = 0; // set the number of students to 0
}

void call_all_functions(char *filename_classlist, char *filename_classgrades, char *filename_classfinalgrades){

	int size;

	student **list = create_class_list(filename_classlist, &size);

	input_grades(filename_classgrades, list, size);

	compute_final_course_grades(list, size);

	output_final_course_grades(filename_classfinalgrades, list, size);

	withdraw(5555, list, &size); // unsuccessful withdraw
	withdraw(1200, list, &size); // successful withdraw
	withdraw(9000, list, &size); // successful withdraw

	destroy_list(list, &size);

}
