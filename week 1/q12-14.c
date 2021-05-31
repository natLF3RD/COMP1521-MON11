#include <stdio.h>
#include <string.h>

#define NAME_MAX_SIZE 1024
#define NAME_TYPE_SIZE 1024

typedef struct Pet {
    char name[NAME_MAX_SIZE];
    char type[NAME_TYPE_SIZE];
    int age;
    float weight;
} Pet;


int main() {
    char* c = "hello";

    Pet axolotl;
    Pet *axolotl2;

    strcpy(axolotl.name, "Fluffy");
    strcpy(axolotl.type, "Axolotl");
    axolotl.age = 7;
    axolotl.weight = 300;

    return 0;
}