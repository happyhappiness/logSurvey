 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1606
+#: src/ftp.c:1819
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Vzorku `%s' nic neodpovídá.\n"
 
 # , c-format
-#: src/ftp.c:1671
-#, c-format
-msgid "Wrote HTML-ized index to `%s' [%ld].\n"
+#: src/ftp.c:1885
+#, fuzzy, c-format
+msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "Výpis adresáøe v HTML formátu byl zapsán do `%s' [%ld].\n"
 
 # , c-format
-#: src/ftp.c:1676
+#: src/ftp.c:1890
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Výpis adresáøe v HTML formátu byl zapsán do `%s'.\n"
 
+#. Still not enough randomness, most likely because neither
+#. /dev/random nor EGD were available.  Resort to a simple and
+#. stupid method -- seed OpenSSL's PRNG with libc PRNG.  This is
+#. cryptographically weak, but people who care about strong
+#. cryptography should install /dev/random (default on Linux) or
+#. specify their own source of randomness anyway.
+#: src/gen_sslfunc.c:109
+msgid "Warning: using a weak random seed.\n"
+msgstr ""
+
+#: src/gen_sslfunc.c:166
+msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
+msgstr ""
+
+#: src/gen_sslfunc.c:223
+msgid "Warning: validation of server certificate not possible!\n"
+msgstr ""
+
 # , c-format
-#: src/getopt.c:454
+#: src/getopt.c:675
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: pøepínaè `%s' není jednoznaèný\n"
 
 # , c-format
-#: src/getopt.c:478
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: pøepínaè `--%s' nemá argument\n"
 
 # , c-format
-#: src/getopt.c:483
+#: src/getopt.c:705
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: pøepínaè `%c%s' nemá argument\n"
 
 # , c-format
-#: src/getopt.c:498
+#: src/getopt.c:723 src/getopt.c:896
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: pøepínaè `%s' vy¾aduje argument\n"
 
 # , c-format
 #. --option
-#: src/getopt.c:528
+#: src/getopt.c:752
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: neznámý pøepínaè `--%s'\n"
 
 # , c-format
 #. +option or -option
-#: src/getopt.c:532
+#: src/getopt.c:756
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: neznámý pøepínaè `%c%s'\n"
 
 # , c-format
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:563
+#: src/getopt.c:782
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: nepøípustný pøepínaè -- %c\n"
 
 # , c-format
+#: src/getopt.c:785
+#, fuzzy, c-format
+msgid "%s: invalid option -- %c\n"
+msgstr "%s: nepøípustný pøepínaè -- %c\n"
+
+# , c-format
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:602
+#: src/getopt.c:815 src/getopt.c:945
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: pøepínaè vy¾aduje argument -- %c\n"
 
-#: src/host.c:374
-msgid "Host not found"
-msgstr "Poèítaè nebyl nalezen"
+# , c-format
+#: src/getopt.c:862
+#, fuzzy, c-format
+msgid "%s: option `-W %s' is ambiguous\n"
+msgstr "%s: pøepínaè `%s' není jednoznaèný\n"
+
+# , c-format
+#: src/getopt.c:880
+#, fuzzy, c-format
+msgid "%s: option `-W %s' doesn't allow an argument\n"
+msgstr "%s: pøepínaè `--%s' nemá argument\n"
+
+#: src/host.c:368
+#, fuzzy
+msgid "Unknown host"
+msgstr "Neznámá chyba"
+
+#. Message modeled after what gai_strerror returns in similar
+#. circumstances.
+#: src/host.c:372
+msgid "Temporary failure in name resolution"
+msgstr ""
 
-#: src/host.c:376
+#: src/host.c:374
 msgid "Unknown error"
 msgstr "Neznámá chyba"
 
+# , c-format
+#: src/host.c:748
+#, fuzzy, c-format
+msgid "Resolving %s... "
+msgstr "Ma¾e se %s.\n"
+
+#: src/host.c:792 src/host.c:839
+#, c-format
+msgid "failed: %s.\n"
+msgstr ""
+
+#: src/host.c:801
+msgid "failed: No IPv4/IPv6 addresses for host.\n"
+msgstr ""
+
+#: src/host.c:842
+msgid "failed: timed out.\n"
+msgstr ""
+
+#: src/html-url.c:297
+#, c-format
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr ""
+
+#: src/http.c:349 src/http.c:1504
+#, c-format
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Nebylo mo¾né odeslat HTTP po¾adavek: %s.\n"
+
+#: src/http.c:663
+msgid "No headers, assuming HTTP/0.9"
+msgstr ""
+
 #. this is fatal
-#: src/http.c:555
+#: src/http.c:1151
 msgid "Failed to set up an SSL context\n"
 msgstr "Nebylo mo¾né nastavit SSL kontext\n"
 
-#: src/http.c:561
+#: src/http.c:1156
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "SSL certifikáty nebylo mo¾né ze souboru `%s' naèíst.\n"
 
-#: src/http.c:565 src/http.c:573
+#: src/http.c:1159 src/http.c:1166
 msgid "Trying without the specified certificate\n"
 msgstr "Program se pokusí pokraèovat bez zadaného certifikátu.\n"
 
-#: src/http.c:569
+#: src/http.c:1163
 #, c-format
 msgid "Failed to get certificate key from %s\n"
-msgstr "Ze souboru `%s' nebylo mo¾né klíè k certifikátu naèíst.\n\n"
-
-#: src/http.c:663 src/http.c:1593
-msgid "Unable to establish SSL connection.\n"
-msgstr "Nebylo mo¾né navázat SSL spojení.\n"
+msgstr ""
+"Ze souboru `%s' nebylo mo¾né klíè k certifikátu naèíst.\n"
+"\n"
 
 # , c-format
-#: src/http.c:671
-#, c-format
-msgid "Reusing connection to %s:%hu.\n"
+#: src/http.c:1382
+#, fuzzy, c-format
+msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Program vyu¾ije existující spojení s %s:%hu.\n"
 
