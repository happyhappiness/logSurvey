 "Downloaded: %s bytes in %d files\n"
 msgstr ""
 "\n"
-"FINITO --%s--\n"
+"TERMINATO --%s--\n"
 "Scaricati: %s byte in %d file\n"
 
-#: src/main.c:821
+#: src/main.c:920
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
-msgstr "Quota per lo scarico (%s byte) SUPERATA!\n"
+msgstr "Quota di scaricamento (%s byte) SUPERATA!\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:851
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "%s ricevuti, redirigo l'output su `%%s'.\n"
-
-#: src/mswindows.c:123
-#, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"CTRL+Break intercettato, ridirigo l'output su `%s'.\n"
-"L'esecuzione continuerà in background\n"
-"Wget può essere fermato premendo CTRL+ALT+DELETE.\n"
-
-#. parent, no error
-#: src/mswindows.c:140 src/utils.c:451
+#: src/mswindows.c:147
 msgid "Continuing in background.\n"
 msgstr "Continuo in background.\n"
 
-#: src/mswindows.c:142 src/utils.c:453
+#: src/mswindows.c:149 src/utils.c:487
 #, c-format
 msgid "Output will be written to `%s'.\n"
-msgstr "L'output sarà scritto su `%s'.\n"
+msgstr "L'output sarÃ  scritto su \"%s\".\n"
 
-#: src/mswindows.c:232
+#: src/mswindows.c:245
 #, c-format
 msgid "Starting WinHelp %s\n"
-msgstr "Avvio WinHelp %s\n"
+msgstr "Avvio di WinHelp %s\n"
 
-#: src/mswindows.c:259 src/mswindows.c:267
+#: src/mswindows.c:272 src/mswindows.c:279
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
-msgstr "%s: Non riesco a trovare un driver utilizzabile per i socket.\n"
+msgstr "%s: impossibile trovare un driver per i socket utilizzabile.\n"
 
-#: src/netrc.c:367
+#: src/netrc.c:380
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
-msgstr ""
-"%s: %s:%d: attenzione: il token \"%s\" appare prima di un nome di macchina\n"
+msgstr "%s: %s:%d: attenzione: \"%s\" appare prima di un nome di macchina\n"
 
-#: src/netrc.c:398
+# token: termine?
+#: src/netrc.c:411
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
-msgstr "%s: %s:%d:  token \"%s\" sconosciuto\n"
+msgstr "%s: %s:%d: termine \"%s\" sconosciuto\n"
 
-#: src/netrc.c:462
+#: src/netrc.c:475
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Uso: %s NETRC [HOSTNAME]\n"
 
-#: src/netrc.c:472
+#: src/netrc.c:485
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
-msgstr "%s: stat su %s fallita: %s\n"
-
-#: src/recur.c:510
-#, c-format
-msgid "Removing %s since it should be rejected.\n"
-msgstr "Rimuovo %s poiché deve essere rifiutato.\n"
-
-#: src/recur.c:684
-msgid "Loading robots.txt; please ignore errors.\n"
-msgstr "Carico robots.txt; si ignorino eventuali errori.\n"
+msgstr "%s: stat di %s non riuscita: %s\n"
 
-#: src/retr.c:229
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:234
 #, c-format
 msgid ""
 "\n"
-"          [ skipping %dK ]"
+"%*s[ skipping %dK ]"
 msgstr ""
 "\n"
-"         [ salto %dK ]"
+"%*s[ %dK ignorato ]"
+
+# Da man wget:
+# Use --progress=dot to switch to the ``dot'' display.  It traces the
+# retrieval by printing dots on the screen, each dot representing a
+# fixed amount of downloaded data.
+#
+# When using the dotted retrieval, you may also set the style by
+# specifying the type as dot:style.
+#
+#: src/progress.c:401
+#, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "Stile di progresso \"%s\" non valido; lasciato invariato.\n"
+
+#: src/recur.c:378
+#, c-format
+msgid "Removing %s since it should be rejected.\n"
+msgstr "Rimozione di %s poichÃ© deve essere rifiutato.\n"
+
+#: src/res.c:549
+msgid "Loading robots.txt; please ignore errors.\n"
+msgstr "Caricamento di robots.txt; ignorare eventuali errori.\n"
 
-#: src/retr.c:421
-msgid "Could not find proxy host.\n"
-msgstr "Non riesco a trovare il proxy host.\n"
+#: src/retr.c:400
+#, c-format
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "Errore analizzando l'URL del proxy %s: %s.\n"
 
-#: src/retr.c:435
+#: src/retr.c:408
 #, c-format
-msgid "Proxy %s: Must be HTTP.\n"
-msgstr "Proxy %s: Deve essere HTTP.\n"
+msgid "Error in proxy URL %s: Must be HTTP.\n"
+msgstr "Errore nell'URL del proxy %s: deve essere HTTP.\n"
 
-#: src/retr.c:529
-#, fuzzy, c-format
-msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: Redirezione su se stesso.\n"
+#: src/retr.c:493
+#, c-format
+msgid "%d redirections exceeded.\n"
+msgstr "superate %d redirezioni.\n"
 
-#: src/retr.c:623
+#: src/retr.c:617
 msgid ""
 "Giving up.\n"
 "\n"
