 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: opcja wymaga argumentu -- %c\n"
 
-#: src/host.c:394
+#: src/host.c:438
 #, c-format
 msgid "%s: Cannot determine user-id.\n"
-msgstr "%s: Nie mog? okre?li? identyfikatora u?ytkownika.\n"
+msgstr "%s: Nie mo¿na znale¼æ identyfikatora u¿ytkownika.\n"
 
-#: src/host.c:406
+#: src/host.c:450
 #, c-format
 msgid "%s: Warning: uname failed: %s\n"
-msgstr "%s: Ostrze?enie: wykonanie uname nie powiod?o si?: %s\n"
+msgstr "%s: Ostrze¿enie: uname nie powiod³o siê: %s\n"
 
-#: src/host.c:418
+#: src/host.c:462
 #, c-format
 msgid "%s: Warning: gethostname failed\n"
-msgstr "%s: Ostrze?enie: wykonanie gethostname nie powiod?o si?\n"
+msgstr "%s: Ostrze¿enie: gethostname nie powiod³o siê\n"
 
-#: src/host.c:446
+#: src/host.c:490
 #, c-format
 msgid "%s: Warning: cannot determine local IP address.\n"
-msgstr "%s: Ostrze?enie: nie mog? okre?li? lokalnego adresu IP.\n"
+msgstr "%s: Ostrze¿enie: nie mo¿na uzyskaæ lokalnego adresu IP.\n"
 
-#: src/host.c:460
+#: src/host.c:504
 #, c-format
 msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
-msgstr "%s: Ostrze?enie: nie mog? odszuka? lokalnego adresu IP.\n"
+msgstr "%s: Ostrze¿enie: nie mo¿na znale¼æ nazwy lokalnego adresu IP.\n"
 
 #. This gets ticked pretty often.  Karl Berry reports
 #. that there can be valid reasons for the local host
 #. name not to be an FQDN, so I've decided to remove the
 #. annoying warning.
-#: src/host.c:473
+#: src/host.c:517
 #, c-format
 msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
-msgstr "%s: Ostrze?enie: odszukanie lokalnego adresu nie wyprodukowa?o FQDN!\n"
+msgstr ""
+"%s: Ostrze¿enie: zapytanie odwrotnego DNSu o lokalny adres nie zwróci³o "
+"FQDN!\n"
 
-#: src/host.c:501
+#: src/host.c:545
 msgid "Host not found"
-msgstr "Serwer nie zosta? odnaleziony"
+msgstr "Host nie zosta³ znaleziony"
 
-#: src/host.c:503
+#: src/host.c:547
 msgid "Unknown error"
-msgstr "Nieznany b??d"
+msgstr "Nieznany b³±d"
 
-#: src/http.c:621 src/http.c:1433
-msgid "Unable to establish SSL connection.\n"
-msgstr ""
+#: src/html.c:615 src/html.c:617
+#, c-format
+msgid "Index of /%s on %s:%d"
+msgstr "Indeks /%s na %s:%d"
 
-#: src/http.c:629
-#, fuzzy, c-format
-msgid "Reusing connection to %s:%hu.\n"
-msgstr "Spróbuj? po??czy? si? z %s:%hu.\n"
+#: src/html.c:639
+msgid "time unknown       "
+msgstr "czas nieznany      "
 
-#: src/http.c:805
-#, fuzzy, c-format
-msgid "Failed writing HTTP request: %s.\n"
-msgstr "Zapisanie ??dania o HTTP nie powiod?o si?.\n"
+#: src/html.c:643
+msgid "File        "
+msgstr "Plik         "
 
-#: src/http.c:810
+#: src/html.c:646
+msgid "Directory   "
+msgstr "Katalog     "
+
+#: src/html.c:649
+msgid "Link        "
+msgstr "Odno¶nik    "
+
+#: src/html.c:652
+msgid "Not sure    "
+msgstr "Nie pewny   "
+
+#: src/html.c:670
+#, c-format
+msgid " (%s bytes)"
+msgstr " (%s bajtów)"
+
+#: src/http.c:512
+msgid "Failed writing HTTP request.\n"
+msgstr "Nie powiod³o siê wysy³anie ¿±dania HTTP.\n"
+
+#: src/http.c:516
 #, c-format
 msgid "%s request sent, awaiting response... "