-#: src/http.c:861
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
+#: src/http.c:1434
+#, fuzzy, c-format
+msgid "Failed writing to proxy: %s.\n"
+msgstr "Nebylo mo¾né odeslat HTTP po¾adavek: %s.\n"
+
+#: src/http.c:1443
+#, fuzzy, c-format
+msgid "Failed reading proxy response: %s\n"
 msgstr "Nebylo mo¾né odeslat HTTP po¾adavek: %s.\n"
 
+#: src/http.c:1463
+#, c-format
+msgid "Proxy tunneling failed: %s"
+msgstr ""
+
 # , c-format
-#: src/http.c:866
+#: src/http.c:1510
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s po¾adavek odeslán, program èeká na odpovìï ... "
 
-#: src/http.c:910
-msgid "End of file while parsing headers.\n"
-msgstr "Hlavièka není úplná.\n"
+#: src/http.c:1521
+#, fuzzy
+msgid "No data received.\n"
+msgstr "Nepøi¹la ¾ádná data"
 
 # , c-format
-#: src/http.c:920
+#: src/http.c:1528
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Chyba (%s) pøi ètení hlavièek.\n"
 
-#: src/http.c:959
-msgid "No data received"
-msgstr "Nepøi¹la ¾ádná data"
+#. If we have tried it already, then there is not point
+#. retrying it.
+#: src/http.c:1595
+msgid "Authorization failed.\n"
+msgstr "Autorizace selhala.\n"
+
+#: src/http.c:1609
+msgid "Unknown authentication scheme.\n"
+msgstr "Server po¾aduje neznámý zpùsob autentifikace.\n"
 
-#: src/http.c:961
+#: src/http.c:1634
 msgid "Malformed status line"
 msgstr "Odpovìï serveru má zkomolený stavový øádek"
 
-#: src/http.c:966
+#: src/http.c:1636
 msgid "(no description)"
 msgstr "(¾ádný popis)"
 
-#: src/http.c:1089
-msgid "Authorization failed.\n"
-msgstr "Autorizace selhala.\n"
-
-#: src/http.c:1096
-msgid "Unknown authentication scheme.\n"
-msgstr "Server po¾aduje neznámý zpùsob autentifikace.\n"
-
 # , c-format
-#: src/http.c:1136
+#: src/http.c:1700
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Pøesmìrováno na: %s%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:1701 src/http.c:1801
 msgid "unspecified"
 msgstr "neudáno"
 
-#: src/http.c:1138
+#: src/http.c:1702
 msgid " [following]"
 msgstr " [následuji]"
 
-#: src/http.c:1200
-msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
-msgstr "\n    Soubor je ji¾ plnì pøenesen, nebude se nic dìlat.\n\n"
-
-#: src/http.c:1216
-#, c-format
+#. If `-c' is in use and the file has been fully downloaded (or
+#. the remote file has shrunk), Wget effectively requests bytes
+#. after the end of file and the server response with 416.
+#: src/http.c:1751
 msgid ""
 "\n"
-"Continued download failed on this file, which conflicts with `-c'.\n"
-"Refusing to truncate existing file `%s'.\n"
+"    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 "\n"
-"Na pøeru¹ené stahování tohoto souboru nelze navázat. Bylo ov¹em zadáno `-c'.\n"
-"Existující soubor `%s' tedy radìji nebude zkrácen.\n"
+"    Soubor je ji¾ plnì pøenesen, nebude se nic dìlat.\n"
 "\n"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1259
+#: src/http.c:1781
 msgid "Length: "
 msgstr "Délka: "
 
-# , c-format
-#: src/http.c:1264
-#, c-format
-msgid " (%s to go)"
-msgstr " (%s zbývá)"
-
-#: src/http.c:1269
+#: src/http.c:1801
 msgid "ignored"
 msgstr "je ignorována"
 
-#: src/http.c:1399
+#: src/http.c:1943
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Varování: HTTP nepodporuje ¾olíkové znaky.\n"
 
 # , c-format
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:1417
+#: src/http.c:1978
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Soubor `%s' je ji¾ zde a nebude se znovu pøená¹et.\n"
 
 # , c-format
-#: src/http.c:1585
+#: src/http.c:2165
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Nelze zapsat do `%s' (%s).\n"
 
+#: src/http.c:2174
+msgid "Unable to establish SSL connection.\n"
+msgstr "Nebylo mo¾né navázat SSL spojení.\n"
+
 # , c-format
-#: src/http.c:1602
+#: src/http.c:2184
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "CHYBA: Pøesmìrování (%d) bez udané nové adresy.\n"
 
 # , c-format
-#: src/http.c:1630
+#: src/http.c:2216
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s CHYBA %d: %s.\n"
 
-#: src/http.c:1642
+#: src/http.c:2229
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr ""
 "Nelze pou¾ít èasová razítka (`time-stamps'), proto¾e v odpovìdi serveru \n"
 "schází hlavièka \"Last-modified\".\n"
 
-#: src/http.c:1650
+#: src/http.c:2237
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr ""
 "Èasové razítko souboru (`time-stamp') bude ignorováno, proto¾e hlavièka \n"
 "\"Last-modified\" obsahuje neplatné údaje.\n"
 
-#: src/http.c:1673
+#: src/http.c:2260
 #, c-format
-msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
-msgstr "Lokální soubor `%s' není star¹í, ne¾ vzdálený soubor, a není jej tøeba stahovat.\n\n"
+msgid ""
+"Server file no newer than local file `%s' -- not retrieving.\n"
+"\n"
+msgstr ""
+"Lokální soubor `%s' není star¹í, ne¾ vzdálený soubor, a není jej tøeba "
+"stahovat.\n"
+"\n"
 
 # , c-format
-#: src/http.c:1680
-#, c-format
-msgid "The sizes do not match (local %ld) -- retrieving.\n"
+#: src/http.c:2268
+#, fuzzy, c-format
+msgid "The sizes do not match (local %s) -- retrieving.\n"
 msgstr "Velikosti se neshodují (lokálnì %ld), soubor je tøeba stáhnout.\n"
 
-#: src/http.c:1684
+#: src/http.c:2273
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Lokální soubor je star¹í a vzdálený soubor se proto bude pøená¹et.\n"
 
 # , c-format
