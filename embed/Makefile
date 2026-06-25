CXX = g++
CXXFLAGS = -g -Wall -I include

SRCMODULES = src/vehicle_manager.cpp src/device/emulator/gps.cpp src/sender.cpp src/device/emulator/battery.cpp
OBJMODULES = $(SRCMODULES:.c=.o)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $< -o $@

bin/prog: src/main.cpp $(OBJMODULES)
	$(CXX) $(CXXFLAGS) $^ -o $@