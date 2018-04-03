 # Translation of `wget' messages to Esperanto.
 # Copyright (C) 2003 Free Software Foundation, Inc.
 # This file is distributed under the same license as the `wget' package.
-# Luiz Portella <lfpor@luiz.org>, 2005.
+# Luiz Portella <lfpor@lujz.org>, 2005.
 #
 msgid ""
 msgstr ""
 "Project-Id-Version: GNU wget 1.9.1\n"
-"Report-Msgid-Bugs-To: \n"
-"POT-Creation-Date: 2005-04-28 12:13+0200\n"
-"PO-Revision-Date: 2005-04-13 24:00-0300\n"
-"Last-Translator: Luiz Portella <lfpor@luiz.org>\n"
+"POT-Creation-Date: 2003-10-11 16:21+0200\n"
+"PO-Revision-Date: 2005-05-04 12:00-0300\n"
+"Last-Translator: Luiz Portella <lfpor@lujz.org>\n"
 "Language-Team: Esperanto <translation-team-eo@lists.sourceforge.net>\n"
 "MIME-Version: 1.0\n"
 "Content-Type: text/plain; charset=UTF-8\n"
 "Content-Transfer-Encoding: 8bit\n"
 
-#: src/connect.c:200
+#: src/connect.c:88
 #, c-format
-msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
-msgstr ""
+msgid "Unable to convert `%s' to a bind address.  Reverting to ANY.\n"
+msgstr "Ne eblis konverti `%s' al adreso. Ŝanĝante al ANY.\n"
 
-#: src/connect.c:272
-#, fuzzy, c-format
-msgid "Connecting to %s|%s|:%d... "
+#: src/connect.c:165
+#, c-format
+msgid "Connecting to %s[%s]:%hu... "
 msgstr "Konektante al %s[%s]:%hu... "
 
-#: src/connect.c:275
-#, fuzzy, c-format
-msgid "Connecting to %s:%d... "
+#: src/connect.c:168
+#, c-format
+msgid "Connecting to %s:%hu... "
 msgstr "Konektante al %s:%hu... "
 
-#: src/connect.c:336
+#: src/connect.c:222
 msgid "connected.\n"
 msgstr "konektita.\n"
 
-#: src/convert.c:176
-#, fuzzy, c-format
-msgid "Converted %d files in %.*f seconds.\n"
+#: src/convert.c:171
+#, c-format
+msgid "Converted %d files in %.2f seconds.\n"
 msgstr "Konvertitaj %d dosieroj dum %.2f sekundoj.\n"
 
-#: src/convert.c:202
+#: src/convert.c:197
 #, c-format
 msgid "Converting %s... "
 msgstr "Konvertante %s... "
 
-#: src/convert.c:215
+#: src/convert.c:210
 msgid "nothing to do.\n"
 msgstr "nenio farenda.\n"
 
-#: src/convert.c:223 src/convert.c:247
+#: src/convert.c:218 src/convert.c:242
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Ne eblis konverti ligilojn al %s: %s\n"
 
-#: src/convert.c:238
+#: src/convert.c:233
 #, c-format
 msgid "Unable to delete `%s': %s\n"
 msgstr "Ne eblis forviŝi `%s': %s\n"
 
-#: src/convert.c:447
+#: src/convert.c:439
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "Ne eblis kopii %s kiel %s: %s\n"
 
-#: src/cookies.c:619
+#: src/cookies.c:606
 #, c-format
 msgid "Error in Set-Cookie, field `%s'"
 msgstr "Eraro en Set-Cookie, kampo `%s'"
 
-#: src/cookies.c:643
+#: src/cookies.c:629
 #, c-format
 msgid "Syntax error in Set-Cookie: %s at position %d.\n"
 msgstr "Sintaksa eraro en Set-Cookie: %s ĉe pozicio %d.\n"
 
