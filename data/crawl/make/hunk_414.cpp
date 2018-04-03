 
 By default, there is no load limit.
 
+@menu
+* Parallel Output::             Handling output during parallel execution
+* Parallel Input::              Handling input during parallel execution
+@end menu
+
+@node Parallel Output, Parallel Input, Parallel, Parallel
+@subsection Output During Parallel Execution
+@cindex output during parallel execution
+@cindex parallel execution, output during
+
+When running several recipes in parallel the output from each
+recipe appears as soon as it is generated, with the result that
+messages from different recipes may be interspersed, sometimes even
+appearing on the same line.  This can make reading the output very
+difficult.
+
+@cindex @code{--output-sync}
+@cindex @code{-O}
+To avoid this you can use the @samp{--output-sync} (@samp{-O}) option.
+This option instructs @code{make} to save the output from the commands
+it invokes and print it all once the commands are completed.
+Additionally, if there are multiple recursive @code{make} invocations
+running in parallel, they will communicate so that only one of them is
+generating output at a time.
+
+There are four levels of granularity when synchronizing output,
+specified by giving an argument to the option (e.g.,  @samp{-Ojob} or
+@samp{--output-sync=make}).
+
+@table @code
+@item none
+The is the default: all output is sent directly as it is generated and
+no synchronization is performed.
+
+@item job
+Output from each individual line of the recipe is grouped and printed
+as soon as that line is complete.  If a recipe consists of multiple
+lines, they may be interspersed with lines from other recipes.
+
+@item target
+Output from the entire recipe for each target is grouped and printed
+once the target is complete.  This is the default if the
+@code{--output-sync} or @code{-O} option is given with no argument.
+
+@item make
+Output from each recursive invocation of @code{make} is grouped and
+printed once the recursive invocation is complete.
+
+@end table
+
+Regardless of the mode chosen, the total build time will be the same.
+The only difference is in how the output appears.
+
+The @samp{make} mode provides the most comprehensive grouping,
+allowing output from all targets built by a given makefile to appear
+together.  However, there will be long interludes during the build
+where no output appears while a recursive @code{make} is running,
+followed by a burst of output.  This mode is best for builds being
+performed in the background, where the output will be examined later.
+
+The @samp{job} mode is mainly useful for front-ends that may be
+watching the output of @code{make} and looking for certain generated
+output to determine when recipes are started and completed.
+
+You should be aware that some programs may act differently when they
+determine they're writing output to a terminal versus a file
+(typically described as ``interactive'' vs. ``non-interactive''
+modes).  If your makefile invokes a program like this then using the
+output synchronization options will cause the program to believe it's
+running in ``non-interactive'' mode even when it's writing to the
+terminal.  Of course, invoking @code{make} with output redirected to a
+file will elicit the same behavior.
+
+@node Parallel Input,  , Parallel Output, Parallel
+@subsection Input During Parallel Execution
+@cindex input during parallel execution
+@cindex parallel execution, input during
+@cindex standard input
+
+Two processes cannot both take input from the same device at the same
+time.  To make sure that only one recipe tries to take input from the
+terminal at once, @code{make} will invalidate the standard input
+streams of all but one running recipe.  If another recipe attempts to
+read from standard input it will usually incur a fatal error (a
+@samp{Broken pipe} signal).
+@cindex broken pipe
+
+It is unpredictable which recipe will have a valid standard input stream
+(which will come from the terminal, or wherever you redirect the standard
+input of @code{make}).  The first recipe run will always get it first, and
+the first recipe started after that one finishes will get it next, and so
+on.
+
+We will change how this aspect of @code{make} works if we find a better
+alternative.  In the mean time, you should not rely on any recipe using
+standard input at all if you are using the parallel execution feature; but
+if you are not using this feature, then standard input works normally in
+all recipes.
+
 @node Errors, Interrupts, Parallel, Recipes
 @section Errors in Recipes
 @cindex errors (in recipes)