-#: src/http.c:1728
-#, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
-msgstr "%s (%s) - `%s' ulo¾eno [%ld/%ld]\n\n"
+#: src/http.c:2315
+#, fuzzy, c-format
+msgid ""
+"%s (%s) - `%s' saved [%s/%s]\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' ulo¾eno [%ld/%ld]\n"
+"\n"
 
 # , c-format
-#: src/http.c:1774
-#, c-format
-msgid "%s (%s) - Connection closed at byte %ld. "
+#: src/http.c:2372
+#, fuzzy, c-format
+msgid "%s (%s) - Connection closed at byte %s. "
 msgstr "%s (%s) - Spojení ukonèeno na bajtu %ld. "
 
 # , c-format
-#: src/http.c:1782
-#, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
-msgstr "%s (%s) - `%s' ulo¾eno [%ld/%ld])\n\n"
+#: src/http.c:2381
+#, fuzzy, c-format
+msgid ""
+"%s (%s) - `%s' saved [%s/%s])\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' ulo¾eno [%ld/%ld])\n"
+"\n"
 
 # , c-format
-#: src/http.c:1801
-#, c-format
-msgid "%s (%s) - Connection closed at byte %ld/%ld. "
+#: src/http.c:2407
+#, fuzzy, c-format
+msgid "%s (%s) - Connection closed at byte %s/%s. "
 msgstr "%s (%s) - Spojení ukonèeno na bajtu %ld/%ld. "
 
 # , c-format
-#: src/http.c:1812
-#, c-format
-msgid "%s (%s) - Read error at byte %ld (%s)."
+#: src/http.c:2421
+#, fuzzy, c-format
+msgid "%s (%s) - Read error at byte %s (%s)."
 msgstr "%s (%s) - Chyba pøi ètení dat na bajtu %ld (%s)."
 
 # , c-format
-#: src/http.c:1820
-#, c-format
-msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
+#: src/http.c:2431
+#, fuzzy, c-format
+msgid "%s (%s) - Read error at byte %s/%s (%s). "
 msgstr "%s (%s) - Chyba pøi ètení dat na bajtu %ld/%ld (%s). "
 
+#: src/init.c:342
+#, c-format
+msgid "%s: WGETRC points to %s, which doesn't exist.\n"
+msgstr ""
+
 # , c-format
-#: src/init.c:349 src/netrc.c:267
+#: src/init.c:395 src/netrc.c:277
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: Nelze pøeèíst %s (%s).\n"
 
 # , c-format
-#: src/init.c:367 src/init.c:373
+#: src/init.c:413 src/init.c:419
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: Chyba v %s na øádku %d.\n"
 
 # , c-format
-#: src/init.c:405
+#: src/init.c:451
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
-msgstr "%s: Varování: Globální i u¾ivatelské wgetrc jsou shodnì ulo¾eny v `%s'.\n"
+msgstr ""
+"%s: Varování: Globální i u¾ivatelské wgetrc jsou shodnì ulo¾eny v `%s'.\n"
 
 # , c-format
-#: src/init.c:497
-#, c-format
-msgid "%s: BUG: unknown command `%s', value `%s'.\n"
-msgstr "%s: CHYBA: Neznámý pøíkaz `%s', hodnota `%s'.\n"
-
-#: src/init.c:529
-#, c-format
-msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
-msgstr "%s: %s: `%s' nelze pøevést na IP adresu.\n"
+#: src/init.c:595
+#, fuzzy, c-format
+msgid "%s: Invalid --execute command `%s'\n"
+msgstr "%s: Neplatná specifikace `%s'\n"
 
 # , c-format
-#: src/init.c:559
-#, c-format
-msgid "%s: %s: Please specify on or off.\n"
+#: src/init.c:631
+#, fuzzy, c-format
+msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
 msgstr "%s: %s: Zadejte prosím `on' (zapnuto) nebo `off' (vypnuto).\n"
 
 # , c-format
-#: src/init.c:603
-#, c-format
-msgid "%s: %s: Please specify always, on, off, or never.\n"
-msgstr "%s: %s: Zadejte prosím `always' (v¾dy), `on' (zapnuto), `off' (vypnuto), nebo `never' (nikdy).\n"
+#: src/init.c:674
+#, fuzzy, c-format
+msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
+msgstr ""
+"%s: %s: Zadejte prosím `always' (v¾dy), `on' (zapnuto), `off' (vypnuto), "
+"nebo `never' (nikdy).\n"
 
 # , c-format
-#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
-#, c-format
-msgid "%s: %s: Invalid specification `%s'.\n"
+#: src/init.c:693
+#, fuzzy, c-format
+msgid "%s: %s: Invalid number `%s'.\n"
 msgstr "%s: %s: Neplatná specifikace `%s'\n"
 
 # , c-format
-#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
-#, c-format
-msgid "%s: Invalid specification `%s'\n"
-msgstr "%s: Neplatná specifikace `%s'\n"
+#: src/init.c:926 src/init.c:945
+#, fuzzy, c-format
+msgid "%s: %s: Invalid byte value `%s'\n"
+msgstr "%s: %s: Neplatná specifikace `%s'\n"
 
 # , c-format
-#: src/main.c:120
-#, c-format
-msgid "Usage: %s [OPTION]... [URL]...\n"
-msgstr "Pou¾ití: %s [PØEPÍNAÈ]... [URL]...\n"
+#: src/init.c:970
+#, fuzzy, c-format
+msgid "%s: %s: Invalid time period `%s'\n"
+msgstr "%s: %s: Neplatná specifikace `%s'\n"
 
 # , c-format
-#: src/main.c:128
-#, c-format
-msgid "GNU Wget %s, a non-interactive network retriever.\n"
-msgstr "GNU Wget %s, program pro neinteraktivní stahování souborù.\n"
+#: src/init.c:1037
+#, fuzzy, c-format
+msgid "%s: %s: Invalid header `%s'.\n"
+msgstr "%s: %s: Neplatná specifikace `%s'\n"
 
