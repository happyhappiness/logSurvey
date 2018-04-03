+GIT v1.5.6.3 Release Notes
+==========================
+
+Fixes since v1.5.6.2
+--------------------
+
+* Setting GIT_TRACE will report spawning of external process via run_command().
+
+* Bash completion script did not notice '--' marker on the command
+  line and tried the relatively slow "ref completion" even when
+  completing arguments after one.
+
+* Registering a non-empty blob racily and then truncating the working
+  tree file for it confused "racy-git avoidance" logic into thinking
+  that the path is now unchanged.
+
+* "git clone" had a leftover debugging fprintf().
+
+* "git clone -q" was not quiet enough as it used to and gave object count
+  and progress reports.
+
+* "git clone" marked downloaded packfile with .keep; this could be a
+  good thing if the remote side is well packed but otherwise not,
+  especially for a project that is not really big.
+
+* The section that describes attributes related to git-archive were placed
+  in a wrong place in the gitattributes(5) manual page.
+
+* When "git push" tries to remove a remote ref, and corresponding
+  tracking ref is missing, we used to report error (i.e. failure to
+  remove something that does not exist).
+
+* "git mailinfo" (hence "git am") did not handle commit log messages in a
+  MIME multipart mail correctly.
+
+Contains other various documentation fixes.
+
+--
+exec >/var/tmp/1
+O=v1.5.6.2-23-ge965647
+echo O=$(git describe maint)
+git shortlog --no-merges $O..maint
-Documentation/RelNotes-1.5.6.2.txt
+Documentation/RelNotes-1.5.6.3.txt
