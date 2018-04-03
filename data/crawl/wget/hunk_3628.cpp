 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: prep�na� vy�aduje argument -- %c\n"
 
-#: src/host.c:394
-#, c-format
-msgid "%s: Cannot determine user-id.\n"
-msgstr "%s: Nemo�no identifikova� u��vate�a.\n"
-
-# , c-format
-#: src/host.c:406
-#, c-format
-msgid "%s: Warning: uname failed: %s\n"
-msgstr "%s: Varovanie: volanie \"uname\" skon�ilo s chybou %s\n"
-
-#: src/host.c:418
-#, c-format
-msgid "%s: Warning: gethostname failed\n"
-msgstr "%s: Varovanie: volanie \"gethostname\" skon�ilo s chybou\n"
-
-#: src/host.c:446
-#, c-format
-msgid "%s: Warning: cannot determine local IP address.\n"
-msgstr "%s: Varovanie: nemo�no ur�i� lok�lnu IP adresu.\n"
-
-#: src/host.c:460
-#, c-format
-msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
-msgstr "%s: Varovanie: lok�lna IP adresa nem� reverzn� z�znam v DNS.\n"
-
-#. This gets ticked pretty often.  Karl Berry reports
-#. that there can be valid reasons for the local host
-#. name not to be an FQDN, so I've decided to remove the
-#. annoying warning.
-#: src/host.c:473
-#, c-format
-msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
-msgstr ""
-"%s: Varovanie: reverzn� vyh�adanie lok�lnej adresy nevr�tilo pln�\n"
-"                kvalifikovan� meno!\n"
-
-#: src/host.c:501
+#: src/host.c:374
 msgid "Host not found"
 msgstr "Hostite� nebol n�jden�"
 
-#: src/host.c:503
+#: src/host.c:376
 msgid "Unknown error"
 msgstr "Nezn�ma chyba"
 
 #. this is fatal
-#: src/http.c:549
+#: src/http.c:555
 msgid "Failed to set up an SSL context\n"
-msgstr ""
+msgstr "Nepodarilo sa nastavi� SSL kontext.\n"
 
-#: src/http.c:555
+#: src/http.c:561
 #, c-format
 msgid "Failed to load certificates from %s\n"
-msgstr ""
+msgstr "Nepodarilo sa na��ta� certifik�ty z %s\n"
 
-#: src/http.c:559 src/http.c:567
+#: src/http.c:565 src/http.c:573
 msgid "Trying without the specified certificate\n"
-msgstr ""
+msgstr "Sk��am bez zadan�ho certifik�tu\n"
 
-#: src/http.c:563
+#: src/http.c:569
 #, c-format
 msgid "Failed to get certificate key from %s\n"
-msgstr ""
+msgstr "Nepodarilo sa na��ta� k��� certifik�tu z %s\n"
 
-#: src/http.c:657 src/http.c:1470
+#: src/http.c:663 src/http.c:1593
 msgid "Unable to establish SSL connection.\n"
-msgstr ""
+msgstr "Nepodarilo sa nadviaza� SSL spojenie\n"
 
 # , c-format
-#: src/http.c:665
-#, fuzzy, c-format
+#: src/http.c:671
+#, c-format
 msgid "Reusing connection to %s:%hu.\n"
-msgstr "Pok�sim sa spoji� s %s:%hu.\n"
+msgstr "Pou��vam existuj�ce spojenie s %s:%hu.\n"
 
-#: src/http.c:841
-#, fuzzy, c-format
+#: src/http.c:861
+#, c-format
 msgid "Failed writing HTTP request: %s.\n"
-msgstr "Po�iadavku HTTP nebolo mo�n� odosla�.\n"
+msgstr "Po�iadavku HTTP nebolo mo�n� odosla�: %s.\n"
 
 # , c-format
-#: src/http.c:846
+#: src/http.c:866
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s po�iadavka odoslan�, �ak�m na odpove� ... "
 
-#: src/http.c:890
+#: src/http.c:910
 msgid "End of file while parsing headers.\n"
 msgstr "Hlavi�ka nie je �pln�.\n"
 
 # , c-format
-#: src/http.c:901
+#: src/http.c:920
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Chyba (%s) pri ��tan� hlavi�iek.\n"
 
-#: src/http.c:941
+#: src/http.c:959
 msgid "No data received"
 msgstr "Nepri�li �iadne d�ta"
 
