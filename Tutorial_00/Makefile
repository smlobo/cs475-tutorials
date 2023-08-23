GPP=g++-13

OPENGLLIB= -lGL
GLEWLIB= -lGLEW
GLFWLIB = -lglfw
LIBS=$(OPENGLLIB) $(GLEWLIB) $(GLFWLIB)
#LDFLAGS=-L/usr/local/lib
LDFLAGS=-L/usr/local/lib -L/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries
CPPFLAGS=-I/usr/local/include

BIN=00_glInit
SRCS=00_glInit.cpp
INCLUDES=

all: $(BIN)


$(BIN): $(SRCS) $(INCLUDES)
	$(GPP) $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)

clean:
	rm -f *~ *.o $(BIN)
