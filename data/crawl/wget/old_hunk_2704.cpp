"Content-Type: text/plain; charset=iso-8859-1\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/connect.c:199
#, c-format
msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
msgstr ""

#: src/connect.c:271
#, fuzzy, c-format
msgid "Connecting to %s|%s|:%d... "
msgstr "Kontakter %s[%s]:%hu... "

#: src/connect.c:274
#, fuzzy, c-format
msgid "Connecting to %s:%d... "
msgstr "Kontakter %s:%hu... "

#: src/connect.c:335
msgid "connected.\n"
msgstr "forbundet.\n"

#: src/convert.c:176
#, fuzzy, c-format
msgid "Converted %d files in %.*f seconds.\n"
msgstr "Konverterede %d filer på %.2f sekunder.\n"

#: src/convert.c:202
#, c-format
msgid "Converting %s... "
msgstr "Konverterer %s... "

#: src/convert.c:215
msgid "nothing to do.\n"
msgstr "ingenting at gøre.\n"

#: src/convert.c:223 src/convert.c:247
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "Kan ikke konvertere lænker i %s: %s\n"

#: src/convert.c:238
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "Kan ikke slette '%s': %s\n"

#: src/convert.c:447
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "Kan ikke sikkerhedskopiere %s som %s: %s\n"

#: src/cookies.c:619
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "fejl ved Set-Cookie, felt '%s'"

#: src/cookies.c:643
#, fuzzy, c-format
msgid "Syntax error in Set-Cookie: %s at position %d.\n"
msgstr "Syntaksfejl i Set-Cookie: streng afsluttet for tidligt.\n"

#: src/cookies.c:1469
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Kan ikke åbne infokagefil %s: %s\n"

#: src/cookies.c:1481
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Fejl ved skrivning til '%s' %s\n"

#: src/cookies.c:1484
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Fejl ved lukning af '%s': %s\n"

#: src/ftp-ls.c:841
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Ikke-understøttet listningstype, prøver Unix-listningsfortolker.\n"

#: src/ftp-ls.c:887 src/ftp-ls.c:889
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Indeks for /%s på %s:%d"

#: src/ftp-ls.c:912
#, c-format
msgid "time unknown       "
msgstr "ukendt tid         "

#: src/ftp-ls.c:916
#, c-format
msgid "File        "
msgstr "Fil         "

#: src/ftp-ls.c:919
#, c-format
msgid "Directory   "
msgstr "Katalog     "

#: src/ftp-ls.c:922
#, c-format
msgid "Link        "
msgstr "Link        "

#: src/ftp-ls.c:925
#, c-format
msgid "Not sure    "
msgstr "Usikker     "

#: src/ftp-ls.c:943
#, c-format
msgid " (%s bytes)"
msgstr " (%s byte)"

#: src/ftp.c:226
#, c-format
msgid "Length: %s"
msgstr "Længde: %s"

#: src/ftp.c:232 src/http.c:1857
#, c-format
msgid ", %s (%s) remaining"
msgstr ""

#: src/ftp.c:236 src/http.c:1861
#, c-format
msgid ", %s remaining"
msgstr ""

#: src/ftp.c:239
msgid " (unauthoritative)\n"
msgstr " (ikke endegyldigt)\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:314
#, c-format
msgid "Logging in as %s ... "
msgstr "Logger ind som %s ... "

#: src/ftp.c:327 src/ftp.c:373 src/ftp.c:402 src/ftp.c:454 src/ftp.c:566
#: src/ftp.c:612 src/ftp.c:640 src/ftp.c:698 src/ftp.c:759 src/ftp.c:819
#: src/ftp.c:866
msgid "Error in server response, closing control connection.\n"
msgstr "Fejl i svar fra server, lukker kontrolforbindelsen.\n"

#: src/ftp.c:334
msgid "Error in server greeting.\n"
msgstr "Fejl i velkomsthilsen fra server.\n"

#: src/ftp.c:341 src/ftp.c:462 src/ftp.c:574 src/ftp.c:648 src/ftp.c:708
#: src/ftp.c:769 src/ftp.c:829 src/ftp.c:876
msgid "Write failed, closing control connection.\n"
msgstr "Fejl ved skrivning, lukker kontrolforbindelsen.\n"

#: src/ftp.c:347
msgid "The server refuses login.\n"
msgstr "Serveren tillader ikke indlogning.\n"

#: src/ftp.c:353
msgid "Login incorrect.\n"
msgstr "Fejl ved indlogging.\n"

#: src/ftp.c:359
msgid "Logged in!\n"
msgstr "Logget ind!\n"

#: src/ftp.c:381
msgid "Server error, can't determine system type.\n"
msgstr "Serverfejl, kan ikke bestemme systemtype.\n"

#: src/ftp.c:390 src/ftp.c:685 src/ftp.c:742 src/ftp.c:785
msgid "done.    "
msgstr "færdig.      "

