 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1606
+#: src/ftp.c:1753
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Vzorku `%s' nic neodpov�d�.\n"
 
 # , c-format
-#: src/ftp.c:1671
-#, c-format
-msgid "Wrote HTML-ized index to `%s' [%ld].\n"
+#: src/ftp.c:1819
+#, fuzzy, c-format
+msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "V�pis adres��e v HTML form�tu byl zaps�n do `%s' [%ld].\n"
 
 # , c-format
-#: src/ftp.c:1676
+#: src/ftp.c:1824
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "V�pis adres��e v HTML form�tu byl zaps�n do `%s'.\n"
 
 # , c-format
-#: src/getopt.c:454
+#: src/getopt.c:670
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: p�ep�na� `%s' nen� jednozna�n�\n"
 
 # , c-format
-#: src/getopt.c:478
+#: src/getopt.c:695
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: p�ep�na� `--%s' nem� argument\n"
 
 # , c-format
-#: src/getopt.c:483
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: p�ep�na� `%c%s' nem� argument\n"
 
 # , c-format
-#: src/getopt.c:498
+#: src/getopt.c:718 src/getopt.c:891
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: p�ep�na� `%s' vy�aduje argument\n"
 
 # , c-format
 #. --option
-#: src/getopt.c:528
+#: src/getopt.c:747
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: nezn�m� p�ep�na� `--%s'\n"
 
 # , c-format
 #. +option or -option
-#: src/getopt.c:532
+#: src/getopt.c:751
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: nezn�m� p�ep�na� `%c%s'\n"
 
 # , c-format
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:563
+#: src/getopt.c:777
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: nep��pustn� p�ep�na� -- %c\n"
 
 # , c-format
+#: src/getopt.c:780
+#, fuzzy, c-format
+msgid "%s: invalid option -- %c\n"
+msgstr "%s: nep��pustn� p�ep�na� -- %c\n"
+
+# , c-format
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:602
+#: src/getopt.c:810 src/getopt.c:940
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: p�ep�na� vy�aduje argument -- %c\n"
 
-#: src/host.c:374
-msgid "Host not found"
-msgstr "Po��ta� nebyl nalezen"
+# , c-format
+#: src/getopt.c:857
+#, fuzzy, c-format
+msgid "%s: option `-W %s' is ambiguous\n"
+msgstr "%s: p�ep�na� `%s' nen� jednozna�n�\n"
+
+# , c-format
+#: src/getopt.c:875
+#, fuzzy, c-format
+msgid "%s: option `-W %s' doesn't allow an argument\n"
+msgstr "%s: p�ep�na� `--%s' nem� argument\n"
+
+#: src/host.c:347
+#, fuzzy
+msgid "Unknown host"
+msgstr "Nezn�m� chyba"
+
+#. Message modeled after what gai_strerror returns in similar
+#. circumstances.
+#: src/host.c:351
+msgid "Temporary failure in name resolution"
+msgstr ""
 
-#: src/host.c:376
+#: src/host.c:353
 msgid "Unknown error"
 msgstr "Nezn�m� chyba"
 
-#. this is fatal
-#: src/http.c:555
-msgid "Failed to set up an SSL context\n"
-msgstr "Nebylo mo�n� nastavit SSL kontext\n"
+# , c-format
+#: src/host.c:714
+#, fuzzy, c-format
+msgid "Resolving %s... "
+msgstr "Ma�e se %s.\n"
+
+#: src/host.c:761
+msgid "failed: No IPv4/IPv6 addresses for host.\n"
+msgstr ""
+
+#: src/host.c:784
+msgid "failed: timed out.\n"
+msgstr ""
 
-#: src/http.c:561
+#: src/html-url.c:288
 #, c-format
-msgid "Failed to load certificates from %s\n"
-msgstr "SSL certifik�ty nebylo mo�n� ze souboru `%s' na��st.\n"
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr ""
 
-#: src/http.c:565 src/http.c:573
-msgid "Trying without the specified certificate\n"
-msgstr "Program se pokus� pokra�ovat bez zadan�ho certifik�tu.\n"
+# , c-format
+#: src/html-url.c:695
+#, fuzzy, c-format
+msgid "%s: Invalid URL %s: %s\n"
+msgstr "%s: Neplatn� specifikace `%s'\n"
 
-#: src/http.c:569
+#: src/http.c:367
 #, c-format
-msgid "Failed to get certificate key from %s\n"
-msgstr "Ze souboru `%s' nebylo mo�n� kl�� k certifik�tu na��st.\n\n"
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Nebylo mo�n� odeslat HTTP po�adavek: %s.\n"
 
-#: src/http.c:663 src/http.c:1593
-msgid "Unable to establish SSL connection.\n"
-msgstr "Nebylo mo�n� nav�zat SSL spojen�.\n"
+#: src/http.c:736
+msgid "No headers, assuming HTTP/0.9"
+msgstr ""
 
-# , c-format
-#: src/http.c:671
+#: src/http.c:1413
+msgid "Disabling SSL due to encountered errors.\n"
+msgstr ""
+
+#: src/http.c:1566
 #, c-format
-msgid "Reusing connection to %s:%hu.\n"
+msgid "POST data file `%s' missing: %s\n"
+msgstr ""
+
+# , c-format
+#: src/http.c:1615
+#, fuzzy, c-format
+msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Program vyu�ije existuj�c� spojen� s %s:%hu.\n"
 
-#: src/http.c:861
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
+#: src/http.c:1684
+#, fuzzy, c-format
+msgid "Failed reading proxy response: %s\n"
 msgstr "Nebylo mo�n� odeslat HTTP po�adavek: %s.\n"
 
+#: src/http.c:1704
+#, c-format
+msgid "Proxy tunneling failed: %s"
+msgstr ""
+
 # , c-format
-#: src/http.c:866
+#: src/http.c:1749
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s po�adavek odesl�n, program �ek� na odpov�� ... "
 
-#: src/http.c:910
-msgid "End of file while parsing headers.\n"
-msgstr "Hlavi�ka nen� �pln�.\n"
+#: src/http.c:1760
+#, fuzzy
+msgid "No data received.\n"
+msgstr "Nep�i�la ��dn� data"
 
 # , c-format
-#: src/http.c:920
+#: src/http.c:1767
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Chyba (%s) p�i �ten� hlavi�ek.\n"
 
-#: src/http.c:959
-msgid "No data received"
-msgstr "Nep�i�la ��dn� data"
+# , c-format
+#. If opt.noclobber is turned on and file already exists, do not
+#. retrieve the file
+#: src/http.c:1813
+#, fuzzy, c-format
+msgid ""
+"File `%s' already there; not retrieving.\n"
+"\n"
+msgstr "Soubor `%s' je ji� zde a nen� jej t�eba p�en�et.\n"
+
+#. If the authentication header is missing or
+#. unrecognized, there's no sense in retrying.
+#: src/http.c:1966
+msgid "Unknown authentication scheme.\n"
+msgstr "Server po�aduje nezn�m� zp�sob autentifikace.\n"
+
+#: src/http.c:1997
+msgid "Authorization failed.\n"
+msgstr "Autorizace selhala.\n"
 
