#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1753
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "N�l aon rud comhoiri�nach leis an phatr�n `%s'.\n"

#: src/ftp.c:1819
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Scr�obhadh inn�acs i gcruth HTML i `%s' [%s].\n"

#: src/ftp.c:1824
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Scr�obhadh inn�acs i gcruth HTML i `%s'.\n"

#: src/getopt.c:670
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: T� an rogha `%s' d�bhr�och\n"

#: src/getopt.c:695
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: n� cheada�tear arg�int i ndiaidh na rogha `--%s'\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: n� cheada�tear arg�int i ndiaidh na rogha `%c%s'\n"

#: src/getopt.c:718 src/getopt.c:891
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: n� fol�ir arg�int don rogha `%s'\n"

#. --option
#: src/getopt.c:747
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: rogha anaithnid `--%s'\n"

#. +option or -option
#: src/getopt.c:751
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: rogha anaithnid `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:777
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: rogha neamhcheadaithe -- %c\n"

#: src/getopt.c:780
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: rogha neamhbhail� -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:810 src/getopt.c:940
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: n� fol�ir arg�int don rogha -- %c\n"

#: src/getopt.c:857
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: T� an rogha `-W %s' d�bhr�och\n"

#: src/getopt.c:875
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: n� cheada�tear arg�int i ndiaidh na rogha `-W %s'\n"

#: src/host.c:347
msgid "Unknown host"
msgstr "�str�omhaire anaithnid"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr "Teip shealadach ar r�iteach na n-ainmneacha"

#: src/host.c:353
msgid "Unknown error"
msgstr "Earr�id anaithnid"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "%s � r�iteach... "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "teipthe: Gan seoladh IPv4/IPv6 don �str�omhaire.\n"

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "teipthe: thar am.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: N� f�idir nasc %s neamhioml�n a r�iteach.\n"

#: src/html-url.c:695
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL neamhbhail� %s: %s\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Theip ar scr�obh iarratais HTTP: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr "Gan cheannt�sca, glac le HTTP/0.9"

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr "SSL � dh�chumas� de bharr earr�id�.\n"

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "Comhad sonra� POST `%s' ar iarraidh: %s\n"

#: src/http.c:1615
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Ag baint ath�s�id as an nasc le %s:%d.\n"

#: src/http.c:1684
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Theip ar l�amh freagra �n seachfhreastala�: %s\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Theip ar tholl�n� seachfhreastala�: %s"

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Iarratas %s seolta, ag fanacht le freagra... "

#: src/http.c:1760
msgid "No data received.\n"
msgstr "N�or glacadh aon sonra.\n"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Earr�id (%s) ag l�amh na gceannt�sc.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"T� an comhad `%s' ann cheana; n� aisghabhfar �.\n"
"\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "Sc�im anaithnid fh�ordheimhnithe.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "Theip ar �dar�.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "L�ne st�dais m�chumtha"

#: src/http.c:2013
msgid "(no description)"
msgstr "(gan cur s�os)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Su�omh: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "gan sonr�"

#: src/http.c:2078
msgid " [following]"
msgstr " [� lean�int]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
