$answer = "This is another included makefile\n";
&compare_output($answer, &get_logfile(1));

$makefile = undef;

# Try to build the "error" target; this will fail since we don't know
# how to create makeit.mk, but we should also get a message (even though
# the -include suppressed it during the makefile read phase, we should
# see one during the makefile run phase).

run_make_test
  ('
-include foo.mk
error: foo.mk ; @echo $@
',
   '',
   "#MAKE#: *** No rule to make target `foo.mk', needed by `error'.  Stop.\n",
   512
  );

# Make sure that target-specific variables don't impact things.  This could
# happen because a file record is created when a target-specific variable is
# set.

run_make_test
  ('
bar.mk: foo := baz
-include bar.mk
hello: ; @echo hello
',
   '',
   "hello\n"
  );


1;
