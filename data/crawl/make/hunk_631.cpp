 @findex error
 @cindex error, stopping on
 @cindex stopping make
-Generates a fatal error where the message is @var{text}.  Note that the
-error is generated whenever this function is evaluated.  So, if you put
-it inside a command script or on the right side of a recursive variable
-assignment, it won't be evaluated until later.  The @var{text} will be
-expanded before the error is generated.
+Generates a fatal error where the message is @var{text}.  Note that
+the error is generated whenever this function is evaluated.  So, if
+you put it inside a recipe or on the right side of a recursive
+variable assignment, it won't be evaluated until later.  The
+@var{text} will be expanded before the error is generated.
 
 For example,
 
