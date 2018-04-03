@w{@samp{$(wildcard *.c)}} (as long as at least one @samp{.c} file
exists).@refill

@node Guile Function,  , Shell Function, Functions
@section The @code{guile} Function
@findex guile
@cindex Guile

GNU make may be built with support for GNU Guile as an embedded
extension language.  You can check the @code{.FEATURES} variable for
the word @samp{guile} to determine if your version of GNU make
provides this capability.

GNU Guile implements the Scheme language.  A review of GNU Guile and
the Scheme language and its features is beyond the scope of this
manual: see the documentation for GNU Guile and Scheme.

If GNU Guile is available as an extension language, there will be one
new @code{make} function available: @code{guile}.  The @code{guile}
function takes one argument which is first expanded by @code{make} in
the normal fashion, then passed to the GNU Guile evaluator.  The
result of the evaluator is converted into a string and used as the
expansion of the @code{guile} function in the makefile.

Similarly, there are Guile procedures exposed by @code{make} for use
in Guile scripts.

@menu
* Guile Types::                 Converting Guile types to @code{make} strings.
* Guile Interface::             Invoking @code{make} functions from Guile.
* Guile Example::               Example using Guile in @code{make}.
@end menu

@node Guile Types, Guile Interface, Guile Function, Guile Function
@subsection Conversion of Guile Types
@cindex convert guile types
@cindex guile, conversion of types
@cindex types, conversion of

There is only one ``data type'' in @code{make}: a string.  GNU Guile,
on the other hand, provides a rich variety of different data types.
An important aspect of the interface between @code{make} and GNU Guile
is the conversion of Guile data types into @code{make} strings.

This conversion is relevant in two places: when a makefile invokes the
@code{guile} function to evaluate a Guile expression, the result of
that evaluation must be converted into a make string so it can be
further evaluated by @code{make}.  And secondly, when a Guile script
invokes one of the procedures exported by @code{make} the argument
provided to the procedure must be converted into a string.

The conversion of Guile types into @code{make} strings is as below:

@table @code
@item #f
False is converted into the empty string: in @code{make} conditionals
the empty string is considered false.

@item #t
True is converted to the string @samp{#t}: in @code{make} conditionals
any non-empty string is considered true.

@item symbol
@item number
A symbol or number is converted into the string representation of that
symbol or number.

@item character
A printable character is converted to the same character.

@item string
A string containing only printable characters is converted to the same
string.

@item list
A list is converted recursively according to the above rules.  This
implies that any structured list will be flattened (that is, a result
of @samp{'(a b (c d) e)} will be converted to the @code{make} string
@samp{a b c d e}).

@item other
Any other Guile type results in an error.  In future versions of
@code{make}, other Guile types may be converted.

@end table

The translation of @samp{#f} (to the empty string) and @samp{#t} (to
the non-empty string @samp{#t}) is designed to allow you to use Guile
boolean results directly as @code{make} boolean conditions.  For
example:

@example
$(if $(guile (access? "myfile" R_OK)),$(info myfile exists))
@end example

As a consequence of these conversion rules you must consider the
result of your Guile script, as that result will be converted into a
string and parsed by @code{make}.  If there is no natural result for
the script (that is, the script exists solely for its side-effects),
you should add @samp{#f} as the final expression in order to avoid
syntax errors in your makefile.

@node Guile Interface, Guile Example, Guile Types, Guile Function
@subsection Interfaces from Guile to @code{make}
@cindex make interface to guile
@cindex make procedures in guile

In addition to the @code{guile} function available in makefiles,
@code{make} exposes some procedures for use in your Guile scripts.  At
startup @code{make} creates a new Guile module, @code{gnu make}, and
exports these procedures as public interfaces from that module:

@table @code
@item gmk-expand
This procedure takes a single argument which is converted into a
string.  The string is expanded by @code{make} using normal
@code{make} expansion rules.  The result of the expansion is converted
into a Guile string and provided as the result of the procedure.

@item gmk-eval
This procedure takes a single argument which is converted into a
string.  The string is evaluated by @code{make} as if it were a
makefile.  This is the same capability available via the @code{eval}
function (@pxref{Eval Function}).  The result of the @code{gmk-eval}
procedure is always the empty string.

@item gmk-var
This procedure takes a single argument which is converted into a
string.  The string is assumed to be the name of a @code{make}
variable, which is then expanded.  The expansion is converted into a
string and provided as the result of the procedure.

@end table

@node Guile Example,  , Guile Interface, Guile Function
@subsection Example Using Guile in @code{make}
@cindex Guile example
@cindex example using Guile

Here is a very simple example using GNU Guile to manage writing to a
file.  These Guile procedures simply open a file, allow writing to the
file (one string per line), and close the file.  Note that because we
cannot store complex values such as Guile ports in @code{make}
variables, we'll keep the port as a global variable in the Guile
interpreter.

You can create Guile functions easily using @code{define}/@code{endef}
to create a Guile script, then use the @code{guile} function to
internalize it:

@example
@group
define GUILEIO
;; A simple Guile IO library for GNU make

(define MKPORT #f)

(define (mkopen name mode)
  (set! MKPORT (open-file name mode))
  #f)

(define (mkwrite s)
  (display s MKPORT)
  (newline MKPORT)
  #f)

(define (mkclose)
  (close-port MKPORT)
  #f)

#f
endef

# Internalize the Guile IO functions
$(guile $(GUILEIO))
@end group
@end example

If you have a significant amount of Guile support code, you might
consider keeping it in a different file (e.g., @file{guileio.scm}) and
then loading it in your makefile using the @code{guile} function:

@example
$(guile (load "guileio.scm"))
@end example

An advantage to this method is that when editing @file{guileio.scm},
your editor will understand that this file contains Scheme syntax
rather than makefile syntax.

Now you can use these Guile functions to create files.  Suppose you
need to operate on a very large list, which cannot fit on the command
line, but the utility you're using accepts the list as input as well:

@example
@group
prog: $(PREREQS)
        @@$(guile (mkopen "tmp.out" "w")) \
         $(foreach X,$^,$(guile (mkwrite "$(X)"))) \
         $(guile (mkclose))
        $(LINK) < tmp.out
@end group
@end example

A more comprehensive suite of file manipulation procedures is possible
of course.  You could, for example, maintain multiple output files at
the same time by choosing a symbol for each one and using it as the
key to a hash table, where the value is a port, then returning the
symbol to be stored in a @code{make} variable.


@node Running, Implicit Rules, Functions, Top
@chapter How to Run @code{make}
