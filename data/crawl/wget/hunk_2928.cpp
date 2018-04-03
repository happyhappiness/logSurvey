 "Content-Type: text/plain; charset=iso-8859-1\n"
 "Content-Transfer-Encoding: 8bit\n"
 
-#: src/connect.c:94
+#: src/connect.c:200
 #, c-format
-msgid "Connecting to %s[%s]:%hu... "
+msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
+msgstr ""
+
+#: src/connect.c:272
+#, fuzzy, c-format
+msgid "Connecting to %s|%s|:%d... "
 msgstr "Kontakter %s[%s]:%hu... "
 
-#: src/connect.c:97
-#, c-format
-msgid "Connecting to %s:%hu... "
+#: src/connect.c:275
+#, fuzzy, c-format
+msgid "Connecting to %s:%d... "
 msgstr "Kontakter %s:%hu... "
 
-#: src/connect.c:131
+#: src/connect.c:336
 msgid "connected.\n"
 msgstr "forbundet.\n"
 
-#: src/cookies.c:595
+#: src/convert.c:176
+#, fuzzy, c-format
+msgid "Converted %d files in %.*f seconds.\n"
+msgstr "Konverterede %d filer på %.2f sekunder.\n"
+
+#: src/convert.c:202
 #, c-format
-msgid "Error in Set-Cookie, field `%s'"
-msgstr "fejl ved Set-Cookie, felt '%s'"
+msgid "Converting %s... "
+msgstr "Konverterer %s... "
+
+#: src/convert.c:215
+msgid "nothing to do.\n"
+msgstr "ingenting at gøre.\n"
+
+#: src/convert.c:223 src/convert.c:247
+#, c-format
+msgid "Cannot convert links in %s: %s\n"
+msgstr "Kan ikke konvertere lænker i %s: %s\n"
+
+#: src/convert.c:238
+#, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "Kan ikke slette '%s': %s\n"
+
+#: src/convert.c:447
+#, c-format
+msgid "Cannot back up %s as %s: %s\n"
+msgstr "Kan ikke sikkerhedskopiere %s som %s: %s\n"
 
 #: src/cookies.c:619
 #, c-format
-msgid "Syntax error in Set-Cookie at character `%c'.\n"
-msgstr "Syntaksfejl i Set-Cookie ved tegnet '%c'.\n"
+msgid "Error in Set-Cookie, field `%s'"
+msgstr "fejl ved Set-Cookie, felt '%s'"
 
-#: src/cookies.c:627
-msgid "Syntax error in Set-Cookie: premature end of string.\n"
+#: src/cookies.c:643
+#, fuzzy, c-format
+msgid "Syntax error in Set-Cookie: %s at position %d.\n"
 msgstr "Syntaksfejl i Set-Cookie: streng afsluttet for tidligt.\n"
 
-#: src/cookies.c:1329
+#: src/cookies.c:1456
 #, c-format
 msgid "Cannot open cookies file `%s': %s\n"
 msgstr "Kan ikke åbne infokagefil %s: %s\n"
 
-#: src/cookies.c:1341
+#: src/cookies.c:1468
 #, c-format
 msgid "Error writing to `%s': %s\n"
 msgstr "Fejl ved skrivning til '%s' %s\n"
 
-#: src/cookies.c:1345
+#: src/cookies.c:1471
 #, c-format
 msgid "Error closing `%s': %s\n"
 msgstr "Fejl ved lukning af '%s': %s\n"
 
-#: src/ftp-ls.c:802
+#: src/ftp-ls.c:841
 msgid "Unsupported listing type, trying Unix listing parser.\n"
 msgstr "Ikke-understøttet listningstype, prøver Unix-listningsfortolker.\n"
 
-#: src/ftp-ls.c:847 src/ftp-ls.c:849
+#: src/ftp-ls.c:887 src/ftp-ls.c:889
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Indeks for /%s på %s:%d"
 
-#: src/ftp-ls.c:871
+#: src/ftp-ls.c:912
+#, c-format
 msgid "time unknown       "
 msgstr "ukendt tid         "
 
-#: src/ftp-ls.c:875
+#: src/ftp-ls.c:916
+#, c-format
 msgid "File        "
 msgstr "Fil         "
 
