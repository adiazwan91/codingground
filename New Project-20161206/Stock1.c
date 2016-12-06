#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define s scanf
#define p printf

struct stock{
    int code;
    char name[45];
    int stockLevel, minStokLevel;
    double stockPrice, salePrice;
    
};

FILE *SK, *bStok;

int main()
{
struct stock oneStok, allStock[25];
int nodata, i;

SK = fopen("myStock", "r");
bStok = fopen("myBinStok", "wb");

fscanf(SK, "%i\n", &nodata);

for(i = 0; i<nodata; i++)
{
    fscanf(SK, "%i\n", &oneStok.code);
    fscanf(SK, "%i\n", &oneStok.name);
    fscanf(SK, "%i\n", &oneStok.stockLevel);
    fscanf(SK, "%i\n", &oneStok.minStokLevel);
    fscanf(SK, "%i\n", &oneStok.stockPrice);
    fscanf(SK, "%i\n", &oneStok.salePrice);
    
    fwrite(&oneStok, sizeof(struct stock),1, bStok);
}

fclose(SK);
fclose(bStok);

return 0;
}