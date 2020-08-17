CXX = gcc
CXXFLAGS = -Wall -g
SGX_SDK = /opt/intel/sgxsdk/sgxsdk/
INCLUDE = -I$(SGX_SDK)/include/
LIBS = -L$(SGX_SDK)/lib64/
LIB = -l:libsgx_capable.a

run: App.o
	$(CXX) App.o -o run $(INCLUDE) $(LIBS) $(LIB) 
App.o: App.cpp
	$(CXX) -c App.cpp $(CXXFLAGS) $(INCLUDE) $(LIBS) $(LIB)

clean:
	rm run App.o
