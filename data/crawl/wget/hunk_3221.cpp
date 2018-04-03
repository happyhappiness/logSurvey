 # Dutch messages for GNU Wget.
 # Copyright © 1997, 1998 Free Software Foundation, Inc.
 # André van Dijk <ady@unseen.demon.nl>, 1998
+# Dennis Smit <ds@nerds-incorporated.org>, 2003
 #
 msgid ""
 msgstr ""
-"Project-Id-Version: wget 1.7\n"
-"POT-Creation-Date: 2001-06-03 15:27+0200\n"
-"PO-Revision-Date: 2001-11-10 15:29+0200\n"
-"Last-Translator: André van Dijk <ady@unseen.demon.nl>\n"
+"Project-Id-Version: wget 1.9\n"
+"POT-Creation-Date: 2003-11-07 00:52+0100\n"
+"PO-Revision-Date: 2003-11-4 16:29+0200\n"
+"Last-Translator: Dennis Smit <ds@nerds-incorporated.org>\n"
 "Language-Team: Dutch <nl@li.org>\n"
 "MIME-Version: 1.0\n"
 "Content-Type: text/plain; charset=iso-8859-1\n"
 "Content-Transfer-Encoding: 8-bit\n"
 
-#: src/cookies.c:588
+#: src/connect.c:181
+#, c-format
+msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
+msgstr ""
+"%s: gefaald in het oplossen van het bind adres `%s'; bind uitgeschakeld\n"
+
+#: src/connect.c:247
+#, c-format
+msgid "Connecting to %s|%s|:%d... "
+msgstr "Verbinden met %s|%s|:%d... "
+
+#: src/connect.c:249
+#, c-format
+msgid "Connecting to %s:%d... "
+msgstr "Verbinden met %s:%d... "
+
+#: src/connect.c:298
+msgid "connected.\n"
+msgstr "verbonden.\n"
+
+#: src/convert.c:171
+#, c-format
+msgid "Converted %d files in %.2f seconds.\n"
+msgstr "Heeft %d bestanden in %.2f seconden geconverteerd.\n"
+
+#: src/convert.c:197
+#, c-format
+msgid "Converting %s... "
+msgstr "Omzetten %s... "
+
+#: src/convert.c:210
+msgid "nothing to do.\n"
+msgstr "niets te doen.\n"
+
+#: src/convert.c:218 src/convert.c:242
+#, c-format
+msgid "Cannot convert links in %s: %s\n"
+msgstr "Kan verwijzingen niet omzetten naar %s: %s\n"
+
+#: src/convert.c:233
+#, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "Niet in staat `%s': %s te verwijderen\n"
+
+#: src/convert.c:448
+#, c-format
+msgid "Cannot back up %s as %s: %s\n"
+msgstr "Kan %s niet backuppen als %s: %s\n"
+
+#: src/cookies.c:619
 #, c-format
 msgid "Error in Set-Cookie, field `%s'"
 msgstr "Fout in Set-Cookie, veld `%s'"
 
-#: src/cookies.c:612
+#: src/cookies.c:642
 #, c-format
-msgid "Syntax error in Set-Cookie at character `%c'.\n"
-msgstr "Syntaxfout in Set-Cookie bij teken `%c'.\n"
-
-#: src/cookies.c:620
-msgid "Syntax error in Set-Cookie: premature end of string.\n"
-msgstr "Syntaxfout in Set-Cookie: voortijdig einde van string.\n"
+msgid "Syntax error in Set-Cookie: %s at position %d.\n"
+msgstr "Syntax fout in Set-Cookie: %s op plek %d.\n"
 
-#: src/cookies.c:1352
+#: src/cookies.c:1443
 #, c-format
 msgid "Cannot open cookies file `%s': %s\n"
 msgstr "Kan cookiesbestand niet openen `%s': %s\n"
 
-#: src/cookies.c:1364
+#: src/cookies.c:1455
 #, c-format
 msgid "Error writing to `%s': %s\n"
 msgstr "Fout bij schrijven naar `%s': %s\n"
 
-#: src/cookies.c:1368
+#: src/cookies.c:1458
 #, c-format
 msgid "Error closing `%s': %s\n"
 msgstr "Fout bij sluiten `%s': %s\n"
 
