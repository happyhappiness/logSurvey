 @samp{%} pattern).@*
 @xref{Wildcard Function, ,The Function @code{wildcard}}.
 
+@item $(error @var{text}@dots{})
+
+When this function is evaluated, @code{make} generates a fatal error
+with the message @var{text}.@*
+@xref{Make Control Functions, ,Functions That Control Make}.
+
+@item $(warning @var{text}@dots{})
+
+When this function is evaluated, @code{make} generates a warning with
+the message @var{text}.@*
+@xref{Make Control Functions, ,Functions That Control Make}.
+
 @item $(shell @var{command})
 
 Execute a shell command and return its output.@*
