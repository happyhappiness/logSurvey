 "Content-Type: text/plain; charset=iso-8859-1\n"
 "Content-Transfer-Encoding: 8bit\n"
 
-#: src/connect.c:199
+#: src/connect.c:94
 #, c-format
-msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
-msgstr ""
-
-#: src/connect.c:271
-#, fuzzy, c-format
-msgid "Connecting to %s|%s|:%d... "
+msgid "Connecting to %s[%s]:%hu... "
 msgstr "Kontakter %s[%s]:%hu... "
 
-#: src/connect.c:274
-#, fuzzy, c-format
-msgid "Connecting to %s:%d... "
+#: src/connect.c:97
+#, c-format
+msgid "Connecting to %s:%hu... "
 msgstr "Kontakter %s:%hu... "
 
-#: src/connect.c:335
+#: src/connect.c:131
 msgid "connected.\n"
 msgstr "forbundet.\n"
 
-#: src/convert.c:176
-#, fuzzy, c-format
-msgid "Converted %d files in %.*f seconds.\n"
-msgstr "Konverterede %d filer på %.2f sekunder.\n"
-
-#: src/convert.c:202
-#, c-format
-msgid "Converting %s... "
-msgstr "Konverterer %s... "
-
-#: src/convert.c:215
-msgid "nothing to do.\n"
-msgstr "ingenting at gøre.\n"
-
-#: src/convert.c:223 src/convert.c:247
-#, c-format
-msgid "Cannot convert links in %s: %s\n"
-msgstr "Kan ikke konvertere lænker i %s: %s\n"
-
-#: src/convert.c:238
+#: src/cookies.c:595
 #, c-format
-msgid "Unable to delete `%s': %s\n"
-msgstr "Kan ikke slette '%s': %s\n"
-
-#: src/convert.c:447
-#, c-format
-msgid "Cannot back up %s as %s: %s\n"
-msgstr "Kan ikke sikkerhedskopiere %s som %s: %s\n"
+msgid "Error in Set-Cookie, field `%s'"
+msgstr "fejl ved Set-Cookie, felt '%s'"
 
 #: src/cookies.c:619
 #, c-format
-msgid "Error in Set-Cookie, field `%s'"
-msgstr "fejl ved Set-Cookie, felt '%s'"
+msgid "Syntax error in Set-Cookie at character `%c'.\n"
+msgstr "Syntaksfejl i Set-Cookie ved tegnet '%c'.\n"
 
-#: src/cookies.c:643
-#, fuzzy, c-format
-msgid "Syntax error in Set-Cookie: %s at position %d.\n"
+#: src/cookies.c:627
+msgid "Syntax error in Set-Cookie: premature end of string.\n"
 msgstr "Syntaksfejl i Set-Cookie: streng afsluttet for tidligt.\n"
 
-#: src/cookies.c:1469
+#: src/cookies.c:1329
 #, c-format
 msgid "Cannot open cookies file `%s': %s\n"
 msgstr "Kan ikke åbne infokagefil %s: %s\n"
 
-#: src/cookies.c:1481
+#: src/cookies.c:1341
 #, c-format
 msgid "Error writing to `%s': %s\n"
 msgstr "Fejl ved skrivning til '%s' %s\n"
 
-#: src/cookies.c:1484
+#: src/cookies.c:1345
 #, c-format
 msgid "Error closing `%s': %s\n"
 msgstr "Fejl ved lukning af '%s': %s\n"
 
-#: src/ftp-ls.c:841
+#: src/ftp-ls.c:802
 msgid "Unsupported listing type, trying Unix listing parser.\n"
 msgstr "Ikke-understøttet listningstype, prøver Unix-listningsfortolker.\n"
 
-#: src/ftp-ls.c:887 src/ftp-ls.c:889
+#: src/ftp-ls.c:847 src/ftp-ls.c:849
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Indeks for /%s på %s:%d"
 
-#: src/ftp-ls.c:912
-#, c-format
+#: src/ftp-ls.c:871
 msgid "time unknown       "
 msgstr "ukendt tid         "
 
-#: src/ftp-ls.c:916
-#, c-format
+#: src/ftp-ls.c:875
 msgid "File        "
 msgstr "Fil         "
 
