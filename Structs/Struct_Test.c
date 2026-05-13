#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[50];
    char id[10];
    int age;
    double grades[5];
} Student;

typedef struct{
    int x;
    int y;
} Point;

typedef struct{
	int *array;
} Data;

void print_student(Student student);

void print_points(Point points[]);

int main(void){
    Student johnny;
    
    johnny.age = 17;
    
    strcpy(johnny.name, "Johnny");
    strcpy(johnny.id, "0001479081");
    johnny.grades[0] = 7.6;
    johnny.grades[1] = 2.8;
    johnny.grades[2] = 7.4;
    johnny.grades[3] = 8.9;
    johnny.grades[4] = 10;
    
    print_student(johnny);
    
    Point p1 = {5, 10};
	Point p2 = { .x = 7, .y = 8};
    
    printf("\np1.x: %d\n", p1.x);
    printf("\np1.y: %d\n", p1.y);
	
    printf("\np2.x: %d\n", p2.x);
    printf("\np2.y: %d\n", p2.y);
	
	p1 = p2;
	
	printf("\np1.x: %d\n", p1.x);
    printf("\np1.y: %d\n", p1.y);
	
	Point points[10];
	
	for (int i = 0; i < 10; i++){
		points[i].x = i;
		points[i].y = 10 - i;
	}
    
	print_points(points);
	
	Data x;
	Data y;
	
	x.array = malloc(sizeof(int) * 5);
	y.array = malloc(sizeof(int) * 5);
	
	x.array[0] = 1;
	x.array[1] = 2;
	x.array[2] = 3;
	x.array[3] = 4;
	x.array[4] = 5;
	
	y.array[0] = 9;
	y.array[1] = 9;
	y.array[2] = 9;
	y.array[3] = 9;
	y.array[4] = 9;
	
	x = y;
	
	for(int i = 0; i < 5; i++)
		printf("x.array[%d] = %d\n", i,x.array[i]);
	
	x.array[0] = 10;
	
	for(int i = 0; i < 5; i++){
		printf("y.array[%d] = %d\n", i,y.array[i]);
	}
	
    return 0;
}

void print_points(Point points[]){
	for (int i = 0; i < 10; i++)
		printf("p%d = (%d,%d)\n", i, points[i].x, points[i].y);
	
}

void print_student(Student student){
    printf("Name: %s\n", student.name);      
    printf("ID: %s\n", student.id);          
    printf("Grades:");
    for (int i = 0; i < 5; i++){
        printf(" %.2f", student.grades[i]);  
    }
    printf("\nAge: %d\n", student.age);     
}