   followed by strcpy/sprintf have been replaced with a less error
   prone constructs such as xstrfmt.

 * The internal stripspace() function has been moved to where it
   logically belongs to, i.e. strbuf API, and the command line parser
   of "git stripspace" has been updated to use the parse_options API.
   (merge bed4452 tk/stripspace later to maint).


Also contains various documentation updates and code clean-ups.

