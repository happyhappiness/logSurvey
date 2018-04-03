msgid "%s: option requires an argument -- %c\n"
msgstr "%s: opcja wymaga argumentu -- %c\n"

#: src/host.c:394
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: Nie mo¿na znale¼æ identyfikatora u¿ytkownika.\n"

#: src/host.c:406
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: Ostrze¿enie: uname nie powiod³o siê: %s\n"

#: src/host.c:418
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: Ostrze¿enie: gethostname nie powiod³o siê\n"

#: src/host.c:446
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: Ostrze¿enie: nie mo¿na uzyskaæ lokalnego adresu IP.\n"

#: src/host.c:460
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr "%s: Ostrze¿enie: nie mo¿na znale¼æ nazwy lokalnego adresu IP.\n"

#. This gets ticked pretty often.  Karl Berry reports
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

#. this is fatal
#: src/http.c:549
msgid "Failed to set up an SSL context\n"
msgstr ""

#: src/http.c:555
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr ""

#: src/http.c:559 src/http.c:567
msgid "Trying without the specified certificate\n"
msgstr ""

#: src/http.c:563
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr ""

#: src/http.c:657 src/http.c:1470
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:665
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Nast±pi± próby po³±czenia z %s:%hu.\n"

#: src/http.c:841
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Nie powiod³o siê wysy³anie ¿±dania HTTP.\n"

#: src/http.c:846
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "¯±danie %s wys³ano, oczekiwanie na odpowied¼... "

#: src/http.c:890
msgid "End of file while parsing headers.\n"
msgstr "Wyst±pi³ koniec pliku podczas skanowania nag³ówków.\n"

#: src/http.c:901
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "B³±d odczytu (%s) w nag³ówkach.\n"

#: src/http.c:941
msgid "No data received"
msgstr "Brak danych w odpowiedzi"

#: src/http.c:943
msgid "Malformed status line"
msgstr "¬le sformu³owana linia statusu"

#: src/http.c:948
msgid "(no description)"
msgstr "(brak opisu)"

#: src/http.c:1066
msgid "Authorization failed.\n"
msgstr "Autoryzacja nie powiod³a siê.\n"

#: src/http.c:1073
msgid "Unknown authentication scheme.\n"
msgstr "Nieznana metoda uwierzytelnienia.\n"

#: src/http.c:1163
#, c-format
msgid "Location: %s%s\n"
msgstr "Lokalizacja: %s%s\n"

#: src/http.c:1164 src/http.c:1189
msgid "unspecified"
msgstr "nieznana"

#: src/http.c:1165
msgid " [following]"
msgstr " [pod±¿am]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1179
msgid "Length: "
msgstr "D³ugo¶æ: "

#: src/http.c:1184
#, c-format
msgid " (%s to go)"
msgstr " (%s do koñca)"

#: src/http.c:1189
msgid "ignored"
msgstr "zignorowano"

#: src/http.c:1290
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Ostrze¿enie: znaki globalne nie s± wspierane w HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1311
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Plik `%s' ju¿ tu jest, nie ¶ci±gam.\n"

#: src/http.c:1462
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nie mo¿na zapisywaæ do `%s' (%s).\n"

#: src/http.c:1480
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "B£¡D: Przekierowywanie (%d) bez lokalizacji.\n"

#: src/http.c:1505
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s B£¡D %d: %s.\n"

#: src/http.c:1518
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Brak nag³ówka Last-modified -- wy³±czanie znaczników czasu.\n"

#: src/http.c:1526
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "B³êdny nag³ówek Last-modified -- znacznik czasu zignorowany.\n"

#: src/http.c:1549
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"Plik po stronie serwera starszy ni¿ plik lokalny `%s' -- nie przesy³am.\n"

#: src/http.c:1557
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Rozmiary nie pasuj± (lokalny %ld) -- ¶ci±ganie.\n"

#: src/http.c:1561
msgid "Remote file is newer, retrieving.\n"
msgstr "Plik na zdalnym serwerze jest nowszy, ¶ci±ganie.\n"

#: src/http.c:1606
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