-#: src/cookies.c:1469
+#: src/cookies.c:1426
 #, c-format
 msgid "Cannot open cookies file `%s': %s\n"
 msgstr "Ne eblis malfermi kuketan dosieron `%s': %s\n"
 
-#: src/cookies.c:1481
+#: src/cookies.c:1438
 #, c-format
 msgid "Error writing to `%s': %s\n"
 msgstr "Eraro dum registrado al `%s': %s\n"
 
-#: src/cookies.c:1484
+#: src/cookies.c:1442
 #, c-format
 msgid "Error closing `%s': %s\n"
 msgstr "Eraro fermante `%s': %s\n"
 
-#: src/ftp-ls.c:841
+#: src/ftp-ls.c:812
 msgid "Unsupported listing type, trying Unix listing parser.\n"
 msgstr "Lista tipo ne eltenebla, provante Uniksan liston.\n"
 
-#: src/ftp-ls.c:887 src/ftp-ls.c:889
+#: src/ftp-ls.c:857 src/ftp-ls.c:859
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Indekso de /%s en %s:%d"
 
-#: src/ftp-ls.c:912
-#, c-format
+#: src/ftp-ls.c:882
 msgid "time unknown       "
 msgstr "horaro nekonata   "
 
-#: src/ftp-ls.c:916
-#, c-format
+#: src/ftp-ls.c:886
 msgid "File        "
 msgstr "Dosiero        "
 
-#: src/ftp-ls.c:919
-#, c-format
+#: src/ftp-ls.c:889
 msgid "Directory   "
 msgstr "Dosierujo   "
 
-#: src/ftp-ls.c:922
-#, c-format
+#: src/ftp-ls.c:892
 msgid "Link        "
 msgstr "Ligilo        "
 
-#: src/ftp-ls.c:925
-#, c-format
+#: src/ftp-ls.c:895
 msgid "Not sure    "
 msgstr "Sen certeco    "
 
-#: src/ftp-ls.c:943
+#: src/ftp-ls.c:913
 #, c-format
 msgid " (%s bytes)"
-msgstr ""
-
-#: src/ftp.c:226
-#, c-format
-msgid "Length: %s"
-msgstr ""
-
-#: src/ftp.c:232 src/http.c:1853
-#, c-format
-msgid ", %s (%s) remaining"
-msgstr ""
-
-#: src/ftp.c:236 src/http.c:1857
-#, c-format
-msgid ", %s remaining"
-msgstr ""
-
-#: src/ftp.c:240
-msgid " (unauthoritative)\n"
-msgstr ""
+msgstr " (%s bajtoj)"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:315
+#: src/ftp.c:202
 #, c-format
 msgid "Logging in as %s ... "
-msgstr ""
+msgstr "Salutante kiel %s ... "
 
-#: src/ftp.c:328 src/ftp.c:381 src/ftp.c:412 src/ftp.c:466 src/ftp.c:581
-#: src/ftp.c:632 src/ftp.c:662 src/ftp.c:724 src/ftp.c:792 src/ftp.c:856
-#: src/ftp.c:908
+#: src/ftp.c:215 src/ftp.c:268 src/ftp.c:299 src/ftp.c:353 src/ftp.c:468
+#: src/ftp.c:519 src/ftp.c:551 src/ftp.c:611 src/ftp.c:675 src/ftp.c:748
+#: src/ftp.c:796
 msgid "Error in server response, closing control connection.\n"
-msgstr ""
+msgstr "Eraro en la respondo de servilo, fermante stirkonekton.\n"
 
-#: src/ftp.c:336
+#: src/ftp.c:223
 msgid "Error in server greeting.\n"
-msgstr ""
+msgstr "Eraro en la saluto de servilo.\n"
 
-#: src/ftp.c:344 src/ftp.c:475 src/ftp.c:590 src/ftp.c:671 src/ftp.c:735
-#: src/ftp.c:803 src/ftp.c:867 src/ftp.c:919
+#: src/ftp.c:231 src/ftp.c:362 src/ftp.c:477 src/ftp.c:560 src/ftp.c:621
+#: src/ftp.c:685 src/ftp.c:758 src/ftp.c:806
 msgid "Write failed, closing control connection.\n"
