 "Größen stimmen nicht überein (lokal %s) -- erneuter Download.\n"
 "\n"
 
-#: src/ftp.c:1468
+#: src/ftp.c:1469
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Ungültiger Name für einen symbolischen Verweis; übersprungen.\n"
 
-#: src/ftp.c:1485
+#: src/ftp.c:1486
 #, c-format
 msgid ""
 "Already have correct symlink %s -> %s\n"
 "\n"
 msgstr "Der richtige symbolische Verweis %s -> %s ist schon vorhanden.\n"
 
-#: src/ftp.c:1493
+#: src/ftp.c:1494
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Symbolischen Verweis %s -> %s anlegen.\n"
 
-#: src/ftp.c:1503
+#: src/ftp.c:1504
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr ""
 "Symbolischer Verweis nicht möglich; symbolischer Verweis »%s« übersprungen.\n"
 
-#: src/ftp.c:1515
+#: src/ftp.c:1516
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Verzeichnis »%s« übersprungen.\n"
 
-#: src/ftp.c:1524
+#: src/ftp.c:1525
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: unbekannter bzw. nicht unterstützter Dateityp.\n"
 
-#: src/ftp.c:1551
+#: src/ftp.c:1552
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: beschädigter Zeitstempel.\n"
 
-#: src/ftp.c:1579
+#: src/ftp.c:1580
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr ""
 "Verzeichnisse nicht erneut holen; da die Tiefe bereits %d ist (max. erlaubt %"
 "d).\n"
 
-#: src/ftp.c:1629
+#: src/ftp.c:1630
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr ""
 "Nicht zu »%s« hinabsteigen, da es ausgeschlossen bzw. nicht eingeschlossen "
 "ist.\n"
 
-#: src/ftp.c:1695 src/ftp.c:1709
+#: src/ftp.c:1696 src/ftp.c:1710
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "»%s« zurückgewiesen.\n"
 
-#: src/ftp.c:1757
+#: src/ftp.c:1733
+#, fuzzy, c-format
+msgid "Error matching %s against %s: %s\n"
+msgstr "Fehler beim Schreiben nach »%s«: %s.\n"
+
+#: src/ftp.c:1774
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Keine Treffer bei dem Muster »%s«.\n"
 
-#: src/ftp.c:1823
+#: src/ftp.c:1840
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "HTML-artigen Index nach »%s« [%s] geschrieben.\n"
 
-#: src/ftp.c:1828
+#: src/ftp.c:1845
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "HTML-artiger Index nach »%s« geschrieben.\n"
 
-#: src/host.c:347
+#: src/host.c:348
 msgid "Unknown host"
 msgstr "Unbekannter Rechner"
 
-#: src/host.c:351
+#: src/host.c:352
 msgid "Temporary failure in name resolution"
 msgstr "Temoprärer Fehler bei der Namensauflösung"
 
-#: src/host.c:353
+#: src/host.c:354
 msgid "Unknown error"
 msgstr "Unbekannter Fehler"
 
-#: src/host.c:714
+#: src/host.c:715
 #, c-format
 msgid "Resolving %s... "
 msgstr "Auflösen des Hostnamen »%s«.... "
 
-#: src/host.c:761
+#: src/host.c:762
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr "Fehler: Keine IPv4/IPv6 Adresse für den Host.\n"
 
-#: src/host.c:784
+#: src/host.c:785
 msgid "failed: timed out.\n"
 msgstr "fehlgeschlagen: Wartezeit abgelaufen.\n"
 
-#: src/html-url.c:288
+#: src/html-url.c:289
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Der unvollständige Link »%s« kann nicht aufgelöst werden.\n"
 
-#: src/html-url.c:695
+#: src/html-url.c:696
 #, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: %s: Ungültige URL »%s«.\n"
 
-#: src/http.c:367
+#: src/http.c:368
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Fehler beim Schreiben der HTTP-Anforderung: %s.\n"
 
-#: src/http.c:736
+#: src/http.c:737
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Keine Header, vermutlich ist es HTTP/0.9."
 
-#: src/http.c:1413
+#: src/http.c:1417
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "SSL wird ausgeschaltet nachdem Fehler aufgetreten sind.\n"
 
-#: src/http.c:1566
+#: src/http.c:1570
 #, c-format
 msgid "POST data file `%s' missing: %s\n"
 msgstr "POST Datendatei »%s« fehlt: %s\n"
 
-#: src/http.c:1615
+#: src/http.c:1619
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Wiederverwendung der bestehenden Verbindung zu %s:%d.\n"
 
-#: src/http.c:1683
+#: src/http.c:1687
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Fehler beim Lesen der Proxy-Antwort: %s.\n"
 
-#: src/http.c:1703
+#: src/http.c:1707
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Proxy-Tunneling fehlgeschlagen: %s"
 
 # Wieder das mit der 1. Person :)
-#: src/http.c:1748
+#: src/http.c:1752
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s Anforderung gesendet, warte auf Antwort... "
 
-#: src/http.c:1759
+#: src/http.c:1763
 msgid "No data received.\n"
 msgstr "Keine Daten empfangen.\n"
 
-#: src/http.c:1766
+#: src/http.c:1770
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lesefehler (%s) beim Vorspann (header).\n"
 
-#: src/http.c:1812
+#: src/http.c:1816 src/http.c:2368
 #, c-format
 msgid ""
 "File `%s' already there; not retrieving.\n"
 "\n"
 msgstr "Die Datei »%s« ist schon vorhanden; kein erneuter Download.\n"
 
-#: src/http.c:1965
+#: src/http.c:1969
 msgid "Unknown authentication scheme.\n"
 msgstr "Unbekanntes Authentifizierungsschema.\n"
 
-#: src/http.c:1996
+#: src/http.c:2000
 msgid "Authorization failed.\n"
 msgstr "Authorisierung fehlgeschlagen.\n"
 
-#: src/http.c:2010
+#: src/http.c:2014
 msgid "Malformed status line"
 msgstr "Nicht korrekte Statuszeile"
 
-#: src/http.c:2012
+#: src/http.c:2016
 msgid "(no description)"
 msgstr "(keine Beschreibung)"
 
-#: src/http.c:2075
+#: src/http.c:2082
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Platz: %s%s\n"
 
-#: src/http.c:2076 src/http.c:2183
+#: src/http.c:2083 src/http.c:2193
 msgid "unspecified"
 msgstr "nicht spezifiziert"
 
-#: src/http.c:2077
+#: src/http.c:2084
 msgid " [following]"
 msgstr "[folge]"
 
-#: src/http.c:2133
+#: src/http.c:2140
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
