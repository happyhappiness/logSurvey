 #. that there can be valid reasons for the local host
 #. name not to be an FQDN, so I've decided to remove the
 #. annoying warning.
-#: src/host.c:517
+#: src/host.c:473
 #, c-format
 msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
 msgstr ""
 "%s: Ostrze�enie: zapytanie odwrotnego DNSu o lokalny adres nie zwr�ci�o "
 "FQDN!\n"
 
-#: src/host.c:545
+#: src/host.c:501
 msgid "Host not found"
 msgstr "Host nie zosta� znaleziony"
 
-#: src/host.c:547
+#: src/host.c:503
 msgid "Unknown error"
 msgstr "Nieznany b��d"
 
-#: src/html.c:615 src/html.c:617
-#, c-format
-msgid "Index of /%s on %s:%d"
-msgstr "Indeks /%s na %s:%d"
-
-#: src/html.c:639
-msgid "time unknown       "
-msgstr "czas nieznany      "
-
-#: src/html.c:643
-msgid "File        "
-msgstr "Plik         "
-
-#: src/html.c:646
-msgid "Directory   "
-msgstr "Katalog     "
-
-#: src/html.c:649
-msgid "Link        "
-msgstr "Odno�nik    "
-
-#: src/html.c:652
-msgid "Not sure    "
-msgstr "Nie pewny   "
+#: src/http.c:625 src/http.c:1437
+msgid "Unable to establish SSL connection.\n"
+msgstr ""
 
-#: src/html.c:670
-#, c-format
-msgid " (%s bytes)"
-msgstr " (%s bajt�w)"
+#: src/http.c:633
+#, fuzzy, c-format
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Nast�pi� pr�by po��czenia z %s:%hu.\n"
 
-#: src/http.c:512
-msgid "Failed writing HTTP request.\n"
+#: src/http.c:809
+#, fuzzy, c-format
+msgid "Failed writing HTTP request: %s.\n"
 msgstr "Nie powiod�o si� wysy�anie ��dania HTTP.\n"
 
-#: src/http.c:516
+#: src/http.c:814
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "��danie %s wys�ano, oczekiwanie na odpowied�... "
 
-#: src/http.c:555
+#: src/http.c:858
 msgid "End of file while parsing headers.\n"
 msgstr "Wyst�pi� koniec pliku podczas skanowania nag��wk�w.\n"
 
-#: src/http.c:566
+#: src/http.c:869
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "B��d odczytu (%s) w nag��wkach.\n"
 
-#: src/http.c:606
+#: src/http.c:909
 msgid "No data received"
 msgstr "Brak danych w odpowiedzi"
 
-#: src/http.c:608
+#: src/http.c:911
 msgid "Malformed status line"
 msgstr "�le sformu�owana linia statusu"
 
-#: src/http.c:613
+#: src/http.c:916
 msgid "(no description)"
 msgstr "(brak opisu)"
 
-#. If we have tried it already, then there is not point
-#. retrying it.
-#: src/http.c:697
+#: src/http.c:1034
 msgid "Authorization failed.\n"
 msgstr "Autoryzacja nie powiod�a si�.\n"
 
-#: src/http.c:704
+#: src/http.c:1041
 msgid "Unknown authentication scheme.\n"
 msgstr "Nieznana metoda uwierzytelnienia.\n"
 
-#: src/http.c:787
+#: src/http.c:1131
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Lokalizacja: %s%s\n"
 
-#: src/http.c:788 src/http.c:813
+#: src/http.c:1132 src/http.c:1157
 msgid "unspecified"
 msgstr "nieznana"
 
-#: src/http.c:789
+#: src/http.c:1133
 msgid " [following]"
 msgstr " [pod��am]"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:803
+#: src/http.c:1147
 msgid "Length: "
 msgstr "D�ugo��: "
 
-#: src/http.c:808
+#: src/http.c:1152
 #, c-format
 msgid " (%s to go)"
 msgstr " (%s do ko�ca)"
 
-#: src/http.c:813
+#: src/http.c:1157
 msgid "ignored"
 msgstr "zignorowano"
 
-#: src/http.c:914
+#: src/http.c:1258
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Ostrze�enie: znaki globalne nie s� wspierane w HTTP.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:935
+#: src/http.c:1279
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Plik `%s' ju� tu jest, nie �ci�gam.\n"
 
-#: src/http.c:1085
+#: src/http.c:1429
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Nie mo�na zapisywa� do `%s' (%s).\n"
 
-#: src/http.c:1096
+#: src/http.c:1447
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "B��D: Przekierowywanie (%d) bez lokalizacji.\n"
 
-#: src/http.c:1121
+#: src/http.c:1472
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s B��D %d: %s.\n"
 
-#: src/http.c:1134
+#: src/http.c:1485
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Brak nag��wka Last-modified -- wy��czanie znacznik�w czasu.\n"
 
-#: src/http.c:1142
+#: src/http.c:1493
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "B��dny nag��wek Last-modified -- znacznik czasu zignorowany.\n"
 
-#: src/http.c:1177
+#: src/http.c:1528
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Plik na zdalnym serwerze jest nowszy, �ci�ganie.\n"
 
-#: src/http.c:1222
+#: src/http.c:1573
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld]\n"
