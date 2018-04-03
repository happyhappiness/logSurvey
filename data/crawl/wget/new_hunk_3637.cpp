#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.7-pre1\n"
"POT-Creation-Date: 2001-05-26 11:07+0200\n"
"PO-Revision-Date: 2001-06-03 08:24+0200\n"
"Last-Translator: Karl Eichwalder <ke@suse.de>\n"
"Language-Team: German <de@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-1\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/cookies.c:588
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Fehler bei Set-Cookie, Feld »%s«"

#: src/cookies.c:612
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Syntaxfehler bei Set-Cookie beim Zeichen »%c«.\n"

#: src/cookies.c:620
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Syntaxfehler bei Set-Cookie, Zeichenkette vorzeitig zu Ende.\n"

#: src/cookies.c:1352
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Cookie-Datei kann nicht geöffnet werden »%s«: %s\n"

#: src/cookies.c:1364
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Fehler beim Schreiben nach »%s«: %s.\n"

#: src/cookies.c:1368
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Fehler beim Schließen von »%s«: %s.\n"

#: src/ftp-ls.c:787
msgid "Usupported listing type, trying Unix listing parser.\n"
msgstr "Nicht unterstützte Art der Auflistung; Versuch Unix-Auflistung zu verwenden.\n"

#: src/ftp-ls.c:832 src/ftp-ls.c:834
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Index von /%s auf %s:%d"

#: src/ftp-ls.c:856
msgid "time unknown       "
msgstr "Zeit unbekannt     "

#: src/ftp-ls.c:860
msgid "File        "
msgstr "Datei       "

#: src/ftp-ls.c:863
msgid "Directory   "
msgstr "Verzeichnis "

#: src/ftp-ls.c:866
msgid "Link        "
msgstr "Verweis     "

#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "Nicht sicher"

#: src/ftp-ls.c:887
#, c-format
msgid " (%s bytes)"
msgstr " (%s Bytes)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:149 src/http.c:623
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Verbindungsaufbau zu %s:%hu... "

#: src/ftp.c:171 src/ftp.c:538 src/http.c:640
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Verbindung nach %s:%hu zurückgewiesen.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:192 src/http.c:651
msgid "connected!\n"
msgstr "verbunden!\n"

#: src/ftp.c:193
#, c-format
msgid "Logging in as %s ... "
msgstr "Anmelden als %s ... "

# Ist das gemeint?
#: src/ftp.c:202 src/ftp.c:255 src/ftp.c:287 src/ftp.c:335 src/ftp.c:428
#: src/ftp.c:480 src/ftp.c:574 src/ftp.c:647 src/ftp.c:708 src/ftp.c:756
msgid "Error in server response, closing control connection.\n"
msgstr "Fehler bei der Antwort des Servers; Kontroll-Verbindung schließen.\n"

#: src/ftp.c:210
msgid "Error in server greeting.\n"
msgstr "Fehler bei der Begrüßung des Servers.\n"

#: src/ftp.c:218 src/ftp.c:344 src/ftp.c:437 src/ftp.c:489 src/ftp.c:584
#: src/ftp.c:657 src/ftp.c:718 src/ftp.c:766
msgid "Write failed, closing control connection.\n"
msgstr "Schreiben schlug fehl; Kontroll-Verbindung schließen.\n"

#: src/ftp.c:225
msgid "The server refuses login.\n"
msgstr "Der Server verweigert das Anmelden.\n"

#: src/ftp.c:232
msgid "Login incorrect.\n"
msgstr "Fehler bei der Anmeldung.\n"

#: src/ftp.c:239
msgid "Logged in!\n"
msgstr "Angemeldet!\n"

#: src/ftp.c:264
msgid "Server error, can't determine system type.\n"
msgstr "Fehler beim Server; es ist nicht möglich, die Art des Systems festzustellen.\n"

#: src/ftp.c:274 src/ftp.c:559 src/ftp.c:631 src/ftp.c:688
msgid "done.    "
msgstr "fertig.    "

#: src/ftp.c:324 src/ftp.c:458 src/ftp.c:739 src/ftp.c:787 src/url.c:1429
msgid "done.\n"
msgstr "fertig.\n"

#: src/ftp.c:352
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Unbekannte Art »%c«, schließe Kontroll-Verbindung.\n"

#: src/ftp.c:365
msgid "done.  "
msgstr "fertig.  "

#: src/ftp.c:371
msgid "==> CWD not needed.\n"
msgstr "==> CWD nicht notwendig.\n"

#: src/ftp.c:444
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Das Verzeichnis »%s« gibt es nicht.\n\n"

