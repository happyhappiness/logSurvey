#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.7-dev\n"
"POT-Creation-Date: 2000-11-24 05:09+0100\n"
"PO-Revision-Date: 2000-11-24 06:20+01:00\n"
"Last-Translator: Karl Eichwalder <ke@suse.de>\n"
"Language-Team: German <de@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-1\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/ftp-ls.c:534 src/ftp-ls.c:536 src/html.c:615 src/html.c:617
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Index von /%s auf %s:%d"

#: src/ftp-ls.c:558 src/html.c:639
msgid "time unknown       "
msgstr "Zeit unbekannt     "

#: src/ftp-ls.c:562 src/html.c:643
msgid "File        "
msgstr "Datei       "

#: src/ftp-ls.c:565 src/html.c:646
msgid "Directory   "
msgstr "Verzeichnis "

#: src/ftp-ls.c:568 src/html.c:649
msgid "Link        "
msgstr "Verweis     "

#: src/ftp-ls.c:571 src/html.c:652
msgid "Not sure    "
msgstr "Nicht sicher"

#: src/ftp-ls.c:589 src/html.c:670
#, c-format
msgid " (%s bytes)"
msgstr " (%s Bytes)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:152 src/http.c:517
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Verbindungsaufbau zu %s:%hu... "

#: src/ftp.c:174 src/ftp.c:518 src/http.c:534
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Verbindung nach %s:%hu zurückgewiesen.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:195 src/http.c:545
msgid "connected!\n"
msgstr "verbunden!\n"

#: src/ftp.c:196
#, c-format
msgid "Logging in as %s ... "
msgstr "Anmelden als %s ... "

# Ist das gemeint?
#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:289 src/ftp.c:314 src/ftp.c:408
#: src/ftp.c:460 src/ftp.c:554 src/ftp.c:627 src/ftp.c:675 src/ftp.c:723
msgid "Error in server response, closing control connection.\n"
msgstr "Fehler bei der Antwort des Servers; Kontroll-Verbindung schließen.\n"

#: src/ftp.c:213
msgid "Error in server greeting.\n"
msgstr "Fehler bei der Begrüßung des Servers.\n"

#: src/ftp.c:221 src/ftp.c:323 src/ftp.c:417 src/ftp.c:469 src/ftp.c:564
#: src/ftp.c:637 src/ftp.c:685 src/ftp.c:733
msgid "Write failed, closing control connection.\n"
msgstr "Schreiben schlug fehl; Kontroll-Verbindung schließen.\n"

#: src/ftp.c:228
msgid "The server refuses login.\n"
msgstr "Der Server verweigert das Anmelden.\n"

#: src/ftp.c:235
msgid "Login incorrect.\n"
msgstr "Fehler bei der Anmeldung.\n"

#: src/ftp.c:242
msgid "Logged in!\n"
msgstr "Angemeldet!\n"

#: src/ftp.c:267
msgid "Server error, can't determine system type.\n"
msgstr "Fehler beim Server; Systemtyp nicht feststellbar.\n"

#: src/ftp.c:277 src/ftp.c:539 src/ftp.c:611 src/ftp.c:655
msgid "done.    "
msgstr "fertig.    "

#: src/ftp.c:303 src/ftp.c:438 src/ftp.c:706 src/ftp.c:754 src/url.c:1423
msgid "done.\n"
msgstr "fertig.\n"

#: src/ftp.c:331
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Unbekannte Art »%c«, schließe Kontroll-Verbindung.\n"

#: src/ftp.c:344
msgid "done.  "
msgstr "fertig.  "

#: src/ftp.c:350
msgid "==> CWD not needed.\n"
msgstr "==> CWD nicht notwendig.\n"

#: src/ftp.c:424
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Das Verzeichnis »%s« gibt es nicht.\n"
"\n"

#. do not CWD
#: src/ftp.c:442
msgid "==> CWD not required.\n"
msgstr "==> CWD nicht erforderlich.\n"

#: src/ftp.c:476
msgid "Cannot initiate PASV transfer.\n"
msgstr "Kann PASV-Übertragung nicht beginnen.\n"

#: src/ftp.c:480
msgid "Cannot parse PASV response.\n"
msgstr "Kann PASV-Antwort nicht auswerten.\n"

