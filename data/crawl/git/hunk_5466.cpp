 All of the fixes in v1.6.5.X maintenance series are included in this
 release, unless otherwise noted.
 
- * Enumeration of available merge strategies iterated over the list of
-   commands in a wrong way, sometimes producing an incorrect result.
-   Will backport by merging ed87465 (builtin-merge.c: call
-   exclude_cmds() correctly., 2009-11-25).
-
- * "git format-patch revisions... -- path" issued an incorrect error
-   message that suggested to use "--" on the command line when path
-   does not exist in the current work tree (it is a separate matter if
-   it makes sense to limit format-patch with pathspecs like that
-   without using the --full-diff option).  Will backport by merging
-   7e93d3b (format-patch: add test for parsing of "--", 2009-11-26).
-
- * "git shortlog" did not honor the "encoding" header embedded in the
-   commit object like "git log" did.  Will backport by merging 79f7ca0
-   (shortlog: respect commit encoding, 2009-11-25).
-
 ---
 exec >/var/tmp/1
 echo O=$(git describe master)