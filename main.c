#include <stdio.h>
#include <stdlib.h>

void sth(int* arr, int size) {
    int* read = arr;
    int* write = arr;
    int* search = arr;
    int* end = read + size;
    while (read<end){
        char is=0;
        for (search = arr; search<write;  search++){
                if(*search==*read){
                    is=1;
                    break;
                }
        }
        if (is==0){
            *write=*read;
            write++;
        }
        read++;
    }
    while (write<end){
        *(write++)=0;
    }
}



int three()
{
    int *pa, i, n;
    printf("Введите количество элементов массива\n");
    scanf("%d", &n);
    pa = (int*) calloc(n, sizeof(int));
    printf("Введите элементы массива\n");
    for(i=0; i<n; i++){
        scanf("%d", &pa[i]);}
    sth(pa, n);
    printf("Полученный массив\n");
    for(i=0; i<n; i++){
        printf("%d ", pa[i]);}
    printf("\n");
    return 0;
}



int search(int value, int *list, int n)
{
  if (n <= 0)
    return -1;
  int mid = (n-1)/2;
  if (value > list[mid]){
        int t=search(value, list + mid + 1, n - mid - 1);
        if (t>-1) return mid+1+t ;
        else return -1;
  }
  else if (value < list[mid])
    return search(value, list, mid );
  return mid;
  }


int five()
{
    int *pa, i, n, what;

    printf("Введите количество элементов массива\n");
    scanf("%d", &n);

    pa = (int*) calloc(n, sizeof(int));
    printf("Введите элементы массива в порядке неубывания\n");
    for(i=0; i<n; i++){
        scanf("%d", &pa[i]);
    }
    printf("Что нужно найти?\n");
    scanf("%d",&what);
    printf("Индекс искомого элемента:  %d", search(what, pa, n));
    printf("\n");
    return 0;
}
void merge(int *pm, int m, int *pn, int n, int *pu ){
    int i=0, j=0,k=0;
    while (i<m && j<n){
        if (pm[i]<pn[j])
            pu[k++]=pm[i++];
        else
            pu[k++]=pn[j++];}
    while(i<m){
        pu[k++]=pm[i++];}
    while (j<n){
        pu[k++]=pn[j++];}
}

int six()
{
    int *pn,*pm,*pu, m, n, i;
    printf("Введите количество элементов первого массива в порядке неубывания\n");
    scanf("%d", &m);
    pm = (int*) calloc(m, sizeof(int));
    printf("Введите элементы первого массива\n");
    for(i=0; i<m; i++){
        scanf("%d", &pm[i]);
    }
    printf("Введите количество элементов второго массива\n");
    scanf("%d", &n);
    pn = (int*) calloc(n, sizeof(int));
    printf("Введите элементы второго массива в порядке неубывания\n");
    for(i=0; i<n; i++){
        scanf("%d", &pn[i]);
    }
    pu = (int*) calloc(m+n, sizeof(int));
    merge(pm,m,pn,n,pu);
    printf("Полученный массив\n");
    for(i=0; i<m+n; i++){
        printf("%d ", pu[i]);
    }
    printf("\n");
    return 0;
}
int main(){
    int n;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    while(1){
        printf("3 - задача 7.3\n5 - задача 7.5\n6 - задача 7.6\n0 - выйти из программы\n");
        scanf("%d", &n);
        switch(n){
        case 3: three(); break;
        case 5: five(); break;
        case 6: six(); break;
        case 0: return 0;
    }

    }

}