-#: src/http.c:961
+#: src/http.c:2011
 msgid "Malformed status line"
 msgstr "Odpov�� serveru m� zkomolen� stavov� ��dek"
 
-#: src/http.c:966
+#: src/http.c:2013
 msgid "(no description)"
 msgstr "(��dn� popis)"
 
-#: src/http.c:1089
-msgid "Authorization failed.\n"
-msgstr "Autorizace selhala.\n"
-
-#: src/http.c:1096
-msgid "Unknown authentication scheme.\n"
-msgstr "Server po�aduje nezn�m� zp�sob autentifikace.\n"
-
 # , c-format
-#: src/http.c:1136
+#: src/http.c:2076
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "P�esm�rov�no na: %s%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:2077 src/http.c:2184
 msgid "unspecified"
 msgstr "neud�no"
 
-#: src/http.c:1138
+#: src/http.c:2078
 msgid " [following]"
 msgstr " [n�sleduji]"
 
-#: src/http.c:1200
-msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
-msgstr "\n    Soubor je ji� pln� p�enesen, nebude se nic d�lat.\n\n"
-
-#: src/http.c:1216
-#, c-format
+#. If `-c' is in use and the file has been fully downloaded (or
+#. the remote file has shrunk), Wget effectively requests bytes
+#. after the end of file and the server response with 416.
+#: src/http.c:2134
 msgid ""
 "\n"
-"Continued download failed on this file, which conflicts with `-c'.\n"
-"Refusing to truncate existing file `%s'.\n"
+"    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 "\n"
-"Na p�eru�en� stahov�n� tohoto souboru nelze nav�zat. Bylo ov�em zad�no `-c'.\n"
-"Existuj�c� soubor `%s' tedy rad�ji nebude zkr�cen.\n"
+"    Soubor je ji� pln� p�enesen, nebude se nic d�lat.\n"
 "\n"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1259
+#: src/http.c:2164
 msgid "Length: "
 msgstr "D�lka: "
 
-# , c-format
-#: src/http.c:1264
-#, c-format
-msgid " (%s to go)"
-msgstr " (%s zb�v�)"
-
-#: src/http.c:1269
+#: src/http.c:2184
 msgid "ignored"
 msgstr "je ignorov�na"
 
-#: src/http.c:1399
+# , c-format
+#: src/http.c:2255
+#, fuzzy, c-format
+msgid "Saving to: `%s'\n"
+msgstr "Adres�� `%s' bude vynech�n.\n"
+
+#: src/http.c:2335
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Varov�n�: HTTP nepodporuje �ol�kov� znaky.\n"
 
-# , c-format
-#. If opt.noclobber is turned on and file already exists, do not
-#. retrieve the file
-#: src/http.c:1417
-#, c-format
-msgid "File `%s' already there, will not retrieve.\n"
-msgstr "Soubor `%s' je ji� zde a nebude se znovu p�en�et.\n"
+#: src/http.c:2364
+msgid "Spider mode enabled. Check if remote file exists.\n"
+msgstr ""
 
 # , c-format
-#: src/http.c:1585
+#: src/http.c:2450
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Nelze zapsat do `%s' (%s).\n"
 
+#. Another fatal error.
+#: src/http.c:2459
+msgid "Unable to establish SSL connection.\n"
+msgstr "Nebylo mo�n� nav�zat SSL spojen�.\n"
+
 # , c-format
-#: src/http.c:1602
+#: src/http.c:2467
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "CHYBA: P�esm�rov�n� (%d) bez udan� nov� adresy.\n"
 
+#: src/http.c:2505
+msgid "Remote file does not exist -- broken link!!!\n"
+msgstr ""
+
 # , c-format
-#: src/http.c:1630
+#: src/http.c:2510
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s CHYBA %d: %s.\n"
 
-#: src/http.c:1642
+#: src/http.c:2526
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr ""
 "Nelze pou��t �asov� raz�tka (`time-stamps'), proto�e v odpov�di serveru \n"
 "sch�z� hlavi�ka \"Last-modified\".\n"
 
-#: src/http.c:1650
+#: src/http.c:2534
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr ""
 "�asov� raz�tko souboru (`time-stamp') bude ignorov�no, proto�e hlavi�ka \n"
 "\"Last-modified\" obsahuje neplatn� �daje.\n"
 
-#: src/http.c:1673
+#: src/http.c:2558
 #, c-format
-msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
-msgstr "Lok�ln� soubor `%s' nen� star��, ne� vzd�len� soubor, a nen� jej t�eba stahovat.\n\n"
+msgid ""
+"Server file no newer than local file `%s' -- not retrieving.\n"
+"\n"
+msgstr ""
+"Lok�ln� soubor `%s' nen� star��, ne� vzd�len� soubor, a nen� jej t�eba "
+"stahovat.\n"
+"\n"
 
 # , c-format
-#: src/http.c:1680
-#, c-format
-msgid "The sizes do not match (local %ld) -- retrieving.\n"
+#: src/http.c:2566
+#, fuzzy, c-format
+msgid "The sizes do not match (local %s) -- retrieving.\n"
 msgstr "Velikosti se neshoduj� (lok�ln� %ld), soubor je t�eba st�hnout.\n"
 
-#: src/http.c:1684
+#: src/http.c:2573
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Lok�ln� soubor je star�� a vzd�len� soubor se proto bude p�en�et.\n"
 
-# , c-format
-#: src/http.c:1728
-#, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
-msgstr "%s (%s) - `%s' ulo�eno [%ld/%ld]\n\n"
+#: src/http.c:2596
+#, fuzzy
+msgid ""
+"Remote file exists and could contain links to other resources -- "
+"retrieving.\n"
+"\n"
+msgstr ""
+"Vzd�len� soubor je nov�j��, ne� lok�ln� soubor `%s', a je jej t�eba "
+"st�hnout.\n"
+"\n"
 
-# , c-format
-#: src/http.c:1774
-#, c-format
-msgid "%s (%s) - Connection closed at byte %ld. "
-msgstr "%s (%s) - Spojen� ukon�eno na bajtu %ld. "
+#: src/http.c:2602
+#, fuzzy
+msgid ""
+"Remote file exists but does not contain any link -- not retrieving.\n"
+"\n"
+msgstr ""
+"Vzd�len� soubor nen� nov�j��, ne� lok�ln� soubor `%s', a nen� jej t�eba "
+"stahovat.\n"
+
+#: src/http.c:2610
+#, fuzzy
+msgid ""
+"Remote file exists but recursion is disabled -- not retrieving.\n"
+"\n"
+msgstr ""
+"Vzd�len� soubor nen� nov�j��, ne� lok�ln� soubor `%s', a nen� jej t�eba "
+"stahovat.\n"
 
 # , c-format
