msgid "%s: option requires an argument -- %c\n"
msgstr "%s: Option verlangt ein Argument -- %c\n"

#: src/host.c:394
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: Benutzer-Kennung (User-ID) nicht bestimmbar.\n"

#: src/host.c:406
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: Warnung: uname fehlgeschlagen: %s\n"

#: src/host.c:418
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: Warnung: gethostname fehlgeschlagen\n"

#: src/host.c:446
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: Warnung: lokale IP-Adresse nicht bestimmbar.\n"

#: src/host.c:460
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr "%s: Warnung: kein \"reverse-lookup\" für lokale IP-Adresse möglich.\n"

#. This gets ticked pretty often.  Karl Berry reports
#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:473
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Warnung: \"reverse-lookup\" für lokale Adresse ergibt keinen FQDN!\n"

#: src/host.c:501
msgid "Host not found"
msgstr "Host nicht gefunden"

#: src/host.c:503
msgid "Unknown error"
msgstr "Unbekannter Fehler"

#. this is fatal
#: src/http.c:549
msgid "Failed to set up an SSL context\n"
msgstr ""

#: src/http.c:555
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr ""

#: src/http.c:559 src/http.c:567
msgid "Trying without the specified certificate\n"
msgstr ""

#: src/http.c:563
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr ""

#: src/http.c:657 src/http.c:1470
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:665
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Versuche Verbindung zu %s:%hu wiederzuverwenden.\n"

#: src/http.c:841
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Schreiben der HTTP-Anforderung fehlgeschlagen: %s.\n"

#: src/http.c:846
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s Anforderung gesendet, warte auf Antwort... "

#: src/http.c:890
msgid "End of file while parsing headers.\n"
msgstr "Dateiende beim Auswerten des Vorspanns (header lines).\n"

#: src/http.c:901
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lesefehler (%s) beim Vorspann (header lines).\n"

#: src/http.c:941
msgid "No data received"
msgstr "Keine Daten empfangen"

#: src/http.c:943
msgid "Malformed status line"
msgstr "Nicht korrekte Statuszeile"

#: src/http.c:948
msgid "(no description)"
msgstr "(keine Beschreibung)"

#: src/http.c:1066
msgid "Authorization failed.\n"
msgstr "Authorisierung fehlgeschlagen.\n"

#: src/http.c:1073
msgid "Unknown authentication scheme.\n"
msgstr "Unbekannter Authentifizierungsablauf.\n"

#: src/http.c:1163
#, c-format
msgid "Location: %s%s\n"
msgstr "Platz: %s%s\n"

#: src/http.c:1164 src/http.c:1189
msgid "unspecified"
msgstr "nicht spezifiziert"

#: src/http.c:1165
msgid " [following]"
msgstr "[folge]"

# Header
#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1179
msgid "Length: "
msgstr "Länge: "

#: src/http.c:1184
#, c-format
msgid " (%s to go)"
msgstr " (noch %s)"

#: src/http.c:1189
msgid "ignored"
msgstr "übergangen"

#: src/http.c:1290
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Warnung: Joker-Zeichen werden bei HTTP nicht unterstützt.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1311
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Datei »%s« schon vorhanden, kein erneuter Download.\n"

#: src/http.c:1462
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kann nicht nach »%s« schreiben (%s).\n"

# Was meint hier location?
#: src/http.c:1480
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEHLER: Umleitung (%d) ohne Ziel(?).\n"

#: src/http.c:1505
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEHLER %d: %s.\n"

#: src/http.c:1518
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "»Last-modified«-Kopfzeile fehlt -- Zeitstempel abgeschaltet.\n"

#: src/http.c:1526
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "»Last-modified«-Kopfzeile ungültig -- Zeitstempel übergangen.\n"

#: src/http.c:1549
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:1557
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Größen stimmen nicht überein (lokal %ld) -- erneuter Download.\n"

#: src/http.c:1561
msgid "Remote file is newer, retrieving.\n"
msgstr "Datei der Gegenseite ist neuer, erneuter Download.\n"

#: src/http.c:1606
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - »%s« gespeichert [%ld/%ld]\n"
"\n"

#: src/http.c:1654
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Verbindung bei Byte %ld geschlossen. "

#: src/http.c:1662
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - »%s« gespeichert [%ld/%ld])\n"
"\n"

#: src/http.c:1682
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Verbindung bei Byte %ld/%ld geschlossen. "

#: src/http.c:1693
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Lesefehler bei Byte %ld (%s)."

#: src/http.c:1701
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Lesefehler bei Byte %ld/%ld (%s). "

#: src/init.c:336 src/netrc.c:261
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: »%s« nicht lesbar (%s).\n"

#: src/init.c:354 src/init.c:360
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Fehler in »%s« bei Zeile %d.\n"

#: src/init.c:391
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Warnung: »wgetrc« des Systems und des Benutzers zeigen nach »%s«.\n"

#: src/init.c:483
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: Unbekannter Befehl »%s«, Wert »%s«.\n"

#: src/init.c:504
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: »%s« ist nicht in eine IP-Adresse umwandelbar.\n"

#: src/init.c:532
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Bitte »on« oder »off« angeben.\n"

#: src/init.c:576
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Bitte »on«, »off« oder »never« angeben.\n"

#: src/init.c:595 src/init.c:852 src/init.c:874 src/init.c:938
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Ungültige Angabe »%s«\n"

#: src/init.c:708 src/init.c:730 src/init.c:752 src/init.c:778
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Ungültige Angabe »%s«\n"

#: src/main.c:120
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Syntax: %s [OPTION]... [URL]...\n"

#: src/main.c:128
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr ""
"GNU Wget %s, ein nicht-interaktives Netz-Werkzeug zum Download von Dateien.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:133
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Erforderliche Argumente zu langen Optionen sind auch bei kurzen Optionen "
"erforderlich.\n"
"\n"

#: src/main.c:136
msgid ""
