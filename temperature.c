
#include <stdio.h> // (lines 1-2) gets standard C library
#include <stdlib.h>

void weatherAdvisory(float temp) { // function that takes a float and prints text
    if (temp < 0) { // runs if temp is less than zero
        printf("Temperature Category: Freezing\n"); // (lines 7-8) prints text
        printf("Weather Advisory: Stay indoors\n");
    } else if (0 <= temp && temp < 10) { // runs if temp is 0 or above but lower than 10
        printf("Temperature Category: Cold\n"); // (lines 10-11) prints text
        printf("Weather Advisory: Wear a jacket\n");
    } else if (10 <= temp && temp < 25) { // runs if temp is 10 or above but lower than 25
        printf("Temperature Category: Comfortable\n"); // (lines 13-14) prints text
        printf("Weather Advisory: You should feel comfortable\n");
    } else if (25 <= temp && temp < 35) { // runs if temp is 25 or above but lower than 35
        printf("Temperature Category: Hot\n"); // (lines 16-17) prints text
        printf("Weather Advisory: Stay hydrated outdoors\n");
    } else { // runs if temp is 35 or above
        printf("Temperature Category: Extreme Heat\n"); // (lines 19-20) prints text
        printf("Weather Advisory: Stay indoors");
    } //ends if statement
} //ends function

float celsius_to_fahrenheit (float celsius) { return (9.0/5.0) * celsius + 32; } //function that takes a temp in celsius and converts it to fahrenheit
float fahrenheit_to_celsius (float fahrenheit) { return (5.0/9.0) * (fahrenheit - 32); } //function that takes a temp in fahrenheit and converts it to celsius
float celsius_to_kelvin (float celsius) { return celsius + 273.15; } //function that takes a temp in celsius and converts it to kelvin
float kelvin_to_celsius (float kelvin) { return kelvin - 273.15; } //function that takes a temp in kelvin and converts it to celsius

int main() { //function main that runs when program starts
    float temp, temp_celsius; //initializes two floats temp and temp_celsius
    int temp_input, temp_output; //initializes two ints temp_input and temp_output

    printf("Enter the temperature: "); //prints text
    scanf("%f", &temp); //sets temp to next float that user inputs

    printf("\nChoose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: "); //prints text
    scanf("%d", &temp_input); //sets temp_input to next int that user inputs

    printf("\nConvert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: "); //prints text
    scanf("%d", &temp_output); //sets temp_output to next int that user inputs

    if (temp_input != 1) { //runs if user didn't input 1 for temp_input, representing celsius
        if (temp_input == 2) { //runs if user input 2 for temp_input, representing fahrenheit
            temp_celsius = fahrenheit_to_celsius(temp); //sets temp_celsius equal to temp converted from fahrenheit to celsius
        } else { //runs if user input 3 for temp_input, representing kelvin
            temp_celsius = kelvin_to_celsius(temp); //sets temp_celsius equal to temp converted from kelvin to celsius
        } // ends if statement
    } else { //runs if user input 1 for temp_input, representing celsius
        temp_celsius = temp; //sets temp_celsius equal to temp, since temp is in celsius
    } //ends if statement

    // (line 53) runs for as long as temp_input equals temp_output and both temp_input or temp_output don't equal 1, 2, or 3
    while (temp_input == temp_output || (temp_input != 1 && temp_input != 2 && temp_input != 3) || (temp_output != 1 && temp_output != 2 && temp_output != 3)) {
        printf("Invalid conversion choices\n"); //prints text
        printf("\nChoose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: "); //prints text
        scanf("%d", &temp_input); //sets temp_input equal to next int that user inputs

        printf("\nConvert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: "); //prints text
        scanf("%d", &temp_output); //sets temp_input equal to next int that user inputs
    } //ends while loop

    while (temp_celsius < -273.15 || temp_celsius > 100) { //runs for as long as temp_celsius is less than 0 K or more than 100 degrees celsius
        printf("Invalid temperature\n"); //prints text
        printf("Enter another temperature: "); //prints text
        scanf("%f", &temp); //sets temp equal to next float that user inputs

        if (temp_input != 1) { //runs if user didn't input 1 for temp_input, representing celsius
            if (temp_input == 2) { //runs if user input 2 for temp_input, representing fahrenheit
                temp_celsius = fahrenheit_to_celsius(temp); //sets temp_celsius equal to temp converted from fahrenheit to celsius
            } else { //runs if user input 3 for temp_input, representing kelvin
                temp_celsius = kelvin_to_celsius(temp); //sets temp_celsius equal to temp converted from kelvin to celsius
            } // ends if statement
        } else { //runs if user input 1 for temp_input, representing celsius
            temp_celsius = temp; //sets temp_celsius equal to temp, since temp is in celsius
        } //ends if statement
    } //ends while loop

    if ((temp_input == 2) && (temp_output == 1)) { //runs if temp_input and temp_output equal 2 and 1 respectively
        printf("Converted temperature: %fºC\n", fahrenheit_to_celsius(temp)); //prints converted temperature from fahrenheit to celsius
    } else if ((temp_input == 1) && (temp_output == 2)) { //runs if temp_input and temp_output equal 1 and 2 respectively
        printf("Converted temperature: %fºF\n", celsius_to_fahrenheit(temp)); //prints converted temperature from celsius to fahrenheit
    } else if ((temp_input == 1) && (temp_output == 3)) { //runs if temp_input and temp_output equal 1 and 3 respectively
        printf("Converted temperature: %f K\n", celsius_to_kelvin(temp)); //prints converted temperature from celsius to kelvin
    } else if ((temp_input == 3) && (temp_output == 1)) { //runs if temp_input and temp_output equal 3 and 1 respectively
        printf("Converted temperature: %fºC\n", kelvin_to_celsius(temp)); //prints converted temperature from kelvin to celsius
    } else if ((temp_input == 2) && (temp_output == 3)) { //runs if temp_input and temp_output equal 2 and 3 respectively
        printf("Converted temperature: %f K\n", celsius_to_kelvin(fahrenheit_to_celsius(temp))); //prints converted temperature from fahrenheit to kelvin
    } else if ((temp_input == 3) && (temp_output == 2)) { //runs if temp_input and temp_output equal 3 and 2 respectively
        printf("Converted temperature: %fºF\n", celsius_to_fahrenheit(kelvin_to_celsius(temp))); //prints converted temperature from kelvin to fahrenheit
    } //ends if statement

    weatherAdvisory(temp_celsius); //calls function weatherAdvisory with celsius temp input
    return 0; // default return value
} //ends main function