@xref{File Name Functions, ,Functions for File Names}.

@item $(error @var{text}@dots{})
When this function is evaluated, @code{make} generates a fatal error
with the message @var{text}.@*
@xref{Make Control Functions, ,Functions That Control Make}.

@item $(warning @var{text}@dots{})
When this function is evaluated, @code{make} generates a warning with
the message @var{text}.@*
@xref{Make Control Functions, ,Functions That Control Make}.

@item $(shell @var{command})
Execute a shell command and return its output.@*
@xref{Shell Function, , The @code{shell} Function}.

@item $(origin @var{variable})
Return a string describing how the @code{make} variable @var{variable} was
defined.@*
@xref{Origin Function, , The @code{origin} Function}.

@item $(flavor @var{variable})
Return a string describing the flavor of the @code{make} variable
@var{variable}.@*
@xref{Flavor Function, , The @code{flavor} Function}.

@item $(foreach @var{var},@var{words},@var{text})
Evaluate @var{text} with @var{var} bound to each word in @var{words},
and concatenate the results.@*
@xref{Foreach Function, ,The @code{foreach} Function}.

@item $(if @var{condition},@var{then-part}[,@var{else-part}])
Evaluate the condition @var{condition}; if it's non-empty substitute
the expansion of the @var{then-part} otherwise substitute the
expansion of the @var{else-part}.@*
@xref{Conditional Functions, ,Functions for Conditionals}.

@item $(or @var{condition1}[,@var{condition2}[,@var{condition3}@dots{}]])
Evaluate each condition @var{conditionN} one at a time; substitute the
first non-empty expansion.  If all expansions are empty, substitute
the empty string.@*
@xref{Conditional Functions, ,Functions for Conditionals}.

@item $(and @var{condition1}[,@var{condition2}[,@var{condition3}@dots{}]])
Evaluate each condition @var{conditionN} one at a time; if any
expansion results in the empty string substitute the empty string.  If
all expansions result in a non-empty string, substitute the expansion
of the last @var{condition}.@*
@xref{Conditional Functions, ,Functions for Conditionals}.

@item $(call @var{var},@var{param},@dots{})
Evaluate the variable @var{var} replacing any references to @code{$(1)},
@code{$(2)} with the first, second, etc.@: @var{param} values.@*
@xref{Call Function, ,The @code{call} Function}.

@item $(eval @var{text})
Evaluate @var{text} then read the results as makefile commands.
Expands to the empty string.@*
@xref{Eval Function, ,The @code{eval} Function}.

@item $(value @var{var})
Evaluates to the contents of the variable @var{var}, with no expansion
performed on it.@*
@xref{Value Function, ,The @code{value} Function}.
