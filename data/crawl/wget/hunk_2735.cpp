 msgstr "%s: az opcióhoz szükség van argumentumra -- %c\n"
 
 #: src/getopt.c:862
-#, fuzzy, c-format
+#, c-format
 msgid "%s: option `-W %s' is ambiguous\n"
-msgstr "%s: a `%s' opció kétes értelmû\n"
+msgstr "%s: a `-W %s' opció kétes értelmû\n"
 
 #: src/getopt.c:880
-#, fuzzy, c-format
+#, c-format
 msgid "%s: option `-W %s' doesn't allow an argument\n"
-msgstr "%s: a `--%s' opcióhoz nem kell argumentum\n"
-
-#: src/host.c:371
-#, fuzzy
-msgid "Unknown host"
-msgstr "Ismeretlen hiba"
-
-#. Message modeled after what gai_strerror returns in similar
-#. circumstances.
-#: src/host.c:375
-msgid "Temporary failure in name resolution"
-msgstr ""
+msgstr "%s: a `-W %s' opcióhoz nem kell argumentum\n"
 
-#: src/host.c:377
-msgid "Unknown error"
-msgstr "Ismeretlen hiba"
-
-#: src/host.c:756
+#: src/host.c:636
 #, c-format
 msgid "Resolving %s... "
 msgstr "IP keresés %s... "
 
-#: src/host.c:800 src/host.c:829
+#: src/host.c:656 src/host.c:672
 #, c-format
 msgid "failed: %s.\n"
-msgstr "nem sikerült: %s.\n"
-
-#: src/host.c:809
-msgid "failed: No IPv4/IPv6 addresses for host.\n"
-msgstr ""
+msgstr "sikertelen: %s.\n"
 
-#: src/host.c:832
-#, fuzzy
+#: src/host.c:674
 msgid "failed: timed out.\n"
-msgstr "nem sikerült: %s.\n"
+msgstr "sikertelen: idõtúllépés.\n"
+
+#: src/host.c:762
+msgid "Host not found"
+msgstr "Gép nem található"
+
+#: src/host.c:764
+msgid "Unknown error"
+msgstr "Ismeretlen hiba"
 
-#: src/html-url.c:298
+#: src/html-url.c:293
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
-msgstr "%s: nem tudom megtalálni a hiányos %s linket.\n"
+msgstr "%s: nem lehet megtalálni a hiányos %s linket.\n"
 
-#: src/http.c:373 src/http.c:1549
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
-msgstr "A HTTP kérés írása sikertelen: %s.\n"
+#. this is fatal
+#: src/http.c:674
+msgid "Failed to set up an SSL context\n"
+msgstr "SSL-környezet beállítása sikertelen\n"
 
-#: src/http.c:687
-msgid "No headers, assuming HTTP/0.9"
-msgstr ""
+#: src/http.c:680
+#, c-format
+msgid "Failed to load certificates from %s\n"
+msgstr "Tanúsítványok betöltése %s-ról sikertelen\n"
 
-#: src/http.c:1198
-msgid "Disabling SSL due to encountered errors.\n"
-msgstr ""
+#: src/http.c:684 src/http.c:692
+msgid "Trying without the specified certificate\n"
+msgstr "Megpróbálom a megadott igazolás nélkül\n"
 
-#: src/http.c:1417
-#, fuzzy, c-format
-msgid "Reusing existing connection to %s:%d.\n"
-msgstr "Újrahasználom a kapcsolatot %s:%hu-hoz.\n"
+#: src/http.c:688
+#, c-format
+msgid "Failed to get certificate key from %s\n"
+msgstr "Tanúsítványkulcs megszerzése %s-ról sikertelen\n"
 
-#: src/http.c:1479
-#, fuzzy, c-format
-msgid "Failed writing to proxy: %s.\n"
-msgstr "A HTTP kérés írása sikertelen: %s.\n"
+#: src/http.c:761 src/http.c:1809
+msgid "Unable to establish SSL connection.\n"
+msgstr "Nem lehet létrehozni SSL-kapcsolatot.\n"
 
-#: src/http.c:1488
-#, fuzzy, c-format
-msgid "Failed reading proxy response: %s\n"
-msgstr "A HTTP kérés írása sikertelen: %s.\n"
+#: src/http.c:770
+#, c-format
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Újrahasználom a kapcsolatot %s:%hu-hoz.\n"
 
-#: src/http.c:1508
+#: src/http.c:1034
 #, c-format
