#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1698
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Brak pasuj±cych do wzorca `%s'.\n"

#: src/ftp.c:1764
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "Zapisano indeks w postaci HTML-u w `%s' [%ld].\n"

#: src/ftp.c:1769
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Zapisano indeks w postaci HTML-u w `%s'.\n"

#: src/gen_sslfunc.c:117
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr ""
"Nie da³o siê ustaliæ ziarna generatora liczb pseudolosowych dla OpenSSL;\n"
"wy³±czenie SSL.\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: opcja `%s` jest niejednoznaczna\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: opcja `--%s' nie przyjmuje argumentów\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: opcja `%c%s' nie przyjmuje argumentów\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: opcja `%s' wymaga argumentu\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: nierozpoznana opcja `--%s'\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: nierozpoznana opcja `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: nieprawid³owa opcja -- %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: niew³a¶ciwa opcja -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: opcja wymaga argumentu -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: opcja `-W %s' jest niejednoznaczna\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: opcja `-W %s' nie przyjmuje argumentów\n"

#: src/host.c:636
#, c-format
msgid "Resolving %s... "
msgstr "Translacja %s... "

#: src/host.c:656 src/host.c:672
#, c-format
msgid "failed: %s.\n"
msgstr "nieudane: %s.\n"

#: src/host.c:674
msgid "failed: timed out.\n"
msgstr "b³±d: przekroczono limit czasu oczekiwania.\n"

#: src/host.c:762
msgid "Host not found"
msgstr "Host nie zosta³ znaleziony"

#: src/host.c:764
msgid "Unknown error"
msgstr "Nieznany b³±d"

#: src/html-url.c:293
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Nie uda³o siê przeanalizowaæ niedokoñczonego ³±cza %s.\n"

#. this is fatal
#: src/http.c:674
msgid "Failed to set up an SSL context\n"
msgstr "Nieudane ustawianie kontekstu SSL\n"

#: src/http.c:680
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Nie uda³o siê wczytaæ certyfikatów z %s\n"

#: src/http.c:684 src/http.c:692
msgid "Trying without the specified certificate\n"
msgstr "Próbowanie bez podanego certyfikatu\n"

#: src/http.c:688
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Nie uda³o siê uzyskaæ klucza certyfikatu z %s\n"

#: src/http.c:761 src/http.c:1809
msgid "Unable to establish SSL connection.\n"
msgstr "Niemo¿liwe utworzenie po³±czenia SSL.\n"

#: src/http.c:770
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Ponowne u¿ycie po³±czenia do %s:%hu.\n"

#: src/http.c:1034
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Nie powiod³o siê wysy³anie ¿±dania HTTP: %s.\n"

#: src/http.c:1039
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "¯±danie %s wys³ano, oczekiwanie na odpowied¼... "

#: src/http.c:1083
msgid "End of file while parsing headers.\n"
msgstr "Podczas analizy nag³ówków wyst±pi³ koniec pliku.\n"

#: src/http.c:1093
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "B³±d odczytu (%s) w nag³ówkach.\n"

#: src/http.c:1128
msgid "No data received"
msgstr "Brak danych w odpowiedzi"

#: src/http.c:1130
msgid "Malformed status line"
msgstr "¬le sformu³owana linia statusu"

#: src/http.c:1135
msgid "(no description)"
msgstr "(brak opisu)"

#: src/http.c:1267
msgid "Authorization failed.\n"
msgstr "Autoryzacja nie powiod³a siê.\n"

#: src/http.c:1274
msgid "Unknown authentication scheme.\n"
msgstr "Nieznana metoda uwierzytelniania.\n"

#: src/http.c:1314
#, c-format
msgid "Location: %s%s\n"
msgstr "Lokalizacja: %s%s\n"

#: src/http.c:1315 src/http.c:1454
msgid "unspecified"
msgstr "nieznana"

#: src/http.c:1316
msgid " [following]"
msgstr " [pod±¿anie]"

#: src/http.c:1383
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
