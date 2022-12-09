#include <stdio.h>

int rem_days(int, int);
void results(int a, int b);
int date_diff(int, int, int, int, int);
void breakdown(int);

int convert_day(int month, int day)
{
    switch (month)
    {
        case 2:
            day = 31 + day;
            break;
        case 3:
            day = 59 + day;
            break;
        case 4:
            day = 90 + day;
            break;
        case 5:
            day = 120 + day;
            break;
        case 6:
            day = 151 + day;
            break;
        case 7:
            day = 181 + day;
            break;
        case 8:
            day = 212 + day;
            break;
        case 9:
            day = 243 + day;
            break;
        case 10:
            day = 273 + day;
            break;
        case 11:
            day = 304 + day;
            break;
        case 12:
            day = 334 + day;
            break;
        default:
            break;
    }
    return (day);
}

int main(void)
{
        int result, diff;
        int s_year, s_day, s_month, new_day; /* s for start */
        int e_year, e_day, e_month, e_new_day; /*e for end */

        printf("Please enter the start date you wish to calculate in the format: yyyy/mm/dd\n");
        scanf("%d/%d/%d", &s_year, &s_month, &s_day);
        /***************************************/
        printf("Please enter the end date you wish to calculate in the format: yyyy/mm/dd\n");
        new_day = convert_day(s_month, s_day);
        result = rem_days(s_year, new_day);
        scanf("%d/%d/%d", &e_year, &e_month, &e_day); 
        diff = date_diff(s_year, result, e_year, e_month, e_day);
        printf("There are %d days between %d/%d/%d and %d/%d/%d (excluding the end date)", diff, s_year, s_month, s_day, e_year, e_month, e_day);
        breakdown(diff);
        
        
        return (0);
}

int rem_days(int year, int day)
{
        if (year % 4 == 0)
        {
                if(day > 59)
                {
                    day++;
                    return (366 - day);
                }
                else
                    return (366 - day);
        }
        else
            return (365 - day);
}

int date_diff(int f_year, int days, int year, int month, int day)
{
        int dt_range = days, yr, c_days;    
        yr = f_year + 1;

        if (year - f_year == 0)
        {   
            int day_cov;
            day_cov = convert_day(month, day);
            int days_left = rem_days(year, day_cov);
            return (dt_range - days_left);
        }
        else
        {
            while (yr < year)
            {
                if (yr % 4 == 0)
                {
                    dt_range += 366;
                }
                else
                    dt_range += 365;
                yr++;
            }
            c_days = convert_day(month, day);
            dt_range += c_days;
        }

        return (dt_range);
} 

void breakdown(int data)
{
    if (data % 7 != 0)
        printf("\n--> %d weeks %d days\n", data/7, data%7);
    else
        printf("\n--> %d weeks", data/7);
}
