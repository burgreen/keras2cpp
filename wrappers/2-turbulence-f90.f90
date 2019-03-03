! 1-test-f90.f90

! evaluate keras model via f90 wrapper of keras2cpp

! notes:
! 1. 2019.03.02 initial coding; greg.burgreen@msstate.edu

#include "keras2cpp_wrapper.h90"

!------------------------------------------
  program main
!------------------------------------------

  character*(80) :: argv
  character*(80) :: filename
  c_int model; 
  c_int rc; 
  c_int n_in, n_out; 
  c_float, dimension(3) :: in
  c_float, dimension(4) :: out

  if( iargc() > 0 )then 
    call getarg( 1, argv )
    filename = trim(argv)
  endif

  call c_keras2cpp_model_create( rc )

  filename = "turbulence.model"

  filename = trim(adjustl(filename))//char(0)

  call c_keras2cpp_model_load( model, filename, rc )

  n_in = 3
  n_out = 4

  in(1) = 500
  in(2) = 1
  in(3) = 0

  do i=1,n_in
    print*, "in", i, in(i)
  enddo

  call c_keras2cpp_model_evaluate( model, n_in, in, n_out, out, rc )

  do i=1,n_out
    print*, "out", i, out(i)
  enddo

  call c_keras2cpp_model_delete( model, rc )

  print*, "evaluated from f90"

end program
