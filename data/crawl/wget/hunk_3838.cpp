 "Content-Type: text/plain; charset=iso-8859-1\n"
 "Content-Transfer-Encoding: 8-bit\n"
 
+#: src/ftp-ls.c:698 src/ftp-ls.c:700
+#, c-format
+msgid "Index of /%s on %s:%d"
+msgstr "Index van /%s op %s:%d"
+
+#: src/ftp-ls.c:722
+msgid "time unknown       "
+msgstr "tijd onbekend     "
+
+#: src/ftp-ls.c:726
+msgid "File        "
+msgstr "Bestand     "
+
+#: src/ftp-ls.c:729
+msgid "Directory   "
+msgstr "Map         "
+
+#: src/ftp-ls.c:732
+msgid "Link        "
+msgstr "Koppeling   "
+
+#: src/ftp-ls.c:735
+msgid "Not sure    "
+msgstr "Niet zeker  "
+
+#: src/ftp-ls.c:753
+#, c-format
+msgid " (%s bytes)"
+msgstr " (%s Bytes)"
+
 #. Login to the server:
 #. First: Establish the control connection.
-#: src/ftp.c:147 src/http.c:346
+#: src/ftp.c:152 src/http.c:582
 #, c-format
 msgid "Connecting to %s:%hu... "
 msgstr "Verbinden met %s:%hu... "
 
-#: src/ftp.c:169 src/ftp.c:411 src/http.c:363
+#: src/ftp.c:174 src/ftp.c:520 src/http.c:599
 #, c-format
 msgid "Connection to %s:%hu refused.\n"
 msgstr "Verbinding met %s:%hu geweigerd.\n"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:190 src/http.c:374
+#: src/ftp.c:195 src/http.c:610
 msgid "connected!\n"
 msgstr "verbonden!\n"
 
-#: src/ftp.c:191
+#: src/ftp.c:196
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Inloggen als %s ... "
 
 # Ist das gemeint?
-#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
-#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
+#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:289 src/ftp.c:314 src/ftp.c:410
+#: src/ftp.c:462 src/ftp.c:556 src/ftp.c:629 src/ftp.c:677 src/ftp.c:725
 msgid "Error in server response, closing control connection.\n"
 msgstr "Fout in antwoord server, verbreek besturingsverbinding.\n"
 
-#: src/ftp.c:208
+#: src/ftp.c:213
 msgid "Error in server greeting.\n"
 msgstr "Fout in servers groet.\n"
 
-#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
-#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
+#: src/ftp.c:221 src/ftp.c:323 src/ftp.c:419 src/ftp.c:471 src/ftp.c:566
+#: src/ftp.c:639 src/ftp.c:687 src/ftp.c:735
 msgid "Write failed, closing control connection.\n"
 msgstr "Schrijf fout, verbreek besturingsverbinding.\n"
 
-#: src/ftp.c:223
+#: src/ftp.c:228
 msgid "The server refuses login.\n"
 msgstr "De server weigert de login.\n"
 
-#: src/ftp.c:230
+#: src/ftp.c:235
 msgid "Login incorrect.\n"
 msgstr "Login onjuist.\n"
 
-#: src/ftp.c:237
+#: src/ftp.c:242
 msgid "Logged in!\n"
 msgstr "Ingelogt!\n"
 
-#: src/ftp.c:270
+#: src/ftp.c:267
+msgid "Server error, can't determine system type.\n"
+msgstr ""
+
+#: src/ftp.c:277 src/ftp.c:541 src/ftp.c:613 src/ftp.c:657
+msgid "done.    "
+msgstr "gereed.    "
+
+#: src/ftp.c:303 src/ftp.c:440 src/ftp.c:708 src/ftp.c:756 src/url.c:1432
+msgid "done.\n"
+msgstr "gereed.\n"
+
+#: src/ftp.c:331
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Onbekend type `%c', verbreek besturingsverbinding.\n"
 
-#: src/ftp.c:283
+#: src/ftp.c:344
 msgid "done.  "
 msgstr "gereed.  "
 
-#: src/ftp.c:289
-msgid "=> CWD not needed.\n"
+#: src/ftp.c:350
+#, fuzzy
+msgid "==> CWD not needed.\n"
 msgstr "=> CWD niet nodig.\n"
 
-#: src/ftp.c:317
+#: src/ftp.c:426
 #, c-format
-msgid "No such directory `%s'.\n\n"
-msgstr "Onbekende directory `%s'.\n\n"
-
-#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1426
-msgid "done.\n"
-msgstr "gereed.\n"
+msgid ""
+"No such directory `%s'.\n"
+"\n"
+msgstr ""
+"Onbekende directory `%s'.\n"
+"\n"
 
 #. do not CWD
