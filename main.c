#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char Nombre[30];
    char Apellido[30];
    char Direccion[30];
    int Numero;
}Contacto;

int i;

int Contactos;

int main()
{
    int opc = 1;
    Contacto vec[100];

    printf("Cuantos contactos quieres cargar en la agenda?\n");
    scanf("%d" , &Contactos);

    cargarContactos(vec);
    system("cls");

    do
    {
        printf("\n---------------------------\n");
        printf("---------------------------\n");
        printf("-    Agenda Telefonica    -\n");
        printf("-                         -\n");
        printf("-        0 - Salir        -\n");
        printf("- 1 - Imprimir Contactos  -\n");
        printf("-   2 - Buscar Contacto   -\n");
        printf("-   3 - Editar Contacto   -\n");
        printf("-                         -\n");
        printf("-                         -\n");
        printf("---------------------------\n");
        printf("---------------------------\n");
        printf("\n");
        scanf("%d" , &opc);

        switch(opc)
        {
            case 0:
                return 0;
                break;
            case 1:
                system("cls");
                imprimirContactos(vec);
                break;
            case 2:
                system("cls");
                buscarContacto(vec);
                break;
            case 3:
                system("cls");
                editarContacto(vec);
                break;
            default:
                printf("Has elegido una opcion invalida.");
                break;
        }
    }while(opc != 0);
    return 0;
}

void cargarContactos(Contacto vec[Contactos])
{
    for(i=0;i<Contactos;i++)
    {
        system("cls");
        printf("Contacto %d\n" , i+1);
        printf("\n");
        fflush(stdin);
        printf("Ingresa el nombre del contacto.\n");
        scanf("%s" , &vec[i].Nombre);
        fflush(stdin);
        printf("Ingresa el apellido del contacto.\n");
        scanf("%s" , &vec[i].Apellido);
        fflush(stdin);
        printf("Ingresa la direccion del contacto.\n");
        fgets(vec[i].Direccion,sizeof(vec[i].Direccion),stdin);
        fflush(stdin);
        printf("Ingresa el numero de telefono del contacto.\n");
        scanf("%d" , &vec[i].Numero);
    }
    system("pause");
}

void imprimirContactos(Contacto vec[Contactos])
{
    for(i=0;i<Contactos;i++)
    {
        printf("Contacto %d\n" , i+1);
        printf("\n");
        printf("Nombre: %s\n" , vec[i].Nombre);
        printf("Apellido: %s\n" , vec[i].Apellido);
        printf("Direccion: %s" , vec[i].Direccion);
        printf("Numero de telefono: %d\n" , vec[i].Numero);
        printf("\n");
        printf("-----------------------------------------\n");
    }
    system("pause");
    system("cls");
}

void buscarContacto(Contacto vec[Contactos])
{
    int encontrado = 0;
    char nombre[30];
    char apellido[30];

    fflush(stdin);
    printf("Ingrese el nombre del contacto a buscar.\n");
    gets(nombre);
    fflush(stdin);
    printf("Ingrese el apellido del contacto a buscar.\n");
    gets(apellido);
    fflush(stdin);

    for(i=0;i<Contactos;i++)
    {
        if(strcmp(nombre, vec[i].Nombre) == 0 && strcmp(apellido, vec[i].Apellido) == 0)
        {
            encontrado = -1;
            printf("Contacto Encontrado!\n");
            printf("\n");
            printf("Contacto %d\n" , i+1);
            printf("\n");
            printf("Nombre: %s\n" , vec[i].Nombre);
            printf("Apellido: %s\n" , vec[i].Apellido);
            printf("Direccion: %s" , vec[i].Direccion);
            printf("Numero de telefono: %d\n" , vec[i].Numero);
        }
    }
    if(encontrado != -1)
        printf("El contacto no se encontro.\n");

    system("pause");
    system("cls");
}

void editarContacto(Contacto vec[Contactos])
{
    int encontrado = 0;
    char nombre[30];
    char apellido[30];

    fflush(stdin);
    printf("Ingrese el nombre del contacto a buscar.\n");
    gets(nombre);
    fflush(stdin);
    printf("Ingrese el apellido del contacto a buscar.\n");
    gets(apellido);
    fflush(stdin);

    for(i=0;i<Contactos;i++)
    {
        if(strcmp(nombre, vec[i].Nombre) == 0 && strcmp(apellido, vec[i].Apellido) == 0)
        {
            encontrado = -1;
            printf("Contacto %d\n" , i+1);
            printf("\n");
            printf("Nombre: %s\n" , vec[i].Nombre);
            printf("Apellido: %s\n" , vec[i].Apellido);
            printf("Direccion: %s" , vec[i].Direccion);
            printf("Numero de telefono: %d\n" , vec[i].Numero);
            printf("\n");
            printf("---------------------------------\n");
            printf("\n");

            fflush(stdin);
            printf("Ingresa nuevo nombre del contacto.\n");
            scanf("%s" , &vec[i].Nombre);
            fflush(stdin);
            printf("Ingresa nuevo apellido del contacto.\n");
            scanf("%s" , &vec[i].Apellido);
            fflush(stdin);
            printf("Ingresa nueva direccion del contacto.\n");
            fgets(vec[i].Direccion,sizeof(vec[i].Direccion),stdin);
            fflush(stdin);
            printf("Ingresa nuevo numero de telefono del contacto.\n");
            scanf("%d" , &vec[i].Numero);
        }
    }
    if(encontrado != -1)
        printf("El contacto no se encontro.\n");

    system("pause");
    system("cls");
}
