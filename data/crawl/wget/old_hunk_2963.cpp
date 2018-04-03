#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1608
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Nincs találat a `%s' mintához .\n"

#: src/ftp.c:1673
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "A HTML-esített indexet a `%s' [%ld] állományba írtam.\n"

#: src/ftp.c:1678
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "A HTML-esített indexet a `%s' állományba írtam.\n"

#: src/gen_sslfunc.c:109
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr "Nem tudom az OpenSSL PRNG-t inicializálni; SSL kikapcsolva.\n"

#: src/getopt.c:454
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: a `%s' opció kétes értelmû\n"

#: src/getopt.c:478
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: a `--%s' opcióhoz nem kell argumentum\n"

#: src/getopt.c:483
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: a `%c%s' opcióhoz nem kell argumentum\n"

#: src/getopt.c:498
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: a `%s' opcióhoz kell argumentum\n"

#. --option
#: src/getopt.c:528
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: ismeretlen opció `--%s'\n"

#. +option or -option
#: src/getopt.c:532
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: ismeretlen opció `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:563
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: helytelen opció -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: az opcióhoz szükség van argumentumra -- %c\n"

#: src/host.c:271
#, c-format
msgid "Resolving %s... "
msgstr "IP keresés %s... "

#: src/host.c:278
#, c-format
msgid "failed: %s.\n"
msgstr "nem sikerült: %s.\n"

#: src/host.c:348
msgid "Host not found"
msgstr "Host-ot nem találom"

#: src/host.c:350
msgid "Unknown error"
msgstr "Ismeretlen hiba"

#: src/html-url.c:336
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: nem tudom megtalálni a hiányos %s linket.\n"

#. this is fatal
#: src/http.c:573
msgid "Failed to set up an SSL context\n"
msgstr "Nem sikerült SSL-t beállítsak\n"

#: src/http.c:579
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Nem sikerült betöltsem az igazolásokat %s-ról\n"

#: src/http.c:583 src/http.c:591
msgid "Trying without the specified certificate\n"
msgstr "Megpróbálom a megadott igazolás nélkül\n"

#: src/http.c:587
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Nemsikerült megszerezni az igazoló kulcsot %s-ról\n"

#: src/http.c:657 src/http.c:1620
msgid "Unable to establish SSL connection.\n"
msgstr "Nem sikerült SSL kapcsolatot létrehozni.\n"

#: src/http.c:666
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Újrahasználom a kapcsolatot %s:%hu-hoz.\n"

#: src/http.c:868
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "A HTTP kérés írása sikertelen: %s.\n"

#: src/http.c:873
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s kérés elküldve, várom a választ... "

#: src/http.c:917
msgid "End of file while parsing headers.\n"
msgstr "Állomány vége miközben a fejlécet olvasom.\n"

#: src/http.c:927
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Olvasási hiba (%s) a fejlécben.\n"

#: src/http.c:962
msgid "No data received"
msgstr "Nem érkezett adat"

#: src/http.c:964
msgid "Malformed status line"
msgstr "Rosszul formázott állapot vonal"

#: src/http.c:969
msgid "(no description)"
msgstr "(nincs leírás)"

#: src/http.c:1101
msgid "Authorization failed.\n"
msgstr "Azonosítás sikertelen.\n"

#: src/http.c:1108
msgid "Unknown authentication scheme.\n"
msgstr "Ismeretlen azonosítási módszer.\n"

#: src/http.c:1148
#, c-format
msgid "Location: %s%s\n"
msgstr "Hely: %s%s\n"

#: src/http.c:1149 src/http.c:1282
msgid "unspecified"
msgstr "nem megadott"

#: src/http.c:1150
msgid " [following]"
msgstr " [következik]"

#: src/http.c:1213
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
