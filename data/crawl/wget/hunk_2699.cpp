 "Content-Type: text/plain; charset=iso-8859-2\n"
 "Content-Transfer-Encoding: 8-bit\n"
 
-#: src/connect.c:199
-#, c-format
-msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
-msgstr ""
-
-# , c-format
-#: src/connect.c:271
-#, fuzzy, c-format
-msgid "Connecting to %s|%s|:%d... "
-msgstr "Navazuje se spojení s %s:%hu... "
-
-# , c-format
-#: src/connect.c:274
-#, fuzzy, c-format
-msgid "Connecting to %s:%d... "
-msgstr "Navazuje se spojení s %s:%hu... "
-
-#: src/connect.c:335
-#, fuzzy
-msgid "connected.\n"
-msgstr "spojeno!\n"
-
-#: src/convert.c:176
-#, c-format
-msgid "Converted %d files in %.*f seconds.\n"
-msgstr ""
-
-# , c-format
-#: src/convert.c:202
-#, c-format
-msgid "Converting %s... "
-msgstr "Pøevádí se %s... "
-
-#: src/convert.c:215
-msgid "nothing to do.\n"
-msgstr "nic není potøeba pøevádìt.\n"
-
-# , c-format
-#: src/convert.c:223 src/convert.c:247
-#, c-format
-msgid "Cannot convert links in %s: %s\n"
-msgstr "Nelze pøevést odkazy v %s: %s\n"
-
-# , c-format
-#: src/convert.c:238
-#, c-format
-msgid "Unable to delete `%s': %s\n"
-msgstr "Nebylo mo¾né odstranit `%s': %s\n"
-
-# , c-format
-#: src/convert.c:447
-#, c-format
-msgid "Cannot back up %s as %s: %s\n"
-msgstr "Nelze zálohovat %s jako %s: %s\n"
-
-#: src/cookies.c:619
+#: src/cookies.c:588
 #, c-format
 msgid "Error in Set-Cookie, field `%s'"
 msgstr "Chyba v hlavièce Set-Cookie v poli `%s'"
 
-#: src/cookies.c:643
-#, fuzzy, c-format
-msgid "Syntax error in Set-Cookie: %s at position %d.\n"
+#: src/cookies.c:612
+#, c-format
+msgid "Syntax error in Set-Cookie at character `%c'.\n"
+msgstr "Syntaktická chyba v hlavièce Set-Cookie na znaku `%c'.\n"
+
+#: src/cookies.c:620
+msgid "Syntax error in Set-Cookie: premature end of string.\n"
 msgstr "Syntaktická chyba v hlavièce Set-Cookie: Pøedèasný konec øetìzce.\n"
 
 # , c-format
-#: src/cookies.c:1469
+#: src/cookies.c:1352
 #, c-format
 msgid "Cannot open cookies file `%s': %s\n"
 msgstr "Nelze otevøít soubor s koláèky `%s': %s\n"
 
 # , c-format
-#: src/cookies.c:1481
+#: src/cookies.c:1364
 #, c-format
 msgid "Error writing to `%s': %s\n"
 msgstr "Pøi zápisu do `%s' nastala chyba: %s.\n"
 
-#: src/cookies.c:1484
+#: src/cookies.c:1368
 #, c-format
 msgid "Error closing `%s': %s\n"
 msgstr "Pøi uzavírání `%s' nastala chyba: %s\n"
 
-#: src/ftp-ls.c:841
+#: src/ftp-ls.c:787
 msgid "Unsupported listing type, trying Unix listing parser.\n"
 msgstr "Nepodporovaný typ výpisu, pou¾ije se Unixový parser.\n"
 
 # , c-format
-#: src/ftp-ls.c:887 src/ftp-ls.c:889
+#: src/ftp-ls.c:832 src/ftp-ls.c:834
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Obsah /%s na %s:%d"
 
-#: src/ftp-ls.c:912
-#, c-format
+#: src/ftp-ls.c:856
 msgid "time unknown       "
 msgstr "èas neznámý        "
 
-#: src/ftp-ls.c:916
-#, c-format
+#: src/ftp-ls.c:860
 msgid "File        "
 msgstr "Soubor      "
 
-#: src/ftp-ls.c:919
-#, c-format
+#: src/ftp-ls.c:863
 msgid "Directory   "
 msgstr "Adresáø     "
 
-#: src/ftp-ls.c:922
-#, c-format
+#: src/ftp-ls.c:866
 msgid "Link        "
 msgstr "Sym. odkaz  "
 
-#: src/ftp-ls.c:925
-#, c-format
+#: src/ftp-ls.c:869
 msgid "Not sure    "
 msgstr "Neznámý typ "
 
 # , c-format
-#: src/ftp-ls.c:943
+#: src/ftp-ls.c:887
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s bajtù)"
 
 # , c-format
