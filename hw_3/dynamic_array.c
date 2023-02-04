#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* private functions *********************************************************/

/* Position in the buffer of the array element at position index */
static int index_to_offset ( const DynamicArray * da, int index ) {
    return index + da->origin;
}

/* Position of the element at buffer position 'offset' */
static int offset_to_index ( const DynamicArray * da, int offset ) {
    return offset - da->origin;
}

/* Non-zero if and only if offset lies ouside the buffer */
static int out_of_buffer ( DynamicArray * da, int offset ) {
    return offset < 0 || offset >= da->capacity;
}

/* Makes a new buffer that is twice the size of the old buffer,
   copies the old information into the new buffer, and deletes
   the old buffer */
static void extend_buffer ( DynamicArray * da ) {

    double * temp = (double *) calloc ( 2 * da->capacity, sizeof(double) );
    int new_origin = da->capacity - (da->end - da->origin)/2,
           new_end = new_origin + (da->end - da->origin);
    int i;
    for ( i=0; i<DynamicArray_size(da); i++ ) {
        temp[new_origin+i] = DynamicArray_get(da,i);
    }

    free(da->buffer);
    da->buffer = temp;

    da->capacity = 2 * da->capacity;
    da->origin = new_origin;
    da->end = new_end;

    return;

}

/* public functions **********************************************************/

DynamicArray * DynamicArray_new(void) {
    DynamicArray * da = (DynamicArray *) malloc(sizeof(DynamicArray));
    da->capacity = DYNAMIC_ARRAY_INITIAL_CAPACITY;    
    da->buffer = (double *) calloc ( da->capacity, sizeof(double) ); 
    da->origin = da->capacity / 2;
    da->end = da->origin;
    return da;
}

void DynamicArray_destroy(DynamicArray * da) {
    free(da->buffer);
    da->buffer = NULL;
    return;
}

int DynamicArray_size(const DynamicArray * da) {
    assert(da->buffer != NULL);
    return da->end - da->origin;
}

char * DynamicArray_to_string(const DynamicArray * da) {
    assert(da->buffer != NULL);
    char * str = (char *) calloc (20,DynamicArray_size(da)),
         temp[20];
    int j = 1;
    str[0] = '[';
    int i;
    for ( i=0; i < DynamicArray_size(da); i++ ) {
        if ( DynamicArray_get(da,i) == 0 ) {
            snprintf ( temp, 20, "0" );
        } else {
            snprintf ( temp, 20, "%.5lf", DynamicArray_get(da,i) ); 
        }
        if ( i < DynamicArray_size(da) - 1 ) {
            sprintf( str + j, "%s,", temp);
            j += strlen(temp) + 1;
        } else {
            sprintf( str + j, "%s", temp);
            j += strlen(temp);
        }

    }
    str[j] = ']';
    return str;
}

void DynamicArray_print_debug_info(const DynamicArray * da) {

    char * s = DynamicArray_to_string(da);
    printf ( "  %s\n", s);
    printf ( "  capacity: %d\n  origin: %d\n  end: %d\n  size: %d\n\n",
      da->capacity, 
      da->origin, 
      da->end,
      DynamicArray_size(da));

    free(s);

}

void DynamicArray_set(DynamicArray * da, int index, double value) {
    assert(da->buffer != NULL);
    assert ( index >= 0 );
    while ( out_of_buffer(da, index_to_offset(da, index) ) ) {
        extend_buffer(da);
    }
    da->buffer[index_to_offset(da, index)] = value;
    if ( index >= DynamicArray_size(da) ) {
        da->end = index_to_offset(da,index+1);
    }

}

double DynamicArray_get(const DynamicArray * da, int index) {
    assert(da->buffer != NULL);
    assert ( index >= 0 );
    if ( index >= DynamicArray_size(da) ) {
        return 0;
    } else {
        return da->buffer[index_to_offset(da,index)];
    }
}

void DynamicArray_push(DynamicArray * da, double value ) {
    DynamicArray_set(da, DynamicArray_size(da), value );
}

