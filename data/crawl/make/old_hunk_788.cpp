$answer = "This is another included makefile\n";
&compare_output($answer, &get_logfile(1));

# Try to build the "error" target; this will fail since we don't know
# how to create makeit.mk, but we should also get a message (even though
# the -include suppressed it during the makefile read phase, we should
# see one during the makefile run phase).

# The fix to this caused more problems than the error, so I removed it.
# pds -- 22 Jan 2000

#&run_make_with_options($makefile, "error", &get_logfile, 512);
#$answer = "$make_name: *** No rule to make target `makeit.mk', needed by `error'.\n";
#&compare_output($answer, &get_logfile(1));

1;
