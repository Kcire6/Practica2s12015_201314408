/* 
 * File:   main.c
 * Author: Erick
 * PRACTICA 2 ESTUCTURAS DE DATOS 1S 2015
 * 201314408
 * Created on 27 de marzo de 2015, 2:40
 */


#include <stdlib.h>
#include<stdio.h>
#include <windows.h>

typedef struct{
    struct nodo* siguiente; 
    int* dato;
} nodo;

nodo* primer = NULL;
nodo* ultimo = NULL;

 void quicksort(int array[], int firstIndex, int lastIndex)
{
    //declaaring index variables
    int pivotIndex, temp, index1, index2;

    if(firstIndex < lastIndex)
    {
        //assigninh first element index as pivot element
        pivotIndex = firstIndex;
        index1 = firstIndex;
        index2 = lastIndex;

        //Sorting in Ascending order with quick sort
        while(index1 < index2)
        {
            while(array[index1] <= array[pivotIndex] && index1 < lastIndex)
            {
                index1++;
            }
            while(array[index2]>array[pivotIndex])
            {
                index2--;
            }

            if(index1<index2)
            {
                //Swapping opertation
                temp = array[index1];
                array[index1] = array[index2];
                array[index2] = temp;
            }
        }

        //At the end of first iteration, swap pivot element with index2 element
        temp = array[pivotIndex];
        array[pivotIndex] = array[index2];
        array[index2] = temp;

        //Recursive call for quick sort, with partiontioning
        quicksort(array, firstIndex, index2-1);
        quicksort(array, index2+1, lastIndex);
    }
}

void agregar(nodo* _nodo){
    _nodo -> siguiente = NULL;
    if(primer == NULL){
        primer = _nodo;
        ultimo = _nodo; 
    }else{
        ultimo -> siguiente = _nodo;
        ultimo = _nodo; 
    }
}

typedef struct node
{  int data;
   struct node *left,*right;
   int ht;
}node;


  node *insert(node *,int);
  node *Delete(node *,int);
  void  preorder(node *);
  void  inorder(node *);
  int   height( node *);
  node *rotateright(node *);
  node *rotateleft(node *);
  node *RR(node *);
  node *LL(node *);
  node *LR(node *);
  node *RL(node *);
  int BF(node *);
  
  LARGE_INTEGER tIn_ini, tIn_fin,tB_ini, tB_fin,tQ_ini, tQ_fin,tRI_ini, tRI_fin,tRP_ini, tRP_fin;
  double secsIn,secsB,secsQ,secsRI,secsRP;
  double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
