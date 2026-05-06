#include <stdio.h>
#include <string.h> // para comparar y manipular texto con strcmp, strcpy

struct Contacto {
	char nombre[50];
	char telefono[20];
	char email[50];
};

int main(){
	struct Contacto agenda[100];
	char buscar[50];
	int cantidad = 0;
	int opcion = 0;
	int i;
	int encontrado = 0;
	
	printf("----------------------------------------------------------------\n");	
	printf("=== Bienvenido a la agenda, elija que opcion desea realizar! ===\n");
	printf("----------------------------------------------------------------\n");
	printf("1. Agregar contacto (nombre + telefono + email)\n");
	printf("2. Mostrar todos (lista de todos los contactos)\n");
	printf("3. Buscar contactos (buscar por nombre)\n");
	printf("4. Eliminar contacto (por nombre)\n");
	printf("5. Salir\n");
	printf("Elija una opcion (1-5): ");
	scanf("%d", &opcion);
	
	while (opcion != 5) {
		switch (opcion) {
			case 1:
				printf("Nombre: ");
				scanf("%s", agenda[cantidad].nombre);
				printf("Telefono: ");
				scanf("%s", agenda[cantidad].telefono);
				printf("Email: ");
				scanf("%s", agenda[cantidad].email);
				cantidad++;
				printf("Contacto agregado!\n");
				break;
			case 2:
				if (cantidad == 0){
					printf("No hay contactos cargados.\n");
				}else {
					for (i = 0; i < cantidad; i++) {
						printf("Contacto %d: \n", i + 1);
						printf(" Nombre: %s\n", agenda[i].nombre);
						printf(" Telefono: %s\n", agenda[i].telefono);
						printf(" Email: %s\n", agenda[i].email);
						printf("-------------------\n");
					}
				}
				break;
			case 3:
				printf("Ingrese el nombre a buscar: ");
				scanf("%s", buscar);
				encontrado = 0;
				for (i = 0; i < cantidad; i++){
					if (strcmp(agenda[i].nombre, buscar) == 0){
						printf(" Nombre: %s\n",  agenda[i].nombre);
						printf(" Telefono: %s\n", agenda[i].telefono);
						printf(" Email: %s\n", agenda[i].email);
						encontrado = 1;
					}
				}			
				if (encontrado == 0) {
					printf("Contacto no econtrado.\n");
				}
				break;
			case 4:
				printf("Ingrese el nombre de contacto a eliminar: ");
				scanf("%s", buscar);
				encontrado = 0;
				for (i = 0; i < cantidad; i++){
					if (strcmp(agenda[i].nombre, buscar) == 0){
						agenda[i] = agenda[cantidad - 1];
						cantidad --;
						encontrado = 1;
						printf ("Contacto: %s eliminado\n", agenda[i].nombre);
					}
				}
				if (encontrado == 0){
					printf ("Contacto no encontrado.\n");
				}
				break;
			default:
				printf("Opcion invalida, elija 1, 2, 3, 4 o 5.\n");
				break;	
		}	
		printf("---------------------------------------------\n");
		printf("=== Elija otra opcion que desee realizar! ===\n");
		printf("---------------------------------------------\n");	
		printf("1. Agregar contacto (nombre + telefono + email)\n");
		printf("2. Mostrar todos (lista de todos los contactos)\n");
		printf("3. Buscar contacto(buscar por nombre)\n");
		printf("4. Eliminar contacto (por nombre)\n");
		printf("5. Salir\n");
		printf("Elija una opcion (1-5): ");
		scanf("%d", &opcion);
	}
	return 0;
} 
