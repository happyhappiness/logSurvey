 #
 msgid ""
 msgstr ""
-"Project-Id-Version: GNU Wget 1.7-dev\n"
-"Report-Msgid-Bugs-To: \n"
-"POT-Creation-Date: 2005-06-06 09:11-0400\n"
+"Project-Id-Version: wget 1.5.2-b1\n"
+"POT-Creation-Date: 2001-06-03 15:27+0200\n"
 "PO-Revision-Date: 1998-05-22 09:00+0100\n"
 "Last-Translator: Robert Schmidt <rsc@vingmed.no>\n"
 "Language-Team: Norwegian <no@li.org>\n"
 "MIME-Version: 1.0\n"
-"Content-Type: text/plain; charset=iso-8859-1\n"
+"Content-Type: text/plain; charset=iso-8859-2\n"
 "Content-Transfer-Encoding: 8bit\n"
 
-#: src/connect.c:199
+#: src/cookies.c:588
 #, c-format
-msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
-msgstr ""
-
-#: src/connect.c:271
-#, fuzzy, c-format
-msgid "Connecting to %s|%s|:%d... "
-msgstr "Kontakter %s:%hu... "
-
-#: src/connect.c:274
-#, fuzzy, c-format
-msgid "Connecting to %s:%d... "
-msgstr "Kontakter %s:%hu... "
-
-#: src/connect.c:335
-#, fuzzy
-msgid "connected.\n"
-msgstr "kontakt!\n"
-
-#: src/convert.c:176
-#, c-format
-msgid "Converted %d files in %.*f seconds.\n"
-msgstr ""
-
-#: src/convert.c:202
-#, c-format
-msgid "Converting %s... "
-msgstr "Konverterer %s... "
-
-#: src/convert.c:215
-msgid "nothing to do.\n"
+msgid "Error in Set-Cookie, field `%s'"
 msgstr ""
 
-#: src/convert.c:223 src/convert.c:247
-#, c-format
-msgid "Cannot convert links in %s: %s\n"
-msgstr "Kan ikke konvertere linker i %s: %s\n"
-
-#: src/convert.c:238
-#, fuzzy, c-format
-msgid "Unable to delete `%s': %s\n"
-msgstr "Kan ikke slette den symbolske linken «%s»: %s\n"
-
-#: src/convert.c:447
-#, fuzzy, c-format
-msgid "Cannot back up %s as %s: %s\n"
-msgstr "Kan ikke konvertere linker i %s: %s\n"
-
-#: src/cookies.c:619
+#: src/cookies.c:612
 #, c-format
-msgid "Error in Set-Cookie, field `%s'"
+msgid "Syntax error in Set-Cookie at character `%c'.\n"
 msgstr ""
 
-#: src/cookies.c:643
-#, c-format
-msgid "Syntax error in Set-Cookie: %s at position %d.\n"
+#: src/cookies.c:620
+msgid "Syntax error in Set-Cookie: premature end of string.\n"
 msgstr ""
 
-#: src/cookies.c:1469
+#: src/cookies.c:1352
 #, fuzzy, c-format
 msgid "Cannot open cookies file `%s': %s\n"
 msgstr "Kan ikke konvertere linker i %s: %s\n"
 
-#: src/cookies.c:1481
+#: src/cookies.c:1364
 #, fuzzy, c-format
 msgid "Error writing to `%s': %s\n"
 msgstr "Kan ikke skrive til «%s» (%s).\n"
 
-#: src/cookies.c:1484
+#: src/cookies.c:1368
 #, c-format
 msgid "Error closing `%s': %s\n"
 msgstr ""
 
-#: src/ftp-ls.c:841
+#: src/ftp-ls.c:787
 msgid "Unsupported listing type, trying Unix listing parser.\n"
 msgstr ""
 
-#: src/ftp-ls.c:887 src/ftp-ls.c:889
+#: src/ftp-ls.c:832 src/ftp-ls.c:834
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Indeks for /%s på %s:%d"
 
