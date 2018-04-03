 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: flaggan beh�ver ett argument -- %c\n"
 
-#: src/host.c:374
+#: src/host.c:251
+#, c-format
+msgid "Resolving %s... "
+msgstr "Sl�r upp %s... "
+
+#: src/host.c:258
+#, c-format
+msgid "failed: %s.\n"
+msgstr "misslyckades: %s.\n"
+
+#: src/host.c:326
 msgid "Host not found"
 msgstr "Servern kunde inte hittas"
 
-#: src/host.c:376
+#: src/host.c:328
 msgid "Unknown error"
 msgstr "Ok�nt fel"
 
 #. this is fatal
-#: src/http.c:555
+#: src/http.c:584
 msgid "Failed to set up an SSL context\n"
 msgstr "Misslyckades med att st�lla in ett SSL-sammanhang\n"
 
-#: src/http.c:561
+#: src/http.c:590
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "Misslyckades med att l�sa in certifikat fr�n %s\n"
 
-#: src/http.c:565 src/http.c:573
+#: src/http.c:594 src/http.c:602
 msgid "Trying without the specified certificate\n"
 msgstr "F�rs�ker utan det angivna certifikatet\n"
 
-#: src/http.c:569
+#: src/http.c:598
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "Misslyckades med att f� tag i certifikatnyckel fr�n %s\n"
 
-#: src/http.c:663 src/http.c:1593
+#: src/http.c:668 src/http.c:1631
 msgid "Unable to establish SSL connection.\n"
 msgstr "Kan inte etablera en SSL-anslutning.\n"
 
-#: src/http.c:671
+#: src/http.c:677
 #, c-format
 msgid "Reusing connection to %s:%hu.\n"
 msgstr "�teranv�nder anslutning till %s:%hu.\n"
 
-#: src/http.c:861
+#: src/http.c:879
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Misslyckades med att skriva HTTP-beg�ran: %s.\n"
 
-#: src/http.c:866
+#: src/http.c:884
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s-beg�ran skickad, v�ntar p� svar... "
 
-#: src/http.c:910
+#: src/http.c:928
 msgid "End of file while parsing headers.\n"
 msgstr "Filslut vid genoms�kning av huvuden.\n"
 
-#: src/http.c:920
+#: src/http.c:938
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "L�sfel (%s) i huvuden.\n"
 
-#: src/http.c:959
+#: src/http.c:973
 msgid "No data received"
 msgstr "Ingen data mottagen"
 
-#: src/http.c:961
+#: src/http.c:975
 msgid "Malformed status line"
 msgstr "Felaktig statusrad"
 
-#: src/http.c:966
+#: src/http.c:980
 msgid "(no description)"
 msgstr "(ingen beskrivning)"
 
-#: src/http.c:1089
+#: src/http.c:1112
 msgid "Authorization failed.\n"
 msgstr "Auktorisering misslyckades.\n"
 
-#: src/http.c:1096
+#: src/http.c:1119
 msgid "Unknown authentication scheme.\n"
 msgstr "Ok�nd autentiseringsmetod.\n"
 
-#: src/http.c:1136
+#: src/http.c:1159
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Adress: %s%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:1160 src/http.c:1293
 msgid "unspecified"
 msgstr "ospecifierat"
 
-#: src/http.c:1138
+#: src/http.c:1161
 msgid " [following]"
 msgstr " [f�ljande]"
 
-#: src/http.c:1200
+#: src/http.c:1224
 msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
 msgstr "\n    Filen �r redan fullst�ndigt h�mtad, inget att g�ra.\n\n"
 
-#: src/http.c:1216
+#: src/http.c:1240
 #, c-format
 msgid ""
 "\n"
