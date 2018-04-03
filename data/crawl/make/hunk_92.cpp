 #MAKE#: *** No rule to make target 'end', needed by 'baz'.  Stop.\n",
 512);
 
+# Test include of make-able file doesn't show an error (Savannah #102)
+run_make_test(q!
+.PHONY: default
+default:; @echo DONE
+
+inc1:; echo > $@
+include inc1
+include inc2
+inc2:; echo > $@
+!,
+              '', "echo > inc2\necho > inc1\nDONE\n");
+
+rmfiles('inc1', 'inc2');
+
+# Test include of non-make-able file does show an error (Savannah #102)
+run_make_test(q!
+.PHONY: default
+default:; @echo DONE
+
+inc1:; echo > $@
+include inc1
+include inc2
+!,
+              '', "#MAKEFILE#:7: inc2: No such file or directory\n#MAKE#: *** No rule to make target 'inc2'.  Stop.\n", 512);
+
+rmfiles('inc1');
+
+# Include same file multiple times
+
+run_make_test(q!
+default:; @echo DEFAULT
+include inc1
+inc1:; echo > $@
+include inc1
+!,
+              '', "echo > inc1\nDEFAULT\n");
+
+rmfiles('inc1');
+
+# Included file has a prerequisite that fails to build
+
+run_make_test(q!
+default:; @echo DEFAULT
+include inc1
+inc1: foo; echo > $@
+foo:; exit 1
+!,
+              '', "exit 1\n#MAKEFILE#:3: inc1: No such file or directory\n#MAKE#: *** [#MAKEFILE#:5: foo] Error 1\n", 512);
+
+rmfiles('inc1');
+
+# Included file has a prerequisite we don't know how to build
+
+run_make_test(q!
+default:; @echo DEFAULT
+include inc1
+inc1: foo; echo > $@
+!,
+              '', "#MAKEFILE#:3: inc1: No such file or directory\n#MAKE#: *** No rule to make target 'foo', needed by 'inc1'.  Stop.\n", 512);
+
+rmfiles('inc1');
+
+# include a directory
+
 if ($all_tests) {
     # Test that include of a rebuild-able file doesn't show a warning
     # Savannah bug #102
