.PHONY: clean allcpp allc

CXX := g++
SRCDIR := src
BINDIR := bin
 
CPPEXT := cpp
CPPSOURCES := $(shell find $(SRCDIR) -type f -name p*.$(CPPEXT))
CPPOBJECTS := $(patsubst $(SRCDIR)/p%,$(BINDIR)/p%,$(CPPSOURCES:.$(CPPEXT)=.exe))
CPPFLAGS := -g -Wno-write-strings

allcpp: $(CPPOBJECTS)
	@true

$(BINDIR)/p200.exe: $(SRCDIR)/p200.cpp
	$(CXX) $(CPPFLAGS) -o $@ $< ; test $$?
	touch $@

# *.cpp
$(BINDIR)/p%.exe: $(SRCDIR)/p%.$(CPPEXT) $(SRCDIR)/common.h
	@mkdir -p $(BINDIR)
	$(CXX) $(CPPFLAGS) -o $@ $<

clean:
	echo " Cleaning..."; 
	$(RM) -r $(BINDIR)