-#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
-#. don't bitch.  Also, it makes translation much easier.
-#: src/main.c:133
-msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
-msgstr ""
-"\n"
-"Argumenty, povinné u dlouhých pøepínaèù, jsou povinné i pro krátké verze\n"
-"pøepínaèù.\n"
-"\n"
+# , c-format
+#: src/init.c:1083
+#, fuzzy, c-format
+msgid "%s: %s: Invalid progress type `%s'.\n"
+msgstr "%s: %s: Neplatná specifikace `%s'\n"
+
+# , c-format
+#: src/init.c:1134
+#, fuzzy, c-format
+msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
+msgstr "%s: %s: Neplatná specifikace `%s'\n"
+
+# , c-format
+#: src/init.c:1175
+#, fuzzy, c-format
+msgid "%s: %s: Invalid value `%s'.\n"
+msgstr "%s: %s: Neplatná specifikace `%s'\n"
 
-#: src/main.c:137
+#: src/log.c:777
+#, fuzzy, c-format
 msgid ""
-"Startup:\n"
-"  -V,  --version           display the version of Wget and exit.\n"
-"  -h,  --help              print this help.\n"
-"  -b,  --background        go to background after startup.\n"
-"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
-"\n"
-msgstr ""
-"Zaèátek:\n"
-"  -V,  --version           vypí¹e informaci o verzi programu Wget a skonèí\n"
-"  -h,  --help              vypí¹e tuto nápovìdu\n"
-"  -b,  --background        po spu¹tìní pokraèuje program v bìhu na pozadí\n"
-"  -e,  --execute=PØÍKAZ    proveïe pøíkaz zadaný ve stylu `.wgetrc'\n"
 "\n"
+"%s received, redirecting output to `%s'.\n"
+msgstr "Byl zachycen signál %s, výstup pøesmìrován do `%%s'.\n"
 
-# , fuzzy
-#: src/main.c:144
+#. Eek!  Opening the alternate log file has failed.  Nothing we
+#. can do but disable printing completely.
+#: src/log.c:787
+#, fuzzy, c-format
 msgid ""
-"Logging and input file:\n"
-"  -o,  --output-file=FILE     log messages to FILE.\n"
-"  -a,  --append-output=FILE   append messages to FILE.\n"
-"  -d,  --debug                print debug output.\n"
-"  -q,  --quiet                quiet (no output).\n"
-"  -v,  --verbose              be verbose (this is the default).\n"
-"  -nv, --non-verbose          turn off verboseness, without being quiet.\n"
-"  -i,  --input-file=FILE      download URLs found in FILE.\n"
-"  -F,  --force-html           treat input file as HTML.\n"
-"  -B,  --base=URL             prepends URL to relative links in -F -i file.\n"
-"       --sslcertfile=FILE     optional client certificate.\n"
-"       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n"
 "\n"
+"%s received.\n"
+msgstr "Nepøi¹la ¾ádná data"
+
+#: src/log.c:788
+#, c-format
+msgid "%s: %s; disabling logging.\n"
 msgstr ""
-"Protokolování a vstupní soubor:\n"
-"  -o,  --output-file=SOUBOR   název souboru s protokolem\n"
-"  -a,  --append-output=SOUBOR protokol se pøipojí na konec tohoto souboru\n"
-"  -d,  --debug                vypisuje ladicí informace\n"
-"  -q,  --quiet                nevypisuje vùbec nic\n"
-"  -v,  --verbose              bude upovídaný (implicitnì zapnuto)\n"
-"  -nv, --non-verbose          vypisuje pouze nejdùle¾itìj¹í informace\n"
-"  -i,  --input-file=SOUBOR    výchozí URL odkazy naète z tohoto souboru\n"
-"  -F,  --force-html           soubor s URL je v HTML formátu\n"
-"  -B,  --base=URL             pøidá URL na zaèátky relat. odkazù pøi '-F -i'\n"
-"       --sslcertfile=SOUBOR   volitelný certifikát klienta\n"
-"       --sslcertkey=SOUBOR    volitelný soubor klíèù pro tento certifikát\n"
-"\n"
 
-# , fuzzy
-#: src/main.c:158
+# , c-format
+#: src/main.c:363
+#, c-format
+msgid "Usage: %s [OPTION]... [URL]...\n"
+msgstr "Pou¾ití: %s [PØEPÍNAÈ]... [URL]...\n"
+
+#: src/main.c:375
+#, fuzzy
 msgid ""
-"Download:\n"
-"       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local host.\n"
-"  -t,  --tries=NUMBER           set number of retries to NUMBER (0 unlimits).\n"
-"  -O   --output-document=FILE   write documents to FILE.\n"
-"  -nc, --no-clobber             don't clobber existing files or use .# suffixes.\n"
-"  -c,  --continue               resume getting a partially-downloaded file.\n"
-"       --dot-style=STYLE        set retrieval display style.\n"
-"  -N,  --timestamping           don't re-retrieve files unless newer than local.\n"
-"  -S,  --server-response        print server response.\n"
-"       --spider                 don't download anything.\n"
-"  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n"
-"  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
-"       --waitretry=SECONDS      wait 1...SECONDS between retries of a retrieval.\n"
-"  -Y,  --proxy=on/off           turn proxy on or off.\n"
-"  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
+"Mandatory arguments to long options are mandatory for short options too.\n"
 "\n"
 msgstr ""
-"Stahování:\n"
-"       --bind-address=ADRESA    pou¾ij lokální rozhraní s danou adresou (IP nebo jméno)\n"
-"  -t,  --tries=ÈÍSLO            poèet pokusù stáhnout URL (0 donekoneèna)\n"
-"  -O   --output-document=SOUBOR sta¾ené dokumenty ukládá do tohoto souboru\n"
-"  -nc, --no-clobber             nepøepisuje existující soubory\n"
-"  -c,  --continue               pokraèuje ve stahování èásteènì pøenesených dat\n"
-"       --dot-style=STYL         nastaví zpùsob zobrazení pøi stahování dat\n"
-"  -N,  --timestamping           nestahuje star¹í soubory (zapne èasová razítka)\n"
-"  -S,  --server-response        vypisuje odpovìdi serveru\n"
-"       --spider                 nic nestahuje\n"
-"  -T,  --timeout=SEKUNDY        nastaví timeout pøi ètení na tuto hodnotu\n"
-"  -w,  --wait=POÈET             pøed ka¾dým stahováním poèká POÈET sekund\n"
-"       --waitretry=POÈET        èeká 1...POÈET sec pøed novým pokusem o sta¾ení\n"
-"  -Y,  --proxy=on/off           zapne pøenos pøes proxy (standardnì `off')\n"
-"  -Q,  --quota=BAJTÙ            nastaví limit objemu ulo¾ených dat\n"
+"\n"
+"Argumenty, povinné u dlouhých pøepínaèù, jsou povinné i pro krátké verze\n"
+"pøepínaèù.\n"
 "\n"
 
