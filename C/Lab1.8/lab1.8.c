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
