#include <stdio.h>

int main()
{
    int h, m;
 
    scanf_s("%d %d", &h, &m);

    // Переводим часы в угол
    float hour_angle = (h % 12) * 30 + m / 2.0;
    // Переводим минуты в угол
    float minute_angle = m * 6;

    // Вычисляем разницу между углами
    float angle_diff = hour_angle - minute_angle;
    if (angle_diff < 0)
        angle_diff = -angle_diff;

    // Вычисляем наименьшее время в минутах
    int time_in_minutes = angle_diff / 5 * 60;
    printf("%d ", time_in_minutes);

    return 0;
}