-#: src/ftp.c:335
-msgid "=> CWD not required.\n"
+#: src/ftp.c:444
+#, fuzzy
+msgid "==> CWD not required.\n"
 msgstr "=> CWD niet noodzakelijk.\n"
 
-#: src/ftp.c:369
+#: src/ftp.c:478
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Kan PASV-overdracht niet beginnen.\n"
 
-#: src/ftp.c:373
+#: src/ftp.c:482
 msgid "Cannot parse PASV response.\n"
 msgstr "Kan PASV-antwoord niet ontleden.\n"
 
-#: src/ftp.c:387
+#: src/ftp.c:496
 #, c-format
 msgid "Will try connecting to %s:%hu.\n"
 msgstr "Tracht verbinding met %s:%hu te herstellen.\n"
 
-#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
-msgid "done.    "
-msgstr "gereed.    "
-
-#: src/ftp.c:474
+#: src/ftp.c:583
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Bind fout (%s).\n"
 
-#: src/ftp.c:490
+#: src/ftp.c:599
 msgid "Invalid PORT.\n"
 msgstr "Ongeldige POORT.\n"
 
-#: src/ftp.c:537
-msgid "\nREST failed, starting from scratch.\n"
-msgstr "\nREST gefaald, begin opnieuw.\n"
+#: src/ftp.c:646
+msgid ""
+"\n"
+"REST failed, starting from scratch.\n"
+msgstr ""
+"\n"
+"REST gefaald, begin opnieuw.\n"
 
-#: src/ftp.c:586
+#: src/ftp.c:695
 #, c-format
-msgid "No such file `%s'.\n\n"
-msgstr "Onbekend bestand `%s'.\n\n"
+msgid ""
+"No such file `%s'.\n"
+"\n"
+msgstr ""
+"Onbekend bestand `%s'.\n"
+"\n"
 
-#: src/ftp.c:634
+#: src/ftp.c:743
 #, c-format
-msgid "No such file or directory `%s'.\n\n"
-msgstr "Onbekend bestand of directory `%s'.\n\n"
+msgid ""
+"No such file or directory `%s'.\n"
+"\n"
+msgstr ""
+"Onbekend bestand of directory `%s'.\n"
+"\n"
 
-#: src/ftp.c:692 src/ftp.c:699
+#: src/ftp.c:819 src/ftp.c:826
 #, c-format
 msgid "Length: %s"
 msgstr "Lengte: %s"
 
-#: src/ftp.c:694 src/ftp.c:701
+#: src/ftp.c:821 src/ftp.c:828
 #, c-format
 msgid " [%s to go]"
 msgstr " [nog %s]"
 
 # Geen idee hoe dit correct te vertalen
-#: src/ftp.c:703
+#: src/ftp.c:830
 msgid " (unauthoritative)\n"
 msgstr " (onauthoritatief)\n"
 
-#: src/ftp.c:721
+#: src/ftp.c:856
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, verbreek besturingsverbinding.\n"
 
-#: src/ftp.c:729
+#: src/ftp.c:864
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - Gegevensverbinding: %s; "
 
-#: src/ftp.c:746
+#: src/ftp.c:881
 msgid "Control connection closed.\n"
 msgstr "Besturingsverbinding verbroken.\n"
 
-#: src/ftp.c:764
+#: src/ftp.c:899
 msgid "Data transfer aborted.\n"
 msgstr "Gegevensoverdracht afgebroken.\n"
 
