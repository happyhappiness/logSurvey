 msgid " (%s bytes)"
 msgstr " (%s byte)"
 
-#: src/http.c:507
+#: src/http.c:508
 msgid "Failed writing HTTP request.\n"
 msgstr "Non riesco a scrivere la richiesta HTTP.\n"
 
-#: src/http.c:511
+#: src/http.c:512
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s richiesta inviata, aspetto la risposta... "
 
-#: src/http.c:550
+#: src/http.c:551
 msgid "End of file while parsing headers.\n"
 msgstr "Raggiunta la fine del file durante l'analisi degli header.\n"
 
-#: src/http.c:561
+#: src/http.c:562
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Errore di lettura degli header (%s).\n"
 
-#: src/http.c:601
+#: src/http.c:602
 msgid "No data received"
 msgstr "Nessun dato ricevuto"
 
-#: src/http.c:603
+#: src/http.c:604
 msgid "Malformed status line"
 msgstr "Riga di stato malformata"
 
-#: src/http.c:608
+#: src/http.c:609
 msgid "(no description)"
 msgstr "(nessuna descrizione)"
 
 #. If we have tried it already, then there is not point
 #. retrying it.
-#: src/http.c:692
+#: src/http.c:693
 msgid "Authorization failed.\n"
 msgstr "Autorizzazione fallita.\n"
 
-#: src/http.c:699
+#: src/http.c:700
 msgid "Unknown authentication scheme.\n"
 msgstr "Schema di autotentificazione sconosciuto.\n"
 
-#: src/http.c:762
+#: src/http.c:783
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Location: %s%s\n"
 
-#: src/http.c:763 src/http.c:788
+#: src/http.c:784 src/http.c:809
 msgid "unspecified"
 msgstr "non specificato"
 
-#: src/http.c:764
+#: src/http.c:785
 msgid " [following]"
 msgstr " [segue]"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:778
+#: src/http.c:799
 msgid "Length: "
 msgstr "Lunghezza: "
 
-#: src/http.c:783
+#: src/http.c:804
 #, c-format
 msgid " (%s to go)"
 msgstr " (%s per finire)"
 
-#: src/http.c:788
+#: src/http.c:809
 msgid "ignored"
 msgstr "ignorato"
 
-#: src/http.c:880
+#: src/http.c:903
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Attenzione: le wildcard non sono supportate in HTTP.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:895
+#: src/http.c:924
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Il file `%s' è già presente, non lo scarico.\n"
 
-#: src/http.c:1048
+#: src/http.c:1083
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Non riesco a scrivere in `%s' (%s).\n"
 
-#: src/http.c:1058
+#: src/http.c:1094
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "ERRORE: Redirezione (%d) senza posizione.\n"
 
-#: src/http.c:1081
+#: src/http.c:1119
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s ERRORE %d: %s.\n"
 
-#: src/http.c:1093
+#: src/http.c:1132
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Manca l'header last-modified -- date disattivate.\n"
 
-#: src/http.c:1101
+#: src/http.c:1140
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "Header last-modified non valido -- data ignorata.\n"
 
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
 msgstr "Il file remoto è più recente, lo scarico.\n"
 
-#: src/http.c:1180
+#: src/http.c:1210
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld]\n"
