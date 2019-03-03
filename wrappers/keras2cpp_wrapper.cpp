/* keras2cpp_wrapper.cpp

// 2019.03.01 initial coding; greg.burgreen@msststae.edu

// C and F90 wrapper of keras2cpp
*/

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "../src/model.h"

using keras2cpp::Model;
using keras2cpp::Tensor;
using keras2cpp::Stream;

static Model* p_model = nullptr;

  static int
//------------------------------------------
  s_handle( Model* m )
//------------------------------------------
{
  return 1;
}

  static Model*
//------------------------------------------
  s_pointer( int handle )
//------------------------------------------
{
  if( handle != 1 ) { printf("bad handle\n"); exit(1); }

  return p_model;
}

#if defined MAIN_IS_F90
extern "C" {
#endif 

#include "keras2cpp_wrapper.h"

  int
//------------------------------------------
  keras2cpp_model_create()
//------------------------------------------
{
  return 1;
}

  int
//------------------------------------------
  keras2cpp_model_load( int model, const char* filename )
//------------------------------------------
{
  printf("filename = <%s>\n", filename );

  std::string file(filename);

  Stream s( file );

  p_model = new Model( s );

  return 0;
}

  int
//------------------------------------------
  keras2cpp_model_evaluate( int model, int n_in,  float* in,
                                       int n_out, float* out )
//------------------------------------------
{
  Tensor t_in; t_in.resize( n_in );

  for( int i=0; i < n_in; i++ ) t_in(i) = in[i];

  Tensor t_out = (*p_model)(t_in);

  if( t_out.size() != n_out ) { printf("bad n_out\n"); exit(1); }

  for( int i=0; i < n_out; i++ ) out[i] = t_out(i);

  return 0;
}

  int
//------------------------------------------
  keras2cpp_model_delete( int model )
//------------------------------------------
{
  if( p_model ) delete p_model;

  return 0;
}

#if defined MAIN_IS_F90
#include "keras2cpp_wrapper.ipp"
#endif

#if defined MAIN_IS_F90
}
#endif 