-msgid "Proxy tunneling failed: %s"
-msgstr ""
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "A HTTP kérés írása sikertelen: %s.\n"
 
-#: src/http.c:1555
+#: src/http.c:1039
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s kérés elküldve, várom a választ... "
 
-#: src/http.c:1566
-#, fuzzy
-msgid "No data received.\n"
-msgstr "Nem érkezett adat"
+#: src/http.c:1083
+msgid "End of file while parsing headers.\n"
+msgstr "Fájl vége miközben a fejlécet olvasom.\n"
 
-#: src/http.c:1573
+#: src/http.c:1093
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Olvasási hiba (%s) a fejlécben.\n"
 
-#. If the authentication header is missing or
-#. unrecognized, there's no sense in retrying.
-#: src/http.c:1658
-msgid "Unknown authentication scheme.\n"
-msgstr "Ismeretlen azonosítási módszer.\n"
-
-#: src/http.c:1682
-msgid "Authorization failed.\n"
-msgstr "Azonosítás sikertelen.\n"
+#: src/http.c:1128
+msgid "No data received"
+msgstr "Nem érkezett adat"
 
-#: src/http.c:1696
+#: src/http.c:1130
 msgid "Malformed status line"
 msgstr "Rosszul formázott állapot vonal"
 
-#: src/http.c:1698
+#: src/http.c:1135
 msgid "(no description)"
 msgstr "(nincs leírás)"
 
-#: src/http.c:1769
+#: src/http.c:1267
+msgid "Authorization failed.\n"
+msgstr "Azonosítás sikertelen.\n"
+
+#: src/http.c:1274
+msgid "Unknown authentication scheme.\n"
+msgstr "Ismeretlen azonosítási módszer.\n"
+
+#: src/http.c:1314
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Hely: %s%s\n"
 
-#: src/http.c:1770 src/http.c:1867
+#: src/http.c:1315 src/http.c:1454
 msgid "unspecified"
 msgstr "nem megadott"
 
-#: src/http.c:1771
+#: src/http.c:1316
 msgid " [following]"
 msgstr " [következik]"
 
-#. If `-c' is in use and the file has been fully downloaded (or
-#. the remote file has shrunk), Wget effectively requests bytes
-#. after the end of file and the server response with 416.
-#: src/http.c:1817
+#: src/http.c:1383
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 "\n"
-"    Az állomány már teljesen le van töltve; nincs mit csinájak.\n"
+"    A fájl már teljesen le van töltve; nincs mit csinálni.\n"
+"\n"
+
+#: src/http.c:1401
+#, c-format
+msgid ""
+"\n"
+"Continued download failed on this file, which conflicts with `-c'.\n"
+"Refusing to truncate existing file `%s'.\n"
+"\n"
+msgstr ""
+"\n"
+"Folytatott letöltés sikertelen ennél a fájlnál, ami ellentmond `-c'-val.\n"
+"Nem tördelem a létezõ `%s' fájlt.\n"
 "\n"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1847
+#: src/http.c:1444
 msgid "Length: "
 msgstr "Hossz: "
 
-#: src/http.c:1867
+#: src/http.c:1449
+#, c-format
+msgid " (%s to go)"
+msgstr " (még %s)"
+
+#: src/http.c:1454
 msgid "ignored"
-msgstr "figyelmen kivül hagyva"
+msgstr "figyelmen kívül hagyva"
 
-#: src/http.c:2007
+#: src/http.c:1598
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Figyelem: * és ? nem használható HTTP-nél.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:2042
+#: src/http.c:1628
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
-msgstr "A `%s' állomány már létezik, nem töltöm le.\n"
+msgstr "A(z) `%s' fájl már létezik, nem töltöm le.\n"
 
-#: src/http.c:2232
+#: src/http.c:1800
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Nem tudok írni `%s'-ba (%s).\n"
 
-#. Another fatal error.
-#: src/http.c:2239
-msgid "Unable to establish SSL connection.\n"
-msgstr "Nem sikerült SSL kapcsolatot létrehozni.\n"
-
-#: src/http.c:2248
+#: src/http.c:1819
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "HIBA: Átirányítás (%d) helyzet nélkül.\n"
 
-#: src/http.c:2278
+#: src/http.c:1851
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s HIBA %d: %s.\n"
 
-#: src/http.c:2291
+#: src/http.c:1864
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Utolsó módosított fejléc hiányzik -- idõbejegyzés kikapcsolva.\n"
 
-#: src/http.c:2299
+#: src/http.c:1872
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
-msgstr ""
-"Utolsó módosított fejléc helytelen -- idõbejegyzés figyelmen kivûl hagyva.\n"
+msgstr "Utolsó módosított fejléc helytelen -- idõbejegyzés figyelmen kívül hagyva.\n"
 
-#: src/http.c:2322
+#: src/http.c:1895
 #, c-format
 msgid ""
 "Server file no newer than local file `%s' -- not retrieving.\n"
 "\n"
 msgstr ""
