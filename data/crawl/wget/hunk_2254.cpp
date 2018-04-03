 # Czech translations for GNU wget
 # Copyright (C) 1998, 2000, 2001 Free Software Foundation, Inc.
 # Jan Prikryl <prikryl@acm.org>, 1998, 2000, 2001
+# Petr Pisar <petr.pisar@atlas.cz>, 2007
 #
 msgid ""
 msgstr ""
-"Project-Id-Version: GNU wget 1.7\n"
-"Report-Msgid-Bugs-To: \n"
-"POT-Creation-Date: 2007-08-26 16:14-0700\n"
-"PO-Revision-Date: 2001-06-05 23:19+0200\n"
-"Last-Translator: Jan Prikryl <prikryl@acm.org>\n"
-"Language-Team: Czech <cs@li.org>\n"
+"Project-Id-Version: wget 1.11-b2363\n"
+"Report-Msgid-Bugs-To: wget@sunsite.dk\n"
+"POT-Creation-Date: 2007-10-22 11:58-0700\n"
+"PO-Revision-Date: 2007-09-04 14:06+0200\n"
+"Last-Translator: Petr Pisar <petr.pisar@atlas.cz>\n"
+"Language-Team: Czech <translation-team-cs@lists.sourceforge.net>\n"
 "MIME-Version: 1.0\n"
-"Content-Type: text/plain; charset=iso-8859-2\n"
+"Content-Type: text/plain; charset=UTF-8\n"
 "Content-Transfer-Encoding: 8-bit\n"
+"Plural-Forms: nplurals=3; plural=(n%10==1 && n%100!=11 ? 0 : n%10>=2 && n%"
+"10<=4 && (n%100<10 || n%100>=20) ? 1 : 2);\n"
 
-#: src/connect.c:195
+#: lib/getopt.c:530 lib/getopt.c:546
+#, c-format
+msgid "%s: option `%s' is ambiguous\n"
+msgstr "%s: přepínač „%s“ není jednoznačný\n"
+
+#: lib/getopt.c:579 lib/getopt.c:583
+#, c-format
+msgid "%s: option `--%s' doesn't allow an argument\n"
+msgstr "%s: přepínač „--%s“ nemá argument\n"
+
+#: lib/getopt.c:592 lib/getopt.c:597
+#, c-format
+msgid "%s: option `%c%s' doesn't allow an argument\n"
+msgstr "%s: přepínač „%c%s“ nemá argument\n"
+
+#: lib/getopt.c:640 lib/getopt.c:659 lib/getopt.c:975 lib/getopt.c:994
+#, c-format
+msgid "%s: option `%s' requires an argument\n"
+msgstr "%s: přepínač „%s“ vyžaduje argument\n"
+
+#: lib/getopt.c:697 lib/getopt.c:700
+#, c-format
+msgid "%s: unrecognized option `--%s'\n"
+msgstr "%s: neznámý přepínač „--%s“\n"
+
+#: lib/getopt.c:708 lib/getopt.c:711
+#, c-format
+msgid "%s: unrecognized option `%c%s'\n"
+msgstr "%s: neznámý přepínač „%c%s“\n"
+
+#: lib/getopt.c:763 lib/getopt.c:766
+#, c-format
+msgid "%s: illegal option -- %c\n"
+msgstr "%s: nepřípustný přepínač – %c\n"
+
+#: lib/getopt.c:772 lib/getopt.c:775
+#, c-format
+msgid "%s: invalid option -- %c\n"
+msgstr "%s: chybný přepínač – %c\n"
+
+#: lib/getopt.c:827 lib/getopt.c:843 lib/getopt.c:1047 lib/getopt.c:1065
+#, c-format
+msgid "%s: option requires an argument -- %c\n"
+msgstr "%s: přepínač vyžaduje argument – %c\n"
+
+#: lib/getopt.c:896 lib/getopt.c:912
+#, c-format
+msgid "%s: option `-W %s' is ambiguous\n"
+msgstr "%s: přepínač „-W %s“ není jednoznačný\n"
+
+#: lib/getopt.c:936 lib/getopt.c:954
+#, c-format
+msgid "%s: option `-W %s' doesn't allow an argument\n"
+msgstr "%s: přepínač „-W %s“ nemá argument\n"
+
+#: src/connect.c:194
 #, c-format
 msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
 msgstr ""
+"%s: adresu „%s“ pro přilepení nelze zjistit, vypínám přilepování (bind(2)).\n"
 
-# , c-format
-#: src/connect.c:267
-#, fuzzy, c-format
+#: src/connect.c:266
+#, c-format
 msgid "Connecting to %s|%s|:%d... "
-msgstr "Navazuje se spojen� s %s:%hu... "
+msgstr "Navazuje se spojení s %s|%s|:%d… "
 
-# , c-format
-#: src/connect.c:270
-#, fuzzy, c-format
+#: src/connect.c:269
+#, c-format
 msgid "Connecting to %s:%d... "
-msgstr "Navazuje se spojen� s %s:%hu... "
+msgstr "Navazuje se spojení s %s:%d… "
 
-#: src/connect.c:330
-#, fuzzy
+#: src/connect.c:329
 msgid "connected.\n"
-msgstr "spojeno!\n"
+msgstr "spojeno.\n"
 
-#: src/connect.c:342 src/host.c:752 src/host.c:781
+#: src/connect.c:341 src/host.c:752 src/host.c:781
 #, c-format
 msgid "failed: %s.\n"
+msgstr "nezdařilo se: %s.\n"
+
+#: src/connect.c:365 src/http.c:1628
+#, fuzzy, c-format
+msgid "%s: unable to resolve host address `%s'\n"
 msgstr ""
+"%s: adresu „%s“ pro přilepení nelze zjistit, vypínám přilepování (bind(2)).\n"
 
-#: src/convert.c:171
+#: src/convert.c:169
 #, c-format
 msgid "Converted %d files in %s seconds.\n"
-msgstr ""
+msgstr "%d souborů převedeno za %s sekund.\n"
 
-# , c-format
-#: src/convert.c:196
+#: src/convert.c:194
 #, c-format
 msgid "Converting %s... "
-msgstr "P�ev�d� se %s... "
+msgstr "Převádí se %s… "
 
-#: src/convert.c:209
+#: src/convert.c:207
 msgid "nothing to do.\n"
-msgstr "nic nen� pot�eba p�ev�d�t.\n"
+msgstr "nic není potřeba převádět.\n"
 
-# , c-format
-#: src/convert.c:217 src/convert.c:241
+#: src/convert.c:215 src/convert.c:239
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
-msgstr "Nelze p�ev�st odkazy v %s: %s\n"
+msgstr "Nelze převést odkazy v %s: %s\n"
 
-# , c-format
-#: src/convert.c:232
+#: src/convert.c:230
 #, c-format
 msgid "Unable to delete `%s': %s\n"
-msgstr "Nebylo mo�n� odstranit `%s': %s\n"
+msgstr "Nebylo možné odstranit „%s“: %s\n"
 
-# , c-format
-#: src/convert.c:441
+#: src/convert.c:439
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
-msgstr "Nelze z�lohovat %s jako %s: %s\n"
+msgstr "Nelze zálohovat %s jako %s: %s\n"
 
-#: src/cookies.c:443
-#, fuzzy, c-format
+#: src/cookies.c:442
+#, c-format
 msgid "Syntax error in Set-Cookie: %s at position %d.\n"
-msgstr "Syntaktick� chyba v hlavi�ce Set-Cookie: P�ed�asn� konec �et�zce.\n"
+msgstr "Syntaktická chyba v hlavičce Set-Cookie: %s na pozici %d.\n"
 
-#: src/cookies.c:685
+#: src/cookies.c:684
 #, c-format
 msgid "Cookie coming from %s attempted to set domain to %s\n"
-msgstr ""
+msgstr "Cookie přiševši z %s se pokusila nastavit doménu na %s\n"
 
-# , c-format
-#: src/cookies.c:1132 src/cookies.c:1250
+#: src/cookies.c:1131 src/cookies.c:1249
 #, c-format
 msgid "Cannot open cookies file `%s': %s\n"
-msgstr "Nelze otev��t soubor s kol��ky `%s': %s\n"
+msgstr "Nelze otevřít soubor s cookie „%s“: %s\n"
 
-# , c-format
-#: src/cookies.c:1287
+#: src/cookies.c:1286
 #, c-format
 msgid "Error writing to `%s': %s\n"
-msgstr "P�i z�pisu do `%s' nastala chyba: %s.\n"
+msgstr "Při zápisu do „%s“ nastala chyba: %s.\n"
 
-#: src/cookies.c:1290
+#: src/cookies.c:1289
 #, c-format
 msgid "Error closing `%s': %s\n"
-msgstr "P�i uzav�r�n� `%s' nastala chyba: %s\n"
+msgstr "Při uzavírání „%s“ nastala chyba: %s\n"
 
-#: src/ftp-ls.c:836
+#: src/ftp-ls.c:835
 msgid "Unsupported listing type, trying Unix listing parser.\n"
-msgstr "Nepodporovan� typ v�pisu, pou�ije se Unixov� parser.\n"
+msgstr "Nepodporovaný typ výpisu, použije se Unixový parser.\n"
 
-# , c-format
-#: src/ftp-ls.c:882 src/ftp-ls.c:884
+#: src/ftp-ls.c:881 src/ftp-ls.c:883
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Obsah /%s na %s:%d"
 
-#: src/ftp-ls.c:907
+#: src/ftp-ls.c:906
 #, c-format
 msgid "time unknown       "
-msgstr "�as nezn�m�        "
+msgstr "čas neznámý        "
 
-#: src/ftp-ls.c:911
+#: src/ftp-ls.c:910
 #, c-format
 msgid "File        "
 msgstr "Soubor      "
 
-#: src/ftp-ls.c:914
+#: src/ftp-ls.c:913
 #, c-format
 msgid "Directory   "
-msgstr "Adres��     "
+msgstr "Adresář     "
 
-#: src/ftp-ls.c:917
+#: src/ftp-ls.c:916
 #, c-format
 msgid "Link        "
 msgstr "Sym. odkaz  "
 
-#: src/ftp-ls.c:920
+#: src/ftp-ls.c:919
 #, c-format
 msgid "Not sure    "
-msgstr "Nezn�m� typ "
+msgstr "Neznámý typ "
 
-# , c-format
-#: src/ftp-ls.c:938
+#: src/ftp-ls.c:937
 #, c-format
 msgid " (%s bytes)"
-msgstr " (%s bajt�)"
+msgstr " (%s bajtů)"
 
-# , c-format
-#: src/ftp.c:209
+#: src/ftp.c:213
 #, c-format
 msgid "Length: %s"
-msgstr "D�lka: %s"
+msgstr "Délka: %s"
 
-#: src/ftp.c:215 src/http.c:2174
+#: src/ftp.c:219 src/http.c:2173
 #, c-format
 msgid ", %s (%s) remaining"
-msgstr ""
+msgstr ", %s (%s) zbývá"
 
-#: src/ftp.c:219 src/http.c:2178
+#: src/ftp.c:223 src/http.c:2177
 #, c-format
 msgid ", %s remaining"
-msgstr ""
+msgstr ", %s zbývá"
 
-#: src/ftp.c:222
+#: src/ftp.c:226
 msgid " (unauthoritative)\n"
-msgstr " (nen� sm�rodatn�)\n"
+msgstr " (není směrodatné)\n"
 
-# , c-format
-#. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:298
+#: src/ftp.c:302
 #, c-format
 msgid "Logging in as %s ... "
-msgstr "Prob�h� p�ihla�ov�n� jako %s ... "
+msgstr "Probíhá přihlašování jako %s… "
 