-msgstr ""
+msgstr "Skrib-eraro, fermante stirkonekton.\n"
 
-#: src/ftp.c:351
+#: src/ftp.c:238
 msgid "The server refuses login.\n"
-msgstr ""
+msgstr "La servilo rifuzis la saluton.\n"
 
-#: src/ftp.c:358
+#: src/ftp.c:245
 msgid "Login incorrect.\n"
-msgstr ""
+msgstr "Erara saluto.\n"
 
-#: src/ftp.c:365
+#: src/ftp.c:252
 msgid "Logged in!\n"
-msgstr ""
+msgstr "Salutite!\n"
 
-#: src/ftp.c:390
+#: src/ftp.c:277
 msgid "Server error, can't determine system type.\n"
-msgstr ""
+msgstr "Eraro de la servilo, ne eblas difini la tipon de sistemo.\n"
 
-#: src/ftp.c:400 src/ftp.c:711 src/ftp.c:775 src/ftp.c:822
+#: src/ftp.c:287 src/ftp.c:596 src/ftp.c:659 src/ftp.c:716
 msgid "done.    "
-msgstr ""
+msgstr "farite.    "
 
-#: src/ftp.c:454 src/ftp.c:611 src/ftp.c:646 src/ftp.c:891 src/ftp.c:942
+#: src/ftp.c:341 src/ftp.c:498 src/ftp.c:533 src/ftp.c:779 src/ftp.c:827
 msgid "done.\n"
-msgstr ""
+msgstr "farite.\n"
 
-#: src/ftp.c:483
+#: src/ftp.c:370
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
-msgstr ""
+msgstr "Tipo `%c' nekonata, fermante stirkonekton.\n"
 
-#: src/ftp.c:496
+#: src/ftp.c:383
 msgid "done.  "
-msgstr ""
+msgstr "farite.  "
 
-#: src/ftp.c:502
+#: src/ftp.c:389
 msgid "==> CWD not needed.\n"
-msgstr ""
+msgstr "==> CWD ne necesa.\n"
 
-#: src/ftp.c:597
+#: src/ftp.c:484
 #, c-format
 msgid ""
 "No such directory `%s'.\n"
 "\n"
 msgstr ""
+"Dosierujo `%s' ne trovita.\n"
+"\n"
 
 #. do not CWD
-#: src/ftp.c:615
+#: src/ftp.c:502
 msgid "==> CWD not required.\n"
-msgstr ""
+msgstr "==> CWD ne postulita.\n"
 
-#: src/ftp.c:678
+#: src/ftp.c:567
 msgid "Cannot initiate PASV transfer.\n"
-msgstr ""
+msgstr "Ne eblis komenci transporton PASV.\n"
 
-#: src/ftp.c:682
+#: src/ftp.c:571
 msgid "Cannot parse PASV response.\n"
 msgstr ""
 
-#: src/ftp.c:702
+#: src/ftp.c:588
 #, c-format
-msgid "couldn't connect to %s port %d: %s\n"
-msgstr ""
+msgid "couldn't connect to %s:%hu: %s\n"
+msgstr "ne eblis konekti al %s:%hu: %s\n"
 
-#: src/ftp.c:753
+#: src/ftp.c:638
 #, c-format
 msgid "Bind error (%s).\n"
-msgstr ""
+msgstr "Bind-eraro (%s).\n"
 
-#: src/ftp.c:760
+#: src/ftp.c:645
 msgid "Invalid PORT.\n"
+msgstr "Pordo nevalida.\n"
+
+#: src/ftp.c:698
+#, c-format
+msgid ""
+"\n"
+"REST failed; will not truncate `%s'.\n"
 msgstr ""
+"\n"
+"REST fuŝis; `%s' ne estos stumpigita.\n"
 