-"A szerveren lévõ `%s' állomány nem újabb mint a helyi -- nem töltöm le.\n"
+"A szerveren lévõ `%s' fájl nem újabb mint a helyi -- nem töltöm le.\n"
 "\n"
 
-#: src/http.c:2330
-#, fuzzy, c-format
-msgid "The sizes do not match (local %s) -- retrieving.\n"
-msgstr "A méretek nem eggyeznek (helyi %ld) -- letöltöm.\n"
+#: src/http.c:1903
+#, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n"
+msgstr "A méretek nem egyeznek (helyi %ld) -- letöltöm.\n"
 
-#: src/http.c:2335
+#: src/http.c:1907
 msgid "Remote file is newer, retrieving.\n"
-msgstr "Távoli állomány újabb, letöltöm.\n"
+msgstr "Távoli fájl újabb, letöltöm.\n"
 
-#: src/http.c:2377
-#, fuzzy, c-format
+#: src/http.c:1948
+#, c-format
 msgid ""
-"%s (%s) - `%s' saved [%s/%s]\n"
+"%s (%s) - `%s' saved [%ld/%ld]\n"
 "\n"
 msgstr ""
 "%s (%s) - `%s' lementve [%ld/%ld]\n"
 "\n"
 
-#: src/http.c:2434
-#, fuzzy, c-format
-msgid "%s (%s) - Connection closed at byte %s. "
-msgstr "%s (%s) - Kapcsolat bezárva a %ld-ik bájtnál. "
+#: src/http.c:1998
+#, c-format
+msgid "%s (%s) - Connection closed at byte %ld. "
+msgstr "%s (%s) - Kapcsolat bezárva a %ld. bájtnál. "
 
-#: src/http.c:2443
-#, fuzzy, c-format
+#: src/http.c:2007
+#, c-format
 msgid ""
-"%s (%s) - `%s' saved [%s/%s])\n"
+"%s (%s) - `%s' saved [%ld/%ld])\n"
 "\n"
 msgstr ""
 "%s (%s) - `%s' lementve [%ld/%ld])\n"
 "\n"
 
-#: src/http.c:2469
-#, fuzzy, c-format
-msgid "%s (%s) - Connection closed at byte %s/%s. "
-msgstr "%s (%s) - Kapcsolat bezárva a %ld/%ld-ik bájtnál. "
+#: src/http.c:2028
+#, c-format
+msgid "%s (%s) - Connection closed at byte %ld/%ld. "
+msgstr "%s (%s) - Kapcsolat bezárva a %ld/%ld. bájtnál. "
 
-#: src/http.c:2483
-#, fuzzy, c-format
-msgid "%s (%s) - Read error at byte %s (%s)."
-msgstr "%s (%s) - Olvasási hiba a %ld-ik bájtnál (%s). "
+#: src/http.c:2040
+#, c-format
+msgid "%s (%s) - Read error at byte %ld (%s)."
+msgstr "%s (%s) - Olvasási hiba a %ld. bájtnál (%s). "
 
-#: src/http.c:2493
-#, fuzzy, c-format
-msgid "%s (%s) - Read error at byte %s/%s (%s). "
-msgstr "%s (%s) - Olvasási hiba a %ld/%ld-ik bájtnál (%s). "
+#: src/http.c:2049
+#, c-format
+msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
+msgstr "%s (%s) - Olvasási hiba a %ld/%ld. bájtnál (%s). "
 
-#: src/init.c:369
+#: src/init.c:342
 #, c-format
 msgid "%s: WGETRC points to %s, which doesn't exist.\n"
-msgstr ""
+msgstr "%s: WGETRC %s-ra mutat, ami nem létezik.\n"
 
-#: src/init.c:433 src/netrc.c:277
+#: src/init.c:398 src/netrc.c:276
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
-msgstr "%s: Nem tudom olvasni %s-t (%s).\n"
+msgstr "%s: Nem lehet olvasni %s-t (%s).\n"
 
