 #. that there can be valid reasons for the local host
 #. name not to be an FQDN, so I've decided to remove the
 #. annoying warning.
-#: src/host.c:511
+#: src/host.c:473
 #, c-format
 msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
-msgstr "%s: Warnung: \"reverse-lookup\" für lokale Adresse ergibt keinen FQDN!\n"
+msgstr ""
+"%s: Warnung: \"reverse-lookup\" für lokale Adresse ergibt keinen FQDN!\n"
 
-#: src/host.c:539
+#: src/host.c:501
 msgid "Host not found"
 msgstr "Host nicht gefunden"
 
-#: src/host.c:541
+#: src/host.c:503
 msgid "Unknown error"
 msgstr "Unbekannter Fehler"
 
-#: src/html.c:439 src/html.c:441
+#: src/http.c:554
 #, c-format
-msgid "Index of /%s on %s:%d"
-msgstr "Index von /%s auf %s:%d"
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Versuche Verbindung zu %s:%hu wiederzuverwenden.\n"
 
-#: src/html.c:463
-msgid "time unknown       "
-msgstr "Zeit unbekannt     "
-
-#: src/html.c:467
-msgid "File        "
-msgstr "Datei       "
-
-#: src/html.c:470
-msgid "Directory   "
-msgstr "Verzeichnis "
-
-#: src/html.c:473
-msgid "Link        "
-msgstr "Verweis     "
-
-#: src/html.c:476
-msgid "Not sure    "
-msgstr "Nicht sicher"
-
-#: src/html.c:494
+#: src/http.c:721
 #, c-format
-msgid " (%s bytes)"
-msgstr " (%s Bytes)"
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Schreiben der HTTP-Anforderung fehlgeschlagen: %s.\n"
 
-#: src/http.c:492
-msgid "Failed writing HTTP request.\n"
-msgstr "Schreiben der HTTP-Anforderung fehlgeschlagen.\n"
-
-#: src/http.c:497
+#: src/http.c:726
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s Anforderung gesendet, warte auf Antwort... "
 
-#: src/http.c:536
+#: src/http.c:765
 msgid "End of file while parsing headers.\n"
 msgstr "Dateiende beim Auswerten des Vorspanns (header lines).\n"
 
-#: src/http.c:547
+#: src/http.c:776
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lesefehler (%s) beim Vorspann (header lines).\n"
 
-#: src/http.c:587
+#: src/http.c:816
 msgid "No data received"
 msgstr "Keine Daten empfangen"
 
-#: src/http.c:589
+#: src/http.c:818
 msgid "Malformed status line"
 msgstr "Nicht korrekte Statuszeile"
 
-#: src/http.c:594
+#: src/http.c:823
 msgid "(no description)"
 msgstr "(keine Beschreibung)"
 
-#. If we have tried it already, then there is not point
-#. retrying it.
-#: src/http.c:678
+#: src/http.c:937
 msgid "Authorization failed.\n"
 msgstr "Authorisierung fehlgeschlagen.\n"
 
-#: src/http.c:685
+#: src/http.c:944
 msgid "Unknown authentication scheme.\n"
 msgstr "Unbekannter Authentifizierungsablauf.\n"
 
-#: src/http.c:748
+#: src/http.c:1034
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Platz: %s%s\n"
 
-#: src/http.c:749 src/http.c:774
+#: src/http.c:1035 src/http.c:1060
 msgid "unspecified"
 msgstr "nicht spezifiziert"
 
-#: src/http.c:750
+#: src/http.c:1036
 msgid " [following]"
 msgstr "[folge]"
 
