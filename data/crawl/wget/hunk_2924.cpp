 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1606
+#: src/ftp.c:1819
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Vzorku `%s' nic neodpov�d�.\n"
 
 # , c-format
-#: src/ftp.c:1671
-#, c-format
-msgid "Wrote HTML-ized index to `%s' [%ld].\n"
+#: src/ftp.c:1885
+#, fuzzy, c-format
+msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "V�pis adres��e v HTML form�tu byl zaps�n do `%s' [%ld].\n"
 
 # , c-format
-#: src/ftp.c:1676
+#: src/ftp.c:1890
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "V�pis adres��e v HTML form�tu byl zaps�n do `%s'.\n"
 
+#. Still not enough randomness, most likely because neither
+#. /dev/random nor EGD were available.  Resort to a simple and
+#. stupid method -- seed OpenSSL's PRNG with libc PRNG.  This is
+#. cryptographically weak, but people who care about strong
+#. cryptography should install /dev/random (default on Linux) or
+#. specify their own source of randomness anyway.
+#: src/gen_sslfunc.c:109
+msgid "Warning: using a weak random seed.\n"
+msgstr ""
+
+#: src/gen_sslfunc.c:166
+msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
+msgstr ""
+
+#: src/gen_sslfunc.c:223
+msgid "Warning: validation of server certificate not possible!\n"
+msgstr ""
+
 # , c-format
-#: src/getopt.c:454
+#: src/getopt.c:675
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: p�ep�na� `%s' nen� jednozna�n�\n"
 
 # , c-format
-#: src/getopt.c:478
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: p�ep�na� `--%s' nem� argument\n"
 
 # , c-format
-#: src/getopt.c:483
+#: src/getopt.c:705
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: p�ep�na� `%c%s' nem� argument\n"
 
 # , c-format
-#: src/getopt.c:498
+#: src/getopt.c:723 src/getopt.c:896
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: p�ep�na� `%s' vy�aduje argument\n"
 
 # , c-format
 #. --option
-#: src/getopt.c:528
+#: src/getopt.c:752
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: nezn�m� p�ep�na� `--%s'\n"
 
 # , c-format
 #. +option or -option
-#: src/getopt.c:532
+#: src/getopt.c:756
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: nezn�m� p�ep�na� `%c%s'\n"
 
 # , c-format
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:563
+#: src/getopt.c:782
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: nep��pustn� p�ep�na� -- %c\n"
 
 # , c-format
+#: src/getopt.c:785
+#, fuzzy, c-format
+msgid "%s: invalid option -- %c\n"
+msgstr "%s: nep��pustn� p�ep�na� -- %c\n"
+
+# , c-format
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:602
+#: src/getopt.c:815 src/getopt.c:945
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: p�ep�na� vy�aduje argument -- %c\n"
 
-#: src/host.c:374
-msgid "Host not found"
-msgstr "Po��ta� nebyl nalezen"
+# , c-format
+#: src/getopt.c:862
+#, fuzzy, c-format
+msgid "%s: option `-W %s' is ambiguous\n"
+msgstr "%s: p�ep�na� `%s' nen� jednozna�n�\n"
+
+# , c-format
+#: src/getopt.c:880
+#, fuzzy, c-format
+msgid "%s: option `-W %s' doesn't allow an argument\n"
+msgstr "%s: p�ep�na� `--%s' nem� argument\n"
+
+#: src/host.c:368
+#, fuzzy
+msgid "Unknown host"
+msgstr "Nezn�m� chyba"
+
+#. Message modeled after what gai_strerror returns in similar
+#. circumstances.
+#: src/host.c:372
+msgid "Temporary failure in name resolution"
+msgstr ""
 
-#: src/host.c:376
+#: src/host.c:374
 msgid "Unknown error"
 msgstr "Nezn�m� chyba"
 
+# , c-format
+#: src/host.c:748
+#, fuzzy, c-format
+msgid "Resolving %s... "
+msgstr "Ma�e se %s.\n"
+
+#: src/host.c:792 src/host.c:839
+#, c-format
+msgid "failed: %s.\n"
+msgstr ""
+
+#: src/host.c:801
+msgid "failed: No IPv4/IPv6 addresses for host.\n"
+msgstr ""
+
+#: src/host.c:842
+msgid "failed: timed out.\n"
+msgstr ""
+
+#: src/html-url.c:297
+#, c-format
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr ""
+
+#: src/http.c:349 src/http.c:1504
+#, c-format
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Nebylo mo�n� odeslat HTTP po�adavek: %s.\n"
+
+#: src/http.c:663
+msgid "No headers, assuming HTTP/0.9"
+msgstr ""
+
 #. this is fatal
