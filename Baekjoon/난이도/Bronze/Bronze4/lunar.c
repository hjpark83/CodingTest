#include <stdio.h>

int main() {
    double weight;
    while (1) {
        scanf("%lf", &weight);
        if (weight < 0) {
            break;
        }
        double moonWeight = weight * 0.167;
        printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n", weight, moonWeight);
    }
    return 0;
}
