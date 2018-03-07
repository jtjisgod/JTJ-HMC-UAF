// gcc ./example_01.c -o example_01 -no-pie

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// C++의 Class 모방
struct Animal {
    char name[100]; // 이름
    char type;      // Type (0=Dog, 1=Cat)
    void (*bark)(); // Function
};

void setAnimal();   // Animal 생성자
void animalInfo();  // Animal 정보
void dog();         // 멍멍이 소리
void cat();         // 고양이 소리

int main() {
    struct Animal pet1;
    struct Animal pet2;

    setAnimal(&pet1, "Tae-Ji", 0);
    setAnimal(&pet2, "Shee", 1);

    animalInfo(&pet1);
    animalInfo(&pet2);

    return 0;
}

void setAnimal(struct Animal* animal, char *name, int type) {
    strcpy(animal -> name, name);
    animal -> type = type;
    if(type == 0) {
        animal -> bark = dog;
    } else {
        animal -> bark = cat;
    }
}

void animalInfo(struct Animal* animal) {
    printf("------------------------\n");
    printf("Address : %p\n", &animal);
    printf("PetName : %s\n", animal -> name);
    printf("Type : %d\n", animal -> type);
    printf("She/He Bark : ");
    animal -> bark();
    printf("------------------------\n");    
}

void dog() {
    puts("Bark! Bark!");
}

void cat() {
    puts("Mew~ Mew~");
}