#: src/ftp.c:494
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Versuche Verbindung zu %s:%hu herzustellen.\n"

#: src/ftp.c:581
#, c-format
msgid "Bind error (%s).\n"
msgstr "Verbindungsfehler (%s).\n"

#: src/ftp.c:597
msgid "Invalid PORT.\n"
msgstr "Ungültiger PORT.\n"

#: src/ftp.c:644
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST schlug fehl; noch einmal von vorn beginnen.\n"

#: src/ftp.c:693
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Die Datei »%s« gibt es nicht.\n"
"\n"

#: src/ftp.c:741
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Die Datei oder das Verzeichnis »%s« gibt es nicht.\n"
"\n"

#: src/ftp.c:817 src/ftp.c:824
#, c-format
msgid "Length: %s"
msgstr "Länge: %s"

#: src/ftp.c:819 src/ftp.c:826
#, c-format
msgid " [%s to go]"
msgstr " [noch %s]"

# wohl "unmaßgeblich", nicht "ohne Berechtigung"
#: src/ftp.c:828
msgid " (unauthoritative)\n"
msgstr " (unmaßgeblich)\n"

#: src/ftp.c:854
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s; Kontroll-Verbindung schließen.\n"

#: src/ftp.c:862
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Daten-Verbindung: %s; "

#: src/ftp.c:879
msgid "Control connection closed.\n"
msgstr "Kontroll-Verbindung geschlossen.\n"

#: src/ftp.c:897
msgid "Data transfer aborted.\n"
msgstr "Daten-Übertragung abgeschlossen.\n"

#: src/ftp.c:963
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Die Datei »%s« ist schon vorhanden, kein erneuter Download.\n"

#: src/ftp.c:1040 src/http.c:1283
#, c-format, ycp-format
msgid "(try:%2d)"
msgstr "(versuche:%2d)"

# oder "gesichert"?
#: src/ftp.c:1104 src/http.c:1503
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""
"%s (%s) - »%s« gespeichert [%ld]\n"
"\n"

#: src/ftp.c:1146 src/main.c:771 src/recur.c:505 src/retr.c:568
#, c-format
msgid "Removing %s.\n"
msgstr "Entferne »%s«.\n"

#: src/ftp.c:1187
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "»%s« als temporäre Auflistungsdatei benutzen.\n"

#: src/ftp.c:1199
#, c-format
msgid "Removed `%s'.\n"
msgstr "»%s« gelöscht.\n"

#: src/ftp.c:1235
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Die Rekursionstiefe %d übersteigt die max. erlaubte Tiefe %d.\n"

#: src/ftp.c:1287
#, c-format
msgid ""
"Server file not newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr "Datei auf dem Server nicht neuer als die lokale Datei `%s' -- kein Download.\n\n"

#: src/ftp.c:1295
msgid "Cannot compare sizes, remote system is VMS.\n"
msgstr "Größe nicht bestimmbar; das System der Gegenseite ist VMS.\n"

#: src/ftp.c:1301 src/http.c:1438
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Größen stimmen nicht überein (lokal %ld) -- erneuter Download.\n"

#: src/ftp.c:1319
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Ungültiger Name für einen symbolischen Verweis; übersprungen.\n"

#: src/ftp.c:1336
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr "Der richtige symbolische Verweis %s -> %s ist schon vorhanden.\n"

#: src/ftp.c:1344
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Symbolischen Verweis %s -> %s anlegen.\n"

#: src/ftp.c:1355
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""
"Symbolischer Verweis nicht möglich; symbolischer Verweis »%s« übersprungen.\n"

#: src/ftp.c:1367
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Verzeichnis »%s« übersprungen.\n"

#: src/ftp.c:1376
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: unbekannter/nicht unterstüzter Dateityp.\n"

#: src/ftp.c:1393
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: beschädigter Zeitstempel.\n"

#: src/ftp.c:1414
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""
"Verzeichnisse nicht erneut holen; da die Tiefe bereits %d ist (max. erlaubt "
"%d).\n"

#: src/ftp.c:1453
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr ""
"Nicht zu »%s« hinabsteigen, da es ausgeschlossen bzw. nicht eingeschlossen "
"ist.\n"

#: src/ftp.c:1498
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "»%s« zurückgewiesen.\n"
