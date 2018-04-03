 @end group
 @end example
 
+Another example of the usefulness of phony targets is in conjunction
+with recursive invocations of @code{make}.  In this case the makefile
+will often contain a variable which lists a number of subdirectories to
+be built.  One way to handle this is with one rule whose command is a
+shell loop over the subdirectories, like this:
+
+@example
+@group
+SUBDIRS = foo bar baz
+
+subdirs:
+        for dir in $(SUBDIRS); do \
+          $(MAKE) -C $$dir; \
+        done
+@end group
+@end example
+
+There are a few of problems with this method, however.  First, any error
+detected in a submake is not noted by this rule, so it will continue to
+build the rest of the directories even when one fails.  This can be
+overcome by adding shell commands to note the error and exit, but then
+it will do so even if @code{make} is invoked with the @code{-k} option,
+which is unfortunate.  Second, and perhaps more importantly, you cannot
+take advantage of the parallel build capabilities of make using this
+method, since there is only one rule.
+
+By declaring the subdirectories as phony targets (you must do this as
+the subdirectory obviously always exists; otherwise it won't be built)
+you can remove these problems:
+
+@example
+@group
+SUBDIRS = foo bar baz
+
+.PHONY: subdirs $(SUBDIRS)
+
+subdirs: $(SUBDIRS)
+
+$(SUBDIRS):
+        $(MAKE) -C $@
+
+foo: baz
+@end group
+@end example
+
+Here we've also declared that the @file{foo} subdirectory cannot be
+built until after the @file{baz} subdirectory is complete; this kind of
+relationship declaration is particularly important when attempting
+parallel builds.
+
 A phony target should not be a prerequisite of a real target file; if it
 is, its commands are run every time @code{make} goes to update that
 file.  As long as a phony target is never a prerequisite of a real