-#: src/http.c:1782
-#, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
-msgstr "%s (%s) - `%s' ulo�eno [%ld/%ld])\n\n"
+#: src/http.c:2652
+#, fuzzy, c-format
+msgid ""
+"%s (%s) - `%s' saved [%s/%s]\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' ulo�eno [%ld/%ld]\n"
+"\n"
 
 # , c-format
-#: src/http.c:1801
-#, c-format
-msgid "%s (%s) - Connection closed at byte %ld/%ld. "
-msgstr "%s (%s) - Spojen� ukon�eno na bajtu %ld/%ld. "
+#: src/http.c:2707
+#, fuzzy, c-format
+msgid "%s (%s) - Connection closed at byte %s. "
+msgstr "%s (%s) - Spojen� ukon�eno na bajtu %ld. "
 
 # , c-format
-#: src/http.c:1812
-#, c-format
-msgid "%s (%s) - Read error at byte %ld (%s)."
+#: src/http.c:2722
+#, fuzzy, c-format
+msgid "%s (%s) - Read error at byte %s (%s)."
 msgstr "%s (%s) - Chyba p�i �ten� dat na bajtu %ld (%s)."
 
 # , c-format
-#: src/http.c:1820
-#, c-format
-msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
+#: src/http.c:2731
+#, fuzzy, c-format
+msgid "%s (%s) - Read error at byte %s/%s (%s). "
 msgstr "%s (%s) - Chyba p�i �ten� dat na bajtu %ld/%ld (%s). "
 
+#: src/init.c:371
+#, c-format
+msgid "%s: WGETRC points to %s, which doesn't exist.\n"
+msgstr ""
+
 # , c-format
-#: src/init.c:349 src/netrc.c:267
+#: src/init.c:434 src/netrc.c:267
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: Nelze p�e��st %s (%s).\n"
 
 # , c-format
-#: src/init.c:367 src/init.c:373
+#: src/init.c:452
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: Chyba v %s na ��dku %d.\n"
 
 # , c-format
-#: src/init.c:405
-#, c-format
-msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
-msgstr "%s: Varov�n�: Glob�ln� i u�ivatelsk� wgetrc jsou shodn� ulo�eny v `%s'.\n"
+#: src/init.c:458
+#, fuzzy, c-format
+msgid "%s: Syntax error in %s at line %d.\n"
+msgstr "%s: Chyba v %s na ��dku %d.\n"
 
 # , c-format
-#: src/init.c:497
-#, c-format
-msgid "%s: BUG: unknown command `%s', value `%s'.\n"
+#: src/init.c:463
+#, fuzzy, c-format
+msgid "%s: Unknown command `%s' in %s at line %d.\n"
 msgstr "%s: CHYBA: Nezn�m� p��kaz `%s', hodnota `%s'.\n"
 
-#: src/init.c:529
+# , c-format
+#: src/init.c:508
 #, c-format
-msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
-msgstr "%s: %s: `%s' nelze p�ev�st na IP adresu.\n"
+msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
+msgstr ""
+"%s: Varov�n�: Glob�ln� i u�ivatelsk� wgetrc jsou shodn� ulo�eny v `%s'.\n"
 
 # , c-format
-#: src/init.c:559
-#, c-format
-msgid "%s: %s: Please specify on or off.\n"
+#: src/init.c:661
+#, fuzzy, c-format
+msgid "%s: Invalid --execute command `%s'\n"
+msgstr "%s: Neplatn� specifikace `%s'\n"
+
+# , c-format
+#: src/init.c:706
+#, fuzzy, c-format
+msgid "%s: %s: Invalid boolean `%s'; use `on' or `off'.\n"
 msgstr "%s: %s: Zadejte pros�m `on' (zapnuto) nebo `off' (vypnuto).\n"
 
 # , c-format
-#: src/init.c:603
-#, c-format
-msgid "%s: %s: Please specify always, on, off, or never.\n"
-msgstr "%s: %s: Zadejte pros�m `always' (v�dy), `on' (zapnuto), `off' (vypnuto), nebo `never' (nikdy).\n"
+#: src/init.c:723
+#, fuzzy, c-format
+msgid "%s: %s: Invalid number `%s'.\n"
+msgstr "%s: %s: Neplatn� specifikace `%s'\n"
 
 # , c-format
-#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
-#, c-format
-msgid "%s: %s: Invalid specification `%s'.\n"
+#: src/init.c:954 src/init.c:973
+#, fuzzy, c-format
+msgid "%s: %s: Invalid byte value `%s'\n"
 msgstr "%s: %s: Neplatn� specifikace `%s'\n"
 
 # , c-format
-#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
-#, c-format
-msgid "%s: Invalid specification `%s'\n"
-msgstr "%s: Neplatn� specifikace `%s'\n"
+#: src/init.c:998
+#, fuzzy, c-format
+msgid "%s: %s: Invalid time period `%s'\n"
+msgstr "%s: %s: Neplatn� specifikace `%s'\n"
 
 # , c-format
-#: src/main.c:120
-#, c-format
-msgid "Usage: %s [OPTION]... [URL]...\n"
-msgstr "Pou�it�: %s [P�EP�NA�]... [URL]...\n"
+#: src/init.c:1052 src/init.c:1142 src/init.c:1245 src/init.c:1270
+#, fuzzy, c-format
+msgid "%s: %s: Invalid value `%s'.\n"
+msgstr "%s: %s: Neplatn� specifikace `%s'\n"
 
 # , c-format
-#: src/main.c:128
-#, c-format
-msgid "GNU Wget %s, a non-interactive network retriever.\n"
-msgstr "GNU Wget %s, program pro neinteraktivn� stahov�n� soubor�.\n"
+#: src/init.c:1089
+#, fuzzy, c-format
+msgid "%s: %s: Invalid header `%s'.\n"
+msgstr "%s: %s: Neplatn� specifikace `%s'\n"
 
-#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
-#. don't bitch.  Also, it makes translation much easier.
-#: src/main.c:133
-msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
-msgstr ""
-"\n"
-"Argumenty, povinn� u dlouh�ch p�ep�na��, jsou povinn� i pro kr�tk� verze\n"
-"p�ep�na��.\n"
-"\n"
+# , c-format
+#: src/init.c:1155
+#, fuzzy, c-format
+msgid "%s: %s: Invalid progress type `%s'.\n"
+msgstr "%s: %s: Neplatn� specifikace `%s'\n"
 
-#: src/main.c:137
+#: src/init.c:1214
+#, c-format
 msgid ""
-"Startup:\n"
-"  -V,  --version           display the version of Wget and exit.\n"
-"  -h,  --help              print this help.\n"
-"  -b,  --background        go to background after startup.\n"
-"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
-"\n"
+"%s: %s: Invalid restriction `%s', use [unix|windows],[lowercase|uppercase],"
+"[nocontrol].\n"
 msgstr ""
