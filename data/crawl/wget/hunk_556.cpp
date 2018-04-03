 "Link simbolico già esistente %s -> %s\n"
 "\n"
 
-#: src/ftp.c:1533
+#: src/ftp.c:1788
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Creazione del link simbolico %s -> %s\n"
 
-#: src/ftp.c:1543
+#: src/ftp.c:1798
 #, fuzzy, c-format
 msgid "Symlinks not supported, skipping symlink %s.\n"
 msgstr "Link simbolici non gestiti, link \"%s\" saltato.\n"
 
-#: src/ftp.c:1555
+#: src/ftp.c:1810
 #, fuzzy, c-format
 msgid "Skipping directory %s.\n"
 msgstr "Directory \"%s\" saltata.\n"
 
-#: src/ftp.c:1564
+#: src/ftp.c:1819
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: tipo di file sconosciuto/non gestito.\n"
 
-#: src/ftp.c:1591
+#: src/ftp.c:1856
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: timestamp danneggiato.\n"
 
-#: src/ftp.c:1619
+#: src/ftp.c:1878
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr ""
 "Le directory non verranno scaricate perché la loro profondità è %d (max %"
 "d).\n"
 
-#: src/ftp.c:1669
+#: src/ftp.c:1928
 #, fuzzy, c-format
 msgid "Not descending to %s as it is excluded/not-included.\n"
 msgstr "Non si discende nella directory \"%s\" perché è esclusa/non inclusa.\n"
 
-#: src/ftp.c:1735 src/ftp.c:1749
+#: src/ftp.c:1994 src/ftp.c:2008
 #, fuzzy, c-format
 msgid "Rejecting %s.\n"
 msgstr "\"%s\" rifiutato.\n"
 
-#: src/ftp.c:1772
+#: src/ftp.c:2031
 #, c-format
 msgid "Error matching %s against %s: %s\n"
 msgstr "Errore nella corrispondenza di %s con %s: %s.\n"
 
-#: src/ftp.c:1814
+#: src/ftp.c:2073
 #, fuzzy, c-format
 msgid "No matches on pattern %s.\n"
 msgstr "Nessun corrispondenza con il modello \"%s\".\n"
 
-#: src/ftp.c:1880
+#: src/ftp.c:2144
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s [%s].\n"
 msgstr "Indice in formato HTML scritto in \"%s\" [%s].\n"
 
-#: src/ftp.c:1885
+#: src/ftp.c:2149
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s.\n"
 msgstr "Indice in formato HTML scritto in \"%s\".\n"
 
-#: src/host.c:348
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "ERROR"
+msgstr "ERRORE"
+
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "WARNING"
+msgstr "AVVERTIMENTO"
+
+#: src/gnutls.c:225 src/openssl.c:504
+#, c-format
+msgid "%s: No certificate presented by %s.\n"
+msgstr "%s: nessun certificato presentato da %s.\n"
+
+#: src/gnutls.c:233
+#, fuzzy, c-format
+msgid "%s: The certificate of %s is not trusted.\n"
+msgstr "%s: nessun certificato presentato da %s.\n"
+
+#: src/gnutls.c:239
+#, c-format
+msgid "%s: The certificate of %s hasn't got a known issuer.\n"
+msgstr ""
+
+#: src/gnutls.c:245
+#, fuzzy, c-format
+msgid "%s: The certificate of %s has been revoked.\n"
+msgstr "  Il certificato rilasciato è scaduto.\n"
+
+#: src/gnutls.c:259
+#, c-format
+msgid "Error initializing X509 certificate: %s\n"
+msgstr ""
+
+#: src/gnutls.c:268
+#, fuzzy
+msgid "No certificate found\n"
+msgstr "%s: nessun certificato presentato da %s.\n"
+
+#: src/gnutls.c:275
+#, fuzzy, c-format
+msgid "Error parsing certificate: %s\n"
+msgstr "Errore analizzando l'URL del proxy %s: %s.\n"
+
+#: src/gnutls.c:282
+#, fuzzy
+msgid "The certificate has not yet been activated\n"
+msgstr "  Il certificato rilasciato non è ancora valido.\n"
+
+#: src/gnutls.c:287
+#, fuzzy
+msgid "The certificate has expired\n"
+msgstr "  Il certificato rilasciato è scaduto.\n"
+
+#: src/gnutls.c:293
+#, fuzzy, c-format
+msgid "The certificate's owner does not match hostname '%s'\n"
+msgstr ""
+"%s: il nome comune di certificato \"%s\" non corrisponde al nome dell'host "
+"richiesto \"%s\".\n"
+
+#: src/host.c:358
 msgid "Unknown host"
 msgstr "Host sconosciuto"
 
-#: src/host.c:352
+#: src/host.c:362
 msgid "Temporary failure in name resolution"
 msgstr "Risoluzione del nome temporaneamente fallita"
 
-#: src/host.c:354
+#: src/host.c:364
 msgid "Unknown error"
 msgstr "Errore sconosciuto"
 
-#: src/host.c:715
+#: src/host.c:737
 #, c-format
 msgid "Resolving %s... "
 msgstr "Risoluzione di %s... "
 
-#: src/host.c:763
+#: src/host.c:789
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr "fallito: nessun indirizzo IPv4/IPv6 per l'host.\n"
 
-#: src/host.c:786
+#: src/host.c:812
 msgid "failed: timed out.\n"
 msgstr "fallito: tempo scaduto.\n"
 
-#: src/html-url.c:289
+#: src/html-url.c:286
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: impossibile risolvere il link incompleto %s.\n"
 
-#: src/html-url.c:696
+#: src/html-url.c:762
 #, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: URL non valido %s: %s\n"
 
-#: src/http.c:368
+#: src/http.c:377
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Scrittura della richiesta HTTP non riuscita: %s.\n"
 
-#: src/http.c:745
+#: src/http.c:754
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Nessuna intestazione, si assume HTTP/0.9"
 
-#: src/http.c:1430
+#: src/http.c:1456
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "SSL disabilitato a causa di errori.\n"
 
-#: src/http.c:1548
+#: src/http.c:1576
 #, fuzzy, c-format
 msgid "POST data file %s missing: %s\n"
 msgstr "File di dati POST \"%s\" mancante: %s\n"
 
-#: src/http.c:1632
+#: src/http.c:1660
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Riutilizzo della connessione esistente a %s:%d.\n"
 
-#: src/http.c:1701
+#: src/http.c:1729
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Lettura della risposta del proxy non riuscita: %s.\n"
 
-#: src/http.c:1721
+#: src/http.c:1750
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Proxy tunneling non riuscito: %s"
 
-#: src/http.c:1766
+#: src/http.c:1795
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s richiesta inviata, in attesa di risposta... "
 
-#: src/http.c:1777
+#: src/http.c:1806
 msgid "No data received.\n"
 msgstr "Nessun dato ricevuto.\n"
 
-#: src/http.c:1784
+#: src/http.c:1813
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Errore di lettura nelle intestazioni (%s).\n"
 
-#: src/http.c:1831 src/http.c:2385
+#: src/http.c:1884
+msgid "Unknown authentication scheme.\n"
+msgstr "Schema di autotentificazione sconosciuto.\n"
+
+#: src/http.c:1918
+msgid "Authorization failed.\n"
+msgstr "Autorizzazione fallita.\n"
+
+#: src/http.c:1956 src/http.c:2466
 #, fuzzy, c-format
 msgid ""
 "File %s already there; not retrieving.\n"