-#: src/ftp-ls.c:787
+#: src/ftp-ls.c:812
 msgid "Unsupported listing type, trying Unix listing parser.\n"
 msgstr "Niet ondersteund listingtype, probeer de Unix listing parser.\n"
 
-#: src/ftp-ls.c:832 src/ftp-ls.c:834
+#: src/ftp-ls.c:857 src/ftp-ls.c:859
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Index van /%s op %s:%d"
 
-#: src/ftp-ls.c:856
+#: src/ftp-ls.c:882
 msgid "time unknown       "
 msgstr "tijd onbekend     "
 
-#: src/ftp-ls.c:860
+#: src/ftp-ls.c:886
 msgid "File        "
 msgstr "Bestand     "
 
-#: src/ftp-ls.c:863
+#: src/ftp-ls.c:889
 msgid "Directory   "
 msgstr "Map         "
 
-#: src/ftp-ls.c:866
+#: src/ftp-ls.c:892
 msgid "Link        "
 msgstr "Koppeling   "
 
-#: src/ftp-ls.c:869
+#: src/ftp-ls.c:895
 msgid "Not sure    "
 msgstr "Niet zeker  "
 
-#: src/ftp-ls.c:887
+#: src/ftp-ls.c:913
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s Bytes)"
 
-#. Login to the server:
-#. First: Establish the control connection.
-#: src/ftp.c:150 src/http.c:624
-#, c-format
-msgid "Connecting to %s:%hu... "
-msgstr "Verbinden met %s:%hu... "
-
-#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
-#, c-format
-msgid "Connection to %s:%hu refused.\n"
-msgstr "Verbinding met %s:%hu geweigerd.\n"
-
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:193 src/http.c:652
-msgid "connected!\n"
-msgstr "verbonden!\n"
-
-#: src/ftp.c:194
+#: src/ftp.c:315
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Inloggen als %s ... "
 
 # Ist das gemeint?
-#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
-#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
+#: src/ftp.c:328 src/ftp.c:381 src/ftp.c:412 src/ftp.c:466 src/ftp.c:581
+#: src/ftp.c:632 src/ftp.c:662 src/ftp.c:723 src/ftp.c:792 src/ftp.c:870
+#: src/ftp.c:921
 msgid "Error in server response, closing control connection.\n"
 msgstr "Fout in antwoord server, verbreek besturingsverbinding.\n"
 
-#: src/ftp.c:211
+#: src/ftp.c:336
 msgid "Error in server greeting.\n"
 msgstr "Fout in servergroet.\n"
 
-#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
-#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
+#: src/ftp.c:344 src/ftp.c:475 src/ftp.c:590 src/ftp.c:671 src/ftp.c:734
+#: src/ftp.c:803 src/ftp.c:881 src/ftp.c:932
 msgid "Write failed, closing control connection.\n"
 msgstr "Schrijffout, verbreek besturingsverbinding.\n"
 
-#: src/ftp.c:226
+#: src/ftp.c:351
 msgid "The server refuses login.\n"
 msgstr "De server weigert de login.\n"
 
-#: src/ftp.c:233
+#: src/ftp.c:358
 msgid "Login incorrect.\n"
 msgstr "Login onjuist.\n"
 
-#: src/ftp.c:240
+#: src/ftp.c:365
 msgid "Logged in!\n"
 msgstr "Ingelogd!\n"
 
-#: src/ftp.c:265
+#: src/ftp.c:390
 msgid "Server error, can't determine system type.\n"
 msgstr "Serverfout, kan systeemtype niet bepalen.\n"
 
-#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
+#: src/ftp.c:400 src/ftp.c:710 src/ftp.c:776 src/ftp.c:836
 msgid "done.    "
 msgstr "gereed.    "
 
-#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
+#: src/ftp.c:454 src/ftp.c:611 src/ftp.c:646 src/ftp.c:904 src/ftp.c:955
 msgid "done.\n"
 msgstr "gereed.\n"
 