-"Za��tek:\n"
-"  -V,  --version           vyp�e informaci o verzi programu Wget a skon��\n"
-"  -h,  --help              vyp�e tuto n�pov�du\n"
-"  -b,  --background        po spu�t�n� pokra�uje program v b�hu na pozad�\n"
-"  -e,  --execute=P��KAZ    prove�e p��kaz zadan� ve stylu `.wgetrc'\n"
+
+#: src/log.c:783
+#, fuzzy, c-format
+msgid ""
 "\n"
+"%s received, redirecting output to `%s'.\n"
+msgstr "Byl zachycen sign�l %s, v�stup p�esm�rov�n do `%%s'.\n"
 
-# , fuzzy
-#: src/main.c:144
-msgid ""
-"Logging and input file:\n"
-"  -o,  --output-file=FILE     log messages to FILE.\n"
-"  -a,  --append-output=FILE   append messages to FILE.\n"
-"  -d,  --debug                print debug output.\n"
-"  -q,  --quiet                quiet (no output).\n"
-"  -v,  --verbose              be verbose (this is the default).\n"
-"  -nv, --non-verbose          turn off verboseness, without being quiet.\n"
-"  -i,  --input-file=FILE      download URLs found in FILE.\n"
-"  -F,  --force-html           treat input file as HTML.\n"
-"  -B,  --base=URL             prepends URL to relative links in -F -i file.\n"
-"       --sslcertfile=FILE     optional client certificate.\n"
-"       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n"
+#. Eek!  Opening the alternate log file has failed.  Nothing we
+#. can do but disable printing completely.
+#: src/log.c:793
+#, fuzzy, c-format
+msgid ""
 "\n"
+"%s received.\n"
+msgstr "Nep�i�la ��dn� data"
+
+#: src/log.c:794
+#, c-format
+msgid "%s: %s; disabling logging.\n"
 msgstr ""
-"Protokolov�n� a vstupn� soubor:\n"
-"  -o,  --output-file=SOUBOR   n�zev souboru s protokolem\n"
-"  -a,  --append-output=SOUBOR protokol se p�ipoj� na konec tohoto souboru\n"
-"  -d,  --debug                vypisuje ladic� informace\n"
-"  -q,  --quiet                nevypisuje v�bec nic\n"
-"  -v,  --verbose              bude upov�dan� (implicitn� zapnuto)\n"
-"  -nv, --non-verbose          vypisuje pouze nejd�le�it�j�� informace\n"
-"  -i,  --input-file=SOUBOR    v�choz� URL odkazy na�te z tohoto souboru\n"
-"  -F,  --force-html           soubor s URL je v HTML form�tu\n"
-"  -B,  --base=URL             p�id� URL na za��tky relat. odkaz� p�i '-F -i'\n"
-"       --sslcertfile=SOUBOR   voliteln� certifik�t klienta\n"
-"       --sslcertkey=SOUBOR    voliteln� soubor kl��� pro tento certifik�t\n"
-"\n"
 
-# , fuzzy
-#: src/main.c:158
-msgid ""
-"Download:\n"
-"       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local host.\n"
-"  -t,  --tries=NUMBER           set number of retries to NUMBER (0 unlimits).\n"
-"  -O   --output-document=FILE   write documents to FILE.\n"
-"  -nc, --no-clobber             don't clobber existing files or use .# suffixes.\n"
-"  -c,  --continue               resume getting a partially-downloaded file.\n"
-"       --dot-style=STYLE        set retrieval display style.\n"
-"  -N,  --timestamping           don't re-retrieve files unless newer than local.\n"
-"  -S,  --server-response        print server response.\n"
-"       --spider                 don't download anything.\n"
-"  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n"
-"  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
-"       --waitretry=SECONDS      wait 1...SECONDS between retries of a retrieval.\n"
-"  -Y,  --proxy=on/off           turn proxy on or off.\n"
-"  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
+# , c-format
+#: src/main.c:353
+#, c-format
+msgid "Usage: %s [OPTION]... [URL]...\n"
+msgstr "Pou�it�: %s [P�EP�NA�]... [URL]...\n"
+
+#: src/main.c:365
+#, fuzzy
+msgid ""
+"Mandatory arguments to long options are mandatory for short options too.\n"
 "\n"
 msgstr ""
-"Stahov�n�:\n"
-"       --bind-address=ADRESA    pou�ij lok�ln� rozhran� s danou adresou (IP nebo jm�no)\n"
-"  -t,  --tries=��SLO            po�et pokus� st�hnout URL (0 donekone�na)\n"
-"  -O   --output-document=SOUBOR sta�en� dokumenty ukl�d� do tohoto souboru\n"
-"  -nc, --no-clobber             nep�episuje existuj�c� soubory\n"
-"  -c,  --continue               pokra�uje ve stahov�n� ��ste�n� p�enesen�ch dat\n"
-"       --dot-style=STYL         nastav� zp�sob zobrazen� p�i stahov�n� dat\n"
-"  -N,  --timestamping           nestahuje star�� soubory (zapne �asov� raz�tka)\n"
-"  -S,  --server-response        vypisuje odpov�di serveru\n"
-"       --spider                 nic nestahuje\n"
-"  -T,  --timeout=SEKUNDY        nastav� timeout p�i �ten� na tuto hodnotu\n"
-"  -w,  --wait=PO�ET             p�ed ka�d�m stahov�n�m po�k� PO�ET sekund\n"
-"       --waitretry=PO�ET        �ek� 1...PO�ET sec p�ed nov�m pokusem o sta�en�\n"
-"  -Y,  --proxy=on/off           zapne p�enos p�es proxy (standardn� `off')\n"
-"  -Q,  --quota=BAJT�            nastav� limit objemu ulo�en�ch dat\n"
 "\n"
-
-# , fuzzy
-#: src/main.c:175
-msgid ""
-"Directories:\n"
-"  -nd  --no-directories            don't create directories.\n"
-"  -x,  --force-directories         force creation of directories.\n"
-"  -nH, --no-host-directories       don't create host directories.\n"
-"  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
-"       --cut-dirs=NUMBER           ignore NUMBER remote directory components.\n"
+"Argumenty, povinn� u dlouh�ch p�ep�na��, jsou povinn� i pro kr�tk� verze\n"
+"p�ep�na��.\n"
 "\n"
+
+#: src/main.c:367
+msgid "Startup:\n"
 msgstr ""
-"Adres��e:\n"
-"  -nd  --no-directories            nevytv��� adres��e\n"
-"  -x,  --force-directories         v�dy vytv��� adres��e\n"
-"  -nH, --no-host-directories       nevytv��� adres��e s adresou serveru\n"
-"  -P,  --directory-prefix=PREFIX   ukl�d� data do PREFIX/...\n"
-"       --cut-dirs=PO�ET            nevytv��� prvn�ch PO�ET podadres���\n"
-"\n"
 