-#: src/http.c:555
+#: src/http.c:1151
 msgid "Failed to set up an SSL context\n"
 msgstr "Nebylo mo�n� nastavit SSL kontext\n"
 
-#: src/http.c:561
+#: src/http.c:1156
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "SSL certifik�ty nebylo mo�n� ze souboru `%s' na��st.\n"
 
-#: src/http.c:565 src/http.c:573
+#: src/http.c:1159 src/http.c:1166
 msgid "Trying without the specified certificate\n"
 msgstr "Program se pokus� pokra�ovat bez zadan�ho certifik�tu.\n"
 
-#: src/http.c:569
+#: src/http.c:1163
 #, c-format
 msgid "Failed to get certificate key from %s\n"
-msgstr "Ze souboru `%s' nebylo mo�n� kl�� k certifik�tu na��st.\n\n"
-
-#: src/http.c:663 src/http.c:1593
-msgid "Unable to establish SSL connection.\n"
-msgstr "Nebylo mo�n� nav�zat SSL spojen�.\n"
+msgstr ""
+"Ze souboru `%s' nebylo mo�n� kl�� k certifik�tu na��st.\n"
+"\n"
 
 # , c-format
-#: src/http.c:671
-#, c-format
-msgid "Reusing connection to %s:%hu.\n"
+#: src/http.c:1382
+#, fuzzy, c-format
+msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Program vyu�ije existuj�c� spojen� s %s:%hu.\n"
 
-#: src/http.c:861
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
+#: src/http.c:1434
+#, fuzzy, c-format
+msgid "Failed writing to proxy: %s.\n"
+msgstr "Nebylo mo�n� odeslat HTTP po�adavek: %s.\n"
+
+#: src/http.c:1443
+#, fuzzy, c-format
+msgid "Failed reading proxy response: %s\n"
 msgstr "Nebylo mo�n� odeslat HTTP po�adavek: %s.\n"
 
+#: src/http.c:1463
+#, c-format
+msgid "Proxy tunneling failed: %s"
+msgstr ""
+
 # , c-format
-#: src/http.c:866
+#: src/http.c:1510
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s po�adavek odesl�n, program �ek� na odpov�� ... "
 
-#: src/http.c:910
-msgid "End of file while parsing headers.\n"
-msgstr "Hlavi�ka nen� �pln�.\n"
+#: src/http.c:1521
+#, fuzzy
+msgid "No data received.\n"
+msgstr "Nep�i�la ��dn� data"
 
 # , c-format
-#: src/http.c:920
+#: src/http.c:1528
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Chyba (%s) p�i �ten� hlavi�ek.\n"
 
-#: src/http.c:959
-msgid "No data received"
-msgstr "Nep�i�la ��dn� data"
+#. If we have tried it already, then there is not point
+#. retrying it.
+#: src/http.c:1595
+msgid "Authorization failed.\n"
+msgstr "Autorizace selhala.\n"
+
+#: src/http.c:1609
+msgid "Unknown authentication scheme.\n"
+msgstr "Server po�aduje nezn�m� zp�sob autentifikace.\n"
 
-#: src/http.c:961
+#: src/http.c:1634
 msgid "Malformed status line"
 msgstr "Odpov�� serveru m� zkomolen� stavov� ��dek"
 
-#: src/http.c:966
+#: src/http.c:1636
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
+#: src/http.c:1700
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "P�esm�rov�no na: %s%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:1701 src/http.c:1801
 msgid "unspecified"
 msgstr "neud�no"
 
-#: src/http.c:1138
+#: src/http.c:1702
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
+#: src/http.c:1751
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
+#: src/http.c:1781
 msgid "Length: "
 msgstr "D�lka: "
 
-# , c-format
-#: src/http.c:1264
-#, c-format
-msgid " (%s to go)"
-msgstr " (%s zb�v�)"
-
-#: src/http.c:1269
+#: src/http.c:1801
 msgid "ignored"
 msgstr "je ignorov�na"
 
-#: src/http.c:1399
+#: src/http.c:1943
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Varov�n�: HTTP nepodporuje �ol�kov� znaky.\n"
 
 # , c-format
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:1417
+#: src/http.c:1978
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Soubor `%s' je ji� zde a nebude se znovu p�en�et.\n"
 
 # , c-format
-#: src/http.c:1585
+#: src/http.c:2165
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Nelze zapsat do `%s' (%s).\n"
 
+#: src/http.c:2174
+msgid "Unable to establish SSL connection.\n"
+msgstr "Nebylo mo�n� nav�zat SSL spojen�.\n"
+
 # , c-format
