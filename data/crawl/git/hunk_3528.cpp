 If <type> is specified, the raw (though uncompressed) contents of the <object>
 will be returned.
 
-If '--batch' is specified, output of the following form is printed for each
-object specified on stdin:
+BATCH OUTPUT
+------------
+
+If `--batch` or `--batch-check` is given, `cat-file` will read objects
+from stdin, one per line, and print information about them.
+
+Each line is considered as a whole object name, and is parsed as if
+given to linkgit:git-rev-parse[1].
+
+You can specify the information shown for each object by using a custom
+`<format>`. The `<format>` is copied literally to stdout for each
+object, with placeholders of the form `%(atom)` expanded, followed by a
+newline. The available atoms are:
+
+`objectname`::
+	The 40-hex object name of the object.
+
+`objecttype`::
+	The type of of the object (the same as `cat-file -t` reports).
+
+`objectsize`::
+	The size, in bytes, of the object (the same as `cat-file -s`
+	reports).
+
+If no format is specified, the default format is `%(objectname)
+%(objecttype) %(objectsize)`.
+
+If `--batch` is specified, the object information is followed by the
+object contents (consisting of `%(objectsize)` bytes), followed by a
+newline.
+
+For example, `--batch` without a custom format would produce:
 
 ------------
 <sha1> SP <type> SP <size> LF
 <contents> LF
 ------------
 
-If '--batch-check' is specified, output of the following form is printed for
-each object specified on stdin:
+Whereas `--batch-check='%(objectname) %(objecttype)'` would produce:
 
 ------------
-<sha1> SP <type> SP <size> LF
+<sha1> SP <type> LF
 ------------
 
-For both '--batch' and '--batch-check', output of the following form is printed
-for each object specified on stdin that does not exist in the repository:
+If a name is specified on stdin that cannot be resolved to an object in
+the repository, then `cat-file` will ignore any custom format and print:
 
 ------------
 <object> SP missing LF