-#: src/ftp.c:311 src/ftp.c:357 src/ftp.c:386 src/ftp.c:438 src/ftp.c:550
-#: src/ftp.c:596 src/ftp.c:625 src/ftp.c:682 src/ftp.c:743 src/ftp.c:803
-#: src/ftp.c:850
+#: src/ftp.c:315 src/ftp.c:361 src/ftp.c:390 src/ftp.c:442 src/ftp.c:554
+#: src/ftp.c:600 src/ftp.c:629 src/ftp.c:686 src/ftp.c:747 src/ftp.c:807
+#: src/ftp.c:854
 msgid "Error in server response, closing control connection.\n"
 msgstr ""
-"��dic� spojen� bude ukon�eno, proto�e server odpov�d�l chybov�m hl�en�m.\n"
+"Řídicí spojení bude ukončeno, protože server odpověděl chybovým hlášením.\n"
 
-#: src/ftp.c:318
+#: src/ftp.c:322
 msgid "Error in server greeting.\n"
-msgstr "�vodn� odpov�� serveru je chybn�.\n"
+msgstr "Úvodní odpověď serveru je chybná.\n"
 
-#: src/ftp.c:325 src/ftp.c:446 src/ftp.c:558 src/ftp.c:633 src/ftp.c:692
-#: src/ftp.c:753 src/ftp.c:813 src/ftp.c:860
+#: src/ftp.c:329 src/ftp.c:450 src/ftp.c:562 src/ftp.c:637 src/ftp.c:696
+#: src/ftp.c:757 src/ftp.c:817 src/ftp.c:864
 msgid "Write failed, closing control connection.\n"
-msgstr "R�dic� spojen� bude ukon�eno, proto�e nelze zapsat data.\n"
+msgstr "Rídicí spojení bude ukončeno, protože nelze zapsat data.\n"
 
-#: src/ftp.c:331
+#: src/ftp.c:335
 msgid "The server refuses login.\n"
-msgstr "Server odm�t� p�ihl�en�.\n"
+msgstr "Server odmítá přihlášení.\n"
 
-#: src/ftp.c:337
+#: src/ftp.c:341
 msgid "Login incorrect.\n"
-msgstr "Chyba p�i p�ihl�en�.\n"
+msgstr "Chyba při přihlášení.\n"
 
-#: src/ftp.c:343
+#: src/ftp.c:347
 msgid "Logged in!\n"
-msgstr "P�ihl�eno!\n"
+msgstr "Přihlášeno!\n"
 
-#: src/ftp.c:365
+#: src/ftp.c:369
 msgid "Server error, can't determine system type.\n"
 msgstr ""
-"Nelze zjistit typ vzd�len�ho opera�n�ho syst�mu, proto�e server odpov�d�l "
-"chybov�m hl�en�m.\n"
+"Nelze zjistit typ vzdáleného operačního systému, protože server odpověděl "
+"chybovým hlášením.\n"
 
-#: src/ftp.c:374 src/ftp.c:669 src/ftp.c:726 src/ftp.c:769
+#: src/ftp.c:378 src/ftp.c:673 src/ftp.c:730 src/ftp.c:773
 msgid "done.    "
 msgstr "hotovo.  "
 
-#: src/ftp.c:426 src/ftp.c:575 src/ftp.c:608 src/ftp.c:833 src/ftp.c:879
+#: src/ftp.c:430 src/ftp.c:579 src/ftp.c:612 src/ftp.c:837 src/ftp.c:883
 msgid "done.\n"
 msgstr "hotovo.\n"
 
-# , c-format
-#: src/ftp.c:453
+#: src/ftp.c:457
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr ""
-"R�dic� spojen� bude ukon�eno, proto�e je po�adov�n nezn�m� typ p�enosu `%"
-"c'.\n"
+"Rídicí spojení bude ukončeno, protože je požadován neznámý typ přenosu „%"
+"c“.\n"
 
-#: src/ftp.c:465
+#: src/ftp.c:469
 msgid "done.  "
 msgstr "hotovo."
 
-#: src/ftp.c:471
+#: src/ftp.c:475
 msgid "==> CWD not needed.\n"
-msgstr "==> CWD nen� pot�eba.\n"
+msgstr "==> CWD není potřeba.\n"
 
-# , c-format
-#: src/ftp.c:564
+#: src/ftp.c:568
 #, c-format
 msgid ""
 "No such directory `%s'.\n"
 "\n"
 msgstr ""
-"Adres�� `%s' neexistuje.\n"
+"Adresář „%s“ neexistuje.\n"
 "\n"
 
-#. do not CWD
-#: src/ftp.c:579
+#: src/ftp.c:583
 msgid "==> CWD not required.\n"
-msgstr "==> CWD nen� pot�eba.\n"
+msgstr "==> CWD není potřeba.\n"
 
-#: src/ftp.c:639
+#: src/ftp.c:643
 msgid "Cannot initiate PASV transfer.\n"
-msgstr "Nelze spustit pasivn� p�enos dat.\n"
+msgstr "Nelze spustit pasivní přenos dat.\n"
 
-#: src/ftp.c:643
+#: src/ftp.c:647
 msgid "Cannot parse PASV response.\n"
-msgstr "Odpov�� na PASV nen� pochopiteln�.\n"
+msgstr "Odpověď na PASV není pochopitelná.\n"
 
-#: src/ftp.c:660
+#: src/ftp.c:664
 #, c-format
 msgid "couldn't connect to %s port %d: %s\n"
-msgstr ""
+msgstr "s %s na portu %d se nelze spojit: %s\n"
 
-# , c-format
-#: src/ftp.c:708
+#: src/ftp.c:712
 #, c-format
 msgid "Bind error (%s).\n"
-msgstr "Chyba p�i operaci \"bind\" (%s).\n"
+msgstr "Chyba při přilepování (bind) (%s).\n"
 
-#: src/ftp.c:714
+#: src/ftp.c:718
 msgid "Invalid PORT.\n"
-msgstr "Neplatn� PORT.\n"
+msgstr "Neplatný PORT.\n"
 
-#: src/ftp.c:760
+#: src/ftp.c:764
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
 msgstr ""
 "\n"
-"P��kaz REST selhal, p�enos za�ne od za��tku souboru.\n"
+"Příkaz REST selhal, přenos začne od začátku souboru.\n"
 
-# , c-format
-#: src/ftp.c:821
+#: src/ftp.c:825
 #, c-format
 msgid ""
 "No such file `%s'.\n"
 "\n"
 msgstr ""
-"Soubor `%s' neexistuje.\n"
+"Soubor „%s“ neexistuje.\n"
 "\n"
 
-# , c-format
-#: src/ftp.c:868
+#: src/ftp.c:872
 #, c-format
 msgid ""
 "No such file or directory `%s'.\n"
 "\n"
 msgstr ""
-"Soubor �i adres�� `%s' neexistuje.\n"
+"Soubor či adresář „%s“ neexistuje.\n"
 "\n"
 
-#. We cannot just invent a new name and use it (which is
-#. what functions like unique_create typically do)
-#. because we told the user we'd use this name.
-#. Instead, return and retry the download.
-#: src/ftp.c:930 src/http.c:2236
+#: src/ftp.c:934 src/http.c:2235
 #, c-format
 msgid "%s has sprung into existence.\n"
-msgstr ""
+msgstr "%s se objevil.\n"
 
-# , c-format
-#: src/ftp.c:982
+#: src/ftp.c:986
 #, c-format
 msgid "%s: %s, closing control connection.\n"
-msgstr "%s: %s, ��dic� spojen� bude ukon�eno.\n"
+msgstr "%s: %s, řídicí spojení bude ukončeno.\n"
 
-# , c-format
-#: src/ftp.c:991
+#: src/ftp.c:995
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
-msgstr "%s (%s) - Datov� spojen�: %s; "
+msgstr "%s (%s) – Datové spojení: %s; "
 
-#: src/ftp.c:1006
+#: src/ftp.c:1010
 msgid "Control connection closed.\n"
-msgstr "��dic� spojen� bylo ukon�eno.\n"
+msgstr "Řídicí spojení bylo ukončeno.\n"
 
-#: src/ftp.c:1024
+#: src/ftp.c:1028
 msgid "Data transfer aborted.\n"
-msgstr "P�enos dat byl p�ed�asn� ukon�en.\n"
+msgstr "Přenos dat byl předčasně ukončen.\n"
 
-# , c-format
-#: src/ftp.c:1092
-#, fuzzy, c-format
+#: src/ftp.c:1096
+#, c-format
 msgid "File `%s' already there; not retrieving.\n"
-msgstr "Soubor `%s' je ji� zde a nen� jej t�eba p�en�et.\n"
+msgstr "Soubor „%s“ je již zde, nebudu jej přenášet.\n"
 
-# , c-format
-#: src/ftp.c:1160 src/http.c:2375
+#: src/ftp.c:1164 src/http.c:2393
 #, c-format
 msgid "(try:%2d)"
 msgstr "(pokus:%2d)"
 
-# , c-format
-#: src/ftp.c:1230 src/http.c:2683
-#, fuzzy, c-format
+#: src/ftp.c:1234 src/http.c:2716
+#, c-format
 msgid ""
 "%s (%s) - `%s' saved [%s]\n"
 "\n"
 msgstr ""
-"%s (%s) - `%s' ulo�en [%ld]\n"
+"%s (%s) – „%s“ uložen [%s]\n"
 "\n"
 
-# , c-format
-#: src/ftp.c:1272 src/main.c:990 src/recur.c:376 src/retr.c:859
+#: src/ftp.c:1276 src/main.c:1006 src/recur.c:377 src/retr.c:859
 #, c-format
 msgid "Removing %s.\n"
-msgstr "Ma�e se %s.\n"
+msgstr "Maže se %s.\n"
 
-# , c-format
-#: src/ftp.c:1314
+#: src/ftp.c:1318
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
-msgstr "Seznam soubor� bude do�asn� ulo�en v `%s'.\n"
+msgstr "Seznam souborů bude dočasně uložen v „%s“.\n"
 
-# , c-format
-#: src/ftp.c:1329
+#: src/ftp.c:1333
 #, c-format
 msgid "Removed `%s'.\n"
-msgstr "Soubor `%s' byl vymaz�n.\n"
+msgstr "Soubor „%s“ byl vymazán.\n"
 
-# , c-format
-#: src/ftp.c:1362
+#: src/ftp.c:1366
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
-msgstr "Hloubka rekurze %d p�ekro�ila maxim�ln� hloubku %d.\n"
+msgstr "Hloubka rekurze %d překročila maximální hloubku %d.\n"
 
-#. Remote file is older, file sizes can be compared and
-#. are both equal.
-#: src/ftp.c:1432
+#: src/ftp.c:1436
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
 msgstr ""
-"Vzd�len� soubor nen� nov�j��, ne� lok�ln� soubor `%s', a nen� jej t�eba "
+"Vzdálený soubor není novější, než lokální soubor „%s“, a není jej třeba "
 "stahovat.\n"
 
-#. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1439
+#: src/ftp.c:1443
 #, c-format
 msgid ""
 "Remote file is newer than local file `%s' -- retrieving.\n"
 "\n"
 msgstr ""
-"Vzd�len� soubor je nov�j��, ne� lok�ln� soubor `%s', a je jej t�eba "
-"st�hnout.\n"
+"Vzdálený soubor je novější, než lokální soubor „%s“, a je jej třeba "
+"stáhnout.\n"
 "\n"
 
-# , c-format
-#. Sizes do not match
-#: src/ftp.c:1446
-#, fuzzy, c-format
+#: src/ftp.c:1450
+#, c-format
 msgid ""
 "The sizes do not match (local %s) -- retrieving.\n"
 "\n"
 msgstr ""
-"Velikosti se neshoduj� (lok�ln� %ld), soubor je t�eba st�hnout.\n"
+"Velikosti se neshodují (lokální %s), stahuji.\n"
 "\n"
 