-#: src/ftp.c:811
+#: src/ftp.c:705
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
 msgstr ""
+"\n"
+"REST fuŝis; rekomencante,\n"
 
-#: src/ftp.c:876
+#: src/ftp.c:766
 #, c-format
 msgid ""
 "No such file `%s'.\n"
 "\n"
 msgstr ""
+"Dosiero `%s' ne trovita.\n"
+"\n"
 
-#: src/ftp.c:928
+#: src/ftp.c:814
 #, c-format
 msgid ""
 "No such file or directory `%s'.\n"
 "\n"
 msgstr ""
+"Dosiero aŭ dosierujo `%s' ne trovita.\n"
+"\n"
 
-#. We cannot just invent a new name and use it (which is
-#. what functions like unique_create typically do)
-#. because we told the user we'd use this name.
-#. Instead, return and retry the download.
-#: src/ftp.c:993 src/http.c:1909
+#: src/ftp.c:898 src/ftp.c:906
 #, c-format
-msgid "%s has sprung into existence.\n"
-msgstr ""
+msgid "Length: %s"
+msgstr "Grando: %s"
+
+#: src/ftp.c:900 src/ftp.c:908
+#, c-format
+msgid " [%s to go]"
+msgstr " [%s por fini]"
 
-#: src/ftp.c:1055
+#: src/ftp.c:910
+msgid " (unauthoritative)\n"
+msgstr " (ne havante permeson)\n"
+
+#: src/ftp.c:936
 #, c-format
 msgid "%s: %s, closing control connection.\n"
-msgstr ""
+msgstr "%s: %s, fermante stirkonekton.\n"
 
-#: src/ftp.c:1063
+#: src/ftp.c:944
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
-msgstr ""
+msgstr "%s (%s) - Konekto de datumoj: %s; "
 
-#: src/ftp.c:1078
+#: src/ftp.c:961
 msgid "Control connection closed.\n"
-msgstr ""
+msgstr "Stirkonekto fermita.\n"
 
-#: src/ftp.c:1096
+#: src/ftp.c:979
 msgid "Data transfer aborted.\n"
-msgstr ""
+msgstr "Transporto de datumoj haltigita.\n"
 
-#: src/ftp.c:1161
+#: src/ftp.c:1044
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
-msgstr ""
+msgstr "La dosiero `%s' jam estas ĉi tie, ĝi ne estos elŝutita.\n"
 
-#: src/ftp.c:1225 src/http.c:2128
+#: src/ftp.c:1114 src/http.c:1716
 #, c-format
 msgid "(try:%2d)"
-msgstr ""
+msgstr "(provo:%2d)"
 
-#: src/ftp.c:1297 src/http.c:2409
+#: src/ftp.c:1180 src/http.c:1975
 #, c-format
 msgid ""
-"%s (%s) - `%s' saved [%s]\n"
+"%s (%s) - `%s' saved [%ld]\n"
 "\n"
 msgstr ""
+"%s (%s) - `%s' ricevite [%ld]\n"
+"\n"
 
-#: src/ftp.c:1339 src/main.c:946 src/recur.c:376 src/retr.c:835
+#: src/ftp.c:1222 src/main.c:890 src/recur.c:377 src/retr.c:596
 #, c-format
 msgid "Removing %s.\n"
-msgstr ""
+msgstr "Forviŝante %s.\n"
 
-#: src/ftp.c:1381
+#: src/ftp.c:1264
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
-msgstr ""
+msgstr "Uzante `%s' kiel dumtempan dosieron de listo.\n"
 
-#: src/ftp.c:1396
+#: src/ftp.c:1279
 #, c-format
 msgid "Removed `%s'.\n"
-msgstr ""
+msgstr "Forviŝite `%s'.\n"
 
