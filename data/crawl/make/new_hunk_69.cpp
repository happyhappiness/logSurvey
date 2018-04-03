
rmfiles('inc1', 'inc2');

# No target gets correct error
run_make_test('', '', '#MAKE#: *** No targets.  Stop.', 512);