void DynamicArray_push_front(DynamicArray * da, double value) {
    assert(da->buffer != NULL);
    while ( da->origin == 0 ) {
        extend_buffer(da);
    }
    da->origin--;
    DynamicArray_set(da,0,value);
}

double DynamicArray_pop(DynamicArray * da) {
    assert(DynamicArray_size(da) > 0);
    double value = DynamicArray_get(da, DynamicArray_size(da)-1);
    DynamicArray_set(da, DynamicArray_size(da)-1, 0.0);
    da->end--;
    return value;
}

double DynamicArray_pop_front(DynamicArray * da) {
    assert(DynamicArray_size(da) > 0);
    double value = DynamicArray_get(da, 0);
    da->origin++;
    return value;    
}

DynamicArray * DynamicArray_map(const DynamicArray * da, double (*f) (double)) {
    assert(da->buffer != NULL);
    DynamicArray * result = DynamicArray_new();
    assert(result->buffer != NULL);
    int i;
    for ( i=0; i<DynamicArray_size(da); i++ ) {
        DynamicArray_set(result, i, f(DynamicArray_get(da, i)));
    }
    return result;
}

DynamicArray * DynamicArray_subarray(DynamicArray * da, int a, int b) {

  assert(da->buffer != NULL);
  assert(b >= a);

  DynamicArray * result = DynamicArray_new();
  int i;  
  for (i=a; i<b; i++) {
      DynamicArray_push(result,DynamicArray_get(da, i));
  }

  return result;

}

/* EXERCISES: ********************************************************/

/*=====================================FUNCTION 1=====================================
*Function: DynamicArray_min
*---------------------------
*Takes an array and finds the minimum value
* da : input array
* returns: minimum value in the array
*/
double DynamicArray_min ( const DynamicArray * da ){
    assert(da->buffer != NULL);
    double min = DynamicArray_get(da, 0);
    int i;
    for ( i=0; i<DynamicArray_size(da); i++ ) {
        if (min > DynamicArray_get(da, i)){
            min = DynamicArray_get(da, i);
        }
    }
    return min;
}

/*=====================================FUNCTION 2=====================================
*Function: DynamicArray_max
*---------------------------
*Takes an array and finds the maximum value
* da : input array
* returns: maximum value in the array
*/
double DynamicArray_max ( const DynamicArray * da ){
    assert(da->buffer != NULL);
    double max = DynamicArray_get(da, DynamicArray_size(da));
    int i;
    for ( i=DynamicArray_size(da)-1; i>=0; i--) {
        if (max < DynamicArray_get(da, i)){
            max = DynamicArray_get(da, i);
        }
    }
    return max;
}

/*=====================================FUNCTION 3=====================================
*Function: DynamicArray_mean
*----------------------------
*Takes an array and finds the mean value
* da : input array
* returns: mean value of the array
*/
double DynamicArray_mean ( const DynamicArray * da ){
    assert(da->buffer != NULL);
    double mean;
    double sum = 0.0;
    int i;
    for ( i=0; i<DynamicArray_size(da); i++ ) {
        sum += DynamicArray_get(da, i);
    }
    mean = sum / DynamicArray_size(da);
    printf("Sum=%f , Mean=%f ",sum, mean);
    return mean;
}

/*=====================================FUNCTION 4=====================================
*Function: DynamicArray_median
*------------------------------
*Takes an array and finds the median value
* da : input array
* returns: median value of the array
*/
double DynamicArray_median ( const DynamicArray * da ){
    assert(da->buffer != NULL);
    double median;
    int i;
    
    if (DynamicArray_size(da)%2 != 0){
        median = DynamicArray_get(da, DynamicArray_size(da)/2);
    }
    else{
        median = DynamicArray_get(da, (DynamicArray_size(da)/2 + DynamicArray_size(da)/2 + 1) /2);
    }
    printf("Median=%f ", median);
    return median;
}

/*=====================================FUNCTION 5=====================================
*Function: DynamicArray_sum
*---------------------------
*Takes an array and finds the sum
* da : input array
* returns: sum of the array values
*/
double DynamicArray_sum ( const DynamicArray * da ){
    double sum = 0.0;
    int i;
    for ( i=0; i<DynamicArray_size(da); i++ ) {
        sum += DynamicArray_get(da, i);
    }
    printf("Sum=%f",sum);
    return sum;
}