-#: src/ftp.c:1464
+#: src/ftp.c:1468
 msgid "Invalid name of the symlink, skipping.\n"
-msgstr "P�eskakuje se symbolick� odkaz, nebo� n�zev odkazu nen� platn�.\n"
+msgstr "Přeskakuje se symbolický odkaz, neboť název odkazu není platný.\n"
 
-# , c-format
-#: src/ftp.c:1481
+#: src/ftp.c:1485
 #, c-format
 msgid ""
 "Already have correct symlink %s -> %s\n"
 "\n"
 msgstr ""
-"Korektn� symbolick� odkaz %s -> %s ji� existuje.\n"
+"Korektní symbolický odkaz %s -> %s již existuje.\n"
 "\n"
 
-# , c-format
-#: src/ftp.c:1489
+#: src/ftp.c:1493
 #, c-format
 msgid "Creating symlink %s -> %s\n"
-msgstr "Vytv��� se symbolick� odkaz %s -> %s\n"
+msgstr "Vytváří se symbolický odkaz %s -> %s\n"
 
-# , c-format
-#: src/ftp.c:1499
+#: src/ftp.c:1503
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr ""
-"Symbolick� odkaz `%s' bude vynech�n, proto�e syst�m symbolick� odkazy "
+"Symbolický odkaz „%s“ bude vynechán, protože systém symbolické odkazy "
 "nepodporuje.\n"
 
-# , c-format
-#: src/ftp.c:1511
+#: src/ftp.c:1515
 #, c-format
 msgid "Skipping directory `%s'.\n"
-msgstr "Adres�� `%s' bude vynech�n.\n"
+msgstr "Adresář „%s“ bude vynechán.\n"
 
-# , c-format
-#: src/ftp.c:1520
+#: src/ftp.c:1524
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
-msgstr "%s: nezn�m�/nepodporovan� typ souboru.\n"
+msgstr "%s: neznámý/nepodporovaný typ souboru.\n"
 
-# , c-format
-#: src/ftp.c:1547
+#: src/ftp.c:1551
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
-msgstr "%s: �asov� raz�tko souboru je poru�en�.\n"
+msgstr "%s: časové razítko souboru je porušené.\n"
 
-# , c-format
-#: src/ftp.c:1575
+#: src/ftp.c:1579
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr ""
-"Podadres��e se nebudou p�en�et, proto�e ji� bylo dosa�eno hloubky %d "
+"Podadresáře se nebudou přenášet, protože již bylo dosaženo hloubky %d "
 "(maximum je %d).\n"
 
-# , c-format
-#: src/ftp.c:1625
+#: src/ftp.c:1629
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr ""
-"Do adres��e `%s' se nesetupuje, proto�e tento adres�� se bu� m� vynechat "
+"Do adresáře „%s“ se nesetupuje, protože tento adresář se buď má vynechat "
 "nebo\n"
-"nebyl zad�n k proch�zen�.\n"
+"nebyl zadán k procházení.\n"
 
-# , c-format
-#: src/ftp.c:1691 src/ftp.c:1705
+#: src/ftp.c:1695 src/ftp.c:1709
 #, c-format
 msgid "Rejecting `%s'.\n"
-msgstr "Soubor `%s' se nem� stahovat.\n"
+msgstr "Soubor „%s“ se nemá stahovat.\n"
 
-# , c-format
-#. No luck.
-#. #### This message SUCKS.  We should see what was the
-#. reason that nothing was retrieved.
-#: src/ftp.c:1753
+#: src/ftp.c:1757
 #, c-format
 msgid "No matches on pattern `%s'.\n"
-msgstr "Vzorku `%s' nic neodpov�d�.\n"
+msgstr "Vzorku „%s“ nic neodpovídá.\n"
 
-# , c-format
-#: src/ftp.c:1819
-#, fuzzy, c-format
+#: src/ftp.c:1823
+#, c-format
 msgid "Wrote HTML-ized index to `%s' [%s].\n"
-msgstr "V�pis adres��e v HTML form�tu byl zaps�n do `%s' [%ld].\n"
+msgstr "Výpis adresáře v HTML formátu byl zapsán do „%s“ [%s].\n"
 
-# , c-format
-#: src/ftp.c:1824
+#: src/ftp.c:1828
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
-msgstr "V�pis adres��e v HTML form�tu byl zaps�n do `%s'.\n"
-
-# , c-format
-#: src/getopt.c:670
-#, c-format
-msgid "%s: option `%s' is ambiguous\n"
-msgstr "%s: p�ep�na� `%s' nen� jednozna�n�\n"
-
-# , c-format
-#: src/getopt.c:695
-#, c-format
-msgid "%s: option `--%s' doesn't allow an argument\n"
-msgstr "%s: p�ep�na� `--%s' nem� argument\n"
-
-# , c-format
-#: src/getopt.c:700
-#, c-format
-msgid "%s: option `%c%s' doesn't allow an argument\n"
-msgstr "%s: p�ep�na� `%c%s' nem� argument\n"
-
-# , c-format
-#: src/getopt.c:718 src/getopt.c:891
-#, c-format
-msgid "%s: option `%s' requires an argument\n"
-msgstr "%s: p�ep�na� `%s' vy�aduje argument\n"
-
-# , c-format
-#. --option
-#: src/getopt.c:747
-#, c-format
-msgid "%s: unrecognized option `--%s'\n"
-msgstr "%s: nezn�m� p�ep�na� `--%s'\n"
-
-# , c-format
-#. +option or -option
-#: src/getopt.c:751
-#, c-format
-msgid "%s: unrecognized option `%c%s'\n"
-msgstr "%s: nezn�m� p�ep�na� `%c%s'\n"
-
-# , c-format
-#. 1003.2 specifies the format of this message.
-#: src/getopt.c:777
-#, c-format
-msgid "%s: illegal option -- %c\n"
-msgstr "%s: nep��pustn� p�ep�na� -- %c\n"
-
-# , c-format
-#: src/getopt.c:780
-#, fuzzy, c-format
-msgid "%s: invalid option -- %c\n"
-msgstr "%s: nep��pustn� p�ep�na� -- %c\n"
-
-# , c-format
-#. 1003.2 specifies the format of this message.
-#: src/getopt.c:810 src/getopt.c:940
-#, c-format
-msgid "%s: option requires an argument -- %c\n"
-msgstr "%s: p�ep�na� vy�aduje argument -- %c\n"
-
-# , c-format
-#: src/getopt.c:857
-#, fuzzy, c-format
-msgid "%s: option `-W %s' is ambiguous\n"
-msgstr "%s: p�ep�na� `%s' nen� jednozna�n�\n"
-
-# , c-format
-#: src/getopt.c:875
-#, fuzzy, c-format
-msgid "%s: option `-W %s' doesn't allow an argument\n"
-msgstr "%s: p�ep�na� `--%s' nem� argument\n"
+msgstr "Výpis adresáře v HTML formátu byl zapsán do „%s“.\n"
 
 #: src/host.c:347
-#, fuzzy
 msgid "Unknown host"
-msgstr "Nezn�m� chyba"
+msgstr "Neznámé jméno počítače"
 
-#. Message modeled after what gai_strerror returns in similar
-#. circumstances.
 #: src/host.c:351
 msgid "Temporary failure in name resolution"
-msgstr ""
+msgstr "Dočasná chyba při překladu jména"
 
 #: src/host.c:353
 msgid "Unknown error"
-msgstr "Nezn�m� chyba"
+msgstr "Neznámá chyba"
 
-# , c-format
 #: src/host.c:714
-#, fuzzy, c-format
+#, c-format
 msgid "Resolving %s... "
-msgstr "Ma�e se %s.\n"
+msgstr "Překlad %s… "
 
 #: src/host.c:761
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
-msgstr ""
+msgstr "selhal: Pro dané jméno neexistuje žádná IPv4/IPv6 adresa.\n"
 
 #: src/host.c:784
 msgid "failed: timed out.\n"
-msgstr ""
+msgstr "selhal: vypršel časový limit.\n"
 
 #: src/html-url.c:288
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
-msgstr ""
+msgstr "%s: Neúplný odkaz %s nelze vyhodnotit.\n"
 
-# , c-format
 #: src/html-url.c:695
-#, fuzzy, c-format
+#, c-format
 msgid "%s: Invalid URL %s: %s\n"
-msgstr "%s: Neplatn� specifikace `%s'\n"
+msgstr "%s: Neplatné URL %s: %s\n"
 
 #: src/http.c:367
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
-msgstr "Nebylo mo�n� odeslat HTTP po�adavek: %s.\n"
+msgstr "Nebylo možné odeslat HTTP požadavek: %s.\n"
 
 #: src/http.c:736
 msgid "No headers, assuming HTTP/0.9"
-msgstr ""
+msgstr "Chybí hlavičky, předpokládám HTTP/0.9"
 
 #: src/http.c:1413
 msgid "Disabling SSL due to encountered errors.\n"
-msgstr ""
+msgstr "Vypínám SSL kvůli chybám, které se vyskytly.\n"
 
 #: src/http.c:1566
 #, c-format
 msgid "POST data file `%s' missing: %s\n"
-msgstr ""
+msgstr "Soubor „%s“ s daty pro POST chybí: %s\n"
 
-# , c-format
 #: src/http.c:1615
-#, fuzzy, c-format
+#, c-format
 msgid "Reusing existing connection to %s:%d.\n"
-msgstr "Program vyu�ije existuj�c� spojen� s %s:%hu.\n"
+msgstr "Využívám existující spojení s %s:%d.\n"
 
-#: src/http.c:1684
-#, fuzzy, c-format
+#: src/http.c:1683
+#, c-format
 msgid "Failed reading proxy response: %s\n"
-msgstr "Nebylo mo�n� odeslat HTTP po�adavek: %s.\n"
+msgstr "Chyba při čtení odpovědi od proxy: %s\n"
 
-#: src/http.c:1704
+#: src/http.c:1703
 #, c-format
 msgid "Proxy tunneling failed: %s"
-msgstr ""
+msgstr "Tunelování zkrz proxy se nezdařilo: %s"
 
-# , c-format
-#: src/http.c:1749
+#: src/http.c:1748
 #, c-format
 msgid "%s request sent, awaiting response... "
-msgstr "%s po�adavek odesl�n, program �ek� na odpov�� ... "
+msgstr "%s požadavek odeslán, program čeká na odpověď… "
 
-#: src/http.c:1760
-#, fuzzy
+#: src/http.c:1759
 msgid "No data received.\n"
-msgstr "Nep�i�la ��dn� data"
+msgstr "Nepřišla žádná data.\n"
 
-# , c-format
-#: src/http.c:1767
+#: src/http.c:1766
 #, c-format
 msgid "Read error (%s) in headers.\n"
-msgstr "Chyba (%s) p�i �ten� hlavi�ek.\n"
+msgstr "Chyba (%s) při čtení hlaviček.\n"
 
-# , c-format
-#. If opt.noclobber is turned on and file already exists, do not
-#. retrieve the file
-#: src/http.c:1813
-#, fuzzy, c-format
+#: src/http.c:1812
+#, c-format
 msgid ""
 "File `%s' already there; not retrieving.\n"
 "\n"
-msgstr "Soubor `%s' je ji� zde a nen� jej t�eba p�en�et.\n"
+msgstr ""
+"Soubor „%s“ je již zde, nebudu jej třeba přenášet.\n"
+"\n"
 
-#. If the authentication header is missing or
-#. unrecognized, there's no sense in retrying.
-#: src/http.c:1966
+#: src/http.c:1965
 msgid "Unknown authentication scheme.\n"
-msgstr "Server po�aduje nezn�m� zp�sob autentifikace.\n"
+msgstr "Server požaduje neznámý způsob autentifikace.\n"
 
-#: src/http.c:1997
+#: src/http.c:1996
 msgid "Authorization failed.\n"
 msgstr "Autorizace selhala.\n"
 
