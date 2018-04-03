msgstr "Unbekannter Fehler"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr "Fehler beim Herstellen des SSL-Kontextes\n"

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Fehler beim Laden der Zertifikate von %s\n"

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr "Versuch ohne die angegebenen Zertifikate\n"

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Fehlversuch den Zertifikat-Schlüssel von %s zu erhalten.\n"

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr "Es ist nicht möglich, eine SSL-Verbindung herzustellen.\n"

#: src/http.c:671
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Weiterverwendung der Verbindung zu %s:%hu.\n"

#: src/http.c:861
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Fehler beim Schreiben der HTTP-Anforderung: %s.\n"

# Wieder das mit der 1. Person :)
#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s Anforderung gesendet, warte auf Antwort... "

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr "Dateiende beim Auswerten des Vorspanns (headers).\n"

#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lesefehler (%s) beim Vorspann (header).\n"

#: src/http.c:959
msgid "No data received"
msgstr "Keine Daten empfangen"

#: src/http.c:961
msgid "Malformed status line"
msgstr "Nicht korrekte Statuszeile"

#: src/http.c:966
msgid "(no description)"
msgstr "(keine Beschreibung)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr "Authorisierung fehlgeschlagen.\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr "Unbekanntes Authentifizierungsschema.\n"

#: src/http.c:1136
#, c-format
msgid "Location: %s%s\n"
msgstr "Platz: %s%s\n"

#: src/http.c:1137 src/http.c:1269
msgid "unspecified"
msgstr "nicht spezifiziert"

#: src/http.c:1138
msgid " [following]"
msgstr "[folge]"

#: src/http.c:1200
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    Download der Datei schon vollständig; kein Download notwendig.\n\n"

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"Die Fortführung des Downloads ist fehlgeschlagen; dies ist ein\n"
"Widerspruch zur Option »-c«.\n"
"Die vorhandene Datei »%s« wird nicht abgeschnitten.\n"
"\n"

# Header
#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1259
msgid "Length: "
msgstr "Länge: "

#: src/http.c:1264
#, c-format
msgid " (%s to go)"
msgstr " (noch %s)"

#: src/http.c:1269
msgid "ignored"
msgstr "übergangen"

#: src/http.c:1399
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Warnung: Joker-Zeichen werden bei HTTP nicht unterstützt.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1417
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Datei »%s« ist schon vorhanden, kein erneuter Download.\n"

#: src/http.c:1585
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kann nicht nach »%s« schreiben (%s).\n"

# Was meint hier location?
#: src/http.c:1602
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEHLER: Umleitung (%d) ohne Ziel(?).\n"

#: src/http.c:1630
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEHLER %d: %s.\n"

#: src/http.c:1642
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "»Last-modified«-Kopfzeile fehlt -- Zeitstempel abgeschaltet.\n"

#: src/http.c:1650
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "»Last-modified«-Kopfzeile ungültig -- Zeitstempel übergangen.\n"

#: src/http.c:1673
#, c-format
msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
msgstr "Datei auf dem Server nicht neuer als die lokale Datei »%s« -- kein Download.\n\n"

#: src/http.c:1680
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Größen stimmen nicht überein (lokal %ld) -- erneuter Download.\n"

#: src/http.c:1684
msgid "Remote file is newer, retrieving.\n"
msgstr "Datei der Gegenseite ist neuer, erneuter Download.\n"

#: src/http.c:1728
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - »%s« gespeichert [%ld/%ld]\n\n"

#: src/http.c:1774
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Verbindung bei Byte %ld geschlossen. "

#: src/http.c:1782
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - »%s« gespeichert [%ld/%ld])\n\n"

#: src/http.c:1801
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Verbindung bei Byte %ld/%ld geschlossen. "

#: src/http.c:1812
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Lesefehler bei Byte %ld (%s)."

#: src/http.c:1820
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Lesefehler bei Byte %ld/%ld (%s). "

#: src/init.c:349 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: »%s« nicht lesbar (%s).\n"

#: src/init.c:367 src/init.c:373
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Fehler in »%s« bei Zeile %d.\n"

#: src/init.c:405
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Warnung: »wgetrc« des Systems und des Benutzers zeigen nach »%s«.\n"

#: src/init.c:497
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: Unbekannter Befehl »%s«, Wert »%s«.\n"

#: src/init.c:529
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: »%s« ist nicht in eine IP-Adresse umwandelbar.\n"

#: src/init.c:559
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Bitte »on« oder »off« angeben.\n"

#: src/init.c:603
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Bitte »on«, »off« oder »never« angeben.\n"

#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Ungültige Angabe »%s«\n"

#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
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
msgstr "GNU Wget %s, ein nicht-interaktives Netz-Werkzeug zum Download von Dateien.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:133
msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
msgstr "\nErforderliche Argumente zu langen Optionen sind auch bei kurzen Optionen erforderlich.\n\n"

#: src/main.c:137
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
