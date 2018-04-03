}
trace_performance(t, "frotz");
------------

Bugs & Caveats
--------------

GIT_TRACE_* environment variables can be used to tell Git to show
trace output to its standard error stream. Git can often spawn a pager
internally to run its subcommand and send its standard output and
standard error to it.

Because GIT_TRACE_PERFORMANCE trace is generated only at the very end
of the program with atexit(), which happens after the pager exits, it
would not work well if you send its log to the standard error output
and let Git spawn the pager at the same time.

As a work around, you can for example use '--no-pager', or set
GIT_TRACE_PERFORMANCE to another file descriptor which is redirected
to stderr, or set GIT_TRACE_PERFORMANCE to a file specified by its
absolute path.

For example instead of the following command which by default may not
print any performance information:

------------
GIT_TRACE_PERFORMANCE=2 git log -1
------------

you may want to use:

------------
GIT_TRACE_PERFORMANCE=2 git --no-pager log -1
------------

or:

------------
GIT_TRACE_PERFORMANCE=3 3>&2 git log -1
------------

or:

------------
GIT_TRACE_PERFORMANCE=/path/to/log/file git log -1
------------