-msgstr "??danie o %s zosta?o wys?ane, oczekiwanie na odpowied?... "
+msgstr "¯±danie %s wys³ano, oczekiwanie na odpowied¼... "
 
-#: src/http.c:854
+#: src/http.c:555
 msgid "End of file while parsing headers.\n"
-msgstr "Wyst?pi? koniec pliku podczas przetwarzania nag?ówków.\n"
+msgstr "Wyst±pi³ koniec pliku podczas skanowania nag³ówków.\n"
 
-#: src/http.c:865
+#: src/http.c:566
 #, c-format
 msgid "Read error (%s) in headers.\n"
-msgstr "B??d odczytu (%s) w nag?ówkach.\n"
+msgstr "B³±d odczytu (%s) w nag³ówkach.\n"
 
-#: src/http.c:905
+#: src/http.c:606
 msgid "No data received"
-msgstr "Nie pobrano ?adnych danych"
+msgstr "Brak danych w odpowiedzi"
 
-#: src/http.c:907
+#: src/http.c:608
 msgid "Malformed status line"
-msgstr "Zniekszta?cona linia stanu"
+msgstr "¬le sformu³owana linia statusu"
 
-#: src/http.c:912
+#: src/http.c:613
 msgid "(no description)"
 msgstr "(brak opisu)"
 
-#: src/http.c:1030
+#. If we have tried it already, then there is not point
+#. retrying it.
+#: src/http.c:697
 msgid "Authorization failed.\n"
-msgstr "Autoryzacja nie powiod?a si?.\n"
+msgstr "Autoryzacja nie powiod³a siê.\n"
 
-#: src/http.c:1037
+#: src/http.c:704
 msgid "Unknown authentication scheme.\n"
-msgstr "Nieznany schemat autentyfikacji.\n"
+msgstr "Nieznana metoda uwierzytelnienia.\n"
 
-#: src/http.c:1127
+#: src/http.c:787
 #, c-format
 msgid "Location: %s%s\n"
-msgstr "Po?o?enie: %s%s\n"
+msgstr "Lokalizacja: %s%s\n"
 
-#: src/http.c:1128 src/http.c:1153
+#: src/http.c:788 src/http.c:813
 msgid "unspecified"
-msgstr "nieokre?lony"
+msgstr "nieznana"
 
-#: src/http.c:1129
+#: src/http.c:789
 msgid " [following]"
-msgstr " [nast?puj?cy]"
+msgstr " [pod±¿am]"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1143
+#: src/http.c:803
 msgid "Length: "
-msgstr "D?ugo??: "
+msgstr "D³ugo¶æ: "
 
-#: src/http.c:1148
+#: src/http.c:808
 #, c-format
 msgid " (%s to go)"
-msgstr " (pozosta?o %s)"
+msgstr " (%s do koñca)"
 
-#: src/http.c:1153
+#: src/http.c:813
 msgid "ignored"
 msgstr "zignorowano"
 
-#: src/http.c:1254
+#: src/http.c:914
 msgid "Warning: wildcards not supported in HTTP.\n"
-msgstr "Ostrze?enie: znaki specjalne nie s? obs?ugiwane z HTTP.\n"
+msgstr "Ostrze¿enie: znaki globalne nie s± wspierane w HTTP.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:1275
+#: src/http.c:935
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
-msgstr "Plik `%s' ju? tam jest, wi?c nie zostanie pobrany.\n"
+msgstr "Plik `%s' ju¿ tu jest, nie ¶ci±gam.\n"
 
-#: src/http.c:1425
+#: src/http.c:1085
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
-msgstr "Nie mog? zapisa? do `%s' (%s).\n"
+msgstr "Nie mo¿na zapisywaæ do `%s' (%s).\n"
 
