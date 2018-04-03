#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1753
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Geen overeenkomsten met patroon '%s'.\n"

#: src/ftp.c:1819
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Index is in HTML-vorm naar '%s' [%s] geschreven.\n"

#: src/ftp.c:1824
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Index is in HTML-vorm naar '%s' geschreven.\n"

#: src/getopt.c:670
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: optie '%s' is niet eenduidig\n"

#: src/getopt.c:695
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: optie '--%s' staat geen argument toe\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: optie '%c%s' staat geen argument toe\n"

#: src/getopt.c:718 src/getopt.c:891
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: optie '%s' vereist een argument\n"

#. --option
#: src/getopt.c:747
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: onbekende optie '--%s'\n"

#. +option or -option
#: src/getopt.c:751
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: onbekende optie '%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:777
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: ongeldige optie -- %c\n"

#: src/getopt.c:780
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: ongeldige optie -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:810 src/getopt.c:940
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: optie vereist een argument -- %c\n"

#: src/getopt.c:857
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: optie '-W %s' is niet eenduidig\n"

#: src/getopt.c:875
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: optie '-W %s' staat geen argument toe\n"

#: src/host.c:347
msgid "Unknown host"
msgstr "Onbekende host"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr "Tijdelijke storing in naamsherleiding"

#: src/host.c:353
msgid "Unknown error"
msgstr "Onbekende fout"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "Herleiden van %s... "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "mislukt: geen IPv4/IPv6-adressen voor de host.\n"

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "mislukt: wachttijd is verstreken.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Kan doel van onvolledige hyperlink %s niet bepalen.\n"

#: src/html-url.c:695
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Ongeldige URL '%s': %s.\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Schrijven van HTTP-verzoek is mislukt: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr "Geen kopregels aanwezig, HTTP/0.9 aangenomen."

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Wegens fouten wordt SSL uitgeschakeld.\n"

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "POST-gegevensbestand '%s' ontbreekt: %s.\n"

#: src/http.c:1615
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Verbinding met %s:%d wordt hergebruikt.\n"

#: src/http.c:1684
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Lezen van proxy-antwoord is mislukt: %s.\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Het tunnelen door een proxy is mislukt: %s."

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s-verzoek is verzonden, wachten op antwoord... "

#: src/http.c:1760
msgid "No data received.\n"
msgstr "Geen gegevens ontvangen.\n"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Leesfout (%s) in kopregels.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"Bestand '%s' is reeds aanwezig -- wordt niet opgehaald.\n"
"\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "Onbekend aanmeldingsschema.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "Aanmelding is mislukt.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "Onjuiste statusregel"

#: src/http.c:2013
msgid "(no description)"
msgstr "(geen omschrijving)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Lokatie: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "niet-opgegeven"

#: src/http.c:2078
msgid " [following]"
msgstr " [volgend]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