/*=====================================FUNCTION 6=====================================
*Function: DynamicArray_last
*----------------------------
*Takes an array and finds the last value
* da : input array
* returns: last value of the array
*/
double DynamicArray_last ( const DynamicArray * da ){
    assert(da->buffer != NULL);
    double last = DynamicArray_get(da, DynamicArray_size(da) - 1);
    return last;
}

/*=====================================FUNCTION 7=====================================
*Function: DynamicArray_first
*-----------------------------
*Takes an array and finds the first value
* da : input array
* returns: first value of the array
*/
double DynamicArray_first ( const DynamicArray * da ){
    assert(da->buffer != NULL);
    double first = DynamicArray_get(da, 0);
    return first;
}

/*=====================================FUNCTION 8=====================================
*Function: DynamicArray_copy
*---------------------------
*Takes an array and copies value to another new array
* da : input array
* returns: result containing copied values
*/
DynamicArray * DynamicArray_copy ( const DynamicArray * da ){
    assert(da->buffer != NULL);
    DynamicArray * result = DynamicArray_new();
    assert(result->buffer != NULL);
    int i;
    for ( i=0; i<DynamicArray_size(da); i++ ) {
        DynamicArray_push( result, DynamicArray_get(da, i));
    }
    return result;
}

/*=====================================FUNCTION 9=====================================
*Function: DynamicArray_range
*-----------------------------
*To provide the range of defined values
* a : start of the range
* b : end of the range
* step : step-size or interval of values in the range
* returns: result containing the range of values
*/
DynamicArray * DynamicArray_range ( double a, double b, double step){
    DynamicArray * result = DynamicArray_new();
    assert(result->buffer != NULL);
    double x = a;
    while ( x < b ) {
        DynamicArray_push(result, x);
        //printf("%f \n", DynamicArray_get(result, x));
        x += step;
    }
    return result;
}

/*=====================================FUNCTION 10=====================================
*Function: DynamicArray_concat
*------------------------------
*Takes two arrays and concatenates them
* a : first input array
* b : second input array
* returns: result array containing concatenated values of arrays a and b
*/
DynamicArray * DynamicArray_concat ( const DynamicArray * a, const DynamicArray * b ){
    assert(a->buffer != NULL);
    assert(b->buffer != NULL);
    DynamicArray * result = DynamicArray_new();
    assert(result->buffer != NULL);
    
    int i, j;
    for (i=0; i<DynamicArray_size(a); i++){
        DynamicArray_push(result, DynamicArray_get(a, i));
        //printf("%f , ", DynamicArray_get(result, i));
    }   
    for (i=0, j=DynamicArray_size(a); j<(DynamicArray_size(a)+DynamicArray_size(b)) && i<DynamicArray_size(b); i++, j++){
        DynamicArray_push(result, DynamicArray_get(b, i));
        //printf("%f , ", DynamicArray_get(result, j));
    }
return result;
}

/*=====================================FUNCTION 11=====================================
*Function: DynamicArray_take
*----------------------------
*Takes an array and shows value as defined
* a : input array
* value: the number of values to show- can be positive, negative
* & even more than input array size 
* returns: result as per the definition
*/
DynamicArray * DynamicArray_take ( const DynamicArray * a, int value ){
    assert(a->buffer != NULL);
    DynamicArray * result = DynamicArray_new();
    assert(result->buffer != NULL);
    
    int i;

    if (value >= 0){
        if (value <= DynamicArray_size(a)){
            for (i=0; i<value; i++){
                DynamicArray_push(result, DynamicArray_get(a, i));
            }
        }
        else {
            for (i=0; i<value; i++){
                DynamicArray_push(result, DynamicArray_get(a, i));
            }
            for (i = 0; i>value; i++){
                DynamicArray_push(result, DynamicArray_get(a, 0));
            }
        }
    }
    else{
        for (i=value; i >= 0; i--){
            DynamicArray_push(result, DynamicArray_get(a , i));
        }
    }
    return result;
}