 @end example
 
 There are problems with this method, however.  First, any error
-detected in a submake is ignored by this rule, so it will continue
+detected in a sub-make is ignored by this rule, so it will continue
 to build the rest of the directories even when one fails.  This can be
 overcome by adding shell commands to note the error and exit, but then
 it will do so even if @code{make} is invoked with the @code{-k}