-# , fuzzy
-#: src/main.c:183
-msgid ""
-"HTTP options:\n"
-"       --http-user=USER      set http user to USER.\n"
-"       --http-passwd=PASS    set http password to PASS.\n"
-"  -C,  --cache=on/off        (dis)allow server-cached data (normally allowed).\n"
-"  -E,  --html-extension      save all text/html documents with .html extension.\n"
-"       --ignore-length       ignore `Content-Length' header field.\n"
-"       --header=STRING       insert STRING among the headers.\n"
-"       --proxy-user=USER     set USER as proxy username.\n"
-"       --proxy-passwd=PASS   set PASS as proxy password.\n"
-"       --referer=URL         include `Referer: URL' header in HTTP request.\n"
-"  -s,  --save-headers        save the HTTP headers to file.\n"
-"  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n"
-"       --no-http-keep-alive  disable HTTP keep-alive (persistent connections).\n"
-"       --cookies=off         don't use cookies.\n"
-"       --load-cookies=FILE   load cookies from FILE before session.\n"
-"       --save-cookies=FILE   save cookies to FILE after session.\n"
-"\n"
+#: src/main.c:369
+msgid "  -V,  --version           display the version of Wget and exit.\n"
 msgstr ""
-"P�ep�na�e pro HTTP:\n"
-"       --http-user=U�IVATEL  u�ivatelsk� jm�no pro autorizovan� HTTP p�enos\n"
-"       --http-passwd=HESLO   heslo pro autorizovan� HTTP p�enos \n"
-"  -C,  --cache=on/off        povol� �i zak�e pou�it� vyrovn�vac� pam�ti na\n"
-"                             stran� serveru (implicitn� `on')\n"
-"  -E,  --html-extension      ulo�� dokumenty typu `text/html' s p��ponou .html\n"
-"       --ignore-length       ignoruje pole `Content-Length' v hlavi�ce\n"
-"       --header=�ET�ZEC      po�le �ET�ZEC serveru jako sou��st hlavi�ek\n"
-"       --proxy-user=U�IVATEL jm�no u�ivatele vy�adovan� pro proxy p�enos\n"
-"       --proxy-passwd=HESLO  heslo pro proxy p�enos\n"
-"       --referer=URL         pos�l� v hlavi�cce HTTP po�adavku `Referer: URL'\n"
-"  -s,  --save-headers        do stahovan�ho souboru ulo�� i hlavi�ky HTTP\n"
-"  -U,  --user-agent=AGENT    m�sto identifikace `Wget/VERZE' pos�l� v hlavi�ce \n"
-"                             HTTP po�adavku identifika�n� �et�zec AGENT\n"
-"       --no-http-keep-alive  vypne HTTP keep-alive (trval� spojen� se serverem)\n"
-"       --cookies=off         nebude pou��vat kol��ky (HTTP cookies)\n"
-"       --load-cookies=SOUBOR p�ed sezen�m na�te kol��ky ze souboru SOUBOR\n"
-"       --save-cookies=SOUBOR po sezen� ulo�� kol��ky do souboru SOUBOR\n"
-"\n"
 
-# , fuzzy
-#: src/main.c:201
+#: src/main.c:371
+msgid "  -h,  --help              print this help.\n"
+msgstr ""
+
+#: src/main.c:373
+msgid "  -b,  --background        go to background after startup.\n"
+msgstr ""
+
+#: src/main.c:375
+msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
+msgstr ""
+
+#: src/main.c:379
+msgid "Logging and input file:\n"
+msgstr ""
+
+#: src/main.c:381
+msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
+msgstr ""
+
+#: src/main.c:383
+msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
+msgstr ""
+
+#: src/main.c:386
+msgid "  -d,  --debug               print lots of debugging information.\n"
+msgstr ""
+
+#: src/main.c:389
+msgid "  -q,  --quiet               quiet (no output).\n"
+msgstr ""
+
+#: src/main.c:391
+msgid "  -v,  --verbose             be verbose (this is the default).\n"
+msgstr ""
+
+#: src/main.c:393
 msgid ""
