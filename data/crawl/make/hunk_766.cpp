 @samp{%} pattern).@*
 @xref{Wildcard Function, ,The Function @code{wildcard}}.
 
+@item $(realpath @var{names}@dots{})
+For each file name in @var{names}, expand to an absolute name that
+does not contain any @code{.}, @code{..}, nor symlinks.@*
+@xref{File Name Functions, ,Functions for File Names}.
+
+@item $(abspath @var{names}@dots{})
+For each file name in @var{names}, expand to an absolute name that
+does not contain any @code{.} or @code{..} components, but preserves
+symlinks.@*
+@xref{File Name Functions, ,Functions for File Names}.
+
 @item $(error @var{text}@dots{})
 
 When this function is evaluated, @code{make} generates a fatal error
