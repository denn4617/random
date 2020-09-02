/* Opgave 9 (Side 124 - IMPR bog) */
#include <stdio.h>

int main(void){
    int length_yard, 
        width_yard, 
        length_house, 
        width_house,
        cutting_speed, 
        grass_area,
        time;
        
printf("Enter the width of your yard: ");
scanf(" %d", &width_yard);

printf("Enter the length of your yard: ");
scanf(" %d", &length_yard);

printf("Enter the width of your house: ");
scanf(" %d", &width_house);

printf("Enter the length of your house: ");
scanf(" %d", &length_house);

printf("Enter the speed you lawn your yard: ");
scanf(" %d", &cutting_speed);

grass_area = (length_yard * width_yard) - (length_house * width_house),
time = grass_area / cutting_speed;

printf("The total grass area is: %d\n", grass_area);

printf("The total time required to cut the grass is %d", time);
return 0;
}