-#: src/ftp-ls.c:912
-#, c-format
+#: src/ftp-ls.c:856
 msgid "time unknown       "
 msgstr "ukjent tid         "
 
-#: src/ftp-ls.c:916
-#, c-format
+#: src/ftp-ls.c:860
 msgid "File        "
 msgstr "Fil         "
 
-#: src/ftp-ls.c:919
-#, c-format
+#: src/ftp-ls.c:863
 msgid "Directory   "
 msgstr "Katalog     "
 
-#: src/ftp-ls.c:922
-#, c-format
+#: src/ftp-ls.c:866
 msgid "Link        "
 msgstr "Link        "
 
-#: src/ftp-ls.c:925
-#, c-format
+#: src/ftp-ls.c:869
 msgid "Not sure    "
 msgstr "Usikker     "
 
-#: src/ftp-ls.c:943
+#: src/ftp-ls.c:887
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s bytes)"
 
-#: src/ftp.c:226
-#, c-format
-msgid "Length: %s"
-msgstr "Lengde: %s"
-
-#: src/ftp.c:232 src/http.c:1857
+#. Login to the server:
+#. First: Establish the control connection.
+#: src/ftp.c:150 src/http.c:624
 #, c-format
-msgid ", %s (%s) remaining"
-msgstr ""
+msgid "Connecting to %s:%hu... "
+msgstr "Kontakter %s:%hu... "
 
-#: src/ftp.c:236 src/http.c:1861
+#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
 #, c-format
-msgid ", %s remaining"
-msgstr ""
-
-#: src/ftp.c:239
-msgid " (unauthoritative)\n"
-msgstr " (ubekreftet)\n"
+msgid "Connection to %s:%hu refused.\n"
+msgstr "Kontakt med %s:%hu nektet.\n"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:314
+#: src/ftp.c:193 src/http.c:652
+msgid "connected!\n"
+msgstr "kontakt!\n"
+
+#: src/ftp.c:194
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Logger inn som %s ... "
 
-#: src/ftp.c:327 src/ftp.c:373 src/ftp.c:402 src/ftp.c:454 src/ftp.c:566
-#: src/ftp.c:612 src/ftp.c:640 src/ftp.c:698 src/ftp.c:759 src/ftp.c:819
-#: src/ftp.c:866
+#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
+#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
 msgid "Error in server response, closing control connection.\n"
 msgstr "Feil i svar fra tjener, lukker kontrollforbindelsen.\n"
 
-#: src/ftp.c:334
+#: src/ftp.c:211
 msgid "Error in server greeting.\n"
 msgstr "Feil i melding fra tjener.\n"
 
-#: src/ftp.c:341 src/ftp.c:462 src/ftp.c:574 src/ftp.c:648 src/ftp.c:708
-#: src/ftp.c:769 src/ftp.c:829 src/ftp.c:876
+#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
+#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
 msgid "Write failed, closing control connection.\n"
 msgstr "Feil ved skriving, lukker kontrollforbindelsen.\n"
 
-#: src/ftp.c:347
+#: src/ftp.c:226
 msgid "The server refuses login.\n"
 msgstr "Tjeneren tillater ikke innlogging.\n"
 
-#: src/ftp.c:353
+#: src/ftp.c:233
 msgid "Login incorrect.\n"
 msgstr "Feil ved innlogging.\n"
 
-#: src/ftp.c:359
+#: src/ftp.c:240
 msgid "Logged in!\n"
 msgstr "Logget inn!\n"
 
-#: src/ftp.c:381
+#: src/ftp.c:265
 msgid "Server error, can't determine system type.\n"
 msgstr ""
 
-#: src/ftp.c:390 src/ftp.c:685 src/ftp.c:742 src/ftp.c:785
+#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
 msgid "done.    "
 msgstr "OK.      "
 
-#: src/ftp.c:442 src/ftp.c:591 src/ftp.c:624 src/ftp.c:849 src/ftp.c:895
+#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
 msgid "done.\n"
 msgstr "OK.\n"
 
-#: src/ftp.c:469
+#: src/ftp.c:353
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Ukjent type «%c», lukker kontrollforbindelsen.\n"
 
