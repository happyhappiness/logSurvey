
rmfiles('inc1');

# No target gets correct error
run_make_test('', '', '#MAKE#: *** No targets.  Stop.', 512);

# No target in included file either, still gets correct error.
touch('inc1.mk');
run_make_test('include inc1.mk', '', '#MAKE#: *** No targets.  Stop.', 512);
rmfiles('inc1.mk');

# Include same file multiple times

run_make_test(q!
