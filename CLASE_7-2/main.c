#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MiBiblioteca.h"

int BuscarLibre(char Matriz[][56],int* Indice, int Len);
int BuscarNombre (char* pNombre,char list[][56],int len, int* pindice);
int main()
{

    int i=0;
    int opcion;
    int indice;
    int poseliminar;
    char buffer[20];
    char nombres [100][56];
    for(i=0;i<100;i++)
    {
        nombres[i][0]='\0';

    }
    nombres[0][0]='a';
    nombres[1][0]='t';
  /*  for(i=0;i<5;i++)
    {
        printf("inicio %s\n",nombres[i]);

    }*/

    while(1)
    {
        getNumber(&opcion,"1-ingresar\n2-listar\n4-eliminar\n","error\n",1,10,2);
        switch(opcion)
        {
            case 1:
            {
                printf("ingresar nombre\n");
                if(BuscarLibre(nombres,&indice,100)==0)
                {
                    printf("se encontro lugar en: %d \n",indice);
                    getString(buffer,"ingrese nombre","error",1,20,2);
                    strncpy(nombres[indice],buffer,20);
                }
                break;
            }
            case 4:
            {
                    if(getString(buffer,"ingrese nobre","error",1,20,2)==0)
                    {
                        if(BuscarNombre(buffer,nombres,100,&poseliminar)==0)
                        {
                            nombres[poseliminar][0]='\0';
                        }

                    }
                    break;
            }

        }

    }
    return 0;
}

int BuscarNombre (char* pNombre,char list[][56],int len, int* pindice)
{
    int i;
    int retorno=-1;
    for(i=0;i<len;i++)
    {
        if(strcmp(pNombre,list[i])==0)
        {
            *pindice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}


int BuscarLibre(char Matriz[][56],int* Indice, int Len)
{
int retorno=-1;
int i;
    for(i=0;i<Len;i++)
    {
        if(Matriz[i][0]=='\0')
        {
            *Indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}











