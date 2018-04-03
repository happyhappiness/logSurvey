#
msgid ""
msgstr ""
"Project-Id-Version: GNU Wget 1.7-dev\n"
"POT-Creation-Date: 2001-02-23 13:23-0800\n"
"PO-Revision-Date: 2000-11-24 06:20+01:00\n"
"Last-Translator: Karl Eichwalder <ke@suse.de>\n"
"Language-Team: German <de@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-1\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/ftp-ls.c:779
msgid "Usupported listing type, trying Unix listing parser.\n"
msgstr ""

#: src/ftp-ls.c:824 src/ftp-ls.c:826
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Index von /%s auf %s:%d"

#: src/ftp-ls.c:848
msgid "time unknown       "
msgstr "Zeit unbekannt     "

#: src/ftp-ls.c:852
msgid "File        "
msgstr "Datei       "

#: src/ftp-ls.c:855
msgid "Directory   "
msgstr "Verzeichnis "

#: src/ftp-ls.c:858
msgid "Link        "
msgstr "Verweis     "

#: src/ftp-ls.c:861
msgid "Not sure    "
msgstr "Nicht sicher"

#: src/ftp-ls.c:879
#, c-format
msgid " (%s bytes)"
msgstr " (%s Bytes)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:151 src/http.c:618
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Verbindungsaufbau zu %s:%hu... "

#: src/ftp.c:173 src/ftp.c:517 src/http.c:635
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Verbindung nach %s:%hu zurückgewiesen.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:194 src/http.c:646
msgid "connected!\n"
msgstr "verbunden!\n"

#: src/ftp.c:195
#, c-format
msgid "Logging in as %s ... "
msgstr "Anmelden als %s ... "

# Ist das gemeint?
#: src/ftp.c:204 src/ftp.c:257 src/ftp.c:288 src/ftp.c:313 src/ftp.c:407
#: src/ftp.c:459 src/ftp.c:553 src/ftp.c:626 src/ftp.c:674 src/ftp.c:722
msgid "Error in server response, closing control connection.\n"
msgstr "Fehler bei der Antwort des Servers; Kontroll-Verbindung schließen.\n"

#: src/ftp.c:212
msgid "Error in server greeting.\n"
msgstr "Fehler bei der Begrüßung des Servers.\n"

#: src/ftp.c:220 src/ftp.c:322 src/ftp.c:416 src/ftp.c:468 src/ftp.c:563
#: src/ftp.c:636 src/ftp.c:684 src/ftp.c:732
msgid "Write failed, closing control connection.\n"
msgstr "Schreiben schlug fehl; Kontroll-Verbindung schließen.\n"

#: src/ftp.c:227
msgid "The server refuses login.\n"
msgstr "Der Server verweigert das Anmelden.\n"

#: src/ftp.c:234
msgid "Login incorrect.\n"
msgstr "Fehler bei der Anmeldung.\n"

#: src/ftp.c:241
msgid "Logged in!\n"
msgstr "Angemeldet!\n"

#: src/ftp.c:266
msgid "Server error, can't determine system type.\n"
msgstr "Fehler beim Server; Systemtyp nicht feststellbar.\n"

#: src/ftp.c:276 src/ftp.c:538 src/ftp.c:610 src/ftp.c:654
msgid "done.    "
msgstr "fertig.    "

#: src/ftp.c:302 src/ftp.c:437 src/ftp.c:705 src/ftp.c:753 src/url.c:1432
msgid "done.\n"
msgstr "fertig.\n"

#: src/ftp.c:330
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Unbekannte Art »%c«, schließe Kontroll-Verbindung.\n"

#: src/ftp.c:343
msgid "done.  "
msgstr "fertig.  "

#: src/ftp.c:349
msgid "==> CWD not needed.\n"
msgstr "==> CWD nicht notwendig.\n"

#: src/ftp.c:423
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Das Verzeichnis »%s« gibt es nicht.\n"
"\n"

#. do not CWD
#: src/ftp.c:441
msgid "==> CWD not required.\n"
msgstr "==> CWD nicht erforderlich.\n"

#: src/ftp.c:475
msgid "Cannot initiate PASV transfer.\n"
msgstr "Kann PASV-Übertragung nicht beginnen.\n"

#: src/ftp.c:479
msgid "Cannot parse PASV response.\n"
msgstr "Kann PASV-Antwort nicht auswerten.\n"

