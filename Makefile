CXX = g++
ROOTFLAGS = `root-config --cflags --libs`
CXXFLAGS = -Wall -O2 -Werror -Wextra $(ROOTFLAGS)
# CXXFLAGS = -Wall -O2 -Wextra $(ROOTFLAGS)

ggTrack.exe: ggTrack.C
	$(CXX) $(CXXFLAGS)  -o $@ $<

