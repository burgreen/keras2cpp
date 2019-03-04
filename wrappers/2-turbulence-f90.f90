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
  c_float, dimension(3) :: in, mean, scale
  c_float, dimension(4) :: out

  if( iargc() > 0 )then 
    call getarg( 1, argv )
    filename = trim(argv)
  endif

  call c_keras2cpp_model_create( rc )

  filename = "turbulence2.model"

  filename = trim(adjustl(filename))//char(0)

  call c_keras2cpp_model_load( model, filename, rc )

  n_in = 3
  n_out = 4

  ! this need to be read in from file
  mean(1)  = 5.41805403e+04 
  mean(2)  = 5.39642143e+00 
  mean(3)  = 4.51179963e-03
  scale(1) = 5.03700975e+04 
  scale(2) = 1.90951479e+01 
  scale(3) = 2.61080447e-03

  in(1) = 500
  in(2) = 1
  in(3) = 0

  do i=1,n_in
    in(i) = (in(i)-mean(i))/scale(i)
    !in(i) = 0.0
    print*, "in", i, in(i)
  enddo

  call c_keras2cpp_model_evaluate( model, n_in, in, n_out, out, rc )

  do i=1,n_out
    print*, "out", i, out(i)
  enddo

  call c_keras2cpp_model_delete( model, rc )

  print*, "evaluated from f90"

end program
