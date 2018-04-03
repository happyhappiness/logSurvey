 endif::git-format-patch[]
 
 -O<orderfile>::
-	Output the patch in the order specified in the
-	<orderfile>, which has one shell glob pattern per line.
+	Control the order in which files appear in the output.
 	This overrides the `diff.orderFile` configuration variable
 	(see linkgit:git-config[1]).  To cancel `diff.orderFile`,
 	use `-O/dev/null`.
+The output order is determined by the order of glob patterns in
+<orderfile>.
+All files with pathnames that match the first pattern are output
+first, all files with pathnames that match the second pattern (but not
+the first) are output next, and so on.
+All files with pathnames that do not match any pattern are output
+last, as if there was an implicit match-all pattern at the end of the
+file.
+If multiple pathnames have the same rank (they match the same pattern
+but no earlier patterns), their output order relative to each other is
+the normal order.
+<orderfile> is parsed as follows:
+--
+ - Blank lines are ignored, so they can be used as separators for
+   readability.
+
+ - Lines starting with a hash ("`#`") are ignored, so they can be used
+   for comments.  Add a backslash ("`\`") to the beginning of the
+   pattern if it starts with a hash.
+
+ - Each other line contains a single pattern.
+--
+Patterns have the same syntax and semantics as patterns used for
+fnmantch(3) without the FNM_PATHNAME flag, except a pathname also
+matches a pattern if removing any number of the final pathname
+components matches the pattern.  For example, the pattern "`foo*bar`"
+matches "`fooasdfbar`" and "`foo/bar/baz/asdf`" but not "`foobarx`".
 
 ifndef::git-format-patch[]
 -R::