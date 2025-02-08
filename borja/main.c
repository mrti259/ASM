#include "lib.h"

int main() {
    FILE *ej2_f = NULL;
    printf("Ej1: %i\n", ej1()); // 136

    printf("Ej2a: %u\n", strLen("BORJA")); // 5
    
    printf("Ej2b: %i, %i, %i\n", strCmp("BORJA", "BORJA"), strCmp("AJROB", "BORJA"), strCmp("BORJA", "AJROB")); // 0, 1, -1
    printf("Ej2b: %i, %i, %i\n", strCmp(NULL, NULL), strCmp(NULL, "AJROB"), strCmp("AJROB", NULL)); // 0, 1, -1
    
    ej2_f = fopen("ej2_null.txt", "w");
    strPrint(NULL, ej2_f);
    fclose(ej2_f);
    
    ej2_f = fopen("ej2_borja.txt", "w");
    strPrint("BORJA", ej2_f);
    fclose(ej2_f);
    
    printf("Ej3: %i\n", countChars("CARAMELO", 'E')); // 1
    printf("Ej3: %i\n", countChars("CARAMELO", 'A')); // 2

    char ej4_s[] = "BORJA";
    printf("Ej4: %s\n", ej4_s); // "BORJA"
    intercambiar(ej4_s);
    printf("Ej4: %s\n", ej4_s); // "AJROB"

    short ej5_n = 3;
    short ej5_m[9] = {
        0, 1, 2,
        3, 4, 5,
        6, 7, 8,
    };
    short ej5_v[3] = {0};
    diagonal(ej5_m, ej5_n, ej5_v);
    printf("Ej5: ");
    for (short i = 0; i < ej5_n; i++) {
        if (i != 0) printf(", ");
        printf("%i", ej5_v[i]); // 0, 4, 8
    }
    printf("\n");

    short ej6_n = 3;
    pixel ej6_m[] = {
        {.r=0x0, .g=0xA, .b=0xF, },
        {.r=0xA, .g=0xF, .b=0x0, },
        {.r=0xF, .g=0x0, .b=0xA, },
    };
    uint8_t ej6_v[] = {0};
    gris(ej6_m, ej6_n, ej6_v);
    printf("Ej6: ");
    for (short i = 0; i < ej6_n; i++) {
        if (i != 0) printf(", ");
        printf("%X", ej6_v[i]); // 8, A, 6
    }
    printf("\n");

    int ej7_m[SIZE_C][SIZE_C] = {
        {0,1,2,3,4,5,6,7,8,9},
        {0,1,2,3,4,5,6,7,8,9},
        {0,1,2,3,4,5,6,7,8,9},
        {0,1,2,3,4,5,6,7,8,9},
        {0,1,2,3,4,5,10,7,8,9}, // 4,6
        {0,1,2,3,4,5,6,7,8,9},
        {0,1,2,3,4,5,6,7,8,9},
        {0,1,2,3,4,5,6,7,8,9},
        {0,1,2,3,4,5,6,7,8,9},
        {0,1,2,3,4,5,6,7,8,9},
    };
    int ej7_f = 0, ej7_c = 0;
    int *ej7_p = primerMaximo(ej7_m, &ej7_f, &ej7_c);
    printf("Ej7: f: %i, c: %i, p: %i\n", ej7_f, ej7_c, *ej7_p); // 4 6 10

    return 0;
}

// int32_t ej1() {
//     int32_t v[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
//     int32_t sum = 0;
//     for(unsigned i = 0; i < 16; i++) sum += v[i];
//     return sum;
// }

// uint32_t strLen(char* a) {
//     uint32_t len = 0;
//     while(a && a[len]) len++;
//     return len;
// }

// int32_t strCmp(char* a, char* b) {
//     if (a==b) return 0;
//     if (!a) return 1;
//     if (!b) return -1;
//     unsigned i = 0;
//     while(1) {
//         if (a[i] < b[i]) return 1;
//         if (b[i] < a[i]) return -1;
//         if (!a[i] && !b[i]) return 0;
//         i++;
//     }
// }

// void strPrint(char* a, FILE* pFile) {
//     if (!a || !a[0]) a = "NULL";
//     fprintf(pFile, a);
// }

// int countChars(char* s, char c) {
//     int count = 0;
//     unsigned i = 0;
//     while(s && s[i]) {
//         if (s[i] == c) count++;
//         i++;
//     }
//     return count;
// }

// void intercambiar(char* s) {
//     uint32_t len = strLen(s);
//     uint32_t top = len >> 1;
//     uint32_t i = 0;
//     while(i < top) {
//         len--;
//         char tmp = s[len];
//         s[len] = s[i];
//         s[i] = tmp;
//         i++;
//     }
// }

// void diagonal(short* matriz, short n, short* vector) {
//     for(unsigned i = 0; i < n; i++) {
//         unsigned j = i * (n + 1);
//         vector[i] = matriz[j];
//     }
// }

// void gris(pixel* matriz, short n, uint8_t* resultado) {
//     unsigned j = n;
//     j *= j;
//     for(unsigned i = 0; i < j; i++) {
//         pixel p = matriz[i];
//         uint8_t r = p.g;
//         r = r << 1;
//         r += p.r;
//         r += p.b;
//         r = r >> 2;
//         resultado[i] = r;
//     }
// }

// int* primerMaximo(int (*matriz)[SIZE_C] , int* f, int* c) {
//     int *max = NULL;
//     for(unsigned i = 0; i < SIZE_C; i++) {
//         for(unsigned j = 0; j < SIZE_C; j++) {
//             if (!max || matriz[i][j] > *max) {
//                 max = &(matriz[i][j]);
//                 *f = i;
//                 *c = j;
//             }
//         }
//     }
//     return max;
// }