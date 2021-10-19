//
//  main.c
//  Quesiti
//
//  Created by Rocco Carpi on 05/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, const char * argv[]) {
   
    FILE *f;
    f = fopen("quesiti.txt", "r");
    char c = 0;
    int input;
    int stampa = 0;
    if (!f)
    {
        printf("errore apertura file quesiti.txt \n");
        exit(0);
    }
    
   
    printf("inserire un numero ");
    scanf("%d", &input);
    
   
   
   
    while (fscanf(f,"%c",&c) == 1)  {
        
        if (c == '@')
        {
            fscanf(f,"%c",&c);
            if ((int)(c - '0') == input)
            {
                stampa = 1;
            }else
            {
                stampa = 0;
            }
            continue;
                
        }
        if (stampa == 1) {
            printf("%c",c);
        }
        
        
    }
   
    fclose(f);
    return 0;
}
