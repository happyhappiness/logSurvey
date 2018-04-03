msgid " (unauthoritative)\n"
msgstr " (není směrodatné)\n"

#: src/ftp.c:305
#, c-format
msgid "Logging in as %s ... "
msgstr "Probíhá přihlašování jako %s… "

#: src/ftp.c:319 src/ftp.c:365 src/ftp.c:394 src/ftp.c:446 src/ftp.c:559
#: src/ftp.c:606 src/ftp.c:635 src/ftp.c:692 src/ftp.c:753 src/ftp.c:839
#: src/ftp.c:886
msgid "Error in server response, closing control connection.\n"
msgstr ""
"Řídicí spojení bude ukončeno, protože server odpověděl chybovým hlášením.\n"

#: src/ftp.c:326
msgid "Error in server greeting.\n"
msgstr "Úvodní odpověď serveru je chybná.\n"

#: src/ftp.c:333 src/ftp.c:454 src/ftp.c:567 src/ftp.c:643 src/ftp.c:702
#: src/ftp.c:763 src/ftp.c:849 src/ftp.c:896
msgid "Write failed, closing control connection.\n"
msgstr "Řídicí spojení bude ukončeno, protože nelze zapsat data.\n"

#: src/ftp.c:339
msgid "The server refuses login.\n"
msgstr "Server odmítá přihlášení.\n"

#: src/ftp.c:345
msgid "Login incorrect.\n"
msgstr "Chyba při přihlášení.\n"

#: src/ftp.c:351
msgid "Logged in!\n"
msgstr "Přihlášeno!\n"

#: src/ftp.c:373
msgid "Server error, can't determine system type.\n"
msgstr ""
"Nelze zjistit typ vzdáleného operačního systému, protože server odpověděl "
"chybovým hlášením.\n"

#: src/ftp.c:382 src/ftp.c:679 src/ftp.c:736 src/ftp.c:779
msgid "done.    "
msgstr "hotovo.  "

#: src/ftp.c:434 src/ftp.c:584 src/ftp.c:618 src/ftp.c:869 src/ftp.c:915
msgid "done.\n"
msgstr "hotovo.\n"

#: src/ftp.c:461
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr ""
"Řídicí spojení bude ukončeno, protože je požadován neznámý typ přenosu „%"
"c“.\n"

#: src/ftp.c:473
msgid "done.  "
msgstr "hotovo."

#: src/ftp.c:479
msgid "==> CWD not needed.\n"
msgstr "==> CWD není potřeba.\n"

#: src/ftp.c:573
#, fuzzy, c-format
msgid ""
"No such directory %s.\n"
"\n"
msgstr ""
"Adresář „%s“ neexistuje.\n"
"\n"

#: src/ftp.c:588
msgid "==> CWD not required.\n"
msgstr "==> CWD není potřeba.\n"

#: src/ftp.c:649
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nelze spustit pasivní přenos dat.\n"

#: src/ftp.c:653
msgid "Cannot parse PASV response.\n"
msgstr "Odpověď na PASV není pochopitelná.\n"

#: src/ftp.c:670
#, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr "s %s na portu %d se nelze spojit: %s\n"

#: src/ftp.c:718
#, c-format
msgid "Bind error (%s).\n"
msgstr "Chyba při přilepování (bind) (%s).\n"

#: src/ftp.c:724
msgid "Invalid PORT.\n"
msgstr "Neplatný PORT.\n"

#: src/ftp.c:770
msgid ""
"\n"
"REST failed, starting from scratch.\n"
