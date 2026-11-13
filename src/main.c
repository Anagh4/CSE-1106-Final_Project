#include <unistd.h>
#include <pigpio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PIN 17

void clear_input_buffer(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int main(int argc, char *argv[])
{
    double min_temp = 68;
  double max_temp = 76;
  printf("Default acceptable range: %.1f°F to %.1f°F\n", min_temp, max_temp);
  printf("Would you like to change the acceptable range? (y/n): ");
  char choice;
  if (scanf(" %c", &choice) == 1 && (choice == 'y' || choice == 'Y')) {
    clear_input_buffer();
    while (1) {
      printf("Enter new minimum temperature (°F): ");
      if (scanf("%lf", &min_temp) != 1) {
        printf("Invalid input. Please enter a number.\n");
        clear_input_buffer();
        continue;
      }
      printf("Enter new maximum temperature (°F): ");
      if (scanf("%lf", &max_temp) != 1) {
        printf("Invalid input. Please enter a number.\n");
        clear_input_buffer();
        continue;
      }
      if (min_temp > max_temp) {
        printf("Error: Minimum temperature cannot exceed maximum. Try again.\n");
      }
      else {        
        break;      
      }    
    }
  }
  clear_input_buffer();
  printf("Current range is %.2lf to %.2lf\n", min_temp, max_temp);
    //Open temperature file in append mode.
    FILE *file = fopen("temperature.txt", "w");
    if(file == NULL){
        perror("Failed to open file");
        return 1;
    }
    
    char input[100];

    //Prompt user for temperature input.
    while(1){
        printf("Input temperature Fahrenheit: ");
        fgets(input, sizeof(input), stdin);
        fprintf(file, "%s", input);
        if(strcmp(input, "exit\n") == 0){
            break;
        }
    }
    fclose(file);

    //Open temperature file in read mode.
    file = fopen("temperature.txt", "r");
    if(file == NULL){
        perror("Failed to open file");
        return 1;
    }

    char line[256];
    double average = 0;
    int count = 0;

    gpioInitialise();
    gpioSetMode(PIN, PI_OUTPUT);
    
    while(fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line, "\r\n")] = '\0';

        //Check if the line is the exit command.
        if(strcmp(line, "exit") == 0){
            //Remove the exit line from the file.
            break;
        }

        char *endptr;
        double temp = strtod(line, &endptr);

        if(*endptr != '\0' || endptr == line){
            fprintf(stderr, "Invalid temperature: %s\n", line);
            continue;
        }

        //Check if the temperature is within the normal range.
        if(temp > max_temp || temp < min_temp){
            printf("%0.2lf F.  WARNING", temp);
            fprintf(file, "WARNING\n");
            average += temp;
            count++;
            gpioWrite(PIN, 1); //LED ON
            getchar();
        }
        else{
            printf("%0.2lf F.  NORMAL", temp);
            fprintf(file, "NORMAL\n");
            average += temp;
            count++;
            gpioWrite(PIN, 0); //LED OFF
            getchar();
        }



    }
    if(count > 0){
        average /= count;
        printf("Average temperature: %0.2lf F\n", average);
    }
    fclose(file);
    printf("Exit");
    printf("LED OFF\n");
    gpioWrite(PIN, 0); //LED OFF
    gpioTerminate();
    return 0;
}