-"FTP options:\n"
-"  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
-"  -g,  --glob=on/off           turn file name globbing on or off.\n"
-"       --passive-ftp           use the \"passive\" transfer mode.\n"
-"       --retr-symlinks         when recursing, get linked-to files (not dirs).\n"
-"\n"
+"  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
+msgstr ""
+
+#: src/main.c:395
+msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
+msgstr ""
+
+#: src/main.c:397
+msgid "  -F,  --force-html          treat input file as HTML.\n"
+msgstr ""
+
+#: src/main.c:399
+msgid ""
+"  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
+msgstr ""
+
+#: src/main.c:403
+msgid "Download:\n"
+msgstr ""
+
+#: src/main.c:405
+msgid ""
+"  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
+"unlimits).\n"
+msgstr ""
+
+#: src/main.c:407
+msgid "       --retry-connrefused       retry even if connection is refused.\n"
+msgstr ""
+
+#: src/main.c:409
+msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
+msgstr ""
+
+#: src/main.c:411
+msgid ""
+"  -nc, --no-clobber              skip downloads that would download to\n"
+"                                 existing files.\n"
+msgstr ""
+
+#: src/main.c:414
+msgid ""
+"  -c,  --continue                resume getting a partially-downloaded "
+"file.\n"
+msgstr ""
+
+#: src/main.c:416
+msgid "       --progress=TYPE           select progress gauge type.\n"
+msgstr ""
+
+#: src/main.c:418
+msgid ""
+"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
+"                                 local.\n"
+msgstr ""
+
+#: src/main.c:421
+msgid "  -S,  --server-response         print server response.\n"
+msgstr ""
+
+#: src/main.c:423
+msgid "       --spider                  don't download anything.\n"
+msgstr ""
+
+#: src/main.c:425
+msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
+msgstr ""
+
+#: src/main.c:427
+msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:429
+msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:431
+msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:433
+msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
+msgstr ""
+
+#: src/main.c:435
+msgid ""
+"       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
+"retrieval.\n"
+msgstr ""
+
+#: src/main.c:437
+msgid ""
+"       --random-wait             wait from 0...2*WAIT secs between "
+"retrievals.\n"
+msgstr ""
+
+#: src/main.c:439
+msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
+msgstr ""
+
+#: src/main.c:441
+msgid "       --no-proxy                explicitly turn off proxy.\n"
+msgstr ""
+
+#: src/main.c:443
+msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
+msgstr ""
+
+#: src/main.c:445
+msgid ""
+"       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
+"host.\n"
+msgstr ""
+
+#: src/main.c:447
+msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
+msgstr ""
+
+#: src/main.c:449
+msgid "       --no-dns-cache            disable caching DNS lookups.\n"
+msgstr ""
+
+#: src/main.c:451
+msgid ""
+"       --restrict-file-names=OS  restrict chars in file names to ones OS "
+"allows.\n"
+msgstr ""
+
+#: src/main.c:453
+msgid ""
+"       --ignore-case             ignore case when matching files/"
+"directories.\n"
+msgstr ""
+
+#: src/main.c:456
+msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
+msgstr ""
+
+#: src/main.c:458
+msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
+msgstr ""
+
+#: src/main.c:460
+msgid ""
+"       --prefer-family=FAMILY    connect first to addresses of specified "
+"family,\n"
+"                                 one of IPv6, IPv4, or none.\n"
+msgstr ""
+
+#: src/main.c:464
+msgid "       --user=USER               set both ftp and http user to USER.\n"
+msgstr ""
+
+#: src/main.c:466
+msgid ""
+"       --password=PASS           set both ftp and http password to PASS.\n"
+msgstr ""
+
+#: src/main.c:470
+#, fuzzy
+msgid "Directories:\n"
+msgstr "Adres��     "
+
+#: src/main.c:472
+msgid "  -nd, --no-directories           don't create directories.\n"
+msgstr ""
+
+#: src/main.c:474
+msgid "  -x,  --force-directories        force creation of directories.\n"
+msgstr ""
+
+#: src/main.c:476
+msgid "  -nH, --no-host-directories      don't create host directories.\n"
+msgstr ""
+
+#: src/main.c:478
+msgid "       --protocol-directories     use protocol name in directories.\n"
+msgstr ""
+
+#: src/main.c:480
+msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
+msgstr ""
+
+#: src/main.c:482
+msgid ""
+"       --cut-dirs=NUMBER          ignore NUMBER remote directory "
+"components.\n"
+msgstr ""
+
+#: src/main.c:486
+msgid "HTTP options:\n"
+msgstr ""
+
+#: src/main.c:488
+msgid "       --http-user=USER        set http user to USER.\n"
+msgstr ""
+
+#: src/main.c:490
+msgid "       --http-password=PASS    set http password to PASS.\n"
+msgstr ""
+
+#: src/main.c:492
+msgid "       --no-cache              disallow server-cached data.\n"
+msgstr ""
+
+#: src/main.c:494
+msgid ""
+"  -E,  --html-extension        save HTML documents with `.html' extension.\n"
+msgstr ""
+
+#: src/main.c:496
+msgid "       --ignore-length         ignore `Content-Length' header field.\n"
+msgstr ""
+
+#: src/main.c:498
+msgid "       --header=STRING         insert STRING among the headers.\n"
+msgstr ""
+
+#: src/main.c:500
+msgid "       --max-redirect          maximum redirections allowed per page.\n"
+msgstr ""
+
+#: src/main.c:502
+msgid "       --proxy-user=USER       set USER as proxy username.\n"
+msgstr ""
+
+#: src/main.c:504
+msgid "       --proxy-password=PASS   set PASS as proxy password.\n"
+msgstr ""
+
+#: src/main.c:506
+msgid ""
+"       --referer=URL           include `Referer: URL' header in HTTP "
+"request.\n"
+msgstr ""
+
+#: src/main.c:508
+msgid "       --save-headers          save the HTTP headers to file.\n"
+msgstr ""
+
+#: src/main.c:510
+msgid ""
+"  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
+msgstr ""
+
+#: src/main.c:512
+msgid ""
+"       --no-http-keep-alive    disable HTTP keep-alive (persistent "
+"connections).\n"
+msgstr ""
+
+#: src/main.c:514
+msgid "       --no-cookies            don't use cookies.\n"
+msgstr ""
+
+#: src/main.c:516
+msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
+msgstr ""
+
+#: src/main.c:518
+msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
+msgstr ""
+
+#: src/main.c:520
+msgid ""
+"       --keep-session-cookies  load and save session (non-permanent) "
+"cookies.\n"
+msgstr ""
+
+#: src/main.c:522
+msgid ""
+"       --post-data=STRING      use the POST method; send STRING as the "
+"data.\n"
+msgstr ""
+
+#: src/main.c:524
+msgid ""
+"       --post-file=FILE        use the POST method; send contents of FILE.\n"
+msgstr ""
+
+#: src/main.c:526
+msgid ""
+"       --no-content-disposition  don't honor Content-Disposition header.\n"
+msgstr ""
+
+#: src/main.c:531
+msgid "HTTPS (SSL/TLS) options:\n"
+msgstr ""
+
+#: src/main.c:533
+msgid ""
+"       --secure-protocol=PR     choose secure protocol, one of auto, SSLv2,\n"
+"                                SSLv3, and TLSv1.\n"
+msgstr ""
+
+#: src/main.c:536
+msgid ""
+"       --no-check-certificate   don't validate the server's certificate.\n"
+msgstr ""
+
+#: src/main.c:538
+msgid "       --certificate=FILE       client certificate file.\n"
+msgstr ""
+
+#: src/main.c:540
+msgid "       --certificate-type=TYPE  client certificate type, PEM or DER.\n"
+msgstr ""
+
+#: src/main.c:542
+msgid "       --private-key=FILE       private key file.\n"
+msgstr ""
+
+#: src/main.c:544
+msgid "       --private-key-type=TYPE  private key type, PEM or DER.\n"
+msgstr ""
+
+#: src/main.c:546
+msgid "       --ca-certificate=FILE    file with the bundle of CA's.\n"
+msgstr ""
+
+#: src/main.c:548
+msgid ""
+"       --ca-directory=DIR       directory where hash list of CA's is "
+"stored.\n"
+msgstr ""
+
+#: src/main.c:550
+msgid ""
+"       --random-file=FILE       file with random data for seeding the SSL "
+"PRNG.\n"
+msgstr ""
+
+#: src/main.c:552
+msgid ""
+"       --egd-file=FILE          file naming the EGD socket with random "
+"data.\n"
+msgstr ""
+
+#: src/main.c:557
+msgid "FTP options:\n"
+msgstr ""
+
+#: src/main.c:559
+msgid "       --ftp-user=USER         set ftp user to USER.\n"
+msgstr ""
+
+#: src/main.c:561
+msgid "       --ftp-password=PASS     set ftp password to PASS.\n"
 msgstr ""
-"P�ep�na�e pro FTP protokol:\n"
-"  -nr, --dont-remove-listing  nema�e soubory `.listing' s obsahy adres���\n"
-"  -g,  --glob=on/off          zapne �i vypne expanzi �ol�k� ve jm�nech soubor�\n"
-"       --passive-ftp          pou�ije pasivn� m�d p�enosu dat\n"
-"       --retr-symlinks        v rekurzivn�m m�du stahuje i symbolick� odkazy na\n"
-"                              soubory (nikoliv na adres��e)\n"
 
-#: src/main.c:208
+#: src/main.c:563
+msgid "       --no-remove-listing     don't remove `.listing' files.\n"
+msgstr ""
+
+#: src/main.c:565
+msgid "       --no-glob               turn off FTP file name globbing.\n"
+msgstr ""
+
+#: src/main.c:567
+msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
+msgstr ""
+
+#: src/main.c:569
+msgid ""
+"       --retr-symlinks         when recursing, get linked-to files (not "
+"dir).\n"
+msgstr ""
+
+#: src/main.c:571
+msgid "       --preserve-permissions  preserve remote file permissions.\n"
+msgstr ""
+
+#: src/main.c:575
+msgid "Recursive download:\n"
+msgstr ""
+
+#: src/main.c:577
+msgid "  -r,  --recursive          specify recursive download.\n"
+msgstr ""
+
+#: src/main.c:579
+msgid ""
+"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
+"infinite).\n"
+msgstr ""
+
+#: src/main.c:581
 msgid ""
