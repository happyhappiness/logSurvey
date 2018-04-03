
rmfiles('inc1');

# Including files that can't be read should show an error
create_file('inc1', 'FOO := foo');
chmod 0000, 'inc1';

run_make_test(q!
include inc1
all:;@echo $(FOO)
!,
              '', "#MAKEFILE#:2: inc1: $ERR_unreadable_file\n#MAKE#: *** No rule to make target 'inc1'.  Stop.", 512);

# Unreadable files that we know how to successfully recreate should work

run_make_test(sprintf(q!
all:;@echo $(FOO)
include inc1
inc1:; @%s $@ && echo FOO := bar > $@
!, $CMD_rmfile),
              '', "bar");

rmfiles('inc1');

1;
