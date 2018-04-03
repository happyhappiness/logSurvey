would want to start over, you can recover with
gitlink:git-reset[1].

CONFIGURATION
-------------

merge.summary::
	Whether to include summaries of merged commits in newly
	created merge commit. False by default.

merge.verbosity::
	Controls the amount of output shown by the recursive merge
	strategy.  Level 0 outputs nothing except a final error
	message if conflicts were detected. Level 1 outputs only
	conflicts, 2 outputs conflicts and file changes.  Level 5 and
	above outputs debugging information.  The default is level 2.
	Can be overriden by 'GIT_MERGE_VERBOSITY' environment variable.


HOW MERGE WORKS
---------------
