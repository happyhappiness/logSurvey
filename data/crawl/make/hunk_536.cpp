 
 @end table
 
+@node Make Control Functions, Shell Function, Flavor Function, Functions
+@section Functions That Control Make
+@cindex functions, for controlling make
+@cindex controlling make
+
+These functions control the way make runs.  Generally, they are used to
+provide information to the user of the makefile or to cause make to stop
+if some sort of environmental error is detected.
+
+@table @code
+@item $(error @var{text}@dots{})
+@findex error
+@cindex error, stopping on
+@cindex stopping make
+Generates a fatal error where the message is @var{text}.  Note that
+the error is generated whenever this function is evaluated.  So, if
+you put it inside a recipe or on the right side of a recursive
+variable assignment, it won't be evaluated until later.  The
+@var{text} will be expanded before the error is generated.
+
+For example,
+
+@example
+ifdef ERROR1
+$(error error is $(ERROR1))
+endif
+@end example
+
+@noindent
+will generate a fatal error during the read of the makefile if the
+@code{make} variable @code{ERROR1} is defined.  Or,
+
+@example
+ERR = $(error found an error!)
+
+.PHONY: err
+err: ; $(ERR)
+@end example
+
+@noindent
+will generate a fatal error while @code{make} is running, if the
+@code{err} target is invoked.
+
+@item $(warning @var{text}@dots{})
+@findex warning
+@cindex warnings, printing
+@cindex printing user warnings
+This function works similarly to the @code{error} function, above,
+except that @code{make} doesn't exit.  Instead, @var{text} is expanded
+and the resulting message is displayed, but processing of the makefile
+continues.
 
-@node Shell Function, Make Control Functions, Flavor Function, Functions
+The result of the expansion of this function is the empty string.
+
+@item $(info @var{text}@dots{})
+@findex info
+@cindex printing messages
+This function does nothing more than print its (expanded) argument(s)
+to standard output.  No makefile name or line number is added.  The
+result of the expansion of this function is the empty string.
+@end table
+
+@node Shell Function, Guile Function, Make Control Functions, Functions
 @section The @code{shell} Function
 @findex shell
 @cindex command expansion
