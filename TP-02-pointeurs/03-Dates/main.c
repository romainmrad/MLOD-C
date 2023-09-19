#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum{
    janvier, 
    fevrier, 
    mars, 
    avril, 
    mai,
    juin,
    juillet,
    aout,
    septembre,
    octobre,
    novembre,
    decembre
} mois;

struct Date{
    int jour;
    mois mois;
    int annee;
};

int main(void){
    Date d;
    return 0;
}