msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: flaggan \"-W %s\" tar inget argument\n"

#: src/host.c:371
#, fuzzy
msgid "Unknown host"
msgstr "Okänt fel"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:375
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:377
msgid "Unknown error"
msgstr "Okänt fel"

#: src/host.c:756
#, c-format
msgid "Resolving %s... "
msgstr "Slår upp %s... "

#: src/host.c:800 src/host.c:829
#, c-format
msgid "failed: %s.\n"
msgstr "misslyckades: %s.\n"

#: src/host.c:809
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:832
msgid "failed: timed out.\n"
msgstr "misslyckades: gjorde time-out.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Kan inte slå upp den ofullständiga länken %s.\n"

#: src/http.c:373 src/http.c:1549
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Misslyckades med att skriva HTTP-begäran: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1198
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1417
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Återanvänder anslutning till %s:%hu.\n"

#: src/http.c:1479
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Misslyckades med att skriva HTTP-begäran: %s.\n"

#: src/http.c:1488
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Misslyckades med att skriva HTTP-begäran: %s.\n"

#: src/http.c:1508
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1555
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s-begäran skickad, väntar på svar... "

#: src/http.c:1566
#, fuzzy
msgid "No data received.\n"
msgstr "Ingen data mottagen"

#: src/http.c:1573
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Läsfel (%s) i huvuden.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1658
msgid "Unknown authentication scheme.\n"
msgstr "Okänd autentiseringsmetod.\n"

#: src/http.c:1682
msgid "Authorization failed.\n"
msgstr "Auktorisering misslyckades.\n"

#: src/http.c:1696
msgid "Malformed status line"
msgstr "Felaktig statusrad"

#: src/http.c:1698
msgid "(no description)"
msgstr "(ingen beskrivning)"

#: src/http.c:1769
#, c-format
msgid "Location: %s%s\n"
msgstr "Adress: %s%s\n"

#: src/http.c:1770 src/http.c:1867
msgid "unspecified"
msgstr "ospecifierat"

#: src/http.c:1771
msgid " [following]"
msgstr " [följer]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1817
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
