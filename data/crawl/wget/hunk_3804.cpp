 "You may stop Wget by pressing CTRL+ALT+DELETE.\n"
 msgstr ""
 "\n"
-"Przechwycono CTRL+Break, przekierowanie wyj?cia do `%s'.\n"
-"Wykonywanie b?dzie kontynuowane w tle.\n"
-"Mo?esz zatrzyma? Wget poprzez wci?ni?cie CTRL+ALT+DELETE.\n"
+"Przes�ano CTRL+Break, przekierowywanie wyj�cia do `%s'.\n"
+"Wykonanie kontynuowane w tle.\n"
+"Mo�na zatrzyma� Wget'a poprzez wci�ni�cie CTRL+ALT+DELETE.\n"
 
 #. parent, no error
-#: src/mswindows.c:135 src/utils.c:457
+#: src/mswindows.c:140 src/utils.c:269
 msgid "Continuing in background.\n"
-msgstr "Kontynuacja w tle.\n"
+msgstr "Kontunuacja w tle.\n"
 
-#: src/mswindows.c:137 src/utils.c:459
+#: src/mswindows.c:142 src/utils.c:271
 #, c-format
 msgid "Output will be written to `%s'.\n"
-msgstr "Wyj?cie zostanie zapisane w `%s'.\n"
+msgstr "Wyj�cie zostanie zapisane do `%s'.\n"
 
-#: src/mswindows.c:227
+#: src/mswindows.c:232
 #, c-format
 msgid "Starting WinHelp %s\n"
-msgstr "Uruchomienie WinHelp %s\n"
+msgstr "Startowanie WinHelp %s\n"
 
-#: src/mswindows.c:254 src/mswindows.c:262
+#: src/mswindows.c:259 src/mswindows.c:267
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
-msgstr "%s: Nie mog? znale?? u?ytecznego sterownika gniazdka.\n"
+msgstr "%s: Nie mog�na znale�� u�ytecznego sterownika do gniazd (socket).\n"
 
-#: src/netrc.c:367
+#: src/netrc.c:359
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr ""
-"%s: %s:%d: ostrze?enie: pojawia si? znak \"%s\" przed jak?kolwiek nazw? "
+"%s: %s:%d: ostrze�enie: \"%s\" znaki (token) pojawiaj� sie przed nazw� "
 "maszyny\n"
 
-#: src/netrc.c:398
+#: src/netrc.c:390
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
-msgstr "%s: %s:%d: nieznany znak \"%s\"\n"
+msgstr "%s: %s:%d: nieznany znak (token) \"%s\"\n"
 
-#: src/netrc.c:462
+#: src/netrc.c:454
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
-msgstr "U?ycie: %s NETRC [NAZWA_SERWERA]\n"
+msgstr "U�ycie: %s NETRC [NAZWA_HOSTA]\n"
 
-#: src/netrc.c:472
+#: src/netrc.c:464
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
-msgstr "%s: nie mog? przeprowadzi? statystyki %s: %s\n"
+msgstr "%s: nie mo�na zlokalizowa� %s: %s\n"
 
-#: src/recur.c:506
+#: src/recur.c:473
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
-msgstr "Usuni?cie %s poniewa? powinien by? odrzucony.\n"
+msgstr "Usuwanie %s poniewa� powinien by� odrzucony.\n"
 
-#: src/recur.c:680
+#: src/recur.c:634
 msgid "Loading robots.txt; please ignore errors.\n"
-msgstr "?adowanie robots.txt; prosz? zignorowa? b??dy.\n"
+msgstr "�adowanie robots.txt; prosz� zignorowa� b��dy.\n"
 
-#: src/retr.c:217
+#: src/retr.c:201
 #, c-format
 msgid ""
 "\n"
 "          [ skipping %dK ]"
 msgstr ""
 "\n"
-"          [ pomijam %d kB ]"
+"          [ pomijanie %dK ]"
 
-#: src/retr.c:399
+#: src/retr.c:384
 msgid "Could not find proxy host.\n"
-msgstr "Nie mog? odnale?? serwera proxy.\n"
+msgstr "Nie mo�na znale�� serwera proxy.\n"
 
-#: src/retr.c:413
+#: src/retr.c:397
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
-msgstr "Proxy %s: Musi by? HTTP.\n"
+msgstr "Proxy %s: Musi by� HTTP.\n"
+
+#: src/retr.c:476
+#, c-format
+msgid "%s: Redirection to itself.\n"
+msgstr "%s: Przekierowanie do samego siebie.\n"
 
-#: src/retr.c:507
-#, fuzzy, c-format
+#: src/retr.c:490
+#, c-format
 msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: Przekierowanie na samego siebie.\n"
+msgstr "%s: Wykryto cykl przekierowa�.\n"
 
