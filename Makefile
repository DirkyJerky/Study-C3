.PHONY: clean allcpp allc all

CXX := g++
SRCDIR := src
BINDIR := bin
 
CC := gcc
 
all: allcpp allc

CPPEXT := cpp
CPPSOURCES := $(shell find $(SRCDIR) -type f -name p*.$(CPPEXT))
CPPOBJECTS := $(patsubst $(SRCDIR)/p%,$(BINDIR)/p%,$(CPPSOURCES:.$(CPPEXT)=.exe))
CPPFLAGS := -g -Wno-write-strings

CEXT := c
CSOURCES := $(shell find $(SRCDIR) -type f -name p*.$(CEXT))
COBJECTS := $(patsubst $(SRCDIR)/p%,$(BINDIR)/p%,$(CSOURCES:.$(CEXT)=.exe))
CFLAGS := -g -Wall $(shell pkg-config --cflags gtk+-3.0)
CLIBFLAGS := $(shell pkg-config --libs gtk+-3.0) -rdynamic

allcpp: $(CPPOBJECTS)
	@true

allc: $(COBJECTS)
	@true

# *.cpp
$(BINDIR)/p%.exe: $(SRCDIR)/p%.$(CPPEXT) $(SRCDIR)/common.hpp
	@mkdir -p $(BINDIR)
	$(CXX) $(CPPFLAGS) -o $@ $<

# *.c
$(BINDIR)/p%.exe: $(SRCDIR)/p%.$(CEXT) $(SRCDIR)/common.h
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $< $(CLIBFLAGS)

clean:
	echo " Cleaning..."; 
	$(RM) -r $(BINDIR)