-# , fuzzy
-#: src/main.c:175
+#: src/main.c:377
+msgid "Startup:\n"
+msgstr ""
+
+#: src/main.c:379
+msgid "  -V,  --version           display the version of Wget and exit.\n"
+msgstr ""
+
+#: src/main.c:381
+msgid "  -h,  --help              print this help.\n"
+msgstr ""
+
+#: src/main.c:383
+msgid "  -b,  --background        go to background after startup.\n"
+msgstr ""
+
+#: src/main.c:385
+msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
+msgstr ""
+
+#: src/main.c:389
+msgid "Logging and input file:\n"
+msgstr ""
+
+#: src/main.c:391
+msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
+msgstr ""
+
+#: src/main.c:393
+msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
+msgstr ""
+
+#: src/main.c:396
+msgid "  -d,  --debug               print lots of debugging information.\n"
+msgstr ""
+
+#: src/main.c:399
+msgid "  -q,  --quiet               quiet (no output).\n"
+msgstr ""
+
+#: src/main.c:401
+msgid "  -v,  --verbose             be verbose (this is the default).\n"
+msgstr ""
+
+#: src/main.c:403
 msgid ""
-"Directories:\n"
-"  -nd  --no-directories            don't create directories.\n"
-"  -x,  --force-directories         force creation of directories.\n"
-"  -nH, --no-host-directories       don't create host directories.\n"
-"  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
-"       --cut-dirs=NUMBER           ignore NUMBER remote directory components.\n"
-"\n"
+"  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
 msgstr ""
-"Adresáøe:\n"
-"  -nd  --no-directories            nevytváøí adresáøe\n"
-"  -x,  --force-directories         v¾dy vytváøí adresáøe\n"
-"  -nH, --no-host-directories       nevytváøí adresáøe s adresou serveru\n"
-"  -P,  --directory-prefix=PREFIX   ukládá data do PREFIX/...\n"
-"       --cut-dirs=POÈET            nevytváøí prvních POÈET podadresáøù\n"
-"\n"
 
-# , fuzzy
-#: src/main.c:183
+#: src/main.c:405
+msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
+msgstr ""
+
+#: src/main.c:407
+msgid "  -F,  --force-html          treat input file as HTML.\n"
+msgstr ""
+
+#: src/main.c:409
 msgid ""
-"HTTP options:\n"
-"       --http-user=USER      set http user to USER.\n"
-"       --http-passwd=PASS    set http password to PASS.\n"
-"  -C,  --cache=on/off        (dis)allow server-cached data (normally allowed).\n"
-"  -E,  --html-extension      save all text/html documents with .html extension.\n"
-"       --ignore-length       ignore `Content-Length' header field.\n"
-"       --header=STRING       insert STRING among the headers.\n"
-"       --proxy-user=USER     set USER as proxy username.\n"
-"       --proxy-passwd=PASS   set PASS as proxy password.\n"
-"       --referer=URL         include `Referer: URL' header in HTTP request.\n"
-"  -s,  --save-headers        save the HTTP headers to file.\n"
-"  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n"
-"       --no-http-keep-alive  disable HTTP keep-alive (persistent connections).\n"
-"       --cookies=off         don't use cookies.\n"
-"       --load-cookies=FILE   load cookies from FILE before session.\n"
-"       --save-cookies=FILE   save cookies to FILE after session.\n"
-"\n"
+"  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
 msgstr ""
-"Pøepínaèe pro HTTP:\n"
-"       --http-user=U®IVATEL  u¾ivatelské jméno pro autorizovaný HTTP pøenos\n"
-"       --http-passwd=HESLO   heslo pro autorizovaný HTTP pøenos \n"
-"  -C,  --cache=on/off        povolí èi zaká¾e pou¾ití vyrovnávací pamìti na\n"
-"                             stranì serveru (implicitnì `on')\n"
-"  -E,  --html-extension      ulo¾í dokumenty typu `text/html' s pøíponou .html\n"
-"       --ignore-length       ignoruje pole `Content-Length' v hlavièce\n"
-"       --header=ØETÌZEC      po¹le ØETÌZEC serveru jako souèást hlavièek\n"
-"       --proxy-user=U®IVATEL jméno u¾ivatele vy¾adované pro proxy pøenos\n"
-"       --proxy-passwd=HESLO  heslo pro proxy pøenos\n"
-"       --referer=URL         posílá v hlaviècce HTTP po¾adavku `Referer: URL'\n"
-"  -s,  --save-headers        do stahovaného souboru ulo¾í i hlavièky HTTP\n"
-"  -U,  --user-agent=AGENT    místo identifikace `Wget/VERZE' posílá v hlavièce \n"
-"                             HTTP po¾adavku identifikaèní øetìzec AGENT\n"
-"       --no-http-keep-alive  vypne HTTP keep-alive (trvalé spojení se serverem)\n"
-"       --cookies=off         nebude pou¾ívat koláèky (HTTP cookies)\n"
-"       --load-cookies=SOUBOR pøed sezením naète koláèky ze souboru SOUBOR\n"
-"       --save-cookies=SOUBOR po sezení ulo¾í koláèky do souboru SOUBOR\n"
-"\n"
 
-# , fuzzy
-#: src/main.c:201
+#: src/main.c:413
+msgid "Download:\n"
+msgstr ""
+
+#: src/main.c:415
 msgid ""
