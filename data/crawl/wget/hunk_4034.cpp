 msgid "ignored"
 msgstr "ignorato"
 
-#: src/http.c:857
+#: src/http.c:858
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Attenzione: le wildcard non sono supportate in HTTP.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:872
+#: src/http.c:873
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Il file `%s' è già presente, non lo scarico.\n"
 
-#: src/http.c:978
+#: src/http.c:1015
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Non riesco a scrivere in `%s' (%s).\n"
 
-#: src/http.c:988
+#: src/http.c:1025
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "ERRORE: Redirezione (%d) senza posizione.\n"
 
-#: src/http.c:1011
+#: src/http.c:1048
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s ERRORE %d: %s.\n"
 
-#: src/http.c:1023
+#: src/http.c:1060
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Manca l'header last-modified -- date disattivate.\n"
 
-#: src/http.c:1031
+#: src/http.c:1068
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "Header last-modified non valido -- data ignorata.\n"
 
-#: src/http.c:1064
+#. We can't collapse this down into just one logprintf()
+#. call with a variable set to u->local or the .orig
+#. filename because we have to malloc() space for the
+#. latter, and because there are multiple returns above (a
+#. coding style no-no by many measures, for reasons such as
+#. this) we'd have to remember to free() the string at each
+#. one to avoid a memory leak.
+#: src/http.c:1099
+#, c-format
+msgid ""
+"Server file no newer than local file `%s.orig' -- not retrieving.\n"
+"\n"
+msgstr ""
+
+#: src/http.c:1113
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Il file remoto è più recente, lo scarico.\n"
 
-#: src/http.c:1098
+#: src/http.c:1147
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld]\n"
