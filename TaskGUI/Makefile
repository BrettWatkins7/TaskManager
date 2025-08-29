CXX = g++
CXXFLAGS = -I./imgui -I./imgui/backends -Wall -std=c++17

SOURCES = main.cpp \
					Application.cpp \
					imgui/imgui.cpp \
					imgui/imgui_draw.cpp \
					imgui/imgui_widgets.cpp \
					imgui/imgui_tables.cpp \
					imgui/imgui_stdlib.cpp \
					imgui/backends/imgui_impl_glfw.cpp \
					imgui/backends/imgui_impl_opengl3.cpp

LIBS = -lglfw -lGL -ldl -lX11 -lpthread

all: taskgui

taskgui: $(SOURCES)
	$(CXX) $(CXXFLAGS) -o taskgui $(SOURCES) $(LIBS)

clean:
	rm -f taskgui