-#: src/http.c:1602
+#: src/http.c:2184
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "CHYBA: P�esm�rov�n� (%d) bez udan� nov� adresy.\n"
 
 # , c-format
-#: src/http.c:1630
+#: src/http.c:2216
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s CHYBA %d: %s.\n"
 
-#: src/http.c:1642
+#: src/http.c:2229
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr ""
 "Nelze pou��t �asov� raz�tka (`time-stamps'), proto�e v odpov�di serveru \n"
 "sch�z� hlavi�ka \"Last-modified\".\n"
 
-#: src/http.c:1650
+#: src/http.c:2237
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr ""
 "�asov� raz�tko souboru (`time-stamp') bude ignorov�no, proto�e hlavi�ka \n"
 "\"Last-modified\" obsahuje neplatn� �daje.\n"
 
-#: src/http.c:1673
+#: src/http.c:2260
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
+#: src/http.c:2268
+#, fuzzy, c-format
+msgid "The sizes do not match (local %s) -- retrieving.\n"
 msgstr "Velikosti se neshoduj� (lok�ln� %ld), soubor je t�eba st�hnout.\n"
 
-#: src/http.c:1684
+#: src/http.c:2273
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Lok�ln� soubor je star�� a vzd�len� soubor se proto bude p�en�et.\n"
 
 # , c-format
-#: src/http.c:1728
-#, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
-msgstr "%s (%s) - `%s' ulo�eno [%ld/%ld]\n\n"
+#: src/http.c:2315
+#, fuzzy, c-format
+msgid ""
+"%s (%s) - `%s' saved [%s/%s]\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' ulo�eno [%ld/%ld]\n"
+"\n"
 
 # , c-format
-#: src/http.c:1774
-#, c-format
-msgid "%s (%s) - Connection closed at byte %ld. "
+#: src/http.c:2372
+#, fuzzy, c-format
+msgid "%s (%s) - Connection closed at byte %s. "
 msgstr "%s (%s) - Spojen� ukon�eno na bajtu %ld. "
 
 # , c-format
-#: src/http.c:1782
-#, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
-msgstr "%s (%s) - `%s' ulo�eno [%ld/%ld])\n\n"
+#: src/http.c:2381
+#, fuzzy, c-format
+msgid ""
+"%s (%s) - `%s' saved [%s/%s])\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' ulo�eno [%ld/%ld])\n"
+"\n"
 
 # , c-format
-#: src/http.c:1801
-#, c-format
-msgid "%s (%s) - Connection closed at byte %ld/%ld. "
+#: src/http.c:2407
+#, fuzzy, c-format
+msgid "%s (%s) - Connection closed at byte %s/%s. "
 msgstr "%s (%s) - Spojen� ukon�eno na bajtu %ld/%ld. "
 
 # , c-format
-#: src/http.c:1812
-#, c-format
-msgid "%s (%s) - Read error at byte %ld (%s)."
+#: src/http.c:2421
+#, fuzzy, c-format
+msgid "%s (%s) - Read error at byte %s (%s)."
 msgstr "%s (%s) - Chyba p�i �ten� dat na bajtu %ld (%s)."
 
 # , c-format
-#: src/http.c:1820
-#, c-format
-msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
+#: src/http.c:2431
+#, fuzzy, c-format
+msgid "%s (%s) - Read error at byte %s/%s (%s). "
 msgstr "%s (%s) - Chyba p�i �ten� dat na bajtu %ld/%ld (%s). "
 
+#: src/init.c:342
+#, c-format
+msgid "%s: WGETRC points to %s, which doesn't exist.\n"
+msgstr ""
+
 # , c-format
-#: src/init.c:349 src/netrc.c:267
+#: src/init.c:395 src/netrc.c:277
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: Nelze p�e��st %s (%s).\n"
 
 # , c-format
-#: src/init.c:367 src/init.c:373
+#: src/init.c:413 src/init.c:419
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: Chyba v %s na ��dku %d.\n"
 
 # , c-format
-#: src/init.c:405
+#: src/init.c:451
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
-msgstr "%s: Varov�n�: Glob�ln� i u�ivatelsk� wgetrc jsou shodn� ulo�eny v `%s'.\n"
+msgstr ""
+"%s: Varov�n�: Glob�ln� i u�ivatelsk� wgetrc jsou shodn� ulo�eny v `%s'.\n"
 
 # , c-format
