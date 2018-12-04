 #include<stdio.h>

int main(int argc, char *argv[]) {
    
    int birth_year, birth_month, total_days, days_of_a_year = 0, days_of_a_leap_year = 0, year, days = 0, days_of_birth_month = 0, start_day = 1, number_of_spaces, joker, k;
    const int YEAR = 365, LEAP_YEAR = 366, THIRTY_ONE = 31, THIRTY = 30, TWENTY_EIGHT = 28, TWENTY_NINE = 29;

    printf("Enter birthdate: ");
    scanf("%d/%d", &birth_month, &birth_year);
    
    if(((birth_month >= 1) && (birth_month <= 12)) && ((birth_year >= 1582) && (birth_year <= 2017))) 
        printf("\n#\n");
    
    else {
        do {
            printf("ERROR: Month must be between 1 and 12 and year between 1582 and 2017.\n");
             printf("Enter birthdate: ");
            scanf("%d/%d", &birth_month, &birth_year);
        }
        while(((birth_month < 1) || (birth_month > 12)) || ((birth_year < 1582) || (birth_year > 2017)));
        printf("\n#\n"); // End of phase 1.
    }
    
    year = birth_year;
    
    for(; year <= 2017; year++) {
        if (((year % 4 == 0) && (year % 100 !=0)) || (year % 400 == 0)) { // Seperating the leap years from the normal ones, then adding them together.
            days_of_a_leap_year += LEAP_YEAR;
        }
        else {
            days_of_a_year += YEAR;
        }
    }
    total_days = days_of_a_leap_year + days_of_a_year;
    
    printf("\n1/1/%d to 1/1/2018: %d days\n", birth_year, total_days);
    printf("\n#\n"); // End of phase 2.
    
    switch (birth_month) {
        case 12: { days_of_birth_month = THIRTY_ONE;
                    break;
                }
        
        case 11: { days_of_birth_month = THIRTY;
                    break;
                }
        
        case 10: { days_of_birth_month = THIRTY_ONE;
                    break;
                }
        
        case 9: { days_of_birth_month = THIRTY;
                    break;
                }
        
        case 8: { days_of_birth_month = THIRTY_ONE;
                    break;
                }
        
        case 7: { days_of_birth_month = THIRTY_ONE;
                    break;
                }
        
        case 6: { days_of_birth_month = THIRTY;
                    break;
                }
        
        case 5: { days_of_birth_month = THIRTY_ONE;
                    break;
                }
        
        case 4: { days_of_birth_month = THIRTY;
                    break;
                }
        
        case 2: {
            if (((birth_year % 4 == 0) && (birth_year % 100 !=0)) || (birth_year % 400 == 0)) {
                days_of_birth_month = TWENTY_NINE;
                break;
            }
            else {
                days_of_birth_month = TWENTY_EIGHT;
                break;
                }
        }
        case 3: { days_of_birth_month = THIRTY_ONE;
                    break; 
                }
        
        case 1: days_of_birth_month = THIRTY_ONE;
    }

    switch (birth_month) {
        case 12: days += THIRTY; // From November to December we need 30 days and so on.
        
        case 11: days += THIRTY_ONE;
        
        case 10: days += THIRTY;
        
        case 9: days += THIRTY_ONE;
        
        case 8: days += THIRTY_ONE;
        
        case 7: days += THIRTY;
        
        case 6: days += THIRTY_ONE;
        
        case 5: days += THIRTY;
        
        case 4: days += THIRTY_ONE;
        
        case 3: {
            if (((birth_year % 4 == 0) && (birth_year % 100 !=0)) || (birth_year % 400 == 0)) {
                days += TWENTY_NINE;
            }
            else
                days += TWENTY_EIGHT;
        }
        case 2: days += THIRTY_ONE; // From January to February we need 31 days. So if birth_month = 2 that means we have to add the days from 1/1 to 1/2.
    }
    total_days = total_days - days;
    
    printf("Birthday to 1/1/2018: %d days\n\n", total_days); // End of phase 3.
    
    for(k = total_days; k > 0; k--) { // start_day = 1 shmainei oti ksekiname apo 1/1/2018 kai pame pros ta pisw
        start_day--;
        if(start_day == 0)
            start_day = 7;
    }
    
    joker = start_day;
    
    printf("Mon Tue Wed Thu Fri Sat Sun\n");
    
    number_of_spaces = start_day - 1;
    
    for(k = 0; k < number_of_spaces; k++) {
        printf("    ");
    }
    
    printf("%3d",1);
    
    for(k = 2; k <= days_of_birth_month; k++) {
        
        if((++joker) == 8){
            joker = 1;
            printf("\n");
            printf("%3d",k);
        }
                
        else {
                printf(" ");
                printf("%3d",k);
            }
        
    }
    
    printf("\n"); //End of phase 4.
    
    return(0);

}
