/*
 * Name: Steven Phung
 * Project: #2
 * Due: November 15th, 2018
 * Course: cs-2560-01-f18
 *
 * Description:
 * 	Trivia game for multiple players. 10 total questions with 4 answers each.
 * 	Each round all players will be asked the same question. Total 5 rounds.
 * 	Print winner at the end, replay possible.
 */
#include <string>
#include <iostream>
#include <stdbool.h>
#include <time.h>
#include "Player.h"
#include "Question.h"

using namespace std;

//Function to quickly print out question and multiple choice answers in a specific format.
void print(Question q[], int counter);

int main1() {
	//An array of 10 question objects are created, all of question's attributes are initialized to null.
	Question questions[10];
	//Added values to each question object, including the question itself, different answers, and the correct answer.
	questions[0].setQuestion("Who painted the Mona Lisa?");
	questions[0].setPossibleAnswer1("Vincent Van Gogh");
	questions[0].setPossibleAnswer2("Leonardo da Vinci");
	questions[0].setPossibleAnswer3("Michelangelo");
	questions[0].setPossibleAnswer4("Pablo Picasso");
	questions[0].setCorrectAnswer(2);

	questions[1].setQuestion("What was the coincidental maiden name of astronaut Buzz Aldrin's mother?");
	questions[1].setPossibleAnswer1("Sun");
	questions[1].setPossibleAnswer2("Moon");
	questions[1].setPossibleAnswer3("Skye");
	questions[1].setPossibleAnswer4("Starr");
	questions[1].setCorrectAnswer(2);

	questions[2].setQuestion("What type of landform is a cay?");
	questions[2].setPossibleAnswer1("Plateau");
	questions[2].setPossibleAnswer2("Glacier");
	questions[2].setPossibleAnswer3("Mountain");
	questions[2].setPossibleAnswer4("Island");
	questions[2].setCorrectAnswer(4);

	questions[3].setQuestion("What caused a 34-minute delay at Super Bowl XLVII (45) in 2013?");
	questions[3].setPossibleAnswer1("Power Outage");
	questions[3].setPossibleAnswer2("Coach Protesting");
	questions[3].setPossibleAnswer3("Faulty Plumbing");
	questions[3].setPossibleAnswer4("Streakers");
	questions[3].setCorrectAnswer(1);

	questions[4].setQuestion("Who was the novelist that was the creator of Jurassic Park?");
	questions[4].setPossibleAnswer1("James Patterson");
	questions[4].setPossibleAnswer2("Stephen King");
	questions[4].setPossibleAnswer3("Tom Clancy");
	questions[4].setPossibleAnswer4("Michael Crichton");
	questions[4].setCorrectAnswer(4);

	questions[5].setQuestion("Which of these characters was a James Bond villain?");
	questions[5].setPossibleAnswer1("Sauron");
	questions[5].setPossibleAnswer2("Mr. Freeze");
	questions[5].setPossibleAnswer3("Nick Nack");
	questions[5].setPossibleAnswer4("General Zod");
	questions[5].setCorrectAnswer(3);

	questions[6].setQuestion("Which of these states were members of the first 13 colonies of the United States of America?");
	questions[6].setPossibleAnswer1("Alabama");
	questions[6].setPossibleAnswer2("New Hampshire");
	questions[6].setPossibleAnswer3("Kentucky");
	questions[6].setPossibleAnswer4("Louisiana");
	questions[6].setCorrectAnswer(2);

	questions[7].setQuestion("What sport does NOT involve horses?");
	questions[7].setPossibleAnswer1("Water Polo");
	questions[7].setPossibleAnswer2("Dressage");
	questions[7].setPossibleAnswer3("Pole Bending");
	questions[7].setPossibleAnswer4("Jousting");
	questions[7].setCorrectAnswer(1);

	questions[8].setQuestion("How many dots are in each level of Pac-Man?");
	questions[8].setPossibleAnswer1("300");
	questions[8].setPossibleAnswer2("150");
	questions[8].setPossibleAnswer3("240");
	questions[8].setPossibleAnswer4("400");
	questions[8].setCorrectAnswer(3);

	questions[9].setQuestion("What measurement is defined as the 220 yard distance a horse can pull a plow without resting?");
	questions[9].setPossibleAnswer1("Furlong");
	questions[9].setPossibleAnswer2("Cubit");
	questions[9].setPossibleAnswer3("Fathom");
	questions[9].setPossibleAnswer4("League");
	questions[9].setCorrectAnswer(1);

	//MAX_PLAYERS will be the limit that prevents user from inputting an extremely large number that would crash the program.
	int const MAX_PLAYERS = 10;
	//MAX_QUESTIONS indicates the amount of questions total in the program.
	int const MAX_QUESTIONS = 10;
	//counter is used to loop
	int counter = 0;
	//playerAmount keeps track of how many players are in the game.
	int playerAmount = 0;
	//loop is used to break out of smaller loops
	bool loop = true;
	//gameLoop is used to loop the entire game again or quit completely.
	bool gameLoop = true;
	//nextRound is used to indicate the 2nd round of 5 questions. (1st round = 5 questions, 2nd round = 5 questions. Total = 10 questions)
	bool nextRound = false;
	//userOption holds all user input.
	string userOption = "";
	//randomNumbers is an array that will hold the order of a randomly generated sequence of numbers.
	int randomNumbers[MAX_QUESTIONS];

	//Prevents random number from being repeated.
	srand(time(NULL));
	//Generates a sequence of random numbers from 0-9 and places it in randomNumbers.
	for (int i = 0; i < MAX_QUESTIONS; i++) {
		//rngCheck checks if number is already in the array.
		bool rngCheck;
		//int to store random number
		int rng;
		do {
			//Generates random number between 0-9.
			rng = rand() % 10;
			rngCheck = true;
			for (int j = 0; j < i; j++) {
				//If generated number is already within the array
				if (randomNumbers[j] == rng) {
					//Set check to false.
					rngCheck = false;
					//If there's a match, no need to check the rest of the elements.
					break;
				}
			}
		//Loop until a unique number has been found
		} while (!rngCheck);
		//Place unique random int into the array.
		randomNumbers[i] = rng;
	}

	cout << "Welcome to a simple trivia game!" << endl;

	//Asks for number of players, will continue to loop if input is not desired.
	do {
		loop = true;
		try {
			cout << "How many total players will play? " << endl;
			getline(cin, userOption);
			//Input must be between 0 and amount of MAX_PLAYERS to break out of loop.
			if (stoi(userOption) > 0 && stoi(userOption) < MAX_PLAYERS) {
				playerAmount = stoi(userOption);
				loop = false;
			}
			//Prevents having a large amount of players
			else if (stoi(userOption) > MAX_PLAYERS) {
				cout << endl << "Maximum players allowed: 10" << endl << endl;
			}
			//Cannot have 0 or less players
			else if (stoi(userOption) <= 0) {
				cout << endl << "Minimum players needed: 1" << endl << endl;
			}
		}
		//Catches invalid_arguement when user inputs characters that cannot be converted to int.
		catch (invalid_argument e) {
			cout << endl << "Invalid input" << endl << endl;
		}
	} while (loop);

	//Dynamic memory allocation is used to create a pointer of players to an array of players on the heap since there is no set amount of players
	Player *player = new Player[playerAmount];
	//Sets playerID for all players
	for (int i = 1; i <= playerAmount; i++) {
		player->setPlayerID(i);
		player++;
	}
	//Reset pointer to original memory address
	for (int i = 1; i <= playerAmount; i++) {
		player--;
	}

	//This do-while loop encompasses the entire game.
	do {
		//This for loop traverses the randomNumbers array and makes sure we only loop through the first 5 elements (1st round of 5 questions).
		for (int n = 0; n < MAX_QUESTIONS && counter < MAX_QUESTIONS && counter < 5 && !nextRound; n++) {
			//Assign element from randomNumbers into questionNumber;
			int questionNumber = randomNumbers[n];
			//This for loop lets every player participate for every question
			for (int i = 1; i <= playerAmount; i++) {
				//This do-while loop will print the question, answers, and ask for the player's answer.
				do {
					loop = true;
					//Prints question
					print(questions, questionNumber);
					try {
						cout << "Player " << player->getPlayerID() << ": Please enter your answer: ";
						getline(cin, userOption);
						//Current player will be repeatedly asked for input until they enter 1, 2, 3, or 4
						if (stoi(userOption) > 0 && stoi(userOption) < 5) {
							//If the player got the correct answer, it is added to the right vector
							if (questions[questionNumber].getCorrectAnswer() == stoi(userOption)) {
								player->gotRight(questions[questionNumber], questionNumber);
							}
							//If the player got the wrong answer, it is added to the other vector
							else {
								player->gotWrong(questions[questionNumber], questionNumber);
							}
							//Next player
							player++;
							//Break out of loop
							loop = false;
						}
						//If the player enters a number less than 1 or greater than 4.
						else {
							cout << endl << "Invalid input" << endl;
						}
					}
					//Catches invalid_arguement when user inputs characters that cannot be converted to int.
					catch (invalid_argument e) {
						cout << endl << "Invalid input" << endl;
					}
				//Continue to loop if input is invalid, if valid, next player gets to go.
				} while (loop);
			}
			//Reset pointer to original memory address
			for (int i = 1; i <= playerAmount; i++) {
				player--;
			}
			//Increment counter
			counter++;
		}

		//This for loop traverses the randomNumbers array and makes sure we only loop through the last 5 elements (2nd round of 5 questions).
		for (int n = 5; n < MAX_QUESTIONS && counter < MAX_QUESTIONS && counter >= 5 && nextRound; n++) {
			//Assign element from randomNumbers into questionNumber;
			int questionNumber = randomNumbers[n];
			//This for loop lets every player participate for every question
			for (int i = 1; i <= playerAmount; i++) {
				//This do-while loop will print the question, answers, and ask for the player's answer.
				do {
					loop = true;
					//Prints question
					print(questions, questionNumber);
					try {
						cout << "Player " << player->getPlayerID() << ": Please enter your answer: ";
						getline(cin, userOption);
						//Current player will be repeatedly asked for input until they enter 1, 2, 3, or 4
						if (stoi(userOption) > 0 && stoi(userOption) < 5) {
							//If the player got the correct answer, it is added to the right vector
							if (questions[questionNumber].getCorrectAnswer() == stoi(userOption)) {
								player->gotRight(questions[questionNumber], questionNumber);
							}
							//If the player got the wrong answer, it is added to the other vector
							else {
								player->gotWrong(questions[questionNumber], questionNumber);
							}
							//Next player
							player++;
							//Break out of loop
							loop = false;
						}
						//If the player enters a number less than 1 or greater than 4.
						else {
							cout << endl << "Invalid input" << endl;
						}
					}
					//Catches invalid_arguement when user inputs characters that cannot be converted to int.
					catch (invalid_argument e) {
						cout << endl << "Invalid input" << endl;
					}
				//Continue to loop if input is invalid, if valid, next player gets to go.
				} while (loop);
			}
			//Reset pointer to original memory address
			for (int i = 1; i <= playerAmount; i++) {
				player--;
			}
			//Increment counter
			counter++;
		}

		//Loops through all possible players
		for (int i = 1; i <= playerAmount; i++) {
			//Prints how many questions out of 5 the player answered correctly.
			cout << "\nPlayer " << player->getPlayerID() << " got " << player->getRightSize() << "/5 questions correct!\n";
			//Prints out each question's distinct number
			cout << "Questions correctly answered: ";
			for (int j = 0; j < player->getCorrect().size(); j++) {
				cout << "#" << (player->getCorrect()[j] + 1) << " ";
			}
			cout << endl;
			//Next player
			player++;
		}
		//Reset pointer to original memory address
		for (int i = 1; i <= playerAmount; i++) {
			player--;
		}

		//This do-while loop prints end game menu and will continue to loop until user entires correct input.
		do {
			loop = true;
			try {
				cout << "Play again?" << endl;
				cout << "  1. Play again" << endl;
				cout << "  2. Quit" << endl;
				getline(cin, userOption);
				//User input is 1
				if (stoi(userOption) == 1) {
					//Loop through all current players
					for (int i = 1; i <= playerAmount; i++) {
						//Reset player to their original state.
						player->resetPlayer();
						//Next player
						player++;
					}
					//Reset pointer to original memory address
					for (int i = 1; i <= playerAmount; i++) {
						player--;
					}
					//Starts round 2
					nextRound = true;
					//Exits this do-while loop
					loop = false;
				//User input that is greater than 2 or less than 1 is considered invalid
				} else if (stoi(userOption) >= 3 || stoi(userOption) <= 0) {
					cout << endl << "Invalid input" << endl << endl;
				//User input is 2
				} else if (stoi(userOption) == 2) {
					//Exits this do-while loop
					loop = false;
					//Exits entire game loop
					gameLoop = false;
					cout << endl << "Thank you for playing!" << endl;
					//Exit program
					exit(0);
				}
			}
			//Catches invalid_arguement when user inputs characters that cannot be converted to int.
			catch (invalid_argument e) {
				cout << endl << "Invalid input" << endl << endl;
			}
		//Continue to loop if input is invalid, if valid, restart entire game.
		} while (loop);

		if (counter >= 9) {
			//Reset counter
			counter = 0;
			//Return to round 1
			nextRound = false;

			//Generates a new sequence of random numbers from 0-9 and places it in randomNumbers.
			for (int i = 0; i < MAX_QUESTIONS; i++) {
				//rngCheck checks if number is already in the array.
				bool rngCheck;
				//int to store random number
				int rng;
				do {
					//Generates random number between 0-9.
					rng = rand() % 10;
					rngCheck = true;
					for (int j = 0; j < i; j++) {
						//If generated number is already within the array
						if (randomNumbers[j] == rng) {
							//Set check to false.
							rngCheck = false;
							//If there's a match, no need to check the rest of the elements.
							break;
						}
					}
					//Loop until a unique number has been found
				} while (!rngCheck);
				//Place unique random int into the array.
				randomNumbers[i] = rng;
			}
		}
	//True will restart entire game
	} while (gameLoop);
}

//Prints question and answers
void print(Question q[], int num) {
	cout << endl << "Q: " <<  q[num].getQuestion() << endl;
	cout << "   1. " << q[num].getPossibleAnswer1() << endl;
	cout << "   2. " << q[num].getPossibleAnswer2() << endl;
	cout << "   3. " << q[num].getPossibleAnswer3() << endl;
	cout << "   4. " << q[num].getPossibleAnswer4() << endl;
}
