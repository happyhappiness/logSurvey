 "ZAKOÑCZONO --%s--\n"
 "¦ci±gniêto: %s bajtów w %d plikach\n"
 
-#: src/main.c:821
-#, c-format
-msgid "Download quota (%s bytes) EXCEEDED!\n"
-msgstr "Quota na ¶ci±ganie (%s bajtów) PRZEKROCZONA!\n"
-
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
 #: src/main.c:851
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "%s przes³ano, przekierowywanie wyj¶cia do `%%s'.\n"
-
-#: src/mswindows.c:123
 #, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"Przes³ano CTRL+Break, przekierowywanie wyj¶cia do `%s'.\n"
-"Wykonanie kontynuowane w tle.\n"
-"Mo¿na zatrzymaæ Wget'a poprzez wci¶niêcie CTRL+ALT+DELETE.\n"
+msgid "Download quota (%s bytes) EXCEEDED!\n"
+msgstr "Ograniczenie na ilo¶æ ¶ci±ganych danych (%s bajtów) PRZEKROCZONE!\n"
 
-#. parent, no error
-#: src/mswindows.c:140 src/utils.c:451
+#: src/mswindows.c:120
 msgid "Continuing in background.\n"
-msgstr "Kontunuacja w tle.\n"
+msgstr "Kontynuacja w tle.\n"
 
-#: src/mswindows.c:142 src/utils.c:453
+#: src/mswindows.c:122 src/utils.c:457
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "Wyj¶cie zostanie zapisane do `%s'.\n"
 
-#: src/mswindows.c:232
+#: src/mswindows.c:202
 #, c-format
 msgid "Starting WinHelp %s\n"
-msgstr "Startowanie WinHelp %s\n"
+msgstr "Uruchamianie WinHelp %s\n"
 
-#: src/mswindows.c:259 src/mswindows.c:267
+#: src/mswindows.c:229 src/mswindows.c:236
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
-msgstr "%s: Nie mog¿na znale¶æ u¿ytecznego sterownika do gniazd (socket).\n"
+msgstr "%s: Nie mo¿na znale¼æ daj±cego siê u¿yæ sterownika do gniazd (socket).\n"
 
-#: src/netrc.c:367
+#: src/netrc.c:365
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
-msgstr ""
-"%s: %s:%d: ostrze¿enie: \"%s\" znaki (token) pojawiaj± sie przed nazw± "
-"maszyny\n"
+msgstr "%s: %s:%d: ostrze¿enie: element (token) \"%s\" pojawia siê przed nazw± komputera\n"
 
-#: src/netrc.c:398
+#: src/netrc.c:396
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
-msgstr "%s: %s:%d: nieznany znak (token) \"%s\"\n"
+msgstr "%s: %s:%d: nieznany element (token) \"%s\"\n"
 
-#: src/netrc.c:462
+#: src/netrc.c:460
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "U¿ycie: %s NETRC [NAZWA_HOSTA]\n"
 
-#: src/netrc.c:472
+#: src/netrc.c:470
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
-msgstr "%s: nie mo¿na zlokalizowaæ %s: %s\n"
+msgstr "%s: nie mo¿na pobraæ informacji o %s: %s\n"
+
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:224
+#, c-format
+msgid ""
+"\n"
+"%*s[ skipping %dK ]"
+msgstr ""
+"\n"
+"%*s[ pomijanie %dK ]"
+
+#: src/progress.c:391
+#, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "Nieprawid³owa specyfikacja stylu wizualizacji `%s'; pozostawiono bez zmian.\n"
 
-#: src/recur.c:510
+#: src/recur.c:350
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Usuwanie %s poniewa¿ powinien byæ odrzucony.\n"
 
-#: src/recur.c:684
+#: src/recur.c:935
+#, c-format
+msgid "Converted %d files in %.2f seconds.\n"
+msgstr "Przekonwertowano %d plików w %.2f sekund.\n"
+
+#: src/res.c:540
 msgid "Loading robots.txt; please ignore errors.\n"
-msgstr "£adowanie robots.txt; proszê zignorowaæ b³êdy.\n"
+msgstr "Wczytywanie robots.txt; proszê zignorowaæ b³êdy.\n"
 
-#: src/retr.c:229
+#: src/retr.c:363
+msgid "Could not find proxy host.\n"
+msgstr "Nie mo¿na znale¼æ serwera proxy.\n"
+
+#: src/retr.c:375
 #, c-format
-msgid ""
-"\n"
-"          [ skipping %dK ]"
-msgstr ""
-"\n"
-"          [ pomijanie %dK ]"
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "B³±d podczas analizy sk³adni URL-a proxy %s: %s.\n"
 
-#: src/retr.c:421
-msgid "Could not find proxy host.\n"
-msgstr "Nie mo¿na znale¶æ serwera proxy.\n"
+#: src/retr.c:384
+#, c-format
+msgid "Error in proxy URL %s: Must be HTTP.\n"
+msgstr "B³±d w URL-u proxy %s: Musi byæ HTTP.\n"
 
-#: src/retr.c:435
+#: src/retr.c:476
 #, c-format
-msgid "Proxy %s: Must be HTTP.\n"
-msgstr "Proxy %s: Musi byæ HTTP.\n"
+msgid "%d redirections exceeded.\n"
+msgstr "przekroczono %d przekierowañ.\n"
 
-#: src/retr.c:529
+#: src/retr.c:491
 #, c-format
 msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: Wykryto cykl przekierowañ.\n"
+msgstr "%s: Wykryto pêtlê przekierowañ.\n"
 
-#: src/retr.c:623
+#: src/retr.c:608
 msgid ""
 "Giving up.\n"
 "\n"
 msgstr ""
-"Poddawanie siê.\n"
+"Program nie mo¿e sobie poradziæ.\n"
 "\n"
 
-#: src/retr.c:623
+#: src/retr.c:608
 msgid ""
 "Retrying.\n"
 "\n"