-#: src/init.c:497
-#, c-format
-msgid "%s: BUG: unknown command `%s', value `%s'.\n"
-msgstr "%s: CHYBA: Nezn�m� p��kaz `%s', hodnota `%s'.\n"
-
-#: src/init.c:529
-#, c-format
-msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
-msgstr "%s: %s: `%s' nelze p�ev�st na IP adresu.\n"
+#: src/init.c:595
+#, fuzzy, c-format
+msgid "%s: Invalid --execute command `%s'\n"
+msgstr "%s: Neplatn� specifikace `%s'\n"
 
 # , c-format
-#: src/init.c:559
-#, c-format
-msgid "%s: %s: Please specify on or off.\n"
+#: src/init.c:631
+#, fuzzy, c-format
+msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
 msgstr "%s: %s: Zadejte pros�m `on' (zapnuto) nebo `off' (vypnuto).\n"
 
 # , c-format
-#: src/init.c:603
-#, c-format
-msgid "%s: %s: Please specify always, on, off, or never.\n"
-msgstr "%s: %s: Zadejte pros�m `always' (v�dy), `on' (zapnuto), `off' (vypnuto), nebo `never' (nikdy).\n"
+#: src/init.c:674
+#, fuzzy, c-format
+msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
+msgstr ""
+"%s: %s: Zadejte pros�m `always' (v�dy), `on' (zapnuto), `off' (vypnuto), "
+"nebo `never' (nikdy).\n"
 
 # , c-format
-#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
-#, c-format
-msgid "%s: %s: Invalid specification `%s'.\n"
+#: src/init.c:693
+#, fuzzy, c-format
+msgid "%s: %s: Invalid number `%s'.\n"
 msgstr "%s: %s: Neplatn� specifikace `%s'\n"
 
 # , c-format
-#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
-#, c-format
-msgid "%s: Invalid specification `%s'\n"
-msgstr "%s: Neplatn� specifikace `%s'\n"
+#: src/init.c:926 src/init.c:945
+#, fuzzy, c-format
+msgid "%s: %s: Invalid byte value `%s'\n"
+msgstr "%s: %s: Neplatn� specifikace `%s'\n"
 
 # , c-format
-#: src/main.c:120
-#, c-format
-msgid "Usage: %s [OPTION]... [URL]...\n"
-msgstr "Pou�it�: %s [P�EP�NA�]... [URL]...\n"
+#: src/init.c:970
+#, fuzzy, c-format
+msgid "%s: %s: Invalid time period `%s'\n"
+msgstr "%s: %s: Neplatn� specifikace `%s'\n"
 
 # , c-format
-#: src/main.c:128
-#, c-format
-msgid "GNU Wget %s, a non-interactive network retriever.\n"
-msgstr "GNU Wget %s, program pro neinteraktivn� stahov�n� soubor�.\n"
+#: src/init.c:1037
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
+#: src/init.c:1083
+#, fuzzy, c-format
+msgid "%s: %s: Invalid progress type `%s'.\n"
+msgstr "%s: %s: Neplatn� specifikace `%s'\n"
+
+# , c-format
+#: src/init.c:1134
+#, fuzzy, c-format
+msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
+msgstr "%s: %s: Neplatn� specifikace `%s'\n"
+
+# , c-format
+#: src/init.c:1175
+#, fuzzy, c-format
+msgid "%s: %s: Invalid value `%s'.\n"
+msgstr "%s: %s: Neplatn� specifikace `%s'\n"
 
-#: src/main.c:137
+#: src/log.c:777
+#, fuzzy, c-format
 msgid ""
-"Startup:\n"
-"  -V,  --version           display the version of Wget and exit.\n"
-"  -h,  --help              print this help.\n"
-"  -b,  --background        go to background after startup.\n"
-"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
-"\n"
-msgstr ""
-"Za��tek:\n"
-"  -V,  --version           vyp�e informaci o verzi programu Wget a skon��\n"
-"  -h,  --help              vyp�e tuto n�pov�du\n"
-"  -b,  --background        po spu�t�n� pokra�uje program v b�hu na pozad�\n"
-"  -e,  --execute=P��KAZ    prove�e p��kaz zadan� ve stylu `.wgetrc'\n"
 "\n"
+"%s received, redirecting output to `%s'.\n"
+msgstr "Byl zachycen sign�l %s, v�stup p�esm�rov�n do `%%s'.\n"
 
-# , fuzzy
-#: src/main.c:144
+#. Eek!  Opening the alternate log file has failed.  Nothing we
+#. can do but disable printing completely.
+#: src/log.c:787
+#, fuzzy, c-format
 msgid ""
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
 "\n"