-#: src/ftp.c:1431
+#: src/ftp.c:1314
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
-msgstr ""
+msgstr "Nivelo de rekursio %d superas maksimuman nivelon %d.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1501
+#: src/ftp.c:1384
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
-msgstr ""
+msgstr "Fora dosiero ne estas plej nova ol loka `%s' -- forgesante.\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1508
+#: src/ftp.c:1391
 #, c-format
 msgid ""
 "Remote file is newer than local file `%s' -- retrieving.\n"
 "\n"
 msgstr ""
+"Fora dosiero estas plej nova ol loka `%s' -- elŝutante.\n"
+"\n"
 
 #. Sizes do not match
-#: src/ftp.c:1515
+#: src/ftp.c:1398
 #, c-format
 msgid ""
-"The sizes do not match (local %s) -- retrieving.\n"
+"The sizes do not match (local %ld) -- retrieving.\n"
 "\n"
-msgstr ""
+msgstr "La grandoj neegalaj (loka %ld) -- elŝutante.\n"
 
-#: src/ftp.c:1533
+#: src/ftp.c:1415
 msgid "Invalid name of the symlink, skipping.\n"
-msgstr ""
+msgstr "Nevalida nomo de simbola ligilo, pretersaltante.\n"
 
-#: src/ftp.c:1550
+#: src/ftp.c:1432
 #, c-format
 msgid ""
 "Already have correct symlink %s -> %s\n"
 "\n"
 msgstr ""
+"Simbola ligilo jam estis ĝusta %s -> %s\n"
+"\n"
 
-#: src/ftp.c:1558
+#: src/ftp.c:1440
 #, c-format
 msgid "Creating symlink %s -> %s\n"
-msgstr ""
+msgstr "Kreante simbolan ligilon %s -> %s\n"
 
-#: src/ftp.c:1568
+#: src/ftp.c:1451
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr ""
+msgstr "Simbolaj ligiloj ne elteneblaj, forgesante simbolan ligilon `%s'.\n"
 
-#: src/ftp.c:1580
+#: src/ftp.c:1463
 #, c-format
 msgid "Skipping directory `%s'.\n"
-msgstr ""
+msgstr "Forgesante dosierujon `%s'.\n"
 
-#: src/ftp.c:1589
+#: src/ftp.c:1472
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
-msgstr ""
+msgstr "%s: nekonata/neeltenebla dosier-tipo.\n"
 
-#: src/ftp.c:1616
+#: src/ftp.c:1499
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
-msgstr ""
+msgstr "%s: horaro (time-stamp) erara.\n"
 
-#: src/ftp.c:1644
+#: src/ftp.c:1524
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
-msgstr ""
+msgstr "Dosierujoj ne estos elŝutitaj dum nivelo de rekursio estas %d (maksimuma %d).\n"
 
-#: src/ftp.c:1694
+#: src/ftp.c:1574
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr ""
 
-#: src/ftp.c:1760 src/ftp.c:1774
+#: src/ftp.c:1639 src/ftp.c:1652
 #, c-format
 msgid "Rejecting `%s'.\n"
-msgstr ""
+msgstr "Rifuzante `%s'.\n"
 
 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1820
+#: src/ftp.c:1698
 #, c-format
 msgid "No matches on pattern `%s'.\n"
-msgstr ""
+msgstr "Nenio trovita kun la ŝablono `%s'.\n"
 
-#: src/ftp.c:1886
+#: src/ftp.c:1764
 #, c-format
-msgid "Wrote HTML-ized index to `%s' [%s].\n"
-msgstr ""
+msgid "Wrote HTML-ized index to `%s' [%ld].\n"
+msgstr "Skribite HTML-indekson al `%s' [%ld].\n"
 
