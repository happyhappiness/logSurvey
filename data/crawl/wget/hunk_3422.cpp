 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: opcja wymaga argumentu -- %c\n"
 
-#: src/host.c:394
-#, c-format
-msgid "%s: Cannot determine user-id.\n"
-msgstr "%s: Nie mo�na znale�� identyfikatora u�ytkownika.\n"
-
-#: src/host.c:406
-#, c-format
-msgid "%s: Warning: uname failed: %s\n"
-msgstr "%s: Ostrze�enie: uname nie powiod�o si�: %s\n"
-
-#: src/host.c:418
-#, c-format
-msgid "%s: Warning: gethostname failed\n"
-msgstr "%s: Ostrze�enie: gethostname nie powiod�o si�\n"
-
-#: src/host.c:446
+#: src/host.c:271
 #, c-format
-msgid "%s: Warning: cannot determine local IP address.\n"
-msgstr "%s: Ostrze�enie: nie mo�na uzyska� lokalnego adresu IP.\n"
+msgid "Resolving %s... "
+msgstr "Translacja %s... "
 
-#: src/host.c:460
+#: src/host.c:278
 #, c-format
-msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
-msgstr "%s: Ostrze�enie: nie mo�na znale�� nazwy lokalnego adresu IP.\n"
+msgid "failed: %s.\n"
+msgstr "nieudane: %s.\n"
 
-#. This gets ticked pretty often.  Karl Berry reports
-#. that there can be valid reasons for the local host
-#. name not to be an FQDN, so I've decided to remove the
-#. annoying warning.
-#: src/host.c:473
-#, c-format
-msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
-msgstr ""
-"%s: Ostrze�enie: zapytanie odwrotnego DNSu o lokalny adres nie zwr�ci�o "
-"FQDN!\n"
-
-#: src/host.c:501
+#: src/host.c:348
 msgid "Host not found"
 msgstr "Host nie zosta� znaleziony"
 
-#: src/host.c:503
+#: src/host.c:350
 msgid "Unknown error"
 msgstr "Nieznany b��d"
 
+#: src/html-url.c:336
+#, c-format
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr "%s: Nie mo�na rozwik�a� niepe�nego odno�nika %s.\n"
+
 #. this is fatal
-#: src/http.c:549
+#: src/http.c:573
 msgid "Failed to set up an SSL context\n"
-msgstr ""
+msgstr "Nieudane ustawianie kontekstu SSL\n"
 
-#: src/http.c:555
+#: src/http.c:579
 #, c-format
 msgid "Failed to load certificates from %s\n"
-msgstr ""
+msgstr "Nie uda�o si� wczyta� certyfikat�w z %s\n"
 
-#: src/http.c:559 src/http.c:567
+#: src/http.c:583 src/http.c:591
 msgid "Trying without the specified certificate\n"
-msgstr ""
+msgstr "Pr�bowanie bez podanego certyfikatu\n"
 
-#: src/http.c:563
+#: src/http.c:587
 #, c-format
 msgid "Failed to get certificate key from %s\n"
-msgstr ""
+msgstr "Nie uda�o si� uzyska� klucza certyfikatu z %s\n"
 
-#: src/http.c:657 src/http.c:1470
+#: src/http.c:657 src/http.c:1620
 msgid "Unable to establish SSL connection.\n"
-msgstr ""
+msgstr "Niemo�liwe utworzenie po��czenia SSL.\n"
 
-#: src/http.c:665
-#, fuzzy, c-format
+#: src/http.c:666
+#, c-format
 msgid "Reusing connection to %s:%hu.\n"
-msgstr "Nast�pi� pr�by po��czenia z %s:%hu.\n"
+msgstr "Ponowne u�ycie po��czenia do %s:%hu.\n"
 
-#: src/http.c:841
-#, fuzzy, c-format
+#: src/http.c:868
+#, c-format
 msgid "Failed writing HTTP request: %s.\n"
-msgstr "Nie powiod�o si� wysy�anie ��dania HTTP.\n"
+msgstr "Nie powiod�o si� wysy�anie ��dania HTTP: %s.\n"
 
-#: src/http.c:846
+#: src/http.c:873
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "��danie %s wys�ano, oczekiwanie na odpowied�... "
 
-#: src/http.c:890
+#: src/http.c:917
 msgid "End of file while parsing headers.\n"
-msgstr "Wyst�pi� koniec pliku podczas skanowania nag��wk�w.\n"
+msgstr "Podczas analizy nag��wk�w wyst�pi� koniec pliku.\n"
 
-#: src/http.c:901
+#: src/http.c:927
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "B��d odczytu (%s) w nag��wkach.\n"
 
-#: src/http.c:941
+#: src/http.c:962
 msgid "No data received"
 msgstr "Brak danych w odpowiedzi"
 
-#: src/http.c:943
+#: src/http.c:964
 msgid "Malformed status line"
 msgstr "�le sformu�owana linia statusu"
 