-#: src/ftp.c:353
+#: src/ftp.c:483
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Onbekend type `%c', verbreek besturingsverbinding.\n"
 
-#: src/ftp.c:366
+#: src/ftp.c:496
 msgid "done.  "
 msgstr "gereed.  "
 
-#: src/ftp.c:372
+#: src/ftp.c:502
 msgid "==> CWD not needed.\n"
 msgstr "-=> CWD onnodig.\n"
 
-#: src/ftp.c:445
+#: src/ftp.c:597
 #, c-format
-msgid "No such directory `%s'.\n\n"
-msgstr "Onbekende directory `%s'.\n\n"
+msgid ""
+"No such directory `%s'.\n"
+"\n"
+msgstr ""
+"Onbekende directory `%s'.\n"
+"\n"
 
 #. do not CWD
-#: src/ftp.c:463
+#: src/ftp.c:615
 msgid "==> CWD not required.\n"
 msgstr "==> CWD niet noodzakelijk.\n"
 
-#: src/ftp.c:497
+#: src/ftp.c:678
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Kan PASV-overdracht niet beginnen.\n"
 
-#: src/ftp.c:501
+#: src/ftp.c:682
 msgid "Cannot parse PASV response.\n"
 msgstr "Kan PASV-antwoord niet ontleden.\n"
 
-#: src/ftp.c:515
+#: src/ftp.c:702
 #, c-format
-msgid "Will try connecting to %s:%hu.\n"
-msgstr "Tracht verbinding met %s:%hu te herstellen.\n"
+msgid "couldn't connect to %s port %hu: %s\n"
+msgstr "kan niet verbinden met %s poort %hu: %s\n"
 
-#: src/ftp.c:602
+#: src/ftp.c:753
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Bindfout (%s).\n"
 
-#: src/ftp.c:618
+#: src/ftp.c:761
 msgid "Invalid PORT.\n"
 msgstr "Ongeldige POORT.\n"
 
-#: src/ftp.c:671
+#: src/ftp.c:817
 #, c-format
-msgid "\nREST failed; will not truncate `%s'.\n"
-msgstr "\nREST gefaald; zal niet afkappen `%s'.\n"
+msgid ""
+"\n"
+"REST failed; will not truncate `%s'.\n"
+msgstr ""
+"\n"
+"REST gefaald; zal niet afkappen `%s'.\n"
 
-#: src/ftp.c:678
-msgid "\nREST failed, starting from scratch.\n"
-msgstr "\nREST gefaald, begin opnieuw.\n"
+#: src/ftp.c:825
+msgid ""
+"\n"
+"REST failed, starting from scratch.\n"
+msgstr ""
+"\n"
+"REST gefaald, begin opnieuw.\n"
 
-#: src/ftp.c:727
+#: src/ftp.c:890
 #, c-format
-msgid "No such file `%s'.\n\n"
-msgstr "Onbekend bestand `%s'.\n\n"
+msgid ""
+"No such file `%s'.\n"
+"\n"
+msgstr ""
+"Onbekend bestand `%s'.\n"
+"\n"
 
-#: src/ftp.c:775
+#: src/ftp.c:941
 #, c-format
-msgid "No such file or directory `%s'.\n\n"
-msgstr "Onbekend bestand of directory `%s'.\n\n"
+msgid ""
+"No such file or directory `%s'.\n"
+"\n"
+msgstr ""
+"Onbekend bestand of directory `%s'.\n"
+"\n"
 
-#: src/ftp.c:859 src/ftp.c:867
+#: src/ftp.c:1027 src/ftp.c:1035
 #, c-format
 msgid "Length: %s"
 msgstr "Lengte: %s"
 
-#: src/ftp.c:861 src/ftp.c:869
+#: src/ftp.c:1029 src/ftp.c:1037
 #, c-format
 msgid " [%s to go]"
 msgstr " [nog %s]"
 
 # Geen idee hoe dit correct te vertalen
-#: src/ftp.c:871
+#: src/ftp.c:1039
 msgid " (unauthoritative)\n"
 msgstr " (onauthoritatief)\n"
 
-#: src/ftp.c:898
+#: src/ftp.c:1067
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, verbreek besturingsverbinding.\n"
 
-#: src/ftp.c:906
+#: src/ftp.c:1075
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - Gegevensverbinding: %s; "
 
-#: src/ftp.c:923
+#: src/ftp.c:1092
 msgid "Control connection closed.\n"
 msgstr "Besturingsverbinding verbroken.\n"
 
