 
 # c-format
 #: src/html-url.c:696
-#, fuzzy, c-format
+#, c-format
 msgid "%s: Invalid URL %s: %s\n"
-msgstr "%s: %s: Nieprawid�owa warto�� `%s'.\n"
+msgstr "%s: Nieprawid�owy URL %s: %s\n"
 
 #: src/http.c:368
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Nie powiod�o si� wysy�anie ��dania HTTP: %s.\n"
 
-#: src/http.c:737
+#: src/http.c:745
 msgid "No headers, assuming HTTP/0.9"
-msgstr ""
+msgstr "Brak nag��wk�w, przyj�to HTTP/0.9"
 
-#: src/http.c:1417
+#: src/http.c:1430
 msgid "Disabling SSL due to encountered errors.\n"
-msgstr ""
-
-#: src/http.c:1570
-#, c-format
-msgid "POST data file `%s' missing: %s\n"
-msgstr ""
+msgstr "Wy��czenie SSL ze wzgl�du na napotkane b��dy\n"
 
-#: src/http.c:1619
+#: src/http.c:1548
 #, fuzzy, c-format
+msgid "POST data file %s missing: %s\n"
+msgstr "Brak pliku danych POST `%s': %s\n"
+
+#: src/http.c:1632
+#, c-format
 msgid "Reusing existing connection to %s:%d.\n"
-msgstr "Ponowne u�ycie po��czenia do %s:%hu.\n"
+msgstr "Ponowne u�ycie po��czenia do %s:%d.\n"
 
-#: src/http.c:1687
-#, fuzzy, c-format
+#: src/http.c:1701
+#, c-format
 msgid "Failed reading proxy response: %s\n"
-msgstr "Nie powiod�o si� wysy�anie ��dania HTTP: %s.\n"
+msgstr "Nie powiod�o si� odczytanie odpowiedzi proxy: %s.\n"
 
-#: src/http.c:1707
+#: src/http.c:1721
 #, c-format
 msgid "Proxy tunneling failed: %s"
-msgstr ""
+msgstr "Tunelowanie proxy nie powiod�o si�: %s"
 
-#: src/http.c:1752
+#: src/http.c:1766
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "��danie %s wys�ano, oczekiwanie na odpowied�... "
 
-#: src/http.c:1763
-#, fuzzy
+#: src/http.c:1777
 msgid "No data received.\n"
-msgstr "Brak danych w odpowiedzi"
+msgstr "Brak danych w odpowiedzi.\n"
 
-#: src/http.c:1770
+#: src/http.c:1784
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "B��d odczytu (%s) w nag��wkach.\n"
 
-#: src/http.c:1816 src/http.c:2368
+#: src/http.c:1831 src/http.c:2385
 #, fuzzy, c-format
 msgid ""
-"File `%s' already there; not retrieving.\n"
+"File %s already there; not retrieving.\n"
+"\n"
+msgstr ""
+"Plik `%s' ju� istnieje, bez pobierania.\n"
 "\n"
-msgstr "Plik `%s' ju� istnieje, bez pobierania.\n"
 
-#: src/http.c:1969
+#: src/http.c:1985
 msgid "Unknown authentication scheme.\n"
 msgstr "Nieznana metoda uwierzytelniania.\n"
 
-#: src/http.c:2000
+#: src/http.c:2016
 msgid "Authorization failed.\n"
 msgstr "Autoryzacja nie powiod�a si�.\n"
 
-#: src/http.c:2014
+#: src/http.c:2030
 msgid "Malformed status line"
 msgstr "�le sformu�owana linia statusu"
 
-#: src/http.c:2016
+#: src/http.c:2032
 msgid "(no description)"
 msgstr "(brak opisu)"
 
-#: src/http.c:2082
+#: src/http.c:2098
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Lokalizacja: %s%s\n"
 
-#: src/http.c:2083 src/http.c:2193
+#: src/http.c:2099 src/http.c:2209
 msgid "unspecified"
 msgstr "nieznana"
 
-#: src/http.c:2084
+#: src/http.c:2100
 msgid " [following]"
 msgstr " [pod��anie]"
 
-#: src/http.c:2140
+#: src/http.c:2156
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
