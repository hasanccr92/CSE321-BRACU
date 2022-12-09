#include <stdio.h>
typedef struct Paratha {
    int qty;
    float uprice;
} Paratha;
typedef struct Vegetable {
    int qty;
    float uprice;
} Vegetable;
typedef struct Water {
    int qty;
    float uprice;
} Water;
int main() {
    Paratha p;
    Vegetable v;
    Water w;
    
    int persons;

    printf("Quantity of Paratha: ");
    scanf("%d", &p.qty);
    printf("Unit price: ");
    scanf("%f", &p.uprice);

    printf("Quantity of Vegetable: ");
    scanf("%d", &v.qty);
    printf("Unit price: ");
    scanf("%f", &v.uprice);

    printf("Quantity of Water: ");
    scanf("%d", &w.qty);
    printf("Unit price: ");
    scanf("%f", &w.uprice);

    printf("Number of people: ");
    scanf("%d", &persons);

    float cost = 0;
    cost += p.qty * p.uprice;
    cost += v.qty * v.uprice;
    cost += w.qty * w.uprice;

    printf("Individual people will pay: %.2f tk\n", cost / persons);
    return 0;
}