-#: src/ftp-ls.c:878
+#: src/ftp-ls.c:919
+#, c-format
 msgid "Directory   "
 msgstr "Katalog     "
 
-#: src/ftp-ls.c:881
+#: src/ftp-ls.c:922
+#, c-format
 msgid "Link        "
 msgstr "Link        "
 
-#: src/ftp-ls.c:884
+#: src/ftp-ls.c:925
+#, c-format
 msgid "Not sure    "
 msgstr "Usikker     "
 
-#: src/ftp-ls.c:902
+#: src/ftp-ls.c:943
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s byte)"
 
+#: src/ftp.c:226
+#, c-format
+msgid "Length: %s"
+msgstr "Længde: %s"
+
+#: src/ftp.c:232 src/http.c:1791
+#, c-format
+msgid ", %s (%s) remaining"
+msgstr ""
+
+#: src/ftp.c:236 src/http.c:1795
+#, c-format
+msgid ", %s remaining"
+msgstr ""
+
+#: src/ftp.c:240
+msgid " (unauthoritative)\n"
+msgstr " (ikke endegyldigt)\n"
+
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:179
+#: src/ftp.c:314
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Logger ind som %s ... "
 
-#: src/ftp.c:188 src/ftp.c:241 src/ftp.c:272 src/ftp.c:326 src/ftp.c:419
-#: src/ftp.c:470 src/ftp.c:500 src/ftp.c:564 src/ftp.c:628 src/ftp.c:689
-#: src/ftp.c:737
+#: src/ftp.c:327 src/ftp.c:380 src/ftp.c:411 src/ftp.c:465 src/ftp.c:580
+#: src/ftp.c:631 src/ftp.c:661 src/ftp.c:723 src/ftp.c:791 src/ftp.c:855
+#: src/ftp.c:907
 msgid "Error in server response, closing control connection.\n"
 msgstr "Fejl i svar fra server, lukker kontrolforbindelsen.\n"
 
-#: src/ftp.c:196
+#: src/ftp.c:335
 msgid "Error in server greeting.\n"
 msgstr "Fejl i velkomsthilsen fra server.\n"
 
-#: src/ftp.c:204 src/ftp.c:335 src/ftp.c:428 src/ftp.c:509 src/ftp.c:574
-#: src/ftp.c:638 src/ftp.c:699 src/ftp.c:747
+#: src/ftp.c:343 src/ftp.c:474 src/ftp.c:589 src/ftp.c:670 src/ftp.c:734
+#: src/ftp.c:802 src/ftp.c:866 src/ftp.c:918
 msgid "Write failed, closing control connection.\n"
 msgstr "Fejl ved skrivning, lukker kontrolforbindelsen.\n"
 
-#: src/ftp.c:211
+#: src/ftp.c:350
 msgid "The server refuses login.\n"
 msgstr "Serveren tillader ikke indlogning.\n"
 
-#: src/ftp.c:218
+#: src/ftp.c:357
 msgid "Login incorrect.\n"
 msgstr "Fejl ved indlogging.\n"
 
-#: src/ftp.c:225
+#: src/ftp.c:364
 msgid "Logged in!\n"
 msgstr "Logget ind!\n"
 
-#: src/ftp.c:250
+#: src/ftp.c:389
 msgid "Server error, can't determine system type.\n"
 msgstr "Serverfejl, kan ikke bestemme systemtype.\n"
 
-#: src/ftp.c:260 src/ftp.c:549 src/ftp.c:612 src/ftp.c:669
+#: src/ftp.c:399 src/ftp.c:710 src/ftp.c:774 src/ftp.c:821
 msgid "done.    "
 msgstr "færdig.      "
 
-#: src/ftp.c:314 src/ftp.c:449 src/ftp.c:484 src/ftp.c:720 src/ftp.c:768
-#: src/host.c:283
+#: src/ftp.c:453 src/ftp.c:610 src/ftp.c:645 src/ftp.c:890 src/ftp.c:941
 msgid "done.\n"
 msgstr "O.k.\n"
 
-#: src/ftp.c:343
+#: src/ftp.c:482
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Ukendt type '%c', lukker kontrolforbindelsen.\n"
 
-#: src/ftp.c:356
+#: src/ftp.c:495
 msgid "done.  "
 msgstr "O.k.    "
 