-"FTP options:\n"
-"  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
-"  -g,  --glob=on/off           turn file name globbing on or off.\n"
-"       --passive-ftp           use the \"passive\" transfer mode.\n"
-"       --retr-symlinks         when recursing, get linked-to files (not dirs).\n"
-"\n"
+"  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
+"unlimits).\n"
+msgstr ""
+
+#: src/main.c:417
+msgid "       --retry-connrefused       retry even if connection is refused.\n"
+msgstr ""
+
+#: src/main.c:419
+msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
+msgstr ""
+
+#: src/main.c:421
+msgid ""
+"  -nc, --no-clobber              skip downloads that would download to\n"
+"                                 existing files.\n"
+msgstr ""
+
+#: src/main.c:424
+msgid ""
+"  -c,  --continue                resume getting a partially-downloaded "
+"file.\n"
+msgstr ""
+
+#: src/main.c:426
+msgid "       --progress=TYPE           select progress gauge type.\n"
+msgstr ""
+
+#: src/main.c:428
+msgid ""
+"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
+"                                 local.\n"
+msgstr ""
+
+#: src/main.c:431
+msgid "  -S,  --server-response         print server response.\n"
+msgstr ""
+
+#: src/main.c:433
+msgid "       --spider                  don't download anything.\n"
+msgstr ""
+
+#: src/main.c:435
+msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
+msgstr ""
+
+#: src/main.c:437
+msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:439
+msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:441
+msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:443
+msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
+msgstr ""
+
+#: src/main.c:445
+msgid ""
+"       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
+"retrieval.\n"
+msgstr ""
+
+#: src/main.c:447
+msgid ""
+"       --random-wait             wait from 0...2*WAIT secs between "
+"retrievals.\n"
+msgstr ""
+
+#: src/main.c:449
+msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
+msgstr ""
+
+#: src/main.c:451
+msgid "       --no-proxy                explicitly turn off proxy.\n"
+msgstr ""
+
+#: src/main.c:453
+msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
+msgstr ""
+
+#: src/main.c:455
+msgid ""
+"       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
+"host.\n"
+msgstr ""
+
+#: src/main.c:457
+msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
+msgstr ""
+
+#: src/main.c:459
+msgid "       --no-dns-cache            disable caching DNS lookups.\n"
+msgstr ""
+
+#: src/main.c:461
+msgid ""
+"       --restrict-file-names=OS  restrict chars in file names to ones OS "
+"allows.\n"
+msgstr ""
+
+#: src/main.c:464
+msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
+msgstr ""
+
+#: src/main.c:466
+msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
+msgstr ""
+
+#: src/main.c:471
+#, fuzzy
+msgid "Directories:\n"
+msgstr "Adresáø     "
+
+#: src/main.c:473
+msgid "  -nd, --no-directories           don't create directories.\n"
+msgstr ""
+
+#: src/main.c:475
+msgid "  -x,  --force-directories        force creation of directories.\n"
+msgstr ""
+
+#: src/main.c:477
+msgid "  -nH, --no-host-directories      don't create host directories.\n"
+msgstr ""
+
+#: src/main.c:479
+msgid "       --protocol-directories     use protocol name in directories.\n"
+msgstr ""
+
+#: src/main.c:481
+msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
+msgstr ""
+
+#: src/main.c:483
+msgid ""
+"       --cut-dirs=NUMBER          ignore NUMBER remote directory "
+"components.\n"
+msgstr ""
+
+#: src/main.c:487
+msgid "HTTP options:\n"
+msgstr ""
+
+#: src/main.c:489
+msgid "       --http-user=USER        set http user to USER.\n"
+msgstr ""
+
+#: src/main.c:491
+msgid "       --http-passwd=PASS      set http password to PASS.\n"
+msgstr ""
+
+#: src/main.c:493
+msgid "       --no-cache              disallow server-cached data.\n"
+msgstr ""
+
+#: src/main.c:495
+msgid ""
+"  -E,  --html-extension        save HTML documents with `.html' extension.\n"
+msgstr ""
+
+#: src/main.c:497
+msgid "       --ignore-length         ignore `Content-Length' header field.\n"
+msgstr ""
+
+#: src/main.c:499
+msgid "       --header=STRING         insert STRING among the headers.\n"
+msgstr ""
+
+#: src/main.c:501
+msgid "       --proxy-user=USER       set USER as proxy username.\n"
+msgstr ""
+
+#: src/main.c:503
+msgid "       --proxy-passwd=PASS     set PASS as proxy password.\n"
+msgstr ""
+
+#: src/main.c:505
+msgid ""
+"       --referer=URL           include `Referer: URL' header in HTTP "
+"request.\n"
+msgstr ""
+
+#: src/main.c:507
+msgid "       --save-headers          save the HTTP headers to file.\n"
+msgstr ""
+
+#: src/main.c:509
+msgid ""
+"  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
+msgstr ""
+
+#: src/main.c:511
+msgid ""
+"       --no-http-keep-alive    disable HTTP keep-alive (persistent "
+"connections).\n"
+msgstr ""
+
+#: src/main.c:513
+msgid "       --no-cookies            don't use cookies.\n"
+msgstr ""
+
+#: src/main.c:515
+msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
+msgstr ""
+
+#: src/main.c:517
+msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
+msgstr ""
+
+#: src/main.c:519
+msgid ""
+"       --keep-session-cookies  load and save session (non-permanent) "
+"cookies.\n"
+msgstr ""
+
+#: src/main.c:521
+msgid ""
+"       --post-data=STRING      use the POST method; send STRING as the "
+"data.\n"
+msgstr ""
+
+#: src/main.c:523
+msgid ""
+"       --post-file=FILE        use the POST method; send contents of FILE.\n"
+msgstr ""
+
+#: src/main.c:528
+msgid "HTTPS (SSL) options:\n"
+msgstr ""
+
+#: src/main.c:530
+msgid "       --sslcertfile=FILE    optional client certificate.\n"
+msgstr ""
+
+#: src/main.c:532
+msgid "       --sslcertkey=KEYFILE  optional keyfile for this certificate.\n"
+msgstr ""
+
+#: src/main.c:534
+msgid "       --sslcadir=DIR        dir where hash list of CA's are stored.\n"
+msgstr ""
+
+#: src/main.c:536
+msgid "       --sslcafile=FILE      file with bundle of CA's.\n"
+msgstr ""
+
+#: src/main.c:538
+msgid ""
+"       --sslcerttype=0/1     Client-Cert type 0=PEM (default) / 1=ASN1 "
+"(DER).\n"
+msgstr ""
+
+#: src/main.c:540
+msgid "       --sslcheckcert=0/1    Check the server cert against given CA.\n"
+msgstr ""
+
+#: src/main.c:542
+msgid ""
+"       --sslprotocol=0-3     choose SSL protocol; 0=automatic,\n"
+"                             1=SSLv2 2=SSLv3 3=TLSv1.\n"
+msgstr ""
+
+#: src/main.c:545
+msgid "       --egd-file=FILE       file name of the EGD socket.\n"
+msgstr ""
+
+#: src/main.c:550
+msgid "FTP options:\n"
+msgstr ""
+
+#: src/main.c:552
+msgid "       --no-remove-listing     don't remove `.listing' files.\n"
+msgstr ""
+
+#: src/main.c:554
+msgid "       --no-glob               turn off FTP file name globbing.\n"
+msgstr ""
+
+#: src/main.c:556
+msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
+msgstr ""
+
+#: src/main.c:558
+msgid ""
+"       --retr-symlinks         when recursing, get linked-to files (not "
+"dir).\n"
+msgstr ""
+
+#: src/main.c:560
+msgid "       --preserve-permissions  preserve remote file permissions.\n"
+msgstr ""
+
+#: src/main.c:564
+msgid "Recursive download:\n"
+msgstr ""
+
+#: src/main.c:566
+msgid "  -r,  --recursive          specify recursive download.\n"
+msgstr ""
+
+#: src/main.c:568
+msgid ""
+"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
+"infinite).\n"
 msgstr ""
