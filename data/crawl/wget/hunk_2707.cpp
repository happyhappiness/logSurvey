 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Der unvollständige Link »%s« kann nicht aufgelöst werden.\n"
 
-#: src/http.c:373 src/http.c:1549
+#: src/html-url.c:705
+#, c-format
+msgid "%s: Invalid URL %s: %s\n"
+msgstr "%s: %s: Ungültige URL »%s«.\n"
+
+#: src/http.c:373
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Fehler beim Schreiben der HTTP-Anforderung: %s.\n"
 
 #: src/http.c:687
 msgid "No headers, assuming HTTP/0.9"
-msgstr ""
+msgstr "Keine Header, vermutlich ist es HTTP/0.9."
 
-#: src/http.c:1198
+#: src/http.c:1204
 msgid "Disabling SSL due to encountered errors.\n"
-msgstr ""
+msgstr "SSL wird ausgeschaltet nachdem Fehler aufgetreten sind.\n"
 
-#: src/http.c:1417
-#, fuzzy, c-format
-msgid "Reusing existing connection to %s:%d.\n"
-msgstr "Weiterverwendung der Verbindung zu %s:%hu.\n"
+#: src/http.c:1374
+#, c-format
+msgid "POST data file `%s' missing: %s\n"
+msgstr "POST Datendatei »%s« fehlt: %s\n"
 
-#: src/http.c:1479
-#, fuzzy, c-format
-msgid "Failed writing to proxy: %s.\n"
-msgstr "Fehler beim Schreiben der HTTP-Anforderung: %s.\n"
+#: src/http.c:1423
+#, c-format
+msgid "Reusing existing connection to %s:%d.\n"
+msgstr "Wiederverwendung der bestehenden Verbindung zu %s:%d.\n"
 
-#: src/http.c:1488
-#, fuzzy, c-format
+#: src/http.c:1492
+#, c-format
 msgid "Failed reading proxy response: %s\n"
-msgstr "Fehler beim Schreiben der HTTP-Anforderung: %s.\n"
+msgstr "Fehler beim Lesen der Proxy-Antwort: %s.\n"
 
-#: src/http.c:1508
+#: src/http.c:1512
 #, c-format
 msgid "Proxy tunneling failed: %s"
-msgstr ""
+msgstr "Proxy-Tunneling fehlgeschlagen: %s"
 
 # Wieder das mit der 1. Person :)
-#: src/http.c:1555
+#: src/http.c:1557
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s Anforderung gesendet, warte auf Antwort... "
 
-#: src/http.c:1566
-#, fuzzy
+#: src/http.c:1568
 msgid "No data received.\n"
-msgstr "Keine Daten empfangen"
+msgstr "Keine Daten empfangen.\n"
 
-#: src/http.c:1573
+#: src/http.c:1575
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lesefehler (%s) beim Vorspann (header).\n"
 
 #. If the authentication header is missing or
 #. unrecognized, there's no sense in retrying.
-#: src/http.c:1658
+#: src/http.c:1660
 msgid "Unknown authentication scheme.\n"
 msgstr "Unbekanntes Authentifizierungsschema.\n"
 
-#: src/http.c:1682
+#: src/http.c:1684
 msgid "Authorization failed.\n"
 msgstr "Authorisierung fehlgeschlagen.\n"
 
-#: src/http.c:1696
+#: src/http.c:1698
 msgid "Malformed status line"
 msgstr "Nicht korrekte Statuszeile"
 
-#: src/http.c:1698
+#: src/http.c:1700
 msgid "(no description)"
 msgstr "(keine Beschreibung)"
 
-#: src/http.c:1769
+#: src/http.c:1763
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Platz: %s%s\n"
 
-#: src/http.c:1770 src/http.c:1867
+#: src/http.c:1764 src/http.c:1871
 msgid "unspecified"
 msgstr "nicht spezifiziert"
 
-#: src/http.c:1771
+#: src/http.c:1765
 msgid " [following]"
 msgstr "[folge]"
 
 #. If `-c' is in use and the file has been fully downloaded (or
 #. the remote file has shrunk), Wget effectively requests bytes
 #. after the end of file and the server response with 416.
-#: src/http.c:1817
+#: src/http.c:1821
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
