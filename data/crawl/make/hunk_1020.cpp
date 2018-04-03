 the target doesn't contain a pattern character (@code{%}).  @xref{Static
 Usage, ,Syntax of Static Pattern Rules}.
 
+@item warning: -jN forced in submake: disabling jobserver mode.
+This warning and the next are generated if @code{make} detects error
+conditions related to parallel processing on systems where
+sub-@code{make}s can communicate (@pxref{Options/Recursion,
+,Communicating Options to a Sub-@code{make}}).  This warning is
+generated if a recursive invocation of a @code{make} process is forced
+to have @samp{-j@var{N}} in its argument list (where @var{N} is greater
+than one).  This could happen, for example, if you set the @code{MAKE}
+environment variable to @samp{make -j2}.  In this case, the
+sub-@code{make} doesn't communicate with other @code{make} processes and
+will simply pretend it has two jobs of its own.
+
+@item warning: jobserver unavailable: using -j1.  Add `+' to parent make rule.
+In order for @code{make} processes to communicate, the parent will pass
+information to the child.  Since this could result in problems if the
+child process isn't actually a @code{make}, the parent will only do this
+if it thinks the child is a @code{make}.  The parent uses the normal
+algorithms to determine this (@pxref{MAKE Variable, ,How the @code{MAKE}
+Variable Works}).  If the makefile is constructed such that the parent
+doesn't know the child is a @code{make} process, then the child will
+receive only part of the information necessary.  In this case, the child
+will generate this warning message and proceed with its build in a
+sequential manner.
+
 @end table
 
 @node Complex Makefile, Concept Index, Make Errors, Top
