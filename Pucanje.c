#include<stdlib.h>
#include<stdio.h>


int compare(const void *bottle1, const void *bottle2) {
    return ( *(unsigned long long int*)bottle2 - *(unsigned long long int*)bottle1);
}
int main() {
    unsigned long number_of_bottles;
    unsigned long long int *power_of_each_bottle;
    unsigned long i;
    unsigned long long int num_of_shots = 0;


    scanf("%lu", &number_of_bottles);

    power_of_each_bottle = (unsigned long long int*)malloc(number_of_bottles*sizeof(unsigned long long int));

    for(i = 0; i < number_of_bottles; i++) {
        scanf("%llu", &power_of_each_bottle[i]);
    }

    //za limenku i snage a(i) pod uvjetom da je prije tog srusio x limenki
    //treba mu  a(i) * x + 1 pucnjeva

    qsort(power_of_each_bottle, number_of_bottles, sizeof(unsigned long long int), compare);

    for(i = 0; i < number_of_bottles; i++) {
        num_of_shots += power_of_each_bottle[i]*i + 1;
    }

    printf("%llu", num_of_shots);

    free(power_of_each_bottle);
    return 0;

}