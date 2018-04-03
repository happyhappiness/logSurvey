#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:517
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Ostrze¿enie: zapytanie odwrotnego DNSu o lokalny adres nie zwróci³o "
"FQDN!\n"

#: src/host.c:545
msgid "Host not found"
msgstr "Host nie zosta³ znaleziony"

#: src/host.c:547
msgid "Unknown error"
msgstr "Nieznany b³±d"

#: src/html.c:615 src/html.c:617
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Indeks /%s na %s:%d"

#: src/html.c:639
msgid "time unknown       "
msgstr "czas nieznany      "

#: src/html.c:643
msgid "File        "
msgstr "Plik         "

#: src/html.c:646
msgid "Directory   "
msgstr "Katalog     "

#: src/html.c:649
msgid "Link        "
msgstr "Odno¶nik    "

#: src/html.c:652
msgid "Not sure    "
msgstr "Nie pewny   "

#: src/html.c:670
#, c-format
msgid " (%s bytes)"
msgstr " (%s bajtów)"

#: src/http.c:512
msgid "Failed writing HTTP request.\n"
msgstr "Nie powiod³o siê wysy³anie ¿±dania HTTP.\n"

#: src/http.c:516
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "¯±danie %s wys³ano, oczekiwanie na odpowied¼... "

#: src/http.c:555
msgid "End of file while parsing headers.\n"
msgstr "Wyst±pi³ koniec pliku podczas skanowania nag³ówków.\n"

#: src/http.c:566
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "B³±d odczytu (%s) w nag³ówkach.\n"

#: src/http.c:606
msgid "No data received"
msgstr "Brak danych w odpowiedzi"

#: src/http.c:608
msgid "Malformed status line"
msgstr "¬le sformu³owana linia statusu"

#: src/http.c:613
msgid "(no description)"
msgstr "(brak opisu)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:697
msgid "Authorization failed.\n"
msgstr "Autoryzacja nie powiod³a siê.\n"

#: src/http.c:704
msgid "Unknown authentication scheme.\n"
msgstr "Nieznana metoda uwierzytelnienia.\n"

#: src/http.c:787
#, c-format
msgid "Location: %s%s\n"
msgstr "Lokalizacja: %s%s\n"

#: src/http.c:788 src/http.c:813
msgid "unspecified"
msgstr "nieznana"

#: src/http.c:789
msgid " [following]"
msgstr " [pod±¿am]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:803
msgid "Length: "
msgstr "D³ugo¶æ: "

#: src/http.c:808
#, c-format
msgid " (%s to go)"
msgstr " (%s do koñca)"

#: src/http.c:813
msgid "ignored"
msgstr "zignorowano"

#: src/http.c:914
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Ostrze¿enie: znaki globalne nie s± wspierane w HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:935
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Plik `%s' ju¿ tu jest, nie ¶ci±gam.\n"

#: src/http.c:1085
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nie mo¿na zapisywaæ do `%s' (%s).\n"

#: src/http.c:1096
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "B£¡D: Przekierowywanie (%d) bez lokalizacji.\n"

#: src/http.c:1121
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s B£¡D %d: %s.\n"

#: src/http.c:1134
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Brak nag³ówka Last-modified -- wy³±czanie znaczników czasu.\n"

#: src/http.c:1142
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "B³êdny nag³ówek Last-modified -- znacznik czasu zignorowany.\n"

#: src/http.c:1177
msgid "Remote file is newer, retrieving.\n"
msgstr "Plik na zdalnym serwerze jest nowszy, ¶ci±ganie.\n"

#: src/http.c:1222
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
