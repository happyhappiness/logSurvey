msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: Option »-W %s« erlaubt kein Argument\n"

#: src/host.c:636
#, c-format
msgid "Resolving %s... "
msgstr "Auflösen des Hostnamen »%s«.... "

#: src/host.c:656 src/host.c:672
#, c-format
msgid "failed: %s.\n"
msgstr "fehlgeschlagen: %s.\n"

#: src/host.c:674
msgid "failed: timed out.\n"
msgstr "fehlgeschlagen: Wartezeit abgelaufen.\n"

#: src/host.c:762
msgid "Host not found"
msgstr "Host nicht gefunden"

#: src/host.c:764
msgid "Unknown error"
msgstr "Unbekannter Fehler"

#: src/html-url.c:293
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Der unvollständige Link »%s« kann nicht aufgelöst werden.\n"

#. this is fatal
#: src/http.c:674
msgid "Failed to set up an SSL context\n"
msgstr "Fehler beim Herstellen des SSL-Kontextes\n"

#: src/http.c:680
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Fehler beim Laden der Zertifikate von %s\n"

#: src/http.c:684 src/http.c:692
msgid "Trying without the specified certificate\n"
msgstr "Versuch ohne die angegebenen Zertifikate\n"

#: src/http.c:688
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Fehlversuch den Zertifikat-Schlüssel von %s zu erhalten.\n"

#: src/http.c:761 src/http.c:1809
msgid "Unable to establish SSL connection.\n"
msgstr "Es ist nicht möglich, eine SSL-Verbindung herzustellen.\n"

#: src/http.c:770
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Weiterverwendung der Verbindung zu %s:%hu.\n"

#: src/http.c:1034
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Fehler beim Schreiben der HTTP-Anforderung: %s.\n"

# Wieder das mit der 1. Person :)
#: src/http.c:1039
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s Anforderung gesendet, warte auf Antwort... "

#: src/http.c:1083
msgid "End of file while parsing headers.\n"
msgstr "Dateiende beim Auswerten des Vorspanns (headers).\n"

#: src/http.c:1093
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lesefehler (%s) beim Vorspann (header).\n"

#: src/http.c:1128
msgid "No data received"
msgstr "Keine Daten empfangen"

#: src/http.c:1130
msgid "Malformed status line"
msgstr "Nicht korrekte Statuszeile"

#: src/http.c:1135
msgid "(no description)"
msgstr "(keine Beschreibung)"

#: src/http.c:1267
msgid "Authorization failed.\n"
msgstr "Authorisierung fehlgeschlagen.\n"

#: src/http.c:1274
msgid "Unknown authentication scheme.\n"
msgstr "Unbekanntes Authentifizierungsschema.\n"

#: src/http.c:1314
#, c-format
msgid "Location: %s%s\n"
msgstr "Platz: %s%s\n"

#: src/http.c:1315 src/http.c:1454
msgid "unspecified"
msgstr "nicht spezifiziert"

#: src/http.c:1316
msgid " [following]"
msgstr "[folge]"

#: src/http.c:1383
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
