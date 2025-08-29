CXX = g++
CXXFLAGS = -I./imgui -I./imgui/backends -Wall -std=c++17

SOURCES = main.cpp \
					Application.cpp \
					imgui/imgui.cpp \
					imgui/imgui_draw.cpp \
					imgui/imgui_widgets.cpp \
					imgui/imgui_tables.cpp \
					imgui/backends/imgui_impl_glfw.cpp \
					imgui/backends/imgui_impl_opengl3.cpp

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LIBS = -lglfw -lGL -ldl -lX11 -lpthread
endif
ifeq ($(UNAME_S),Darwin)
	BREW_PREFIX := $(shell brew --prefix glfw)
	CXXFLAGS += -I$(BREW_PREFIX)/include
	LIBS = -L$(BREW_PREFIX)/lib -lglfw -framework OpenGl -framework Cocoa -framework IOKit -framework CoreVideo
endif

all: taskgui

taskgui: $(SOURCES)
	$(CXX) $(CXXFLAGS) -o taskgui $(SOURCES) $(LIBS)

clean:
	rm -f taskgui