-#: src/ftp.c:226
-#, c-format
-msgid "Length: %s"
-msgstr "Délka: %s"
-
-#: src/ftp.c:232 src/http.c:1857
+#. Login to the server:
+#. First: Establish the control connection.
+#: src/ftp.c:150 src/http.c:624
 #, c-format
-msgid ", %s (%s) remaining"
-msgstr ""
+msgid "Connecting to %s:%hu... "
+msgstr "Navazuje se spojení s %s:%hu... "
 
-#: src/ftp.c:236 src/http.c:1861
+# , c-format
+#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
 #, c-format
-msgid ", %s remaining"
-msgstr ""
+msgid "Connection to %s:%hu refused.\n"
+msgstr "Spojení s %s:%hu odmítnuto.\n"
 
-#: src/ftp.c:239
-msgid " (unauthoritative)\n"
-msgstr " (není smìrodatné)\n"
+#. Second: Login with proper USER/PASS sequence.
+#: src/ftp.c:193 src/http.c:652
+msgid "connected!\n"
+msgstr "spojeno!\n"
 
 # , c-format
-#. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:314
+#: src/ftp.c:194
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Probíhá pøihla¹ování jako %s ... "
 
-#: src/ftp.c:327 src/ftp.c:373 src/ftp.c:402 src/ftp.c:454 src/ftp.c:566
-#: src/ftp.c:612 src/ftp.c:640 src/ftp.c:698 src/ftp.c:759 src/ftp.c:819
-#: src/ftp.c:866
+#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
+#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
 msgid "Error in server response, closing control connection.\n"
-msgstr ""
-"Øídicí spojení bude ukonèeno, proto¾e server odpovìdìl chybovým hlá¹ením.\n"
+msgstr "Øídicí spojení bude ukonèeno, proto¾e server odpovìdìl chybovým hlá¹ením.\n"
 
-#: src/ftp.c:334
+#: src/ftp.c:211
 msgid "Error in server greeting.\n"
 msgstr "Úvodní odpovìï serveru je chybná.\n"
 
-#: src/ftp.c:341 src/ftp.c:462 src/ftp.c:574 src/ftp.c:648 src/ftp.c:708
-#: src/ftp.c:769 src/ftp.c:829 src/ftp.c:876
+#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
+#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
 msgid "Write failed, closing control connection.\n"
 msgstr "Rídicí spojení bude ukonèeno, proto¾e nelze zapsat data.\n"
 
-#: src/ftp.c:347
+#: src/ftp.c:226
 msgid "The server refuses login.\n"
 msgstr "Server odmítá pøihlá¹ení.\n"
 
-#: src/ftp.c:353
+#: src/ftp.c:233
 msgid "Login incorrect.\n"
 msgstr "Chyba pøi pøihlá¹ení.\n"
 
-#: src/ftp.c:359
+#: src/ftp.c:240
 msgid "Logged in!\n"
 msgstr "Pøihlá¹eno!\n"
 
-#: src/ftp.c:381
+#: src/ftp.c:265
 msgid "Server error, can't determine system type.\n"
-msgstr ""
-"Nelze zjistit typ vzdáleného operaèního systému, proto¾e server odpovìdìl "
-"chybovým hlá¹ením.\n"
+msgstr "Nelze zjistit typ vzdáleného operaèního systému, proto¾e server odpovìdìl chybovým hlá¹ením.\n"
 
-#: src/ftp.c:390 src/ftp.c:685 src/ftp.c:742 src/ftp.c:785
+#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
 msgid "done.    "
 msgstr "hotovo.  "
 
-#: src/ftp.c:442 src/ftp.c:591 src/ftp.c:624 src/ftp.c:849 src/ftp.c:895
+#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
 msgid "done.\n"
 msgstr "hotovo.\n"
 
 # , c-format
-#: src/ftp.c:469
+#: src/ftp.c:353
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
-msgstr ""
-"Rídicí spojení bude ukonèeno, proto¾e je po¾adován neznámý typ pøenosu `%"
-"c'.\n"
+msgstr "Rídicí spojení bude ukonèeno, proto¾e je po¾adován neznámý typ pøenosu `%c'.\n"
 
-#: src/ftp.c:481
+#: src/ftp.c:366
 msgid "done.  "
 msgstr "hotovo."
 
-#: src/ftp.c:487
+#: src/ftp.c:372
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD není potøeba.\n"
 
 # , c-format
-#: src/ftp.c:580
+#: src/ftp.c:445
 #, c-format
-msgid ""
-"No such directory `%s'.\n"
-"\n"
-msgstr ""
-"Adresáø `%s' neexistuje.\n"
-"\n"
+msgid "No such directory `%s'.\n\n"
+msgstr "Adresáø `%s' neexistuje.\n\n"
 
 #. do not CWD
