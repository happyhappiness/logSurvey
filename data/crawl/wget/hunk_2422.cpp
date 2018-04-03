 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1777
+#: src/ftp.c:1753
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Keine Treffer bei dem Muster »%s«.\n"
 
-#: src/ftp.c:1843
+#: src/ftp.c:1819
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "HTML-artigen Index nach »%s« [%s] geschrieben.\n"
 
-#: src/ftp.c:1848
+#: src/ftp.c:1824
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "HTML-artiger Index nach »%s« geschrieben.\n"
 
-#: src/getopt.c:675
+#: src/getopt.c:670
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: Option »%s« ist zweideutig\n"
 
-#: src/getopt.c:700
+#: src/getopt.c:695
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: Option »--%s« erlaubt kein Argument\n"
 
-#: src/getopt.c:705
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: Option »%c%s« erlaubt kein Argument\n"
 
-#: src/getopt.c:723 src/getopt.c:896
+#: src/getopt.c:718 src/getopt.c:891
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: Option »%s« benötigt ein Argument\n"
 
 #. --option
-#: src/getopt.c:752
+#: src/getopt.c:747
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: nicht erkannte Option »--%s«\n"
 
 #. +option or -option
-#: src/getopt.c:756
+#: src/getopt.c:751
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: nicht erkannte Option »%c%s«\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:782
+#: src/getopt.c:777
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: ungültige Option -- %c\n"
 
-#: src/getopt.c:785
+#: src/getopt.c:780
 #, c-format
 msgid "%s: invalid option -- %c\n"
 msgstr "%s: ungültige Option -- %c\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:815 src/getopt.c:945
+#: src/getopt.c:810 src/getopt.c:940
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: Option verlangt ein Argument -- %c\n"
 
-#: src/getopt.c:862
+#: src/getopt.c:857
 #, c-format
 msgid "%s: option `-W %s' is ambiguous\n"
 msgstr "%s: Option »-W %s« ist zweideutig\n"
 
-#: src/getopt.c:880
+#: src/getopt.c:875
 #, c-format
 msgid "%s: option `-W %s' doesn't allow an argument\n"
 msgstr "%s: Option »-W %s« erlaubt kein Argument\n"
 
-#: src/host.c:366
+#: src/host.c:347
 msgid "Unknown host"
 msgstr "Unbekannter Rechner"
 
 #. Message modeled after what gai_strerror returns in similar
 #. circumstances.
-#: src/host.c:370
+#: src/host.c:351
 msgid "Temporary failure in name resolution"
 msgstr "Temoprärer Fehler bei der Namensauflösung"
 
-#: src/host.c:372
+#: src/host.c:353
 msgid "Unknown error"
 msgstr "Unbekannter Fehler"
 
-#: src/host.c:751
+#: src/host.c:714
 #, c-format
 msgid "Resolving %s... "
 msgstr "Auflösen des Hostnamen »%s«.... "
 
-#: src/host.c:798
+#: src/host.c:761
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr "Fehler: Keine IPv4/IPv6 Adresse für den Host.\n"
 
-#: src/host.c:821
+#: src/host.c:784
 msgid "failed: timed out.\n"
 msgstr "fehlgeschlagen: Wartezeit abgelaufen.\n"
 
-#: src/html-url.c:298
+#: src/html-url.c:288
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Der unvollständige Link »%s« kann nicht aufgelöst werden.\n"
 
-#: src/html-url.c:705
+#: src/html-url.c:695
 #, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: %s: Ungültige URL »%s«.\n"
 
-#: src/http.c:373
+#: src/http.c:367
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Fehler beim Schreiben der HTTP-Anforderung: %s.\n"
 
-#: src/http.c:687
+#: src/http.c:736
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Keine Header, vermutlich ist es HTTP/0.9."
 
-#: src/http.c:1204
+#: src/http.c:1413
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "SSL wird ausgeschaltet nachdem Fehler aufgetreten sind.\n"
 
-#: src/http.c:1374
+#: src/http.c:1566
 #, c-format
 msgid "POST data file `%s' missing: %s\n"
 msgstr "POST Datendatei »%s« fehlt: %s\n"
 
-#: src/http.c:1423
+#: src/http.c:1615
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Wiederverwendung der bestehenden Verbindung zu %s:%d.\n"
 
-#: src/http.c:1492
+#: src/http.c:1684
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Fehler beim Lesen der Proxy-Antwort: %s.\n"
 
-#: src/http.c:1512
+#: src/http.c:1704
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Proxy-Tunneling fehlgeschlagen: %s"
 
 # Wieder das mit der 1. Person :)
-#: src/http.c:1557
+#: src/http.c:1749
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s Anforderung gesendet, warte auf Antwort... "
 
-#: src/http.c:1568
+#: src/http.c:1760
 msgid "No data received.\n"
 msgstr "Keine Daten empfangen.\n"
 
-#: src/http.c:1575
+#: src/http.c:1767
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lesefehler (%s) beim Vorspann (header).\n"
 
+#. If opt.noclobber is turned on and file already exists, do not
+#. retrieve the file
+#: src/http.c:1813
+#, c-format
+msgid ""
+"File `%s' already there; not retrieving.\n"
+"\n"
+msgstr "Die Datei »%s« ist schon vorhanden; kein erneuter Download.\n"
+
 #. If the authentication header is missing or
 #. unrecognized, there's no sense in retrying.
-#: src/http.c:1660
+#: src/http.c:1966
 msgid "Unknown authentication scheme.\n"
 msgstr "Unbekanntes Authentifizierungsschema.\n"
 
-#: src/http.c:1684
+#: src/http.c:1997
 msgid "Authorization failed.\n"
 msgstr "Authorisierung fehlgeschlagen.\n"
 
-#: src/http.c:1698
+#: src/http.c:2011
 msgid "Malformed status line"
 msgstr "Nicht korrekte Statuszeile"
 
-#: src/http.c:1700
+#: src/http.c:2013
 msgid "(no description)"
 msgstr "(keine Beschreibung)"
 
-#: src/http.c:1763
+#: src/http.c:2076
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Platz: %s%s\n"
 
-#: src/http.c:1764 src/http.c:1871
+#: src/http.c:2077 src/http.c:2184
 msgid "unspecified"
 msgstr "nicht spezifiziert"
 
-#: src/http.c:1765
+#: src/http.c:2078
 msgid " [following]"
 msgstr "[folge]"
 
 #. If `-c' is in use and the file has been fully downloaded (or
 #. the remote file has shrunk), Wget effectively requests bytes
 #. after the end of file and the server response with 416.
-#: src/http.c:1821
+#: src/http.c:2134
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
