//
//  main.c
//  Assenze
//
//  Created by Rocco Carpi on 05/04/21.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
   
    FILE *f;
    f = fopen("assenze.txt", "r");
    
    if (!f)
    {
        perror("errore apertura file!");
        exit(EXIT_FAILURE);
    }
    
    
    int lezioni = 0;
    int alunni = 0;
    fscanf(f, "%d %d",&lezioni,&alunni);
    int studenti[13] = {0};
    int temp;
    // printf("%d %d \n",alunni,lezioni);
    while (fscanf(f, "%d",&temp) == 1)
    {
        studenti[temp-1]++;
    }
    const int soglia_presenza = 70;
    int presenza_studente;
    
    for (int j = 0; j<13; j++)
    {
        presenza_studente = (lezioni - studenti[j])*10;
        if (presenza_studente <= soglia_presenza)
        {
            printf("l'alunno %d ha fatto: %d assenze,percentuale di presenza: %d insufficente \n",j+1,studenti[j],presenza_studente);
        }else
            printf("l'alunno %d ha fatto: %d assenze,percentuale di presenza: %d \n",j+1,studenti[j],presenza_studente);
    }
    fclose(f);
    return 0;
}
