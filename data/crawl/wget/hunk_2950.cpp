 msgid "%s: option `-W %s' doesn't allow an argument\n"
 msgstr "%s: valinta \"-W %s\" ei hyväksy parametrejä\n"
 
-#: src/host.c:636
+#: src/host.c:368
+#, fuzzy
+msgid "Unknown host"
+msgstr "Tuntematon virhe"
+
+#. Message modeled after what gai_strerror returns in similar
+#. circumstances.
+#: src/host.c:372
+msgid "Temporary failure in name resolution"
+msgstr ""
+
+#: src/host.c:374
+msgid "Unknown error"
+msgstr "Tuntematon virhe"
+
+#: src/host.c:748
 #, c-format
 msgid "Resolving %s... "
 msgstr "Selvitetään osoitetta %s... "
 
-#: src/host.c:656 src/host.c:672
+#: src/host.c:792 src/host.c:839
 #, c-format
 msgid "failed: %s.\n"
 msgstr "epäonnistui: %s.\n"
 
-#: src/host.c:674
+#: src/host.c:801
+msgid "failed: No IPv4/IPv6 addresses for host.\n"
+msgstr ""
+
+#: src/host.c:842
 msgid "failed: timed out.\n"
 msgstr "epäonnistui: aikaraja ylittyi.\n"
 
-#: src/host.c:762
-msgid "Host not found"
-msgstr "Palvelinta ei löytynyt"
-
-#: src/host.c:764
-msgid "Unknown error"
-msgstr "Tuntematon virhe"
-
-#: src/html-url.c:293
+#: src/html-url.c:297
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Epätäydellistä linkkiä %s ei voi selvittää.\n"
 
+#: src/http.c:349 src/http.c:1504
+#, c-format
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "HTTP-pyynnön kirjoitus epäonnistui: %s.\n"
+
+#: src/http.c:663
+msgid "No headers, assuming HTTP/0.9"
+msgstr ""
+
 #. this is fatal
-#: src/http.c:674
+#: src/http.c:1151
 msgid "Failed to set up an SSL context\n"
 msgstr "SSL-kontekstin asettaminen epäonnistui\n"
 
-#: src/http.c:680
+#: src/http.c:1156
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "Varmenteen lataaminen epäonnistui kohteesta %s\n"
 
-#: src/http.c:684 src/http.c:692
+#: src/http.c:1159 src/http.c:1166
 msgid "Trying without the specified certificate\n"
 msgstr "Yritetään ilman määriteltyä varmennetta\n"
 
-#: src/http.c:688
+#: src/http.c:1163
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "Varmenteen haku ei onnistunut kohteesta %s\n"
 
-#: src/http.c:761 src/http.c:1809
-msgid "Unable to establish SSL connection.\n"
-msgstr "SSL-yhteyden muodostaminen ei onnistu.\n"
-
-#: src/http.c:770
-#, c-format
-msgid "Reusing connection to %s:%hu.\n"
+#: src/http.c:1382
+#, fuzzy, c-format
+msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Uudelleenkäytetään yhteyttä %s:%hu.\n"
 
-#: src/http.c:1034
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
+#: src/http.c:1434
+#, fuzzy, c-format
+msgid "Failed writing to proxy: %s.\n"
+msgstr "HTTP-pyynnön kirjoitus epäonnistui: %s.\n"
+
+#: src/http.c:1443
+#, fuzzy, c-format
+msgid "Failed reading proxy response: %s\n"
 msgstr "HTTP-pyynnön kirjoitus epäonnistui: %s.\n"
 
-#: src/http.c:1039
+#: src/http.c:1463
+#, c-format
+msgid "Proxy tunneling failed: %s"
+msgstr ""
+
+#: src/http.c:1510
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s-pyyntö lähetetty, odotetaan vastausta... "
 
-#: src/http.c:1083
-msgid "End of file while parsing headers.\n"
-msgstr "Tiedoston loppu otsakkeita jäsennettäessä.\n"
+#: src/http.c:1521
+#, fuzzy
+msgid "No data received.\n"
+msgstr "Dataa ei ole vastaanotettu"
 
-#: src/http.c:1093
+#: src/http.c:1528
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lukuvirhe (%s) otsakkeissa.\n"
 
-#: src/http.c:1128
-msgid "No data received"
-msgstr "Dataa ei ole vastaanotettu"
+#. If we have tried it already, then there is not point
+#. retrying it.
+#: src/http.c:1595
+msgid "Authorization failed.\n"
+msgstr "Todentaminen epäonnistui.\n"
+
+#: src/http.c:1609
+msgid "Unknown authentication scheme.\n"
+msgstr "Tuntematon varmennusjärjestelmä.\n"
 
-#: src/http.c:1130
+#: src/http.c:1634
 msgid "Malformed status line"
 msgstr "Väärin muotoiltu tilarivi"
 
-#: src/http.c:1135
+#: src/http.c:1636
 msgid "(no description)"
 msgstr "(ei kuvausta)"
 
-#: src/http.c:1267
-msgid "Authorization failed.\n"
-msgstr "Todentaminen epäonnistui.\n"
-
-#: src/http.c:1274
-msgid "Unknown authentication scheme.\n"
-msgstr "Tuntematon varmennusjärjestelmä.\n"
-
-#: src/http.c:1314
+#: src/http.c:1700
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Sijainti: %s%s\n"
 
-#: src/http.c:1315 src/http.c:1454
+#: src/http.c:1701 src/http.c:1801
 msgid "unspecified"
 msgstr "määrittelemätön"
 
-#: src/http.c:1316
+#: src/http.c:1702
 msgid " [following]"
 msgstr " [seurataan]"
 
-#: src/http.c:1383
+#. If `-c' is in use and the file has been fully downloaded (or
+#. the remote file has shrunk), Wget effectively requests bytes
+#. after the end of file and the server response with 416.
+#: src/http.c:1751
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
