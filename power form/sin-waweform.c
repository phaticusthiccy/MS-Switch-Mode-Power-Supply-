#include <stdio.h>
// #include <conio.h>  
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double vi;
    double teta;
    double vmax;
    puts("Enter Max Voltage :: ");
    scanf("%lf", &vmax);
    puts("Enter Teta :: ");
    scanf("%lf", &teta);
    system("cls");
    if (teta > 360 || teta < 0) {
        return puts("Teta Must Be Between 0-360!");
    }
    // The instantaneous values of a sinusoidal waveform is given 
    // as the “Instantaneous value = Maximum value x sin θ ” and this is 
    // generalized by the formula.

    // Where, Vmax is the maximum voltage induced in the coil 
    // and θ = ωt, is the rotational angle of the coil with respect to time.
    double absn = abs((vmax * sin(teta)));
    return printf("Output :: %lf to %lf", vmax * sin(teta), absn);
}