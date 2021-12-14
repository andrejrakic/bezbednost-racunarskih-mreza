#include <stdio.h>
#include "shared.h"

int i, j, determinanta = 0;
int kljuc[3][3], rec[3][1], enkodirana[3][1];
 

int ucitajKljuc() {
  printf("Unesite matricu 3x3 kao kljuc\n");

  for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			scanf("%d", &kljuc[i][j]);
		}
	}

  for(i = 0; i < 3; i++) {
		determinanta += (kljuc[0][i] * (kljuc[1][(i+1)%3] * kljuc[2][(i+2)%3] - kljuc[1][(i+2)%3] * kljuc[2][(i+1)%3]));
	}

  determinanta %= 30;

  printf("Kljuc: \n");
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			printf("%d ", kljuc[i][j]);
		}
    printf("\n");
	}

  return 0;
}

int ucitajRec() {
  char ucitanaRec[3];

  printf("Unesite troslovnu rec\n");

  scanf("%s", &ucitanaRec);

  for(i = 0; i < 3; i++) {
    for(j = 0; j < 30; j++) {
      if(ucitanaRec[i] == Azbuka[j]) {
         rec[i][0] = j;
      }
    }
  }

  return 0;
}

int enkodiraj() {
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      enkodirana[i][0] += kljuc[i][j] * rec[j][0];
    }
  }

  for(i = 0; i < 3; i++) {
		enkodirana[i][0] %= 30;
	}

  printf("Enkodirana rec: \n");
	for(i = 0; i < 3; i++) {
    printf("%c", Azbuka[enkodirana[i][0]]);
	}

  printf("\n");

  return 0;
}

int main() {
    ucitajKljuc();
    if(!uzajamnoProsti(determinanta, 30)) {
      printf("Nije moguce naci inverznu matricu za dati kljuc\n");
      return 1;
    }
    ucitajRec();
    enkodiraj();

  return 0;
}