-"Pøepínaèe pro FTP protokol:\n"
-"  -nr, --dont-remove-listing  nema¾e soubory `.listing' s obsahy adresáøù\n"
-"  -g,  --glob=on/off          zapne èi vypne expanzi ¾olíkù ve jménech souborù\n"
-"       --passive-ftp          pou¾ije pasivní mód pøenosu dat\n"
-"       --retr-symlinks        v rekurzivním módu stahuje i symbolické odkazy na\n"
-"                              soubory (nikoliv na adresáøe)\n"
 
-#: src/main.c:208
+#: src/main.c:570
 msgid ""
-"Recursive retrieval:\n"
-"  -r,  --recursive          recursive web-suck -- use with care!\n"
-"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for infinite).\n"
 "       --delete-after       delete files locally after downloading them.\n"
-"  -k,  --convert-links      convert non-relative links to relative.\n"
+msgstr ""
+
+#: src/main.c:572
+msgid ""
+"  -k,  --convert-links      make links in downloaded HTML point to local "
+"files.\n"
+msgstr ""
+
+#: src/main.c:574
+msgid ""
 "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
+msgstr ""
+
+#: src/main.c:576
+msgid ""
 "  -m,  --mirror             shortcut option equivalent to -r -N -l inf -nr.\n"
-"  -p,  --page-requisites    get all images, etc. needed to display HTML page.\n"
-"\n"
 msgstr ""
-"Rekurzivní stahování:\n"
-"  -r,  --recursive             rekurzivní stahování -- buïte opatrní!\n"
-"  -l,  --level=ÈÍSLO           maximální hloubka rekurze (0 bez limitu)\n"
-"       --delete-after          po pøenosu sma¾e sta¾ené soubory\n"
-"  -k,  --convert-links         absolutní URL pøeveïe na relativní\n"
-"  -K,  --backup-converted      pøed konverzí ulo¾í `X' jako `X.orig'\n"
-"  -m,  --mirror                zapne pøepínaèe vhodné pro zrcadlení dat \n"
-"  -p,  --page-requisites       stáhne v¹e nutné pro zobrazení HTML stránky\n"
 
-# , fuzzy
-#: src/main.c:218
+#: src/main.c:578
 msgid ""
-"Recursive accept/reject:\n"
-"  -A,  --accept=LIST                comma-separated list of accepted extensions.\n"
-"  -R,  --reject=LIST                comma-separated list of rejected extensions.\n"
-"  -D,  --domains=LIST               comma-separated list of accepted domains.\n"
-"       --exclude-domains=LIST       comma-separated list of rejected domains.\n"
-"       --follow-ftp                 follow FTP links from HTML documents.\n"
-"       --follow-tags=LIST           comma-separated list of followed HTML tags.\n"
-"  -G,  --ignore-tags=LIST           comma-separated list of ignored HTML tags.\n"
-"  -H,  --span-hosts                 go to foreign hosts when recursive.\n"
-"  -L,  --relative                   follow relative links only.\n"
-"  -I,  --include-directories=LIST   list of allowed directories.\n"
-"  -X,  --exclude-directories=LIST   list of excluded directories.\n"
-"  -nh, --no-host-lookup             don't DNS-lookup hosts.\n"
-"  -np, --no-parent                  don't ascend to the parent directory.\n"
-"\n"
+"  -p,  --page-requisites    get all images, etc. needed to display HTML "
+"page.\n"
+msgstr ""
+
+#: src/main.c:580
+msgid ""
+"       --strict-comments    turn on strict (SGML) handling of HTML "
+"comments.\n"
+msgstr ""
+
+#: src/main.c:584
+msgid "Recursive accept/reject:\n"
+msgstr ""
+
+#: src/main.c:586
+msgid ""
+"  -A,  --accept=LIST               comma-separated list of accepted "
+"extensions.\n"
+msgstr ""
+
+#: src/main.c:588
+msgid ""
+"  -R,  --reject=LIST               comma-separated list of rejected "
+"extensions.\n"
+msgstr ""
+
+#: src/main.c:590
+msgid ""
+"  -D,  --domains=LIST              comma-separated list of accepted "
+"domains.\n"
+msgstr ""
+
+#: src/main.c:592
+msgid ""
+"       --exclude-domains=LIST      comma-separated list of rejected "
+"domains.\n"
+msgstr ""
+
+#: src/main.c:594
+msgid ""
+"       --follow-ftp                follow FTP links from HTML documents.\n"
+msgstr ""
+
+#: src/main.c:596
+msgid ""
+"       --follow-tags=LIST          comma-separated list of followed HTML "
+"tags.\n"
+msgstr ""
+
+#: src/main.c:598
+msgid ""
+"       --ignore-tags=LIST          comma-separated list of ignored HTML "
+"tags.\n"
+msgstr ""
+
+#: src/main.c:600
+msgid ""
+"  -H,  --span-hosts                go to foreign hosts when recursive.\n"
+msgstr ""
+
+#: src/main.c:602
+msgid "  -L,  --relative                  follow relative links only.\n"
+msgstr ""
+
+#: src/main.c:604
+msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
+msgstr ""
+
+#: src/main.c:606
+msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
+msgstr ""
+
+#: src/main.c:608
+msgid ""
+"  -np, --no-parent                 don't ascend to the parent directory.\n"
 msgstr ""
