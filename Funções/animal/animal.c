#include <stdio.h>
#include <string.h>

void Animal(char *p1, char *p2, char *p3 ){
	    if (strcmp(p1, "vertebrado") == 0) {
        if (strcmp(p2, "ave") == 0) {
            if (strcmp(p3, "carnivoro") == 0) {
                printf("aguia\n");
            } else if (strcmp(p3, "onivoro") == 0) {
                printf("pomba\n");
            }
        } else if (strcmp(p2, "mamifero") == 0) {
            if (strcmp(p3, "onivoro") == 0) {
                printf("homem\n");
            } else if (strcmp(p3, "herbivoro") == 0) {
                printf("vaca\n");
            }
        }
    } 
    else if (strcmp(p1, "invertebrado") == 0) {
        if (strcmp(p2, "inseto") == 0) {
            if (strcmp(p3, "hematofago") == 0) {
                printf("pulga\n");
            } else if (strcmp(p3, "herbivoro") == 0) {
                printf("lagarta\n");
            }
        } else if (strcmp(p2, "anelideo") == 0) {
            if (strcmp(p3, "hematofago") == 0) {
                printf("sanguessuga\n");
            } else if (strcmp(p3, "onivoro") == 0) {
                printf("minhoca\n");
            }
        }
    }

}