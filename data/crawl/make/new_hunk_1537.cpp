@code{make}, except that the modification time is changed only in the
imagination of @code{make}.
@xref{Instead of Execution, ,Instead of Executing the Commands}.

@item --warn-undefined-variables
@cindex @code{--warn-undefined-variables}
@cindex variables, warning for undefined
@cindex undefined variables, warning message
Issue a warning message whenever @code{make} sees a reference to an
undefined variable.  This can be helpful when you are trying to debug
makefiles which use variables in complex ways.
@end table

@node Implicit Rules, Archives, Running, Top
