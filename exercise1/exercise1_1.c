// by Frederik Holfeld

#include <stdio.h>
#include <math.h>

int main() {
  float radius;

  printf("Bitte Radius angeben: ");
  scanf("%f", &radius);
  // pow(radius, 2) und pow(radius, 3) hat nicht geklappt, nimmt scheinbar keine floats ¯\_(ツ)_/¯
  printf("Fläche: %.2f\nVolumen: %.2f\n", M_PI * radius * radius, 4.0 / 3.0 * M_PI * radius * radius * radius);

  return 0;
}
