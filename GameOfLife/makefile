#########################################################
# File: Makefile
#########################################################

# #'s are line-comments 

# CXX is a standard variable name used for the compiler. 
CXX = g++

# CXXFLAGS is a standard variable name for compile flags.
# -std=c++0x specifies to use a certain language version.
CXXFLAGS = -std=c++0x

# -Wall turns on all warnings
CXXFLAGS += -Wall

# -pedantic-errors strictly enforces the standard
CXXFLAGS += -pedantic-errors

# -g turns on debug information 
CXXFLAGS += -g

####################
### USER SECTION ###
####################

# SRCS is a standard name for the source files. 
SRC1 = gameOfLife.cpp
SRCS = ${SRC1}

# HEADERS is a standard name for the header files. 
HEADER1 = 
HEADERS = ${HEADER1} 

# These will be executable names. 
PROG1 = gameOfLife
PROGS = ${PROG1} 

# Report file. 
DOC = a1report.pdf

# This is the name of compressed file. 
TAR = cs162_assignment1_baljotsingh.tar.bz2

#####################
### BUILD SECTION ###
#####################
# Typing 'make' in terminal calls the first build availible.
# In this case, gameOfLife.

# Typing 'make gameOfLife' in terminal calls this build.

gameOfLife: ${SRC1} ${HEADER1}
	${CXX} ${CXXFLAGS} ${SRC1} -o ${PROG1}

# Typing 'make tar' in terminal calls this build.

tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} ${DOC} makefile

# Typing 'make clean' calls this build.
# It's designed to clean up the folder. It will clean all executable and object files in folder

clean: 
	rm -f ${PROGS} *.o *~

