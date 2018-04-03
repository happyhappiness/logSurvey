 "Oikea symbolinen linkki %s -> %s on jo paikallaan.\n"
 "\n"
 
-#: src/ftp.c:1493
+#: src/ftp.c:1494
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Luodaan symbolinen linkki %s -> %s\n"
 
-#: src/ftp.c:1503
+#: src/ftp.c:1504
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr "Ei tukea symbolisille linkeille, ohitetaan \"%s\".\n"
+msgstr "Ei tukea symbolisille linkeille, ohitetaan ‚Äù%s‚Äù.\n"
 
-#: src/ftp.c:1515
+#: src/ftp.c:1516
 #, c-format
 msgid "Skipping directory `%s'.\n"
-msgstr "Ohitetaan hakemisto \"%s\".\n"
+msgstr "Ohitetaan hakemisto ‚Äù%s‚Äù.\n"
 
-#: src/ftp.c:1524
+#: src/ftp.c:1525
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: tuntematon/tukematon tiedostotyyppi.\n"
 
-#: src/ftp.c:1551
+#: src/ftp.c:1552
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
-msgstr "%s: v‰‰ristynyt aikaleima.\n"
+msgstr "%s: v√§√§ristynyt aikaleima.\n"
 
-#: src/ftp.c:1579
+#: src/ftp.c:1580
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Hakemistoja ei noudeta, koska syvyys on %d (raja %d).\n"
 
-#: src/ftp.c:1629
+#: src/ftp.c:1630
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
-msgstr "Hakemiston \"%s\" sis‰ltˆ‰ ei noudeta, koska se on poissuljettu.\n"
+msgstr "Hakemiston ‚Äù%s‚Äù sis√§lt√∂√§ ei noudeta, koska se on poissuljettu.\n"
 
-#: src/ftp.c:1695 src/ftp.c:1709
+#: src/ftp.c:1696 src/ftp.c:1710
 #, c-format
 msgid "Rejecting `%s'.\n"
-msgstr "Hyl‰t‰‰n \"%s\".\n"
+msgstr "Hyl√§t√§√§n ‚Äù%s‚Äù.\n"
+
+#: src/ftp.c:1733
+#, fuzzy, c-format
+msgid "Error matching %s against %s: %s\n"
+msgstr "Kirjoitettaessa tiedostoon ‚Äù%s‚Äù tapahtui virhe: %s\n"
 
-#: src/ftp.c:1757
+#: src/ftp.c:1774
 #, c-format
 msgid "No matches on pattern `%s'.\n"
-msgstr "Hakulause \"%s\" ei lˆyt‰nyt mit‰‰n.\n"
+msgstr "Hakulause ‚Äù%s‚Äù ei l√∂yt√§nyt mit√§√§n.\n"
 
-#: src/ftp.c:1823
+#: src/ftp.c:1840
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%s].\n"
-msgstr "HTML-muotoiltu indeksi on kirjoitettu tiedostoon \"%s\" [%s].\n"
+msgstr "HTML-muotoiltu indeksi on kirjoitettu tiedostoon ‚Äù%s‚Äù [%s].\n"
 
-#: src/ftp.c:1828
+#: src/ftp.c:1845
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
-msgstr "HTML-muotoiltu indeksi on kirjoitettu tiedostoon \"%s\".\n"
+msgstr "HTML-muotoiltu indeksi on kirjoitettu tiedostoon ‚Äù%s‚Äù.\n"
 
-#: src/host.c:347
+#: src/host.c:348
 msgid "Unknown host"
 msgstr "Tuntematon palvelin"
 
-#: src/host.c:351
+#: src/host.c:352
 msgid "Temporary failure in name resolution"
-msgstr "V‰liaikainen virhe nimipalvelussa"
+msgstr "V√§liaikainen virhe nimipalvelussa"
 
-#: src/host.c:353
+#: src/host.c:354
 msgid "Unknown error"
 msgstr "Tuntematon virhe"
 
-#: src/host.c:714
+#: src/host.c:715
 #, c-format
 msgid "Resolving %s... "
-msgstr "Selvitet‰‰n osoitetta %s... "
+msgstr "Selvitet√§√§n osoitetta %s... "
 
-#: src/host.c:761
+#: src/host.c:762
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
-msgstr "ep‰onnistui: Palvelimelle ei ole IPv4/IPv6-osoitteita.\n"
+msgstr "ep√§onnistui: Palvelimelle ei ole IPv4/IPv6-osoitteita.\n"
 
-#: src/host.c:784
+#: src/host.c:785
 msgid "failed: timed out.\n"
-msgstr "ep‰onnistui: aikaraja ylittyi.\n"
+msgstr "ep√§onnistui: aikaraja ylittyi.\n"
 