-#: src/ftp.c:362
+#: src/ftp.c:501
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD ikke nødvendig.\n"
 
-#: src/ftp.c:435
+#: src/ftp.c:596
 #, c-format
-msgid "No such directory `%s'.\n\n"
-msgstr "Intet katalog ved navn '%s'.\n\n"
+msgid ""
+"No such directory `%s'.\n"
+"\n"
+msgstr ""
+"Intet katalog ved navn '%s'.\n"
+"\n"
 
 #. do not CWD
-#: src/ftp.c:453
+#: src/ftp.c:614
 msgid "==> CWD not required.\n"
 msgstr "==> CWD ikke nødvendig.\n"
 
-#: src/ftp.c:516
+#: src/ftp.c:677
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Kan ikke opsætte PASV-overførsel.\n"
 
-#: src/ftp.c:520
+#: src/ftp.c:681
 msgid "Cannot parse PASV response.\n"
 msgstr "Kan ikke tolke PASV-tilbagemelding.\n"
 
-#: src/ftp.c:541
-#, c-format
-msgid "couldn't connect to %s:%hu: %s\n"
+#: src/ftp.c:701
+#, fuzzy, c-format
+msgid "couldn't connect to %s port %d: %s\n"
 msgstr "kunne ikke forbinde til %s:%hu: %s\n"
 
-#: src/ftp.c:591
+#: src/ftp.c:752
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Bind-fejl (%s).\n"
 
-#: src/ftp.c:598
+#: src/ftp.c:759
 msgid "Invalid PORT.\n"
 msgstr "Ugyldig PORT.\n"
 
-#: src/ftp.c:651
-#, c-format
-msgid "\nREST failed; will not truncate `%s'.\n"
-msgstr "\nREST mislykkedes; vil ikke afkorte '%s'.\n"
-
-#: src/ftp.c:658
-msgid "\nREST failed, starting from scratch.\n"
-msgstr "\nFejl ved REST, starter forfra.\n"
-
-#: src/ftp.c:707
-#, c-format
-msgid "No such file `%s'.\n\n"
-msgstr "Ingen fil ved navn '%s'.\n\n"
+#: src/ftp.c:810
+msgid ""
+"\n"
+"REST failed, starting from scratch.\n"
+msgstr ""
+"\n"
+"Fejl ved REST, starter forfra.\n"
 
-#: src/ftp.c:755
+#: src/ftp.c:875
 #, c-format
-msgid "No such file or directory `%s'.\n\n"
-msgstr "Ingen fil eller katalog ved navn '%s'.\n\n"
+msgid ""
+"No such file `%s'.\n"
+"\n"
+msgstr ""
+"Ingen fil ved navn '%s'.\n"
+"\n"
 
-#: src/ftp.c:839 src/ftp.c:847
+#: src/ftp.c:927
 #, c-format
-msgid "Length: %s"
-msgstr "Længde: %s"
+msgid ""
+"No such file or directory `%s'.\n"
+"\n"
+msgstr ""
+"Ingen fil eller katalog ved navn '%s'.\n"
+"\n"
 
-#: src/ftp.c:841 src/ftp.c:849
+#. We cannot just invent a new name and use it (which is
+#. what functions like unique_create typically do)
+#. because we told the user we'd use this name.
+#. Instead, return and retry the download.
+#: src/ftp.c:992 src/http.c:1847
 #, c-format
-msgid " [%s to go]"
-msgstr " [%s tilbage]"
-
-#: src/ftp.c:851
-msgid " (unauthoritative)\n"
-msgstr " (ikke endegyldigt)\n"
+msgid "%s has sprung into existence.\n"
+msgstr ""
 
-#: src/ftp.c:877
+#: src/ftp.c:1054
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, lukker kontrolforbindelsen.\n"
 
-#: src/ftp.c:885
+#: src/ftp.c:1062
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - dataforbindelse: %s; "
 
-#: src/ftp.c:902
+#: src/ftp.c:1077
 msgid "Control connection closed.\n"
 msgstr "Forbindelsen lukket.\n"
 
-#: src/ftp.c:920
+#: src/ftp.c:1095
 msgid "Data transfer aborted.\n"
 msgstr "Dataoverførsel afbrudt.\n"
 
