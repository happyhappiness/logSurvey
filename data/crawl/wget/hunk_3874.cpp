 "Content-Type: text/plain; charset=iso-8859-2\n"
 "Content-Transfer-Encoding: 8bit\n"
 
+#: src/ftp-ls.c:698 src/ftp-ls.c:700
+#, c-format
+msgid "Index of /%s on %s:%d"
+msgstr "Indeks direktorija /%s na %s:%d"
+
+#: src/ftp-ls.c:722
+msgid "time unknown       "
+msgstr "nepoznato vrijeme    "
+
+#: src/ftp-ls.c:726
+msgid "File        "
+msgstr "Datoteka    "
+
+#: src/ftp-ls.c:729
+msgid "Directory   "
+msgstr "Direktorij  "
+
+#: src/ftp-ls.c:732
+msgid "Link        "
+msgstr "Link        "
+
+#: src/ftp-ls.c:735
+msgid "Not sure    "
+msgstr "Ne znam     "
+
+#: src/ftp-ls.c:753
+#, c-format
+msgid " (%s bytes)"
+msgstr " (%s bajtova)"
+
 #. Login to the server:
 #. First: Establish the control connection.
-#: src/ftp.c:147 src/http.c:348
+#: src/ftp.c:152 src/http.c:582
 #, c-format
 msgid "Connecting to %s:%hu... "
 msgstr "Spajam se na %s:%hu... "
 
-#: src/ftp.c:169 src/ftp.c:411 src/http.c:365
+#: src/ftp.c:174 src/ftp.c:520 src/http.c:599
 #, c-format
 msgid "Connection to %s:%hu refused.\n"
 msgstr "%s:%hu odbija vezu.\n"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:190 src/http.c:376
+#: src/ftp.c:195 src/http.c:610
 msgid "connected!\n"
 msgstr "spojen!\n"
 
-#: src/ftp.c:191
+#: src/ftp.c:196
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Logiram se kao %s ... "
 
-#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
-#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
+#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:289 src/ftp.c:314 src/ftp.c:410
+#: src/ftp.c:462 src/ftp.c:556 src/ftp.c:629 src/ftp.c:677 src/ftp.c:725
 msgid "Error in server response, closing control connection.\n"
 msgstr "Gre¹ka u odgovoru, zatvaram kontrolnu vezu.\n"
 
-#: src/ftp.c:208
+#: src/ftp.c:213
 msgid "Error in server greeting.\n"
 msgstr "Gre¹ka u poslu¾iteljevom pozdravu.\n"
 
-#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
-#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
+#: src/ftp.c:221 src/ftp.c:323 src/ftp.c:419 src/ftp.c:471 src/ftp.c:566
+#: src/ftp.c:639 src/ftp.c:687 src/ftp.c:735
 msgid "Write failed, closing control connection.\n"
 msgstr "Write nije uspio, zatvaram kontrolnu vezu.\n"
 
-#: src/ftp.c:223
+#: src/ftp.c:228
 msgid "The server refuses login.\n"
 msgstr "Poslu¾itelj odbija prijavu.\n"
 
-#: src/ftp.c:230
+#: src/ftp.c:235
 msgid "Login incorrect.\n"
 msgstr "Pogre¹na prijava.\n"
 
-#: src/ftp.c:237
+#: src/ftp.c:242
 msgid "Logged in!\n"
 msgstr "Ulogiran!\n"
 
-#: src/ftp.c:270
+#: src/ftp.c:267
+msgid "Server error, can't determine system type.\n"
+msgstr "Gre¹ka na serveru, ne mogu utvrditi vrstu sustava."
+
+#: src/ftp.c:277 src/ftp.c:541 src/ftp.c:613 src/ftp.c:657
+msgid "done.    "
+msgstr "gotovo.  "
+
+#: src/ftp.c:303 src/ftp.c:440 src/ftp.c:708 src/ftp.c:756 src/url.c:1432
+msgid "done.\n"
+msgstr "gotovo.\n"
+
+#: src/ftp.c:331
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Nepoznat tip `%c', zatvaram kontrolnu vezu.\n"
 
-#: src/ftp.c:283
+#: src/ftp.c:344
 msgid "done.  "
 msgstr "gotovo."
 
-#: src/ftp.c:289
+#: src/ftp.c:350
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD ne treba.\n"
 
-#: src/ftp.c:317
+#: src/ftp.c:426
 #, c-format
 msgid ""
 "No such directory `%s'.\n"
 "\n"
 msgstr "Nema direktorija `%s'.\n"
 
-#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1678
-msgid "done.\n"
-msgstr "gotovo.\n"
-
 #. do not CWD
-#: src/ftp.c:335
+#: src/ftp.c:444
 msgid "==> CWD not required.\n"
 msgstr "==> CWD se ne tra¾i.\n"
 
-#: src/ftp.c:369
+#: src/ftp.c:478
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Ne mogu otpoèeti PASV prijenos.\n"
 
-#: src/ftp.c:373
+#: src/ftp.c:482
 msgid "Cannot parse PASV response.\n"
 msgstr "Ne mogu raspoznati PASV odgovor.\n"
 
-#: src/ftp.c:387
+#: src/ftp.c:496
 #, c-format
 msgid "Will try connecting to %s:%hu.\n"
 msgstr "Poku¹at æu se spojiti na %s:%hu.\n"
 
-#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
-msgid "done.    "
-msgstr "gotovo.  "
-
-#: src/ftp.c:474
+#: src/ftp.c:583
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Gre¹ka u bindu (%s).\n"
 
-#: src/ftp.c:490
+#: src/ftp.c:599
 msgid "Invalid PORT.\n"
 msgstr "Pogre¹an PORT.\n"
 
-#: src/ftp.c:537
+#: src/ftp.c:646
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
