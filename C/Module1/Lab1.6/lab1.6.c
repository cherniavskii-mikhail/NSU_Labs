#include <stdio.h>

int main()
{
    int h, m;
 
    scanf_s("%d %d", &h, &m);

    // Переводим часы в угол
    float hourAngle = (h % 12) * 30 + m / 2.0;
    // Переводим минуты в угол
    float minuteAngle = m * 6;

    // Вычисляем разницу между углами
    float angleDiff = hourAngle - minuteAngle;
    
    if (angleDiff < 0)
    {
        angleDiff = -angleDiff;
    }

    // Вычисляем наименьшее время в минутах
    int timeInMinutes = angleDiff / 5 * 60;
    printf("%d ", timeInMinutes);

    return 0;
}

Даны целые числа h, m (0 < h ≤ 12, 0 ≤ m ≤ 59), указывающие момент времени: "h часов, m минут". 
Определить наименьшее время (число полных минут), которое должно пройти до того момента, когда часовая и минутная стрелки на циферблате расположатся перпендикулярно друг другу.
