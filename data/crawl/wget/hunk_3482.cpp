 #     ... Kontroll-Verbindung wird geschlossen
 # oder
 #     ... Schließen der Kontroll-Verbindung
-#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
-#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
+#: src/ftp.c:196 src/ftp.c:249 src/ftp.c:281 src/ftp.c:330 src/ftp.c:423
+#: src/ftp.c:474 src/ftp.c:504 src/ftp.c:568 src/ftp.c:641 src/ftp.c:702
+#: src/ftp.c:750
 msgid "Error in server response, closing control connection.\n"
 msgstr "Fehler in der Antwort des Servers; schließe Kontroll-Verbindung.\n"
 
-#: src/ftp.c:211
+#: src/ftp.c:204
 msgid "Error in server greeting.\n"
 msgstr "Fehler bei der Begrüßung des Servers.\n"
 
-#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
-#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
+#: src/ftp.c:212 src/ftp.c:339 src/ftp.c:432 src/ftp.c:513 src/ftp.c:578
+#: src/ftp.c:651 src/ftp.c:712 src/ftp.c:760
 msgid "Write failed, closing control connection.\n"
 msgstr "Schreiben schlug fehl; Kontroll-Verbindung schließen.\n"
 
-#: src/ftp.c:226
+#: src/ftp.c:219
 msgid "The server refuses login.\n"
 msgstr "Der Server verweigert die Anmeldung.\n"
 
-#: src/ftp.c:233
+#: src/ftp.c:226
 msgid "Login incorrect.\n"
 msgstr "Fehler bei der Anmeldung.\n"
 
-#: src/ftp.c:240
+#: src/ftp.c:233
 msgid "Logged in!\n"
 msgstr "Angemeldet!\n"
 
-#: src/ftp.c:265
+#: src/ftp.c:258
 msgid "Server error, can't determine system type.\n"
 msgstr "Fehler beim Server; es ist nicht möglich, die Art des Systems festzustellen.\n"
 
-#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
+#: src/ftp.c:268 src/ftp.c:553 src/ftp.c:625 src/ftp.c:682
 msgid "done.    "
 msgstr "fertig.    "
 
-#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
+#: src/ftp.c:318 src/ftp.c:453 src/ftp.c:488 src/ftp.c:733 src/ftp.c:781
+#: src/host.c:263
 msgid "done.\n"
 msgstr "fertig.\n"
 
-#: src/ftp.c:353
+#: src/ftp.c:347
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Unbekannte Art »%c«, schließe Kontroll-Verbindung.\n"
 
-#: src/ftp.c:366
+#: src/ftp.c:360
 msgid "done.  "
 msgstr "fertig.  "
 
-#: src/ftp.c:372
+#: src/ftp.c:366
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD nicht notwendig.\n"
 
-#: src/ftp.c:445
+#: src/ftp.c:439
 #, c-format
 msgid "No such directory `%s'.\n\n"
 msgstr "Das Verzeichnis »%s« gibt es nicht.\n\n"
 
 #. do not CWD
-#: src/ftp.c:463
+#: src/ftp.c:457
 msgid "==> CWD not required.\n"
 msgstr "==> CWD nicht erforderlich.\n"
 
-#: src/ftp.c:497
+#: src/ftp.c:520
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Kann PASV-Übertragung nicht beginnen.\n"
 
-#: src/ftp.c:501
+#: src/ftp.c:524
 msgid "Cannot parse PASV response.\n"
 msgstr "Kann PASV-Antwort nicht auswerten.\n"
 
-# short for:
-# Es wird der versuch unternommen, ...
-# -ke- 2001-06-03 07:40:10 CEST
-# Finde ich nicht gut.  Meine Übersetzung war gedacht als Verkürzung von:
-#     Es wird der Versuch unternommen, eine Verbindung zu ... herzustellen
-#: src/ftp.c:515
+#: src/ftp.c:545
 #, c-format