-#: src/ftp.c:1891
+#: src/ftp.c:1769
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
+msgstr "Skribite HTML-indekson al `%s'.\n"
+
+#: src/gen_sslfunc.c:117
+msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
 msgstr ""
 
 #: src/getopt.c:675
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
-msgstr ""
+msgstr "%s: elekto `%s' estas multesenca\n"
 
 #: src/getopt.c:700
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
-msgstr ""
+msgstr "%s:  elekto `--%s' ne permesas argumenton\n"
 
 #: src/getopt.c:705
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
-msgstr ""
+msgstr "%s: elekto `%c%s' ne permesas argumenton\n"
 
 #: src/getopt.c:723 src/getopt.c:896
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
-msgstr ""
+msgstr "%s: elekto `%s' postulas argumenton\n"
 
 #. --option
 #: src/getopt.c:752
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
-msgstr ""
+msgstr "%s: nekonata elekto `--%s'\n"
 
 #. +option or -option
 #: src/getopt.c:756
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
-msgstr ""
+msgstr "%s: nekonata elekto `%c%s'\n"
 
 #. 1003.2 specifies the format of this message.
 #: src/getopt.c:782
 #, c-format
 msgid "%s: illegal option -- %c\n"
-msgstr ""
+msgstr "%s: neleĝa elekto -- %c\n"
 
 #: src/getopt.c:785
 #, c-format
 msgid "%s: invalid option -- %c\n"
-msgstr ""
+msgstr "%s: nevalida elekto -- %c\n"
 
 #. 1003.2 specifies the format of this message.
 #: src/getopt.c:815 src/getopt.c:945
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
-msgstr ""
+msgstr "%s: elekto postulas argumenton -- %c\n"
 
 #: src/getopt.c:862
 #, c-format
 msgid "%s: option `-W %s' is ambiguous\n"
-msgstr ""
+msgstr "%s: elekto `-W %s' estas multesenca\n"
 
 #: src/getopt.c:880
 #, c-format
 msgid "%s: option `-W %s' doesn't allow an argument\n"
-msgstr ""
+msgstr "%s: elekto `-W %s' ne permesas argumenton\n"
 
-#: src/host.c:371
-msgid "Unknown host"
-msgstr ""
-
-#. Message modeled after what gai_strerror returns in similar
-#. circumstances.
-#: src/host.c:375
-msgid "Temporary failure in name resolution"
-msgstr ""
-
-#: src/host.c:377
-msgid "Unknown error"
-msgstr ""
-
-#: src/host.c:757
+#: src/host.c:636
 #, c-format
 msgid "Resolving %s... "
-msgstr ""
+msgstr "Provante %s... "
 
-#: src/host.c:801 src/host.c:830
+#: src/host.c:656 src/host.c:672
 #, c-format
 msgid "failed: %s.\n"
-msgstr ""
+msgstr "fiasko: %s.\n"
 
-#: src/host.c:810
-msgid "failed: No IPv4/IPv6 addresses for host.\n"
-msgstr ""
-
-#: src/host.c:833
+#: src/host.c:674
 msgid "failed: timed out.\n"
-msgstr ""
+msgstr "fiasko: limtempo finita.\n"
+
+#: src/host.c:762
+msgid "Host not found"
+msgstr "Retnodo netrovita"
 
-#: src/html-url.c:297
+#: src/host.c:764
+msgid "Unknown error"
+msgstr "Nekonata eraro"
+
+#: src/html-url.c:293
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr ""
 
-#: src/http.c:373 src/http.c:1534
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
+#. this is fatal
+#: src/http.c:674
+msgid "Failed to set up an SSL context\n"
 msgstr ""
 
-#: src/http.c:687
-msgid "No headers, assuming HTTP/0.9"
+#: src/http.c:680
+#, c-format
+msgid "Failed to load certificates from %s\n"
 msgstr ""
 
-#: src/http.c:1194
-msgid "Disabling SSL due to encountered errors.\n"
+#: src/http.c:684 src/http.c:692
+msgid "Trying without the specified certificate\n"
 msgstr ""
 
-#: src/http.c:1402
+#: src/http.c:688
 #, c-format
-msgid "Reusing existing connection to %s:%d.\n"
+msgid "Failed to get certificate key from %s\n"
 msgstr ""
 
