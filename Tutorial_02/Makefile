GPP=g++-13

OPENGLLIB= -lGL
GLEWLIB= -lGLEW
GLFWLIB = -lglfw
LIBS=$(OPENGLLIB) $(GLEWLIB) $(GLFWLIB)
#LDFLAGS=-L/usr/local/lib
LDFLAGS=-L/usr/local/lib -L/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries
CPPFLAGS=-I/usr/local/include -I./

BIN=02_colorcube
SRCS=02_colorcube.cpp gl_framework.cpp shader_util.cpp 
INCLUDES=gl_framework.hpp shader_util.hpp 02_colorcube.hpp

all: $(BIN)

$(BIN): $(SRCS) $(INCLUDES)
	$(GPP) $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)

clean:
	rm -f *~ *.o $(BIN)
