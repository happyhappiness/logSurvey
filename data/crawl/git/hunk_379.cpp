 	be ignored, no matter if they are already present in the work
 	tree or not.
 
+--no-warn-embedded-repo::
+	By default, `git add` will warn when adding an embedded
+	repository to the index without using `git submodule add` to
+	create an entry in `.gitmodules`. This option will suppress the
+	warning (e.g., if you are manually performing operations on
+	submodules).
+
 --chmod=(+|-)x::
 	Override the executable bit of the added files.  The executable
 	bit is only changed in the index, the files on disk are left