+"%s received.\n"
+msgstr "Nep�i�la ��dn� data"
+
+#: src/log.c:788
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
+# , c-format
+#: src/main.c:363
+#, c-format
+msgid "Usage: %s [OPTION]... [URL]...\n"
+msgstr "Pou�it�: %s [P�EP�NA�]... [URL]...\n"
+
+#: src/main.c:375
+#, fuzzy
 msgid ""
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
+"\n"
+"Argumenty, povinn� u dlouh�ch p�ep�na��, jsou povinn� i pro kr�tk� verze\n"
+"p�ep�na��.\n"
 "\n"
 
-# , fuzzy
-#: src/main.c:175
+#: src/main.c:377
+msgid "Startup:\n"
+msgstr ""
+
+#: src/main.c:379
+msgid "  -V,  --version           display the version of Wget and exit.\n"
+msgstr ""
+
+#: src/main.c:381
+msgid "  -h,  --help              print this help.\n"
+msgstr ""
+
+#: src/main.c:383
+msgid "  -b,  --background        go to background after startup.\n"
+msgstr ""
+
+#: src/main.c:385
+msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
+msgstr ""
+
+#: src/main.c:389
+msgid "Logging and input file:\n"
+msgstr ""
+
+#: src/main.c:391
+msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
+msgstr ""
+
+#: src/main.c:393
+msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
+msgstr ""
+
+#: src/main.c:396
+msgid "  -d,  --debug               print lots of debugging information.\n"
+msgstr ""
+
+#: src/main.c:399
+msgid "  -q,  --quiet               quiet (no output).\n"
+msgstr ""
+
+#: src/main.c:401
+msgid "  -v,  --verbose             be verbose (this is the default).\n"
+msgstr ""
+
+#: src/main.c:403
 msgid ""
-"Directories:\n"
-"  -nd  --no-directories            don't create directories.\n"
-"  -x,  --force-directories         force creation of directories.\n"
-"  -nH, --no-host-directories       don't create host directories.\n"
-"  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
-"       --cut-dirs=NUMBER           ignore NUMBER remote directory components.\n"
-"\n"
+"  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
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
+#: src/main.c:405
+msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
+msgstr ""
+
+#: src/main.c:407
+msgid "  -F,  --force-html          treat input file as HTML.\n"
+msgstr ""
+
+#: src/main.c:409
 msgid ""
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
+"  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
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
+#: src/main.c:413
+msgid "Download:\n"
+msgstr ""
+
+#: src/main.c:415
 msgid ""
