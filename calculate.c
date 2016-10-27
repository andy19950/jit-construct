#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    FILE *ori = fopen("orig.txt", "r");
    FILE *opt = fopen("opt.txt", "r");
    FILE *out = fopen("output.txt", "w");
    char func[50];
    double _ori[3], _opt[3], temp;
    char table[3][20] = {"awib", "hanoi", "mandelbrot"};
    for (int i=0; i<300; i++) {
        fscanf(ori, "%s %lf", func, &temp);
        for(int j=0; j<3; j++)  if(!strcmp(func, table[j])) _ori[j] += temp;
    }
    for (int i=0; i<300; i++) {
        fscanf(opt, "%s %lf", func, &temp);
        for(int j=0; j<3; j++)  if(!strcmp(func, table[j])) _opt[j] += temp;
    }
    for(int i=0; i<3; i++) {
        _ori[i] /= 100;
        _opt[i] /= 100;
        fprintf(out, "%s %lf %lf\n", table[i], _ori[i], _opt[i]);
    }
    return 0;
}
