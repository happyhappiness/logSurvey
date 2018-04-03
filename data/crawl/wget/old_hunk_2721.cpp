msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: `-W %s' aukerak ez du argudiorik onartzen\n"

#: src/host.c:371
#, fuzzy
msgid "Unknown host"
msgstr "Errore ezezaguna"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:375
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:377
msgid "Unknown error"
msgstr "Errore ezezaguna"

#: src/host.c:756
#, c-format
msgid "Resolving %s... "
msgstr "%s ebazten... "

#: src/host.c:800 src/host.c:829
#, c-format
msgid "failed: %s.\n"
msgstr "huts egin da: %s.\n"

#: src/host.c:809
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:832
msgid "failed: timed out.\n"
msgstr "huts·egin·da: denboraz kanpo.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Ezin da osatu gabeko linka ebatzi %s.\n"

#: src/http.c:373 src/http.c:1549
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Huts egin da HTTP eskaera idazterakoan: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1198
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1417
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Konexioa berrerabiltzen %srentzat: %hu.\n"

#: src/http.c:1479
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Huts egin da HTTP eskaera idazterakoan: %s.\n"

#: src/http.c:1488
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Huts egin da HTTP eskaera idazterakoan: %s.\n"

#: src/http.c:1508
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1555
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s eskaera bidalia, erantzunaren zain... "

#: src/http.c:1566
#, fuzzy
msgid "No data received.\n"
msgstr "Ez da daturik jaso"

#: src/http.c:1573
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Irakurketa errorea (%s) goiburukoetan.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1658
msgid "Unknown authentication scheme.\n"
msgstr "Autentifikazio eskema ezezaguna.\n"

#: src/http.c:1682
msgid "Authorization failed.\n"
msgstr "Autorizazitzen huts egin da.\n"

#: src/http.c:1696
msgid "Malformed status line"
msgstr "Gaizki eratutako egoera lerroa"

#: src/http.c:1698
msgid "(no description)"
msgstr "(deskripziorik gabe)"

#: src/http.c:1769
#, c-format
msgid "Location: %s%s\n"
msgstr "Kokapena: %s%s\n"

#: src/http.c:1770 src/http.c:1867
msgid "unspecified"
msgstr "zehaztugabea"

#: src/http.c:1771
msgid " [following]"
msgstr " [hurrengoa]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1817
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