-#: src/ftp.c:984
+#: src/ftp.c:1160
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "File '%s' eksisterer allerede, hentes ikke.\n"
 
-#: src/ftp.c:1054 src/http.c:1527
+#: src/ftp.c:1224 src/http.c:2066
 #, c-format
 msgid "(try:%2d)"
 msgstr "(forsøg:%2d)"
 
-#: src/ftp.c:1118 src/http.c:1786
-#, c-format
-msgid "%s (%s) - `%s' saved [%ld]\n\n"
-msgstr "%s (%s) - '%s' gemt [%ld]\n\n"
+#: src/ftp.c:1296 src/http.c:2347
+#, fuzzy, c-format
+msgid ""
+"%s (%s) - `%s' saved [%s]\n"
+"\n"
+msgstr ""
+"%s (%s) - '%s' gemt [%ld]\n"
+"\n"
 
-#: src/ftp.c:1160 src/main.c:819 src/recur.c:349 src/retr.c:587
+#: src/ftp.c:1338 src/main.c:921 src/recur.c:376 src/retr.c:835
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Fjerner %s.\n"
 
-#: src/ftp.c:1202
+#: src/ftp.c:1380
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Bruger '%s' som midlertidig katalogliste.\n"
 
-#: src/ftp.c:1217
+#: src/ftp.c:1395
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "Slettet '%s'.\n"
 
-#: src/ftp.c:1252
+#: src/ftp.c:1430
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "Rekursionsdybde %d overskred maksimal dybde %d.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1317
+#: src/ftp.c:1500
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
-msgstr "Fjernfil ikke nyere end lokal fil '%s' - hentes ikke.\n\n"
+msgstr ""
+"Fjernfil ikke nyere end lokal fil '%s' - hentes ikke.\n"
+"\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1324
+#: src/ftp.c:1507
 #, c-format
-msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
-msgstr "Fjernfil er nyere end lokal fil '%s' - hentes.\n\n"
+msgid ""
+"Remote file is newer than local file `%s' -- retrieving.\n"
+"\n"
+msgstr ""
+"Fjernfil er nyere end lokal fil '%s' - hentes.\n"
+"\n"
 
 #. Sizes do not match
-#: src/ftp.c:1331
-#, c-format
-msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
+#: src/ftp.c:1514
+#, fuzzy, c-format
+msgid ""
+"The sizes do not match (local %s) -- retrieving.\n"
+"\n"
 msgstr "Størrelserne er forskellige (lokal %ld) - hentes.\n"
 
-#: src/ftp.c:1348
+#: src/ftp.c:1532
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Ugyldigt navn for symbolsk lænke, ignoreres.\n"
 
-#: src/ftp.c:1365
+#: src/ftp.c:1549
 #, c-format
-msgid "Already have correct symlink %s -> %s\n\n"
-msgstr "Har allerede gyldig symbolsk lænke %s -> %s\n\n"
+msgid ""
+"Already have correct symlink %s -> %s\n"
+"\n"
+msgstr ""
+"Har allerede gyldig symbolsk lænke %s -> %s\n"
+"\n"
 
-#: src/ftp.c:1373
+#: src/ftp.c:1557
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Laver symbolsk lænke %s -> %s\n"
 
-#: src/ftp.c:1384
+#: src/ftp.c:1567
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "Symbolske lænker ikke understøttet, ignorerer '%s'.\n"
 
-#: src/ftp.c:1396
+#: src/ftp.c:1579
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Ignorerer katalog '%s'.\n"
 
-#: src/ftp.c:1405
+#: src/ftp.c:1588
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: filtypen er ukendt/ikke understøttet.\n"
 
-#: src/ftp.c:1432
+#: src/ftp.c:1615
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: ugyldigt tidsstempel.\n"
 
-#: src/ftp.c:1457
+#: src/ftp.c:1643
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Henter ikke kataloger, da dybde er %d (max %d).\n"
 
-#: src/ftp.c:1507
+#: src/ftp.c:1693
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "Behandler ikke '%s' da det er ekskluderet/ikke inkluderet.\n"
 
-#: src/ftp.c:1561
+#: src/ftp.c:1759 src/ftp.c:1773
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Ignorerer '%s'.\n"
