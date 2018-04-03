
rmfiles('inc1');

# include a directory

if ($all_tests) {
    # Test that include of a rebuild-able file doesn't show a warning
    # Savannah bug #102
    run_make_test(q!
include foo
foo: ; @echo foo = bar > $@
!,
                  '', "#MAKE#: 'foo' is up to date.\n");
    rmfiles('foo');
}

1;