-#: src/http.c:2011
+#: src/http.c:2010
 msgid "Malformed status line"
-msgstr "Odpov�� serveru m� zkomolen� stavov� ��dek"
+msgstr "Odpověď serveru má zkomolený stavový řádek"
 
-#: src/http.c:2013
+#: src/http.c:2012
 msgid "(no description)"
-msgstr "(��dn� popis)"
+msgstr "(žádný popis)"
 
-# , c-format
-#: src/http.c:2076
+#: src/http.c:2075
 #, c-format
 msgid "Location: %s%s\n"
-msgstr "P�esm�rov�no na: %s%s\n"
+msgstr "Přesměrováno na: %s%s\n"
 
-#: src/http.c:2077 src/http.c:2184
+#: src/http.c:2076 src/http.c:2183
 msgid "unspecified"
-msgstr "neud�no"
+msgstr "neudáno"
 
-#: src/http.c:2078
+#: src/http.c:2077
 msgid " [following]"
-msgstr " [n�sleduji]"
+msgstr " [následuji]"
 
-#. If `-c' is in use and the file has been fully downloaded (or
-#. the remote file has shrunk), Wget effectively requests bytes
-#. after the end of file and the server response with 416.
-#: src/http.c:2134
+#: src/http.c:2133
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 "\n"
-"    Soubor je ji� pln� p�enesen, nebude se nic d�lat.\n"
+"    Soubor je již plně přenesen, nebude se nic dělat.\n"
 "\n"
 
-#. No need to print this output if the body won't be
-#. downloaded at all, or if the original server response is
-#. printed.
-#: src/http.c:2164
+#: src/http.c:2163
 msgid "Length: "
-msgstr "D�lka: "
+msgstr "Délka: "
 
-#: src/http.c:2184
+#: src/http.c:2183
 msgid "ignored"
-msgstr "je ignorov�na"
+msgstr "je ignorována"
 
-# , c-format
-#: src/http.c:2255
-#, fuzzy, c-format
+#: src/http.c:2254
+#, c-format
 msgid "Saving to: `%s'\n"
-msgstr "Adres�� `%s' bude vynech�n.\n"
+msgstr "Ukládám do: „%s“.\n"
 
 #: src/http.c:2335
 msgid "Warning: wildcards not supported in HTTP.\n"
-msgstr "Varov�n�: HTTP nepodporuje �ol�kov� znaky.\n"
+msgstr "Varování: HTTP nepodporuje žolíkové znaky.\n"
 
-#: src/http.c:2364
+#: src/http.c:2382
 msgid "Spider mode enabled. Check if remote file exists.\n"
-msgstr ""
+msgstr "Aktivován režim pavouka. Kontroluje, zda vzdálený soubor existuje.\n"
 
-# , c-format
-#: src/http.c:2450
+#: src/http.c:2467
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
-msgstr "Nelze zapsat do `%s' (%s).\n"
+msgstr "Nelze zapsat do „%s“ (%s).\n"
 
-#. Another fatal error.
-#: src/http.c:2459
+#: src/http.c:2476
 msgid "Unable to establish SSL connection.\n"
-msgstr "Nebylo mo�n� nav�zat SSL spojen�.\n"
+msgstr "Nebylo možné navázat SSL spojení.\n"
 
 # , c-format
-#: src/http.c:2467
+#: src/http.c:2484
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
-msgstr "CHYBA: P�esm�rov�n� (%d) bez udan� nov� adresy.\n"
+msgstr "CHYBA: Přesměrování (%d) bez udané nové adresy.\n"
 
-#: src/http.c:2505
+#: src/http.c:2530
 msgid "Remote file does not exist -- broken link!!!\n"
-msgstr ""
+msgstr "Vzdálený soubor neexistuje – slepý odkaz!!!\n"
 
-# , c-format
-#: src/http.c:2510
+#: src/http.c:2535
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s CHYBA %d: %s.\n"
 
-#: src/http.c:2526
+#: src/http.c:2551
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr ""
-"Nelze pou��t �asov� raz�tka (`time-stamps'), proto�e v odpov�di serveru \n"
-"sch�z� hlavi�ka \"Last-modified\".\n"
+"Nelze použít časová razítka, protože v odpovědi serveru \n"
+"schází hlavička „Last-modified“.\n"
 
-#: src/http.c:2534
+#: src/http.c:2559
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr ""
-"�asov� raz�tko souboru (`time-stamp') bude ignorov�no, proto�e hlavi�ka \n"
-"\"Last-modified\" obsahuje neplatn� �daje.\n"
+"Časové razítko souboru bude ignorováno, protože hlavička \n"
+"„Last-modified“ obsahuje neplatné údaje.\n"
 
-#: src/http.c:2558
+#: src/http.c:2589
 #, c-format
 msgid ""
 "Server file no newer than local file `%s' -- not retrieving.\n"
 "\n"
 msgstr ""
-"Lok�ln� soubor `%s' nen� star��, ne� vzd�len� soubor, a nen� jej t�eba "
+"Lokální soubor „%s“ není starší než vzdálený soubor a není třeba jej "
 "stahovat.\n"
 "\n"
 
-# , c-format
-#: src/http.c:2566
-#, fuzzy, c-format
+#: src/http.c:2597
+#, c-format
 msgid "The sizes do not match (local %s) -- retrieving.\n"
-msgstr "Velikosti se neshoduj� (lok�ln� %ld), soubor je t�eba st�hnout.\n"
+msgstr "Velikosti se neshodují (lokální %s), stahuji.\n"
 
-#: src/http.c:2573
+#: src/http.c:2604
 msgid "Remote file is newer, retrieving.\n"
-msgstr "Lok�ln� soubor je star�� a vzd�len� soubor se proto bude p�en�et.\n"
+msgstr "Lokální soubor je starší a vzdálený soubor se proto bude přenášet.\n"
 
-#: src/http.c:2596
-#, fuzzy
+#: src/http.c:2620
 msgid ""
 "Remote file exists and could contain links to other resources -- "
 "retrieving.\n"
 "\n"
 msgstr ""
-"Vzd�len� soubor je nov�j��, ne� lok�ln� soubor `%s', a je jej t�eba "
-"st�hnout.\n"
+"Vzdálený soubor nexistuje a mohl by obsahovat odkazy na další "
+"zdroje – stahuji.\n"
 "\n"
 
-#: src/http.c:2602
-#, fuzzy
+#: src/http.c:2625
 msgid ""
 "Remote file exists but does not contain any link -- not retrieving.\n"
 "\n"
 msgstr ""
-"Vzd�len� soubor nen� nov�j��, ne� lok�ln� soubor `%s', a nen� jej t�eba "
-"stahovat.\n"
+"Vzdálený soubor existuje, ale neobsahuje žádné odkazy – nestahuji.\n"
+"\n"
 
-#: src/http.c:2610
-#, fuzzy
+#: src/http.c:2633
 msgid ""
 "Remote file exists but recursion is disabled -- not retrieving.\n"
 "\n"
-msgstr ""
-"Vzd�len� soubor nen� nov�j��, ne� lok�ln� soubor `%s', a nen� jej t�eba "
-"stahovat.\n"
+msgstr "Vzdálený soubor existuje, ale rekurze je vypnuta – nestahuji.\n"
 
-# , c-format
-#: src/http.c:2652
-#, fuzzy, c-format
+#: src/http.c:2685
+#, c-format
 msgid ""
 "%s (%s) - `%s' saved [%s/%s]\n"
 "\n"
 msgstr ""
-"%s (%s) - `%s' ulo�eno [%ld/%ld]\n"
+"%s (%s) – „%s“ uloženo [%s/%s]\n"
 "\n"
 
-# , c-format
-#: src/http.c:2707
-#, fuzzy, c-format
+#: src/http.c:2740
+#, c-format
 msgid "%s (%s) - Connection closed at byte %s. "
-msgstr "%s (%s) - Spojen� ukon�eno na bajtu %ld. "
+msgstr "%s (%s) – Spojení ukončeno na bajtu %s. "
 
-# , c-format
-#: src/http.c:2722
-#, fuzzy, c-format
+#: src/http.c:2755
+#, c-format
 msgid "%s (%s) - Read error at byte %s (%s)."
-msgstr "%s (%s) - Chyba p�i �ten� dat na bajtu %ld (%s)."
+msgstr "%s (%s) – Chyba při čtení dat na bajtu %s (%s)."
 
-# , c-format
-#: src/http.c:2731
-#, fuzzy, c-format
+#: src/http.c:2764
+#, c-format
 msgid "%s (%s) - Read error at byte %s/%s (%s). "
-msgstr "%s (%s) - Chyba p�i �ten� dat na bajtu %ld/%ld (%s). "
+msgstr "%s (%s) – Chyba při čtení dat na bajtu %s/%s (%s). "
 
-#: src/init.c:370
+#: src/init.c:386
 #, c-format
 msgid "%s: WGETRC points to %s, which doesn't exist.\n"
-msgstr ""
+msgstr "%s: WGETRC ukazuje na %s, který ale neexistuje.\n"
 
-# , c-format
-#: src/init.c:433 src/netrc.c:267
+#: src/init.c:449 src/netrc.c:264
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
-msgstr "%s: Nelze p�e��st %s (%s).\n"
+msgstr "%s: Nelze přečíst %s (%s).\n"
 
-# , c-format
-#: src/init.c:451
+#: src/init.c:467
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
-msgstr "%s: Chyba v %s na ��dku %d.\n"
+msgstr "%s: Chyba v %s na řádku %d.\n"
 
-# , c-format
-#: src/init.c:457
-#, fuzzy, c-format
+#: src/init.c:473
+#, c-format
 msgid "%s: Syntax error in %s at line %d.\n"
-msgstr "%s: Chyba v %s na ��dku %d.\n"
+msgstr "%s: Syntaktická chyba v %s na řádku %d.\n"
 
-# , c-format
-#: src/init.c:462
-#, fuzzy, c-format
+#: src/init.c:478
+#, c-format
 msgid "%s: Unknown command `%s' in %s at line %d.\n"
-msgstr "%s: CHYBA: Nezn�m� p��kaz `%s', hodnota `%s'.\n"
+msgstr "%s: Neznámý příkaz „%s“ v %s na řádku %d.\n"
 
-# , c-format
-#: src/init.c:507
+#: src/init.c:523
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
 msgstr ""
-"%s: Varov�n�: Glob�ln� i u�ivatelsk� wgetrc jsou shodn� ulo�eny v `%s'.\n"
+"%s: Varování: Globální i uživatelské wgetrc jsou shodně uloženy v „%s“.\n"
 
-# , c-format
-#: src/init.c:660
-#, fuzzy, c-format
+#: src/init.c:676
+#, c-format
 msgid "%s: Invalid --execute command `%s'\n"
-msgstr "%s: Neplatn� specifikace `%s'\n"
+msgstr "%s: Neplatný příkaz --execute „%s“\n"
 
-# , c-format
-#: src/init.c:705
-#, fuzzy, c-format
+#: src/init.c:721
+#, c-format
 msgid "%s: %s: Invalid boolean `%s'; use `on' or `off'.\n"
-msgstr "%s: %s: Zadejte pros�m `on' (zapnuto) nebo `off' (vypnuto).\n"
+msgstr ""
+"%s: %s: Chybná pravdivostní hodnota „%s“, zadejte „on“ (zapnuto) nebo "
+"„off“ (vypnuto).\n"
 
-# , c-format
-#: src/init.c:722
-#, fuzzy, c-format
+#: src/init.c:738
+#, c-format
 msgid "%s: %s: Invalid number `%s'.\n"
-msgstr "%s: %s: Neplatn� specifikace `%s'\n"
+msgstr "%s: %s: Neplatné číslo „%s“\n"
 
