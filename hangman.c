/*	File name: hangman.c
/	Written by: Samara Overvaag
/	Playable 2P hangman game using string library
/	Status: running
/
/	CSC 250 - DSU - Sophia Lewis
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char hang[7] = "HANGMAN";  //letters to output for incorrect guesses
	char word[30]; //secret word specified before the game starts
	char user;  //user input for guessing
	int len; //length of secret word


	//"title screen" prompt:
	printf(" ------------------------- \n");
	printf("|   H A N G M A N ! ! !   |\n");
	printf(" ------------------------- \n");
	printf("\n");
	printf("P1, enter the secret word: ");
	//////////

	//get secret word using fgets()
	fgets(word, sizeof(word), stdin);

	//clear the screen so player 2 can't see the secret word
	system("clear");

	//replace newline with null terminator
	len = strlen(word);
	len--;
	word[len] = '\0';

	/////////DEBUG
	//puts(word);//debugging purposes
	//printf("%lu\n", sizeof(word));

	//fill show array with dashes for the length of the secret word
	//  followed by a null terminator
	char show[30]={'_','_','_','_','_','_','_','_','_','_',
					'_','_','_','_','_','_','_','_','_','_',
					'_','_','_','_','_','_','_','_','_','\0'};

	//////////DEBUG
	//puts(show);
	//printf("%lu\n", sizeof(show));

	//prompt for P2
    printf(" ------------------------- \n");
    printf("|   H A N G M A N ! ! !   |\n");
    printf(" ------------------------- \n");
	printf("P2, guess the word!\n");
	//

	//game logic goes here
	int right = 0; //for correct guess
	int wrong = 0; //for incorrect guess

//begin loop
	while(right < len && wrong < 7){
		//printing the prompt (Secret word: _ _ _ _ _ _ ...)
		//number of dashes = length of word chosen
    	printf("Secret word:");
    	for(int i = 0; i < len; i++)
        	printf("%2c",show[i]); //from the array of dashes

    	printf("\n");
		printf("\n");

		//taking input from user, either correct or incorrect
		printf("Guess a letter: ");
		scanf(" %c", &user);

		//correct answer:
		//compare input to the elements of word[]
		int guess = 0;
		for(int i = 0; i < len; i++){
			//if input = an element of word[]
			if(word[i] == user){
				show[i] = user;	//set replace _ with char
				guess = 1;		//correct guess
				right++;		//adds to correct guess counter
				printf("Correct!\n");
				//printf("%2c",show);
			}
		}

		//if guess is false
		if(guess != 1){
			printf("Incorrect.\n");
			printf("%c", hang[wrong]);	//prints corresponding element of hang[]
			wrong++;	//adds to incorrect guess counter
			printf("\n");
			}
		//printf("\n\nincorrect guesses: %d\n\n",wrong);
	}//end loop

	//correct guesses = length, P2 is congratulated
	if(right == len)
       printf("Yippee! You did it: %s\n", word);

	//upon reaching 7 incorrect guesses, game ends and the secret word is revealed
	if(wrong >= 7)
		printf("HANGMAN\n\nGame over! The secret word was: %s.\n", word);

	return 0;


}