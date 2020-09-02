#include    <stdio.h>  

#define UGE 604800
#define DAGE 86400
#define TIMER 3600
#define MINUTTER 60

int main(void){

    /* 
    * 'while-loopet' er unødvendigt, men er blevet lavet, for at kunne køre programmet uden en terminal!
    */

    int true = 1;
    while(true = 1){

        int sek_value;

        printf("Indtast antal sekuder:");

        scanf("%d", &sek_value);

        int uge = sek_value / UGE,
            dage = (sek_value % UGE) / DAGE,
            time = ((sek_value % UGE) % DAGE) / TIMER,
            minut = (((sek_value % UGE) % DAGE) % TIMER) / MINUTTER,
            sekund = ((((sek_value % UGE) % DAGE) % TIMER) % MINUTTER);

        printf("%d sekunder er tilsvarende:\nUge(r): %d\nDag(e): %d\nTime(r): %d\nMinut(ter): %d\nSekund(er): %d\n\n", sek_value, uge, dage, time, minut, sekund);
    }

    return 0;

}
