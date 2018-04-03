
#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:150 src/http.c:624
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Verbindungsaufbau zu %s:%hu... "

#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Verbindung nach %s:%hu zur�ckgewiesen.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:193 src/http.c:652
msgid "connected!\n"
msgstr "verbunden!\n"

#: src/ftp.c:194
#, c-format
msgid "Logging in as %s ... "
msgstr "Anmelden als %s ... "

# Ist das gemeint?
# Das finde ich nicht gut.  Ich denke, Programme sollten nie in der
# 1. Person von sich sprechen.  Im Deutschen k�nnte man sagen:
#     ... Kontroll-Verbindung wird geschlossen
# oder
#     ... Schlie�en der Kontroll-Verbindung
#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
msgid "Error in server response, closing control connection.\n"
msgstr "Fehler in der Antwort des Servers; schlie�e Kontroll-Verbindung.\n"

#: src/ftp.c:211
msgid "Error in server greeting.\n"
msgstr "Fehler bei der Begr��ung des Servers.\n"

#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
msgid "Write failed, closing control connection.\n"
msgstr "Schreiben schlug fehl; Kontroll-Verbindung schlie�en.\n"

#: src/ftp.c:226
msgid "The server refuses login.\n"
msgstr "Der Server verweigert die Anmeldung.\n"

#: src/ftp.c:233
msgid "Login incorrect.\n"
msgstr "Fehler bei der Anmeldung.\n"

#: src/ftp.c:240
msgid "Logged in!\n"
msgstr "Angemeldet!\n"

#: src/ftp.c:265
msgid "Server error, can't determine system type.\n"
msgstr "Fehler beim Server; es ist nicht m�glich, die Art des Systems festzustellen.\n"

#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
msgid "done.    "
msgstr "fertig.    "

#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
msgid "done.\n"
msgstr "fertig.\n"

#: src/ftp.c:353
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Unbekannte Art �%c�, schlie�e Kontroll-Verbindung.\n"

#: src/ftp.c:366
msgid "done.  "
msgstr "fertig.  "

#: src/ftp.c:372
msgid "==> CWD not needed.\n"
msgstr "==> CWD nicht notwendig.\n"

#: src/ftp.c:445
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Das Verzeichnis �%s� gibt es nicht.\n\n"

#. do not CWD
#: src/ftp.c:463
msgid "==> CWD not required.\n"
msgstr "==> CWD nicht erforderlich.\n"

#: src/ftp.c:497
msgid "Cannot initiate PASV transfer.\n"
msgstr "Kann PASV-�bertragung nicht beginnen.\n"

#: src/ftp.c:501
msgid "Cannot parse PASV response.\n"
msgstr "Kann PASV-Antwort nicht auswerten.\n"

# short for:
# Es wird der versuch unternommen, ...
# -ke- 2001-06-03 07:40:10 CEST
# Finde ich nicht gut.  Meine �bersetzung war gedacht als Verk�rzung von:
#     Es wird der Versuch unternommen, eine Verbindung zu ... herzustellen
#: src/ftp.c:515
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Versuch: Verbindung zu %s:%hu herstellen.\n"

#: src/ftp.c:602
#, c-format
msgid "Bind error (%s).\n"
msgstr "Verbindungsfehler (%s).\n"

#: src/ftp.c:618
msgid "Invalid PORT.\n"
msgstr "Ung�ltiger PORT.\n"

#: src/ftp.c:671
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST schlug fehl; �%s� wird nicht abgeschnitten.\n"

# Wieder das mit der 1. Person :)
#: src/ftp.c:678
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST schlug fehl; es wird wieder von vorn begonnen.\n"

#: src/ftp.c:727
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Die Datei �%s� gibt es nicht.\n\n"

#: src/ftp.c:775
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Die Datei oder das Verzeichnis �%s� gibt es nicht.\n\n"

#: src/ftp.c:859 src/ftp.c:867
#, c-format
msgid "Length: %s"
msgstr "L�nge: %s"

#: src/ftp.c:861 src/ftp.c:869
#, c-format
msgid " [%s to go]"
msgstr " [noch %s]"

# wohl "unma�geblich", nicht "ohne Berechtigung"
#: src/ftp.c:871
msgid " (unauthoritative)\n"
msgstr " (unma�geblich)\n"

#: src/ftp.c:898
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s; Kontroll-Verbindung schlie�en.\n"

#: src/ftp.c:906
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Daten-Verbindung: %s; "

#: src/ftp.c:923
msgid "Control connection closed.\n"
msgstr "Kontroll-Verbindung geschlossen.\n"

#: src/ftp.c:941
msgid "Data transfer aborted.\n"
msgstr "Daten-�bertragung abgebrochen.\n"

#: src/ftp.c:1005
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Die Datei �%s� ist schon vorhanden, kein erneuter Download.\n"

#: src/ftp.c:1075 src/http.c:1502
#, c-format
msgid "(try:%2d)"
msgstr "(Versuch:%2d)"

# oder "gesichert"?
#: src/ftp.c:1139 src/http.c:1753
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - �%s� gespeichert [%ld]\n\n"

#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "Entferne �%s�.\n"

#: src/ftp.c:1221
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "�%s� als tempor�re Auflistungsdatei benutzen.\n"

#: src/ftp.c:1233
#, c-format
msgid "Removed `%s'.\n"
msgstr "�%s� gel�scht.\n"

#: src/ftp.c:1269
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Die Rekursionstiefe %d �bersteigt die max. erlaubte Tiefe %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1330
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Datei auf dem Server nicht neuer als die lokale Datei �%s� -- kein Download.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1337
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "Datei auf dem Server neuer als die lokale Datei �%s�, -- erneuter Download.\n"

#. Sizes do not match
#: src/ftp.c:1344
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Gr��en stimmen nicht �berein (lokal %ld) -- erneuter Download.\n\n"

#: src/ftp.c:1361
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Ung�ltiger Name f�r einen symbolischen Verweis; �bersprungen.\n"

#: src/ftp.c:1378
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Der richtige symbolische Verweis %s -> %s ist schon vorhanden.\n"

#: src/ftp.c:1386
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Symbolischen Verweis %s -> %s anlegen.\n"

#: src/ftp.c:1397
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Symbolischer Verweis nicht m�glich; symbolischer Verweis �%s� �bersprungen.\n"

#: src/ftp.c:1409
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Verzeichnis �%s� �bersprungen.\n"

#: src/ftp.c:1418
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: unbekannter bzw. nicht unterst�tzter Dateityp.\n"

#: src/ftp.c:1445
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: besch�digter Zeitstempel.\n"

#: src/ftp.c:1466
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Verzeichnisse nicht erneut holen; da die Tiefe bereits %d ist (max. erlaubt %d).\n"

#: src/ftp.c:1512
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Nicht zu �%s� hinabsteigen, da es ausgeschlossen bzw. nicht eingeschlossen ist.\n"

#: src/ftp.c:1559
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "�%s� zur�ckgewiesen.\n"
