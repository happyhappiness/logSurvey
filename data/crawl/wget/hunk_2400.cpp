 "Content-Type: text/plain; charset=iso-8859-2\n"
 "Content-Transfer-Encoding: 8bit\n"
 
-#. Login to the server:
-#. First: Establish the control connection.
-#: src/ftp.c:147 src/http.c:346
+#: src/connect.c:195
 #, c-format
-msgid "Connecting to %s:%hu... "
+msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
+msgstr ""
+
+#: src/connect.c:267
+#, fuzzy, c-format
+msgid "Connecting to %s|%s|:%d... "
 msgstr "Kontakter %s:%hu... "
 
-#: src/ftp.c:169 src/ftp.c:411 src/http.c:363
-#, c-format
-msgid "Connection to %s:%hu refused.\n"
-msgstr "Kontakt med %s:%hu nektet.\n"
+#: src/connect.c:270
+#, fuzzy, c-format
+msgid "Connecting to %s:%d... "
+msgstr "Kontakter %s:%hu... "
 
-#. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:190 src/http.c:374
-msgid "connected!\n"
+#: src/connect.c:330
+#, fuzzy
+msgid "connected.\n"
 msgstr "kontakt!\n"
 
-#: src/ftp.c:191
+#: src/connect.c:342 src/host.c:752 src/host.c:781
+#, c-format
+msgid "failed: %s.\n"
+msgstr ""
+
+#: src/convert.c:171
+#, c-format
+msgid "Converted %d files in %s seconds.\n"
+msgstr ""
+
+#: src/convert.c:196
+#, c-format
+msgid "Converting %s... "
+msgstr "Konverterer %s... "
+
+#: src/convert.c:209
+msgid "nothing to do.\n"
+msgstr ""
+
+#: src/convert.c:217 src/convert.c:241
+#, c-format
+msgid "Cannot convert links in %s: %s\n"
+msgstr "Kan ikke konvertere linker i %s: %s\n"
+
+#: src/convert.c:232
+#, fuzzy, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "Kan ikke slette den symbolske linken �%s�: %s\n"
+
+#: src/convert.c:441
+#, fuzzy, c-format
+msgid "Cannot back up %s as %s: %s\n"
+msgstr "Kan ikke konvertere linker i %s: %s\n"
+
+#: src/cookies.c:443
+#, c-format
+msgid "Syntax error in Set-Cookie: %s at position %d.\n"
+msgstr ""
+
+#: src/cookies.c:685
+#, c-format
+msgid "Cookie coming from %s attempted to set domain to %s\n"
+msgstr ""
+
+#: src/cookies.c:1132 src/cookies.c:1250
+#, fuzzy, c-format
+msgid "Cannot open cookies file `%s': %s\n"
+msgstr "Kan ikke konvertere linker i %s: %s\n"
+
+#: src/cookies.c:1287
+#, fuzzy, c-format
+msgid "Error writing to `%s': %s\n"
+msgstr "Kan ikke skrive til �%s� (%s).\n"
+
+#: src/cookies.c:1290
+#, c-format
+msgid "Error closing `%s': %s\n"
+msgstr ""
+
+#: src/ftp-ls.c:836
+msgid "Unsupported listing type, trying Unix listing parser.\n"
+msgstr ""
+
+#: src/ftp-ls.c:882 src/ftp-ls.c:884
+#, c-format
+msgid "Index of /%s on %s:%d"
+msgstr "Indeks for /%s p� %s:%d"
+
+#: src/ftp-ls.c:907
+#, c-format
+msgid "time unknown       "
+msgstr "ukjent tid         "
+
+#: src/ftp-ls.c:911
+#, c-format
+msgid "File        "
+msgstr "Fil         "
+
+#: src/ftp-ls.c:914
+#, c-format
+msgid "Directory   "
+msgstr "Katalog     "
+
+#: src/ftp-ls.c:917
+#, c-format
+msgid "Link        "
+msgstr "Link        "
+
+#: src/ftp-ls.c:920
+#, c-format
+msgid "Not sure    "
+msgstr "Usikker     "
+
+#: src/ftp-ls.c:938
+#, c-format
+msgid " (%s bytes)"
+msgstr " (%s bytes)"
+
+#: src/ftp.c:209
+#, c-format
+msgid "Length: %s"
+msgstr "Lengde: %s"
+
+#: src/ftp.c:215 src/http.c:2174
+#, c-format
+msgid ", %s (%s) remaining"
+msgstr ""
+
+#: src/ftp.c:219 src/http.c:2178
+#, c-format
+msgid ", %s remaining"
+msgstr ""
+
+#: src/ftp.c:222
+msgid " (unauthoritative)\n"
+msgstr " (ubekreftet)\n"
+
+#. Second: Login with proper USER/PASS sequence.
+#: src/ftp.c:298
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Logger inn som %s ... "
 
