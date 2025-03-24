#include <stdio.h> //gets standard C library

void findPoints(int score) { //function findPoints that takes an int score
    for (int td2pt = 0; td2pt * 8 <= score; td2pt++) { //loop that runs as many times as td+2pts fits in score
        for (int td1pt = 0; td1pt * 7 <= score; td1pt++) { //loop that runs as many times as td+1pt fits in score
            for (int td = 0; td * 6 <= score; td++) { //loop that runs as many times as td fits in score
                for (int fg = 0; fg * 3 <= score; fg++) { //loop that runs as many times as fg fits in score
                    for (int safety = 0; safety * 2 <= score; safety++) { //loop that runs as many times as safety fits in score
                        if (td2pt * 8 + td1pt * 7 + td * 6 + fg * 3 + safety * 2 == score) { //runs if combinations of points add up to score
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, td1pt, td, fg, safety); //prints score combination
                        } //ends if statement
                    } //ends for loop
                } //ends for loop
            } //ends for loop
        } //ends for loop
    } //ends for loop
} //ends function

int main() { //function main that runs when program starts
    int score; //initializes int score

    while (1) { //runs indefinitely
        printf("Enter 0 or 1 to STOP\n"); //prints text
        printf("Enter the NFL score: "); //prints text
        scanf("%d", &score); //sets score equal to next user input int 

        if (score <= 1) { // (lines 27-29) breaks loop if score is 0 or 1
            break; 
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score); //prints text with score
        findPoints(score); //calls findPoints which prints all possible score combinations that add up to score
    } //ends while loop

    return 0; //default return value
} //ends main function