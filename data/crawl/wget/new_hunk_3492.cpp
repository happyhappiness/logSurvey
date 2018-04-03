msgid " (%s bytes)"
msgstr " (%s byte) "

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:187
#, c-format
msgid "Logging in as %s ... "
msgstr "Loggar in som %s... "

#: src/ftp.c:196 src/ftp.c:249 src/ftp.c:281 src/ftp.c:330 src/ftp.c:423
#: src/ftp.c:474 src/ftp.c:504 src/ftp.c:568 src/ftp.c:641 src/ftp.c:702
#: src/ftp.c:750
msgid "Error in server response, closing control connection.\n"
msgstr "Fel i serversvar, st�nger styrf�rbindelse.\n"

#: src/ftp.c:204
msgid "Error in server greeting.\n"
msgstr "Fel i serverh�lsning.\n"

#: src/ftp.c:212 src/ftp.c:339 src/ftp.c:432 src/ftp.c:513 src/ftp.c:578
#: src/ftp.c:651 src/ftp.c:712 src/ftp.c:760
msgid "Write failed, closing control connection.\n"
msgstr "Skrivning misslyckades, st�nger styrf�rbindelse.\n"

#: src/ftp.c:219
msgid "The server refuses login.\n"
msgstr "Inloggning nekas av servern.\n"

#: src/ftp.c:226
msgid "Login incorrect.\n"
msgstr "Felaktig inloggning.\n"

#: src/ftp.c:233
msgid "Logged in!\n"
msgstr "Inloggad!\n"

#: src/ftp.c:258
msgid "Server error, can't determine system type.\n"
msgstr "Serverfel, kan inte avg�ra systemtyp.\n"

#: src/ftp.c:268 src/ftp.c:553 src/ftp.c:625 src/ftp.c:682
msgid "done.    "
msgstr "f�rdig.  "

#: src/ftp.c:318 src/ftp.c:453 src/ftp.c:488 src/ftp.c:733 src/ftp.c:781
#: src/host.c:263
msgid "done.\n"
msgstr "f�rdig.\n"

#: src/ftp.c:347
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Typen \"%c\" �r ok�nd, st�nger styrf�rbindelse.\n"

#: src/ftp.c:360
msgid "done.  "
msgstr "f�rdig.  "

#: src/ftp.c:366
msgid "==> CWD not needed.\n"
msgstr "==> CWD beh�vs inte.\n"

#: src/ftp.c:439
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Katalogen \"%s\" finns inte.\n\n"

#. do not CWD
#: src/ftp.c:457
msgid "==> CWD not required.\n"
msgstr "==> CWD kr�vs inte.\n"

#: src/ftp.c:520
msgid "Cannot initiate PASV transfer.\n"
msgstr "Kan inte initiera PASV-�verf�ring.\n"

#: src/ftp.c:524
msgid "Cannot parse PASV response.\n"
msgstr "Kan inte tolka PASV-svar.\n"

#: src/ftp.c:545
#, c-format
msgid "couldn't connect to %s:%hu: %s\n"
msgstr "kunde inte ansluta till %s:%hu: %s\n"

#: src/ftp.c:595
#, c-format
msgid "Bind error (%s).\n"
msgstr "Bindningsfel (%s).\n"

#: src/ftp.c:611
msgid "Invalid PORT.\n"
msgstr "Felaktig PORT.\n"

#: src/ftp.c:664
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST misslyckades, kommer inte att klippa \"%s\".\n"

#: src/ftp.c:671
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST misslyckades, startar om fr�n b�rjan.\n"

#: src/ftp.c:720
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Filen \"%s\" finns inte.\n\n"

#: src/ftp.c:768
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Filen eller katalogen \"%s\" finns inte.\n\n"

#: src/ftp.c:852 src/ftp.c:860
#, c-format
msgid "Length: %s"
msgstr "L�ngd: %s"

#: src/ftp.c:854 src/ftp.c:862
#, c-format
msgid " [%s to go]"
msgstr " [%s kvar]"

#: src/ftp.c:864
msgid " (unauthoritative)\n"
msgstr " (ej auktoritativt)\n"

#: src/ftp.c:890
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, st�nger styrf�rbindelse.\n"

#: src/ftp.c:898
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Dataf�rbindelse: %s; "

#: src/ftp.c:915
msgid "Control connection closed.\n"
msgstr "Styrf�rbindelse st�ngd.\n"

#: src/ftp.c:933
msgid "Data transfer aborted.\n"
msgstr "Data�verf�ring avbruten.\n"

#: src/ftp.c:997
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Filen \"%s\" finns redan, h�mtar inte.\n"

#: src/ftp.c:1067 src/http.c:1538
#, c-format
msgid "(try:%2d)"
msgstr "(f�rs�k:%2d)"

#: src/ftp.c:1131 src/http.c:1797
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - \"%s\" sparad [%ld]\n\n"

#: src/ftp.c:1173 src/main.c:814 src/recur.c:336 src/retr.c:587
#, c-format
msgid "Removing %s.\n"
msgstr "Tar bort %s.\n"

#: src/ftp.c:1215
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Anv�nder \"%s\" som tempor�r listningsfil.\n"

#: src/ftp.c:1230
#, c-format
msgid "Removed `%s'.\n"
msgstr "Tog bort \"%s\".\n"

#: src/ftp.c:1265
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Rekursionsdjupet %d �verskred det maximala djupet %d.\n"