-#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
-#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
+#: src/ftp.c:311 src/ftp.c:357 src/ftp.c:386 src/ftp.c:438 src/ftp.c:550
+#: src/ftp.c:596 src/ftp.c:625 src/ftp.c:682 src/ftp.c:743 src/ftp.c:803
+#: src/ftp.c:850
 msgid "Error in server response, closing control connection.\n"
 msgstr "Feil i svar fra tjener, lukker kontrollforbindelsen.\n"
 
-#: src/ftp.c:208
+#: src/ftp.c:318
 msgid "Error in server greeting.\n"
 msgstr "Feil i melding fra tjener.\n"
 
-#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
-#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
+#: src/ftp.c:325 src/ftp.c:446 src/ftp.c:558 src/ftp.c:633 src/ftp.c:692
+#: src/ftp.c:753 src/ftp.c:813 src/ftp.c:860
 msgid "Write failed, closing control connection.\n"
 msgstr "Feil ved skriving, lukker kontrollforbindelsen.\n"
 
-#: src/ftp.c:223
+#: src/ftp.c:331
 msgid "The server refuses login.\n"
 msgstr "Tjeneren tillater ikke innlogging.\n"
 
-#: src/ftp.c:230
+#: src/ftp.c:337
 msgid "Login incorrect.\n"
 msgstr "Feil ved innlogging.\n"
 
-#: src/ftp.c:237
+#: src/ftp.c:343
 msgid "Logged in!\n"
 msgstr "Logget inn!\n"
 
-#: src/ftp.c:270
+#: src/ftp.c:365
+msgid "Server error, can't determine system type.\n"
+msgstr ""
+
+#: src/ftp.c:374 src/ftp.c:669 src/ftp.c:726 src/ftp.c:769
+msgid "done.    "
+msgstr "OK.      "
+
+#: src/ftp.c:426 src/ftp.c:575 src/ftp.c:608 src/ftp.c:833 src/ftp.c:879
+msgid "done.\n"
+msgstr "OK.\n"
+
+#: src/ftp.c:453
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Ukjent type �%c�, lukker kontrollforbindelsen.\n"
 
-#: src/ftp.c:283
+#: src/ftp.c:465
 msgid "done.  "
 msgstr "OK.    "
 
-#: src/ftp.c:289
+#: src/ftp.c:471
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD ikke n�dvendig.\n"
 
-#: src/ftp.c:317
+#: src/ftp.c:564
 #, c-format
-msgid "No such directory `%s'.\n\n"
-msgstr "Ingen katalog ved navn �%s�.\n\n"
-
-#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1431
-msgid "done.\n"
-msgstr "OK.\n"
+msgid ""
+"No such directory `%s'.\n"
+"\n"
+msgstr ""
+"Ingen katalog ved navn �%s�.\n"
+"\n"
 
 #. do not CWD
-#: src/ftp.c:335
+#: src/ftp.c:579
 msgid "==> CWD not required.\n"
 msgstr "==> CWD ikke n�dvendig.\n"
 
