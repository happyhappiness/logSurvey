 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Vil pr�ve � kontakte %s:%hu.\n"
 
-#: src/http.c:1684
+#: src/http.c:1683
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr ""
 
-#: src/http.c:1704
+#: src/http.c:1703
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr ""
 
-#: src/http.c:1749
+#: src/http.c:1748
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s foresp�rsel sendt, mottar topptekster... "
 
-#: src/http.c:1760
+#: src/http.c:1759
 #, fuzzy
 msgid "No data received.\n"
 msgstr "Ingen data mottatt"
 
-#: src/http.c:1767
+#: src/http.c:1766
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lesefeil (%s) i topptekster.\n"
 
-#. If opt.noclobber is turned on and file already exists, do not
-#. retrieve the file
-#: src/http.c:1813
+#: src/http.c:1812
 #, fuzzy, c-format
 msgid ""
 "File `%s' already there; not retrieving.\n"
 "\n"
 msgstr "File �%s� eksisterer allerede, ignoreres.\n"
 
-#. If the authentication header is missing or
-#. unrecognized, there's no sense in retrying.
-#: src/http.c:1966
+#: src/http.c:1965
 msgid "Unknown authentication scheme.\n"
 msgstr "Ukjent autorisasjons-protokoll.\n"
 
-#: src/http.c:1997
+#: src/http.c:1996
 msgid "Authorization failed.\n"
 msgstr "Autorisasjon mislyktes\n"
 
-#: src/http.c:2011
+#: src/http.c:2010
 msgid "Malformed status line"
 msgstr "Feil i statuslinje"
 
-#: src/http.c:2013
+#: src/http.c:2012
 msgid "(no description)"
 msgstr "(ingen beskrivelse)"
 
-#: src/http.c:2076
+#: src/http.c:2075
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Sted: %s%s\n"
 
-#: src/http.c:2077 src/http.c:2184
+#: src/http.c:2076 src/http.c:2183
 msgid "unspecified"
 msgstr "uspesifisert"
 
-#: src/http.c:2078
+#: src/http.c:2077
 msgid " [following]"
 msgstr " [omdirigert]"
 
-#. If `-c' is in use and the file has been fully downloaded (or
-#. the remote file has shrunk), Wget effectively requests bytes
-#. after the end of file and the server response with 416.
-#: src/http.c:2134
+#: src/http.c:2133
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 
-#. No need to print this output if the body won't be
-#. downloaded at all, or if the original server response is
-#. printed.
-#: src/http.c:2164
+#: src/http.c:2163
 msgid "Length: "
 msgstr "Lengde: "
 
-#: src/http.c:2184
+#: src/http.c:2183
 msgid "ignored"
 msgstr "ignoreres"
 
-#: src/http.c:2255
+#: src/http.c:2254
 #, fuzzy, c-format
 msgid "Saving to: `%s'\n"
 msgstr "Ignorerer katalog �%s�.\n"
