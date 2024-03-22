// C Program for B trees 
#include <stdio.h>
#include <stdlib.h>
struct BTree {
    //node declaration
   int *d;
   struct BTree **child_ptr;
   int l;
   int n;
};
struct BTree *r = NULL;
struct BTree *np = NULL;
struct BTree *x = NULL;
// creation of node
struct BTree* init() {
   int i;
   np = (struct BTree*)malloc(sizeof(struct BTree));
   //order 6
   np->d = (int*)malloc(6 * sizeof(int));
   np->child_ptr = (struct BTree**)malloc(7 * sizeof(struct BTree*));
   np->l = 1;
   np->n = 0;
   for (i = 0; i < 7; i++) {
      np->child_ptr[i] = NULL;
   }
   return np;
}
//traverse the tree
void traverse(struct BTree *p) {
   printf("\n");
   int i;
   for (i = 0; i < p->n; i++) {
      if (p->l == 0) {
         traverse(p->child_ptr[i]);
      }
      printf(" %d", p->d[i]);
   }
   if (p->l == 0) {
      traverse(p->child_ptr[i]);
   }
   printf("\n");
}
//sort the tree
void sort(int *p, int n) {
   int i, j, t;
   for (i = 0; i < n; i++) {
      for (j = i; j <= n; j++) {
         if (p[i] > p[j]) {
            t = p[i];
            p[i] = p[j];
            p[j] = t;
         }
      }
   }
}
int split_child(struct BTree *x, int i) {
   int j, mid;
   struct BTree *np1, *np3, *y;
   np3 = init();
   //create new node
   np3->l = 1;
   if (i == -1) {
      mid = x->d[2];
      //find mid
      x->d[2] = 0;
      x->n--;
      np1 = init();
      np1->l = 0;
      x->l = 1;
      for (j = 3; j < 6; j++) {
         np3->d[j - 3] = x->d[j];
         np3->child_ptr[j - 3] = x->child_ptr[j];
         np3->n++;
         x->d[j] = 0;
         x->n--;
      }
      for (j = 0; j < 6; j++) {
         x->child_ptr[j] = NULL;
      }
      np1->d[0] = mid;
      np1->child_ptr[np1->n] = x;
      np1->child_ptr[np1->n + 1] = np3;
      np1->n++;
      r = np1;
   } else {
      y = x->child_ptr[i];
      mid = y->d[2];
      y->d[2] = 0;
      y->n--;
      for (j = 3; j < 6; j++) {
         np3->d[j - 3] = y->d[j];
         np3->n++;
         y->d[j] = 0;
         y->n--;
      }
      x->child_ptr[i + 1] = y;
      x->child_ptr[i + 1] = np3;
   }
   return mid;
}
void insert(int a) {
   int i, t;
   x = r;
   if (x == NULL) {
      r = init();
      x = r;
   } else {
      if (x->l == 1 && x->n == 6) {
         t = split_child(x, -1);
         x = r;
         for (i = 0; i < x->n; i++) {
            if (a > x->d[i] && a < x->d[i + 1]) {
               i++;
               break;
            } else if (a < x->d[0]) {
               break;
            } else {
               continue;
            }
         }
         x = x->child_ptr[i];
      } else {
         while (x->l == 0) {
            for (i = 0; i < x->n; i++) {
               if (a > x->d[i] && a < x->d[i + 1]) {
                  i++;
                  break;
               } else if (a < x->d[0]) {
                  break;
               } else {
                  continue;
               }
            }
            if (x->child_ptr[i]->n == 6) {
               t = split_child(x, i);
               x->d[x->n] = t;
               x->n++;
               continue;
            } else {
               x = x->child_ptr[i];
            }
         }
      }
   }
   x->d[x->n] = a;
   sort(x->d, x->n);
   x->n++;
}

int main() {
   int i, n, t;
   insert(10);
   insert(20);
   insert(30);
   insert(40);
   insert(50);
   printf("Insertion Done");
   printf("\nB tree:");
   traverse(r);
   return 0;
}
