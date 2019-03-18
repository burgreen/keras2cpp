// 2-turbulence-cpp.cpp

#include <iostream>
#include <cmath>

#include "keras2cpp_wrapper.h"

using namespace std;

int main( int argc, char** argv )
{
  int model = keras2cpp_model_create();

  int rc = keras2cpp_model_load( model, "turbulence-log.model" );

  int n_in = 3;
  int n_out = 4;
  float mean[]  = { 4.48331753,-0.2465536, -2.53451854};
  float scale[] = {0.51062794,1.26746158,1.11060776};
  float in[3];
  float out[4];

  in[0] = 500;
  in[1] = 1;
  in[2] = 0;

  for( int i=0; i < n_in; i++ )
  {
    if( in[i] < 1.e-20 ) in[i] = 1.e-20;
    in[i] = std::log10( in[i] );
    in[i] = (in[i] - mean[i]) / scale[i];
    cout << "in[" << i << "] = " << in[i] << endl;
  }

  rc = keras2cpp_model_evaluate( model, n_in, in, n_out, out );

  for( int i=0; i < n_out; i++ )
  {
    out[i] = std::pow( 10., out[i] );
    cout << "out[" << i << "] = " << out[i] << endl;
  }
  cout << "evaluated by cpp" << endl;

  rc = keras2cpp_model_delete( model );

  return 0;
}
