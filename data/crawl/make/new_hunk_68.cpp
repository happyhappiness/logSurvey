"#MAKE#: *** No rule to make target 'end', needed by 'baz'.  Stop.\n",
512);

# Test include of make-able file doesn't show an error (Savannah #102)
run_make_test(q!
.PHONY: default