-"Omezení pøi rekurzi:\n"
-"  -A,  --accept=SEZNAM              seznam povolených extenzí souborù\n"
-"  -R,  --reject=SEZNAM              seznam nepovolených extenzí souborù\n"
-"  -D,  --domains=SEZNAM             seznam povolených domén\n"
-"       --exclude-domains=SEZNAM     seznam nepovolených domén\n"
-"       --follow-ftp                 následuje FTP odkazy v HTML dokumentech\n"
-"       --follow-tags=LIST           seznam následovaných HTML znaèek \n"
-"  -G,  --ignore-tags=LIST           seznam ignorovaných HTML znaèek\n"
-"  -H,  --span-hosts                 naèítá dokumenty i z ostatních serverù\n"
-"  -I,  --include-directories=SEZNAM seznam povolených adresáøù\n"
-"  -L,  --relative                   následuje pouze relativní odkazy\n"
-"  -X,  --exclude-directories=SEZNAM seznam vylouèených adresáøù\n"
-"  -nh, --no-host-lookup             nevyhledává adresy v DNS\n"
-"  -np, --no-parent                  nesestupuje do rodièovského adresáøe\n"
-"\n"
 
 # , fuzzy
-#: src/main.c:234
+#: src/main.c:612
 msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
 msgstr ""
 "Zprávy o chybách a návrhy na vylep¹ení programu zasílejte na adresu\n"
 "<bug-wget@gnu.org> (pouze anglicky).\n"
 "Komentáøe k èeskému pøekladu zasílejte na adresu <cs@li.org>. \n"
 
-# , fuzzy
-#: src/main.c:420
+# , c-format
+#: src/main.c:617
 #, c-format
-msgid "%s: debug support not compiled in.\n"
-msgstr "%s: program nebyl zkompilován s podporou pro ladìní.\n"
+msgid "GNU Wget %s, a non-interactive network retriever.\n"
+msgstr "GNU Wget %s, program pro neinteraktivní stahování souborù.\n"
 
-#: src/main.c:472
+#: src/main.c:631
+msgid "Copyright (C) 2005 Free Software Foundation, Inc.\n"
+msgstr ""
+
+#: src/main.c:633
+#, fuzzy
 msgid ""
-"Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
 "This program is distributed in the hope that it will be useful,\n"
 "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
 "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
 "GNU General Public License for more details.\n"
 msgstr ""
-"Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
+"Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, "
+"Inc.\n"
 "Tento program je ¹íøen v nadìji, ¾e bude u¾iteèný, av¹ak\n"
 "BEZ JAKÉKOLI ZÁRUKY; neposkytují se ani odvozené záruky PRODEJNOSTI \n"
 "anebo VHODNOSTI PRO URÈITÝ ÚÈEL. Dal¹í podrobnosti hledejte \n"
 "v Obecné veøejné licenci GNU.\n"
 
-#: src/main.c:478
-msgid "\nOriginally written by Hrvoje Niksic <hniksic@arsdigita.com>.\n"
-msgstr "\nPùvodním autorem tohto programu je Hrvoje Nik¹iæ <hniksic@arsdigita.com>.\n"
+#: src/main.c:638
+#, fuzzy
+msgid ""
+"\n"
+"Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
+msgstr ""
+"\n"
+"Pùvodním autorem tohto programu je Hrvoje Nik¹iæ <hniksic@arsdigita.com>.\n"
 
 # , c-format
-#: src/main.c:569
+#. #### Something nicer should be printed here -- similar to the
+#. pre-1.5 `--help' page.
+#: src/main.c:684 src/main.c:753 src/main.c:832
 #, c-format
-msgid "%s: %s: invalid command\n"
-msgstr "%s: %s: neplatný pøíkaz\n"
+msgid "Try `%s --help' for more options.\n"
+msgstr "Pøíkaz `%s --help' vypí¹e význam platných pøepínaèù.\n"
 
 # , c-format
-#: src/main.c:625
+#: src/main.c:750
 #, c-format
 msgid "%s: illegal option -- `-n%c'\n"
 msgstr "%s: nepøípustný pøepínaè -- `-n%c'\n"
 
-# , c-format
-#. #### Something nicer should be printed here -- similar to the
-#. pre-1.5 `--help' page.
-#: src/main.c:628 src/main.c:670 src/main.c:728
+#: src/main.c:803
 #, c-format
-msgid "Try `%s --help' for more options.\n"
-msgstr "Pøíkaz `%s --help' vypí¹e význam platných pøepínaèù.\n"
-
-#: src/main.c:708
 msgid "Can't be verbose and quiet at the same time.\n"
 msgstr "Program nemù¾e být upovídaný a zitcha najednou.\n"
 
-#: src/main.c:714
+#: src/main.c:809
+#, c-format
 msgid "Can't timestamp and not clobber old files at the same time.\n"
 msgstr "Nelze pou¾ívat èasová razítka a nemazat pøitom staré soubory.\n"
 
+#: src/main.c:817
+#, c-format
+msgid "Cannot specify both --inet4-only and --inet6-only.\n"
+msgstr ""
+
 #. No URL specified.
-#: src/main.c:723
+#: src/main.c:827
 #, c-format
 msgid "%s: missing URL\n"
 msgstr "%s: chybí URL\n"
 
 # , c-format
-#: src/main.c:825
+#: src/main.c:936
 #, c-format
 msgid "No URLs found in %s.\n"
 msgstr "V souboru `%s' nebyla nalezena ¾ádná URL.\n"
 
 # , c-format
-#: src/main.c:834
+#: src/main.c:945
 #, c-format
 msgid ""
 "\n"
