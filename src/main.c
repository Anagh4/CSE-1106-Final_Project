#include <stdio.h>
void clear_input_buffer(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}
int main(void) {
  double min_temp = 68;
  double max_temp = 74;
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
  printf("Current range is %.2lf to %.2lf", 
         &min_temp, &max_temp);
  return 0;
}
