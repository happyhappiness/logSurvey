 msgid "%s: option `-W %s' doesn't allow an argument\n"
 msgstr "%s: opcja `-W %s' nie przyjmuje argument�w\n"
 
-#: src/host.c:371
-#, fuzzy
-msgid "Unknown host"
-msgstr "Nieznany b��d"
-
-#. Message modeled after what gai_strerror returns in similar
-#. circumstances.
-#: src/host.c:375
-msgid "Temporary failure in name resolution"
-msgstr ""
-
-#: src/host.c:377
-msgid "Unknown error"
-msgstr "Nieznany b��d"
-
-#: src/host.c:756
+#: src/host.c:636
 #, c-format
 msgid "Resolving %s... "
 msgstr "Translacja %s... "
 
-#: src/host.c:800 src/host.c:829
+#: src/host.c:656 src/host.c:672
 #, c-format
 msgid "failed: %s.\n"
 msgstr "nieudane: %s.\n"
 
-#: src/host.c:809
-msgid "failed: No IPv4/IPv6 addresses for host.\n"
-msgstr ""
-
-#: src/host.c:832
+#: src/host.c:674
 msgid "failed: timed out.\n"
 msgstr "b��d: przekroczono limit czasu oczekiwania.\n"
 
-#: src/html-url.c:298
+#: src/host.c:762
+msgid "Host not found"
+msgstr "Host nie zosta� znaleziony"
+
+#: src/host.c:764
+msgid "Unknown error"
+msgstr "Nieznany b��d"
+
+#: src/html-url.c:293
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Nie uda�o si� przeanalizowa� niedoko�czonego ��cza %s.\n"
 
-#: src/http.c:373 src/http.c:1549
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
-msgstr "Nie powiod�o si� wysy�anie ��dania HTTP: %s.\n"
+#. this is fatal
+#: src/http.c:674
+msgid "Failed to set up an SSL context\n"
+msgstr "Nieudane ustawianie kontekstu SSL\n"
 
-#: src/http.c:687
-msgid "No headers, assuming HTTP/0.9"
-msgstr ""
+#: src/http.c:680
+#, c-format
+msgid "Failed to load certificates from %s\n"
+msgstr "Nie uda�o si� wczyta� certyfikat�w z %s\n"
 
-#: src/http.c:1198
-msgid "Disabling SSL due to encountered errors.\n"
-msgstr ""
+#: src/http.c:684 src/http.c:692
+msgid "Trying without the specified certificate\n"
+msgstr "Pr�bowanie bez podanego certyfikatu\n"
 
-#: src/http.c:1417
-#, fuzzy, c-format
-msgid "Reusing existing connection to %s:%d.\n"
-msgstr "Ponowne u�ycie po��czenia do %s:%hu.\n"
+#: src/http.c:688
+#, c-format
+msgid "Failed to get certificate key from %s\n"
+msgstr "Nie uda�o si� uzyska� klucza certyfikatu z %s\n"
 
-#: src/http.c:1479
-#, fuzzy, c-format
-msgid "Failed writing to proxy: %s.\n"
-msgstr "Nie powiod�o si� wysy�anie ��dania HTTP: %s.\n"
+#: src/http.c:761 src/http.c:1809
+msgid "Unable to establish SSL connection.\n"
+msgstr "Niemo�liwe utworzenie po��czenia SSL.\n"
 
-#: src/http.c:1488
-#, fuzzy, c-format
-msgid "Failed reading proxy response: %s\n"
-msgstr "Nie powiod�o si� wysy�anie ��dania HTTP: %s.\n"
+#: src/http.c:770
+#, c-format
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Ponowne u�ycie po��czenia do %s:%hu.\n"
 
-#: src/http.c:1508
+#: src/http.c:1034
 #, c-format
-msgid "Proxy tunneling failed: %s"
-msgstr ""
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Nie powiod�o si� wysy�anie ��dania HTTP: %s.\n"
 
-#: src/http.c:1555
+#: src/http.c:1039
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "��danie %s wys�ano, oczekiwanie na odpowied�... "
 
-#: src/http.c:1566
-#, fuzzy
-msgid "No data received.\n"
-msgstr "Brak danych w odpowiedzi"
+#: src/http.c:1083
+msgid "End of file while parsing headers.\n"
+msgstr "Podczas analizy nag��wk�w wyst�pi� koniec pliku.\n"
 
-#: src/http.c:1573
+#: src/http.c:1093
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "B��d odczytu (%s) w nag��wkach.\n"
 
-#. If the authentication header is missing or
-#. unrecognized, there's no sense in retrying.
-#: src/http.c:1658
-msgid "Unknown authentication scheme.\n"
-msgstr "Nieznana metoda uwierzytelniania.\n"
-
-#: src/http.c:1682
-msgid "Authorization failed.\n"
-msgstr "Autoryzacja nie powiod�a si�.\n"
+#: src/http.c:1128
+msgid "No data received"
+msgstr "Brak danych w odpowiedzi"
 
-#: src/http.c:1696
+#: src/http.c:1130
 msgid "Malformed status line"
 msgstr "�le sformu�owana linia statusu"
 
-#: src/http.c:1698
+#: src/http.c:1135
 msgid "(no description)"
 msgstr "(brak opisu)"
 
-#: src/http.c:1769
+#: src/http.c:1267
+msgid "Authorization failed.\n"
+msgstr "Autoryzacja nie powiod�a si�.\n"
+
+#: src/http.c:1274
+msgid "Unknown authentication scheme.\n"
+msgstr "Nieznana metoda uwierzytelniania.\n"
+
+#: src/http.c:1314
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Lokalizacja: %s%s\n"
 
-#: src/http.c:1770 src/http.c:1867
+#: src/http.c:1315 src/http.c:1454
 msgid "unspecified"
 msgstr "nieznana"
 
-#: src/http.c:1771
+#: src/http.c:1316
 msgid " [following]"
 msgstr " [pod��anie]"
 
-#. If `-c' is in use and the file has been fully downloaded (or
-#. the remote file has shrunk), Wget effectively requests bytes
-#. after the end of file and the server response with 416.
-#: src/http.c:1817
+#: src/http.c:1383
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
