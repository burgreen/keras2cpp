/* 1-test-c.c

// evaluate model using c wrapper of keras2cpp

// 2019.03.01 initial coding; greg.burgreen@msstate.edu
*/

#include <stdio.h>

#include "keras2cpp_wrapper.h"

int main( int argc, char** argv )
{
  int rc;

  int model = keras2cpp_model_create();

  rc = keras2cpp_model_load( model, "../build/example.model" );

  int num_in = 10;
  int num_out = 1;
  float in[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  float out[1];

  rc = keras2cpp_model_evaluate( model, num_in, in, num_out, out );

  for( int i=0; i < num_in;  i++ ) printf( "in[%i] = %f\n", i, in[i] );
  for( int i=0; i < num_out; i++ ) printf( "out[%i] = %f\n", i, out[i] );

  rc = keras2cpp_model_delete( model );

  printf("evaluated from c\n");

  return 0;
}
