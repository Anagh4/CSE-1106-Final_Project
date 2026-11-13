void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
printf("Default acceptable range: %.1f°F to %.1f°F\n", min_temp, max_temp);
    printf("Would you like to change the acceptable range? (y/n): ");

    char choice;
    if (scanf(" %c", &choice) == 1 && (choice == 'y' || choice == 'Y')) {
        clear_input_buffer();
        while (true) {
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
            } else {
                break;
            }
        }
    }
    clear_input_buffer();
