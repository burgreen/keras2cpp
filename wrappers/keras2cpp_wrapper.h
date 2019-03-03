/* keras2cpp_wrapper.h

// 2019.03.01 initial coding; greg.burgreen@msststae.edu

// C and F90 wrapper of keras2cpp
*/

#ifndef keras2cpp_wrapper_h
#define keras2cpp_wrapper_h

int  keras2cpp_model_create();

int  keras2cpp_model_load( int model, const char* filename );

int  keras2cpp_model_evaluate( int model, int n_in,  float* in, 
                                          int n_out, float* out );
int  keras2cpp_model_delete( int model );

#endif