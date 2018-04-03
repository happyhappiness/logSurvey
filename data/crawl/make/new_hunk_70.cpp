
rmfiles('inc1');

if (defined $ERR_no_such_file) {

    # Test that the diagnostics is issued even if the target has been
    # tried before with the dontcare flag (include/-include case).
    #
    run_make_test('
include bar
-include foo

all:

foo: baz
bar: baz
baz: end
',
'',
                  "#MAKEFILE#:2: bar: $ERR_no_such_file\n#MAKE#: *** No rule to make target 'end', needed by 'baz'.  Stop.\n",
                  512);

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

    # Included file has a prerequisite that fails to build

    run_make_test(q!
default:; @echo DEFAULT
include inc1
inc1: foo; echo > $@
foo:; exit 1
!,
                  '', "exit 1\n#MAKEFILE#:3: inc1: $ERR_no_such_file\n#MAKE#: *** [#MAKEFILE#:5: foo] Error 1\n", 512);

    rmfiles('inc1');

    # Included file has a prerequisite we don't know how to build

    run_make_test(q!
default:; @echo DEFAULT
include inc1
inc1: foo; echo > $@
!,
                  '', "#MAKEFILE#:3: inc1: $ERR_no_such_file\n#MAKE#: *** No rule to make target 'foo', needed by 'inc1'.  Stop.\n", 512);

    rmfiles('inc1');
}

# Including files that can't be read should show an error
if (defined $ERR_unreadable_file) {
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
}

1;