-#: src/http.c:1464
-#, fuzzy, c-format
-msgid "Failed writing to proxy: %s.\n"
-msgstr "Eraro dum registrado al `%s': %s\n"
+#: src/http.c:761 src/http.c:1809
+msgid "Unable to establish SSL connection.\n"
+msgstr ""
 
-#: src/http.c:1473
+#: src/http.c:770
 #, c-format
-msgid "Failed reading proxy response: %s\n"
+msgid "Reusing connection to %s:%hu.\n"
 msgstr ""
 
-#: src/http.c:1493
+#: src/http.c:1034
 #, c-format
-msgid "Proxy tunneling failed: %s"
+msgid "Failed writing HTTP request: %s.\n"
 msgstr ""
 
-#: src/http.c:1540
+#: src/http.c:1039
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr ""
 
-#: src/http.c:1551
-msgid "No data received.\n"
+#: src/http.c:1083
+msgid "End of file while parsing headers.\n"
 msgstr ""
 
-#: src/http.c:1558
+#: src/http.c:1093
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr ""
 
-#. If we have tried it already, then there is not point
-#. retrying it.
-#: src/http.c:1629
-msgid "Authorization failed.\n"
-msgstr ""
-
-#: src/http.c:1656
-msgid "Unknown authentication scheme.\n"
+#: src/http.c:1128
+msgid "No data received"
 msgstr ""
 
-#: src/http.c:1689
+#: src/http.c:1130
 msgid "Malformed status line"
 msgstr ""
 
-#: src/http.c:1691
+#: src/http.c:1135
 msgid "(no description)"
 msgstr ""
 
-#: src/http.c:1762
+#: src/http.c:1267
+msgid "Authorization failed.\n"
+msgstr ""
+
+#: src/http.c:1274
+msgid "Unknown authentication scheme.\n"
+msgstr ""
+
+#: src/http.c:1314
 #, c-format
 msgid "Location: %s%s\n"
 msgstr ""
 
-#: src/http.c:1763 src/http.c:1863
+#: src/http.c:1315 src/http.c:1454
 msgid "unspecified"
 msgstr ""
 
-#: src/http.c:1764
+#: src/http.c:1316
 msgid " [following]"
 msgstr ""
 
-#. If `-c' is in use and the file has been fully downloaded (or
-#. the remote file has shrunk), Wget effectively requests bytes
-#. after the end of file and the server response with 416.
-#: src/http.c:1813
+#: src/http.c:1383
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 
+#: src/http.c:1401
+#, c-format
+msgid ""
+"\n"
+"Continued download failed on this file, which conflicts with `-c'.\n"
+"Refusing to truncate existing file `%s'.\n"
+"\n"
+msgstr ""
+
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1843
+#: src/http.c:1444
 msgid "Length: "
 msgstr ""
 
-#: src/http.c:1863
+#: src/http.c:1449
+#, c-format
+msgid " (%s to go)"
+msgstr ""
+
+#: src/http.c:1454
 msgid "ignored"
 msgstr ""
 
-#: src/http.c:2005
+#: src/http.c:1598
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr ""
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:2040
+#: src/http.c:1628
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr ""
 
-#: src/http.c:2227
+#: src/http.c:1800
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr ""
 
-#: src/http.c:2236
-msgid "Unable to establish SSL connection.\n"
-msgstr ""
-
-#: src/http.c:2246
+#: src/http.c:1819
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr ""
 
-#: src/http.c:2278
+#: src/http.c:1851
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr ""
 
-#: src/http.c:2291
+#: src/http.c:1864
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr ""
 
-#: src/http.c:2299
+#: src/http.c:1872
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr ""
 
-#: src/http.c:2322
+#: src/http.c:1895
 #, c-format
 msgid ""
 "Server file no newer than local file `%s' -- not retrieving.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2330
+#: src/http.c:1903
 #, c-format
