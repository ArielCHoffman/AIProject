CC=g++
PREFIX=/usr
CXX=g++
CXXFLAGS= -D_MP_INTERNAL -D_AMD64_ -D_USE_THREAD_LOCAL  -fopenmp -mfpmath=sse -fno-strict-aliasing -fPIC -DZ3DEBUG -D_TRACE -c -g -Wall -msse -msse2 
CXX_OUT_FLAG=-o 
OBJ_EXT=.o
LIB_EXT=.a
AR=ar
AR_FLAGS=rcs
AR_OUTFLAG= 
EXE_EXT=
LINK=g++
LINK_FLAGS=
LINK_OUT_FLAG=-o 
LINK_EXTRA_FLAGS=-lpthread  -fopenmp -lrt
SO_EXT=.so
SLINK=g++
SLINK_FLAGS= -shared -flto -O3
SLINK_EXTRA_FLAGS= -fopenmp -lrt
SLINK_OUT_FLAG=-o 
