CFLAGS = -Wall

SRCDIR := src
TESTDIR := test
OBJDIR := build
BINDIR := bin

all: $(BINDIR)/tests

check: $(BINDIR)/tests
	$<

OBJS := $(addprefix $(OBJDIR)/,\
	\
	roman.o \
	roman_check.o)

$(BINDIR)/tests: $(TESTDIR)/tests.c $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ \
		$(shell pkg-config --cflags --libs check)

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(TESTDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ \
		$(shell pkg-config --cflags check)

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean

clean:
	$(RM) -r $(OBJDIR) $(BINDIR)
