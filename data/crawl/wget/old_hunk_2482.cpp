#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1698
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Nu s-au g�sit potriviri pentru tiparul `%s'.\n"

#: src/ftp.c:1764
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "S-a scris indexul HTML �n `%s' [%ld].\n"

#: src/ftp.c:1769
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "S-a scris indexul HTML �n `%s'\n"

#: src/gen_sslfunc.c:117
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr "Nu s-a selectat OpenSSL PRNG; dezactivare SSL.\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: op�iunea `%s' este ambigu�\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: op�iunea `--%s' nu permite un parametru\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: op�iunea `%c%s' nu permite un parametru\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: op�iunea `%s' necesit� un parametru\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: op�iune nerecunoscut� `--%s'\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: op�iune nerecunoscut� `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: op�iune ilegal� -- %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: op�iune invalid� -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: op�iunea necesit� un parametru -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: op�iunea `W %s' este ambigu�\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: op�iunea `-W %s' nu permite parametri\n"

#: src/host.c:636
#, c-format
msgid "Resolving %s... "
msgstr "Rezolvare %s... "

#: src/host.c:656 src/host.c:672
#, c-format
msgid "failed: %s.\n"
msgstr "e�uare: %s.\n"

#: src/host.c:674
msgid "failed: timed out.\n"
msgstr "e�uare: .expirat(�)\n"

#: src/host.c:762
msgid "Host not found"
msgstr "Host neg�sit"

#: src/host.c:764
msgid "Unknown error"
msgstr "Eroare necunoscut�"

#: src/html-url.c:293
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Nu s-a rezolvat linkul incomplet %s.\n"

#. this is fatal
#: src/http.c:674
msgid "Failed to set up an SSL context\n"
msgstr "S-a e�uat �n setarea contextului SSL\n"

#: src/http.c:680
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "S-a e�uat �n �nc�rcarea certificatelor din %s\n"

#: src/http.c:684 src/http.c:692
msgid "Trying without the specified certificate\n"
msgstr "Se �ncearc� f�r� certificatele specificate\n"

#: src/http.c:688
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Nu s-a putut primi codul(key) certificatului de la %s\n"

#: src/http.c:761 src/http.c:1809
msgid "Unable to establish SSL connection.\n"
msgstr "Nu s-a putut stabili o conexiune SSL.\n"

#: src/http.c:770
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Reutilizare conexiune c�tre %s:%hu.\n"

#: src/http.c:1034
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Scriere cerere HTTP e�uat�: %s.\n"

#: src/http.c:1039
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Cerere %s trimis�, se a�teapt� r�spuns... "

#: src/http.c:1083
msgid "End of file while parsing headers.\n"
msgstr "Sf�r�it fi�ier la analiza headerelor.\n"

#: src/http.c:1093
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Eroare de citire (%s) �n headere.\n"

#: src/http.c:1128
msgid "No data received"
msgstr "Nici o dat� recep�ionat�"

#: src/http.c:1130
msgid "Malformed status line"
msgstr "Linie de stare malformat�"

#: src/http.c:1135
msgid "(no description)"
msgstr "(f�r� descriere)"

#: src/http.c:1267
msgid "Authorization failed.\n"
msgstr "Autorizare e�uat�.\n"

#: src/http.c:1274
msgid "Unknown authentication scheme.\n"
msgstr "Schem� autentificare necunoscut�.\n"

#: src/http.c:1314
#, c-format
msgid "Location: %s%s\n"
msgstr "Loca�ie: %s%s\n"

#: src/http.c:1315 src/http.c:1454
msgid "unspecified"
msgstr "nespecificat(�)"

#: src/http.c:1316
msgid " [following]"
msgstr " [urmeaz�]"

#: src/http.c:1383
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