-#: src/http.c:1443
+#: src/http.c:1096
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
-msgstr "B??D: Przekierowanie (%d) bez po?o?enia.\n"
+msgstr "B£¡D: Przekierowywanie (%d) bez lokalizacji.\n"
 
-#: src/http.c:1468
+#: src/http.c:1121
 #, c-format
 msgid "%s ERROR %d: %s.\n"
-msgstr "%s B??D %d: %s.\n"
+msgstr "%s B£¡D %d: %s.\n"
 
-#: src/http.c:1481
+#: src/http.c:1134
 msgid "Last-modified header missing -- time-stamps turned off.\n"
-msgstr ""
-"Brak nag?ówka ostatniej modyfikacji -- znaczniki czasowe zosta?y wy??czone.\n"
+msgstr "Brak nag³ówka Last-modified -- wy³±czanie znaczników czasu.\n"
 
-#: src/http.c:1489
+#: src/http.c:1142
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
-msgstr ""
-"Nieprawid?owy nag?ówek ostatniej modyfikacji -- znacznik czasowy zosta? "
-"zignorowany.\n"
+msgstr "B³êdny nag³ówek Last-modified -- znacznik czasu zignorowany.\n"
 
-#: src/http.c:1524
+#: src/http.c:1177
 msgid "Remote file is newer, retrieving.\n"
-msgstr "Odleg?y plik jest nowszy, wi?c pobieram go.\n"
+msgstr "Plik na zdalnym serwerze jest nowszy, ¶ci±ganie.\n"
 
-#: src/http.c:1559
+#: src/http.c:1222
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld]\n"
 "\n"
 msgstr ""
-"%s (%s) - `%s' zosta? zapisany [%ld/%ld]\n"
+"%s (%s) - zapisano `%s' [%ld/%ld]\n"
 "\n"
 
-#: src/http.c:1607
+#: src/http.c:1270
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld. "
-msgstr "%s (%s) - Po??czenie zosta?o zamkni?te przy bajcie %ld. "
+msgstr "%s (%s) - Po³±czenie zamkniête przy %ld bajcie. "
 
-#: src/http.c:1615
+#: src/http.c:1278
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld])\n"
 "\n"
 msgstr ""
-"%s (%s) - `%s' zosta? zapisany [%ld/%ld])\n"
+"%s (%s) - zapisano `%s' [%ld/%ld])\n"
 "\n"
 
-#: src/http.c:1635
+#: src/http.c:1298
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld/%ld. "
-msgstr "%s (%s) - Po??czenie zosta?o zamkni?te przy bajcie %ld/%ld. "
+msgstr "%s (%s) - Po³±czenie zamkniête przy %ld/%ld bajcie."
 
-#: src/http.c:1646
+#: src/http.c:1309
 #, c-format
 msgid "%s (%s) - Read error at byte %ld (%s)."
-msgstr "%s (%s) - B??d odczytu przy bajcie %ld (%s)."
+msgstr "%s (%s) - B³±d podczas odczytu przy bajcie %ld (%s)."
 
-#: src/http.c:1654
+#: src/http.c:1317
 #, c-format
 msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
-msgstr "%s (%s) - B??d odczytu przy bajcie %ld/%ld (%s). "
+msgstr "%s (%s) - B³±d podczas odczytu przy bajcie %ld/%ld (%s). "
 
-#: src/init.c:332 src/netrc.c:261
+#: src/init.c:329 src/netrc.c:260
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
-msgstr "%s: Nie mog? odczyta? %s (%s).\n"
+msgstr "%s: Nie mo¿na odczytaæ %s (%s).\n"
 
-#: src/init.c:350 src/init.c:356
+#: src/init.c:347 src/init.c:353
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
-msgstr "%s: B??d w %s w linii %d.\n"
+msgstr "%s: B³±d w %s w lini %d.\n"
 
-#: src/init.c:387
+#: src/init.c:384
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
 msgstr ""