#: src/ftp.c:493
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Versuche Verbindung zu %s:%hu herzustellen.\n"

#: src/ftp.c:580
#, c-format
msgid "Bind error (%s).\n"
msgstr "Verbindungsfehler (%s).\n"

#: src/ftp.c:596
msgid "Invalid PORT.\n"
msgstr "Ungültiger PORT.\n"

#: src/ftp.c:643
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST schlug fehl; noch einmal von vorn beginnen.\n"

#: src/ftp.c:692
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Die Datei »%s« gibt es nicht.\n"
"\n"

#: src/ftp.c:740
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Die Datei oder das Verzeichnis »%s« gibt es nicht.\n"
"\n"

#: src/ftp.c:816 src/ftp.c:823
#, c-format
msgid "Length: %s"
msgstr "Länge: %s"

#: src/ftp.c:818 src/ftp.c:825
#, c-format
msgid " [%s to go]"
msgstr " [noch %s]"

# wohl "unmaßgeblich", nicht "ohne Berechtigung"
#: src/ftp.c:827
msgid " (unauthoritative)\n"
msgstr " (unmaßgeblich)\n"

#: src/ftp.c:853
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s; Kontroll-Verbindung schließen.\n"

#: src/ftp.c:861
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Daten-Verbindung: %s; "

#: src/ftp.c:878
msgid "Control connection closed.\n"
msgstr "Kontroll-Verbindung geschlossen.\n"

#: src/ftp.c:896
msgid "Data transfer aborted.\n"
msgstr "Daten-Übertragung abgeschlossen.\n"

#: src/ftp.c:960
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Die Datei »%s« ist schon vorhanden, kein erneuter Download.\n"

#: src/ftp.c:1021 src/http.c:1394
#, c-format
msgid "(try:%2d)"
msgstr "(versuche:%2d)"

# oder "gesichert"?
#: src/ftp.c:1085 src/http.c:1632
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""
"%s (%s) - »%s« gespeichert [%ld]\n"
"\n"

#: src/ftp.c:1127 src/main.c:789 src/recur.c:509 src/retr.c:602
#, c-format
msgid "Removing %s.\n"
msgstr "Entferne »%s«.\n"

#: src/ftp.c:1168
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "»%s« als temporäre Auflistungsdatei benutzen.\n"

#: src/ftp.c:1180
#, c-format
msgid "Removed `%s'.\n"
msgstr "»%s« gelöscht.\n"

#: src/ftp.c:1216
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Die Rekursionstiefe %d übersteigt die max. erlaubte Tiefe %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1277
#, fuzzy, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr ""
"Datei auf dem Server nicht neuer als die lokale Datei `%s' -- kein "
"Download.\n"
"\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1284
#, fuzzy, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr ""
"Datei auf dem Server nicht neuer als die lokale Datei `%s' -- kein "
"Download.\n"
"\n"

#. Sizes do not match
#: src/ftp.c:1291
#, fuzzy, c-format
msgid ""
"The sizes do not match (local %ld) -- retrieving.\n"
"\n"
msgstr "Größen stimmen nicht überein (lokal %ld) -- erneuter Download.\n"

#: src/ftp.c:1308
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Ungültiger Name für einen symbolischen Verweis; übersprungen.\n"

#: src/ftp.c:1325
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr "Der richtige symbolische Verweis %s -> %s ist schon vorhanden.\n"

#: src/ftp.c:1333
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Symbolischen Verweis %s -> %s anlegen.\n"

#: src/ftp.c:1344
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""
"Symbolischer Verweis nicht möglich; symbolischer Verweis »%s« übersprungen.\n"

#: src/ftp.c:1356
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Verzeichnis »%s« übersprungen.\n"

#: src/ftp.c:1365
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: unbekannter/nicht unterstüzter Dateityp.\n"

#: src/ftp.c:1392
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: beschädigter Zeitstempel.\n"

#: src/ftp.c:1413
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""
"Verzeichnisse nicht erneut holen; da die Tiefe bereits %d ist (max. erlaubt "
"%d).\n"

#: src/ftp.c:1449
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr ""
"Nicht zu »%s« hinabsteigen, da es ausgeschlossen bzw. nicht eingeschlossen "
"ist.\n"

#: src/ftp.c:1494
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "»%s« zurückgewiesen.\n"
