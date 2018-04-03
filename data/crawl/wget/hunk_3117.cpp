+2004-02-16  David Fritz  <zeroxdf@att.net>
+
+	* init.c (home_dir): Use aprintf() instead of xmalloc()/sprintf().
+	Under Windows, if $HOME is not defined, use the directory that
+	contains the Wget binary instead of hard-coded `C:\'.
+	(wgetrc_file_name): Under Windows, look for $HOME/.wgetrc then, if
+	not found, look for wget.ini in the directory of the Wget binary.
+
+	* mswindows.c (ws_mypath): Employ slightly more robust methodology.
+	Strip trailing path separator.
+
 2004-02-06  Hrvoje Niksic  <hniksic@xemacs.org>
 
 	* http.c (gethttp): Respect --ignore-length.
