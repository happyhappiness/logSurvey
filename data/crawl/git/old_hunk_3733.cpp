
	init_vars &&
	rm -f "$HOME/stdout" "$HOME/stderr" "$HOME/cmd" &&
	echo git $global_args check-ignore $quiet_opt $verbose_opt $args \
		>"$HOME/cmd" &&
	test_expect_code "$expect_code" \
		git $global_args check-ignore $quiet_opt $verbose_opt $args \
		>"$HOME/stdout" 2>"$HOME/stderr" &&
	test_cmp "$HOME/expected-stdout" "$HOME/stdout" &&
	stderr_empty_on_success "$expect_code"
}

# Runs the same code with 3 different levels of output verbosity,
# expecting success each time.  Takes advantage of the fact that
# check-ignore --verbose output is the same as normal output except
# for the extra first column.
#
# Arguments:
#   - (optional) prereqs for this test, e.g. 'SYMLINKS'
#   - test name
#   - output to expect from -v / --verbose mode
#   - code to run (should invoke test_check_ignore)
test_expect_success_multi () {
	prereq=