-# , c-format
-#: src/init.c:953 src/init.c:972
-#, fuzzy, c-format
+#: src/init.c:969 src/init.c:988
+#, c-format
 msgid "%s: %s: Invalid byte value `%s'\n"
-msgstr "%s: %s: Neplatn� specifikace `%s'\n"
+msgstr "%s: %s: Neplatná hodnota bajtu „%s“\n"
 
-# , c-format
-#: src/init.c:997
-#, fuzzy, c-format
+#: src/init.c:1013
+#, c-format
 msgid "%s: %s: Invalid time period `%s'\n"
-msgstr "%s: %s: Neplatn� specifikace `%s'\n"
+msgstr "%s: %s: Neplatná časová perioda „%s“\n"
 
-# , c-format
-#: src/init.c:1051 src/init.c:1141 src/init.c:1244 src/init.c:1269
-#, fuzzy, c-format
+#: src/init.c:1067 src/init.c:1157 src/init.c:1260 src/init.c:1285
+#, c-format
 msgid "%s: %s: Invalid value `%s'.\n"
-msgstr "%s: %s: Neplatn� specifikace `%s'\n"
+msgstr "%s: %s: Neplatná hodnota „%s“.\n"
 
-# , c-format
-#: src/init.c:1088
-#, fuzzy, c-format
+#: src/init.c:1104
+#, c-format
 msgid "%s: %s: Invalid header `%s'.\n"
-msgstr "%s: %s: Neplatn� specifikace `%s'\n"
+msgstr "%s: %s: Neplatná hlavička „%s“\n"
 
-# , c-format
-#: src/init.c:1154
-#, fuzzy, c-format
+#: src/init.c:1170
+#, c-format
 msgid "%s: %s: Invalid progress type `%s'.\n"
-msgstr "%s: %s: Neplatn� specifikace `%s'\n"
+msgstr "%s: %s: Neplatný druh indikace postupu „%s“.\n"
 
-#: src/init.c:1213
+#: src/init.c:1229
 #, c-format
 msgid ""
 "%s: %s: Invalid restriction `%s', use [unix|windows],[lowercase|uppercase],"
 "[nocontrol].\n"
 msgstr ""
+"%s: %s: Neplatná hodnota omezení „%s“, použijte [unix|windows], [lowercase|"
+"uppercase] (malá/velká písmena), [nocontrol] (bez kontroly)\n"
 
 #: src/log.c:783
-#, fuzzy, c-format
+#, c-format
 msgid ""
 "\n"
 "%s received, redirecting output to `%s'.\n"
-msgstr "Byl zachycen sign�l %s, v�stup p�esm�rov�n do `%%s'.\n"
+msgstr ""
+"\n"
+"Obdržen signál %s, výstup přesměrován do „%s“.\n"
 
-#. Eek!  Opening the alternate log file has failed.  Nothing we
-#. can do but disable printing completely.
 #: src/log.c:793
-#, fuzzy, c-format
+#, c-format
 msgid ""
 "\n"
 "%s received.\n"
-msgstr "Nep�i�la ��dn� data"
+msgstr ""
+"\n"
+"obdržen signál %s.\n"
 
 #: src/log.c:794
 #, c-format
 msgid "%s: %s; disabling logging.\n"
-msgstr ""
+msgstr "%s: %s: vypínám protokolování\n"
 
-# , c-format
-#: src/main.c:353
+#: src/main.c:356
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
-msgstr "Pou�it�: %s [P�EP�NA�]... [URL]...\n"
+msgstr "Použití: %s [PŘEPÍNAČ]… [URL]…\n"
 
-#: src/main.c:365
-#, fuzzy
+#: src/main.c:368
 msgid ""
 "Mandatory arguments to long options are mandatory for short options too.\n"
 "\n"
 msgstr ""
-"\n"
-"Argumenty, povinn� u dlouh�ch p�ep�na��, jsou povinn� i pro kr�tk� verze\n"
-"p�ep�na��.\n"
+"Argumenty povinné u dlouhých přepínačů jsou povinné i pro jejich krátké "
+"verze.\n"
 "\n"
 
-#: src/main.c:367
+#: src/main.c:370
 msgid "Startup:\n"
-msgstr ""
+msgstr "Rozjezd:\n"
 
-#: src/main.c:369
+#: src/main.c:372
 msgid "  -V,  --version           display the version of Wget and exit.\n"
-msgstr ""
+msgstr "  -V,  --version           zobrazí verzi Wgetu a skončí.\n"
 
-#: src/main.c:371
+#: src/main.c:374
 msgid "  -h,  --help              print this help.\n"
-msgstr ""
+msgstr "  -h,  --help              vytiskne tuto nápovědu.\n"
 
-#: src/main.c:373
+#: src/main.c:376
 msgid "  -b,  --background        go to background after startup.\n"
-msgstr ""
+msgstr "  -b,  --background        po spuštění přejde do pozadí.\n"
 
-#: src/main.c:375
+#: src/main.c:378
 msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
-msgstr ""
+msgstr "  -e,  --execute=PŘÍKAZ    provede příkaz jako z „.wgetrc“.\n"
 
-#: src/main.c:379
+#: src/main.c:382
 msgid "Logging and input file:\n"
-msgstr ""
+msgstr "Protokolový a vstupní soubor:\n"
 
-#: src/main.c:381
+#: src/main.c:384
 msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
-msgstr ""
+msgstr "  -o,  --output-file=SOUBOR  protokol zapisuje do SOUBORU.\n"
 
-#: src/main.c:383
+#: src/main.c:386
 msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
 msgstr ""
+"  -a,  --append-output=SOUBOR\n"
+"                             zprávy připojuje k SOUBORU.\n"
 
-#: src/main.c:386
+#: src/main.c:389
 msgid "  -d,  --debug               print lots of debugging information.\n"
-msgstr ""
+msgstr "  -d,  --debug               tiskne mnoho ladicích informací.\n"
 
-#: src/main.c:389
+#: src/main.c:393
+#, fuzzy
+msgid "       --wdebug              print Watt-32 debug output.\n"
+msgstr "  -d,  --debug               tiskne mnoho ladicích informací.\n"
+
+#: src/main.c:396
 msgid "  -q,  --quiet               quiet (no output).\n"
-msgstr ""
+msgstr "  -q,  --quiet               tichý režim (žádný výstup).\n"
 
-#: src/main.c:391
+#: src/main.c:398
 msgid "  -v,  --verbose             be verbose (this is the default).\n"
-msgstr ""
+msgstr "  -v,  --verbose             bude upovídaný (implicitní chování).\n"
 
-#: src/main.c:393
+#: src/main.c:400
 msgid ""
 "  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
 msgstr ""
+"  -nv, --no-verbose          vypne upovídanost, aniž by byl zcela zticha.\n"
 
-#: src/main.c:395
+#: src/main.c:402
 msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
-msgstr ""
+msgstr "  -i,  --input-file=SOUBOR   stáhne URL uvedená v SOUBORU.\n"
 
-#: src/main.c:397
+#: src/main.c:404
 msgid "  -F,  --force-html          treat input file as HTML.\n"
-msgstr ""
+msgstr "  -F,  --force-html          vstupní soubor považuje za HTML soubor.\n"
 
-#: src/main.c:399
+#: src/main.c:406
 msgid ""
 "  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
 msgstr ""
+"  -B,  --base=URL            předřadí URL relativním odkazům z -F -i "
+"souboru.\n"
 
-#: src/main.c:403
+#: src/main.c:410
 msgid "Download:\n"
-msgstr ""
+msgstr "Stahování:\n"
 
-#: src/main.c:405
+#: src/main.c:412
 msgid ""
 "  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
 "unlimits).\n"
 msgstr ""
+"  -t,  --tries=POČET             nastaví POČET opakování (0 znamená "
+"neomezeno).\n"
 
-#: src/main.c:407
+#: src/main.c:414
 msgid "       --retry-connrefused       retry even if connection is refused.\n"
 msgstr ""
+"       --retry-connrefused       opakuje, i když spojení bude odmítnuto.\n"
 
-#: src/main.c:409
+#: src/main.c:416
 msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
-msgstr ""
+msgstr "  -O,  --output-document=SOUBOR  dokumenty zapisuje do SOUBORU.\n"
 
-#: src/main.c:411
+#: src/main.c:418
 msgid ""
 "  -nc, --no-clobber              skip downloads that would download to\n"
 "                                 existing files.\n"
 msgstr ""
+"  -nc, --no-clobber              vynechá stahování, která by přepsala již\n"
+"                                 existující soubory.\n"
 
-#: src/main.c:414
+#: src/main.c:421
 msgid ""
 "  -c,  --continue                resume getting a partially-downloaded "
 "file.\n"
 msgstr ""
+"  -c,  --continue                obnoví stahování částečně staženého "
+"souboru.\n"
 
-#: src/main.c:416
+#: src/main.c:423
 msgid "       --progress=TYPE           select progress gauge type.\n"
-msgstr ""
+msgstr "       --progress=DRUH           vybere druh indikátoru postupu.\n"
 
-#: src/main.c:418
+#: src/main.c:425
 msgid ""
 "  -N,  --timestamping            don't re-retrieve files unless newer than\n"
 "                                 local.\n"
 msgstr ""
+"  -N,  --timestamping            nesnaží se znovu získat soubory, jež mají\n"
+"                                 mladší místní kopii\n"
 
-#: src/main.c:421
+#: src/main.c:428
 msgid "  -S,  --server-response         print server response.\n"
-msgstr ""
+msgstr "  -S,  --server-response         tiskne odpověď serveru.\n"
 
-#: src/main.c:423
+#: src/main.c:430
 msgid "       --spider                  don't download anything.\n"
-msgstr ""
+msgstr "       --spider                  nestahuje nic.\n"
 
-#: src/main.c:425
+#: src/main.c:432
 msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
 msgstr ""
+"  -T,  --timeout=SEKUNDY         nastaví všechny časové limity\n"
+"                                 na SEKUND.\n"
 
-#: src/main.c:427
+#: src/main.c:434
 msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
 msgstr ""
+"       --dns-timeout=SEKUNDY     nastaví limit pro hledání v DNS\n"
+"                                 na SEKUND.\n"
 
-#: src/main.c:429
+#: src/main.c:436
 msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
 msgstr ""
+"       --connect-timeout=SEKUNDY\n"
+"                                 nastaví limit pro navázání spojení\n"
+"                                 na SEKUND.\n"
 
-#: src/main.c:431
+#: src/main.c:438
 msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
-msgstr ""
+msgstr "       --read-timeout=SEKUNDY    nastaví limit pro čtení na SEKUND\n"
 
-#: src/main.c:433
+#: src/main.c:440
 msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
-msgstr ""
+msgstr "  -w,  --wait=SEKUNDY            čeká SEKUND mezi každým stažením.\n"
 
-#: src/main.c:435
+#: src/main.c:442
 msgid ""
 "       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
 "retrieval.\n"
 msgstr ""
+"       --waitretry=SEKUNDY       čeká 1 až SEKUND mezi opakováním stažení.\n"
 
-#: src/main.c:437
+#: src/main.c:444
 msgid ""
 "       --random-wait             wait from 0...2*WAIT secs between "
 "retrievals.\n"
 msgstr ""
+"       --random-wait             čeká od 0 do 2*WAIT sekund mezi staženími.\n"
 
-#: src/main.c:439
+#: src/main.c:446
 msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
-msgstr ""
+msgstr "  -Y,  --proxy                   explicitně zapne proxy.\n"
 
-#: src/main.c:441
+#: src/main.c:448
 msgid "       --no-proxy                explicitly turn off proxy.\n"
-msgstr ""
+msgstr "       --no-proxy                explicitně vypne proxy.\n"
 
-#: src/main.c:443
+#: src/main.c:450
 msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
-msgstr ""
+msgstr "  -Q,  --quota=POČET             nastaví kvótu na POČET stažení.\n"
 