-#: src/ftp.c:830
+#: src/ftp.c:963
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "Bestand `%s' reeds aanwezig, niet ophalen.\n"
 
-#: src/ftp.c:896 src/http.c:922
-#, c-format
+#: src/ftp.c:1024 src/http.c:1358
+#, c-format, ycp-format
 msgid "(try:%2d)"
 msgstr "(poging:%2d)"
 
-#: src/ftp.c:955 src/http.c:1116
+#: src/ftp.c:1088 src/http.c:1585
+#, c-format
+msgid ""
+"%s (%s) - `%s' saved [%ld]\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' bewaard [%ld]\n"
+"\n"
+
+#: src/ftp.c:1130 src/main.c:771 src/recur.c:505 src/retr.c:580
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld]\n\n"
-msgstr "%s (%s) - `%s' bewaard [%ld]\n\n"
+msgid "Removing %s.\n"
+msgstr "Verwijder `%s'.\n"
 
-#: src/ftp.c:1001
+#: src/ftp.c:1171
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Aanroep `%s' als tijdelijk lijstbestand.\n"
 
-#: src/ftp.c:1013
+#: src/ftp.c:1183
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "Verwijderd `%s'.\n"
 
-#: src/ftp.c:1049
+#: src/ftp.c:1219
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "De recursiediepte %d overschreed de maximum diepte %d.\n"
 
-#: src/ftp.c:1096 src/http.c:1054
+#: src/ftp.c:1271 src/http.c:1512
 #, c-format
-msgid "Local file `%s' is more recent, not retrieving.\n\n"
-msgstr "Lokaal bestand `%s' is nieuwer, niet ophalen.\n\n"
+msgid ""
+"Server file no newer than local file `%s' -- not retrieving.\n"
+"\n"
+msgstr ""
 
-#: src/ftp.c:1102 src/http.c:1060
-#, c-format
-msgid "The sizes do not match (local %ld), retrieving.\n"
+#: src/ftp.c:1279
+msgid "Cannot compare sizes, remote system is VMS.\n"
+msgstr ""
+
+#: src/ftp.c:1285 src/http.c:1520
+#, fuzzy, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n"
 msgstr "Groottes komen niet overeen (lokaal %ld), ophalen.\n"
 
-#: src/ftp.c:1119
+#: src/ftp.c:1303
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Ongeldige naam voor een symbolische koppeling, overslaan.\n"
 
-#: src/ftp.c:1136
+#: src/ftp.c:1320
 #, c-format
-msgid "Already have correct symlink %s -> %s\n\n"
+msgid ""
+"Already have correct symlink %s -> %s\n"
+"\n"
 msgstr "Juiste symbolische koppeling bestaat reeds %s -> %s\n"
 
-#: src/ftp.c:1143
+#: src/ftp.c:1328
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Maak symbolische koppeling %s -> %s\n"
 
-#: src/ftp.c:1154
+#: src/ftp.c:1339
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr "Symbolische koppelingen niet ondersteunt, symbolische koppeling overslaan `%s'.\n"
+msgstr ""
+"Symbolische koppelingen niet ondersteunt, symbolische koppeling overslaan "
+"`%s'.\n"
 
-#: src/ftp.c:1166
+#: src/ftp.c:1351
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Directory overslaan `%s'.\n"
 
-#: src/ftp.c:1175
+#: src/ftp.c:1360
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: onbekend/niet-ondersteund bestandstype.\n"
 
-#: src/ftp.c:1191
+#: src/ftp.c:1377
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: beschadigd tijdstempel.\n"
 
-#: src/ftp.c:1211
+#: src/ftp.c:1398
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Mappen worden niet opgehaald, omdat diepte %d is (max %d).\n"
 
-#: src/ftp.c:1250
+#: src/ftp.c:1437
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "Daal niet af naar `%s', omdat het uitgesloten/niet-ingesloten is.\n"
 
-#: src/ftp.c:1295
+#: src/ftp.c:1482
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "`%s' afgewezen.\n"
