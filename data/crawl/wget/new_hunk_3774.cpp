#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:473
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Ostrze¿enie: zapytanie odwrotnego DNSu o lokalny adres nie zwróci³o "
"FQDN!\n"

#: src/host.c:501
msgid "Host not found"
msgstr "Host nie zosta³ znaleziony"

#: src/host.c:503
msgid "Unknown error"
msgstr "Nieznany b³±d"

#: src/http.c:625 src/http.c:1437
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:633
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Nast±pi± próby po³±czenia z %s:%hu.\n"

#: src/http.c:809
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Nie powiod³o siê wysy³anie ¿±dania HTTP.\n"

#: src/http.c:814
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "¯±danie %s wys³ano, oczekiwanie na odpowied¼... "

#: src/http.c:858
msgid "End of file while parsing headers.\n"
msgstr "Wyst±pi³ koniec pliku podczas skanowania nag³ówków.\n"

#: src/http.c:869
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "B³±d odczytu (%s) w nag³ówkach.\n"

#: src/http.c:909
msgid "No data received"
msgstr "Brak danych w odpowiedzi"

#: src/http.c:911
msgid "Malformed status line"
msgstr "¬le sformu³owana linia statusu"

#: src/http.c:916
msgid "(no description)"
msgstr "(brak opisu)"

#: src/http.c:1034
msgid "Authorization failed.\n"
msgstr "Autoryzacja nie powiod³a siê.\n"

#: src/http.c:1041
msgid "Unknown authentication scheme.\n"
msgstr "Nieznana metoda uwierzytelnienia.\n"

#: src/http.c:1131
#, c-format
msgid "Location: %s%s\n"
msgstr "Lokalizacja: %s%s\n"

#: src/http.c:1132 src/http.c:1157
msgid "unspecified"
msgstr "nieznana"

#: src/http.c:1133
msgid " [following]"
msgstr " [pod±¿am]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1147
msgid "Length: "
msgstr "D³ugo¶æ: "

#: src/http.c:1152
#, c-format
msgid " (%s to go)"
msgstr " (%s do koñca)"

#: src/http.c:1157
msgid "ignored"
msgstr "zignorowano"

#: src/http.c:1258
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Ostrze¿enie: znaki globalne nie s± wspierane w HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1279
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Plik `%s' ju¿ tu jest, nie ¶ci±gam.\n"

#: src/http.c:1429
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nie mo¿na zapisywaæ do `%s' (%s).\n"

#: src/http.c:1447
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "B£¡D: Przekierowywanie (%d) bez lokalizacji.\n"

#: src/http.c:1472
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s B£¡D %d: %s.\n"

#: src/http.c:1485
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Brak nag³ówka Last-modified -- wy³±czanie znaczników czasu.\n"

#: src/http.c:1493
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "B³êdny nag³ówek Last-modified -- znacznik czasu zignorowany.\n"

#: src/http.c:1528
msgid "Remote file is newer, retrieving.\n"
msgstr "Plik na zdalnym serwerze jest nowszy, ¶ci±ganie.\n"

#: src/http.c:1573
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