-#: src/ftp.c:941
+#: src/ftp.c:1110
 msgid "Data transfer aborted.\n"
 msgstr "Gegevensoverdracht afgebroken.\n"
 
-#: src/ftp.c:1005
+#: src/ftp.c:1175
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "Bestand `%s' reeds aanwezig, niet ophalen.\n"
 
-#: src/ftp.c:1075 src/http.c:1502
+#: src/ftp.c:1245 src/http.c:1618
 #, c-format
 msgid "(try:%2d)"
 msgstr "(poging:%2d)"
 
-#: src/ftp.c:1139 src/http.c:1753
+#: src/ftp.c:1311 src/http.c:1877
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld]\n\n"
-msgstr "%s (%s) - `%s' bewaard [%ld]\n\n"
+msgid ""
+"%s (%s) - `%s' saved [%ld]\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' bewaard [%ld]\n"
+"\n"
 
-#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
+#: src/ftp.c:1353 src/main.c:894 src/recur.c:376 src/retr.c:593
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Verwijder `%s'.\n"
 
-#: src/ftp.c:1221
+#: src/ftp.c:1395
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Aanroep `%s' als tijdelijk lijstbestand.\n"
 
-#: src/ftp.c:1233
+#: src/ftp.c:1410
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "Verwijderd `%s'.\n"
 
-#: src/ftp.c:1269
+#: src/ftp.c:1445
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "De recursiediepte %d overschreed de maximum diepte %d.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1330
+#: src/ftp.c:1515
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
 msgstr "Serverbestand niet nieuwer dan lokaal bestand `%s' -- niet ophalen.\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1337
+#: src/ftp.c:1522
 #, c-format
-msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
-msgstr "Serverbestand nieuwer dan lokaal bestand `%s' -- ophalen.\n\n"
+msgid ""
+"Remote file is newer than local file `%s' -- retrieving.\n"
+"\n"
+msgstr ""
+"Serverbestand nieuwer dan lokaal bestand `%s' -- ophalen.\n"
+"\n"
 
 #. Sizes do not match
-#: src/ftp.c:1344
+#: src/ftp.c:1529
 #, c-format
-msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
-msgstr "Groottes komen niet overeen (lokaal %ld) -- ophalen.\n\n"
+msgid ""
+"The sizes do not match (local %ld) -- retrieving.\n"
+"\n"
+msgstr ""
+"Groottes komen niet overeen (lokaal %ld) -- ophalen.\n"
+"\n"
 
-#: src/ftp.c:1361
+#: src/ftp.c:1546
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Ongeldige naam voor een symbolische koppeling, overslaan.\n"
 
-#: src/ftp.c:1378
+#: src/ftp.c:1563
 #, c-format
-msgid "Already have correct symlink %s -> %s\n\n"
+msgid ""
+"Already have correct symlink %s -> %s\n"
+"\n"
 msgstr "Juiste symbolische koppeling bestaat reeds %s -> %s\n"
 
-#: src/ftp.c:1386
+#: src/ftp.c:1571
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Maak symbolische koppeling %s -> %s\n"
 
-#: src/ftp.c:1397
+#: src/ftp.c:1582
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr "Symbolische koppelingen niet ondersteund, symbolische koppeling overslaan `%s'.\n"
+msgstr ""
+"Symbolische koppelingen niet ondersteund, symbolische koppeling overslaan`%"
+"s'.\n"
 
-#: src/ftp.c:1409
+#: src/ftp.c:1594
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Directory overslaan `%s'.\n"
 
-#: src/ftp.c:1418
+#: src/ftp.c:1603
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: onbekend/niet-ondersteund bestandstype.\n"
 
-#: src/ftp.c:1445
+#: src/ftp.c:1630
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: beschadigd tijdstempel.\n"
 
-#: src/ftp.c:1466
+#: src/ftp.c:1658
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Mappen worden niet opgehaald, omdat diepte %d is (max %d).\n"
 
-#: src/ftp.c:1512
+#: src/ftp.c:1708
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "Daal niet af naar `%s', omdat het uitgesloten/niet-ingesloten is.\n"
 
-#: src/ftp.c:1559
+#: src/ftp.c:1772 src/ftp.c:1785
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "`%s' afgewezen.\n"