-"FTP options:\n"
-"  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
-"  -g,  --glob=on/off           turn file name globbing on or off.\n"
-"       --passive-ftp           use the \"passive\" transfer mode.\n"
-"       --retr-symlinks         when recursing, get linked-to files (not dirs).\n"
-"\n"
+"  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
+"unlimits).\n"
+msgstr ""
+
+#: src/main.c:417
+msgid "       --retry-connrefused       retry even if connection is refused.\n"
+msgstr ""
+
+#: src/main.c:419
+msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
+msgstr ""
+
+#: src/main.c:421
+msgid ""
+"  -nc, --no-clobber              skip downloads that would download to\n"
+"                                 existing files.\n"
+msgstr ""
+
+#: src/main.c:424
+msgid ""
+"  -c,  --continue                resume getting a partially-downloaded "
+"file.\n"
+msgstr ""
+
+#: src/main.c:426
+msgid "       --progress=TYPE           select progress gauge type.\n"
+msgstr ""
+
+#: src/main.c:428
+msgid ""
+"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
+"                                 local.\n"
+msgstr ""
+
+#: src/main.c:431
+msgid "  -S,  --server-response         print server response.\n"
+msgstr ""
+
+#: src/main.c:433
+msgid "       --spider                  don't download anything.\n"
+msgstr ""
+
+#: src/main.c:435
+msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
+msgstr ""
+
+#: src/main.c:437
+msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:439
+msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:441
+msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:443
+msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
+msgstr ""
+
+#: src/main.c:445
+msgid ""
+"       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
+"retrieval.\n"
+msgstr ""
+
+#: src/main.c:447
+msgid ""
+"       --random-wait             wait from 0...2*WAIT secs between "
+"retrievals.\n"
+msgstr ""
+
+#: src/main.c:449
+msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
+msgstr ""
+
+#: src/main.c:451
+msgid "       --no-proxy                explicitly turn off proxy.\n"
+msgstr ""
+
+#: src/main.c:453
+msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
+msgstr ""
+
+#: src/main.c:455
+msgid ""
+"       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
+"host.\n"
+msgstr ""
+
+#: src/main.c:457
+msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
+msgstr ""
+
+#: src/main.c:459
+msgid "       --no-dns-cache            disable caching DNS lookups.\n"
+msgstr ""
+
+#: src/main.c:461
+msgid ""
+"       --restrict-file-names=OS  restrict chars in file names to ones OS "
+"allows.\n"
+msgstr ""
+
+#: src/main.c:464
+msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
+msgstr ""
+
+#: src/main.c:466
+msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
+msgstr ""
+
+#: src/main.c:471
+#, fuzzy
+msgid "Directories:\n"
+msgstr "Adres��     "
+
+#: src/main.c:473
+msgid "  -nd, --no-directories           don't create directories.\n"
+msgstr ""
+
+#: src/main.c:475
+msgid "  -x,  --force-directories        force creation of directories.\n"
+msgstr ""
+
+#: src/main.c:477
+msgid "  -nH, --no-host-directories      don't create host directories.\n"
+msgstr ""
+
+#: src/main.c:479
+msgid "       --protocol-directories     use protocol name in directories.\n"
+msgstr ""
+
+#: src/main.c:481
+msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
+msgstr ""
+
+#: src/main.c:483
+msgid ""
+"       --cut-dirs=NUMBER          ignore NUMBER remote directory "
+"components.\n"
+msgstr ""
+
+#: src/main.c:487
+msgid "HTTP options:\n"
+msgstr ""
+
+#: src/main.c:489
+msgid "       --http-user=USER        set http user to USER.\n"
+msgstr ""
+
+#: src/main.c:491
+msgid "       --http-passwd=PASS      set http password to PASS.\n"
+msgstr ""
+
+#: src/main.c:493
+msgid "       --no-cache              disallow server-cached data.\n"
+msgstr ""
+
+#: src/main.c:495
+msgid ""
+"  -E,  --html-extension        save HTML documents with `.html' extension.\n"
+msgstr ""
+
+#: src/main.c:497
+msgid "       --ignore-length         ignore `Content-Length' header field.\n"
+msgstr ""
+
+#: src/main.c:499
+msgid "       --header=STRING         insert STRING among the headers.\n"
+msgstr ""
+
+#: src/main.c:501
+msgid "       --proxy-user=USER       set USER as proxy username.\n"
+msgstr ""
+
+#: src/main.c:503
+msgid "       --proxy-passwd=PASS     set PASS as proxy password.\n"
+msgstr ""
+
+#: src/main.c:505
+msgid ""
+"       --referer=URL           include `Referer: URL' header in HTTP "
+"request.\n"
+msgstr ""
+
+#: src/main.c:507
+msgid "       --save-headers          save the HTTP headers to file.\n"
+msgstr ""
+
+#: src/main.c:509
+msgid ""
+"  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
+msgstr ""
+
+#: src/main.c:511
+msgid ""
+"       --no-http-keep-alive    disable HTTP keep-alive (persistent "
+"connections).\n"
+msgstr ""
+
+#: src/main.c:513
+msgid "       --no-cookies            don't use cookies.\n"
+msgstr ""
+
+#: src/main.c:515
+msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
+msgstr ""
+
+#: src/main.c:517
+msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
+msgstr ""
+
+#: src/main.c:519
+msgid ""
+"       --keep-session-cookies  load and save session (non-permanent) "
+"cookies.\n"
+msgstr ""
+
+#: src/main.c:521
+msgid ""
+"       --post-data=STRING      use the POST method; send STRING as the "
+"data.\n"
+msgstr ""
+
+#: src/main.c:523
+msgid ""
+"       --post-file=FILE        use the POST method; send contents of FILE.\n"
+msgstr ""
+
+#: src/main.c:528
+msgid "HTTPS (SSL) options:\n"
+msgstr ""
+
+#: src/main.c:530
+msgid "       --sslcertfile=FILE    optional client certificate.\n"
+msgstr ""
+
+#: src/main.c:532
+msgid "       --sslcertkey=KEYFILE  optional keyfile for this certificate.\n"
+msgstr ""
+
+#: src/main.c:534
+msgid "       --sslcadir=DIR        dir where hash list of CA's are stored.\n"
+msgstr ""
+
+#: src/main.c:536
+msgid "       --sslcafile=FILE      file with bundle of CA's.\n"
+msgstr ""
+
+#: src/main.c:538
+msgid ""
+"       --sslcerttype=0/1     Client-Cert type 0=PEM (default) / 1=ASN1 "
+"(DER).\n"
+msgstr ""
+
+#: src/main.c:540
+msgid "       --sslcheckcert=0/1    Check the server cert against given CA.\n"
+msgstr ""
+
+#: src/main.c:542
+msgid ""
+"       --sslprotocol=0-3     choose SSL protocol; 0=automatic,\n"
+"                             1=SSLv2 2=SSLv3 3=TLSv1.\n"
+msgstr ""
+
+#: src/main.c:545
+msgid "       --egd-file=FILE       file name of the EGD socket.\n"
+msgstr ""
+
+#: src/main.c:550
+msgid "FTP options:\n"
+msgstr ""
+
+#: src/main.c:552
+msgid "       --no-remove-listing     don't remove `.listing' files.\n"
+msgstr ""
+
+#: src/main.c:554
+msgid "       --no-glob               turn off FTP file name globbing.\n"
+msgstr ""
+
+#: src/main.c:556
+msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
+msgstr ""
+
+#: src/main.c:558
+msgid ""
+"       --retr-symlinks         when recursing, get linked-to files (not "
+"dir).\n"
+msgstr ""
+
+#: src/main.c:560
+msgid "       --preserve-permissions  preserve remote file permissions.\n"
+msgstr ""
+
+#: src/main.c:564
+msgid "Recursive download:\n"
+msgstr ""
+
+#: src/main.c:566
+msgid "  -r,  --recursive          specify recursive download.\n"
+msgstr ""
+
+#: src/main.c:568
+msgid ""
+"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
+"infinite).\n"
 msgstr ""