-#: src/ftp-ls.c:919
-#, c-format
+#: src/ftp-ls.c:878
 msgid "Directory   "
 msgstr "Katalog     "
 
-#: src/ftp-ls.c:922
-#, c-format
+#: src/ftp-ls.c:881
 msgid "Link        "
 msgstr "Link        "
 
-#: src/ftp-ls.c:925
-#, c-format
+#: src/ftp-ls.c:884
 msgid "Not sure    "
 msgstr "Usikker     "
 
-#: src/ftp-ls.c:943
+#: src/ftp-ls.c:902
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s byte)"
 
-#: src/ftp.c:226
-#, c-format
-msgid "Length: %s"
-msgstr "Længde: %s"
-
-#: src/ftp.c:232 src/http.c:1857
-#, c-format
-msgid ", %s (%s) remaining"
-msgstr ""
-
-#: src/ftp.c:236 src/http.c:1861
-#, c-format
-msgid ", %s remaining"
-msgstr ""
-
-#: src/ftp.c:239
-msgid " (unauthoritative)\n"
-msgstr " (ikke endegyldigt)\n"
-
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:314
+#: src/ftp.c:179
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Logger ind som %s ... "
 
-#: src/ftp.c:327 src/ftp.c:373 src/ftp.c:402 src/ftp.c:454 src/ftp.c:566
-#: src/ftp.c:612 src/ftp.c:640 src/ftp.c:698 src/ftp.c:759 src/ftp.c:819
-#: src/ftp.c:866
+#: src/ftp.c:188 src/ftp.c:241 src/ftp.c:272 src/ftp.c:326 src/ftp.c:419
+#: src/ftp.c:470 src/ftp.c:500 src/ftp.c:564 src/ftp.c:628 src/ftp.c:689
+#: src/ftp.c:737
 msgid "Error in server response, closing control connection.\n"
 msgstr "Fejl i svar fra server, lukker kontrolforbindelsen.\n"
 
-#: src/ftp.c:334
+#: src/ftp.c:196
 msgid "Error in server greeting.\n"
 msgstr "Fejl i velkomsthilsen fra server.\n"
 
-#: src/ftp.c:341 src/ftp.c:462 src/ftp.c:574 src/ftp.c:648 src/ftp.c:708
-#: src/ftp.c:769 src/ftp.c:829 src/ftp.c:876
+#: src/ftp.c:204 src/ftp.c:335 src/ftp.c:428 src/ftp.c:509 src/ftp.c:574
+#: src/ftp.c:638 src/ftp.c:699 src/ftp.c:747
 msgid "Write failed, closing control connection.\n"
 msgstr "Fejl ved skrivning, lukker kontrolforbindelsen.\n"
 
-#: src/ftp.c:347
+#: src/ftp.c:211
 msgid "The server refuses login.\n"
 msgstr "Serveren tillader ikke indlogning.\n"
 
-#: src/ftp.c:353
+#: src/ftp.c:218
 msgid "Login incorrect.\n"
 msgstr "Fejl ved indlogging.\n"
 
-#: src/ftp.c:359
+#: src/ftp.c:225
 msgid "Logged in!\n"
 msgstr "Logget ind!\n"
 
-#: src/ftp.c:381
+#: src/ftp.c:250
 msgid "Server error, can't determine system type.\n"
 msgstr "Serverfejl, kan ikke bestemme systemtype.\n"
 
-#: src/ftp.c:390 src/ftp.c:685 src/ftp.c:742 src/ftp.c:785
+#: src/ftp.c:260 src/ftp.c:549 src/ftp.c:612 src/ftp.c:669
 msgid "done.    "
 msgstr "færdig.      "
 
-#: src/ftp.c:442 src/ftp.c:591 src/ftp.c:624 src/ftp.c:849 src/ftp.c:895
+#: src/ftp.c:314 src/ftp.c:449 src/ftp.c:484 src/ftp.c:720 src/ftp.c:768
+#: src/host.c:283
 msgid "done.\n"
 msgstr "O.k.\n"
 
-#: src/ftp.c:469
+#: src/ftp.c:343
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Ukendt type '%c', lukker kontrolforbindelsen.\n"
 
-#: src/ftp.c:481
+#: src/ftp.c:356
 msgid "done.  "
 msgstr "O.k.    "
 