-#: src/http.c:943
+#: src/http.c:961
 msgid "Malformed status line"
 msgstr "Odpove� serveru m� skomolen� stavov� riadok"
 
-#: src/http.c:948
+#: src/http.c:966
 msgid "(no description)"
 msgstr "(�iadny popis)"
 
-#: src/http.c:1066
+#: src/http.c:1089
 msgid "Authorization failed.\n"
 msgstr "Autoriz�cia zlyhala.\n"
 
-#: src/http.c:1073
+#: src/http.c:1096
 msgid "Unknown authentication scheme.\n"
 msgstr "Server po�aduje nezn�my sp�sob autentifik�cie.\n"
 
 # , c-format
-#: src/http.c:1163
+#: src/http.c:1136
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Presmerovan� na: %s%s\n"
 
-#: src/http.c:1164 src/http.c:1189
+#: src/http.c:1137 src/http.c:1269
 msgid "unspecified"
 msgstr "neudan�"
 
-#: src/http.c:1165
+#: src/http.c:1138
 msgid " [following]"
 msgstr " [nasledujem]"
 
+#: src/http.c:1200
+msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
+msgstr "\n    Tento s�bor je u� kompletne prenesen�; netreba ni� robi�.\n\n"
+
+#: src/http.c:1216
+#, c-format
+msgid ""
+"\n"
+"Continued download failed on this file, which conflicts with `-c'.\n"
+"Refusing to truncate existing file `%s'.\n"
+"\n"
+msgstr ""
+"\n"
+"Pokra�ovanie prenosu tohoto s�boru zlyhalo, �o koliduje s `-c'.\n"
+"Existuj�ci s�bor `%s' nebude skr�ten�.\n"
+"\n"
+
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1179
+#: src/http.c:1259
 msgid "Length: "
 msgstr "D�ka:  "
 
 # , c-format
-#: src/http.c:1184
+#: src/http.c:1264
 #, c-format
 msgid " (%s to go)"
 msgstr " (ost�va %s)"
 
-#: src/http.c:1189
+#: src/http.c:1269
 msgid "ignored"
 msgstr "je ignorovan�"
 
-#: src/http.c:1290
+#: src/http.c:1399
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Varovanie: HTTP nepodporuje �ol�kov� znaky.\n"
 
 # , c-format
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:1311
+#: src/http.c:1417
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "S�bor `%s' sa nebude pren�a�, je u� tu.\n"
 
 # , c-format
-#: src/http.c:1462
+#: src/http.c:1585
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Nemo�no zap�sa� do `%s' (%s).\n"
 
 # , c-format
-#: src/http.c:1480
+#: src/http.c:1602
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "CHYBA: Presmerovanie (%d) bez udanej novej adresy.\n"
 
 # , c-format
-#: src/http.c:1505
+#: src/http.c:1630
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s CHYBA %d: %s.\n"
 
-#: src/http.c:1518
+#: src/http.c:1642
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr ""
 "Nebud� sa pou��va� �asov� raz�tka (`time-stamps'), preto�e hlavi�ka\n"
 "\"Last-modified\" v odpovedi serveru ch�ba.\n"
 
-#: src/http.c:1526
+#: src/http.c:1650
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr ""
 "Ignorujem �asov� raz�tko s�boru (`time-stamp'), preto�e hlavi�ka \n"
 "\"Last-modified\" obsahuje neplatn� �daje.\n"
 
-#: src/http.c:1549
+#: src/http.c:1673
 #, c-format
-msgid ""
-"Server file no newer than local file `%s' -- not retrieving.\n"
-"\n"
-msgstr ""
+msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
+msgstr "S�bor na serveri nie je nov�� ako lok�lny s�bor `%s' -- nepren�am.\n\n"
 
 # , c-format
-#: src/http.c:1557
-#, fuzzy, c-format
+#: src/http.c:1680
+#, c-format
 msgid "The sizes do not match (local %ld) -- retrieving.\n"
-msgstr "Ve�kosti se nezhoduj� (lok�lne %ld), pren�am.\n"
+msgstr "Ve�kosti se nezhoduj� (lok�lne %ld) -- pren�am.\n"
 
-#: src/http.c:1561
+#: src/http.c:1684
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Vzdialen� s�bor m� nov�� d�tum, pren�am.\n"
 
 # , c-format
