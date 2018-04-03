 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Používam existujúce spojenie s %s:%d.\n"
 
-#: src/http.c:1684
+#: src/http.c:1683
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Zlyhalo čítanie odpovede z proxy: %s\n"
 
-#: src/http.c:1704
+#: src/http.c:1703
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Tunelovanie proxy zlyhalo: %s"
 
 # , c-format
-#: src/http.c:1749
+#: src/http.c:1748
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s požiadavka odoslaná, čakám na odpoveď... "
 
-#: src/http.c:1760
+#: src/http.c:1759
 msgid "No data received.\n"
 msgstr "Neboli prijaté žiadne dáta.\n"
 
 # , c-format
-#: src/http.c:1767
+#: src/http.c:1766
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Chyba (%s) pri čítaní hlavičiek.\n"
 
 # , c-format
-#. If opt.noclobber is turned on and file already exists, do not
-#. retrieve the file
-#: src/http.c:1813
+#: src/http.c:1812
 #, c-format
 msgid ""
 "File `%s' already there; not retrieving.\n"
 "\n"
 msgstr "Súbor `%s' je už tam, nebudem ho prenášať.\n"
 
-#. If the authentication header is missing or
-#. unrecognized, there's no sense in retrying.
-#: src/http.c:1966
+#: src/http.c:1965
 msgid "Unknown authentication scheme.\n"
 msgstr "Neznámy spôsob autentifikácie.\n"
 
-#: src/http.c:1997
+#: src/http.c:1996
 msgid "Authorization failed.\n"
 msgstr "Autorizácia zlyhala.\n"
 
-#: src/http.c:2011
+#: src/http.c:2010
 msgid "Malformed status line"
 msgstr "Odpoveď servera má skomolený stavový riadok"
 
-#: src/http.c:2013
+#: src/http.c:2012
 msgid "(no description)"
 msgstr "(bez popisu)"
 
 # , c-format
-#: src/http.c:2076
+#: src/http.c:2075
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Presmerované na: %s%s\n"
 
-#: src/http.c:2077 src/http.c:2184
+#: src/http.c:2076 src/http.c:2183
 msgid "unspecified"
 msgstr "neudané"
 
-#: src/http.c:2078
+#: src/http.c:2077
 msgid " [following]"
 msgstr " [nasledujem]"
 
-#. If `-c' is in use and the file has been fully downloaded (or
-#. the remote file has shrunk), Wget effectively requests bytes
-#. after the end of file and the server response with 416.
-#: src/http.c:2134
+#: src/http.c:2133
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
