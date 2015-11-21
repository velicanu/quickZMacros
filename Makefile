CXX = g++
ROOTFLAGS = `root-config --cflags --libs`
CXXFLAGS = -Wall -O2 -Werror -Wextra $(ROOTFLAGS)
SRCS_C = $(wildcard *.C)
PROGS_C = $(patsubst %.C,%.exe,$(SRCS_C))
SRCS_cc = $(wildcard *.cc)
PROGS_cc = $(patsubst %.cc,%.exe,$(SRCS_cc))

all: $(PROGS_C) $(PROGS_cc)

%.exe: %.C
	$(CXX) $(CXXFLAGS)  -o $@ $<

%.exe: %.cc
	$(CXX) $(CXXFLAGS)  -o $@ $<
