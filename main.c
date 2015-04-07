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
int main(int argc,char **argv)
{
    node *root=NULL;
    int n;
    nodo* i1;
    
     QueryPerformanceCounter(&tIn_ini);
    //*conteo lineas
    FILE *pToFile = fopen("C:\\Users\\Erick\\Desktop\\Datos.txt","r");
	int line = 0;
	char input[512];
	while( fgets( input, 512, pToFile )) {
		line++;
	}
	fclose(pToFile);
	n = line;
        int datos[n];
        int BubbleData[n];
        int QuickData[n];
        
    //*registro datos
        FILE *pToFile1 = fopen("C:\\Users\\Erick\\Desktop\\Datos.txt","r");
	char input1[512];
        int cont = 0;
	while( fgets( input1, 512, pToFile1 )) {
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
      
     //preorder   
        QueryPerformanceCounter(&tRP_ini);
        preorder(root);
        QueryPerformanceCounter(&tRP_fin);
        secsRP = performancecounter_diff(&tRP_fin, &tRP_ini);
       //inorder 
        QueryPerformanceCounter(&tRI_ini);
        inorder(root);
        QueryPerformanceCounter(&tRI_fin);
        secsRP = performancecounter_diff(&tRI_fin, &tRI_ini);
    
  //buuble sort  
         QueryPerformanceCounter(&tB_ini);
        int i;
        int j;
        int temp;
        for (i = 1; i < n; i++) {
            for (j = 0; j < n-1; j++) {
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
    
       
        printf("\n Tiempo Ingreso Datos: %.10lf milisegundos\n", secsIn*1000);
        printf("\n Tiempo Recorrido Preorder: %.10lf milisegundos\n", secsRP*1000);
        printf("\n Tiempo Bubble Sort: %.10lf milisegundos\n", secsB*1000);
        printf("\n Tiempo Quick Sort: %.10lf milisegundos\n", secsQ*1000);
       
   /* do
        {
            printf("\n1)Create : ");
            printf("\n2)Insert : ");
            printf("\n3)Delete : ");
            printf("\n4)Print  : ");
            printf("\n5)Quit   : ");
            printf("\nEnter Your Choice : ");
            scanf("%d",&op);
            switch(op)
                {
                case 1:printf("\nEnter no.of elements :");
                       scanf("%d",&n);
                       printf("\n Enter tree data :");
                       root=NULL;
                        QueryPerformanceCounter(&t_ini);
                       for(i=0;i<n;i++)
                       {
                        scanf("%d",&x);
                        root=insert(root,x);
                       }  
                         QueryPerformanceCounter(&t_fin);
                         secs = performancecounter_diff(&t_fin, &t_ini);
                         printf("\n %.16g segundos\n", secs);
                       break;
                case 2:printf("\nEnter a data : ");
                       scanf("%d",&x);
                       root=insert(root,x);
                       break;
                case 3:printf("\nEnter a data : ");
                       scanf("%d",&x);
                       root=Delete(root,x);
                       break;
                case 4:    printf("\nPreorder sequence :\n");
                    preorder(root);
                    printf("\nInorder sequence :\n");
                    inorder(root);
                    break;
                 }

    }while(op!=5);*/
        return 0;

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
        //printf(" %d(Bf=%d)",T->data,BF(T));
        preorder(T->left);
        preorder(T->right);
    }
}
void inorder(node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        //printf(" %d(Bf=%d)",T->data,BF(T));
        inorder(T->right);
    }
}

