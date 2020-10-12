# Author: Amrit Singh (2020)

OBJS_DIR = .objs

# define the executable
EXE=debugger

# list the object file dependencies
OBJS_DEBUGGER=debugger_main.o debugger.o

# set up the compiler
CC = clang
WARNINGS = -Wall -Wextra -Werror -Wno-error=unused-parameter -Wmissing-declarations -Wmissing-variable-declarations
CFLAGS_COMMON = $(WARNINGS) -std=c99 -c -MMD -MP -D_GNU_SOURCE
CFLAGS_RELEASE = $(CFLAGS_COMMON) -O2
CFLAGS_DEBUG = $(CFLAGS_COMMON) -O0 -g -DDEBUG

# set up linker
LD = clang
LDFLAGS = -lm

.PHONY: all
all: release

# build types
.PHONY: release
.PHONY: debug

release: $(EXE)
debug:   clean $(EXE:%=%-debug)

# include dependencies
-include $(OBJS_DIR)/*.d

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# patterns to create objects
# keep the debug and release suffix for object files so that we can always
# separate them correctly
$(OBJS_DIR)/%-debug.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS_DEBUG) $< -o $@

$(OBJS_DIR)/%-release.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS_RELEASE) $< -o $@

# define executables
$(EXE)-debug: $(OBJS_DEBUGGER:%.o=$(OBJS_DIR)/%-debug.o)
	$(LD) $^ $(LDFLAGS) -o $@

$(EXE): $(OBJS_DEBUGGER:%.o=$(OBJS_DIR)/%-release.o)
	$(LD) $^ $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf .objs $(EXE) $(EXE:%=%-debug)



