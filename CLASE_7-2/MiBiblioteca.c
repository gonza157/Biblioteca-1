#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MiBiblioteca.h"

int getString(  char *pResultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos)
{
    int retorno=-1;
    char bufferStr[4096];
    int Largo=0;
    if(pResultado !=NULL )
    {
        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            Largo=strlen(bufferStr);
            if(Largo>=minimo && Largo<=maximo)
            {
                strncpy(pResultado,bufferStr,maximo);
                retorno=0;
                break;

            }else{
                    printf("%s",msgError);
            }
            reintentos--;
        }while(reintentos!=0);
    }


    return retorno;

}

/*{
    char bufferStr[4096];

    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';


    return 0;

}*/


int isValidIntNumber (char* cadena)
{
    int retorno=1;
    int i=0;
    if(cadena[i] == '-')
    {
        i++;
    }
    for(;cadena[i]!='\0';i++)
    {
        if(cadena[i]< '0' || cadena[i]>'9')
        {
            retorno=0;
            break;
        }

    }

    return retorno;

}


int getNumber(  int *resultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos)
{
    int retorno = -1;
    char bufferStr[4096];
    int bufferInt;

    if( resultado != NULL &&
        reintentos >= 0) //FALTAN
    {
        if(!getString(bufferStr,msg,msgError,1,6,1) &&
            isValidIntNumber(bufferStr))
        {
            bufferInt = atoi(bufferStr);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                retorno = 0;
                *resultado = bufferInt;
            }
        }
    }
    return retorno;
}
