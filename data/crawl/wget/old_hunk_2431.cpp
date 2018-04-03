#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1778
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Nenio trovita kun la ŝablono `%s'.\n"

#: src/ftp.c:1844
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Skribite HTML-igitan indekson al `%s' [%s].\n"

#: src/ftp.c:1849
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Skribite HTML-igitan indekson al `%s'.\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: opcio `%s' estas plursenca\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s:  opcio `--%s' ne permesas argumenton\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: opcio `%c%s' ne permesas argumenton\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: opcio `%s' postulas argumenton\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: nekonata opcio `--%s'\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: nekonata opcio `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: neleĝa opcio -- %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: nevalida opcio -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: opcio postulas argumenton -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: opcio `-W %s' estas plursenca\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: opcio `-W %s' ne permesas argumenton\n"

#: src/host.c:366
msgid "Unknown host"
msgstr "Nekonata retnodo"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:370
msgid "Temporary failure in name resolution"
msgstr "Dumtempa malsukceso ĉe nom-eltrovo"

#: src/host.c:372
msgid "Unknown error"
msgstr "Nekonata eraro"

#: src/host.c:751
#, c-format
msgid "Resolving %s... "
msgstr "Provante %s... "

#: src/host.c:798
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "fiasko: Ne estas IPv4/IPv6 adreso por la retnodo.\n"

#: src/host.c:821
msgid "failed: timed out.\n"
msgstr "fiasko: limtempo finita.\n"

#: src/html-url.c:298
#, fuzzy, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Ne eblis eltrovi nekompletan ligilon %s.\n"

#: src/html-url.c:705
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Nevalida URL %s: %s\n"

#: src/http.c:373
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Fiasko skribante HTTP-an peton: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr "Sen ĉapoj, supozante HTTP/0.9"

#: src/http.c:1204
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1374
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr ""

#: src/http.c:1423
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Reuzante estantan konekton al %s:%d.\n"

#: src/http.c:1492
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Fiasko legante prokuran (proxy) respondon: %s\n"

#: src/http.c:1512
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1557
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s peto sendita, atendante respondon... "

#: src/http.c:1568
msgid "No data received.\n"
msgstr "Ne datumo ricevita.\n"

#: src/http.c:1575
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Leg-eraro (%s) ĉe ĉapoj.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1660
msgid "Unknown authentication scheme.\n"
msgstr "Nekonata aŭtentokontrola ŝablono.\n"

#: src/http.c:1684
msgid "Authorization failed.\n"
msgstr "Permesado fiaskis.\n"

#: src/http.c:1698
msgid "Malformed status line"
msgstr ""

#: src/http.c:1700
msgid "(no description)"
msgstr "(sen priskribo)"

#: src/http.c:1763
#, c-format
msgid "Location: %s%s\n"
msgstr ""

#: src/http.c:1764 src/http.c:1871
msgid "unspecified"
msgstr "nedifinita"

#: src/http.c:1765
msgid " [following]"
msgstr "[sekvanta]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1821
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