-#: src/main.c:445
+#: src/main.c:452
 msgid ""
 "       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
 "host.\n"
 msgstr ""
+"       --bind-address=ADRESA     přilepí se (bind) na ADRESU (jméno nebo "
+"IP)\n"
+"                                 na tomto stroji.\n"
 
-#: src/main.c:447
+#: src/main.c:454
 msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
 msgstr ""
+"       --limit-rate=RYCHLOST     omezí rychlost stahování na RYCHLOST.\n"
 
-#: src/main.c:449
+#: src/main.c:456
 msgid "       --no-dns-cache            disable caching DNS lookups.\n"
-msgstr ""
+msgstr "       --no-dns-cache            zakáže kešování DNS odpovědí.\n"
 
-#: src/main.c:451
+#: src/main.c:458
 msgid ""
 "       --restrict-file-names=OS  restrict chars in file names to ones OS "
 "allows.\n"
 msgstr ""
+"       --restrict-file-names=OS  omezí znaky ve jménech souborů na ty,\n"
+"                                 které dovoluje vybraný operační systém "
+"(OS).\n"
 
-#: src/main.c:453
+#: src/main.c:460
 msgid ""
 "       --ignore-case             ignore case when matching files/"
 "directories.\n"
 msgstr ""
+"       --ignore-case             při porovnávání jmen souborů/adresářů\n"
+"                                 nebere zřetel na velikost písmen.\n"
 
-#: src/main.c:456
+#: src/main.c:463
 msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
-msgstr ""
+msgstr "  -4,  --inet4-only              připojuje se jen na IPv4 adresy.\n"
 
-#: src/main.c:458
+#: src/main.c:465
 msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
-msgstr ""
+msgstr "  -6,  --inet6-only              připojuje se jen na IPv6 adresy.\n"
 
-#: src/main.c:460
+#: src/main.c:467
 msgid ""
 "       --prefer-family=FAMILY    connect first to addresses of specified "
 "family,\n"
 "                                 one of IPv6, IPv4, or none.\n"
 msgstr ""
+"       --prefer-family=RODINA    připojuje se nejprve na adresu zadané\n"
+"                                 RODINY („IPv6“, „IPv4“ nebo "
+"„none“ (žádná))\n"
 
-#: src/main.c:464
+#: src/main.c:471
 msgid "       --user=USER               set both ftp and http user to USER.\n"
 msgstr ""
+"       --user=UŽIVATEL           nastaví přihlašovací jméno uživatele\n"
+"                                 pro FTP i pro HTTP na UŽIVATELE.\n"
 
-#: src/main.c:466
+#: src/main.c:473
 msgid ""
 "       --password=PASS           set both ftp and http password to PASS.\n"
 msgstr ""
+"       --password=HESLO          nastaví heslo pro FTP i pro HTTP na HESLO.\n"
 
-#: src/main.c:470
-#, fuzzy
+#: src/main.c:477
 msgid "Directories:\n"
-msgstr "Adres��     "
+msgstr "Adresáře:\n"
 
-#: src/main.c:472
+#: src/main.c:479
 msgid "  -nd, --no-directories           don't create directories.\n"
-msgstr ""
+msgstr "  -nd, --no-directories           nevytváří adresáře,\n"
 
-#: src/main.c:474
+#: src/main.c:481
 msgid "  -x,  --force-directories        force creation of directories.\n"
-msgstr ""
+msgstr "  -x,  --force-directories        vynutí vytváření adresářů.\n"
 
-#: src/main.c:476
+#: src/main.c:483
 msgid "  -nH, --no-host-directories      don't create host directories.\n"
 msgstr ""
+"  -nH, --no-host-directories      nevytváří adresáře se jmény počítačů.\n"
 
-#: src/main.c:478
+#: src/main.c:485
 msgid "       --protocol-directories     use protocol name in directories.\n"
 msgstr ""
+"       --protocol-directories     použije jméno protokolu v adresářích.\n"
 
-#: src/main.c:480
+#: src/main.c:487
 msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
-msgstr ""
+msgstr "  -P,  --directory-prefix=CESTA   uloží soubory do CESTA/…\n"
 
-#: src/main.c:482
+#: src/main.c:489
 msgid ""
 "       --cut-dirs=NUMBER          ignore NUMBER remote directory "
 "components.\n"
 msgstr ""
+"       --cut-dirs=POČET           ignoruje POČET vzdálených adresářových\n"
+"                                  komponent.\n"
 
-#: src/main.c:486
+#: src/main.c:493
 msgid "HTTP options:\n"
-msgstr ""
+msgstr "Přepínače pro HTTP:\n"
 
-#: src/main.c:488
+#: src/main.c:495
 msgid "       --http-user=USER        set http user to USER.\n"
 msgstr ""
+"       --http-user=UŽIVATEL    nastaví přihlašovací jméno uživatele\n"
+"                               pro HTTP na UŽIVATELE.\n"
 
-#: src/main.c:490
+#: src/main.c:497
 msgid "       --http-password=PASS    set http password to PASS.\n"
-msgstr ""
+msgstr "       --http-password=HESLO   nastaví heslo pro HTTP na HESLO.\n"
 
-#: src/main.c:492
+#: src/main.c:499
 msgid "       --no-cache              disallow server-cached data.\n"
-msgstr ""
+msgstr "       --no-cache              zakáže kešování na straně serveru.\n"
 
-#: src/main.c:494
+#: src/main.c:501
 msgid ""
 "  -E,  --html-extension        save HTML documents with `.html' extension.\n"
 msgstr ""
+"  -E,  --html-extension        HTML dokumenty ukládá s příponou „.html“.\n"
 
-#: src/main.c:496
+#: src/main.c:503
 msgid "       --ignore-length         ignore `Content-Length' header field.\n"
-msgstr ""
+msgstr "       --ignore-length         ignoruje hlavičku „Content-Length“.\n"
 
-#: src/main.c:498
+#: src/main.c:505
 msgid "       --header=STRING         insert STRING among the headers.\n"
-msgstr ""
+msgstr "       --header=ŘETĚZEC        ke hlavičkám přidá ŘETĚZEC.\n"
 
-#: src/main.c:500
+#: src/main.c:507
 msgid "       --max-redirect          maximum redirections allowed per page.\n"
 msgstr ""
+"       --max-redirect          maximum přesměrování povolených\n"
+"                               na stránku.\n"
 
-#: src/main.c:502
+#: src/main.c:509
 msgid "       --proxy-user=USER       set USER as proxy username.\n"
 msgstr ""
+"       --proxy-user=UŽIVATEL   nastaví UŽIVATELE jako přihlašovací jméno\n"
+"                               uživatele pro proxy.\n"
 
-#: src/main.c:504
+#: src/main.c:511
 msgid "       --proxy-password=PASS   set PASS as proxy password.\n"
-msgstr ""
+msgstr "       --proxy-password=HESLO  nastaví HESLO jako heslo pro proxy.\n"
 
-#: src/main.c:506
+#: src/main.c:513
 msgid ""
 "       --referer=URL           include `Referer: URL' header in HTTP "
 "request.\n"
 msgstr ""
+"       --referer=URL           zahrne hlavičku „Referer: URL“ do\n"
+"                               HTTP požadavku.\n"
 
-#: src/main.c:508
+#: src/main.c:515
 msgid "       --save-headers          save the HTTP headers to file.\n"
-msgstr ""
+msgstr "       --save-headers          hlavičky HTTP uloží do souboru.\n"
 
-#: src/main.c:510
+#: src/main.c:517
 msgid ""
 "  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
 msgstr ""
+"  -U,  --user-agent=AGENT      identifikuje se jako AGENT místo Wget/VERZE.\n"
 
-#: src/main.c:512
+#: src/main.c:519
 msgid ""
 "       --no-http-keep-alive    disable HTTP keep-alive (persistent "
 "connections).\n"
 msgstr ""
+"       --no-http-keep-alive    zakáže HTTP keep-alive (trvalá spojení).\n"
 
-#: src/main.c:514
+#: src/main.c:521
 msgid "       --no-cookies            don't use cookies.\n"
-msgstr ""
+msgstr "       --no-cookies            nepoužívá cookies.\n"
 
-#: src/main.c:516
+#: src/main.c:523
 msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
-msgstr ""
+msgstr "       --load-cookies=SOUBOR   před relací načte cookies ze SOUBORU.\n"
 
-#: src/main.c:518
+#: src/main.c:525
 msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
-msgstr ""
+msgstr "       --save-cookies=SOUBOR   po relaci uloží cookies do SOUBORU.\n"
 
-#: src/main.c:520
+#: src/main.c:527
 msgid ""
 "       --keep-session-cookies  load and save session (non-permanent) "
 "cookies.\n"
 msgstr ""
+"       --keep-session-cookies  načte a uloží cookies relace (ne-trvalé).\n"
 
-#: src/main.c:522
+#: src/main.c:529
 msgid ""
 "       --post-data=STRING      use the POST method; send STRING as the "
 "data.\n"
 msgstr ""
+"       --post-data=ŘETĚZEC     použije metodu POST, jako data pošle "
+"ŘETĚZEC.\n"
 
-#: src/main.c:524
+#: src/main.c:531
 msgid ""
 "       --post-file=FILE        use the POST method; send contents of FILE.\n"
 msgstr ""
+"       --post-file=SOUBOR      použije metodu POST, pošle obsah SOUBORU.\n"
 
-#: src/main.c:526
+#: src/main.c:533
 msgid ""
 "       --no-content-disposition  don't honor Content-Disposition header.\n"
 msgstr ""
+"       --no-content-disposition  nebere v úvahu hlavičku Content-"
+"Disposition.\n"
 
-#: src/main.c:531
+#: src/main.c:538
 msgid "HTTPS (SSL/TLS) options:\n"
-msgstr ""
+msgstr "Přepínače HTTPS (SSL/TLS):\n"
 
-#: src/main.c:533
+#: src/main.c:540
 msgid ""
 "       --secure-protocol=PR     choose secure protocol, one of auto, SSLv2,\n"
 "                                SSLv3, and TLSv1.\n"
 msgstr ""
+"       --secure-protocol=PROT   vybere bezpečnostní protokol, jeden z "
+"„auto“,\n"
+"                                „SSLv2“, „SSLv3“ a „TLSv1“.\n"
 
-#: src/main.c:536
+#: src/main.c:543
 msgid ""
 "       --no-check-certificate   don't validate the server's certificate.\n"
-msgstr ""
+msgstr "       --no-check-certificate   neověřuje certifikát serveru.\n"
 
-#: src/main.c:538
+#: src/main.c:545
 msgid "       --certificate=FILE       client certificate file.\n"
-msgstr ""
+msgstr "       --certificate=SOUBOR     soubor s certifikátem klienta.\n"
 
-#: src/main.c:540
+#: src/main.c:547
 msgid "       --certificate-type=TYPE  client certificate type, PEM or DER.\n"
 msgstr ""
+"       --certificate-type=DRUH  druh certifikátu klienta: „PEM“ nebo „DER“.\n"
 
-#: src/main.c:542
+#: src/main.c:549
 msgid "       --private-key=FILE       private key file.\n"
-msgstr ""
+msgstr "       --private-key=SOUBOR     soubor se soukromým klíčem.\n"
 
-#: src/main.c:544
+#: src/main.c:551
 msgid "       --private-key-type=TYPE  private key type, PEM or DER.\n"
 msgstr ""
+"       --private-key-type=DRUH  druh soukromého klíče: „PEM“ nebo „DER“.\n"
 
-#: src/main.c:546
+#: src/main.c:553
 msgid "       --ca-certificate=FILE    file with the bundle of CA's.\n"
 msgstr ""
+"       --ca-certificate=SOUBOR  soubor se sbírkou certifikačních autorit.\n"
 
