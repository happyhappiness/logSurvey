 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: Option verlangt ein Argument -- %c\n"
 
-#: src/host.c:374
+#: src/host.c:251
+#, c-format
+msgid "Resolving %s... "
+msgstr "Auflösen des Hostnamen »%s«.... "
+
+#: src/host.c:258
+#, c-format
+msgid "failed: %s.\n"
+msgstr "fehlgeschlagen: %s.\n"
+
+#: src/host.c:326
 msgid "Host not found"
 msgstr "Host nicht gefunden"
 
-#: src/host.c:376
+#: src/host.c:328
 msgid "Unknown error"
 msgstr "Unbekannter Fehler"
 
 #. this is fatal
-#: src/http.c:555
+#: src/http.c:584
 msgid "Failed to set up an SSL context\n"
 msgstr "Fehler beim Herstellen des SSL-Kontextes\n"
 
-#: src/http.c:561
+#: src/http.c:590
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "Fehler beim Laden der Zertifikate von %s\n"
 
-#: src/http.c:565 src/http.c:573
+#: src/http.c:594 src/http.c:602
 msgid "Trying without the specified certificate\n"
 msgstr "Versuch ohne die angegebenen Zertifikate\n"
 
-#: src/http.c:569
+#: src/http.c:598
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "Fehlversuch den Zertifikat-Schlüssel von %s zu erhalten.\n"
 
-#: src/http.c:663 src/http.c:1593
+#: src/http.c:668 src/http.c:1631
 msgid "Unable to establish SSL connection.\n"
 msgstr "Es ist nicht möglich, eine SSL-Verbindung herzustellen.\n"
 
-#: src/http.c:671
+#: src/http.c:677
 #, c-format
 msgid "Reusing connection to %s:%hu.\n"
 msgstr "Weiterverwendung der Verbindung zu %s:%hu.\n"
 
-#: src/http.c:861
+#: src/http.c:879
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Fehler beim Schreiben der HTTP-Anforderung: %s.\n"
 
 # Wieder das mit der 1. Person :)
-#: src/http.c:866
+#: src/http.c:884
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s Anforderung gesendet, warte auf Antwort... "
 
-#: src/http.c:910
+#: src/http.c:928
 msgid "End of file while parsing headers.\n"
 msgstr "Dateiende beim Auswerten des Vorspanns (headers).\n"
 
-#: src/http.c:920
+#: src/http.c:938
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lesefehler (%s) beim Vorspann (header).\n"
 
-#: src/http.c:959
+#: src/http.c:973
 msgid "No data received"
 msgstr "Keine Daten empfangen"
 
-#: src/http.c:961
+#: src/http.c:975
 msgid "Malformed status line"
 msgstr "Nicht korrekte Statuszeile"
 
-#: src/http.c:966
+#: src/http.c:980
 msgid "(no description)"
 msgstr "(keine Beschreibung)"
 
-#: src/http.c:1089
+#: src/http.c:1112
 msgid "Authorization failed.\n"
 msgstr "Authorisierung fehlgeschlagen.\n"
 
-#: src/http.c:1096
+#: src/http.c:1119
 msgid "Unknown authentication scheme.\n"
 msgstr "Unbekanntes Authentifizierungsschema.\n"
 
-#: src/http.c:1136
+#: src/http.c:1159
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Platz: %s%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:1160 src/http.c:1293
 msgid "unspecified"
 msgstr "nicht spezifiziert"
 
-#: src/http.c:1138
+#: src/http.c:1161
 msgid " [following]"
 msgstr "[folge]"
 
-#: src/http.c:1200
+#: src/http.c:1224
 msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
 msgstr "\n    Download der Datei schon vollständig; kein Download notwendig.\n\n"
 
-#: src/http.c:1216
+#: src/http.c:1240
 #, c-format
 msgid ""
 "\n"
