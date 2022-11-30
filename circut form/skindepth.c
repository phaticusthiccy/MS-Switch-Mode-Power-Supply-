#include <stdio.h>
// #include <conio.h>  
#include <math.h>
#include <stdlib.h>

int skinDepth() {
    int frequency;
    double conductor;
    char metal[20];
    double metal_conductor;
    double resistance;
    puts("Enter frequency :: (0 = 50KHz)");
    scanf("%d", &frequency);
    if (frequency == 0) frequency = 500000;
    puts("Enter conductor resistivity :: (0 = 1)");
    scanf("%lf", &conductor);
    if (conductor == 0) frequency = 1;
    puts("Enter conductor metal name :: (0 = Silver)");
    scanf("%s", &metal);
    if (metal == "al" || metal == "aluminium" || metal == "cu" || metal == "copper" || metal == "gold" || metal == "silver" || metal == "nickel") {
        if (metal == "aluminium" || metal == "al") metal_conductor = 12.9;
        if (metal == "copper") metal_conductor = 9.7;
        if (metal == "gold") metal_conductor = 2.1;
        if (metal == "nickel") metal_conductor = 4.5;
        if (metal == "silver") metal_conductor = 19.8;
        puts("Enter resistance :: (0 = 220kOHM)");
        scanf("%lf", &resistance);
        if (resistance == 0) frequency = 220000;
        return printf("forumala: %lf \nr-sensivity: %lf", (metal_conductor / (3.14159265*frequency*resistance)), (metal_conductor / (3.14159265*frequency*metal_conductor*4*3.14159265*0.0000001)));
    } else {
        return printf("conductor metal must be non-metal super conductor");
    }
}
// epsilon skin depth sensivity and amphere way. 22.5 degree, 1,231722238826 atm, 270A, 311V (default test env)
// conductor non-metal silver must be pure. (gold may include %3 of alloy)
// nickel may include %7 of stainless stell alloy

// skin depth pretty accurite with sensivity of amphere way, (using silver may be out of the cable)