-#: src/ftp.c:487
+#: src/ftp.c:362
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD ikke nødvendig.\n"
 
-#: src/ftp.c:580
+#: src/ftp.c:435
 #, c-format
-msgid ""
-"No such directory `%s'.\n"
-"\n"
-msgstr ""
-"Intet katalog ved navn '%s'.\n"
-"\n"
+msgid "No such directory `%s'.\n\n"
+msgstr "Intet katalog ved navn '%s'.\n\n"
 
 #. do not CWD
-#: src/ftp.c:595
+#: src/ftp.c:453
 msgid "==> CWD not required.\n"
 msgstr "==> CWD ikke nødvendig.\n"
 
-#: src/ftp.c:654
+#: src/ftp.c:516
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Kan ikke opsætte PASV-overførsel.\n"
 
-#: src/ftp.c:658
+#: src/ftp.c:520
 msgid "Cannot parse PASV response.\n"
 msgstr "Kan ikke tolke PASV-tilbagemelding.\n"
 
-#: src/ftp.c:676
-#, fuzzy, c-format
-msgid "couldn't connect to %s port %d: %s\n"
+#: src/ftp.c:541
+#, c-format
+msgid "couldn't connect to %s:%hu: %s\n"
 msgstr "kunne ikke forbinde til %s:%hu: %s\n"
 
-#: src/ftp.c:724
+#: src/ftp.c:591
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Bind-fejl (%s).\n"
 
-#: src/ftp.c:730
+#: src/ftp.c:598
 msgid "Invalid PORT.\n"
 msgstr "Ugyldig PORT.\n"
 
-#: src/ftp.c:776
-msgid ""
-"\n"
-"REST failed, starting from scratch.\n"
-msgstr ""
-"\n"
-"Fejl ved REST, starter forfra.\n"
+#: src/ftp.c:651
+#, c-format
+msgid "\nREST failed; will not truncate `%s'.\n"
+msgstr "\nREST mislykkedes; vil ikke afkorte '%s'.\n"
+
+#: src/ftp.c:658
+msgid "\nREST failed, starting from scratch.\n"
+msgstr "\nFejl ved REST, starter forfra.\n"
 
-#: src/ftp.c:837
+#: src/ftp.c:707
 #, c-format
-msgid ""
-"No such file `%s'.\n"
-"\n"
-msgstr ""
-"Ingen fil ved navn '%s'.\n"
-"\n"
+msgid "No such file `%s'.\n\n"
+msgstr "Ingen fil ved navn '%s'.\n\n"
 
-#: src/ftp.c:884
+#: src/ftp.c:755
 #, c-format
-msgid ""
-"No such file or directory `%s'.\n"
-"\n"
-msgstr ""
-"Ingen fil eller katalog ved navn '%s'.\n"
-"\n"
+msgid "No such file or directory `%s'.\n\n"
+msgstr "Ingen fil eller katalog ved navn '%s'.\n\n"
 
-#. We cannot just invent a new name and use it (which is
-#. what functions like unique_create typically do)
-#. because we told the user we'd use this name.
-#. Instead, return and retry the download.
-#: src/ftp.c:946 src/http.c:1913
+#: src/ftp.c:839 src/ftp.c:847
 #, c-format
-msgid "%s has sprung into existence.\n"
-msgstr ""
+msgid "Length: %s"
+msgstr "Længde: %s"
+
+#: src/ftp.c:841 src/ftp.c:849
+#, c-format
+msgid " [%s to go]"
+msgstr " [%s tilbage]"
+
+#: src/ftp.c:851
+msgid " (unauthoritative)\n"
+msgstr " (ikke endegyldigt)\n"
 
-#: src/ftp.c:1008
+#: src/ftp.c:877
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, lukker kontrolforbindelsen.\n"
 
-#: src/ftp.c:1016
+#: src/ftp.c:885
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - dataforbindelse: %s; "
 
-#: src/ftp.c:1031
+#: src/ftp.c:902
 msgid "Control connection closed.\n"
 msgstr "Forbindelsen lukket.\n"
 
-#: src/ftp.c:1049
+#: src/ftp.c:920
 msgid "Data transfer aborted.\n"
 msgstr "Dataoverførsel afbrudt.\n"
 
