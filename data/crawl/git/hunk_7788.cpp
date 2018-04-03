 `filter`
 ^^^^^^^^
 
-A `filter` attribute can be set to a string value.  This names
+A `filter` attribute can be set to a string value that names a
 filter driver specified in the configuration.
 
-A filter driver consists of `clean` command and `smudge`
+A filter driver consists of a `clean` command and a `smudge`
 command, either of which can be left unspecified.  Upon
-checkout, when `smudge` command is specified, the command is fed
-the blob object from its standard input, and its standard output
-is used to update the worktree file.  Similarly, `clean` command
-is used to convert the contents of worktree file upon checkin.
+checkout, when the `smudge` command is specified, the command is
+fed the blob object from its standard input, and its standard
+output is used to update the worktree file.  Similarly, the
+`clean` command is used to convert the contents of worktree file
+upon checkin.
 
-Missing filter driver definition in the config is not an error
+A missing filter driver definition in the config is not an error
 but makes the filter a no-op passthru.
 
 The content filtering is done to massage the content into a
 shape that is more convenient for the platform, filesystem, and
-the user to use.  The keyword here is "more convenient" and not
+the user to use.  The key phrase here is "more convenient" and not
 "turning something unusable into usable".  In other words, the
 intent is that if someone unsets the filter driver definition,
 or does not have the appropriate filter program, the project