-#: src/main.c:548
+#: src/main.c:555
 msgid ""
 "       --ca-directory=DIR       directory where hash list of CA's is "
 "stored.\n"
 msgstr ""
+"       --ca-directory=ADRESÁŘ   adresář obsahující hashe jmen\n"
+"                                certifikačních autorit.\n"
 
-#: src/main.c:550
+#: src/main.c:557
 msgid ""
 "       --random-file=FILE       file with random data for seeding the SSL "
 "PRNG.\n"
 msgstr ""
+"       --random-file=SOUBOR     soubor s náhodnými daty pro zdroj SSL PRNG.\n"
 
-#: src/main.c:552
+#: src/main.c:559
 msgid ""
 "       --egd-file=FILE          file naming the EGD socket with random "
 "data.\n"
 msgstr ""
+"       --egd-file=SOUBOR        soubor jmenující soket EGD s náhodnými "
+"daty.\n"
 
-#: src/main.c:557
+#: src/main.c:564
 msgid "FTP options:\n"
-msgstr ""
+msgstr "Přepínače FTP:\n"
 
-#: src/main.c:559
+#: src/main.c:566
 msgid "       --ftp-user=USER         set ftp user to USER.\n"
 msgstr ""
+"       --ftp-user=UŽIVATEL     nastaví přihlašovací jméno na UŽIVATELE.\n"
 
-#: src/main.c:561
+#: src/main.c:568
 msgid "       --ftp-password=PASS     set ftp password to PASS.\n"
-msgstr ""
+msgstr "       --ftp-password=HESLO    nastaví heslo pro FTP na HESLO.\n"
 
-#: src/main.c:563
+#: src/main.c:570
 msgid "       --no-remove-listing     don't remove `.listing' files.\n"
-msgstr ""
+msgstr "       --no-remove-listing     neodstraňuje soubory „.listing“.\n"
 
-#: src/main.c:565
+#: src/main.c:572
 msgid "       --no-glob               turn off FTP file name globbing.\n"
-msgstr ""
+msgstr "       --no-glob               neexpanduje jména FTP souborů.\n"
 
-#: src/main.c:567
+#: src/main.c:574
 msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
-msgstr ""
+msgstr "       --no-passive-ftp        zakáže pasivní režim přenosu.\n"
 
-#: src/main.c:569
+#: src/main.c:576
 msgid ""
 "       --retr-symlinks         when recursing, get linked-to files (not "
 "dir).\n"
 msgstr ""
+"       --retr-symlinks         při rekurzi stáhne soubory (adresáře ne),\n"
+"                               na které odkazuje symbolický odkaz.\n"
 
-#: src/main.c:571
+#: src/main.c:578
 msgid "       --preserve-permissions  preserve remote file permissions.\n"
-msgstr ""
+msgstr "       --preserve-permissions  zachová přístupová práva ze serveru.\n"
 
-#: src/main.c:575
+#: src/main.c:582
 msgid "Recursive download:\n"
-msgstr ""
+msgstr "Rekurzivní stahování:\n"
 
-#: src/main.c:577
+#: src/main.c:584
 msgid "  -r,  --recursive          specify recursive download.\n"
-msgstr ""
+msgstr "  -r,  --recursive          zapne rekurzivní stahování.\n"
 
-#: src/main.c:579
+#: src/main.c:586
 msgid ""
 "  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
 "infinite).\n"
 msgstr ""
+"  -l,  --level=POČET        maximální hloubka rekurze\n"
+"                            („inf“ nebo „0“ pro nekonečno).\n"
 
-#: src/main.c:581
+#: src/main.c:588
 msgid ""
 "       --delete-after       delete files locally after downloading them.\n"
 msgstr ""
+"       --delete-after       smaže soubory lokálně po té, co dokončí "
+"stahování.\n"
 
-#: src/main.c:583
+#: src/main.c:590
 msgid ""
 "  -k,  --convert-links      make links in downloaded HTML point to local "
 "files.\n"
 msgstr ""
+"  -k,  --convert-links      učiní odkazy v HTML odkazující na místní "
+"soubory.\n"
 
-#: src/main.c:585
+#: src/main.c:592
 msgid ""
 "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
 msgstr ""
+"  -K,  --backup-converted   před konverzí souboru X jej zazálohuje jako X."
+"orig.\n"
 
-#: src/main.c:587
+#: src/main.c:594
 msgid ""
 "  -m,  --mirror             shortcut for -N -r -l inf --no-remove-listing.\n"
 msgstr ""
+"  -m,  --mirror             zkratka pro -N -r -l inf --no-remove-listing.\n"
 
-#: src/main.c:589
+#: src/main.c:596
 msgid ""
 "  -p,  --page-requisites    get all images, etc. needed to display HTML "
 "page.\n"
 msgstr ""
+"  -p,  --page-requisites    získá všechny obrázky apod. potřebné pro\n"
+"                            zobrazení HTML stránky.\n"
 
-#: src/main.c:591
+#: src/main.c:598
 msgid ""
 "       --strict-comments    turn on strict (SGML) handling of HTML "
 "comments.\n"
 msgstr ""
+"       --strict-comments    zapne přísné zacházení s HTML komentáři podle "
+"SGML.\n"
 
-#: src/main.c:595
+#: src/main.c:602
 msgid "Recursive accept/reject:\n"
-msgstr ""
+msgstr "Rekurzivní povolení/zakázání:\n"
 
-#: src/main.c:597
+#: src/main.c:604
 msgid ""
 "  -A,  --accept=LIST               comma-separated list of accepted "
 "extensions.\n"
 msgstr ""
+"  -A,  --accept=SEZNAM             čárkou oddělený seznam povolených "
+"přípon.\n"
 
-#: src/main.c:599
+#: src/main.c:606
 msgid ""
 "  -R,  --reject=LIST               comma-separated list of rejected "
 "extensions.\n"
 msgstr ""
+"  -R,  --reject=SEZNAM             čárkou oddělený seznam zakázaných "
+"přípon.\n"
 
-#: src/main.c:601
+#: src/main.c:608
 msgid ""
 "  -D,  --domains=LIST              comma-separated list of accepted "
 "domains.\n"
 msgstr ""
+"  -D,  --domains=SEZNAM            čárkou oddělený seznam povolených domén.\n"
 
-#: src/main.c:603
+#: src/main.c:610
 msgid ""
 "       --exclude-domains=LIST      comma-separated list of rejected "
 "domains.\n"
 msgstr ""
+"       --exclude-domains=SEZNAM    čárkou oddělený seznam zakázaných domén.\n"
 
-#: src/main.c:605
+#: src/main.c:612
 msgid ""
 "       --follow-ftp                follow FTP links from HTML documents.\n"
 msgstr ""
+"       --follow-ftp                následuje FTP odkazy z HTML dokumentů.\n"
 
-#: src/main.c:607
+#: src/main.c:614
 msgid ""
 "       --follow-tags=LIST          comma-separated list of followed HTML "
 "tags.\n"
 msgstr ""
+"       --follow-tags=SEZNAM        čárkou oddělený seznam HTML značek "
+"určených\n"
+"                                   k následování.\n"
 
-#: src/main.c:609
+#: src/main.c:616
 msgid ""
 "       --ignore-tags=LIST          comma-separated list of ignored HTML "
 "tags.\n"
 msgstr ""
+"       --ignore-tags=SEZNAM        čárkou oddělený seznam ignorovaných\n"
+"                                   HTML značek.\n"
 
-#: src/main.c:611
+#: src/main.c:618
 msgid ""
 "  -H,  --span-hosts                go to foreign hosts when recursive.\n"
 msgstr ""
+"  -H,  --span-hosts                při rekurzi přechází i na jiné počítače.\n"
 
-#: src/main.c:613
+#: src/main.c:620
 msgid "  -L,  --relative                  follow relative links only.\n"
-msgstr ""
+msgstr "  -L,  --relative                  následuje jen relativní odkazy.\n"
 
-#: src/main.c:615
+#: src/main.c:622
 msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
 msgstr ""
+"  -I,  --include-directories=SEZNAM\n"
+"                                   seznam povolených adresářů.\n"
 
-#: src/main.c:617
+#: src/main.c:624
 msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
 msgstr ""
+"  -X,  --exclude-directories=SEZNAM\n"
+"                                   seznam zakázaných adresářů.\n"
 
-#: src/main.c:619
+#: src/main.c:626
 msgid ""
 "  -np, --no-parent                 don't ascend to the parent directory.\n"
-msgstr ""
+msgstr "  -np, --no-parent                 nestoupá do nadřízeného adresáře.\n"
 
-# , fuzzy
-#: src/main.c:623
+#: src/main.c:630
 msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
 msgstr ""
-"Zpr�vy o chyb�ch a n�vrhy na vylep�en� programu zas�lejte na adresu\n"
-"<bug-wget@gnu.org> (pouze anglicky).\n"
-"Koment��e k �esk�mu p�ekladu zas�lejte na adresu <cs@li.org>. \n"
+"Zprávy o chybách a návrhy na vylepšení programu zasílejte na adresu\n"
+"<bug-wget@gnu.org> (pouze anglicky). Komentáře k českému překladu\n"
+"zasílejte na adresu <translation-team-cs@lists.sourceforge.net>.\n"
 
 # , c-format
-#: src/main.c:628
+#: src/main.c:635
 #, c-format
 msgid "GNU Wget %s, a non-interactive network retriever.\n"
-msgstr "GNU Wget %s, program pro neinteraktivn� stahov�n� soubor�.\n"
+msgstr "GNU Wget %s, program pro neinteraktivní stahování souborů.\n"
 
-#: src/main.c:668
+#: src/main.c:675
 msgid "Copyright (C) 2007 Free Software Foundation, Inc.\n"
-msgstr ""
+msgstr "Copyright © 2007 Free Software Foundation, Inc.\n"
 
-#: src/main.c:670
+#: src/main.c:677
 msgid ""
 "License GPLv3+: GNU GPL version 3 or later\n"
 "<http://www.gnu.org/licenses/gpl.html>.\n"
 "This is free software: you are free to change and redistribute it.\n"
 "There is NO WARRANTY, to the extent permitted by law.\n"
 msgstr ""
+"Licence GPLv3+: GNU GPL verze 3 nebo vyšší\n"
+"<http://www.gnu.org/licenses/gpl.html>.\n"
+"Toto je volné programové vybavení: máte právo jej měnit a dále šířit.\n"
+"Není poskytována ŽÁDNÁ ZÁRUKA, jak jen zákon dovoluje.\n"
 
-#: src/main.c:675
-#, fuzzy
+#: src/main.c:682
 msgid ""
 "\n"
 "Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
 msgstr ""
 "\n"
-"P�vodn�m autorem tohto programu je Hrvoje Nik�i� <hniksic@arsdigita.com>.\n"
+"Původním autorem tohoto programu je Hrvoje Nikšić <hniksic@xemacs.org>.\n"
 
-#: src/main.c:677
+#: src/main.c:684
 msgid "Currently maintained by Micah Cowan <micah@cowan.name>.\n"
-msgstr ""
+msgstr "Nyní jej spravuje Micah Cowan <micah@cowan.name>.\n"
 
-# , c-format
-#. #### Something nicer should be printed here -- similar to the
-#. pre-1.5 `--help' page.
-#: src/main.c:724 src/main.c:793 src/main.c:890
+#: src/main.c:731 src/main.c:800 src/main.c:900
 #, c-format
 msgid "Try `%s --help' for more options.\n"
-msgstr "P��kaz `%s --help' vyp��e v�znam platn�ch p�ep�na��.\n"
+msgstr "Příkaz „%s --help“ vypíše další přepínače.\n"
 
-# , c-format
-#: src/main.c:790
+#: src/main.c:797
 #, c-format
 msgid "%s: illegal option -- `-n%c'\n"
