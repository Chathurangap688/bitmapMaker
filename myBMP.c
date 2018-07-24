#include <stdio.h>
void BPMwrirer(int size, unsigned char bitmap[]){
    FILE *file;
    int i = 0;
    char name[20];
    printf("\nname\n"); 
    scanf("%s",&*name);
    file = fopen(name, "wb+");
    for( i = 0; i < size; i++){
        fputc(bitmap[i], file);
    }
    fclose(file);
}
void makeBMP(int width,int heiht){
    int size = 40+14+width*heiht*4;
    int i = 0;
    unsigned char bitmap[size];
    //tag BM
    bitmap[0] = 'B';
    bitmap[1] = 'M';
    //file size 54+width*heiht
    bitmap[2] = size%100;
    bitmap[3] = size/100;
    bitmap[4] = 0;
    bitmap[5] = 0;
    //unused 4byte
    for( i = 6; i < 10; i++) bitmap[i] = 0;

    //file offset
    bitmap[10] = 54;
    for( i = 11; i < 14; i++) bitmap[i] = 0;

    //heder size = 40
    bitmap[14] = 40;
    for( i = 15; i < 18; i++) bitmap[i] = 0;

    //width 
    bitmap[18] = width;
    for( i = 19; i < 22; i++) bitmap[i] = 0;

    //heiht
    bitmap[22] = heiht;
    for( i = 23; i < 26; i++) bitmap[i] = 0;

    // nomber of PLANCE
    bitmap[26] = 1;
    bitmap[27] = 0;

    //no of colour
    bitmap[28] = 24;
    bitmap[29] = 0;

    //compression type = no compression
    for( i = 30; i < 34; i++) bitmap[i] = 0;

    //compressed size
    bitmap[34] = width*heiht*4;
    for( i = 35; i < 38; i++) bitmap[i] = 0;

    //horizontal resulution
    for( i = 38; i < 42; i++) bitmap[i] = 0;

    //vertical resulution = 0
    for( i = 42; i < 46; i++) bitmap[i] = 0;

    //number of used colour 
    bitmap[46]=0;
    bitmap[47]=0;
    for( i = 48; i < 50; i++) bitmap[i] = 0;

    // number of importan colour 
    for( i = 50; i < 54; i++) bitmap[i] = 0;


    // pixel deta

    for( i = 54; i < size; i+=4){
        bitmap[i] = 0xff;
        bitmap[i+1] = 0xff;
        bitmap[i+2] = 0xff;
        bitmap[i+3] = 0x00;
    }
   



    BPMwrirer(size, bitmap);

}

int main(int argc, char const *argv[])
{   int width = 0,heiht = 0,i= 0;
    printf("sise\n");
    scanf("%d",&width);
    scanf("%d",&heiht);
    printf("%dX%d",width,heiht);
    makeBMP(width , heiht);
    printf("\nend\n");
    return 0;
}