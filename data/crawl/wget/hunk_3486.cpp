 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: võti nõuab argumenti -- %c\n"
 
-#: src/host.c:374
+#: src/host.c:251
+#, c-format
+msgid "Resolving %s... "
+msgstr "Lahendan %s... "
+
+#: src/host.c:258
+#, c-format
+msgid "failed: %s.\n"
+msgstr "ebaõnnestus: %s.\n"
+
+#: src/host.c:326
 msgid "Host not found"
 msgstr "Hosti ei leitud"
 
-#: src/host.c:376
+#: src/host.c:328
 msgid "Unknown error"
 msgstr "Tundmatu viga"
 
 #. this is fatal
-#: src/http.c:555
+#: src/http.c:584
 msgid "Failed to set up an SSL context\n"
 msgstr "SSL konteksti määramine ebaõnnestus\n"
 
-#: src/http.c:561
+#: src/http.c:590
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "Sertifikaadi laadimine failist %s ebaõnnestus\n"
 
-#: src/http.c:565 src/http.c:573
+#: src/http.c:594 src/http.c:602
 msgid "Trying without the specified certificate\n"
 msgstr "Proovin näidatud sertifikaati mitte kasutada\n"
 
-#: src/http.c:569
+#: src/http.c:598
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "Sertifikaadi võtme laadimine failist %s ebaõnnestus\n"
 
-#: src/http.c:663 src/http.c:1593
+#: src/http.c:668 src/http.c:1631
 msgid "Unable to establish SSL connection.\n"
 msgstr "SSL ühenduse loomine ei õnnestu.\n"
 
-#: src/http.c:671
+#: src/http.c:677
 #, c-format
 msgid "Reusing connection to %s:%hu.\n"
 msgstr "Kasutan ühendust serveriga %s:%hu.\n"
 
-#: src/http.c:861
+#: src/http.c:879
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "HTTP päringu kirjutamine ebaõnnestus: %s.\n"
 
-#: src/http.c:866
+#: src/http.c:884
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s päring saadetud, ootan vastust... "
 
-#: src/http.c:910
+#: src/http.c:928
 msgid "End of file while parsing headers.\n"
 msgstr "Päiste analüüsil sain faili lõpu teate.\n"
 
-#: src/http.c:920
+#: src/http.c:938
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Päiste lugemise viga (%s).\n"
 
-#: src/http.c:959
+#: src/http.c:973
 msgid "No data received"
 msgstr "Andmeid ei saanudki"
 
-#: src/http.c:961
+#: src/http.c:975
 msgid "Malformed status line"
 msgstr "Katkine staatuse rida"
 
-#: src/http.c:966
+#: src/http.c:980
 msgid "(no description)"
 msgstr "(kirjeldus puudub)"
 
-#: src/http.c:1089
+#: src/http.c:1112
 msgid "Authorization failed.\n"
 msgstr "Autoriseerimine ebaõnnestus.\n"
 
-#: src/http.c:1096
+#: src/http.c:1119
 msgid "Unknown authentication scheme.\n"
 msgstr "Tundmatu autentimis skeem.\n"
 
-#: src/http.c:1136
+#: src/http.c:1159
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Asukoht: %s%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:1160 src/http.c:1293
 msgid "unspecified"
 msgstr "määramata"
 
-#: src/http.c:1138
+#: src/http.c:1161
 msgid " [following]"
 msgstr " [järgnev]"
 
-#: src/http.c:1200
+#: src/http.c:1224
 msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
 msgstr "\n    Fail on juba täielikult kohal; rohkem ei saa midagi teha.\n\n"
 
-#: src/http.c:1216
+#: src/http.c:1240
 #, c-format
 msgid ""
 "\n"