-#: src/retr.c:601
+#: src/retr.c:585
 msgid ""
 "Giving up.\n"
 "\n"
 msgstr ""
-"Poddaj? si?.\n"
+"Poddawanie si�.\n"
 "\n"
 
-#: src/retr.c:601
+#: src/retr.c:585
 msgid ""
 "Retrying.\n"
 "\n"
 msgstr ""
-"Ponawiam pr�b?.\n"
+"Ponawianie pr�by.\n"
 "\n"
 
-#: src/url.c:1325
+#: src/url.c:983
 #, c-format
-msgid "Converting %s... "
-msgstr "Konwersja %s... "
+msgid "Error (%s): Link %s without a base provided.\n"
+msgstr "B��d (%s): Odno�nik %s podany bez bazy.\n"
 
-#: src/url.c:1338
-msgid "nothing to do.\n"
-msgstr ""
+#: src/url.c:999
+#, c-format
+msgid "Error (%s): Base %s relative, without referer URL.\n"
+msgstr "B��d (%s): Baza %s jest relatywna, bez odsy�aj�cego URLa.\n"
 
-#: src/url.c:1346 src/url.c:1370
+#: src/url.c:1540
 #, c-format
-msgid "Cannot convert links in %s: %s\n"
-msgstr "Nie mog? przekonwertowa? ??cza w %s: %s\n"
+msgid "Converting %s... "
+msgstr "Konwertuj� %s... "
 
-#: src/url.c:1361
-#, fuzzy, c-format
-msgid "Unable to delete `%s': %s\n"
-msgstr "Od??czenie ??cza symbolicznego `%s' nie powiod?o si?: %s\n"
+#: src/url.c:1545 src/url.c:1632
+#, c-format
+msgid "Cannot convert links in %s: %s\n"
+msgstr "Nie mo�na skonwertowa� odno�nik�w w %s: %s\n"
 
-#: src/url.c:1558
-#, fuzzy, c-format
+#: src/url.c:1608
+#, c-format
 msgid "Cannot back up %s as %s: %s\n"
-msgstr "Nie mog? przekonwertowa? ??cza w %s: %s\n"
+msgstr "Nie mo�na stworzy� kopii zapasowej %s jako %s: %s\n"
 
-#: src/utils.c:94
+#: src/utils.c:72
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
-msgstr "%s: %s: Brak pami?ci.\n"
+msgstr "%s: %s: Nie ma wystarczaj�cej ilo�ci pami�ci.\n"
 
-#: src/utils.c:392
+#: src/utils.c:204
 msgid "Unknown/unsupported protocol"
-msgstr "Nieznany/nieobs?ugiwany protok�?"
+msgstr "Nieznany/niewspierany protok�"
 
-#: src/utils.c:395
+#: src/utils.c:207
 msgid "Invalid port specification"
-msgstr "Nieprawid?owa specyfikacja portu"
+msgstr "Nieprawid�owa specyfikacja portu"
 
-#: src/utils.c:398
+#: src/utils.c:210
 msgid "Invalid host name"
-msgstr "Nieprawid?owa nazwa serwera"
+msgstr "Nieprawid�owa nazwa hosta"
 
-#: src/utils.c:619
+#: src/utils.c:431
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
-msgstr "Od??czenie ??cza symbolicznego `%s' nie powiod?o si?: %s\n"
-
-#~ msgid "%s: Redirection to itself.\n"
-#~ msgstr "%s: Przekierowanie na samego siebie.\n"
-
-#~ msgid "Error (%s): Link %s without a base provided.\n"
-#~ msgstr "B??d (%s): ??cze %s zosta?o dostarczone bez bazy.\n"
-
-#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
-#~ msgstr "B??d (%s): Baza %s jest wzgl?dna, bez odniesienia do URL'a.\n"
+msgstr "Nie uda�o sie usun�� dowi�zania symbolicznego `%s': %s\n"
 
 #~ msgid ""
 #~ "Local file `%s' is more recent, not retrieving.\n"
 #~ "\n"
 #~ msgstr ""
-#~ "Plik lokalny `%s' jest nowszy, wi?c go nie pobieram.\n"
+#~ "Lokalny plik `%s' jest �wie�szy, nie �ci�gam.\n"
 #~ "\n"
+
+#~ msgid "%s: unrecognized option, character code 0%o\n"
+#~ msgstr "%s: nieznana opcja, kod znaku 0%o\n"
+
+#~ msgid "%s: unrecognized option `-%c'\n"
+#~ msgstr "%s: nierozpoznana opcja `-%c'\n"
+
+#~ msgid "%s: option `-%c' requires an argument\n"
+#~ msgstr "%s: opcja `-%c' wymaga argumentu"
