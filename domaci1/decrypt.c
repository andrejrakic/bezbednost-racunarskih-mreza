#include <stdio.h>
#include "shared.h"

int i, j, determinanta = 0;
int kljuc[3][3], rec[3][1], adj[3][3], inverzna[3][3], dekodirana[3][1];

int ucitajKljuc() {
  printf("Unesite matricu 3x3 kao kljuc\n");

  for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			scanf("%d", &kljuc[i][j]);
		}
	}

  printf("Kljuc: \n");
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			printf("%d ", kljuc[i][j]);
		}
    printf("\n");
	}

  return 0;
}

int izracunajDeterminantu() {
  for(i = 0; i < 3; i++) {
		determinanta += (kljuc[0][i] * (kljuc[1][(i+1)%3] * kljuc[2][(i+2)%3] - kljuc[1][(i+2)%3] * kljuc[2][(i+1)%3]));
	}

  determinanta %= 30;

  return 0;
}

int nadjiInverznu() {
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      adj[i][j] = (kljuc[(j+1)%3][(i+1)%3] * kljuc[(j+2)%3][(i+2)%3]) - (kljuc[(j+1)%3][(i+2)%3] * kljuc[(j+2)%3][(i+1)%3]);
    }
  }

  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      adj[i][j] = moduo30(adj[i][j]); 
    }
  }

  determinanta = inverzniModuo(determinanta, 30);

  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      inverzna[i][j] = determinanta * adj[i][j]; 
    }
  }

  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      inverzna[i][j] = moduo30(inverzna[i][j]); 
    }
  }

  return 0;
}

int ucitajEnkriptovanuRec() {
  char ucitanaRec[3];

  printf("Unesite troslovnu enkodiranu rec\n");

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


int dekodiraj() {
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      dekodirana[i][0] += inverzna[i][j] * rec[j][0];
    }
  }

  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      dekodirana[i][0] = moduo30(dekodirana[i][0]);
    }
  }

  printf("Dekodirana rec: \n");
	for(i = 0; i < 3; i++) {
    printf("%c", Azbuka[dekodirana[i][0]]);
	}

  printf("\n");

  return 0;
}


int main() {

  ucitajKljuc();
  ucitajEnkriptovanuRec();
  izracunajDeterminantu();

  if(!uzajamnoProsti(determinanta, 30)) {
    printf("Nije moguce naci inverznu matricu");
    return 1;
  }

  nadjiInverznu();
  dekodiraj();

  return 0;
}

