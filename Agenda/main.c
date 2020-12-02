#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void crear();
void leer();
void menu();
void buscar();
void buscarn();



int main(){
    
    int opcion;
    
    
    
    printf("\nEliga una opcion!\n");
    
 
    
    do{
           
        
        
        
        menu();
        printf("\nTu opcion: ");
        scanf("%d", &opcion);
        if(opcion > 5 || opcion <=0){
        
        printf("Opcion no valida\n");}
    
        
        
        switch(opcion){
        
        
        case 1:
           
            crear();
            break;
                    
            case 2:
                leer();
                break;
        
            case 3:
                buscar();
                break;
            
            case 4:
                modificar();
                break;
            case 5:
                buscarn();
                break;
        }
    
        
       
    
    

   


 }while(opcion != 6);
 
 return 0;
}
typedef struct{
    
    int fecha;
    char nomb;
    int hora;
   char lug; 
   char tem[50];
   char dur[15];
    
    
    

}mat;

void crear(){
    
    FILE*ag;
    
   ag = fopen("Mi agenda.dat", "ab");
    
    mat dat;
    
  
    printf("Ingresa la fecha(Un espacio por numero): ");
    scanf("%d", &dat.fecha);
    fflush(stdin);
    
    printf("Ingrese el nombre del evento: ");
    gets(dat.nomb);
    fflush(stdin);
    
    printf("Ingresa la hora del evento(formato 24  hrs.)\n");
    scanf("%d", &dat.hora);
    fflush(stdin);
    
    printf("Ingresa el Lugar: \n");
    gets(dat.lug);
    fflush(stdin);
    
    printf("Ingresa el tema: \n");
    scanf("%s", &dat.tem);
    fflush(stdin);
    
    printf("Ingresa la duracion del evento \n");
    scanf("%s", &dat.dur);
    fflush(stdin);
   
    fwrite(&dat, sizeof(mat), 1, ag);
    
     fclose(ag);

}

void leer(){
   FILE*ag;   
   
   
   
   ag = fopen("Mi agenda.dat", "rb");
   
   mat dat;
  
   fread(&dat, sizeof(mat), 1, ag);
   while(!feof(ag)){
       
       printf("%d", dat.fecha);
       printf("\n%s\n %d\n", dat.nomb, dat.hora);
       printf("\n%s\n %s\n ", dat.lug, dat.tem);
       
       fread(&dat, sizeof(mat), 1, ag);
   }
    

   fclose(ag);
}

void buscar(){
    int fech;
    FILE*ag;
    
    ag = fopen("Mi agenda.dat", "rb");
    
    printf("Ingrese la fecha a consultar: ");
    scanf("%i",&fech);
    
    mat dat;
    
    fread(&dat, sizeof(mat), 1, ag);
    
    while(!feof(ag)){
        
        if(fech==dat.fecha){
            
             printf("%d %s %d\n", dat.fecha, dat.nomb, dat.hora);
             break;
        }
   
        fread(&dat, sizeof(mat), 1, ag);
        
        }
    
    if(fech != dat.fecha){
        printf("No hay evento registrado con esa fecha :c \n");
    }
    
    fclose(ag);
    
    
}
   
void modificar(){
    int fech;
    FILE*ag;
    
    ag = fopen("Mi agenda.dat", "r+b");
    
    printf("Ingrese la fecha del evento a modificar: ");
    scanf("%i", &fech);
    mat dat; 
    
    while(!feof(ag)){
        
        if(fech==dat.fecha){
            
             printf("%d %s %d\n", dat.fecha, dat.nomb, dat.hora);
              printf("Ingresa la fecha: ");
    scanf("%d", &dat.fecha);
    fflush(stdin);
    
    printf("Ingrese el nombre del evento: ");
    gets(dat.nomb);
    fflush(stdin);
    
    printf("Ingresa la hora del evento(formato 24  hrs.)\n");
    scanf("%d", &dat.hora);
    fflush(stdin);
    
    printf("Ingresa el Lugar: \n");
    gets(dat.lug);
    fflush(stdin);
    
    printf("Ingresa el tema: \n");
    scanf("%s", &dat.tem);
    fflush(stdin);
    
    printf("Ingresa la duracion del evento \n");
    scanf("%s", &dat.dur);
    fflush(stdin);
    
    int pos=ftell(ag)-sizeof(mat);
    
    fseek(ag,pos,SEEK_SET);
    fwrite(&dat,sizeof(mat), 1, ag);
    break;
        }
   
        fread(&dat, sizeof(mat), 1, ag);
        
        }
    
    if(fech != dat.fecha){
        printf("No hay evento registrado con esa fecha :c \n");
    }
    
    fclose(ag);
    
    
    
    
}

   

void buscarn()
{
    FILE *ag;
    
    ag=fopen("Mi agenda.dat","rb");
    if (ag==NULL)
        exit(1);
    printf("Ingrese el nombre del evento a consultar:");
    char aux[41];
    fflush(stdin);
    gets(aux);
    mat dat;
    
    fread(&dat, sizeof(mat), 1, ag);
    while(!feof(ag))
    {
        if (strcmp(dat.nomb,aux)==0)
        {
           printf("%d %s %d\n", dat.fecha, dat.nomb, dat.hora);
             break;
        }
        fread(&dat, sizeof(mat), 1, ag);
    }
    
    fclose(ag);
}

  void menu(){
    printf("1.- Crear nuevo evento\n");
    printf("2.- Lista de eventos\n");
    printf("3.- Buscar evento por fecha\n");
    printf("4.- Modificar evento\n");
    printf("5.- Buscar por nombre\n");
    printf("6.- Salir");
} 
