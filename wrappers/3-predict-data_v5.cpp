// 3-predict-data_v5.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "keras2cpp_wrapper.h"

using namespace std;

  int
//---------------------------------------------
  main( int argc, char** argv )
//---------------------------------------------
{
  char text[256];

  string model_archive = "data_v5.model";
  string data = "data_v5.csv";

  // read keras model

  int model = keras2cpp_model_create();
  int rc = keras2cpp_model_load( model, model_archive.c_str() );
  int n_in = 3;
  int n_out = 4;
  float mean[] = { 3.60555178, -0.24038211, -2.52406594 };
  float scale[] = {1.64775645, 1.24384599, 1.06873837 };
  float in[3];
  float out[4];

  // read and predict data

  ifstream ifs( data.c_str() ); if( ! ifs ) exit(1);

  ifs.getline(text,256);
  cout << text << endl;

  double Re,u_mean,dudy,TKE;
  double u_rms,v_rms,w_rms,uv_rms;
  string s;

  while( ifs )
  //for( int i=0; i<10; i++ )
  {
    getline(ifs, s, ','); if( ! ifs ) break; Re = stof(s);
    getline(ifs, s, ','); u_mean = stof(s);
    getline(ifs, s, ','); dudy   = stof(s);
    getline(ifs, s, ','); TKE    = stof(s);
    getline(ifs, s, ','); u_rms  = stof(s);
    getline(ifs, s, ','); v_rms  = stof(s);
    getline(ifs, s, ','); w_rms  = stof(s);
    getline(ifs, s     ); uv_rms = stof(s);

    // actual data
    //cout << Re <<","<< u_mean <<" "<< dudy <<","<< TKE <<","
    //     << u_rms <<","<< v_rms <<","<< w_rms <<","<< uv_rms << endl;

    if( Re < 1e-20 ) Re = 1e-20;
    if( dudy < 1e-20 ) dudy = 1e-20;
    if( TKE < 1e-20 ) TKE = 1e-20;
    in[0] = (std::log10(Re)   - mean[0]) / scale[0];
    in[1] = (std::log10(dudy) - mean[1]) / scale[1];
    in[2] = (std::log10(TKE)  - mean[2]) / scale[2];

    rc = keras2cpp_model_evaluate( model, n_in, in, n_out, out );

    for( int j=0; j<4; j++ ) out[j] = std::pow(10.,out[j]);

    if( dudy > 1e-19 )
    {
    // predicted data
    cout << Re <<","<< u_mean <<","<< dudy <<","<< TKE <<","
         << out[0] <<","<< out[1] <<","<< out[2] <<","<< out[3] << endl;
    }

    //cout << "-" << endl;
  }

  rc = keras2cpp_model_delete( model );

  return 0;
}