-#: src/ftp.c:481
+#: src/ftp.c:366
 msgid "done.  "
 msgstr "OK.    "
 
-#: src/ftp.c:487
+#: src/ftp.c:372
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD ikke nødvendig.\n"
 
-#: src/ftp.c:580
+#: src/ftp.c:445
 #, c-format
-msgid ""
-"No such directory `%s'.\n"
-"\n"
-msgstr ""
-"Ingen katalog ved navn «%s».\n"
-"\n"
+msgid "No such directory `%s'.\n\n"
+msgstr "Ingen katalog ved navn «%s».\n\n"
 
 #. do not CWD
-#: src/ftp.c:595
+#: src/ftp.c:463
 msgid "==> CWD not required.\n"
 msgstr "==> CWD ikke nødvendig.\n"
 
-#: src/ftp.c:654
+#: src/ftp.c:497
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Kan ikke sette opp PASV-overføring.\n"
 
-#: src/ftp.c:658
+#: src/ftp.c:501
 msgid "Cannot parse PASV response.\n"
 msgstr "Kan ikke tolke PASV-tilbakemelding.\n"
 
-#: src/ftp.c:676
+#: src/ftp.c:515
 #, c-format
-msgid "couldn't connect to %s port %d: %s\n"
-msgstr ""
+msgid "Will try connecting to %s:%hu.\n"
+msgstr "Vil prøve å kontakte %s:%hu.\n"
 
-#: src/ftp.c:724
+#: src/ftp.c:602
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Bind-feil (%s).\n"
 
-#: src/ftp.c:730
+#: src/ftp.c:618
 msgid "Invalid PORT.\n"
 msgstr "Ugyldig PORT.\n"
 
-#: src/ftp.c:776
-msgid ""
-"\n"
-"REST failed, starting from scratch.\n"
+#: src/ftp.c:671
+#, c-format
+msgid "\nREST failed; will not truncate `%s'.\n"
 msgstr ""
-"\n"
-"Feil ved REST, starter fra begynnelsen.\n"
 
-#: src/ftp.c:837
+#: src/ftp.c:678
+msgid "\nREST failed, starting from scratch.\n"
+msgstr "\nFeil ved REST, starter fra begynnelsen.\n"
+
+#: src/ftp.c:727
 #, c-format
-msgid ""
-"No such file `%s'.\n"
-"\n"
-msgstr ""
-"Ingen fil ved navn «%s».\n"
-"\n"
+msgid "No such file `%s'.\n\n"
+msgstr "Ingen fil ved navn «%s».\n\n"
 
-#: src/ftp.c:884
+#: src/ftp.c:775
 #, c-format
-msgid ""
-"No such file or directory `%s'.\n"
-"\n"
-msgstr ""
-"Ingen fil eller katalog ved navn «%s».\n"
-"\n"
+msgid "No such file or directory `%s'.\n\n"
+msgstr "Ingen fil eller katalog ved navn «%s».\n\n"
 
-#. We cannot just invent a new name and use it (which is
-#. what functions like unique_create typically do)
-#. because we told the user we'd use this name.
-#. Instead, return and retry the download.
-#: src/ftp.c:946 src/http.c:1913
+#: src/ftp.c:859 src/ftp.c:867
 #, c-format
-msgid "%s has sprung into existence.\n"
-msgstr ""
+msgid "Length: %s"
+msgstr "Lengde: %s"
+
+#: src/ftp.c:861 src/ftp.c:869
+#, c-format
+msgid " [%s to go]"
+msgstr " [%s igjen]"
+
+#: src/ftp.c:871
+msgid " (unauthoritative)\n"
+msgstr " (ubekreftet)\n"
 
-#: src/ftp.c:1008
+#: src/ftp.c:898
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, lukker kontrollforbindelsen.\n"
 
-#: src/ftp.c:1016
+#: src/ftp.c:906
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - dataforbindelse: %s; "
 