-"P�ep�na�e pro FTP protokol:\n"
-"  -nr, --dont-remove-listing  nema�e soubory `.listing' s obsahy adres���\n"
-"  -g,  --glob=on/off          zapne �i vypne expanzi �ol�k� ve jm�nech soubor�\n"
-"       --passive-ftp          pou�ije pasivn� m�d p�enosu dat\n"
-"       --retr-symlinks        v rekurzivn�m m�du stahuje i symbolick� odkazy na\n"
-"                              soubory (nikoliv na adres��e)\n"
 
-#: src/main.c:208
+#: src/main.c:570
 msgid ""
-"Recursive retrieval:\n"
-"  -r,  --recursive          recursive web-suck -- use with care!\n"
-"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for infinite).\n"
 "       --delete-after       delete files locally after downloading them.\n"
-"  -k,  --convert-links      convert non-relative links to relative.\n"
+msgstr ""
+
+#: src/main.c:572
+msgid ""
+"  -k,  --convert-links      make links in downloaded HTML point to local "
+"files.\n"
+msgstr ""
+
+#: src/main.c:574
+msgid ""
 "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
+msgstr ""
+
+#: src/main.c:576
+msgid ""
 "  -m,  --mirror             shortcut option equivalent to -r -N -l inf -nr.\n"
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
+#: src/main.c:578
 msgid ""
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
+"  -p,  --page-requisites    get all images, etc. needed to display HTML "
+"page.\n"
+msgstr ""
+
+#: src/main.c:580
+msgid ""
+"       --strict-comments    turn on strict (SGML) handling of HTML "
+"comments.\n"
+msgstr ""
+
+#: src/main.c:584
+msgid "Recursive accept/reject:\n"
+msgstr ""
+
+#: src/main.c:586
+msgid ""
+"  -A,  --accept=LIST               comma-separated list of accepted "
+"extensions.\n"
+msgstr ""
+
+#: src/main.c:588
+msgid ""
+"  -R,  --reject=LIST               comma-separated list of rejected "
+"extensions.\n"
+msgstr ""
+
+#: src/main.c:590
+msgid ""
+"  -D,  --domains=LIST              comma-separated list of accepted "
+"domains.\n"
+msgstr ""
+
+#: src/main.c:592
+msgid ""
+"       --exclude-domains=LIST      comma-separated list of rejected "
+"domains.\n"
+msgstr ""
+
+#: src/main.c:594
+msgid ""
+"       --follow-ftp                follow FTP links from HTML documents.\n"
+msgstr ""
+
+#: src/main.c:596
+msgid ""
+"       --follow-tags=LIST          comma-separated list of followed HTML "
+"tags.\n"
+msgstr ""
+
+#: src/main.c:598
+msgid ""
+"       --ignore-tags=LIST          comma-separated list of ignored HTML "
+"tags.\n"
+msgstr ""
+
+#: src/main.c:600
+msgid ""
+"  -H,  --span-hosts                go to foreign hosts when recursive.\n"
+msgstr ""
+
+#: src/main.c:602
+msgid "  -L,  --relative                  follow relative links only.\n"
+msgstr ""
+
+#: src/main.c:604
+msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
+msgstr ""
+
+#: src/main.c:606
+msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
+msgstr ""
+
+#: src/main.c:608
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
+#: src/main.c:612
 msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
 msgstr ""
 "Zpr�vy o chyb�ch a n�vrhy na vylep�en� programu zas�lejte na adresu\n"
 "<bug-wget@gnu.org> (pouze anglicky).\n"
 "Koment��e k �esk�mu p�ekladu zas�lejte na adresu <cs@li.org>. \n"
 