-msgid "Will try connecting to %s:%hu.\n"
-msgstr "Versuch: Verbindung zu %s:%hu herstellen.\n"
+msgid "couldn't connect to %s:%hu: %s\n"
+msgstr "Konnte keine Verbindung zu »%s:%hu« herstellen: %s\n"
 
-#: src/ftp.c:602
+#: src/ftp.c:595
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Verbindungsfehler (%s).\n"
 
-#: src/ftp.c:618
+#: src/ftp.c:611
 msgid "Invalid PORT.\n"
 msgstr "Ungültiger PORT.\n"
 
-#: src/ftp.c:671
+#: src/ftp.c:664
 #, c-format
 msgid "\nREST failed; will not truncate `%s'.\n"
 msgstr "\nREST schlug fehl; »%s« wird nicht abgeschnitten.\n"
 
 # Wieder das mit der 1. Person :)
-#: src/ftp.c:678
+#: src/ftp.c:671
 msgid "\nREST failed, starting from scratch.\n"
 msgstr "\nREST schlug fehl; es wird wieder von vorn begonnen.\n"
 
-#: src/ftp.c:727
+#: src/ftp.c:720
 #, c-format
 msgid "No such file `%s'.\n\n"
 msgstr "Die Datei »%s« gibt es nicht.\n\n"
 
-#: src/ftp.c:775
+#: src/ftp.c:768
 #, c-format
 msgid "No such file or directory `%s'.\n\n"
 msgstr "Die Datei oder das Verzeichnis »%s« gibt es nicht.\n\n"
 
-#: src/ftp.c:859 src/ftp.c:867
+#: src/ftp.c:852 src/ftp.c:860
 #, c-format
 msgid "Length: %s"
 msgstr "Länge: %s"
 
-#: src/ftp.c:861 src/ftp.c:869
+#: src/ftp.c:854 src/ftp.c:862
 #, c-format
 msgid " [%s to go]"
 msgstr " [noch %s]"
 
 # wohl "unmaßgeblich", nicht "ohne Berechtigung"
-#: src/ftp.c:871
+#: src/ftp.c:864
 msgid " (unauthoritative)\n"
 msgstr " (unmaßgeblich)\n"
 
-#: src/ftp.c:898
+#: src/ftp.c:890
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s; Kontroll-Verbindung schließen.\n"
 
-#: src/ftp.c:906
+#: src/ftp.c:898
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - Daten-Verbindung: %s; "
 
-#: src/ftp.c:923
+#: src/ftp.c:915
 msgid "Control connection closed.\n"
 msgstr "Kontroll-Verbindung geschlossen.\n"
 
-#: src/ftp.c:941
+#: src/ftp.c:933
 msgid "Data transfer aborted.\n"
 msgstr "Daten-Übertragung abgebrochen.\n"
 
-#: src/ftp.c:1005
+#: src/ftp.c:997
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "Die Datei »%s« ist schon vorhanden, kein erneuter Download.\n"
 
-#: src/ftp.c:1075 src/http.c:1502
+#: src/ftp.c:1067 src/http.c:1538
 #, c-format
 msgid "(try:%2d)"
 msgstr "(Versuch:%2d)"
 
 # oder "gesichert"?
-#: src/ftp.c:1139 src/http.c:1753
+#: src/ftp.c:1131 src/http.c:1797
 #, c-format
 msgid "%s (%s) - `%s' saved [%ld]\n\n"
 msgstr "%s (%s) - »%s« gespeichert [%ld]\n\n"
 
-#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
+#: src/ftp.c:1173 src/main.c:814 src/recur.c:336 src/retr.c:587
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Entferne »%s«.\n"
 
-#: src/ftp.c:1221
+#: src/ftp.c:1215
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "»%s« als temporäre Auflistungsdatei benutzen.\n"
 
-#: src/ftp.c:1233
+#: src/ftp.c:1230
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "»%s« gelöscht.\n"
 
-#: src/ftp.c:1269
+#: src/ftp.c:1265
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "Die Rekursionstiefe %d übersteigt die max. erlaubte Tiefe %d.\n"
