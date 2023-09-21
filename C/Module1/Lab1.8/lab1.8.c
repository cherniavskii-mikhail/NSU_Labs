#include <stdio.h>
#include <math.h>

int main() {
    int floors, flats, num_of_flat;
    float ent, floor, flats_in_ent;

    scanf_s("%d %d %d", &floors, &flats, &num_of_flat);

    flats_in_ent = floors * flats;

    ent = ceil(num_of_flat / flats_in_ent);

    floor = ceil((num_of_flat - ((ent - 1) * flats_in_ent)) / flats);

    printf("%d %d", (int)ent, (int)floor);

    return 0;
}

Известно, сколько в доме этажей и сколько квартир на каждой площадке в подъезде (значения вводятся с клавиатуры). 
По заданному номеру квартиры, определить в каком подъезде и на каком этаже находится квартира.
