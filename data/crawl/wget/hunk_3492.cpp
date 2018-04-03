 msgid " (%s bytes)"
 msgstr " (%s byte) "
 
-#. Login to the server:
-#. First: Establish the control connection.
-#: src/ftp.c:150 src/http.c:624
-#, c-format
-msgid "Connecting to %s:%hu... "
-msgstr "Ansluter till %s:%hu... "
-
-#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
-#, c-format
-msgid "Connection to %s:%hu refused.\n"
-msgstr "Anslutning till %s:%hu vägras.\n"
-
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:193 src/http.c:652
-msgid "connected!\n"
-msgstr "ansluten!\n"
-
-#: src/ftp.c:194
+#: src/ftp.c:187
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Loggar in som %s... "
 
-#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
-#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
+#: src/ftp.c:196 src/ftp.c:249 src/ftp.c:281 src/ftp.c:330 src/ftp.c:423
+#: src/ftp.c:474 src/ftp.c:504 src/ftp.c:568 src/ftp.c:641 src/ftp.c:702
+#: src/ftp.c:750
 msgid "Error in server response, closing control connection.\n"
 msgstr "Fel i serversvar, stänger styrförbindelse.\n"
 
-#: src/ftp.c:211
+#: src/ftp.c:204
 msgid "Error in server greeting.\n"
 msgstr "Fel i serverhälsning.\n"
 
-#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
-#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
+#: src/ftp.c:212 src/ftp.c:339 src/ftp.c:432 src/ftp.c:513 src/ftp.c:578
+#: src/ftp.c:651 src/ftp.c:712 src/ftp.c:760
 msgid "Write failed, closing control connection.\n"
 msgstr "Skrivning misslyckades, stänger styrförbindelse.\n"
 
-#: src/ftp.c:226
+#: src/ftp.c:219
 msgid "The server refuses login.\n"
 msgstr "Inloggning nekas av servern.\n"
 
-#: src/ftp.c:233
+#: src/ftp.c:226
 msgid "Login incorrect.\n"
 msgstr "Felaktig inloggning.\n"
 
-#: src/ftp.c:240
+#: src/ftp.c:233
 msgid "Logged in!\n"
 msgstr "Inloggad!\n"
 
-#: src/ftp.c:265
+#: src/ftp.c:258
 msgid "Server error, can't determine system type.\n"
 msgstr "Serverfel, kan inte avgöra systemtyp.\n"
 
-#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
+#: src/ftp.c:268 src/ftp.c:553 src/ftp.c:625 src/ftp.c:682
 msgid "done.    "
 msgstr "färdig.  "
 
-#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
+#: src/ftp.c:318 src/ftp.c:453 src/ftp.c:488 src/ftp.c:733 src/ftp.c:781
+#: src/host.c:263
 msgid "done.\n"
 msgstr "färdig.\n"
 
-#: src/ftp.c:353
+#: src/ftp.c:347
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Typen \"%c\" är okänd, stänger styrförbindelse.\n"
 
-#: src/ftp.c:366
+#: src/ftp.c:360
 msgid "done.  "
 msgstr "färdig.  "
 
-#: src/ftp.c:372
+#: src/ftp.c:366
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD behövs inte.\n"
 
-#: src/ftp.c:445
+#: src/ftp.c:439
 #, c-format
 msgid "No such directory `%s'.\n\n"
 msgstr "Katalogen \"%s\" finns inte.\n\n"
 
 #. do not CWD
-#: src/ftp.c:463
+#: src/ftp.c:457
 msgid "==> CWD not required.\n"
 msgstr "==> CWD krävs inte.\n"
 
-#: src/ftp.c:497
+#: src/ftp.c:520
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Kan inte initiera PASV-överföring.\n"
 
-#: src/ftp.c:501
+#: src/ftp.c:524
 msgid "Cannot parse PASV response.\n"
 msgstr "Kan inte tolka PASV-svar.\n"
 
-#: src/ftp.c:515
+#: src/ftp.c:545
 #, c-format
-msgid "Will try connecting to %s:%hu.\n"
-msgstr "Försöker ansluta till %s:%hu.\n"
+msgid "couldn't connect to %s:%hu: %s\n"
+msgstr "kunde inte ansluta till %s:%hu: %s\n"
 
-#: src/ftp.c:602
+#: src/ftp.c:595
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Bindningsfel (%s).\n"
 
-#: src/ftp.c:618
+#: src/ftp.c:611
 msgid "Invalid PORT.\n"
 msgstr "Felaktig PORT.\n"
 
-#: src/ftp.c:671
+#: src/ftp.c:664
 #, c-format
 msgid "\nREST failed; will not truncate `%s'.\n"
 msgstr "\nREST misslyckades, kommer inte att klippa \"%s\".\n"
 
-#: src/ftp.c:678
+#: src/ftp.c:671
 msgid "\nREST failed, starting from scratch.\n"
 msgstr "\nREST misslyckades, startar om från början.\n"
 
-#: src/ftp.c:727
+#: src/ftp.c:720
 #, c-format
 msgid "No such file `%s'.\n\n"
 msgstr "Filen \"%s\" finns inte.\n\n"
 
-#: src/ftp.c:775
+#: src/ftp.c:768
 #, c-format
 msgid "No such file or directory `%s'.\n\n"
 msgstr "Filen eller katalogen \"%s\" finns inte.\n\n"
 
-#: src/ftp.c:859 src/ftp.c:867
+#: src/ftp.c:852 src/ftp.c:860
 #, c-format
 msgid "Length: %s"
 msgstr "Längd: %s"
 
-#: src/ftp.c:861 src/ftp.c:869
+#: src/ftp.c:854 src/ftp.c:862
 #, c-format
 msgid " [%s to go]"
 msgstr " [%s kvar]"
 
-#: src/ftp.c:871
+#: src/ftp.c:864
 msgid " (unauthoritative)\n"
 msgstr " (ej auktoritativt)\n"
 
-#: src/ftp.c:898
+#: src/ftp.c:890
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, stänger styrförbindelse.\n"
 
-#: src/ftp.c:906
+#: src/ftp.c:898
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - Dataförbindelse: %s; "
 
-#: src/ftp.c:923
+#: src/ftp.c:915
 msgid "Control connection closed.\n"
 msgstr "Styrförbindelse stängd.\n"
 
-#: src/ftp.c:941
+#: src/ftp.c:933
 msgid "Data transfer aborted.\n"
 msgstr "Dataöverföring avbruten.\n"
 
-#: src/ftp.c:1005
+#: src/ftp.c:997
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "Filen \"%s\" finns redan, hämtar inte.\n"
 
-#: src/ftp.c:1075 src/http.c:1502
+#: src/ftp.c:1067 src/http.c:1538
 #, c-format
 msgid "(try:%2d)"
 msgstr "(försök:%2d)"
 
-#: src/ftp.c:1139 src/http.c:1753
+#: src/ftp.c:1131 src/http.c:1797
 #, c-format
 msgid "%s (%s) - `%s' saved [%ld]\n\n"
 msgstr "%s (%s) - \"%s\" sparad [%ld]\n\n"
 
-#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
+#: src/ftp.c:1173 src/main.c:814 src/recur.c:336 src/retr.c:587
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Tar bort %s.\n"
 
-#: src/ftp.c:1221
+#: src/ftp.c:1215
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Använder \"%s\" som temporär listningsfil.\n"
 
-#: src/ftp.c:1233
+#: src/ftp.c:1230
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "Tog bort \"%s\".\n"
 
-#: src/ftp.c:1269
+#: src/ftp.c:1265
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "Rekursionsdjupet %d överskred det maximala djupet %d.\n"
