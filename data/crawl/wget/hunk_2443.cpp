 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1778
+#: src/ftp.c:1753
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Hakulause \"%s\" ei löytänyt mitään.\n"
 
-#: src/ftp.c:1844
+#: src/ftp.c:1819
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "HTML-muotoiltu indeksi on kirjoitettu tiedostoon \"%s\" [%s].\n"
 
-#: src/ftp.c:1849
+#: src/ftp.c:1824
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "HTML-muotoiltu indeksi on kirjoitettu tiedostoon \"%s\".\n"
 
-#: src/getopt.c:675
+#: src/getopt.c:670
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: valitsin \"%s\" on moniselkoinen\n"
 
-#: src/getopt.c:700
+#: src/getopt.c:695
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: valitsin \"--%s\" ei salli argumenttia\n"
 
-#: src/getopt.c:705
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: valitsin \"%c%s\" ei salli argumenttia\n"
 
-#: src/getopt.c:723 src/getopt.c:896
+#: src/getopt.c:718 src/getopt.c:891
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: valitsin \"%s\" vaatii argumentin\n"
 
 #. --option
-#: src/getopt.c:752
+#: src/getopt.c:747
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: tuntematon valitsin \"--%s\"\n"
 
 #. +option or -option
-#: src/getopt.c:756
+#: src/getopt.c:751
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: tuntematon valitsin \"%c%s\"\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:782
+#: src/getopt.c:777
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: valitsin ei kelpaa -- %c\n"
 
-#: src/getopt.c:785
+#: src/getopt.c:780
 #, c-format
 msgid "%s: invalid option -- %c\n"
 msgstr "%s: valitsin on virheellinen -- %c\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:815 src/getopt.c:945
+#: src/getopt.c:810 src/getopt.c:940
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: valitsin vaatii argumentin -- %c\n"
 
-#: src/getopt.c:862
+#: src/getopt.c:857
 #, c-format
 msgid "%s: option `-W %s' is ambiguous\n"
 msgstr "%s: valitsin \"-W %s\" on moniselkoinen\n"
 
-#: src/getopt.c:880
+#: src/getopt.c:875
 #, c-format
 msgid "%s: option `-W %s' doesn't allow an argument\n"
 msgstr "%s: valitsin \"-W %s\" ei salli argumentteja\n"
 
-#: src/host.c:366
+#: src/host.c:347
 msgid "Unknown host"
 msgstr "Tuntematon palvelin"
 
 #. Message modeled after what gai_strerror returns in similar
 #. circumstances.
-#: src/host.c:370
+#: src/host.c:351
 msgid "Temporary failure in name resolution"
 msgstr "Väliaikainen virhe nimipalvelussa"
 
-#: src/host.c:372
+#: src/host.c:353
 msgid "Unknown error"
 msgstr "Tuntematon virhe"
 
-#: src/host.c:751
+#: src/host.c:714
 #, c-format
 msgid "Resolving %s... "
 msgstr "Selvitetään osoitetta %s... "
 
-#: src/host.c:798
+#: src/host.c:761
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr "epäonnistui: Palvelimelle ei ole IPv4/IPv6-osoitteita.\n"
 
-#: src/host.c:821
+#: src/host.c:784
 msgid "failed: timed out.\n"
 msgstr "epäonnistui: aikaraja ylittyi.\n"
 
-#: src/html-url.c:298
+#: src/html-url.c:288
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Epätäydellistä linkkiä %s ei voitu selvittää.\n"
 
-#: src/html-url.c:705
+#: src/html-url.c:695
 #, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: virheellinen URL %s: %s\n"
 
-#: src/http.c:373
+#: src/http.c:367
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "HTTP-pyynnön kirjoitus epäonnistui: %s.\n"
 
-#: src/http.c:687
+#: src/http.c:736
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Ei otsakkeita, oletetaan HTTP/0.9"
 
-#: src/http.c:1204
+#: src/http.c:1413
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "SSL otetaan pois päältä tapahtuneiden virheiden johdosta.\n"
 
-#: src/http.c:1374
+#: src/http.c:1566
 #, c-format
 msgid "POST data file `%s' missing: %s\n"
 msgstr "POST:n data-tiedosto \"%s\" puuttuu: %s\n"
 
-#: src/http.c:1423
+#: src/http.c:1615
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Käytetään uudelleen yhteyttä %s:%d.\n"
 
-#: src/http.c:1492
+#: src/http.c:1684
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Vastaanotto välityspalvelimelta epäonnistui: %s.\n"
 
-#: src/http.c:1512
+#: src/http.c:1704
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Välityspalvelintunnelointi epäonnistui: %s"
 
-#: src/http.c:1557
+#: src/http.c:1749
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s-pyyntö lähetetty, odotetaan vastausta... "
 
-#: src/http.c:1568
+#: src/http.c:1760
 msgid "No data received.\n"
 msgstr "Yhtään dataa ei vastaanotettu.\n"
 
-#: src/http.c:1575
+#: src/http.c:1767
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lukuvirhe (%s) otsakkeissa.\n"
 
+#. If opt.noclobber is turned on and file already exists, do not
+#. retrieve the file
+#: src/http.c:1813
+#, c-format
+msgid ""
+"File `%s' already there; not retrieving.\n"
+"\n"
+msgstr ""
+"Tiedostoa \"%s\" ei noudeta, koska se on jo paikalla.\n"
+"\n"
+
 #. If the authentication header is missing or
 #. unrecognized, there's no sense in retrying.
-#: src/http.c:1660
+#: src/http.c:1966
 msgid "Unknown authentication scheme.\n"
 msgstr "Tuntematon todennusjärjestelmä.\n"
 
-#: src/http.c:1684
+#: src/http.c:1997
 msgid "Authorization failed.\n"
 msgstr "Todentaminen epäonnistui.\n"
 
-#: src/http.c:1698
+#: src/http.c:2011
 msgid "Malformed status line"
 msgstr "Väärin muotoiltu Status-otsake"
 
-#: src/http.c:1700
+#: src/http.c:2013
 msgid "(no description)"
 msgstr "(ei kuvausta)"
 
-#: src/http.c:1763
+#: src/http.c:2076
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Sijainti: %s%s\n"
 
-#: src/http.c:1764 src/http.c:1871
+#: src/http.c:2077 src/http.c:2184
 msgid "unspecified"
 msgstr "määrittelemätön"
 
-#: src/http.c:1765
+#: src/http.c:2078
 msgid " [following]"
 msgstr " [seurataan]"
 
 #. If `-c' is in use and the file has been fully downloaded (or
 #. the remote file has shrunk), Wget effectively requests bytes
 #. after the end of file and the server response with 416.
-#: src/http.c:1821
+#: src/http.c:2134
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
