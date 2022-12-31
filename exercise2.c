// by Frederik Holfeld

#include <stdio.h>
#include <math.h>

const int monSize = 25;
int mid = monSize / 2;
const int rad = 10;
// Beim Testen wurde der Kreis am besten, wenn der Threshold und der Radius identisch sind.
int thresh = rad;

int i, j;


// Für die 2. Aufgabe habe ich Hilfe von Kommilitonen Veit Pitrasch bekommen, mir erschließt sich jedoch nach wie vor nicht die Sinnhaftigkeit der Aufgabe. ¯\_(ツ)_/¯
typedef struct {
  char circle[25][25];
} Display;

#define CIRCLE (i - mid) * (i - mid) + (j - mid) * (j - mid) - rad * rad > -thresh && (i - mid) * (i - mid) + (j - mid) * (j - mid) - rad * rad < thresh


void printCircle(char circle[][monSize]) {
  for (i = 0; i < monSize; i++) {
    for (j = 0; j < monSize; j++) {
      printf("%c", circle[i][j]);
    }
    printf("\n");
  }
}

// Die Ausgabe-Prozedur kann nicht wiederverwendet werden, da der Parameter ein Display-Objekt anstelle eines char[][] ist. (Aufgabenstellung?!)
void printCircleDisplay(Display dis) {
  for (i = 0; i < monSize; i++) {
    for (j = 0; j < monSize; j++) {
      printf("%c", dis.circle[i][j]);
    }
    printf("\n");
  }
}

int main() {
  char input;

  printf("Bitte die Eingabe für Aufgabe 1 mit 'a' beginnen, ansonsten wird Aufgabe 2 ausgegeben: ");
  scanf("%c", &input);
  if (input == 'a') {
    char circle[monSize][monSize];
    for (i = 0; i < monSize; i++) {
      for (j = 0; j < monSize; j++) {
        if ((i - mid) * (i - mid) + (j - mid) * (j - mid) - rad * rad > -thresh && (i - mid) * (i - mid) + (j - mid) * (j - mid) - rad * rad < thresh) {
          circle[i][j] = '#';
        } else {
          circle[i][j] = '-';
        }
      }
    }
    printCircle(circle);
    printf("Circle von Aufgabe 1.\n");
  } else {
    Display dis;
    for (i = 0; i < monSize; i++) {
      for (j = 0; j < monSize; j++) {
        if (CIRCLE) {
          dis.circle[i][j] = '#';
        } else {
          dis.circle[i][j] = '-';
        }
      }
    }
    printCircleDisplay(dis);
    printf("Circle von Aufgabe 2.\n");
  }
  return 0;
}
