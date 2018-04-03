 msgid "%s: option `-W %s' doesn't allow an argument\n"
 msgstr "%s: uz opciju `-W %s' ne ide argument\n"
 
-#: src/connect.c:194
+#: src/connect.c:195
 #, c-format
 msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
 msgstr "%s: ne mogu pronaæi adresu `%s' u svrhu binda; bindanje onemoguæeno.\n"
 
-#: src/connect.c:266
+#: src/connect.c:267
 #, c-format
 msgid "Connecting to %s|%s|:%d... "
 msgstr "Spajam se na %s|%s|:%d... "
 
-#: src/connect.c:269
+#: src/connect.c:270
 #, c-format
 msgid "Connecting to %s:%d... "
 msgstr "Spajam se na %s:%d... "
 
-#: src/connect.c:329
+#: src/connect.c:330
 msgid "connected.\n"
 msgstr "spojen.\n"
 
-#: src/connect.c:341 src/host.c:752 src/host.c:781
+#: src/connect.c:342 src/host.c:753 src/host.c:782
 #, c-format
 msgid "failed: %s.\n"
 msgstr "nije uspjelo: %s.\n"
 
-#: src/connect.c:365 src/http.c:1628
+#: src/connect.c:366 src/http.c:1632
 #, fuzzy, c-format
 msgid "%s: unable to resolve host address `%s'\n"
 msgstr "%s: ne mogu pronaæi adresu `%s' u svrhu binda; bindanje onemoguæeno.\n"
 
-#: src/convert.c:169
+#: src/convert.c:170
 #, fuzzy, c-format
 msgid "Converted %d files in %s seconds.\n"
 msgstr "Konvertirao %d spisa za %.*f sekundi.\n"
 
-#: src/convert.c:194
+#: src/convert.c:197
 #, c-format
 msgid "Converting %s... "
 msgstr "Konvertiram %s... "
 
-#: src/convert.c:207
+#: src/convert.c:210
 msgid "nothing to do.\n"
 msgstr "nema posla.\n"
 
-#: src/convert.c:215 src/convert.c:239
+#: src/convert.c:218 src/convert.c:242
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Ne mogu konvertirati linkove u %s: %s\n"
 
-#: src/convert.c:230
+#: src/convert.c:233
 #, c-format
 msgid "Unable to delete `%s': %s\n"
 msgstr "Ne mogu izbrisati `%s': %s\n"
 
-#: src/convert.c:439
+#: src/convert.c:442
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "Ne mogu snimiti backup iz %s u %s: %s\n"
 
-#: src/cookies.c:442
+#: src/cookies.c:443
 #, c-format
 msgid "Syntax error in Set-Cookie: %s at position %d.\n"
 msgstr "Gre¹ka u Set-Cookie: %s na poziciji %d.\n"
 
-#: src/cookies.c:684
+#: src/cookies.c:685
 #, c-format
 msgid "Cookie coming from %s attempted to set domain to %s\n"
 msgstr "Cookie s adrese %s poku¹ao je postaviti domenu na %s\n"
 
-#: src/cookies.c:1131 src/cookies.c:1249
+#: src/cookies.c:1132 src/cookies.c:1250
 #, c-format
 msgid "Cannot open cookies file `%s': %s\n"
 msgstr "Ne mogu otvoriti spis s cookiejima `%s': %s\n"
 
-#: src/cookies.c:1286
+#: src/cookies.c:1287
 #, c-format
 msgid "Error writing to `%s': %s\n"
 msgstr "Gre¹ka pri pisanju u `%s': %s\n"
 
-#: src/cookies.c:1289
+#: src/cookies.c:1290
 #, c-format
 msgid "Error closing `%s': %s\n"
 msgstr "Gre¹ka pri zatvaranju `%s': %s\n"
 
-#: src/ftp-ls.c:835
+#: src/ftp-ls.c:836
 msgid "Unsupported listing type, trying Unix listing parser.\n"
 msgstr ""
 "Nepodr¾ana vrsta ispisa, poku¹avat æu s razluèiteljem Unixovog ispisa.\n"
 
-#: src/ftp-ls.c:881 src/ftp-ls.c:883
+#: src/ftp-ls.c:882 src/ftp-ls.c:884
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Indeks direktorija /%s na %s:%d"
 
-#: src/ftp-ls.c:906
+#: src/ftp-ls.c:907
 #, c-format
 msgid "time unknown       "
 msgstr "nepoznato vrijeme    "
 
-#: src/ftp-ls.c:910
+#: src/ftp-ls.c:911
 #, c-format
 msgid "File        "
 msgstr "Spis        "
 
-#: src/ftp-ls.c:913
+#: src/ftp-ls.c:914
 #, c-format
 msgid "Directory   "
 msgstr "Direktorij  "
 
-#: src/ftp-ls.c:916
+#: src/ftp-ls.c:917
 #, c-format
 msgid "Link        "
 msgstr "Link        "
 
-#: src/ftp-ls.c:919
+#: src/ftp-ls.c:920
 #, c-format
 msgid "Not sure    "
 msgstr "Ne znam     "
 
-#: src/ftp-ls.c:937
+#: src/ftp-ls.c:938
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s bajtova)"
 
-#: src/ftp.c:213
+#: src/ftp.c:214
 #, c-format
 msgid "Length: %s"
 msgstr "Duljina: %s"
 