void main(int argc,char **argv)
{
    node *root=NULL;
    int n;
    nodo* i1;
    char url[1500];
    char final[500];
    puts("Ingrese direccion del archivo: ");
	scanf("%s", &url);
    
     QueryPerformanceCounter(&tIn_ini);
    //*conteo lineas
    FILE *pToFile = fopen(url,"r");
	int line = 0;
	char input[5120];
	while( fgets( input, 5120, pToFile )) {
		line++;
	}
	fclose(pToFile);
	n = line;
        int datos[n];
        int BubbleData[n];
        int QuickData[n];
        int inO[n];
        int inP[n];
        
    //*registro datos
        FILE *pToFile1 = fopen(url,"r");
	char input1[5120];
        int cont = 0;
	while( fgets( input1, 5120, pToFile1 )) {
                 root=insert(root,atoi(input1));
                  nodo* auxNodo = malloc(sizeof(nodo));
                  auxNodo -> dato = atoi(input1);
                  agregar(auxNodo);
                  datos[cont] = atoi(input1);
                  BubbleData[cont] = atoi(input1);
                  QuickData[cont] = atoi(input1);
                  if(cont == 0){
                      i1 = auxNodo;
                  }
                  cont = cont +1;
	}
	fclose(pToFile);
    /* while(i1 != NULL){
        printf("%d\n", i1->dato);
        i1 = i1->siguiente;
    }*/
        QueryPerformanceCounter(&tIn_fin);
        secsIn = performancecounter_diff(&tIn_fin, &tIn_ini);
      
   
  //buuble sort  
         QueryPerformanceCounter(&tB_ini);
        int i;
        int j;
        int temp;
        for (i = 0; i < (n-1); i++) {
            for (j = 0; j < (n-i)-1; j++) {
                if (BubbleData[j] > BubbleData[j + 1]) {
                    temp = BubbleData[j];
                    BubbleData[j] = BubbleData[j + 1];
                    BubbleData[j + 1] = temp;
                  }
               }
           }
        QueryPerformanceCounter(&tB_fin);
        secsB = performancecounter_diff(&tB_fin, &tB_ini);
        
        //quicksort 
       QueryPerformanceCounter(&tQ_ini);
        quicksort(QuickData,0,n-1);
       QueryPerformanceCounter(&tQ_fin);
        secsQ = performancecounter_diff(&tQ_fin, &tQ_ini);
    
        
        printf("\n\nRecorrido AVL Pre-Order:\n");
    
          //preorder   
        QueryPerformanceCounter(&tRP_ini);
        preorder(root);
        QueryPerformanceCounter(&tRP_fin);
        secsRP = performancecounter_diff(&tRP_fin, &tRP_ini);
       //inorder 
       printf("\n\nRecorrido AVL In-Order:\n");
    
        QueryPerformanceCounter(&tRI_ini);
        inorder(root);
        QueryPerformanceCounter(&tRI_fin);
        secsRP = performancecounter_diff(&tRI_fin, &tRI_ini);
    
       
     printf("\n\nSalida Bubble Sort:\n");
     int ty;
     for(ty=0;ty<n;ty++){
         if(ty==0){
         printf("%d",BubbleData[ty]);    
         }else{
         printf(",%d",BubbleData[ty]);    
         }
     }
     printf("\n\nSalida Quick Sort:\n");
     int tx;
     for(tx=0;tx<n;tx++){
         if(tx==0){
             printf("%d",QuickData[tx]);
         }else{
             printf(",%d",QuickData[tx]);
         } 
     }
       
  FILE *archivo;/*El manejador de archivo*/
  archivo=fopen("C:\\Users\\Erick\\Desktop\\MisDatos201314408.txt", "w");
  if(archivo==NULL){
   return 1;/*Reornamos 1 por si no lo logramos abrir o crear el  fichero, y salimos*/
   }
 else{
      
      
      
      
 fprintf(archivo,"DATOS PRACTICA 2 EDD 201314408\n");
 //Escribimos en el archivo las coordenadas
 fprintf(archivo,"\n Tiempo Ingreso Datos: %.10lf milisegundos\n", secsIn*1000);
 fprintf(archivo,"\n Tiempo Recorrido Preorder: %.10lf milisegundos\n", secsRP*1000);
 fprintf(archivo,"\n Tiempo Bubble Sort: %.10lf milisegundos\n", secsB*1000);
 fprintf(archivo,"\n Tiempo Quick Sort: %.10lf milisegundos\n", secsQ*1000);
 
 
 
 }/*Fin del while*/
    fclose(archivo);/*Cerramos el archivo*/
    puts(" ");
    scanf("%s",&final);
        
        

}
node * insert(node *T,int x)
{
    if(T==NULL)
    {
        T=(node*)malloc(sizeof(node));
        T->data=x;
        T->left=NULL;
        T->right=NULL;
    }
    else
        if(x > T->data)                // insert in right subtree
        {
            T->right=insert(T->right,x);
            if(BF(T)==-2)
                if(x>T->right->data)
                    T=RR(T);
                else
                    T=RL(T);
        }
        else
            if(x<T->data)
            {
                T->left=insert(T->left,x);
                if(BF(T)==2)
                    if(x < T->left->data)
                        T=LL(T);
                    else
                        T=LR(T);
            }
            T->ht=height(T);
            return(T);
}

node * Delete(node *T,int x)
{       node *p;

    if(T==NULL)
    {
        return NULL;
    }
    else

        if(x > T->data)                // insert in right subtree
        {
            T->right=Delete(T->right,x);
            if(BF(T)==2)
                if(BF(T->left)>=0)
                    T=LL(T);
                else
                    T=LR(T);
        }
        else
            if(x<T->data)
                {
                    T->left=Delete(T->left,x);
                    if(BF(T)==-2)//Rebalance during windup
                        if(BF(T->right)<=0)
                            T=RR(T);
                        else
                            T=RL(T);
                }
            else
              {
                //data to be deleted is found
                  if(T->right !=NULL)
                  {  //delete its inorder succesor
                      p=T->right;
                      while(p->left != NULL)
                      p=p->left;

                      T->data=p->data;
                      T->right=Delete(T->right,p->data);
                      if(BF(T)==2)//Rebalance during windup
                        if(BF(T->left)>=0)
                            T=LL(T);
                        else
                            T=LR(T);
                   }
                  else
                   return(T->left);

              }
    T->ht=height(T);
    return(T);
}

int height(node *T)
{
    int lh,rh;
    if(T==NULL)
        return(0);
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;
    if(lh>rh)
        return(lh);
    return(rh);
}
node * rotateright(node *x)
{
    node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}
node * rotateleft(node *x)
{
    node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}
node * RR(node *T)
{
    T=rotateleft(T);
    return(T);
}
node * LL(node *T)
{
    T=rotateright(T);
    return(T);
}
node * LR(node *T)
{
    T->left=rotateleft(T->left);
    T=rotateright(T);
    return(T);
}
node * RL(node *T)
{
    T->right=rotateright(T->right);
    T=rotateleft(T);
    return(T);
}
int BF(node *T)
{
    int lh,rh;
    if(T==NULL)
    return(0);
    if(T->left==NULL)
        lh=0;
    else
        lh=1+T->left->ht;
    if(T->right==NULL)
        rh=0;
    else
        rh=1+T->right->ht;
    return(lh-rh);
}
void preorder(node *T)
{
    if(T!=NULL)
    {
     printf(",%d",T->data);
        preorder(T->left);
        preorder(T->right);
    }
}
void inorder(node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
      printf(",%d",T->data);
        inorder(T->right);
    }
}