-"Recursive retrieval:\n"
-"  -r,  --recursive          recursive web-suck -- use with care!\n"
-"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for infinite).\n"
 "       --delete-after       delete files locally after downloading them.\n"
-"  -k,  --convert-links      convert non-relative links to relative.\n"
+msgstr ""
+
+#: src/main.c:583
+msgid ""
+"  -k,  --convert-links      make links in downloaded HTML point to local "
+"files.\n"
+msgstr ""
+
+#: src/main.c:585
+msgid ""
 "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
-"  -m,  --mirror             shortcut option equivalent to -r -N -l inf -nr.\n"
-"  -p,  --page-requisites    get all images, etc. needed to display HTML page.\n"
-"\n"
 msgstr ""
-"Rekurzivn� stahov�n�:\n"
-"  -r,  --recursive             rekurzivn� stahov�n� -- bu�te opatrn�!\n"
-"  -l,  --level=��SLO           maxim�ln� hloubka rekurze (0 bez limitu)\n"
-"       --delete-after          po p�enosu sma�e sta�en� soubory\n"
-"  -k,  --convert-links         absolutn� URL p�eve�e na relativn�\n"
-"  -K,  --backup-converted      p�ed konverz� ulo�� `X' jako `X.orig'\n"
-"  -m,  --mirror                zapne p�ep�na�e vhodn� pro zrcadlen� dat \n"
-"  -p,  --page-requisites       st�hne v�e nutn� pro zobrazen� HTML str�nky\n"
 
-# , fuzzy
-#: src/main.c:218
-msgid ""
-"Recursive accept/reject:\n"
-"  -A,  --accept=LIST                comma-separated list of accepted extensions.\n"
-"  -R,  --reject=LIST                comma-separated list of rejected extensions.\n"
-"  -D,  --domains=LIST               comma-separated list of accepted domains.\n"
-"       --exclude-domains=LIST       comma-separated list of rejected domains.\n"
-"       --follow-ftp                 follow FTP links from HTML documents.\n"
-"       --follow-tags=LIST           comma-separated list of followed HTML tags.\n"
-"  -G,  --ignore-tags=LIST           comma-separated list of ignored HTML tags.\n"
-"  -H,  --span-hosts                 go to foreign hosts when recursive.\n"
-"  -L,  --relative                   follow relative links only.\n"
-"  -I,  --include-directories=LIST   list of allowed directories.\n"
-"  -X,  --exclude-directories=LIST   list of excluded directories.\n"
-"  -nh, --no-host-lookup             don't DNS-lookup hosts.\n"
-"  -np, --no-parent                  don't ascend to the parent directory.\n"
-"\n"
+#: src/main.c:587
+msgid ""
+"  -m,  --mirror             shortcut for -N -r -l inf --no-remove-listing.\n"
+msgstr ""
+
+#: src/main.c:589
+msgid ""
+"  -p,  --page-requisites    get all images, etc. needed to display HTML "
+"page.\n"
+msgstr ""
+
+#: src/main.c:591
+msgid ""
+"       --strict-comments    turn on strict (SGML) handling of HTML "
+"comments.\n"
+msgstr ""
+
+#: src/main.c:595
+msgid "Recursive accept/reject:\n"
+msgstr ""
+
+#: src/main.c:597
+msgid ""
+"  -A,  --accept=LIST               comma-separated list of accepted "
+"extensions.\n"
+msgstr ""
+
+#: src/main.c:599
+msgid ""
+"  -R,  --reject=LIST               comma-separated list of rejected "
+"extensions.\n"
+msgstr ""
+
+#: src/main.c:601
+msgid ""
+"  -D,  --domains=LIST              comma-separated list of accepted "
+"domains.\n"
+msgstr ""
+
+#: src/main.c:603
+msgid ""
+"       --exclude-domains=LIST      comma-separated list of rejected "
+"domains.\n"
+msgstr ""
+
+#: src/main.c:605
+msgid ""
+"       --follow-ftp                follow FTP links from HTML documents.\n"
+msgstr ""
+
+#: src/main.c:607
+msgid ""
+"       --follow-tags=LIST          comma-separated list of followed HTML "
+"tags.\n"
+msgstr ""
+
+#: src/main.c:609
+msgid ""
+"       --ignore-tags=LIST          comma-separated list of ignored HTML "
+"tags.\n"
+msgstr ""
+
+#: src/main.c:611
+msgid ""
+"  -H,  --span-hosts                go to foreign hosts when recursive.\n"
+msgstr ""
+
+#: src/main.c:613
+msgid "  -L,  --relative                  follow relative links only.\n"
+msgstr ""
+
+#: src/main.c:615
+msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
+msgstr ""
+
+#: src/main.c:617
+msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
+msgstr ""
+
+#: src/main.c:619
+msgid ""
+"  -np, --no-parent                 don't ascend to the parent directory.\n"
 msgstr ""
-"Omezen� p�i rekurzi:\n"
-"  -A,  --accept=SEZNAM              seznam povolen�ch extenz� soubor�\n"
-"  -R,  --reject=SEZNAM              seznam nepovolen�ch extenz� soubor�\n"
-"  -D,  --domains=SEZNAM             seznam povolen�ch dom�n\n"
-"       --exclude-domains=SEZNAM     seznam nepovolen�ch dom�n\n"
-"       --follow-ftp                 n�sleduje FTP odkazy v HTML dokumentech\n"
-"       --follow-tags=LIST           seznam n�sledovan�ch HTML zna�ek \n"
-"  -G,  --ignore-tags=LIST           seznam ignorovan�ch HTML zna�ek\n"
-"  -H,  --span-hosts                 na��t� dokumenty i z ostatn�ch server�\n"
-"  -I,  --include-directories=SEZNAM seznam povolen�ch adres���\n"
-"  -L,  --relative                   n�sleduje pouze relativn� odkazy\n"
-"  -X,  --exclude-directories=SEZNAM seznam vylou�en�ch adres���\n"
-"  -nh, --no-host-lookup             nevyhled�v� adresy v DNS\n"
-"  -np, --no-parent                  nesestupuje do rodi�ovsk�ho adres��e\n"
-"\n"
 
 # , fuzzy
-#: src/main.c:234
+#: src/main.c:623
 msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
 msgstr ""
 "Zpr�vy o chyb�ch a n�vrhy na vylep�en� programu zas�lejte na adresu\n"
 "<bug-wget@gnu.org> (pouze anglicky).\n"
 "Koment��e k �esk�mu p�ekladu zas�lejte na adresu <cs@li.org>. \n"
 
