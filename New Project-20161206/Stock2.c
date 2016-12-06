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

FILE *bStok;


int main()
{
    struct stock oneStok, allStok[25];
    int nodata, i;
    
    bStok = fopen("myBinStok", "rb");
    
    fseek(bStok, 0, SEEK_END);
    nodata = ftell(bStok)/sizeof(struct stock);
    p("Number of records in file: %i \n", nodata);
    rewind(bStok);
    
    p("Code  Name           Stoklevel Price\n");
    p("====================================\n");
    
    for(i = 0; i<nodata; i++)
    {
        fread(&oneStok, sizeof(struct stock), 1, bStok);
        
        p("%i", &oneStok.code);
        p("%-25s", &oneStok.name);
        p("%i", &oneStok.stockLevel);
        p("%lf\n", &oneStok.salePrice);
    }
    
    fclose(bStok);
    return 0;
}