-#: src/init.c:451
+#: src/init.c:416 src/init.c:422
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: Hiba %s-ban a %d-ik sornál.\n"
 
-#: src/init.c:457
-#, fuzzy, c-format
-msgid "%s: Syntax error in %s at line %d.\n"
-msgstr "%s: Hiba %s-ban a %d-ik sornál.\n"
-
-#: src/init.c:462
-#, fuzzy, c-format
-msgid "%s: Unknown command `%s' in %s at line %d.\n"
-msgstr "%s: BUG: ismeretlen parancs `%s', érték `%s'.\n"
-
-#: src/init.c:507
+#: src/init.c:454
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
-msgstr ""
-"%s: Figyelem: Mind a rendszer és a felhasználói wgetrc `%s'-re mutat.\n"
+msgstr "%s: Figyelem: Mind a rendszer és a felhasználói wgetrc `%s'-re mutat.\n"
 
-#: src/init.c:661
-#, fuzzy, c-format
+#: src/init.c:594
+#, c-format
 msgid "%s: Invalid --execute command `%s'\n"
-msgstr "%s: Helytelen megadás `%s'\n"
+msgstr "%s: Hibás --execute parancs `%s'\n"
 
-#: src/init.c:707
-#, fuzzy, c-format
+#: src/init.c:630
+#, c-format
 msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
-msgstr "%s: %s: Kérem adja meg, hogy ki vagy bekapcsolva.\n"
+msgstr "%s: %s: Hibás boolean `%s', használja az `on' vagy `off' szavakat.\n"
 
-#: src/init.c:750
-#, fuzzy, c-format
+#: src/init.c:673
+#, c-format
 msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
-msgstr ""
-"%s: %s: Kérem adja meg, hogy mindig, kikapcsolva, bekapcsolva vagy soha.\n"
+msgstr "%s: %s: Hibás boolean `%s', használja az always, on, off vagy never szavakat.\n"
 
-#: src/init.c:767
-#, fuzzy, c-format
+#: src/init.c:691
+#, c-format
 msgid "%s: %s: Invalid number `%s'.\n"
-msgstr "%s: %s: Helytelen megadás `%s'.\n"
+msgstr "%s: %s:Hibás szám `%s'.\n"
 
-#: src/init.c:998 src/init.c:1017
-#, fuzzy, c-format
+#: src/init.c:930 src/init.c:949
+#, c-format
 msgid "%s: %s: Invalid byte value `%s'\n"
-msgstr "%s: %s: Helytelen tipus `%s'.\n"
+msgstr "%s: %s: Hibás bájt érték `%s'.\n"
 
-#: src/init.c:1042
-#, fuzzy, c-format
+#: src/init.c:974
+#, c-format
 msgid "%s: %s: Invalid time period `%s'\n"
-msgstr "%s: %s: Helytelen megadás `%s'.\n"
-
-#: src/init.c:1096 src/init.c:1186 src/init.c:1281 src/init.c:1306
-#, fuzzy, c-format
-msgid "%s: %s: Invalid value `%s'.\n"
-msgstr "%s: %s: Helytelen megadás `%s'.\n"
+msgstr "%s: %s: Hibás idõ intervallum `%s'.\n"
 
-#: src/init.c:1133
-#, fuzzy, c-format
+#: src/init.c:1051
+#, c-format
 msgid "%s: %s: Invalid header `%s'.\n"
-msgstr "%s: %s: Helytelen megadás `%s'.\n"
+msgstr "%s: %s: Hibás fejléc `%s'.\n"
 
-#: src/init.c:1198
+#: src/init.c:1106
 #, c-format
 msgid "%s: %s: Invalid progress type `%s'.\n"
-msgstr "%s: %s: Helytelen tipus `%s'.\n"
+msgstr "%s: %s: Helytelen típus `%s'.\n"
 
-#: src/init.c:1249
-#, fuzzy, c-format
+#: src/init.c:1157
+#, c-format
 msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
-msgstr "%s: %s: Helytelen megadás `%s'.\n"
+msgstr "%s: %s: Hibás megkötés `%s', használja a `unix'-t vagy `windows'-t.\n"
 
-#: src/log.c:806
+#: src/init.c:1198
+#, c-format
+msgid "%s: %s: Invalid value `%s'.\n"
+msgstr "%s: %s: Hibás érték `%s'.\n"
+
+#: src/log.c:636
 #, c-format
 msgid ""
 "\n"
