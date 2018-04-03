"#MAKE#: *** No rule to make target 'end', needed by 'baz'.  Stop.\n",
512);

# Test that the diagnostics is issued even if the target has been
# tried before with the dontcare flag (include/-include case).
#
run_make_test('
include bar

all:

foo: baz
bar: baz
baz: end
',
'',
"#MAKEFILE#:2: bar: $ERR_no_such_file
#MAKE#: *** No rule to make target 'end', needed by 'baz'.  Stop.\n",
512);

# Test include of make-able file doesn't show an error (Savannah #102)
run_make_test(q!
.PHONY: default
