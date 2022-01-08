#include <stdio.h>
#include <stdlib.h>

#define POLINOM 0b100011011 // x^8 + x^4 + x^3 + x + 1

typedef u_int8_t gf8; // GF(2^8)

void stampaj(gf8 a)
{
    int i = 8;
    while (i--) {
        printf("%d", (a >> i & 1));
    }
}

gf8 saberi(gf8 a, gf8 b)
{
    return a ^ b;
}

/**
 * Run the following loop eight times (once per bit)
 * 1. If the rightmost bit of b is set, exclusive OR the product p by the value of a. This is polynomial addition.
 * 2. Shift b one bit to the right, discarding the rightmost bit, and making the leftmost bit have a value of zero. This divides the polynomial by x, discarding the x0 term.
 * 3. Keep track of whether the leftmost bit of a is set to one and call this value carry.
 * 4. Shift a one bit to the left, discarding the leftmost bit, and making the new rightmost bit zero. This multiplies the polynomial by x, but we still need to take account of carry which represented the coefficient of x7.
 * 5. If carry had a value of one, exclusive or a with the hexadecimal number 0x1b (00011011 in binary). 0x1b corresponds to the irreducible polynomial with the high term eliminated. Conceptually, the high term of the irreducible polynomial and carry add modulo 2 to 0.
 * p now has the product
*/
gf8 pomnozi(gf8 a, gf8 b)
{
    int i;
    gf8 proizvod = 0;

    for (i = 0; i < 8; ++i) {
        if (b & 0b00000001) {
            proizvod ^= a;
        }

        b >>= 1;

        if (a & 0b10000000) {
            a = (a << 1) ^ POLINOM;
        } else {
            a <<= 1;
        }
    }

    return proizvod;
}

void podeli(gf8 a, gf8 b) {
    int i;

    gf8 deljenik = a;
    gf8 delilac = b;
    gf8 prviBitA;
    gf8 prviBitB;

    printf("A / B: ");
    for (i = 0; i < 8; i++) {
        prviBitA = deljenik & 0b10000000;
        prviBitB = delilac & 0b10000000;
        gf8 temp = prviBitA / prviBitB;
        printf("%d", temp & 0b10000000);

        gf8 tempProizvod = pomnozi(temp, b);
        deljenik = saberi(tempProizvod, deljenik);

        deljenik <<= 1;
        delilac <<= 1;
    }
    printf("\n");

    printf("A %% B: ");
    stampaj(deljenik);
    printf("\n");
}

int main(int argc, char* argv[]) {
    gf8 a = atoi(argv[1]);
    gf8 b = atoi(argv[2]);

    gf8 zbir = saberi(a, b);

    printf("A + B: ");
    stampaj(zbir);
    printf("\n");

    gf8 proizvod = pomnozi(a, b);

    printf("A * B: ");
    stampaj(proizvod);
    printf("\n");

    podeli(a, b);

    return 0;
}