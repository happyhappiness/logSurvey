 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:778
+#: src/http.c:799
 msgid "Length: "
 msgstr "L�nge: "
 
-#: src/http.c:783
+#: src/http.c:804
 #, c-format
 msgid " (%s to go)"
 msgstr " (noch %s)"
 
-#: src/http.c:788
+#: src/http.c:809
 msgid "ignored"
 msgstr "�bergangen"
 
-#: src/http.c:880
+#: src/http.c:903
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Warnung: Joker-Zeichen werden bei HTTP nicht unterst�tzt.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:895
+#: src/http.c:924
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Datei �%s� schon vorhanden, kein Hol-Versuch.\n"
 
-#: src/http.c:1048
+#: src/http.c:1083
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Kann nicht nach �%s� schreiben (%s).\n"
 
 # Was meint hier location?
-#: src/http.c:1058
+#: src/http.c:1094
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "FEHLER: Redirektion (%d) ohne Ziel(?).\n"
 
-#: src/http.c:1081
+#: src/http.c:1119
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s FEHLER %d: %s.\n"
 
-#: src/http.c:1093
+#: src/http.c:1132
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "�Last-modified�-Kopfzeile fehlt -- Zeitstempel abgeschaltet.\n"
 
-#: src/http.c:1101
+#: src/http.c:1140
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "�Last-modified�-Kopfzeile ung�ltig -- Zeitstempeln �bergangen.\n"
 
-#. We can't collapse this down into just one logprintf()
-#. call with a variable set to u->local or the .orig
-#. filename because we have to malloc() space for the
-#. latter, and because there are multiple returns above (a
-#. coding style no-no by many measures, for reasons such as
-#. this) we'd have to remember to free() the string at each
-#. one to avoid a memory leak.
-#: src/http.c:1132
-#, c-format
-msgid ""
-"Server file no newer than local file `%s.orig' -- not retrieving.\n"
-"\n"
-msgstr ""
-
-#: src/http.c:1146
+#: src/http.c:1175
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Entfernte Datei ist neuer, Hol-Versuch.\n"
 
-#: src/http.c:1180
+#: src/http.c:1210
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld]\n"