-msgid "The sizes do not match (local %s) -- retrieving.\n"
+msgid "The sizes do not match (local %ld) -- retrieving.\n"
 msgstr ""
 
-#: src/http.c:2335
+#: src/http.c:1907
 msgid "Remote file is newer, retrieving.\n"
 msgstr ""
 
-#: src/http.c:2377
+#: src/http.c:1948
 #, c-format
 msgid ""
-"%s (%s) - `%s' saved [%s/%s]\n"
+"%s (%s) - `%s' saved [%ld/%ld]\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2434
+#: src/http.c:1998
 #, c-format
-msgid "%s (%s) - Connection closed at byte %s. "
+msgid "%s (%s) - Connection closed at byte %ld. "
 msgstr ""
 
-#: src/http.c:2443
+#: src/http.c:2007
 #, c-format
 msgid ""
-"%s (%s) - `%s' saved [%s/%s])\n"
+"%s (%s) - `%s' saved [%ld/%ld])\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2469
+#: src/http.c:2028
 #, c-format
-msgid "%s (%s) - Connection closed at byte %s/%s. "
+msgid "%s (%s) - Connection closed at byte %ld/%ld. "
 msgstr ""
 
-#: src/http.c:2483
+#: src/http.c:2040
 #, c-format
-msgid "%s (%s) - Read error at byte %s (%s)."
+msgid "%s (%s) - Read error at byte %ld (%s)."
 msgstr ""
 
-#: src/http.c:2493
+#: src/http.c:2049
 #, c-format
-msgid "%s (%s) - Read error at byte %s/%s (%s). "
+msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
 msgstr ""
 
-#: src/init.c:369
+#: src/init.c:342
 #, c-format
 msgid "%s: WGETRC points to %s, which doesn't exist.\n"
 msgstr ""
 
-#: src/init.c:422 src/netrc.c:277
+#: src/init.c:398 src/netrc.c:276
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr ""
 
-#: src/init.c:440 src/init.c:446
+#: src/init.c:416 src/init.c:422
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr ""
 
-#: src/init.c:478
+#: src/init.c:454
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
 msgstr ""
 
-#: src/init.c:622
+#: src/init.c:594
 #, c-format
 msgid "%s: Invalid --execute command `%s'\n"
 msgstr ""
 
-#: src/init.c:668
+#: src/init.c:630
 #, c-format
 msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
 msgstr ""
 
-#: src/init.c:711
+#: src/init.c:673
 #, c-format
 msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
 msgstr ""
 
-#: src/init.c:728
+#: src/init.c:691
 #, c-format
 msgid "%s: %s: Invalid number `%s'.\n"
 msgstr ""
 
-#: src/init.c:959 src/init.c:978
+#: src/init.c:930 src/init.c:949
 #, c-format
 msgid "%s: %s: Invalid byte value `%s'\n"
 msgstr ""
 
-#: src/init.c:1003
+#: src/init.c:974
 #, c-format
 msgid "%s: %s: Invalid time period `%s'\n"
 msgstr ""
 
-#: src/init.c:1057 src/init.c:1138 src/init.c:1233 src/init.c:1259
-#, c-format
-msgid "%s: %s: Invalid value `%s'.\n"
-msgstr ""
-
-#: src/init.c:1086
+#: src/init.c:1051
 #, c-format
 msgid "%s: %s: Invalid header `%s'.\n"
 msgstr ""
 
-#: src/init.c:1150
+#: src/init.c:1106
 #, c-format
 msgid "%s: %s: Invalid progress type `%s'.\n"
 msgstr ""
 
-#: src/init.c:1201
+#: src/init.c:1157
 #, c-format
 msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
 msgstr ""
 
-#: src/log.c:777
+#: src/init.c:1198
+#, c-format
+msgid "%s: %s: Invalid value `%s'.\n"
+msgstr ""
+
+#: src/log.c:636
 #, c-format
 msgid ""
 "\n"
