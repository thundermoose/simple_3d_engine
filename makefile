compiler := gcc

compiler_flags := -I./source -mavx2
linker_flags := -lm 
test_linker_flags := -lm -lthundertester

source := $(shell find ./source -regex [^\#]*\\.c)
objects := $(source:./source/%.c=./.tmp/%.o)
dependency := $(sourc:./source/%.c=./.tmp/%.d)

.PRECIOUS: $(objects) $(dependency)
executable := game
test_executable := test_game

all: $(executable)

test: $(test_executable)

clean:
	rm -rf .tmp $(executable)

$(executable): compiler_flags+=-DNDEBUG -O3
$(executable): $(objects)
	$(compiler) -o $@ $^ $(linker_flags)

$(test_executable): compiler_flags+=-ggdb -DTEST
$(test_executable): $(objects)
	$(compiler) -o $@ $^ $(test_linker_flags)

-include $(dependency)
.tmp/%.o: source/%.c
	mkdir -p $(@D)
	$(compiler) -c -o $@ $< $(compiler_flags)

.tmp/%.d: source/%.c
	mkdir -p $(@D)
	$(compiler) -M -MT $(@:%.d=%.o) -MF $@ $<