-#: src/http.c:1606
+#: src/http.c:1728
 #, c-format
-msgid ""
-"%s (%s) - `%s' saved [%ld/%ld]\n"
-"\n"
-msgstr ""
-"%s (%s) - `%s' ulo�en� [%ld/%ld]\n"
-"\n"
+msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
+msgstr "%s (%s) - `%s' ulo�en� [%ld/%ld]\n\n"
 
 # , c-format
-#: src/http.c:1654
+#: src/http.c:1774
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld. "
 msgstr "%s (%s) - Spojenie uzatvoren� na byte %ld. "
 
 # , c-format
-#: src/http.c:1662
+#: src/http.c:1782
 #, c-format
-msgid ""
-"%s (%s) - `%s' saved [%ld/%ld])\n"
-"\n"
-msgstr ""
-"%s (%s) - `%s' ulo�en� [%ld/%ld])\n"
-"\n"
+msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
+msgstr "%s (%s) - `%s' ulo�en� [%ld/%ld])\n\n"
 
 # , c-format
-#: src/http.c:1682
+#: src/http.c:1801
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld/%ld. "
 msgstr "%s (%s) - Spojenie uzatvoren� na byte %ld/%ld. "
 
 # , c-format
-#: src/http.c:1693
+#: src/http.c:1812
 #, c-format
 msgid "%s (%s) - Read error at byte %ld (%s)."
 msgstr "%s (%s) - Chyba pri ��tan� d�t na byte %ld (%s)."
 
 # , c-format
-#: src/http.c:1701
+#: src/http.c:1820
 #, c-format
 msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
 msgstr "%s (%s) - Chyba pri ��tan� d�t na byte %ld/%ld (%s). "
 
 # , c-format
-#: src/init.c:336 src/netrc.c:261
+#: src/init.c:349 src/netrc.c:267
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: Nemo�no pre��ta� %s (%s).\n"
 
 # , c-format
-#: src/init.c:354 src/init.c:360
+#: src/init.c:367 src/init.c:373
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: Chyba v %s na riadku %d.\n"
 
 # , c-format
-#: src/init.c:391
+#: src/init.c:405
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
-msgstr ""
-"%s: Varovanie: Glob�lne aj u��vate�sk� wgetrc s� zhodne ulo�en� v `%s'.\n"
+msgstr "%s: Varovanie: Glob�lne aj u��vate�sk� wgetrc s� zhodne ulo�en� v `%s'.\n"
 
 # , c-format
-#: src/init.c:483
+#: src/init.c:497
 #, c-format
 msgid "%s: BUG: unknown command `%s', value `%s'.\n"
 msgstr "%s: Chyba: Nezn�my pr�kaz `%s', hodnota `%s'.\n"
 
-#: src/init.c:504
-#, fuzzy, c-format
+#: src/init.c:529
+#, c-format
 msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
-msgstr "%s: Varovanie: lok�lna IP adresa nem� reverzn� z�znam v DNS.\n"
+msgstr "%s: %s: Nie je mo�n� konvertova� `%s' na IP adresu.\n"
 
 # , c-format
-#: src/init.c:532
+#: src/init.c:559
 #, c-format
 msgid "%s: %s: Please specify on or off.\n"
-msgstr "%s: %s: Zadajte pros�m `on' alebo `off'.\n"
+msgstr "%s: %s: Zadajte pros�m on alebo off.\n"
 
 # , c-format
-#: src/init.c:576
-#, fuzzy, c-format
+#: src/init.c:603
+#, c-format
 msgid "%s: %s: Please specify always, on, off, or never.\n"
-msgstr "%s: %s: Zadajte pros�m `on' alebo `off'.\n"
+msgstr "%s: %s: Zadajte pros�m v�dy on, off alebo never.\n"
 
 # , c-format
-#: src/init.c:595 src/init.c:852 src/init.c:874 src/init.c:938
+#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
 #, c-format
 msgid "%s: %s: Invalid specification `%s'.\n"
 msgstr "%s: %s: Neplatn� �pecifik�cia `%s'\n"
 
 # , c-format
-#: src/init.c:708 src/init.c:730 src/init.c:752 src/init.c:778
+#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
 #, c-format
 msgid "%s: Invalid specification `%s'\n"
 msgstr "%s: Neplatn� �pecifik�cia `%s'\n"
