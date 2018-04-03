 #. that there can be valid reasons for the local host
 #. name not to be an FQDN, so I've decided to remove the
 #. annoying warning.
-#: src/host.c:516
+#: src/host.c:511
 #, c-format
 msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
-msgstr ""
-"%s: Warnung: \"reverse-lookup\" für lokale Adresse ergibt keinen FQDN!\n"
+msgstr "%s: Warnung: \"reverse-lookup\" für lokale Adresse ergibt keinen FQDN!\n"
 
-#: src/host.c:544
+#: src/host.c:539
 msgid "Host not found"
 msgstr "Host nicht gefunden"
 
-#: src/host.c:546
+#: src/host.c:541
 msgid "Unknown error"
 msgstr "Unbekannter Fehler"
 
-#: src/html.c:615 src/html.c:617
+#: src/html.c:439 src/html.c:441
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Index von /%s auf %s:%d"
 
-#: src/html.c:639
+#: src/html.c:463
 msgid "time unknown       "
 msgstr "Zeit unbekannt     "
 
-#: src/html.c:643
+#: src/html.c:467
 msgid "File        "
 msgstr "Datei       "
 
-#: src/html.c:646
+#: src/html.c:470
 msgid "Directory   "
 msgstr "Verzeichnis "
 
-#: src/html.c:649
+#: src/html.c:473
 msgid "Link        "
 msgstr "Verweis     "
 
-#: src/html.c:652
+#: src/html.c:476
 msgid "Not sure    "
 msgstr "Nicht sicher"
 
-#: src/html.c:670
+#: src/html.c:494
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s Bytes)"
 
-#: src/http.c:508
+#: src/http.c:492
 msgid "Failed writing HTTP request.\n"
-msgstr "HTTP-Anforderung zu schreiben schlug fehl.\n"
+msgstr "Schreiben der HTTP-Anforderung fehlgeschlagen.\n"
 
-#: src/http.c:512
+#: src/http.c:497
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s Anforderung gesendet, warte auf Antwort... "
 
-#: src/http.c:551
+#: src/http.c:536
 msgid "End of file while parsing headers.\n"
-msgstr "Dateiende beim auswerten der Kopfzeilen.\n"
+msgstr "Dateiende beim Auswerten des Vorspanns (header lines).\n"
 
-#: src/http.c:562
+#: src/http.c:547
 #, c-format
 msgid "Read error (%s) in headers.\n"
-msgstr "Lesefehler (%s) bei den Kopfzeilen.\n"
+msgstr "Lesefehler (%s) beim Vorspann (header lines).\n"
 
-#: src/http.c:602
+#: src/http.c:587
 msgid "No data received"
 msgstr "Keine Daten empfangen"
 
-#: src/http.c:604
+#: src/http.c:589
 msgid "Malformed status line"
 msgstr "Nicht korrekte Statuszeile"
 
-#: src/http.c:609
+#: src/http.c:594
 msgid "(no description)"
 msgstr "(keine Beschreibung)"
 
 #. If we have tried it already, then there is not point
 #. retrying it.
-#: src/http.c:693
+#: src/http.c:678
 msgid "Authorization failed.\n"
 msgstr "Authorisierung fehlgeschlagen.\n"
 
-#: src/http.c:700
+#: src/http.c:685
 msgid "Unknown authentication scheme.\n"
-msgstr "Unbekannten Authentifizierungsablauf.\n"
+msgstr "Unbekannter Authentifizierungsablauf.\n"
 
-#: src/http.c:783
+#: src/http.c:748
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Platz: %s%s\n"
 
-#: src/http.c:784 src/http.c:809
+#: src/http.c:749 src/http.c:774
 msgid "unspecified"
 msgstr "nicht spezifiziert"
 
-#: src/http.c:785
+#: src/http.c:750
 msgid " [following]"
 msgstr "[folge]"
 
