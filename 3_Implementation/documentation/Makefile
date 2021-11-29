# Document the code using Doxygen

doc: Doxyfile
	doxygen ./Doxyfile
  
  PROJ_NAME = 
SRC = 

ifdef OS
   RM = del /q
   FixPath = $(subst /,,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
      EXEC = out
   endif
endif

build:
    gcc $(SRC) -o $(call FixPath,$(PROJ_NAME).$(EXEC))

run: build
    ./$(call FixPath,$(PROJ_NAME).$(EXEC))

clean:
    $(RM) $(call FixPath,$(PROJ_NAME).$(EXEC))
