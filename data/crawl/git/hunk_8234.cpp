 	fi
 }
 
+# override die(): this version puts in an extra line break, so that
+# the progress is still visible
+
+die()
+{
+	echo >&2
+	echo "$*" >&2
+	exit 1
+}
+
 # When piped a commit, output a script to set the ident of either
 # "author" or "committer
 