-#: src/ftp.c:369
+#: src/ftp.c:639
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Kan ikke sette opp PASV-overf�ring.\n"
 
-#: src/ftp.c:373
+#: src/ftp.c:643
 msgid "Cannot parse PASV response.\n"
 msgstr "Kan ikke tolke PASV-tilbakemelding.\n"
 
-#: src/ftp.c:387
+#: src/ftp.c:660
 #, c-format
-msgid "Will try connecting to %s:%hu.\n"
-msgstr "Vil pr�ve � kontakte %s:%hu.\n"
-
-#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
-msgid "done.    "
-msgstr "OK.      "
+msgid "couldn't connect to %s port %d: %s\n"
+msgstr ""
 
-#: src/ftp.c:474
+#: src/ftp.c:708
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Bind-feil (%s).\n"
 
-#: src/ftp.c:490
+#: src/ftp.c:714
 msgid "Invalid PORT.\n"
 msgstr "Ugyldig PORT.\n"
 
-#: src/ftp.c:537
-msgid "\nREST failed, starting from scratch.\n"
-msgstr "\nFeil ved REST, starter fra begynnelsen.\n"
-
-#: src/ftp.c:586
-#, c-format
-msgid "No such file `%s'.\n\n"
-msgstr "Ingen fil ved navn �%s�.\n\n"
+#: src/ftp.c:760
+msgid ""
+"\n"
+"REST failed, starting from scratch.\n"
+msgstr ""
+"\n"
+"Feil ved REST, starter fra begynnelsen.\n"
 
-#: src/ftp.c:634
+#: src/ftp.c:821
 #, c-format
-msgid "No such file or directory `%s'.\n\n"
-msgstr "Ingen fil eller katalog ved navn �%s�.\n\n"
+msgid ""
+"No such file `%s'.\n"
+"\n"
+msgstr ""
+"Ingen fil ved navn �%s�.\n"
+"\n"
 
-#: src/ftp.c:692 src/ftp.c:699
+#: src/ftp.c:868
 #, c-format
-msgid "Length: %s"
-msgstr "Lengde: %s"
+msgid ""
+"No such file or directory `%s'.\n"
+"\n"
+msgstr ""
+"Ingen fil eller katalog ved navn �%s�.\n"
+"\n"
 
-#: src/ftp.c:694 src/ftp.c:701
+#. We cannot just invent a new name and use it (which is
+#. what functions like unique_create typically do)
+#. because we told the user we'd use this name.
+#. Instead, return and retry the download.
+#: src/ftp.c:930 src/http.c:2236
 #, c-format
-msgid " [%s to go]"
-msgstr " [%s igjen]"
-
-#: src/ftp.c:703
-msgid " (unauthoritative)\n"
-msgstr " (ubekreftet)\n"
+msgid "%s has sprung into existence.\n"
+msgstr ""
 
-#: src/ftp.c:721
+#: src/ftp.c:982
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, lukker kontrollforbindelsen.\n"
 
-#: src/ftp.c:729
+#: src/ftp.c:991
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - dataforbindelse: %s; "
 
-#: src/ftp.c:746
+#: src/ftp.c:1006
 msgid "Control connection closed.\n"
 msgstr "Forbindelsen brutt.\n"
 
-#: src/ftp.c:764
+#: src/ftp.c:1024
 msgid "Data transfer aborted.\n"
 msgstr "Dataoverf�ring brutt.\n"
 
-#: src/ftp.c:830
-#, c-format
-msgid "File `%s' already there, not retrieving.\n"
+#: src/ftp.c:1092
+#, fuzzy, c-format
+msgid "File `%s' already there; not retrieving.\n"
 msgstr "File �%s� eksisterer allerede, ignoreres.\n"
 
-#: src/ftp.c:896 src/http.c:922
+#: src/ftp.c:1160 src/http.c:2375
 #, c-format
 msgid "(try:%2d)"
 msgstr "(fors�k:%2d)"
 
