#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.5.3\n"
"POT-Creation-Date: 1998-09-21 19:08+0200\n"
"PO-Revision-Date: 2000-10-23 11:04+02:00\n"
"Last-Translator: Karl Eichwalder <ke@suse.de>\n"
"Language-Team: German <de@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-1\n"
"Content-Transfer-Encoding: 8-bit\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:147 src/http.c:346
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Verbindungsaufbau zu %s:%hu... "

#: src/ftp.c:169 src/ftp.c:411 src/http.c:363
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Verbindung nach %s:%hu zurückgewiesen.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:190 src/http.c:374
msgid "connected!\n"
msgstr "verbunden!\n"

#: src/ftp.c:191
#, c-format
msgid "Logging in as %s ... "
msgstr "Anmelden als %s ... "

# Ist das gemeint?
#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
msgid "Error in server response, closing control connection.\n"
msgstr "Fehler bei der Antwort des Servers; Kontroll-Verbindung schließen.\n"

#: src/ftp.c:208
msgid "Error in server greeting.\n"
msgstr "Fehler bei der Begrüßung des Servers.\n"

#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
msgid "Write failed, closing control connection.\n"
msgstr "Schreiben schlug fehl; Kontroll-Verbindung schließen.\n"

#: src/ftp.c:223
msgid "The server refuses login.\n"
msgstr "Der Server verweigert das Anmelden.\n"

#: src/ftp.c:230
msgid "Login incorrect.\n"
msgstr "Fehler bei der Anmeldung.\n"

#: src/ftp.c:237
msgid "Logged in!\n"
msgstr "Angemeldet!\n"

#: src/ftp.c:270
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Unbekannte Art »%c«, schließe Kontroll-Verbindung.\n"

#: src/ftp.c:283
msgid "done.  "
msgstr "fertig.  "

#: src/ftp.c:289
msgid "==> CWD not needed.\n"
msgstr "==> CWD nicht notwendig.\n"

#: src/ftp.c:317
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Das Verzeichnis »%s« gibt es nicht.\n\n"

#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1431
msgid "done.\n"
msgstr "fertig.\n"

#. do not CWD
#: src/ftp.c:335
msgid "==> CWD not required.\n"
msgstr "==> CWD nicht erforderlich.\n"

#: src/ftp.c:369
msgid "Cannot initiate PASV transfer.\n"
msgstr "Kann PASV-Übertragung nicht beginnen.\n"

#: src/ftp.c:373
msgid "Cannot parse PASV response.\n"
msgstr "Kann PASV-Antwort nicht auswerten.\n"

#: src/ftp.c:387
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Versuche Verbindung zu %s:%hu herzustellen.\n"

#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
msgid "done.    "
msgstr "fertig.    "

#: src/ftp.c:474
#, c-format
msgid "Bind error (%s).\n"
msgstr "Verbindungsfehler (%s).\n"

#: src/ftp.c:490
msgid "Invalid PORT.\n"
msgstr "Ungültiger PORT.\n"

#: src/ftp.c:537
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST schlug fehl; noch einmal von vorn beginnen.\n"

#: src/ftp.c:586
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Die Datei »%s« gibt es nicht.\n\n"

#: src/ftp.c:634
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Die Datei oder das Verzeichnis »%s« gibt es nicht.\n\n"

#: src/ftp.c:692 src/ftp.c:699
#, c-format
msgid "Length: %s"
msgstr "Länge: %s"

#: src/ftp.c:694 src/ftp.c:701
#, c-format
msgid " [%s to go]"
msgstr " [noch %s]"

# wohl "unmaßgeblich", nicht "ohne Berechtigung"
#: src/ftp.c:703
msgid " (unauthoritative)\n"
msgstr " (unmaßgeblich)\n"

#: src/ftp.c:721
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s; Kontroll-Verbindung schließen.\n"

#: src/ftp.c:729
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Daten-Verbindung: %s; "

#: src/ftp.c:746
msgid "Control connection closed.\n"
msgstr "Kontroll-Verbindung geschlossen.\n"

#: src/ftp.c:764
msgid "Data transfer aborted.\n"
msgstr "Daten-Übertragung abgeschlossen.\n"

#: src/ftp.c:830
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Die Datei »%s« ist schon vorhanden, kein erneuter Download.\n"

#: src/ftp.c:896 src/http.c:922
#, c-format
msgid "(try:%2d)"
msgstr "(versuche:%2d)"

# oder "gesichert"?
#: src/ftp.c:955 src/http.c:1116
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - »%s« gespeichert [%ld]\n\n"

#: src/ftp.c:1001
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "»%s« als temporäre Auflistungsdatei benutzen.\n"

#: src/ftp.c:1013
#, c-format
msgid "Removed `%s'.\n"
msgstr "»%s« gelöscht.\n"

#: src/ftp.c:1049
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Die Rekursionstiefe %d übersteigt die max. erlaubte Tiefe %d.\n"

#: src/ftp.c:1096 src/http.c:1054
#, c-format
msgid "Local file `%s' is more recent, not retrieving.\n\n"
msgstr "Lokale Datei »%s« ist neuer, kein erneuter Download.\n\n"

#: src/ftp.c:1102 src/http.c:1060
#, c-format
msgid "The sizes do not match (local %ld), retrieving.\n"
msgstr "Größen stimmen nicht überein (lokal %ld), erneuter Download.\n"

#: src/ftp.c:1119
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Ungültiger Name für einen symbolischen Verweis; übersprungen.\n"

#: src/ftp.c:1136
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Der richtige symbolische Verweis %s -> %s ist schon vorhanden.\n"

#: src/ftp.c:1144
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Symbolischen Verweis %s -> %s anlegen.\n"

#: src/ftp.c:1155
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Symbolischer Verweis nicht möglich; symbolischer Verweis »%s« übersprungen.\n"

#: src/ftp.c:1167
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Verzeichnis »%s« übersprungen.\n"

#: src/ftp.c:1176
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: unbekannter/nicht unterstüzter Dateityp.\n"

#: src/ftp.c:1193
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: beschädigter Zeitstempel.\n"

#: src/ftp.c:1213
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Verzeichnisse nicht erneut holen; da die Tiefe bereits %d ist (max. erlaubt %d).\n"

#: src/ftp.c:1252
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Nicht zu »%s« hinabsteigen, da es ausgeschlossen bzw. nicht eingeschlossen ist.\n"

#: src/ftp.c:1297
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "»%s« zurückgewiesen.\n"