-"%s: Ostrze?enie: Zarówno plik systemowy wgetrc jak i u?ytkownika odnosz? si? "
-"do `%s'.\n"
+"%s: Ostrze¿enie: Zarówno wgetrc systemowy jak i u¿ytkownika wskazuj± na "
+"`%s'.\n"
 
-#: src/init.c:479
+#: src/init.c:476
 #, c-format
 msgid "%s: BUG: unknown command `%s', value `%s'.\n"
-msgstr "%s: B??D W PROGRAMIE: nieznane polecenie `%s', warto?? `%s'.\n"
-
-#: src/init.c:501
-#, fuzzy, c-format
-msgid "%s: Out of memory.\n"
-msgstr "%s: %s: Brak pami?ci.\n"
+msgstr "%s: BUG: nieznana komenda `%s', warto¶æ `%s'.\n"
 
-#: src/init.c:507
-#, fuzzy, c-format
+#: src/init.c:497
+#, c-format
 msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
-msgstr "%s: Ostrze?enie: nie mog? odszuka? lokalnego adresu IP.\n"
+msgstr "%s: %s: Nie mo¿na skonwertowaæ `%s' do adresu IP.\n"
 
-#: src/init.c:535
+#: src/init.c:525
 #, c-format
 msgid "%s: %s: Please specify on or off.\n"
-msgstr "%s: %s: Prosz? okre?li?: on lub off.\n"
+msgstr "%s: %s: Proszê podaæ on lub off.\n"
 
-#: src/init.c:579
-#, fuzzy, c-format
+#: src/init.c:569
+#, c-format
 msgid "%s: %s: Please specify always, on, off, or never.\n"
-msgstr "%s: %s: Prosz? okre?li?: on lub off.\n"
+msgstr "%s: %s: Proszê podaæ: zawsze, on, off lub never.\n"
 
-#: src/init.c:598 src/init.c:855 src/init.c:877 src/init.c:941
+#: src/init.c:588 src/init.c:845 src/init.c:867 src/init.c:931
 #, c-format
 msgid "%s: %s: Invalid specification `%s'.\n"
-msgstr "%s: %s: Nieprawid?owa specyfikacja `%s'.\n"
+msgstr "%s: %s: Nieprawid³owa specyfikacja `%s'.\n"
 
-#: src/init.c:711 src/init.c:733 src/init.c:755 src/init.c:781
+#: src/init.c:701 src/init.c:723 src/init.c:745 src/init.c:771
 #, c-format
 msgid "%s: Invalid specification `%s'\n"
-msgstr "%s: Nieprawid?owa specyfikacja `%s'\n"
+msgstr "%s: Nieprawid³owa specyfikacja `%s`\n"
 
-#: src/main.c:119
+#: src/main.c:106
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
-msgstr "U?ycie: %s [OPCJA]... [URL]...\n"
+msgstr "U¿ycie: %s [OPCJE]... [URL]...\n"
 
-#: src/main.c:127
+#: src/main.c:114
 #, c-format
 msgid "GNU Wget %s, a non-interactive network retriever.\n"
-msgstr "GNU Wget %s, nieinteraktywna ?ci?garka sieciowa.\n"
+msgstr "GNU Wget %s, nie-interaktywny ¶ci±gacz sieciowy.\n"
 
 #. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
 #. don't bitch.  Also, it makes translation much easier.
-#: src/main.c:132
+#: src/main.c:119
 msgid ""
 "\n"
 "Mandatory arguments to long options are mandatory for short options too.\n"
 "\n"
 msgstr ""
 "\n"
-"Argumenty obowi?zkowe dla opcji d?ugich s? równie? obowi?zkowe dla opcji "
-"krótkich.\n"
+"Obowi±zkowe argumenty d³ugich opcji s± te¿ obowi±zkowe dla opcji krótkich.\n"
 "\n"
 
-#: src/main.c:135
-#, fuzzy
+#: src/main.c:122
 msgid ""
 "Startup:\n"
 "  -V,  --version           display the version of Wget and exit.\n"
