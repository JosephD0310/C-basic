#include <stdio.h>
#include <stdlib.h>

//cau a
typedef struct Goat{
    int ID,fID,mID;
    double w,h,L;
    struct Goat* leftmostchid;
    struct Goat* rightsibling;
}Goat;

//cau b
Goat* makeGoat(int ID,int fID, int mID, double w, double h,double L){
    Goat* p=(Goat*)malloc(sizeof(Goat));
    p -> ID=ID;
    p -> w=w;
    p ->h=h;
    p -> L=L;
    p ->fID=fID;
    p ->mID=mID;
    p -> leftmostchid=NULL;
    p -> rightsibling=NULL;
    return p;
}
//cau d
Goat *find(Goat *r,int ID){
    if (r==NULL) return NULL;
    if (r->ID==ID) return r;
    Goat *p=r->leftmostchid;
    while(p!=NULL){
        Goat* q=find(p,ID);
        if(q!=NULL)return q;
        p=p->rightsibling;
        
    }
}
int main(){  
//cau c
    Goat** root;
    int i;
    int N,ID,fID,mID;
    double w,h,L;
    printf("Nhap vao so luong con de ");
    scanf("%d",&N);
    root = (Goat**)malloc(sizeof(Goat*)*N);
    for(i= 1 ; i <= N ;i++){
        printf("Nhap vao id con de thu %d: ", i);
        scanf("%d",&ID);
        printf("Nhap vao khoi luong con de thu %d: ", i);
        scanf("%f",&w);
        printf("Nhap vao Chieu cao con de thu %d: ", i);
        scanf("%f",&h);
        printf("Nhap vao chieu dai con de thu %d: ", i);
        scanf("%f",&L);
        printf("Nhap vao fID con de thu %d: ", i);
        scanf("%f",&fID);
        printf("Nhap vao mID con de thu %d: ", i);
        scanf("%f",&mID);
        root[i] = makeGoat(ID,fID,mID,w,h,L);

}
    return 0;
}
