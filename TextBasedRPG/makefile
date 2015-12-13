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
SRC1 = Creature.cpp BlueMen.cpp Barbarian.cpp ReptilePeople.cpp Goblin.cpp TheShadow.cpp Hero.cpp Rooms.cpp LevelOne.cpp LevelTwo.cpp LevelThree.cpp Item.cpp integer_validation.cpp double_validation.cpp main.cpp
SRCS = ${SRC1}

# HEADERS is a standard name for the header files. 
HEADER1 = Creature.h BlueMen.h Barbarian.h ReptilePeople.h Goblin.h TheShadow.h Hero.h Item.h Rooms.h LevelOne.h LevelTwo.h LevelThree.h integer_validation.h double_validation.h
HEADERS = ${HEADER1}

# These will be executable names. 
PROG1 = rpg
PROGS = ${PROG1}

DOC = fpReport.pdf

# This is the name of compressed file. 
TAR = cs162_fp_baljotsingh.tar.bz2

#####################
### BUILD SECTION ###
#####################
# Typing 'make rpg' in terminal calls this build.
# Typing 'make' in terminal calls the first build availible..

rpg: ${SRC1} ${HEADER1}
	${CXX} ${CXXFLAGS} ${SRC1} -o ${PROG1}

# Typing 'make tar' in terminal calls this build.

tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} ${DOC} makefile

# Typing 'make clean' calls this build.
# It's designed to clean up the folder. It will clean all executable and object files in folder

clean: 
	rm -f ${PROGS} *.o *~