#: src/ftp.c:442 src/ftp.c:591 src/ftp.c:624 src/ftp.c:849 src/ftp.c:895
msgid "done.\n"
msgstr "O.k.\n"

#: src/ftp.c:469
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Ukendt type '%c', lukker kontrolforbindelsen.\n"

#: src/ftp.c:481
msgid "done.  "
msgstr "O.k.    "

#: src/ftp.c:487
msgid "==> CWD not needed.\n"
msgstr "==> CWD ikke nødvendig.\n"

#: src/ftp.c:580
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Intet katalog ved navn '%s'.\n"
"\n"

#. do not CWD
#: src/ftp.c:595
msgid "==> CWD not required.\n"
msgstr "==> CWD ikke nødvendig.\n"

#: src/ftp.c:654
msgid "Cannot initiate PASV transfer.\n"
msgstr "Kan ikke opsætte PASV-overførsel.\n"

#: src/ftp.c:658
msgid "Cannot parse PASV response.\n"
msgstr "Kan ikke tolke PASV-tilbagemelding.\n"

#: src/ftp.c:676
#, fuzzy, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr "kunne ikke forbinde til %s:%hu: %s\n"

#: src/ftp.c:724
#, c-format
msgid "Bind error (%s).\n"
msgstr "Bind-fejl (%s).\n"

#: src/ftp.c:730
msgid "Invalid PORT.\n"
msgstr "Ugyldig PORT.\n"

#: src/ftp.c:776
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"Fejl ved REST, starter forfra.\n"

#: src/ftp.c:837
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Ingen fil ved navn '%s'.\n"
"\n"

#: src/ftp.c:884
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Ingen fil eller katalog ved navn '%s'.\n"
"\n"

#. We cannot just invent a new name and use it (which is
#. what functions like unique_create typically do)
#. because we told the user we'd use this name.
#. Instead, return and retry the download.
#: src/ftp.c:946 src/http.c:1913
#, c-format
msgid "%s has sprung into existence.\n"
msgstr ""

#: src/ftp.c:1008
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, lukker kontrolforbindelsen.\n"

#: src/ftp.c:1016
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - dataforbindelse: %s; "

#: src/ftp.c:1031
msgid "Control connection closed.\n"
msgstr "Forbindelsen lukket.\n"

#: src/ftp.c:1049
msgid "Data transfer aborted.\n"
msgstr "Dataoverførsel afbrudt.\n"

#: src/ftp.c:1114
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "File '%s' eksisterer allerede, hentes ikke.\n"

#: src/ftp.c:1182 src/http.c:2130
#, c-format
msgid "(try:%2d)"
msgstr "(forsøg:%2d)"

#: src/ftp.c:1252 src/http.c:2409
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s]\n"
"\n"
msgstr ""
"%s (%s) - '%s' gemt [%ld]\n"
"\n"

#: src/ftp.c:1294 src/main.c:948 src/recur.c:376 src/retr.c:842
#, c-format
msgid "Removing %s.\n"
msgstr "Fjerner %s.\n"

#: src/ftp.c:1336
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Bruger '%s' som midlertidig katalogliste.\n"

#: src/ftp.c:1351
#, c-format
msgid "Removed `%s'.\n"
msgstr "Slettet '%s'.\n"

#: src/ftp.c:1386
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Rekursionsdybde %d overskred maksimal dybde %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1456
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr ""
"Fjernfil ikke nyere end lokal fil '%s' - hentes ikke.\n"
"\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1463
#, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr ""
"Fjernfil er nyere end lokal fil '%s' - hentes.\n"
"\n"

#. Sizes do not match
#: src/ftp.c:1470
#, fuzzy, c-format
msgid ""
"The sizes do not match (local %s) -- retrieving.\n"
"\n"
msgstr "Størrelserne er forskellige (lokal %ld) - hentes.\n"

#: src/ftp.c:1488
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Ugyldigt navn for symbolsk lænke, ignoreres.\n"

#: src/ftp.c:1505
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"Har allerede gyldig symbolsk lænke %s -> %s\n"
"\n"

#: src/ftp.c:1513
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Laver symbolsk lænke %s -> %s\n"

#: src/ftp.c:1523
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Symbolske lænker ikke understøttet, ignorerer '%s'.\n"

#: src/ftp.c:1535
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Ignorerer katalog '%s'.\n"

#: src/ftp.c:1544
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: filtypen er ukendt/ikke understøttet.\n"

#: src/ftp.c:1571
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: ugyldigt tidsstempel.\n"

#: src/ftp.c:1599
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Henter ikke kataloger, da dybde er %d (max %d).\n"

#: src/ftp.c:1649
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Behandler ikke '%s' da det er ekskluderet/ikke inkluderet.\n"

#: src/ftp.c:1715 src/ftp.c:1729
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Ignorerer '%s'.\n"