-#: src/ftp.c:595
+#: src/ftp.c:463
 msgid "==> CWD not required.\n"
 msgstr "==> CWD není potøeba.\n"
 
-#: src/ftp.c:654
+#: src/ftp.c:497
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Nelze spustit pasivní pøenos dat.\n"
 
-#: src/ftp.c:658
+#: src/ftp.c:501
 msgid "Cannot parse PASV response.\n"
 msgstr "Odpovìï na PASV není pochopitelná.\n"
 
-#: src/ftp.c:676
+# , c-format
+#: src/ftp.c:515
 #, c-format
-msgid "couldn't connect to %s port %d: %s\n"
-msgstr ""
+msgid "Will try connecting to %s:%hu.\n"
+msgstr "Program se pokusí spojit s %s:%hu.\n"
 
 # , c-format
-#: src/ftp.c:724
+#: src/ftp.c:602
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Chyba pøi operaci \"bind\" (%s).\n"
 
-#: src/ftp.c:730
+#: src/ftp.c:618
 msgid "Invalid PORT.\n"
 msgstr "Neplatný PORT.\n"
 
-#: src/ftp.c:776
-msgid ""
-"\n"
-"REST failed, starting from scratch.\n"
-msgstr ""
-"\n"
-"Pøíkaz REST selhal, pøenos zaène od zaèátku souboru.\n"
+#: src/ftp.c:671
+#, c-format
+msgid "\nREST failed; will not truncate `%s'.\n"
+msgstr "\nPøíkaz REST selhal, `%s' nebude zkráceno.\n"
+
+#: src/ftp.c:678
+msgid "\nREST failed, starting from scratch.\n"
+msgstr "\nPøíkaz REST selhal, pøenos zaène od zaèátku souboru.\n"
 
 # , c-format
-#: src/ftp.c:837
+#: src/ftp.c:727
 #, c-format
-msgid ""
-"No such file `%s'.\n"
-"\n"
-msgstr ""
-"Soubor `%s' neexistuje.\n"
-"\n"
+msgid "No such file `%s'.\n\n"
+msgstr "Soubor `%s' neexistuje.\n\n"
 
 # , c-format
-#: src/ftp.c:884
+#: src/ftp.c:775
 #, c-format
-msgid ""
-"No such file or directory `%s'.\n"
-"\n"
-msgstr ""
-"Soubor èi adresáø `%s' neexistuje.\n"
-"\n"
+msgid "No such file or directory `%s'.\n\n"
+msgstr "Soubor èi adresáø `%s' neexistuje.\n\n"
 
-#. We cannot just invent a new name and use it (which is
-#. what functions like unique_create typically do)
-#. because we told the user we'd use this name.
-#. Instead, return and retry the download.
-#: src/ftp.c:946 src/http.c:1913
+# , c-format
+#: src/ftp.c:859 src/ftp.c:867
 #, c-format
-msgid "%s has sprung into existence.\n"
-msgstr ""
+msgid "Length: %s"
+msgstr "Délka: %s"
 
 # , c-format
-#: src/ftp.c:1008
+#: src/ftp.c:861 src/ftp.c:869
+#, c-format
+msgid " [%s to go]"
+msgstr " [%s zbývá]"
+
+#: src/ftp.c:871
+msgid " (unauthoritative)\n"
+msgstr " (není smìrodatné)\n"
+
+# , c-format
+#: src/ftp.c:898
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, øídicí spojení bude ukonèeno.\n"
 
 # , c-format
-#: src/ftp.c:1016
+#: src/ftp.c:906
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - Datové spojení: %s; "
 
-#: src/ftp.c:1031
+#: src/ftp.c:923
 msgid "Control connection closed.\n"
 msgstr "Øídicí spojení bylo ukonèeno.\n"
 
-#: src/ftp.c:1049
+#: src/ftp.c:941
 msgid "Data transfer aborted.\n"
 msgstr "Pøenos dat byl pøedèasnì ukonèen.\n"
 
 # , c-format
-#: src/ftp.c:1114
+#: src/ftp.c:1005
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "Soubor `%s' je ji¾ zde a není jej tøeba pøená¹et.\n"
 
 # , c-format
-#: src/ftp.c:1182 src/http.c:2130
+#: src/ftp.c:1075 src/http.c:1502
 #, c-format
 msgid "(try:%2d)"
 msgstr "(pokus:%2d)"
 
 # , c-format
-#: src/ftp.c:1252 src/http.c:2409
-#, fuzzy, c-format
-msgid ""
-"%s (%s) - `%s' saved [%s]\n"
-"\n"
-msgstr ""
-"%s (%s) - `%s' ulo¾en [%ld]\n"
-"\n"
+#: src/ftp.c:1139 src/http.c:1753
+#, c-format
+msgid "%s (%s) - `%s' saved [%ld]\n\n"
+msgstr "%s (%s) - `%s' ulo¾en [%ld]\n\n"
 
 # , c-format