-#: src/ftp.c:1114
+#: src/ftp.c:984
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "File '%s' eksisterer allerede, hentes ikke.\n"
 
-#: src/ftp.c:1182 src/http.c:2130
+#: src/ftp.c:1054 src/http.c:1527
 #, c-format
 msgid "(try:%2d)"
 msgstr "(forsøg:%2d)"
 
-#: src/ftp.c:1252 src/http.c:2409
-#, fuzzy, c-format
-msgid ""
-"%s (%s) - `%s' saved [%s]\n"
-"\n"
-msgstr ""
-"%s (%s) - '%s' gemt [%ld]\n"
-"\n"
+#: src/ftp.c:1118 src/http.c:1786
+#, c-format
+msgid "%s (%s) - `%s' saved [%ld]\n\n"
+msgstr "%s (%s) - '%s' gemt [%ld]\n\n"
 
-#: src/ftp.c:1294 src/main.c:948 src/recur.c:376 src/retr.c:842
+#: src/ftp.c:1160 src/main.c:819 src/recur.c:349 src/retr.c:587
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Fjerner %s.\n"
 
-#: src/ftp.c:1336
+#: src/ftp.c:1202
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Bruger '%s' som midlertidig katalogliste.\n"
 
-#: src/ftp.c:1351
+#: src/ftp.c:1217
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "Slettet '%s'.\n"
 
-#: src/ftp.c:1386
+#: src/ftp.c:1252
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "Rekursionsdybde %d overskred maksimal dybde %d.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1456
+#: src/ftp.c:1317
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
-msgstr ""
-"Fjernfil ikke nyere end lokal fil '%s' - hentes ikke.\n"
-"\n"
+msgstr "Fjernfil ikke nyere end lokal fil '%s' - hentes ikke.\n\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1463
+#: src/ftp.c:1324
 #, c-format
-msgid ""
-"Remote file is newer than local file `%s' -- retrieving.\n"
-"\n"
-msgstr ""
-"Fjernfil er nyere end lokal fil '%s' - hentes.\n"
-"\n"
+msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
+msgstr "Fjernfil er nyere end lokal fil '%s' - hentes.\n\n"
 
 #. Sizes do not match
-#: src/ftp.c:1470
-#, fuzzy, c-format
-msgid ""
-"The sizes do not match (local %s) -- retrieving.\n"
-"\n"
+#: src/ftp.c:1331
+#, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
 msgstr "Størrelserne er forskellige (lokal %ld) - hentes.\n"
 
-#: src/ftp.c:1488
+#: src/ftp.c:1348
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Ugyldigt navn for symbolsk lænke, ignoreres.\n"
 
-#: src/ftp.c:1505
+#: src/ftp.c:1365
 #, c-format
-msgid ""
-"Already have correct symlink %s -> %s\n"
-"\n"
-msgstr ""
-"Har allerede gyldig symbolsk lænke %s -> %s\n"
-"\n"
+msgid "Already have correct symlink %s -> %s\n\n"
+msgstr "Har allerede gyldig symbolsk lænke %s -> %s\n\n"
 
-#: src/ftp.c:1513
+#: src/ftp.c:1373
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Laver symbolsk lænke %s -> %s\n"
 
-#: src/ftp.c:1523
+#: src/ftp.c:1384
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "Symbolske lænker ikke understøttet, ignorerer '%s'.\n"
 
-#: src/ftp.c:1535
+#: src/ftp.c:1396
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Ignorerer katalog '%s'.\n"
 
-#: src/ftp.c:1544
+#: src/ftp.c:1405
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: filtypen er ukendt/ikke understøttet.\n"
 
-#: src/ftp.c:1571
+#: src/ftp.c:1432
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: ugyldigt tidsstempel.\n"
 
-#: src/ftp.c:1599
+#: src/ftp.c:1457
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Henter ikke kataloger, da dybde er %d (max %d).\n"
 
-#: src/ftp.c:1649
+#: src/ftp.c:1507
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "Behandler ikke '%s' da det er ekskluderet/ikke inkluderet.\n"
 
-#: src/ftp.c:1715 src/ftp.c:1729
+#: src/ftp.c:1561
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Ignorerer '%s'.\n"
