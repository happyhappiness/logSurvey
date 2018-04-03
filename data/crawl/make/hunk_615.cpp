 
 $details = "";
 
-open(MAKEFILE, "> $makefile");
+# TEST 0: Recursive
 
-# The Contents of the MAKEFILE ...
-
-print MAKEFILE <<'EOF';
+run_make_test('
+ugh = Goodbye
 foo = $(bar)
 bar = ${ugh}
 ugh = Hello
+all: ; @echo $(foo)
+',
+              '', "Hello\n");
 
-all: multi ; @echo $(foo)
-
-multi: ; $(multi)
-
-x := foo
-y := $(x) bar
-x := later
-
-nullstring :=
-space := $(nullstring) $(nullstring)
-
-next: ; @echo $x$(space)$y
-
-define multi
-@echo hi
-echo there
-endef
-
-ifdef BOGUS
-define
-@echo error
-endef
-endif
-
-define outer
- define inner
-  A = B
- endef
-endef
-
-$(eval $(outer))
-
-outer: ; @echo $(inner)
-
-EOF
-
-# END of Contents of MAKEFILE
-
-close(MAKEFILE);
-
-# TEST #1
-# -------
-
-&run_make_with_options($makefile, "", &get_logfile);
-$answer = "hi\necho there\nthere\nHello\n";
-&compare_output($answer, &get_logfile(1));
-
-# TEST #2
-# -------
-
-&run_make_with_options($makefile, "next", &get_logfile);
-$answer = "later foo bar\n";
-&compare_output($answer, &get_logfile(1));
-
-# TEST #3
-# -------
-
-&run_make_with_options($makefile, "BOGUS=true", &get_logfile, 512);
-$answer = "$makefile:24: *** empty variable name.  Stop.\n";
-&compare_output($answer, &get_logfile(1));
-
-# TEST #4
-# -------
-
-&run_make_with_options($makefile, "outer", &get_logfile);
-$answer = "A = B\n";
-&compare_output($answer, &get_logfile(1));
-
-# Clean up from "old style" testing.  If all the above tests are converted to
-# run_make_test() syntax than this line can be removed.
-$makefile = undef;
-
-# -------------------------
-# Make sure that prefix characters apply properly to define/endef values.
-#
-# There's a bit of oddness here if you try to use a variable to hold the
-# prefix character for a define.  Even though something like this:
-#
-#       define foo
-#       echo bar
-#       endef
-#
-#       all: ; $(V)$(foo)
-#
-# (where V=@) can be seen by the user to be obviously different than this:
-#
-#       define foo
-#       $(V)echo bar
-#       endef
-#
-#       all: ; $(foo)
-#
-# and the user thinks it should behave the same as when the "@" is literal
-# instead of in a variable, that can't happen because by the time make
-# expands the variables for the command line and sees it begins with a "@" it
-# can't know anymore whether the prefix character came before the variable
-# reference or was included in the first line of the variable reference.
-
-# TEST #5
-# -------
+# TEST 1: Simple
 
 run_make_test('
-define FOO
-$(V1)echo hello
-$(V2)echo world
-endef
-all: ; @$(FOO)
-', '', 'hello
-world');
-
-# TEST #6
-# -------
-
-run_make_test(undef, 'V1=@ V2=@', 'hello
-world');
+bar = Goodbye
+foo := $(bar)
+bar = ${ugh}
+ugh = Hello
+all: ; @echo $(foo)
+',
+              '', "Goodbye\n");
 
-# TEST #7
-# -------
+# TEST 2: Append to recursive
 
 run_make_test('
-define FOO
-$(V1)echo hello
-$(V2)echo world
-endef
-all: ; $(FOO)
-', 'V1=@', 'hello
-echo world
-world');
+foo = Hello
+ugh = Goodbye
+foo += $(bar)
+bar = ${ugh}
+ugh = Hello
+all: ; @echo $(foo)
+',
+              '', "Hello Hello\n");
 
-# TEST #8
-# -------
+# TEST 3: Append to simple
 
-run_make_test(undef, 'V2=@', 'echo hello
-hello
-world');
+run_make_test('
+foo := Hello
+ugh = Goodbye
+bar = ${ugh}
+foo += $(bar)
+ugh = Hello
+all: ; @echo $(foo)
+',
+              '', "Hello Goodbye\n");
 
-# TEST #9
-# -------
+# TEST 4: Conditional pre-set
 
-run_make_test(undef, 'V1=@ V2=@', 'hello
-world');
+run_make_test('
+foo = Hello
+ugh = Goodbye
+bar = ${ugh}
+foo ?= $(bar)
+ugh = Hello
+all: ; @echo $(foo)
+',
+              '', "Hello\n");
 
-# TEST #10
-# -------
-# Test the basics; a "@" internally to the variable applies to only one line.
-# A "@" before the variable applies to the entire variable.
+# TEST 5: Conditional unset
 
 run_make_test('
-define FOO
-@echo hello
-echo world
-endef
-define BAR
-echo hello
-echo world
-endef
-
-all: foo bar
-foo: ; $(FOO)
-bar: ; @$(BAR)
-', '', 'hello
-echo world
-world
-hello
-world
-');
+ugh = Goodbye
+bar = ${ugh}
+foo ?= $(bar)
+ugh = Hello
+all: ; @echo $(foo)
+',
+              '', "Hello\n");
 
 1;
