#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1753
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Brak pasuj±cych do wzorca `%s'.\n"

#: src/ftp.c:1819
#, fuzzy, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Zapisano indeks w postaci HTML-u w `%s' [%ld].\n"

#: src/ftp.c:1824
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Zapisano indeks w postaci HTML-u w `%s'.\n"

#: src/getopt.c:670
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: opcja `%s` jest niejednoznaczna\n"

#: src/getopt.c:695
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: opcja `--%s' nie przyjmuje argumentów\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: opcja `%c%s' nie przyjmuje argumentów\n"

#: src/getopt.c:718 src/getopt.c:891
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: opcja `%s' wymaga argumentu\n"

#. --option
#: src/getopt.c:747
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: nierozpoznana opcja `--%s'\n"

#. +option or -option
#: src/getopt.c:751
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: nierozpoznana opcja `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:777
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: nieprawid³owa opcja -- %c\n"

#: src/getopt.c:780
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: niew³a¶ciwa opcja -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:810 src/getopt.c:940
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: opcja wymaga argumentu -- %c\n"

#: src/getopt.c:857
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: opcja `-W %s' jest niejednoznaczna\n"

#: src/getopt.c:875
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: opcja `-W %s' nie przyjmuje argumentów\n"

#: src/host.c:347
#, fuzzy
msgid "Unknown host"
msgstr "Nieznany b³±d"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:353
msgid "Unknown error"
msgstr "Nieznany b³±d"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "Translacja %s... "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "b³±d: przekroczono limit czasu oczekiwania.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Nie uda³o siê przeanalizowaæ niedokoñczonego ³±cza %s.\n"

# c-format
#: src/html-url.c:695
#, fuzzy, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: %s: Nieprawid³owa warto¶æ `%s'.\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Nie powiod³o siê wysy³anie ¿±dania HTTP: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr ""

#: src/http.c:1615
#, fuzzy, c-format
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
