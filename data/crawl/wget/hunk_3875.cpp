 #. that there can be valid reasons for the local host
 #. name not to be an FQDN, so I've decided to remove the
 #. annoying warning.
-#: src/host.c:517
+#: src/host.c:473
 #, c-format
 msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
 msgstr "%s: Upozorenje: reverzni lookup lokalne adrese ne daje FQDN!\n"
 
-#: src/host.c:545
+#: src/host.c:501
 msgid "Host not found"
 msgstr "Ra�unalo nije prona�eno"
 
-#: src/host.c:547
+#: src/host.c:503
 msgid "Unknown error"
 msgstr "Nepoznata gre�ka"
 
-#: src/html.c:615 src/html.c:617
-#, c-format
-msgid "Index of /%s on %s:%d"
-msgstr "Indeks direktorija /%s na %s:%d"
-
-#: src/html.c:639
-msgid "time unknown       "
-msgstr "nepoznato vrijeme    "
-
-#: src/html.c:643
-msgid "File        "
-msgstr "Datoteka    "
-
-#: src/html.c:646
-msgid "Directory   "
-msgstr "Direktorij  "
-
-#: src/html.c:649
-msgid "Link        "
-msgstr "Link        "
+#: src/http.c:621 src/http.c:1433
+msgid "Unable to establish SSL connection.\n"
+msgstr "Ne mogu uspostaviti SSL vezu.\n"
 
-#: src/html.c:652
-msgid "Not sure    "
-msgstr "Ne znam     "
-
-#: src/html.c:670
+#: src/http.c:629
 #, c-format
-msgid " (%s bytes)"
-msgstr " (%s bajtova)"
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Koristim postoje�u vezu prema %s:%hu.\n"
 
-#: src/http.c:508
-msgid "Failed writing HTTP request.\n"
-msgstr "Nisam uspio poslati HTTP zahtjev.\n"
+#: src/http.c:805
+#, c-format
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Nisam uspio poslati HTTP zahtjev: %s.\n"
 
-#: src/http.c:512
+#: src/http.c:810
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s zahtjev poslan, �ekam odgovor... "
 
-#: src/http.c:551
+#: src/http.c:854
 msgid "End of file while parsing headers.\n"
 msgstr "Kraj datoteke za vrijeme obrade zaglavlja.\n"
 
-#: src/http.c:562
+#: src/http.c:865
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Gre�ka pri �itanju zaglavlja (%s).\n"
 
-#: src/http.c:602
+#: src/http.c:905
 msgid "No data received"
 msgstr "Podaci nisu primljeni"
 
-#: src/http.c:604
+#: src/http.c:907
 msgid "Malformed status line"
 msgstr "Deformirana statusna linija"
 
-#: src/http.c:609
+#: src/http.c:912
 msgid "(no description)"
 msgstr "(bez opisa)"
 
-#. If we have tried it already, then there is not point
-#. retrying it.
-#: src/http.c:693
+#: src/http.c:1030
 msgid "Authorization failed.\n"
 msgstr "Ovjera nije uspjela.\n"
 
-#: src/http.c:700
+#: src/http.c:1037
 msgid "Unknown authentication scheme.\n"
 msgstr "Nepoznata metoda ovjere.\n"
 
-#: src/http.c:783
+#: src/http.c:1127
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Polo�aj: %s%s\n"
 
-#: src/http.c:784 src/http.c:809
+#: src/http.c:1128 src/http.c:1153
 msgid "unspecified"
 msgstr "neodre�en"
 
-#: src/http.c:785
+#: src/http.c:1129
 msgid " [following]"
 msgstr " [pratim]"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:799
+#: src/http.c:1143
 msgid "Length: "
 msgstr "Duljina: "
 
-#: src/http.c:804
+#: src/http.c:1148
 #, c-format
 msgid " (%s to go)"
 msgstr " (jo� %s)"
 
-#: src/http.c:809
+#: src/http.c:1153
 msgid "ignored"
 msgstr "zanemarena"
 
-#: src/http.c:912
+#: src/http.c:1254
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Upozorenje: wildcardi nisu podr�ani za HTTP.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:933
+#: src/http.c:1275
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Datoteka `%s' ve� postoji, ne skidam.\n"
 
-#: src/http.c:1099
+#: src/http.c:1425
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Ne mogu pisati u `%s' (%s).\n"
 
-#: src/http.c:1110
+#: src/http.c:1443
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "GRE�KA: Redirekcija (%d) bez novog polo�aja (location).\n"
 
-#: src/http.c:1135
+#: src/http.c:1468
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s GRE�KA %d: %s.\n"
 
-#: src/http.c:1148
+#: src/http.c:1481
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Nedostaje Last-Modified zaglavlje -- ignoriram vremensku oznaku.\n"
 
-#: src/http.c:1156
+#: src/http.c:1489
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "Nevaljan Last-Modified header -- ignoriram vremensku oznaku.\n"
 
-#: src/http.c:1191
+#: src/http.c:1524
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Datoteka na poslu�itelju je novija, skidam.\n"
 
-#: src/http.c:1226
+#: src/http.c:1559
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld]\n"
