#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char Nombre[30];
    char Apellido[30];
    int Telefono[15];
    char Direccion[30];
}Agenda;

void Cargar (Agenda v[]);
void Imprimir (Agenda v[]);
void Buscar (Agenda v[]);
int Contactos;

int main()
{
    Agenda v[Contactos];
    int opcion = 1;

    do
    {

        printf("Agenda programa 1\n");
        printf("Elige una opcion valida.\n");
        printf("1- Cargar contactos en la agenda.\n");
        printf("2- Buscar contactos en la agenda.\n");
        printf("3- Imprimir contactos.\n");
        printf("0- Terminar programa.\n");
        scanf("%d" , &opcion);

        switch(opcion)
        {
            case 1:
                printf("Cuantos contactos quieres cargar?\n");
                scanf("%d" , &Contactos);
                Cargar(v);
                break;
            case 2:
                Buscar(v);
                break;
            case 3:
                break;
            default:
                system("cls");
                printf("Has insertado una opcion invalida.\n");
                break;
        }
    }while(opcion < 0 || opcion > 3);


}

void Cargar(Agenda v[])
{
    int i;
    system("cls");

    for(i=0;i<Contactos;i++)
    {
        system("cls");
        printf("Contacto numero %d\n" , i+1);
        fflush(stdin);
        printf("Escriba el nombre.\n");
        scanf("%s" , &v[i].Nombre);
        fflush(stdin);
        printf("Escriba el apellido.\n");
        scanf("%s" , &v[i].Apellido);
        fflush(stdin);
        printf("Escriba la direccion.\n");
        gets(v[i].Direccion);
        fflush(stdin);
        printf("Escriba el telefono.\n");
        scanf("%d" , &v[i].Telefono);
    }
    fflush(stdin);
    return;
}

void Buscar(Agenda v[])
{
    int i;
    system("cls");
    char busquedaN[30];
    fflush(stdin);
    printf("Escribe el nombre del contacto.\n");
    scanf("%s" , &busquedaN[30]);

    char busquedaP[30];
    fflush(stdin);
    printf("Escribe el apellido del contacto.\n");
    scanf("%s" , &busquedaP[30]);

    for(i=0;i<Contactos;i++)
    {
        if(strcmp(v[i].Nombre , busquedaN) == 0 && strcmp(v[i].Apellido , busquedaP) == 0)
        {
            printf("Nombre del contacto: %s" , v[i].Nombre);
        }
    }
}
