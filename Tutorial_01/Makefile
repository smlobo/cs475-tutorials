GPP=g++-13

OPENGLLIB= -lGL
GLEWLIB= -lGLEW
GLFWLIB = -lglfw
LIBS=$(OPENGLLIB) $(GLEWLIB) $(GLFWLIB)
#LDFLAGS=-L/usr/local/lib
LDFLAGS=-L/usr/local/lib -L/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries
CPPFLAGS=-I/usr/local/include

BIN1=01_triangle
BIN2=01_triangle_dep
BIN3=cube-rotate
SRCS1=01_triangle.cpp gl_framework.cpp shader_util.cpp
SRCS2=01_triangle_dep.cpp gl_framework.cpp shader_util.cpp 
SRCS3=cube-rotate.cpp
INCLUDES=gl_framework.hpp shader_util.hpp

all: $(BIN1) $(BIN2) $(BIN3)

$(BIN1): $(SRCS1) $(INCLUDES)
	$(GPP) $(CPPFLAGS) $(SRCS1) -o $(BIN1) $(LDFLAGS) $(LIBS)

$(BIN2): $(SRCS2) $(INCLUDES)
	$(GPP) $(CPPFLAGS) $(SRCS2) -o $(BIN2) $(LDFLAGS) $(LIBS)

$(BIN3): $(SRCS3)
	$(GPP) $(SRCS3) -o $(BIN3) -framework OpenGL -framework GLUT

clean:
	rm -f *~ *.o $(BIN1) $(BIN2) $(BIN3)
