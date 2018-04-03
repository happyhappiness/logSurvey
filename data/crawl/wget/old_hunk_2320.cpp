msgid "Reusing existing connection to %s:%d.\n"
msgstr "Ponowne u¿ycie po³±czenia do %s:%hu.\n"

#: src/http.c:1684
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Nie powiod³o siê wysy³anie ¿±dania HTTP: %s.\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "¯±danie %s wys³ano, oczekiwanie na odpowied¼... "

#: src/http.c:1760
#, fuzzy
msgid "No data received.\n"
msgstr "Brak danych w odpowiedzi"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "B³±d odczytu (%s) w nag³ówkach.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, fuzzy, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "Plik `%s' ju¿ istnieje, bez pobierania.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "Nieznana metoda uwierzytelniania.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "Autoryzacja nie powiod³a siê.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "¬le sformu³owana linia statusu"

#: src/http.c:2013
msgid "(no description)"
msgstr "(brak opisu)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Lokalizacja: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "nieznana"

#: src/http.c:2078
msgid " [following]"
msgstr " [pod±¿anie]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
