#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1778
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Níl aon rud comhoiriúnach leis an phatrún `%s'.\n"

#: src/ftp.c:1844
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Scríobhadh innéacs i gcruth HTML i `%s' [%s].\n"

#: src/ftp.c:1849
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Scríobhadh innéacs i gcruth HTML i `%s'.\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: Tá an rogha `%s' débhríoch\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: ní cheadaítear argóint i ndiaidh na rogha `--%s'\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: ní cheadaítear argóint i ndiaidh na rogha `%c%s'\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: ní foláir argóint don rogha `%s'\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: rogha anaithnid `--%s'\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: rogha anaithnid `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: rogha neamhcheadaithe -- %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: rogha neamhbhailí -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: ní foláir argóint don rogha -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: Tá an rogha `-W %s' débhríoch\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: ní cheadaítear argóint i ndiaidh na rogha `-W %s'\n"

#: src/host.c:366
msgid "Unknown host"
msgstr "Óstríomhaire anaithnid"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:370
msgid "Temporary failure in name resolution"
msgstr "Teip shealadach ar réiteach na n-ainmneacha"

#: src/host.c:372
msgid "Unknown error"
msgstr "Earráid anaithnid"

#: src/host.c:751
#, c-format
msgid "Resolving %s... "
msgstr "%s á réiteach... "

#: src/host.c:798
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "teipthe: Gan seoladh IPv4/IPv6 don óstríomhaire.\n"

#: src/host.c:821
msgid "failed: timed out.\n"
msgstr "teipthe: thar am.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Ní féidir nasc %s neamhiomlán a réiteach.\n"

#: src/html-url.c:705
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL neamhbhailí %s: %s\n"

#: src/http.c:373
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Theip ar scríobh iarratais HTTP: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr "Gan cheanntásca, glac le HTTP/0.9"

#: src/http.c:1204
msgid "Disabling SSL due to encountered errors.\n"
msgstr "SSL á dhíchumasú de bharr earráidí.\n"

#: src/http.c:1374
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "Comhad sonraí POST `%s' ar iarraidh: %s\n"

#: src/http.c:1423
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Ag baint athúsáid as an nasc le %s:%d.\n"

#: src/http.c:1492
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Theip ar léamh freagra ón seachfhreastalaí: %s\n"

#: src/http.c:1512
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Theip ar thollánú seachfhreastalaí: %s"

#: src/http.c:1557
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Iarratas %s seolta, ag fanacht le freagra... "

#: src/http.c:1568
msgid "No data received.\n"
msgstr "Níor glacadh aon sonra.\n"

#: src/http.c:1575
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Earráid (%s) ag léamh na gceanntásc.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1660
msgid "Unknown authentication scheme.\n"
msgstr "Scéim anaithnid fhíordheimhnithe.\n"

#: src/http.c:1684
msgid "Authorization failed.\n"
msgstr "Theip ar údarú.\n"

#: src/http.c:1698
msgid "Malformed status line"
msgstr "Líne stádais míchumtha"

#: src/http.c:1700
msgid "(no description)"
msgstr "(gan cur síos)"

#: src/http.c:1763
#, c-format
msgid "Location: %s%s\n"
msgstr "Suíomh: %s%s\n"

#: src/http.c:1764 src/http.c:1871
msgid "unspecified"
msgstr "gan sonrú"

#: src/http.c:1765
msgid " [following]"
msgstr " [á leanúint]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1821
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
