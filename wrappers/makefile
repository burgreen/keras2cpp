# makefile

#--------------------------- 
# include what to build
#----------------------------

include make-3-cpp

#--------------------------- 
# rules section
#----------------------------

all:	$(FILES_OBJ) $(MAIN_OBJ)
	$(LINK) $(FLAGS_LINK) $(OUT_EXE) $(EXE) $(FILES_OBJ) $(MAIN_OBJ) $(LIBS) $(LIBPATH)

.f90.$(OBJ):
	$(F90) -c $(FLAGS_F90) $(PATH_F90) $(OUT_OBJ) $*.$(OBJ) $*.f90

.c.$(OBJ):
	$(C) -c $(FLAGS_C) $(PATH_C_CPP) $(OUT_OBJ_C_CPP)$*.$(OBJ) $*.c

.cpp.$(OBJ):
	$(CPP) -c $(FLAGS_CPP) $(PATH_C_CPP) $(OUT_OBJ_C_CPP)$*.$(OBJ) $*.cpp

.cc.$(OBJ):
	$(CPP) -c $(FLAGS_CPP) $(PATH_C_CPP) $(OUT_OBJ_C_CPP)$*.$(OBJ) $*.cc

clean:
	-rm *.mod
	-rm $(FILES_OBJ)
	-rm $(MAIN_OBJ)
	-rm a.exe a.out a

depend:	
	$(MAKEDEPEND) --file=make-depend-output $(F90PATH) $(FILES_F90) $(MAIN_F90)

include make-depend-output
