#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "passwords.h"

//functions
void ten_k(char *haystack, char *needle);
void leet(char *haystack, char *needle);
void plus_one(char *haystack, char *needle);
void entropy(char *needle);

int main(int argc, char *argv[]) {
        //exit program if more or less than 2 arguments provided
        if( argc != 3 ) {
                printf("2 arguments expected\n", argv[1]);
                return -1;
        }

        //haystack will hold the passwords, needle is the user's input
	char *haystack;
        char *needle = argv[2];
	int i;

	//trigger 10k function if user chooses it
        if(!strcmp(argv[1], "10k")) {
		printf("10k: ");
                for(i = 0; i < 10000; i++) {
                        haystack = passwords[i];
                        ten_k(haystack, needle);
                }
		if(i = 10000) {
			printf("no match\n");
		}
	}

	//trigger l33t function if user chooses it
        if(!strcmp(argv[1], "l33t")) {
		printf("l33t: ");
                for(i = 0; i < 10000; i++) {
                        haystack = passwords[i];
                        leet(haystack, needle);
                }
		if(i = 10000) {
                        printf("no match\n");
                }
        }

	//trigger plus1 function if user chooses it
        if(!strcmp(argv[1], "plus1")) {
		printf("plus1: ");
                for(i = 0; i < 10000; i++) {
                        haystack = passwords[i];
                        plus_one(haystack, needle);
                }
		if(i = 10000) {
                        printf("no match\n");
                }
        }

	//trigger entropy function if user chooses it
        if(!strcmp(argv[1], "entropy")) {
                entropy(needle);
        }

        return 0;

}

//calculates the entropy of a given input
void entropy(char* needle) {
	double N = strlen(needle);
	double possible_characters = 0;
	double result = 0;
	int entropy = 0;
	int j = 0;

	//increments amount of possible characters based on values within string
	//upper case letters
	while(needle[j] != '\0') {
		if(needle[j] >= 'A' && needle[j] <= 'Z') {
			possible_characters += 26;
			break;
		}
		j++;
	}
	j = 0;
	//lower case letters
        while(needle[j] != '\0') {
                if(needle[j] >= 'a' && needle[j] <= 'z') {
                        possible_characters += 26;
                        break;
                }
                j++;
        }
        j = 0;
	//digits
        while(needle[j] != '\0') {
                if(needle[j] >= '0' && needle[j] <= '9') {
                        possible_characters += 10;
                        break;
                }
                j++;
        }
        j = 0;
	//non-letter, non-digit, printable characters
        while(needle[j] != '\0') {
                if(isprint(needle[j]) && !(needle[j] >= 'A' && needle[j] <= 'Z') && !(needle[j] >= 'a' && needle[j] <= 'z') && !(needle[j] >= '0' && needle[j] <= '9')) {
                        possible_characters += 32;
                        break;
                }
                j++;
        }

	//calculate entropy using log equation
	result = pow(possible_characters, N);
	result = log2(result);
	entropy = result;
	printf("bits of entropy: %d\n", entropy);
}

//substitues "l33t speak" transformations in a given input, then identifies if that value matches a password
void leet(char *haystack, char *needle) {
	int j = 0;
	while(needle[j] != '\0') {
		switch (needle[j]) { //switch cases to substitute values
			case '0':
				needle[j] = 'o';
				break;
			case '3':
				needle[j] = 'e';
				break;
			case '!':
				needle[j] = 'i';
				break;
			case '@':
				needle[j] = 'a';
				break;
			case '#':
				needle[j] = 'h';
				break;
			case '$':
				needle[j] = 's';
				break;
			case '+':
				needle[j] = 't';
				break;
		}
		j++;
	}
	ten_k(haystack, needle); //inputs value into "10k" function
}

//identifies if there's a "1" at the end of an input, takes out that "1" and then compares to passwords
void plus_one(char *haystack, char *needle) {
	int N = strlen(needle);
	if(needle[N-1] == '1') { //turn "1" into null character
		needle[N-1] = '\0';
	}
	ten_k(haystack, needle); //inputs value into "10k" function
}

//compares any given input to a password 
void ten_k(char *haystack, char *needle) {
	int N = strlen(needle);
	int j;
      	int i;

      	for(i = 0; i <= N; i++) { //for loop to iterate the letters of the input and the password
          	j = 0;
              	while(needle[j] != '\0') { 
			if(needle[j] != haystack[i+j]) { //if-statement to check if each character matches, breaks if one character is off
                       		return;
                      	}
                      	j++;
                      	if(needle[j] == '\0' && haystack[i+j] == '\0') { //if this if-statement is reached, password found, exits program
				printf("match\n");
				exit(0);
                       	}
              	}
     	}
}