-#: src/ftp.c:219 src/http.c:2173
+#: src/ftp.c:220 src/http.c:2183
 #, c-format
 msgid ", %s (%s) remaining"
 msgstr ", %s (%s) preostaje"
 
-#: src/ftp.c:223 src/http.c:2177
+#: src/ftp.c:224 src/http.c:2187
 #, c-format
 msgid ", %s remaining"
 msgstr ", %s preostaje"
 
-#: src/ftp.c:226
+#: src/ftp.c:227
 msgid " (unauthoritative)\n"
 msgstr " (nepouzdano)\n"
 
-#: src/ftp.c:302
+#: src/ftp.c:303
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Prijavljujem se kao %s ... "
 
-#: src/ftp.c:315 src/ftp.c:361 src/ftp.c:390 src/ftp.c:442 src/ftp.c:554
-#: src/ftp.c:600 src/ftp.c:629 src/ftp.c:686 src/ftp.c:747 src/ftp.c:807
-#: src/ftp.c:854
+#: src/ftp.c:316 src/ftp.c:362 src/ftp.c:391 src/ftp.c:443 src/ftp.c:555
+#: src/ftp.c:601 src/ftp.c:630 src/ftp.c:687 src/ftp.c:748 src/ftp.c:808
+#: src/ftp.c:855
 msgid "Error in server response, closing control connection.\n"
 msgstr "Gre¹ka u odgovoru, zatvaram kontrolnu vezu.\n"
 
-#: src/ftp.c:322
+#: src/ftp.c:323
 msgid "Error in server greeting.\n"
 msgstr "Gre¹ka u poslu¾iteljevom pozdravu.\n"
 
-#: src/ftp.c:329 src/ftp.c:450 src/ftp.c:562 src/ftp.c:637 src/ftp.c:696
-#: src/ftp.c:757 src/ftp.c:817 src/ftp.c:864
+#: src/ftp.c:330 src/ftp.c:451 src/ftp.c:563 src/ftp.c:638 src/ftp.c:697
+#: src/ftp.c:758 src/ftp.c:818 src/ftp.c:865
 msgid "Write failed, closing control connection.\n"
 msgstr "Pisanje je zakazalo, zatvaram kontrolnu vezu.\n"
 
-#: src/ftp.c:335
+#: src/ftp.c:336
 msgid "The server refuses login.\n"
 msgstr "Poslu¾itelj odbija prijavu.\n"
 
-#: src/ftp.c:341
+#: src/ftp.c:342
 msgid "Login incorrect.\n"
 msgstr "Pogre¹na prijava.\n"
 
-#: src/ftp.c:347
+#: src/ftp.c:348
 msgid "Logged in!\n"
 msgstr "Ulogiran!\n"
 
-#: src/ftp.c:369
+#: src/ftp.c:370
 msgid "Server error, can't determine system type.\n"
 msgstr "Gre¹ka na serveru, ne mogu utvrditi vrstu sustava.\n"
 
-#: src/ftp.c:378 src/ftp.c:673 src/ftp.c:730 src/ftp.c:773
+#: src/ftp.c:379 src/ftp.c:674 src/ftp.c:731 src/ftp.c:774
 msgid "done.    "
 msgstr "gotovo.  "
 
-#: src/ftp.c:430 src/ftp.c:579 src/ftp.c:612 src/ftp.c:837 src/ftp.c:883
+#: src/ftp.c:431 src/ftp.c:580 src/ftp.c:613 src/ftp.c:838 src/ftp.c:884
 msgid "done.\n"
 msgstr "gotovo.\n"
 
-#: src/ftp.c:457
+#: src/ftp.c:458
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Nepoznat tip `%c', zatvaram kontrolnu vezu.\n"
 
-#: src/ftp.c:469
+#: src/ftp.c:470
 msgid "done.  "
 msgstr "gotovo."
 
-#: src/ftp.c:475
+#: src/ftp.c:476
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD nepotreban.\n"
 
-#: src/ftp.c:568
+#: src/ftp.c:569
 #, c-format
 msgid ""
 "No such directory `%s'.\n"
 "\n"
 msgstr "Ne postoji direktorij `%s'.\n"
 
-#: src/ftp.c:583
+#: src/ftp.c:584
 msgid "==> CWD not required.\n"
 msgstr "==> CWD se ne tra¾i.\n"
 
-#: src/ftp.c:643
+#: src/ftp.c:644
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Ne mogu otpoèeti PASV prijenos.\n"
 
-#: src/ftp.c:647
+#: src/ftp.c:648
 msgid "Cannot parse PASV response.\n"
 msgstr "Ne mogu ra¹èlaniti PASV odgovor.\n"
 
-#: src/ftp.c:664
+#: src/ftp.c:665
 #, c-format
 msgid "couldn't connect to %s port %d: %s\n"
 msgstr "nemoguæe spajanje na %s, port %d: %s\n"
 
-#: src/ftp.c:712
+#: src/ftp.c:713
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Gre¹ka pri bindu (%s).\n"
 
-#: src/ftp.c:718
+#: src/ftp.c:719
 msgid "Invalid PORT.\n"
 msgstr "Neispravan PORT.\n"
 
-#: src/ftp.c:764
+#: src/ftp.c:765
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