-#: src/http.c:948
+#: src/http.c:969
 msgid "(no description)"
 msgstr "(brak opisu)"
 
-#: src/http.c:1066
+#: src/http.c:1101
 msgid "Authorization failed.\n"
 msgstr "Autoryzacja nie powiod�a si�.\n"
 
-#: src/http.c:1073
+#: src/http.c:1108
 msgid "Unknown authentication scheme.\n"
-msgstr "Nieznana metoda uwierzytelnienia.\n"
+msgstr "Nieznana metoda uwierzytelniania.\n"
 
-#: src/http.c:1163
+#: src/http.c:1148
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Lokalizacja: %s%s\n"
 
-#: src/http.c:1164 src/http.c:1189
+#: src/http.c:1149 src/http.c:1282
 msgid "unspecified"
 msgstr "nieznana"
 
-#: src/http.c:1165
+#: src/http.c:1150
 msgid " [following]"
-msgstr " [pod��am]"
+msgstr " [pod��anie]"
+
+#: src/http.c:1213
+msgid ""
+"\n"
+"    The file is already fully retrieved; nothing to do.\n"
+"\n"
+msgstr ""
+"\n"
+"    Plik ju� zosta� w pe�ni pobrany; nic do roboty.\n"
+"\n"
+
+#: src/http.c:1229
+#, c-format
+msgid ""
+"\n"
+"Continued download failed on this file, which conflicts with `-c'.\n"
+"Refusing to truncate existing file `%s'.\n"
+"\n"
+msgstr ""
+"\n"
+"Kontynuacja �ci�gania tego pliku nie powiod�a si�, co koliduje z `-c'.\n"
+"Odmowa obci�cia istniej�cego pliku `%s'.\n"
+"\n"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1179
+#: src/http.c:1272
 msgid "Length: "
 msgstr "D�ugo��: "
 
-#: src/http.c:1184
+#: src/http.c:1277
 #, c-format
 msgid " (%s to go)"
 msgstr " (%s do ko�ca)"
 
-#: src/http.c:1189
+#: src/http.c:1282
 msgid "ignored"
 msgstr "zignorowano"
 
-#: src/http.c:1290
+#: src/http.c:1413
 msgid "Warning: wildcards not supported in HTTP.\n"
-msgstr "Ostrze�enie: znaki globalne nie s� wspierane w HTTP.\n"
+msgstr "Ostrze�enie: znaki globalne nie s� obs�ugiwane w HTTP.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:1311
+#: src/http.c:1443
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
-msgstr "Plik `%s' ju� tu jest, nie �ci�gam.\n"
+msgstr "Plik `%s' ju� tu jest. Nie zostanie pobrany.\n"
 
-#: src/http.c:1462
+#: src/http.c:1611
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
-msgstr "Nie mo�na zapisywa� do `%s' (%s).\n"
+msgstr "Nie mo�na zapisa� do `%s' (%s).\n"
 
-#: src/http.c:1480
+#: src/http.c:1630
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
-msgstr "B��D: Przekierowywanie (%d) bez lokalizacji.\n"
+msgstr "B��D: Przekierowanie (%d) bez lokalizacji.\n"
 
-#: src/http.c:1505
+#: src/http.c:1662
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s B��D %d: %s.\n"
 
-#: src/http.c:1518
+#: src/http.c:1675
 msgid "Last-modified header missing -- time-stamps turned off.\n"
-msgstr "Brak nag��wka Last-modified -- wy��czanie znacznik�w czasu.\n"
+msgstr "Brak nag��wka Last-modified -- znaczniki czasu wy��czone.\n"
 
-#: src/http.c:1526
+#: src/http.c:1683
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "B��dny nag��wek Last-modified -- znacznik czasu zignorowany.\n"
 
-#: src/http.c:1549
+#: src/http.c:1706
 #, c-format
 msgid ""
 "Server file no newer than local file `%s' -- not retrieving.\n"
 "\n"
-msgstr ""
-"Plik po stronie serwera starszy ni� plik lokalny `%s' -- nie przesy�am.\n"
+msgstr "Plik po stronie serwera nie nowszy ni� plik lokalny `%s' -- bez pobierania.\n"
 
-#: src/http.c:1557
+#: src/http.c:1714
 #, c-format
 msgid "The sizes do not match (local %ld) -- retrieving.\n"
-msgstr "Rozmiary nie pasuj� (lokalny %ld) -- �ci�ganie.\n"
+msgstr "Rozmiary nie pasuj� (lokalny %ld) -- pobieranie.\n"
 
-#: src/http.c:1561
+#: src/http.c:1718
 msgid "Remote file is newer, retrieving.\n"
-msgstr "Plik na zdalnym serwerze jest nowszy, �ci�ganie.\n"
+msgstr "Plik na zdalnym serwerze jest nowszy, pobieranie.\n"
 
-#: src/http.c:1606
+#: src/http.c:1759
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld]\n"
