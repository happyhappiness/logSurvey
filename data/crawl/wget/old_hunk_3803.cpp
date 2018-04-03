msgid "%s: option requires an argument -- %c\n"
msgstr "%s: opcja wymaga argumentu -- %c\n"

#: src/host.c:394
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: Nie mog? okre?li? identyfikatora u?ytkownika.\n"

#: src/host.c:406
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: Ostrze?enie: wykonanie uname nie powiod?o si?: %s\n"

#: src/host.c:418
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: Ostrze?enie: wykonanie gethostname nie powiod?o si?\n"

#: src/host.c:446
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: Ostrze?enie: nie mog? okre?li? lokalnego adresu IP.\n"

#: src/host.c:460
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr "%s: Ostrze?enie: nie mog? odszuka? lokalnego adresu IP.\n"

#. This gets ticked pretty often.  Karl Berry reports
#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:473
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr "%s: Ostrze?enie: odszukanie lokalnego adresu nie wyprodukowa?o FQDN!\n"

#: src/host.c:501
msgid "Host not found"
msgstr "Serwer nie zosta? odnaleziony"

#: src/host.c:503
msgid "Unknown error"
msgstr "Nieznany b??d"

#: src/http.c:621 src/http.c:1433
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:629
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Spróbuj? po??czy? si? z %s:%hu.\n"

#: src/http.c:805
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Zapisanie ??dania o HTTP nie powiod?o si?.\n"

#: src/http.c:810
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "??danie o %s zosta?o wys?ane, oczekiwanie na odpowied?... "

#: src/http.c:854
msgid "End of file while parsing headers.\n"
msgstr "Wyst?pi? koniec pliku podczas przetwarzania nag?ówków.\n"

#: src/http.c:865
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "B??d odczytu (%s) w nag?ówkach.\n"

#: src/http.c:905
msgid "No data received"
msgstr "Nie pobrano ?adnych danych"

#: src/http.c:907
msgid "Malformed status line"
msgstr "Zniekszta?cona linia stanu"

#: src/http.c:912
msgid "(no description)"
msgstr "(brak opisu)"

#: src/http.c:1030
msgid "Authorization failed.\n"
msgstr "Autoryzacja nie powiod?a si?.\n"

#: src/http.c:1037
msgid "Unknown authentication scheme.\n"
msgstr "Nieznany schemat autentyfikacji.\n"

#: src/http.c:1127
#, c-format
msgid "Location: %s%s\n"
msgstr "Po?o?enie: %s%s\n"

#: src/http.c:1128 src/http.c:1153
msgid "unspecified"
msgstr "nieokre?lony"

#: src/http.c:1129
msgid " [following]"
msgstr " [nast?puj?cy]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1143
msgid "Length: "
msgstr "D?ugo??: "

#: src/http.c:1148
#, c-format
msgid " (%s to go)"
msgstr " (pozosta?o %s)"

#: src/http.c:1153
msgid "ignored"
msgstr "zignorowano"

#: src/http.c:1254
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Ostrze?enie: znaki specjalne nie s? obs?ugiwane z HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1275
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Plik `%s' ju? tam jest, wi?c nie zostanie pobrany.\n"

#: src/http.c:1425
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nie mog? zapisa? do `%s' (%s).\n"

#: src/http.c:1443
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "B??D: Przekierowanie (%d) bez po?o?enia.\n"

#: src/http.c:1468
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s B??D %d: %s.\n"

#: src/http.c:1481
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Brak nag?ówka ostatniej modyfikacji -- znaczniki czasowe zosta?y wy??czone.\n"

#: src/http.c:1489
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Nieprawid?owy nag?ówek ostatniej modyfikacji -- znacznik czasowy zosta? "
"zignorowany.\n"

#: src/http.c:1524
msgid "Remote file is newer, retrieving.\n"
msgstr "Odleg?y plik jest nowszy, wi?c pobieram go.\n"

#: src/http.c:1559
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' zosta? zapisany [%ld/%ld]\n"
"\n"

#: src/http.c:1607
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Po??czenie zosta?o zamkni?te przy bajcie %ld. "

#: src/http.c:1615
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - `%s' zosta? zapisany [%ld/%ld])\n"
"\n"

#: src/http.c:1635
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Po??czenie zosta?o zamkni?te przy bajcie %ld/%ld. "

#: src/http.c:1646
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - B??d odczytu przy bajcie %ld (%s)."

#: src/http.c:1654
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - B??d odczytu przy bajcie %ld/%ld (%s). "

#: src/init.c:332 src/netrc.c:261
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Nie mog? odczyta? %s (%s).\n"

#: src/init.c:350 src/init.c:356
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: B??d w %s w linii %d.\n"

#: src/init.c:387
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Ostrze?enie: Zarówno plik systemowy wgetrc jak i u?ytkownika odnosz? si? "
"do `%s'.\n"

#: src/init.c:479
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: B??D W PROGRAMIE: nieznane polecenie `%s', warto?? `%s'.\n"

#: src/init.c:501
#, fuzzy, c-format
msgid "%s: Out of memory.\n"
msgstr "%s: %s: Brak pami?ci.\n"

#: src/init.c:507
#, fuzzy, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: Ostrze?enie: nie mog? odszuka? lokalnego adresu IP.\n"

#: src/init.c:535
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Prosz? okre?li?: on lub off.\n"

#: src/init.c:579
#, fuzzy, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Prosz? okre?li?: on lub off.\n"

#: src/init.c:598 src/init.c:855 src/init.c:877 src/init.c:941
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Nieprawid?owa specyfikacja `%s'.\n"

#: src/init.c:711 src/init.c:733 src/init.c:755 src/init.c:781
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Nieprawid?owa specyfikacja `%s'\n"

#: src/main.c:119
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "U?ycie: %s [OPCJA]... [URL]...\n"

#: src/main.c:127
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, nieinteraktywna ?ci?garka sieciowa.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:132
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Argumenty obowi?zkowe dla opcji d?ugich s? równie? obowi?zkowe dla opcji "
"krótkich.\n"
"\n"

#: src/main.c:135
#, fuzzy
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
