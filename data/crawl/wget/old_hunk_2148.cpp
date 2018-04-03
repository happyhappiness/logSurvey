msgid "Reusing existing connection to %s:%d.\n"
msgstr "Wiederverwendung der bestehenden Verbindung zu %s:%d.\n"

#: src/http.c:1684
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Fehler beim Lesen der Proxy-Antwort: %s.\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Proxy-Tunneling fehlgeschlagen: %s"

# Wieder das mit der 1. Person :)
#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s Anforderung gesendet, warte auf Antwort... "

#: src/http.c:1760
msgid "No data received.\n"
msgstr "Keine Daten empfangen.\n"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lesefehler (%s) beim Vorspann (header).\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "Die Datei »%s« ist schon vorhanden; kein erneuter Download.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "Unbekanntes Authentifizierungsschema.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "Authorisierung fehlgeschlagen.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "Nicht korrekte Statuszeile"

#: src/http.c:2013
msgid "(no description)"
msgstr "(keine Beschreibung)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Platz: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "nicht spezifiziert"

#: src/http.c:2078
msgid " [following]"
msgstr "[folge]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