-msgstr "%s: nep��pustn� p�ep�na� -- `-n%c'\n"
+msgstr "%s: nepřípustný přepínač – „-n%c“\n"
 
-#: src/main.c:845
+#: src/main.c:855
 #, c-format
 msgid "Can't be verbose and quiet at the same time.\n"
-msgstr "Program nem��e b�t upov�dan� a zitcha najednou.\n"
+msgstr "Program nemůže být upovídaný a zticha zároveň.\n"
 
-#: src/main.c:851
+#: src/main.c:861
 #, c-format
 msgid "Can't timestamp and not clobber old files at the same time.\n"
-msgstr "Nelze pou��vat �asov� raz�tka a nemazat p�itom star� soubory.\n"
+msgstr "Nelze používat časová razítka a nemazat přitom staré soubory.\n"
 
-#: src/main.c:859
+#: src/main.c:869
 #, c-format
 msgid "Cannot specify both --inet4-only and --inet6-only.\n"
-msgstr ""
+msgstr "--inet4-only a --inet6-only nelze zadat najednou.\n"
 
-#: src/main.c:869
+#: src/main.c:879
 #, c-format
 msgid "Cannot specify -r, -p or -N if -O is given.\n"
-msgstr ""
+msgstr "Je-li zadáno -O, nelze současně použí -r, -p nebo -N.\n"
 
-#: src/main.c:877
+#: src/main.c:887
 #, c-format
 msgid "Cannot specify both -k and -O if multiple URLs are given.\n"
-msgstr ""
+msgstr "Je-li zadáno více URL, nelze najednou použít jak -k, tak i -O.\n"
 
-#. No URL specified.
-#: src/main.c:885
+#: src/main.c:895
 #, c-format
 msgid "%s: missing URL\n"
-msgstr "%s: chyb� URL\n"
+msgstr "%s: chybí URL\n"
 
-# , c-format
-#: src/main.c:1005
+#: src/main.c:1021
 #, c-format
 msgid "No URLs found in %s.\n"
-msgstr "V souboru `%s' nebyla nalezena ��dn� URL.\n"
+msgstr "V souboru „%s“ nebyla nalezena žádná URL.\n"
 
-# , c-format
-#: src/main.c:1023
-#, fuzzy, c-format
+#: src/main.c:1039
+#, c-format
 msgid ""
 "FINISHED --%s--\n"
 "Downloaded: %d files, %s in %s (%s)\n"
 msgstr ""
-"\n"
 "KONEC --%s--\n"
-"Celkem na�teno %s bajt� v %d souborech\n"
+"Staženo: %d souborů, %s za %s (%s)\n"
 
-# , c-format
-#: src/main.c:1032
-#, fuzzy, c-format
+#: src/main.c:1048
+#, c-format
 msgid "Download quota of %s EXCEEDED!\n"
-msgstr "P�ekro�en limit objemu ulo�en�ch dat (%s bajt�)!\n"
+msgstr "Kvóta %s na stahování PŘEKROČENA!\n"
 
-#: src/mswindows.c:96
+#: src/mswindows.c:97
 #, c-format
 msgid "Continuing in background.\n"
-msgstr "Program pokra�uje v b�hu na pozad�.\n"
+msgstr "Program pokračuje v běhu na pozadí.\n"
 
-#: src/mswindows.c:289
-#, fuzzy, c-format
+#: src/mswindows.c:290
+#, c-format
 msgid "Continuing in background, pid %lu.\n"
-msgstr "Program pokra�uje v b�hu na pozad�.\n"
+msgstr "Program pokračuje v běhu na pozadí, pid %lu.\n"
 
-# , c-format
-#: src/mswindows.c:291 src/utils.c:326
+#: src/mswindows.c:292 src/utils.c:329
 #, c-format
 msgid "Output will be written to `%s'.\n"
-msgstr "V�stup bude zaps�n do `%s'.\n"
+msgstr "Výstup bude zapsán do „%s“.\n"
 
-#: src/mswindows.c:459 src/mswindows.c:466
+#: src/mswindows.c:460 src/mswindows.c:467
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
-msgstr "%s: Nelze naj�t pou�iteln� ovlada� socket�.\n"
+msgstr "%s: Nelze najít použitelný ovladač soketů.\n"
 
-# , c-format
-#: src/netrc.c:375
+#: src/netrc.c:372
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr ""
-"%s: %s:%d varov�n�: token \"%s\" je uveden je�t� p�ed jak�mkoliv\n"
-"      n�zvem po��ta�e\n"
+"%s: %s:%d varování: token „%s“ je uveden ještě před jakýmkoliv\n"
+"      názvem počítače\n"
 
-# , c-format
-#: src/netrc.c:406
+#: src/netrc.c:403
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
-msgstr "%s: %s:%d: nezn�m� token \"%s\"\n"
+msgstr "%s: %s:%d: neznámý token „%s“\n"
 
-# , c-format
-#: src/netrc.c:470
+#: src/netrc.c:467
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
-msgstr "Pou�it�: %s NETRC [N�ZEV PO��TA�E]\n"
+msgstr "Použití: %s NETRC [NÁZEV POČÍTAČE]\n"
 
-# , c-format
-#: src/netrc.c:480
+#: src/netrc.c:477
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
-msgstr "%s: vol�n� `stat %s' skon�ilo chybou: %s\n"
+msgstr "%s: volání „stat %s“ skončilo chybou: %s\n"
 
-#. Still not random enough, presumably because neither /dev/random
-#. nor EGD were available.  Try to seed OpenSSL's PRNG with libc
-#. PRNG.  This is cryptographically weak and defeats the purpose
-#. of using OpenSSL, which is why it is highly discouraged.
 #: src/openssl.c:112
 msgid "WARNING: using a weak random seed.\n"
-msgstr ""
+msgstr "VAROVÁNÍ: používám slabý zdroj náhodných čísel.\n"
 
 #: src/openssl.c:172
 msgid "Could not seed PRNG; consider using --random-file.\n"
-msgstr ""
+msgstr "PRNG nelze zinicializovat, zvažte použití přepínače --random-file.\n"
 
-#. If the user has specified --no-check-cert, we still want to warn
-#. him about problems with the server's certificate.
 #: src/openssl.c:487
 msgid "ERROR"
-msgstr ""
+msgstr "CHYBA"
 
 #: src/openssl.c:487
 msgid "WARNING"
-msgstr ""
+msgstr "VAROVÁNÍ"
 
 #: src/openssl.c:496
 #, c-format
 msgid "%s: No certificate presented by %s.\n"
-msgstr ""
+msgstr "%s: %s nepředložil žádný certifikát.\n"
 
 #: src/openssl.c:517
 #, c-format
 msgid "%s: cannot verify %s's certificate, issued by `%s':\n"
-msgstr ""
+msgstr "%s: certifikát pro %s vydaný „%s“ nelze ověřit:\n"
 
 #: src/openssl.c:525
 msgid "  Unable to locally verify the issuer's authority.\n"
-msgstr ""
+msgstr "  Autoritu vydavatele nelze lokálně ověřit.\n"
 
 #: src/openssl.c:529
 msgid "  Self-signed certificate encountered.\n"
-msgstr ""
+msgstr "  Nalezen certifikát podepsaný sám sebou.\n"
 
 #: src/openssl.c:532
 msgid "  Issued certificate not yet valid.\n"
-msgstr ""
+msgstr "  Vydaný certifikát ještě nenabyl platnosti.\n"
 
 #: src/openssl.c:535
 msgid "  Issued certificate has expired.\n"
-msgstr ""
+msgstr "  Vydanému certifikátu uplynula doba platnosti.\n"
 
 #: src/openssl.c:567
 #, c-format
 msgid ""
 "%s: certificate common name `%s' doesn't match requested host name `%s'.\n"
 msgstr ""
+"%s: obecné jméno (CN) „%s“ na certifikátu se neshoduje s požadovaným jménem "
+"počítače „%s“.\n"
 
 #: src/openssl.c:580
 #, c-format
 msgid "To connect to %s insecurely, use `--no-check-certificate'.\n"
-msgstr ""
+msgstr "Pro nezabezpečené spojení s %s použijte „--no-check-certificate“.\n"
 
-# , c-format
-#. Align the [ skipping ... ] line with the dots.  To do
-#. that, insert the number of spaces equal to the number of
-#. digits in the skipped amount in K.
 #: src/progress.c:238
-#, fuzzy, c-format
+#, c-format
 msgid ""
 "\n"
 "%*s[ skipping %sK ]"
 msgstr ""
 "\n"
-"          [ p�eskakuje se %dK ]"
+"%*s[ přeskakuje se %s K ]"
 
-# , c-format
 #: src/progress.c:452
-#, fuzzy, c-format
+#, c-format
 msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
-msgstr "%s: Neplatn� specifikace `%s'\n"
+msgstr "„%s“ není platné určení způsobu indikace, ponechávám nezměněno.\n"
 
-#. Translation note: "ETA" is English-centric, but this must
-#. be short, ideally 3 chars.  Abbreviate if necessary.
 #: src/progress.c:946
 #, c-format
 msgid "  eta %s"
-msgstr ""
+msgstr " zbývá %s"
 
-#. When the download is done, print the elapsed time.
-#. Note to translators: this should not take up more room than
-#. available here.  Abbreviate if necessary.
 #: src/progress.c:961
 msgid "   in "
-msgstr ""
+msgstr "   za "
 
-#. If no clock was found, it means that clock_getres failed for
-#. the realtime clock.
-#: src/ptimer.c:160
+#: src/ptimer.c:159
 #, c-format
 msgid "Cannot get REALTIME clock frequency: %s\n"
-msgstr ""
+msgstr "Frekvenci hodin REÁLNÉHO ČASU nelze určit: %s\n"
 
-# , c-format
-#: src/recur.c:377
+#: src/recur.c:378
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
-msgstr "Ma�e se %s, proto�e tento soubor nen� po�adov�n.\n"
+msgstr "Maže se %s, protože tento soubor není požadován.\n"
 
-# , c-format
-#: src/res.c:392
-#, fuzzy, c-format
+#: src/res.c:389
+#, c-format
 msgid "Cannot open %s: %s"
-msgstr "Nelze p�ev�st odkazy v %s: %s\n"
+msgstr "%s nelze otevřít: %s"
 
-#: src/res.c:544
+#: src/res.c:541
 msgid "Loading robots.txt; please ignore errors.\n"
-msgstr "Na��t� se `robots.txt'. Chybov� hl�en� ignorujte, pros�m.\n"
+msgstr "Načítá se „robots.txt“. Chybová hlášení ignorujte, prosím.\n"
 
-# , c-format
 #: src/retr.c:651
-#, fuzzy, c-format
+#, c-format
 msgid "Error parsing proxy URL %s: %s.\n"
-msgstr "P�i z�pisu do `%s' nastala chyba: %s.\n"
+msgstr "Chyba rozebírání URL proxy serveru %s: %s.\n"
 
-# , c-format
 #: src/retr.c:659
-#, fuzzy, c-format
+#, c-format
 msgid "Error in proxy URL %s: Must be HTTP.\n"
-msgstr "Proxy %s: Mus� b�t HTTP.\n"
+msgstr "Chyba v URL Proxy %s: Musí být HTTP.\n"
 
-# , c-format
 #: src/retr.c:745
-#, fuzzy, c-format
+#, c-format
 msgid "%d redirections exceeded.\n"
-msgstr "%s: Detekov�no zacyklen� p�esm�rov�n�.\n"
+msgstr "Překročeno %d přesměrování.\n"
 
 #: src/retr.c:880
 msgid ""
 "Giving up.\n"
 "\n"
 msgstr ""
-"Ani posledn� pokus nebyl �sp�n�.\n"
+"Ani poslední pokus nebyl úspěšný.\n"
 "\n"
 
 #: src/retr.c:880