-#: src/ftp.c:1294 src/main.c:948 src/recur.c:376 src/retr.c:842
+#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Ma¾e se %s.\n"
 
 # , c-format
-#: src/ftp.c:1336
+#: src/ftp.c:1221
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Seznam souborù bude doèasnì ulo¾en v `%s'.\n"
 
 # , c-format
-#: src/ftp.c:1351
+#: src/ftp.c:1233
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "Soubor `%s' byl vymazán.\n"
 
 # , c-format
-#: src/ftp.c:1386
+#: src/ftp.c:1269
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "Hloubka rekurze %d pøekroèila maximální hloubku %d.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1456
+#: src/ftp.c:1330
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
-msgstr ""
-"Vzdálený soubor není novìj¹í, ne¾ lokální soubor `%s', a není jej tøeba "
-"stahovat.\n"
+msgstr "Vzdálený soubor není novìj¹í, ne¾ lokální soubor `%s', a není jej tøeba stahovat.\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1463
+#: src/ftp.c:1337
 #, c-format
-msgid ""
-"Remote file is newer than local file `%s' -- retrieving.\n"
-"\n"
-msgstr ""
-"Vzdálený soubor je novìj¹í, ne¾ lokální soubor `%s', a je jej tøeba "
-"stáhnout.\n"
-"\n"
+msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
+msgstr "Vzdálený soubor je novìj¹í, ne¾ lokální soubor `%s', a je jej tøeba stáhnout.\n\n"
 
 # , c-format
 #. Sizes do not match
-#: src/ftp.c:1470
-#, fuzzy, c-format
-msgid ""
-"The sizes do not match (local %s) -- retrieving.\n"
-"\n"
-msgstr ""
-"Velikosti se neshodují (lokálnì %ld), soubor je tøeba stáhnout.\n"
-"\n"
+#: src/ftp.c:1344
+#, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
+msgstr "Velikosti se neshodují (lokálnì %ld), soubor je tøeba stáhnout.\n\n"
 
-#: src/ftp.c:1488
+#: src/ftp.c:1361
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Pøeskakuje se symbolický odkaz, nebo» název odkazu není platný.\n"
 
 # , c-format
-#: src/ftp.c:1505
+#: src/ftp.c:1378
 #, c-format
-msgid ""
-"Already have correct symlink %s -> %s\n"
-"\n"
-msgstr ""
-"Korektní symbolický odkaz %s -> %s ji¾ existuje.\n"
-"\n"
+msgid "Already have correct symlink %s -> %s\n\n"
+msgstr "Korektní symbolický odkaz %s -> %s ji¾ existuje.\n\n"
 
 # , c-format
-#: src/ftp.c:1513
+#: src/ftp.c:1386
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Vytváøí se symbolický odkaz %s -> %s\n"
 
 # , c-format
-#: src/ftp.c:1523
+#: src/ftp.c:1397
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr ""
-"Symbolický odkaz `%s' bude vynechán, proto¾e systém symbolické odkazy "
-"nepodporuje.\n"
+msgstr "Symbolický odkaz `%s' bude vynechán, proto¾e systém symbolické odkazy nepodporuje.\n"
 
 # , c-format
-#: src/ftp.c:1535
+#: src/ftp.c:1409
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Adresáø `%s' bude vynechán.\n"
 
 # , c-format
-#: src/ftp.c:1544
+#: src/ftp.c:1418
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: neznámý/nepodporovaný typ souboru.\n"
 
 # , c-format
-#: src/ftp.c:1571
+#: src/ftp.c:1445
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: èasové razítko souboru je poru¹ené.\n"
 
 # , c-format
-#: src/ftp.c:1599
+#: src/ftp.c:1466
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
-msgstr ""
-"Podadresáøe se nebudou pøená¹et, proto¾e ji¾ bylo dosa¾eno hloubky %d "
-"(maximum je %d).\n"
+msgstr "Podadresáøe se nebudou pøená¹et, proto¾e ji¾ bylo dosa¾eno hloubky %d (maximum je %d).\n"
 
 # , c-format
-#: src/ftp.c:1649
+#: src/ftp.c:1512
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr ""
-"Do adresáøe `%s' se nesetupuje, proto¾e tento adresáø se buï má vynechat "
-"nebo\n"
+"Do adresáøe `%s' se nesetupuje, proto¾e tento adresáø se buï má vynechat nebo\n"
 "nebyl zadán k procházení.\n"
 
 # , c-format
-#: src/ftp.c:1715 src/ftp.c:1729
+#: src/ftp.c:1559
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Soubor `%s' se nemá stahovat.\n"