-# , fuzzy
-#: src/main.c:420
+# , c-format
+#: src/main.c:628
 #, c-format
-msgid "%s: debug support not compiled in.\n"
-msgstr "%s: program nebyl zkompilov�n s podporou pro lad�n�.\n"
+msgid "GNU Wget %s, a non-interactive network retriever.\n"
+msgstr "GNU Wget %s, program pro neinteraktivn� stahov�n� soubor�.\n"
 
-#: src/main.c:472
+#: src/main.c:668
+msgid "Copyright (C) 2007 Free Software Foundation, Inc.\n"
+msgstr ""
+
+#: src/main.c:670
 msgid ""
-"Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
-"This program is distributed in the hope that it will be useful,\n"
-"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
-"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
-"GNU General Public License for more details.\n"
+"License GPLv3+: GNU GPL version 3 or later\n"
+"<http://www.gnu.org/licenses/gpl.html>.\n"
+"This is free software: you are free to change and redistribute it.\n"
+"There is NO WARRANTY, to the extent permitted by law.\n"
 msgstr ""
-"Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
-"Tento program je ���en v nad�ji, �e bude u�ite�n�, av�ak\n"
-"BEZ JAK�KOLI Z�RUKY; neposkytuj� se ani odvozen� z�ruky PRODEJNOSTI \n"
-"anebo VHODNOSTI PRO UR�IT� ��EL. Dal�� podrobnosti hledejte \n"
-"v Obecn� ve�ejn� licenci GNU.\n"
 
-#: src/main.c:478
-msgid "\nOriginally written by Hrvoje Niksic <hniksic@arsdigita.com>.\n"
-msgstr "\nP�vodn�m autorem tohto programu je Hrvoje Nik�i� <hniksic@arsdigita.com>.\n"
+#: src/main.c:675
+#, fuzzy
+msgid ""
+"\n"
+"Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
+msgstr ""
+"\n"
+"P�vodn�m autorem tohto programu je Hrvoje Nik�i� <hniksic@arsdigita.com>.\n"
+
+#: src/main.c:677
+msgid "Currently maintained by Micah Cowan <micah@cowan.name>.\n"
+msgstr ""
 
 # , c-format
-#: src/main.c:569
+#. #### Something nicer should be printed here -- similar to the
+#. pre-1.5 `--help' page.
+#: src/main.c:724 src/main.c:793 src/main.c:890
 #, c-format
-msgid "%s: %s: invalid command\n"
-msgstr "%s: %s: neplatn� p��kaz\n"
+msgid "Try `%s --help' for more options.\n"
+msgstr "P��kaz `%s --help' vyp�e v�znam platn�ch p�ep�na��.\n"
 
 # , c-format
-#: src/main.c:625
+#: src/main.c:790
 #, c-format
 msgid "%s: illegal option -- `-n%c'\n"
 msgstr "%s: nep��pustn� p�ep�na� -- `-n%c'\n"
 
-# , c-format
-#. #### Something nicer should be printed here -- similar to the
-#. pre-1.5 `--help' page.
-#: src/main.c:628 src/main.c:670 src/main.c:728
+#: src/main.c:845
 #, c-format
-msgid "Try `%s --help' for more options.\n"
-msgstr "P��kaz `%s --help' vyp�e v�znam platn�ch p�ep�na��.\n"
-
-#: src/main.c:708
 msgid "Can't be verbose and quiet at the same time.\n"
 msgstr "Program nem��e b�t upov�dan� a zitcha najednou.\n"
 
-#: src/main.c:714
+#: src/main.c:851
+#, c-format
 msgid "Can't timestamp and not clobber old files at the same time.\n"
 msgstr "Nelze pou��vat �asov� raz�tka a nemazat p�itom star� soubory.\n"
 
+#: src/main.c:859
+#, c-format
+msgid "Cannot specify both --inet4-only and --inet6-only.\n"
+msgstr ""
+
+#: src/main.c:869
+#, c-format
+msgid "Cannot specify -r, -p or -N if -O is given.\n"
+msgstr ""
+
+#: src/main.c:877
+#, c-format
+msgid "Cannot specify both -k and -O if multiple URLs are given.\n"
+msgstr ""
+
 #. No URL specified.
-#: src/main.c:723
+#: src/main.c:885
 #, c-format
 msgid "%s: missing URL\n"
 msgstr "%s: chyb� URL\n"
 
 # , c-format
-#: src/main.c:825
+#: src/main.c:1005
 #, c-format
 msgid "No URLs found in %s.\n"
 msgstr "V souboru `%s' nebyla nalezena ��dn� URL.\n"
 
 # , c-format
-#: src/main.c:834
-#, c-format
+#: src/main.c:1023
+#, fuzzy, c-format
 msgid ""
-"\n"
 "FINISHED --%s--\n"
-"Downloaded: %s bytes in %d files\n"
+"Downloaded: %d files, %s in %s (%s)\n"
 msgstr ""
 "\n"
 "KONEC --%s--\n"
 "Celkem na�teno %s bajt� v %d souborech\n"
 
 # , c-format
-#: src/main.c:842
-#, c-format
-msgid "Download quota (%s bytes) EXCEEDED!\n"
+#: src/main.c:1032
+#, fuzzy, c-format
+msgid "Download quota of %s EXCEEDED!\n"
 msgstr "P�ekro�en limit objemu ulo�en�ch dat (%s bajt�)!\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:876
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "Byl zachycen sign�l %s, v�stup p�esm�rov�n do `%%s'.\n"
-
-# , c-format
-#: src/mswindows.c:89
+#: src/mswindows.c:96
 #, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"Stiskli jste CTRL+Break, v�stup byl proto p�esm�rov�n do `%s'.\n"
-"Program pokra�uje v b�hu na pozad�.\n"
-"Wget lze zastavit stiskem CTRL+ALT+DELETE.\n"
-
-#. parent, no error
-#: src/mswindows.c:106 src/utils.c:458
 msgid "Continuing in background.\n"
 msgstr "Program pokra�uje v b�hu na pozad�.\n"
 
+#: src/mswindows.c:289
+#, fuzzy, c-format
+msgid "Continuing in background, pid %lu.\n"
+msgstr "Program pokra�uje v b�hu na pozad�.\n"
+
 # , c-format
-#: src/mswindows.c:108 src/utils.c:460
+#: src/mswindows.c:291 src/utils.c:326
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "V�stup bude zaps�n do `%s'.\n"
 
-# , c-format
-#: src/mswindows.c:188
-#, c-format
-msgid "Starting WinHelp %s\n"
-msgstr "Spou�t� se WinHelp %s\n"
-
-#: src/mswindows.c:215 src/mswindows.c:222
+#: src/mswindows.c:459 src/mswindows.c:466
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Nelze naj�t pou�iteln� ovlada� socket�.\n"
 
 # , c-format
-#: src/netrc.c:367
+#: src/netrc.c:375
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr ""
