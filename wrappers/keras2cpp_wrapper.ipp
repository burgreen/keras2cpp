// keras2cpp.ipp

#if defined COMPILER_F_UNDERSCORE
  #define c_keras2cpp_model_create    c_keras2cpp_model_create_
  #define c_keras2cpp_model_delete    c_keras2cpp_model_delete_
  #define c_keras2cpp_model_load      c_keras2cpp_model_load_
  #define c_keras2cpp_model_evaluate  c_keras2cpp_model_evaluate_
  #define c_keras2cpp_model_evaluate_data_v4  c_keras2cpp_model_evaluate_data_v4_
  #define c_keras2cpp_model_evaluate_data_v5  c_keras2cpp_model_evaluate_data_v5_
#endif

#if defined COMPILER_F_CAPITALS
  #define c_keras2cpp_model_create     C_KERAS2CPP_MODEL_CREATE
  #define c_keras2cpp_model_delete     C_KERAS2CPP_MODEL_DELETE
  #define c_keras2cpp_model_load       C_KERAS2CPP_MODEL_LOAD
  #define c_keras2cpp_model_evaluate   C_KERAS2CPP_MODEL_EVALUATE
  #define c_keras2cpp_model_evaluate_data_v4  C_KERAS2CPP_MODEL_EVALUATE_DATA_V4_
  #define c_keras2cpp_model_evaluate_data_v5  C_KERAS2CPP_MODEL_EVALUATE_DATA_V5_
#endif

  void
//------------------------------------------
  c_keras2cpp_model_create( int* rc )
//------------------------------------------
{
  *rc = keras2cpp_model_create();
}

  void
//------------------------------------------
  c_keras2cpp_model_delete( int* model, int* rc )
//------------------------------------------
{
  *rc = keras2cpp_model_delete( *model );
}

  void
//------------------------------------------
  c_keras2cpp_model_load( int* model, const char* filename, int* rc )
//------------------------------------------
{ 
  *rc = keras2cpp_model_load( *model, filename );
}

  void
//------------------------------------------
  c_keras2cpp_model_evaluate
//------------------------------------------
( 
  int*    model, 
  int*    n_in, 
  float*  in, 
  int*    n_out, 
  float*  out, 
  int*    rc
)
{
  *rc = keras2cpp_model_evaluate( *model, *n_in, in, *n_out, out );
}

  void
//------------------------------------------
  c_keras2cpp_model_evaluate_data_v4
//------------------------------------------
( 
  int*    model, 
  int*    n_in, 
  float*  in, 
  int*    n_out, 
  float*  out, 
  int*    rc
)
{
  *rc = keras2cpp_model_evaluate_data_v4( *model, *n_in, in, *n_out, out );
}

  void
//------------------------------------------
  c_keras2cpp_model_evaluate_data_v5
//------------------------------------------
( 
  int*    model, 
  int*    n_in, 
  float*  in, 
  int*    n_out, 
  float*  out, 
  int*    rc
)
{
  *rc = keras2cpp_model_evaluate_data_v4( *model, *n_in, in, *n_out, out );
}