-# , fuzzy
-#: src/main.c:420
+# , c-format
+#: src/main.c:617
 #, c-format
-msgid "%s: debug support not compiled in.\n"
-msgstr "%s: program nebyl zkompilov�n s podporou pro lad�n�.\n"
+msgid "GNU Wget %s, a non-interactive network retriever.\n"
+msgstr "GNU Wget %s, program pro neinteraktivn� stahov�n� soubor�.\n"
 
-#: src/main.c:472
+#: src/main.c:631
+msgid "Copyright (C) 2005 Free Software Foundation, Inc.\n"
+msgstr ""
+
+#: src/main.c:633
+#, fuzzy
 msgid ""
-"Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
 "This program is distributed in the hope that it will be useful,\n"
 "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
 "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
 "GNU General Public License for more details.\n"
 msgstr ""
-"Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
+"Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, "
+"Inc.\n"
 "Tento program je ���en v nad�ji, �e bude u�ite�n�, av�ak\n"
 "BEZ JAK�KOLI Z�RUKY; neposkytuj� se ani odvozen� z�ruky PRODEJNOSTI \n"
 "anebo VHODNOSTI PRO UR�IT� ��EL. Dal�� podrobnosti hledejte \n"
 "v Obecn� ve�ejn� licenci GNU.\n"
 
-#: src/main.c:478
-msgid "\nOriginally written by Hrvoje Niksic <hniksic@arsdigita.com>.\n"
-msgstr "\nP�vodn�m autorem tohto programu je Hrvoje Nik�i� <hniksic@arsdigita.com>.\n"
+#: src/main.c:638
+#, fuzzy
+msgid ""
+"\n"
+"Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
+msgstr ""
+"\n"
+"P�vodn�m autorem tohto programu je Hrvoje Nik�i� <hniksic@arsdigita.com>.\n"
 
 # , c-format
-#: src/main.c:569
+#. #### Something nicer should be printed here -- similar to the
+#. pre-1.5 `--help' page.
+#: src/main.c:684 src/main.c:753 src/main.c:832
 #, c-format
-msgid "%s: %s: invalid command\n"
-msgstr "%s: %s: neplatn� p��kaz\n"
+msgid "Try `%s --help' for more options.\n"
+msgstr "P��kaz `%s --help' vyp�e v�znam platn�ch p�ep�na��.\n"
 
 # , c-format
-#: src/main.c:625
+#: src/main.c:750
 #, c-format
 msgid "%s: illegal option -- `-n%c'\n"
 msgstr "%s: nep��pustn� p�ep�na� -- `-n%c'\n"
 
-# , c-format
-#. #### Something nicer should be printed here -- similar to the
-#. pre-1.5 `--help' page.
-#: src/main.c:628 src/main.c:670 src/main.c:728
+#: src/main.c:803
 #, c-format
-msgid "Try `%s --help' for more options.\n"
-msgstr "P��kaz `%s --help' vyp�e v�znam platn�ch p�ep�na��.\n"
-
-#: src/main.c:708
 msgid "Can't be verbose and quiet at the same time.\n"
 msgstr "Program nem��e b�t upov�dan� a zitcha najednou.\n"
 
-#: src/main.c:714
+#: src/main.c:809
+#, c-format
 msgid "Can't timestamp and not clobber old files at the same time.\n"
 msgstr "Nelze pou��vat �asov� raz�tka a nemazat p�itom star� soubory.\n"
 
+#: src/main.c:817
+#, c-format
+msgid "Cannot specify both --inet4-only and --inet6-only.\n"
+msgstr ""
+
 #. No URL specified.
-#: src/main.c:723
+#: src/main.c:827
 #, c-format
 msgid "%s: missing URL\n"
 msgstr "%s: chyb� URL\n"
 
 # , c-format
-#: src/main.c:825
+#: src/main.c:936
 #, c-format
 msgid "No URLs found in %s.\n"
 msgstr "V souboru `%s' nebyla nalezena ��dn� URL.\n"
 
 # , c-format
-#: src/main.c:834
+#: src/main.c:945
 #, c-format
 msgid ""
 "\n"
