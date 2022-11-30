#include <stdio.h>
// #include <conio.h>  
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double v; // voltage
    double i; // current
    double r; // resistance
    puts("Enter Voltage :: (0 = Blank)");
    scanf("%lf", &v);
    puts("\nEnter Current :: (0 = Blank)");
    scanf("%lf", &i);
    puts("\nEnter Resistance :: (0 = Blank)");
    scanf("%lf", &r);
    system("cls");
    double formul;
    if (v == 0) {
        if (i == 0 || r == 0) {
            return puts("Current and Resistance Must Be Declared!");
        } else {
            formul = (i * i) * r;
        }
    } else if (i == 0) {
        if (v == 0 || r == 0) {
            return puts("Voltage and Resistance Must Be Declared!");
        } else {
            formul = (v * v) / (r);
        }
    } else if (r == 0) {
        if (v == 0 || i == 0) {
            return puts("Voltage and Current Must Be Declared!");
        } else {
            formul = v * i;
        }
    } else {
        return puts("Something Missed About Doubles!");
    }
    delay(2000);
    printf("Voltage :: %lf\nCurrent :: %lf\nResistance :: %lf", v,i,r);
    return printf("\nOutput :: %lfW", formul);
}

void delay(int milliseconds)
{
    long durdur;
    clock_t t1,t2;

    durdur = milliseconds*(CLOCKS_PER_SEC/1000);
    t1 = t2 = clock();
    while( (t1-t2) < durdur ) t1 = clock();
}
