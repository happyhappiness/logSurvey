 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: optie vereist een argument -- %c\n"
 
-#: src/host.c:432
+#: src/host.c:394
 #, c-format
 msgid "%s: Cannot determine user-id.\n"
 msgstr "%s: Kan gebruikers-id niet bepalen.\n"
 
-#: src/host.c:444
+#: src/host.c:406
 #, c-format
 msgid "%s: Warning: uname failed: %s\n"
 msgstr "%s: Waarschuwing: uname gefaald: %s\n"
 
-#: src/host.c:456
+#: src/host.c:418
 #, c-format
 msgid "%s: Warning: gethostname failed\n"
 msgstr "%s: Waarschuwing: gethostname gefaald\n"
 
-#: src/host.c:484
+#: src/host.c:446
 #, c-format
 msgid "%s: Warning: cannot determine local IP address.\n"
 msgstr "%s: Waarschuwing: kan lokaal IP-adres niet bepalen.\n"
 
-#: src/host.c:498
+#: src/host.c:460
 #, c-format
 msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
 msgstr "%s: Waarschuwing: omgekeerd opzoeken van lokaal IP-adres onmogelijk.\n"
 
-#: src/host.c:506
+#. This gets ticked pretty often.  Karl Berry reports
+#. that there can be valid reasons for the local host
+#. name not to be an FQDN, so I've decided to remove the
+#. annoying warning.
+#: src/host.c:473
 #, c-format
 msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
 msgstr ""
 "%s: Waarschuwing: omgekeerd opzoeken van lokaal adres levert geen\n"
 "volledige domein naam.\n"
 
-#: src/host.c:533
+#: src/host.c:501
 msgid "Host not found"
 msgstr "Host niet gevonden"
 
-#: src/host.c:535
+#: src/host.c:503
 msgid "Unknown error"
 msgstr "Onbekende fout"
 
-#: src/html.c:435 src/html.c:437
-#, c-format
-msgid "Index of /%s on %s:%d"
-msgstr "Index van /%s op %s:%d"
-
-#: src/html.c:459
-msgid "time unknown       "
-msgstr "tijd onbekend     "
-
-#: src/html.c:463
-msgid "File        "
-msgstr "Bestand     "
-
-#: src/html.c:466
-msgid "Directory   "
-msgstr "Map         "
-
-#: src/html.c:469
-msgid "Link        "
-msgstr "Koppeling   "
-
-#: src/html.c:472
-msgid "Not sure    "
-msgstr "Niet zeker  "
+#: src/http.c:621 src/http.c:1433
+msgid "Unable to establish SSL connection.\n"
+msgstr ""
 
-#: src/html.c:490
-#, c-format
-msgid " (%s bytes)"
-msgstr " (%s Bytes)"
+#: src/http.c:629
+#, fuzzy, c-format
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Tracht verbinding met %s:%hu te herstellen.\n"
 
-#: src/http.c:492
-msgid "Failed writing HTTP request.\n"
+#: src/http.c:805
+#, fuzzy, c-format
+msgid "Failed writing HTTP request: %s.\n"
 msgstr "Schrijven HTTP-verzoek gefaald.\n"
 
-#: src/http.c:497
+#: src/http.c:810
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s verzoek verzonden, wacht op antwoord... "
 
-#: src/http.c:536
+#: src/http.c:854
 msgid "End of file while parsing headers.\n"
 msgstr "Bestandseinde bij ontleden kopregels.\n"
 
-#: src/http.c:547
+#: src/http.c:865
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Leesfout (%s) in kopregels.\n"
 
-#: src/http.c:587
+#: src/http.c:905
 msgid "No data received"
 msgstr "Geen gegevens ontvangen"
 
-#: src/http.c:589
+#: src/http.c:907
 msgid "Malformed status line"
 msgstr "Onjuiste statusregel"
 
-#: src/http.c:594
+#: src/http.c:912
 msgid "(no description)"
 msgstr "(geen beschrijving)"
 
-#. If we have tried it already, then there is not point
-#. retrying it.
-#: src/http.c:678
+#: src/http.c:1030
 msgid "Authorization failed.\n"
 msgstr "Authorisatie gefaald.\n"
 
-#: src/http.c:685
+#: src/http.c:1037
 msgid "Unknown authentication scheme.\n"
 msgstr "Onbekend authenticatieschema.\n"
 
-#: src/http.c:748
+#: src/http.c:1127
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Lokatie: %s%s\n"
 
-#: src/http.c:749 src/http.c:774
+#: src/http.c:1128 src/http.c:1153
 msgid "unspecified"
 msgstr "ongespecificeerd"
 
-#: src/http.c:750
+#: src/http.c:1129
 msgid " [following]"
 msgstr "[volgt]"
 
