 msgid "Error closing %s: %s\n"
 msgstr "Gre�ka pri zatvaranju `%s': %s\n"
 
-#: src/ftp-ls.c:836
+#: src/ftp-ls.c:1065
 msgid "Unsupported listing type, trying Unix listing parser.\n"
 msgstr ""
 "Nepodr�ana vrsta ispisa, poku�avat �u s razlu�iteljem Unixovog ispisa.\n"
 
-#: src/ftp-ls.c:882 src/ftp-ls.c:884
+#: src/ftp-ls.c:1116 src/ftp-ls.c:1118
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Indeks direktorija /%s na %s:%d"
 
-#: src/ftp-ls.c:907
+#: src/ftp-ls.c:1143
 #, c-format
 msgid "time unknown       "
 msgstr "nepoznato vrijeme    "
 
-#: src/ftp-ls.c:911
+#: src/ftp-ls.c:1147
 #, c-format
 msgid "File        "
 msgstr "Spis        "
 
-#: src/ftp-ls.c:914
+#: src/ftp-ls.c:1150
 #, c-format
 msgid "Directory   "
 msgstr "Direktorij  "
 
-#: src/ftp-ls.c:917
+#: src/ftp-ls.c:1153
 #, c-format
 msgid "Link        "
 msgstr "Link        "
 
-#: src/ftp-ls.c:920
+#: src/ftp-ls.c:1156
 #, c-format
 msgid "Not sure    "
 msgstr "Ne znam     "
 
-#: src/ftp-ls.c:938
+#: src/ftp-ls.c:1179
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s bajtova)"
 
-#: src/ftp.c:214
+#: src/ftp.c:220
 #, c-format
 msgid "Length: %s"
 msgstr "Duljina: %s"
 
-#: src/ftp.c:220 src/http.c:2199
+#: src/ftp.c:226 src/http.c:2248
 #, c-format
 msgid ", %s (%s) remaining"
 msgstr ", %s (%s) preostaje"
 
-#: src/ftp.c:224 src/http.c:2203
+#: src/ftp.c:230 src/http.c:2252
 #, c-format
 msgid ", %s remaining"
 msgstr ", %s preostaje"
 
-#: src/ftp.c:227
+#: src/ftp.c:233
 msgid " (unauthoritative)\n"
 msgstr " (nepouzdano)\n"
 
-#: src/ftp.c:305
+#: src/ftp.c:311
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Prijavljujem se kao %s ... "
 
-#: src/ftp.c:319 src/ftp.c:365 src/ftp.c:394 src/ftp.c:446 src/ftp.c:559
-#: src/ftp.c:606 src/ftp.c:635 src/ftp.c:692 src/ftp.c:753 src/ftp.c:839
-#: src/ftp.c:886
+#: src/ftp.c:325 src/ftp.c:371 src/ftp.c:400 src/ftp.c:465 src/ftp.c:695
+#: src/ftp.c:748 src/ftp.c:777 src/ftp.c:834 src/ftp.c:895 src/ftp.c:987
+#: src/ftp.c:1034
 msgid "Error in server response, closing control connection.\n"
 msgstr "Gre�ka u odgovoru, zatvaram kontrolnu vezu.\n"
 
-#: src/ftp.c:326
+#: src/ftp.c:332
 msgid "Error in server greeting.\n"
 msgstr "Gre�ka u poslu�iteljevom pozdravu.\n"
 
-#: src/ftp.c:333 src/ftp.c:454 src/ftp.c:567 src/ftp.c:643 src/ftp.c:702
-#: src/ftp.c:763 src/ftp.c:849 src/ftp.c:896
+#: src/ftp.c:339 src/ftp.c:473 src/ftp.c:703 src/ftp.c:785 src/ftp.c:844
+#: src/ftp.c:905 src/ftp.c:997 src/ftp.c:1044
 msgid "Write failed, closing control connection.\n"
 msgstr "Pisanje je zakazalo, zatvaram kontrolnu vezu.\n"
 
-#: src/ftp.c:339
+#: src/ftp.c:345
 msgid "The server refuses login.\n"
 msgstr "Poslu�itelj odbija prijavu.\n"
 
-#: src/ftp.c:345
+#: src/ftp.c:351
 msgid "Login incorrect.\n"
 msgstr "Pogre�na prijava.\n"
 
-#: src/ftp.c:351
+#: src/ftp.c:357
 msgid "Logged in!\n"
 msgstr "Ulogiran!\n"
 
-#: src/ftp.c:373
+#: src/ftp.c:379
 msgid "Server error, can't determine system type.\n"
 msgstr "Gre�ka na serveru, ne mogu utvrditi vrstu sustava.\n"
 
-#: src/ftp.c:382 src/ftp.c:679 src/ftp.c:736 src/ftp.c:779
+#: src/ftp.c:388 src/ftp.c:821 src/ftp.c:878 src/ftp.c:921
 msgid "done.    "
 msgstr "gotovo.  "
 
-#: src/ftp.c:434 src/ftp.c:584 src/ftp.c:618 src/ftp.c:869 src/ftp.c:915
+#: src/ftp.c:453 src/ftp.c:720 src/ftp.c:760 src/ftp.c:1017 src/ftp.c:1063
 msgid "done.\n"
 msgstr "gotovo.\n"
 
-#: src/ftp.c:461
+#: src/ftp.c:480
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Nepoznat tip `%c', zatvaram kontrolnu vezu.\n"
 
-#: src/ftp.c:473
+#: src/ftp.c:492
 msgid "done.  "
 msgstr "gotovo."
 
-#: src/ftp.c:479
+#: src/ftp.c:498
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD nepotreban.\n"
 
-#: src/ftp.c:573
+#: src/ftp.c:709
 #, fuzzy, c-format
 msgid ""
 "No such directory %s.\n"
 "\n"
 msgstr "Ne postoji direktorij `%s'.\n"
 
-#: src/ftp.c:588
+#: src/ftp.c:730
 msgid "==> CWD not required.\n"
 msgstr "==> CWD se ne tra�i.\n"
 
-#: src/ftp.c:649
+#: src/ftp.c:791
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Ne mogu otpo�eti PASV prijenos.\n"
 
-#: src/ftp.c:653
+#: src/ftp.c:795
 msgid "Cannot parse PASV response.\n"
 msgstr "Ne mogu ra��laniti PASV odgovor.\n"
 
-#: src/ftp.c:670
+#: src/ftp.c:812
 #, c-format
 msgid "couldn't connect to %s port %d: %s\n"
 msgstr "nemogu�e spajanje na %s, port %d: %s\n"
 
-#: src/ftp.c:718
+#: src/ftp.c:860
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Gre�ka pri bindu (%s).\n"
 
-#: src/ftp.c:724
+#: src/ftp.c:866
 msgid "Invalid PORT.\n"
 msgstr "Neispravan PORT.\n"
 
-#: src/ftp.c:770
+#: src/ftp.c:912
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
