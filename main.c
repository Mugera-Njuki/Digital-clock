#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{

int userChoice;
int alarmHours, alarmMinutes;
int alarmTimeInSeconds;
time_t now;

    printf("Hello!\nThis is Wallie.\n");

    while(1){

            printf("Select:\n 1. To check Time and Date\n 2. To set the Alarm clock\n");
            scanf("%d", &userChoice);

    switch (userChoice){
        case 1:

            now = time (NULL);

            char *string_now = ctime(&now);
            printf("%s \n", string_now);
             sleep(2);
         printf("Select any below to continue.\n\n");
            break;

        case 2:
                printf("Set the alarm time (24-hour format):\n");
                printf("Hours: ");
                scanf("%d", &alarmHours);

                printf("Minutes: ");
                scanf("%d", &alarmMinutes);

            alarmTimeInSeconds = alarmHours * 3600 + alarmMinutes * 60;

                printf("Alarm set for %02d:%02d\n", alarmHours, alarmMinutes);

            time_t currentTime;
            time(&currentTime);

            struct tm *localTime = localtime(&currentTime);
            int currentTimeInSeconds = localTime->tm_hour * 3600 + localTime->tm_min * 60 + localTime->tm_sec;

            int timeDifference = alarmTimeInSeconds - currentTimeInSeconds;

        if (timeDifference <= 0) {
        printf("Invalid alarm time. Please set a time in the future.\n");
        return 1;
    } else{
        printf("Waiting for the alarm...\n");
        sleep(timeDifference);

         printf("\nALARM! It's %02d:%02d\n", alarmHours, alarmMinutes);
         sleep(2);
         printf("Select any below to continue.\n\n");
}
        break;
    default:
        printf("Invalid input!\n");



    }
    }

        //scanf(" %c", &choice);

    return 0;
}
