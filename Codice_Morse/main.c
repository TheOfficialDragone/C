//
//  main.c
//  Codice_Morse
//
//  Created by Rocco Carpi on 15/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct codice {
    char lettera;
    char codice [50];
};


int main(int argc, const char * argv[]) {
   
    FILE *f;
    
    struct codice alfabeto [28];
    
    f = fopen("morse.txt", "r");
    
    if(!f)
    {
        printf("errore nell'apertura del file morse.txt \n");
        exit(0);
        
    }
    
    int i = 0;
    char temporanea [50];
    char parola_input [50];
    
    
    while (fscanf(f, " %c %[^\n]", &alfabeto[i].lettera,temporanea) == 2)  //leggo e memorizzo  file
    {
        fflush(stdin);
        strcpy(alfabeto[i].codice,temporanea);
        ++i;
    }
    
    printf("inserire una parola: ");
    scanf(" %s",parola_input);
    
    for(i = 0; i<strlen(parola_input); i++)
    {
        parola_input[i] = toupper(parola_input[i]);
    }
    
    int j;
    //decodifico la parola passata
    printf("equivalente in codice morse della parola inserita: \n");
    
    for (j = 0; j<strlen(parola_input); j++)
    {
        for(i = 0; i < sizeof(alfabeto);i++)
        {
            if (parola_input[j] == alfabeto[i].lettera)
            {
                printf("%s ",alfabeto[i].codice);
                break;
            }
        }
    }
    
    printf("\n");
   
    fclose(f);
    return 0;
}