-#: src/html-url.c:288
+#: src/html-url.c:289
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
-msgstr "%s: Ep‰t‰ydellist‰ linkki‰ %s ei voitu selvitt‰‰.\n"
+msgstr "%s: Ep√§t√§ydellist√§ linkki√§ %s ei voitu selvitt√§√§.\n"
 
-#: src/html-url.c:695
+#: src/html-url.c:696
 #, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: virheellinen URL %s: %s\n"
 
-#: src/http.c:367
+#: src/http.c:368
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
-msgstr "HTTP-pyynnˆn kirjoitus ep‰onnistui: %s.\n"
+msgstr "HTTP-pyynn√∂n kirjoitus ep√§onnistui: %s.\n"
 
-#: src/http.c:736
+#: src/http.c:737
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Ei otsakkeita, oletetaan HTTP/0.9"
 
-#: src/http.c:1413
+#: src/http.c:1417
 msgid "Disabling SSL due to encountered errors.\n"
-msgstr "SSL otetaan pois p‰‰lt‰ tapahtuneiden virheiden johdosta.\n"
+msgstr "SSL otetaan pois p√§√§lt√§ tapahtuneiden virheiden johdosta.\n"
 
-#: src/http.c:1566
+#: src/http.c:1570
 #, c-format
 msgid "POST data file `%s' missing: %s\n"
-msgstr "POST:n data-tiedosto \"%s\" puuttuu: %s\n"
+msgstr "POST-metodin data-tiedosto ‚Äù%s‚Äù puuttuu: %s\n"
 
-#: src/http.c:1615
+#: src/http.c:1619
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
-msgstr "K‰ytet‰‰n uudelleen yhteytt‰ %s:%d.\n"
+msgstr "K√§ytet√§√§n uudelleen yhteytt√§ %s:%d.\n"
 
-#: src/http.c:1683
+#: src/http.c:1687
 #, c-format
 msgid "Failed reading proxy response: %s\n"
-msgstr "Vastaanotto v‰lityspalvelimelta ep‰onnistui: %s.\n"
+msgstr "Vastaanotto v√§lityspalvelimelta ep√§onnistui: %s.\n"
 
-#: src/http.c:1703
+#: src/http.c:1707
 #, c-format
 msgid "Proxy tunneling failed: %s"
-msgstr "V‰lityspalvelintunnelointi ep‰onnistui: %s"
+msgstr "V√§lityspalvelintunnelointi ep√§onnistui: %s"
 
-#: src/http.c:1748
+#: src/http.c:1752
 #, c-format
 msgid "%s request sent, awaiting response... "
-msgstr "%s-pyyntˆ l‰hetetty, odotetaan vastausta... "
+msgstr "%s-pyynt√∂ l√§hetetty, odotetaan vastausta... "
 
-#: src/http.c:1759
+#: src/http.c:1763
 msgid "No data received.\n"
-msgstr "Yht‰‰n dataa ei vastaanotettu.\n"
+msgstr "Yht√§√§n dataa ei vastaanotettu.\n"
 
-#: src/http.c:1766
+#: src/http.c:1770
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lukuvirhe (%s) otsakkeissa.\n"
 
-#: src/http.c:1812
+#: src/http.c:1816 src/http.c:2368
 #, c-format
 msgid ""
 "File `%s' already there; not retrieving.\n"
 "\n"
 msgstr ""
-"Tiedostoa \"%s\" ei noudeta, koska se on jo paikalla.\n"
+"Tiedostoa ‚Äù%s‚Äù ei noudeta, koska se on jo paikalla.\n"
 "\n"
 
-#: src/http.c:1965
+#: src/http.c:1969
 msgid "Unknown authentication scheme.\n"
-msgstr "Tuntematon todennusj‰rjestelm‰.\n"
+msgstr "Tuntematon todennusj√§rjestelm√§.\n"
 
-#: src/http.c:1996
+#: src/http.c:2000
 msgid "Authorization failed.\n"
-msgstr "Todentaminen ep‰onnistui.\n"
+msgstr "Todentaminen ep√§onnistui.\n"
 
-#: src/http.c:2010
+#: src/http.c:2014
 msgid "Malformed status line"
-msgstr "V‰‰rin muotoiltu Status-otsake"
+msgstr "V√§√§rin muotoiltu Status-otsake"
 
-#: src/http.c:2012
+#: src/http.c:2016
 msgid "(no description)"
 msgstr "(ei kuvausta)"
 
-#: src/http.c:2075
+#: src/http.c:2082
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Sijainti: %s%s\n"
 
-#: src/http.c:2076 src/http.c:2183
+#: src/http.c:2083 src/http.c:2193
 msgid "unspecified"
-msgstr "m‰‰rittelem‰tˆn"
+msgstr "m√§√§rittelem√§t√∂n"
 
-#: src/http.c:2077
+#: src/http.c:2084
 msgid " [following]"
 msgstr " [seurataan]"
 
-#: src/http.c:2133
+#: src/http.c:2140
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
