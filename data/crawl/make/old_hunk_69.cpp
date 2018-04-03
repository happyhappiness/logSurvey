
rmfiles('inc1', 'inc2');

# Test include of non-make-able file does show an error (Savannah #102)
run_make_test(q!
.PHONY: default
default:; @echo DONE

inc1:; echo > $@
include inc1
include inc2
!,
              '', "#MAKEFILE#:7: inc2: $ERR_no_such_file\n#MAKE#: *** No rule to make target 'inc2'.  Stop.\n", 512);

rmfiles('inc1');

# No target gets correct error
run_make_test('', '', '#MAKE#: *** No targets.  Stop.', 512);

