#include "solutions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*=====================================FUNCTION 1=====================================
*Function running total
*-----------------------
*Keeps track of the sum of the arguments it has been called with over time
* a : number of calls
* returns : the sum
*/
int running_total (int a){
  static int sum=0; //used static to keep the value in the memory for the entire run
  sum = sum + a; //adds the calls to sum
  return sum;
}

/*=====================================FUNCTION 2=====================================
*Function reverse
*-----------------------
*Takes an array and provides a new reversed array
* x : input array
* n : size of the array
* returns : a new array p which is reverse of input array
*/
int * reverse (const int * x, const int n){
  int * p;
  int i;

  p = (int * )calloc(n, sizeof(int)); //memory allocation using calloc for new array

  //Check if new array and the memory is allocated
  if (p == NULL) {
    printf("Memory not allocated! \n");
    exit(0);
  }
  else{
    printf("Memory successfully allocated! \n");
    for(i = 0; i < n; i++){
    *(p+i) = *(x+n-i-1); //Assigning last of input array to first of new array
    }
  }
  return p;
} 

/*=====================================FUNCTION 3=====================================
*Function reverse_in_place
*-----------------------
*Takes an array and reverse in its place
* x : input array
* n : size of the array
*/
void reverse_in_place (int x[], int n) {
  int temp;
  int start=-1;
  while (start < n)
  {
    //Array values assignments
    temp = x[start];  
    x[start] = x[n];
    x[n] = temp;
    start++;
    n--;
  }  
  return;
}    

/*=====================================FUNCTION 4=====================================
*Function num_occurences
*-----------------------
*Takes an array and provides the occurences of a number in that array
* a : input array
* len : size of the array
* value : the value whose occurences are required
* returns : the count of the occurences
*/
int num_occurences (int a[], int len, int value) {
  int count = 0;
  int i;
  for (i=0; i<len; i++){
    if (a[i]==value){
      count++;
    }
  }
  return count;
}