// by Frederik Holfeld

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int i;
  struct wagon * next;
  struct wagon * previous;
} wagon;

typedef struct {

} zug;

/*

*/

wagon* createW(int ladung) {
  wagon* wagonTemp = malloc(sizeof(wagon));
  wagonTemp->i = ladung;
  return wagonTemp;
}

void ausgabeW(wagon* wagon) {
  printf("%d\n", wagon->i);
}

//wagon* insert(wagon* wagon1, wagon* wagon2) {
  //wagon1-> next = &wagon2;
//}

int main() {
  wagon wagon1 = {
    .i = 5
  };
  wagon wagon2 = {
    .i = 33
  };
  printf("%d\n", wagon1.i);
  ausgabeW(&wagon1);
  ausgabeW(createW(42));
  ausgabeW(createW(1337));

  return 0;
}
