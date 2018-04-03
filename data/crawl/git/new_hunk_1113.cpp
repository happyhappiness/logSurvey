   script file "git am" internally uses.
   (merge a77598e jc/am-read-author-file later to maint).

 * Lifts calls to exit(2) and die() higher in the callchain in
   sequencer.c files so that more helper functions in it can be used
   by callers that want to handle error conditions themselves.


Also contains various documentation updates and code clean-ups.

