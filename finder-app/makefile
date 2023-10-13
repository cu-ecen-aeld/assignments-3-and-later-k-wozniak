# Set the compiler
CC = gcc

# Set the source files for the writer application
SOURCES = writer.c

# Set the default build type to Release
ifndef CMAKE_BUILD_TYPE
	CMAKE_BUILD_TYPE = Release
endif

# Set the compiler flags for the different build types
ifeq ($(CMAKE_BUILD_TYPE), Debug)
	CFLAGS = -g
else
	CFLAGS = -O2
endif

# Support for cross-compilation
ifdef CROSS_COMPILE
	CC = $(CROSS_COMPILE)gcc
endif

# Add an executable target for the writer application
writer: $(SOURCES)
	$(CC) $(CFLAGS) -o writer $(SOURCES)

# Add a clean target to remove the writer application and all .o files
clean:
	rm -f writer *.o
