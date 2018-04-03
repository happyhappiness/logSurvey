 choices like this to affect the functioning of makefiles.
 @xref{Environment}.
 
-@node Errors, Interrupts, Execution, Commands
+@node Parallel, Errors, Execution, Commands
+@section Parallel Execution
+
+@cindex parallel execution
+@cindex execution in parallel
+@cindex job slots
+GNU @code{make} knows how to execute several commands at once.
+Normally, @code{make} will execute only one command at a time, waiting
+for it to finish before executing the next.  However, the @samp{-j}
+option tells @code{make} to execute many commands simultaneously.@refill
+
+If the @samp{-j} option is followed by an integer, this is the number of
+commands to execute at once; this is called the number of @dfn{job slots}.
+If there is nothing looking like an integer after the @samp{-j} option,
+there is no limit on the number of job slots.  The default number of job
+slots is one, which means serial execution (one thing at a time).
+
+One unpleasant consequence of running several commands simultaneously is
+that output from all of the commands comes when the commands send it, so
+messages from different commands may be interspersed.
+
+Another problem is that two processes cannot both take input from the same
+device; so to make sure that only one command tries to take input from the
+terminal at once, @code{make} will invalidate the standard input streams of
+all but one running command.  This means that attempting to read from
+standard input, for most child processes if there are several, will usually
+be a fatal error (a @samp{Broken pipe} signal).
+
+It is unpredictable which command will have a valid standard input stream
+(which will come from the terminal, or wherever you redirect the standard
+input of @code{make}).  The first command run will always get it first, and
+the first command started after that one finishes will get it next, and so
+on.
+
+We will change how this aspect of @code{make} works if we find a better
+alternative.  In the mean time, you should not rely on any command using
+standard input at all if you are using the parallel execution feature; but
+if you are not using this feature, then standard input works normally in
+all commands.
+
+If a command fails (is killed by a signal or exits with a nonzero
+status), and errors are not ignored for that command (@pxref{Errors}),
+the remaining command lines to remake the same target will not be run.
+If a command fails and the @samp{-k} option was not given
+(@pxref{Options}), @code{make} aborts execution.  If make terminates for
+any reason (including a signal) with child processes running, it waits
+for them to finish before actually exiting.@refill
+
+When the system is heavily loaded, you will probably want to run fewer jobs
+than when it is lightly loaded.  You can use the @samp{-l} option to tell
+@code{make} to limit the number of jobs to run at once, based on the load
+average.  The @samp{-l} option is followed by a floating-point number.  For
+example,
+
+@example
+-l 2.5
+@end example
+
+@noindent
+will not let @code{make} start more than one job if the load average is
+above 2.5.  The @samp{-l} option with no following number removes the
+load limit, if one was given with a previous @samp{-l} option.@refill
+
+More precisely, when @code{make} goes to start up a job, and it already has
+at least one job running, it checks the current load average; if it is not
+lower than the limit given with @samp{-l}, @code{make} waits until the load
+average goes below that limit, or until all the other jobs finish.
+
+By default, there is no load limit.
+
+@node Errors, Interrupts, Parallel, Commands
 @section Errors in Commands
 
 @cindex error (in commands)
