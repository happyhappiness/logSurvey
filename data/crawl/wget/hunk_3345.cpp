 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: az opci�hoz sz�ks�g van argumentumra -- %c\n"
 
-#: src/host.c:374
+#: src/host.c:271
+#, c-format
+msgid "Resolving %s... "
+msgstr "IP keres�s %s... "
+
+#: src/host.c:278
+#, c-format
+msgid "failed: %s.\n"
+msgstr "nem siker�lt: %s.\n"
+
+#: src/host.c:348
 msgid "Host not found"
 msgstr "Host-ot nem tal�lom"
 
-#: src/host.c:376
+#: src/host.c:350
 msgid "Unknown error"
 msgstr "Ismeretlen hiba"
 
+#: src/html-url.c:336
+#, c-format
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr "%s: nem tudom megtal�lni a hi�nyos %s linket.\n"
+
 #. this is fatal
-#: src/http.c:555
+#: src/http.c:573
 msgid "Failed to set up an SSL context\n"
 msgstr "Nem siker�lt SSL-t be�ll�tsak\n"
 
-#: src/http.c:561
+#: src/http.c:579
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "Nem siker�lt bet�ltsem az igazol�sokat %s-r�l\n"
 
-#: src/http.c:565 src/http.c:573
+#: src/http.c:583 src/http.c:591
 msgid "Trying without the specified certificate\n"
 msgstr "Megpr�b�lom a megadott igazol�s n�lk�l\n"
 
-#: src/http.c:569
+#: src/http.c:587
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "Nemsiker�lt megszerezni az igazol� kulcsot %s-r�l\n"
 
-#: src/http.c:663 src/http.c:1593
+#: src/http.c:657 src/http.c:1620
 msgid "Unable to establish SSL connection.\n"
 msgstr "Nem siker�lt SSL kapcsolatot l�trehozni.\n"
 
-#: src/http.c:671
+#: src/http.c:666
 #, c-format
 msgid "Reusing connection to %s:%hu.\n"
 msgstr "�jrahaszn�lom a kapcsolatot %s:%hu-hoz.\n"
 
-#: src/http.c:861
+#: src/http.c:868
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "A HTTP k�r�s �r�sa sikertelen: %s.\n"
 
-#: src/http.c:866
+#: src/http.c:873
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s k�r�s elk�ldve, v�rom a v�laszt... "
 
-#: src/http.c:910
+#: src/http.c:917
 msgid "End of file while parsing headers.\n"
 msgstr "�llom�ny v�ge mik�zben a fejl�cet olvasom.\n"
 
-#: src/http.c:920
+#: src/http.c:927
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Olvas�si hiba (%s) a fejl�cben.\n"
 
-#: src/http.c:959
+#: src/http.c:962
 msgid "No data received"
 msgstr "Nem �rkezett adat"
 
-#: src/http.c:961
+#: src/http.c:964
 msgid "Malformed status line"
 msgstr "Rosszul form�zott �llapot vonal"
 
-#: src/http.c:966
+#: src/http.c:969
 msgid "(no description)"
 msgstr "(nincs le�r�s)"
 
-#: src/http.c:1089
+#: src/http.c:1101
 msgid "Authorization failed.\n"
 msgstr "Azonos�t�s sikertelen.\n"
 
-#: src/http.c:1096
+#: src/http.c:1108
 msgid "Unknown authentication scheme.\n"
 msgstr "Ismeretlen azonos�t�si m�dszer.\n"
 
-#: src/http.c:1136
+#: src/http.c:1148
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Hely: %s%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:1149 src/http.c:1282
 msgid "unspecified"
 msgstr "nem megadott"
 
-#: src/http.c:1138
+#: src/http.c:1150
 msgid " [following]"
 msgstr " [k�vetkezik]"
 
-#: src/http.c:1200
-msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
-msgstr "\n    Az �llom�ny m�r teljesen le van t�ltve; nincs mit csin�jak.\n\n"
+#: src/http.c:1213
+msgid ""
+"\n"
+"    The file is already fully retrieved; nothing to do.\n"
+"\n"
+msgstr ""
+"\n"
+"    Az �llom�ny m�r teljesen le van t�ltve; nincs mit csin�jak.\n"
+"\n"
 
-#: src/http.c:1216
+#: src/http.c:1229
 #, c-format
 msgid ""
 "\n"