-#: src/ftp.c:1031
+#: src/ftp.c:923
 msgid "Control connection closed.\n"
 msgstr "Forbindelsen brutt.\n"
 
-#: src/ftp.c:1049
+#: src/ftp.c:941
 msgid "Data transfer aborted.\n"
 msgstr "Dataoverføring brutt.\n"
 
-#: src/ftp.c:1114
+#: src/ftp.c:1005
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "File «%s» eksisterer allerede, ignoreres.\n"
 
-#: src/ftp.c:1182 src/http.c:2130
+#: src/ftp.c:1075 src/http.c:1502
 #, c-format
 msgid "(try:%2d)"
 msgstr "(forsøk:%2d)"
 
-#: src/ftp.c:1252 src/http.c:2409
-#, fuzzy, c-format
-msgid ""
-"%s (%s) - `%s' saved [%s]\n"
-"\n"
-msgstr ""
-"%s (%s) - «%s» lagret [%ld]\n"
-"\n"
+#: src/ftp.c:1139 src/http.c:1753
+#, c-format
+msgid "%s (%s) - `%s' saved [%ld]\n\n"
+msgstr "%s (%s) - «%s» lagret [%ld]\n\n"
 
-#: src/ftp.c:1294 src/main.c:948 src/recur.c:376 src/retr.c:842
+#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Fjerner %s.\n"
 
-#: src/ftp.c:1336
+#: src/ftp.c:1221
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Bruker «%s» som temporær katalogliste.\n"
 
-#: src/ftp.c:1351
+#: src/ftp.c:1233
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "Slettet «%s».\n"
 
-#: src/ftp.c:1386
+#: src/ftp.c:1269
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "Rekursjonsdybde %d overskred maksimal dybde %d.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1456
+#: src/ftp.c:1330
 #, fuzzy, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
 msgstr "Fil på tjener er nyere - hentes.\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1463
+#: src/ftp.c:1337
 #, fuzzy, c-format
-msgid ""
-"Remote file is newer than local file `%s' -- retrieving.\n"
-"\n"
+msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
 msgstr "Fil på tjener er nyere - hentes.\n"
 
 #. Sizes do not match
-#: src/ftp.c:1470
+#: src/ftp.c:1344
 #, fuzzy, c-format
-msgid ""
-"The sizes do not match (local %s) -- retrieving.\n"
-"\n"
+msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
 msgstr "Filstørrelsene er forskjellige (local %ld), hentes.\n"
 
-#: src/ftp.c:1488
+#: src/ftp.c:1361
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Ugyldig navn for symbolsk link, ignoreres.\n"
 
-#: src/ftp.c:1505
+#: src/ftp.c:1378
 #, c-format
-msgid ""
-"Already have correct symlink %s -> %s\n"
-"\n"
-msgstr ""
-"Har allerede gyldig symbolsk link %s -> %s\n"
-"\n"
+msgid "Already have correct symlink %s -> %s\n\n"
+msgstr "Har allerede gyldig symbolsk link %s -> %s\n\n"
 
-#: src/ftp.c:1513
+#: src/ftp.c:1386
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Lager symbolsk link %s -> %s\n"
 
-#: src/ftp.c:1523
+#: src/ftp.c:1397
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "Symbolske linker ikke støttet, ignorerer «%s».\n"
 
-#: src/ftp.c:1535
+#: src/ftp.c:1409
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Ignorerer katalog «%s».\n"
 
-#: src/ftp.c:1544
+#: src/ftp.c:1418
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: filtypen er ukjent/ikke støttet.\n"
 
-#: src/ftp.c:1571
+#: src/ftp.c:1445
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: ugyldig tidsstempel.\n"
 
-#: src/ftp.c:1599
+#: src/ftp.c:1466
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Henter ikke kataloger på dybde %d (max %d).\n"
 
-#: src/ftp.c:1649
+#: src/ftp.c:1512
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "Behandler ikke «%s» da det er ekskludert/ikke inkludert.\n"
 
-#: src/ftp.c:1715 src/ftp.c:1729
+#: src/ftp.c:1559
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Ignorerer «%s».\n"
