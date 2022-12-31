// by Frederik Holfeld

#include <stdio.h>
#include <math.h>

float area(float radius) {
  return M_PI * radius * radius;
}

float volume(float radius) {
  return 4.0 / 3.0 * M_PI * radius * radius * radius;
}

int main() {
  float radius;

  printf("Bitte Radius angeben: ");
  scanf("%f", &radius);
  printf("Fläche: %.2f\nVolumen: %.2f\n", area(radius), volume(radius));
  return 0;
}
