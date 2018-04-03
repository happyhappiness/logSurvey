"Größen stimmen nicht überein (lokal %s) -- erneuter Download.\n"
"\n"

#: src/ftp.c:1507
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Ungültiger Name für einen symbolischen Verweis; übersprungen.\n"

#: src/ftp.c:1524
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr "Der richtige symbolische Verweis %s -> %s ist schon vorhanden.\n"

#: src/ftp.c:1533
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Symbolischen Verweis %s -> %s anlegen.\n"

#: src/ftp.c:1543
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr ""
"Symbolischer Verweis nicht möglich; symbolischer Verweis »%s« übersprungen.\n"

#: src/ftp.c:1555
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "Verzeichnis »%s« übersprungen.\n"

#: src/ftp.c:1564
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: unbekannter bzw. nicht unterstützter Dateityp.\n"

#: src/ftp.c:1591
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: beschädigter Zeitstempel.\n"

#: src/ftp.c:1619
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""
"Verzeichnisse nicht erneut holen; da die Tiefe bereits %d ist (max. erlaubt %"
"d).\n"

#: src/ftp.c:1669
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr ""
"Nicht zu »%s« hinabsteigen, da es ausgeschlossen bzw. nicht eingeschlossen "
"ist.\n"

#: src/ftp.c:1735 src/ftp.c:1749
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "»%s« zurückgewiesen.\n"

#: src/ftp.c:1772
#, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Fehler beim Vergleichen von »%s« mit »%s«: %s.\n"

#: src/ftp.c:1814
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Keine Treffer bei dem Muster »%s«.\n"

#: src/ftp.c:1880
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "HTML-artigen Index nach »%s« [%s] geschrieben.\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "HTML-artiger Index nach »%s« geschrieben.\n"

#: src/host.c:348
msgid "Unknown host"
msgstr "Unbekannter Rechner"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr "Temoprärer Fehler bei der Namensauflösung"

#: src/host.c:354
msgid "Unknown error"
msgstr "Unbekannter Fehler"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "Auflösen des Hostnamen »%s«.... "

#: src/host.c:763
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "Fehler: Keine IPv4/IPv6 Adresse für den Host.\n"

#: src/host.c:786
msgid "failed: timed out.\n"
msgstr "fehlgeschlagen: Wartezeit abgelaufen.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Der unvollständige Link »%s« kann nicht aufgelöst werden.\n"

#: src/html-url.c:696
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: %s: Ungültige URL »%s«.\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Fehler beim Schreiben der HTTP-Anforderung: %s.\n"

#: src/http.c:745
msgid "No headers, assuming HTTP/0.9"
msgstr "Keine Header, vermutlich ist es HTTP/0.9."

#: src/http.c:1430
msgid "Disabling SSL due to encountered errors.\n"
msgstr "SSL wird ausgeschaltet nachdem Fehler aufgetreten sind.\n"

#: src/http.c:1548
#, fuzzy, c-format
msgid "POST data file %s missing: %s\n"
msgstr "POST Datendatei »%s« fehlt: %s\n"

#: src/http.c:1632
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Wiederverwendung der bestehenden Verbindung zu %s:%d.\n"

#: src/http.c:1701
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Fehler beim Lesen der Proxy-Antwort: %s.\n"

#: src/http.c:1721
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Proxy-Tunneling fehlgeschlagen: %s"

# Wieder das mit der 1. Person :)
#: src/http.c:1766
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s Anforderung gesendet, warte auf Antwort... "

#: src/http.c:1777
msgid "No data received.\n"
msgstr "Keine Daten empfangen.\n"

#: src/http.c:1784
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lesefehler (%s) beim Vorspann (header).\n"

#: src/http.c:1831 src/http.c:2385
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
"\n"
msgstr "Die Datei »%s« ist schon vorhanden; kein erneuter Download.\n"

#: src/http.c:1985
msgid "Unknown authentication scheme.\n"
msgstr "Unbekanntes Authentifizierungsschema.\n"

#: src/http.c:2016
msgid "Authorization failed.\n"
msgstr "Authorisierung fehlgeschlagen.\n"

#: src/http.c:2030
msgid "Malformed status line"
msgstr "Nicht korrekte Statuszeile"

#: src/http.c:2032
msgid "(no description)"
msgstr "(keine Beschreibung)"

#: src/http.c:2098
#, c-format
msgid "Location: %s%s\n"
msgstr "Platz: %s%s\n"

#: src/http.c:2099 src/http.c:2209
msgid "unspecified"
msgstr "nicht spezifiziert"

#: src/http.c:2100
msgid " [following]"
msgstr "[folge]"

#: src/http.c:2156
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
