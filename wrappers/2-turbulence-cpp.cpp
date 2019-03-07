// 2-turbulence-cpp.cpp

#include <iostream>

#include "keras2cpp_wrapper.h"

using namespace std;

int main( int argc, char** argv )
{
  int model = keras2cpp_model_create();

  int rc = keras2cpp_model_load( model, "turbulence2.model" );

  int n_in = 3;
  int n_out = 4;
  float mean[]  = { 5.41805403e+04, 5.39642143e+00, 4.51179963e-03 };
  float scale[] = { 5.03700975e+04, 1.90951479e+01, 2.61080447e-03  };
  float in[3];
  float out[4];

  in[0] = 500;
  in[1] = 1;
  in[2] = 0;

  for( int i=0; i < n_in; i++ )
  {
    in[i] = (in[i] - mean[i]) / scale[i];
    cout << "in[" << i << "] = " << in[i] << endl;
  }

  rc = keras2cpp_model_evaluate( model, n_in, in, n_out, out );

  for( int i=0; i < n_out; i++ )
  {
    cout << "out[" << i << "] = " << out[i] << endl;
  }
  cout << "evaluated by cpp" << endl;

  rc = keras2cpp_model_delete( model );

  return 0;
}