#. do not CWD
#: src/ftp.c:462
msgid "==> CWD not required.\n"
msgstr "==> CWD nicht erforderlich.\n"

#: src/ftp.c:496
msgid "Cannot initiate PASV transfer.\n"
msgstr "Kann PASV-Übertragung nicht beginnen.\n"

#: src/ftp.c:500
msgid "Cannot parse PASV response.\n"
msgstr "Kann PASV-Antwort nicht auswerten.\n"

# short for:
# Es wird der versuch unternommen, ...
# -ke- 2001-06-03 07:40:10 CEST
#: src/ftp.c:514
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Versuch Verbindung zu %s:%hu herzustellen.\n"

#: src/ftp.c:601
#, c-format
msgid "Bind error (%s).\n"
msgstr "Verbindungsfehler (%s).\n"

#: src/ftp.c:617
msgid "Invalid PORT.\n"
msgstr "Ungültiger PORT.\n"

#: src/ftp.c:670
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST schlug fehl; »%s« wird nicht zurückgekürzt.\n"

#: src/ftp.c:677
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST schlug fehl; noch einmal von vorn beginnen.\n"

#: src/ftp.c:726
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Die Datei »%s« gibt es nicht.\n\n"

#: src/ftp.c:774
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Die Datei oder das Verzeichnis »%s« gibt es nicht.\n\n"

#: src/ftp.c:858 src/ftp.c:866
#, c-format
msgid "Length: %s"
msgstr "Länge: %s"

#: src/ftp.c:860 src/ftp.c:868
#, c-format
msgid " [%s to go]"
msgstr " [noch %s]"

# wohl "unmaßgeblich", nicht "ohne Berechtigung"
#: src/ftp.c:870
msgid " (unauthoritative)\n"
msgstr " (unmaßgeblich)\n"

#: src/ftp.c:897
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s; Kontroll-Verbindung schließen.\n"

#: src/ftp.c:905
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Daten-Verbindung: %s; "

#: src/ftp.c:922
msgid "Control connection closed.\n"
msgstr "Kontroll-Verbindung geschlossen.\n"

#: src/ftp.c:940
msgid "Data transfer aborted.\n"
msgstr "Daten-Übertragung abgeschlossen.\n"

#: src/ftp.c:1004
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Die Datei »%s« ist schon vorhanden, kein erneuter Download.\n"

#: src/ftp.c:1074 src/http.c:1501
#, c-format
msgid "(try:%2d)"
msgstr "(versuche:%2d)"

# oder "gesichert"?
#: src/ftp.c:1138 src/http.c:1752
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - »%s« gespeichert [%ld]\n\n"

#: src/ftp.c:1180 src/main.c:809 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "Entferne »%s«.\n"

#: src/ftp.c:1220
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "»%s« als temporäre Auflistungsdatei benutzen.\n"

#: src/ftp.c:1232
#, c-format
msgid "Removed `%s'.\n"
msgstr "»%s« gelöscht.\n"

#: src/ftp.c:1268
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Die Rekursionstiefe %d übersteigt die max. erlaubte Tiefe %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1329
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Datei auf dem Server nicht neuer als die lokale Datei »%s« -- kein Download.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1336
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "Datei auf dem Server neuer als die lokale Datei »%s«, -- erneuter Download.\n"

#. Sizes do not match
#: src/ftp.c:1343
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Größen stimmen nicht überein (lokal %ld) -- erneuter Download.\n\n"

#: src/ftp.c:1360
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Ungültiger Name für einen symbolischen Verweis; übersprungen.\n"

#: src/ftp.c:1377
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Der richtige symbolische Verweis %s -> %s ist schon vorhanden.\n"

#: src/ftp.c:1385
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Symbolischen Verweis %s -> %s anlegen.\n"

#: src/ftp.c:1396
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Symbolischer Verweis nicht möglich; symbolischer Verweis »%s« übersprungen.\n"

#: src/ftp.c:1408
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Verzeichnis »%s« übersprungen.\n"

#: src/ftp.c:1417
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: unbekannter bzw. nicht unterstützter Dateityp.\n"

#: src/ftp.c:1444
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: beschädigter Zeitstempel.\n"

#: src/ftp.c:1465
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Verzeichnisse nicht erneut holen; da die Tiefe bereits %d ist (max. erlaubt %d).\n"

#: src/ftp.c:1511
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Nicht zu »%s« hinabsteigen, da es ausgeschlossen bzw. nicht eingeschlossen ist.\n"

#: src/ftp.c:1558
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "»%s« zurückgewiesen.\n"