-#: src/ftp.c:955 src/http.c:1116
+#: src/ftp.c:1230 src/http.c:2683
+#, fuzzy, c-format
+msgid ""
+"%s (%s) - `%s' saved [%s]\n"
+"\n"
+msgstr ""
+"%s (%s) - �%s� lagret [%ld]\n"
+"\n"
+
+#: src/ftp.c:1272 src/main.c:990 src/recur.c:376 src/retr.c:859
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld]\n\n"
-msgstr "%s (%s) - �%s� lagret [%ld]\n\n"
+msgid "Removing %s.\n"
+msgstr "Fjerner %s.\n"
 
-#: src/ftp.c:1001
+#: src/ftp.c:1314
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Bruker �%s� som tempor�r katalogliste.\n"
 
-#: src/ftp.c:1013
+#: src/ftp.c:1329
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "Slettet �%s�.\n"
 
-#: src/ftp.c:1049
+#: src/ftp.c:1362
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "Rekursjonsdybde %d overskred maksimal dybde %d.\n"
 
-#: src/ftp.c:1096 src/http.c:1054
-#, c-format
-msgid "Local file `%s' is more recent, not retrieving.\n\n"
-msgstr "Lokal fil �%s� er samme/nyere, ignoreres.\n\n"
+#. Remote file is older, file sizes can be compared and
+#. are both equal.
+#: src/ftp.c:1432
+#, fuzzy, c-format
+msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
+msgstr "Fil p� tjener er nyere - hentes.\n"
 
-#: src/ftp.c:1102 src/http.c:1060
-#, c-format
-msgid "The sizes do not match (local %ld), retrieving.\n"
+#. Remote file is newer or sizes cannot be matched
+#: src/ftp.c:1439
+#, fuzzy, c-format
+msgid ""
+"Remote file is newer than local file `%s' -- retrieving.\n"
+"\n"
+msgstr "Fil p� tjener er nyere - hentes.\n"
+
+#. Sizes do not match
+#: src/ftp.c:1446
+#, fuzzy, c-format
+msgid ""
+"The sizes do not match (local %s) -- retrieving.\n"
+"\n"
 msgstr "Filst�rrelsene er forskjellige (local %ld), hentes.\n"
 
-#: src/ftp.c:1119
+#: src/ftp.c:1464
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Ugyldig navn for symbolsk link, ignoreres.\n"
 
-#: src/ftp.c:1136
+#: src/ftp.c:1481
 #, c-format
-msgid "Already have correct symlink %s -> %s\n\n"
-msgstr "Har allerede gyldig symbolsk link %s -> %s\n\n"
+msgid ""
+"Already have correct symlink %s -> %s\n"
+"\n"
+msgstr ""
+"Har allerede gyldig symbolsk link %s -> %s\n"
+"\n"
 
-#: src/ftp.c:1144
+#: src/ftp.c:1489
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Lager symbolsk link %s -> %s\n"
 
-#: src/ftp.c:1155
+#: src/ftp.c:1499
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "Symbolske linker ikke st�ttet, ignorerer �%s�.\n"
 
-#: src/ftp.c:1167
+#: src/ftp.c:1511
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Ignorerer katalog �%s�.\n"
 
-#: src/ftp.c:1176
+#: src/ftp.c:1520
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: filtypen er ukjent/ikke st�ttet.\n"
 
-#: src/ftp.c:1193
+#: src/ftp.c:1547
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: ugyldig tidsstempel.\n"
 
-#: src/ftp.c:1213
+#: src/ftp.c:1575
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Henter ikke kataloger p� dybde %d (max %d).\n"
 
-#: src/ftp.c:1252
+#: src/ftp.c:1625
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "Behandler ikke �%s� da det er ekskludert/ikke inkludert.\n"
 
-#: src/ftp.c:1297
+#: src/ftp.c:1691 src/ftp.c:1705
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Ignorerer �%s�.\n"
