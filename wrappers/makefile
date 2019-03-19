# makefile-lib

#--------------------------- 
# include what to build
#----------------------------

include make-2-f90-exe

#--------------------------- 
# rules section
#----------------------------

default: $(OUT)

$(EXE):	$(OBJECTS) $(MAIN_OBJECT)
	$(EXE_LINK) $(EXE_LINK_FLAGS) $(EXE_OUT) $(EXE) $(MAIN_OBJECT) $(OBJECTS) $(LIBS) $(LIBS_PATH)

$(STATIC_LIB): $(OBJECTS)
	$(STATIC_LIB_LINK) $(STATIC_LIB_LINK_FLAGS) $(STATIC_LIB) $(OBJECTS) 

$(SHARED_LIB): $(OBJECTS)
	$(SHARED_LIB_LINK) $(SHARED_LIB_LINK_FLAGS) -o $(SHARED_LIB) $(OBJECTS) 

.f90.$(OBJ):
	$(F90_COMPILER) -c $(F90_FLAGS) $(F90_PATH) $(F90_OUT) $*.$(OBJ) $*.f90

.c.$(OBJ):
	$(C_COMPILER) -c $(C_FLAGS) $(C_PATH) $(C_OUT)$*.$(OBJ) $*.c

.cpp.$(OBJ):
	$(CPP_COMPILER) -c $(CPP_FLAGS) $(CPP_PATH) $(CPP_OUT)$*.$(OBJ) $*.cpp

.cc.$(OBJ):
	$(CPP_COMPILER) -c $(CPP_FLAGS) $(CPP_PATH) $(CPP_OUT)$*.$(OBJ) $*.cc

clean:
	-rm *.mod
	-rm $(OBJECTS)
	-rm $(MAIN_OBJECT)
	-rm $(OUT)

depend:	
	$(F90_DEPEND) --file=make-depend-output $(F90_PATH) $(FILES_F90) $(MAIN_F90)

include make-depend-output
