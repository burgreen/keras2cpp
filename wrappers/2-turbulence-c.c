/* 2-turbulence-c.c

// evaluate model using c wrapper of keras2cpp

// 2019.03.01 initial coding; greg.burgreen@msstate.edu
*/

#include <stdio.h>

#include "keras2cpp_wrapper.h"

int main( int argc, char** argv )
{
  int rc;

  int model = keras2cpp_model_create();

  rc = keras2cpp_model_load( model, "turbulence.model" );

  int num_in = 3;
  int num_out = 4;
  float in[] = {500, 1, 0};
  float out[4];

  rc = keras2cpp_model_evaluate( model, num_in, in, num_out, out );

  for( int i=0; i < num_in;  i++ ) printf( "in[%i] = %f\n", i, in[i] );
  for( int i=0; i < num_out; i++ ) printf( "out[%i] = %f\n", i, out[i] );

  rc = keras2cpp_model_delete( model );

  printf("evaluated from c\n");

  return 0;
}
