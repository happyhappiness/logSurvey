 "T� nasc ceart siombalach ann cheana %s -> %s\n"
 "\n"
 
-#: src/ftp.c:1533
+#: src/ftp.c:1788
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Nasc siombalach %s -> %s � chruth�\n"
 
-#: src/ftp.c:1543
+#: src/ftp.c:1798
 #, fuzzy, c-format
 msgid "Symlinks not supported, skipping symlink %s.\n"
 msgstr "N�l aon taca�ocht ar naisc shiombalacha, ag scipe�il `%s'.\n"
 
-#: src/ftp.c:1555
+#: src/ftp.c:1810
 #, fuzzy, c-format
 msgid "Skipping directory %s.\n"
 msgstr "Ag f�g�il na comhadlainne `%s' ar l�r.\n"
 
-#: src/ftp.c:1564
+#: src/ftp.c:1819
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: comhad de chine�l anaithnid/gan tac�.\n"
 
-#: src/ftp.c:1591
+#: src/ftp.c:1856
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: stampa truaillithe ama.\n"
 
-#: src/ftp.c:1619
+#: src/ftp.c:1878
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr ""
 "N� aisghabhfar comhadlanna �s rud � go bhfuil an doimhneacht %d faoi l�thair "
 "(uasmh�id %d).\n"
 
-#: src/ftp.c:1669
+#: src/ftp.c:1928
 #, fuzzy, c-format
 msgid "Not descending to %s as it is excluded/not-included.\n"
 msgstr ""
 "n� ag dul isteach i `%s' �s rud � go bhfuil s� f�gtha-as/nach-curtha-san-"
 "�ireamh.\n"
 
-#: src/ftp.c:1735 src/ftp.c:1749
+#: src/ftp.c:1994 src/ftp.c:2008
 #, fuzzy, c-format
 msgid "Rejecting %s.\n"
 msgstr "`%s' � dhi�lt�.\n"
 
-#: src/ftp.c:1772
+#: src/ftp.c:2031
 #, c-format
 msgid "Error matching %s against %s: %s\n"
 msgstr "Earr�id agus %s � chur i gcomhoiri�nacht do %s: %s\n"
 
-#: src/ftp.c:1814
+#: src/ftp.c:2073
 #, fuzzy, c-format
 msgid "No matches on pattern %s.\n"
 msgstr "N�l aon rud comhoiri�nach leis an phatr�n `%s'.\n"
 
-#: src/ftp.c:1880
+#: src/ftp.c:2144
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s [%s].\n"
 msgstr "Scr�obhadh inn�acs i gcruth HTML i `%s' [%s].\n"
 
-#: src/ftp.c:1885
+#: src/ftp.c:2149
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s.\n"
 msgstr "Scr�obhadh inn�acs i gcruth HTML i `%s'.\n"
 
-#: src/host.c:348
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "ERROR"
+msgstr "EARR�ID"
+
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "WARNING"
+msgstr "RABHADH"
+
+#: src/gnutls.c:225 src/openssl.c:504
+#, c-format
+msgid "%s: No certificate presented by %s.\n"
+msgstr "%s: N�or thaispe�in %s teastas ar bith.\n"
+
+#: src/gnutls.c:233
+#, fuzzy, c-format
+msgid "%s: The certificate of %s is not trusted.\n"
+msgstr "%s: N�or thaispe�in %s teastas ar bith.\n"
+
+#: src/gnutls.c:239
+#, c-format
+msgid "%s: The certificate of %s hasn't got a known issuer.\n"
+msgstr ""
+
+#: src/gnutls.c:245
+#, fuzzy, c-format
+msgid "%s: The certificate of %s has been revoked.\n"
+msgstr "  T� an teastas imithe as feidhm.\n"
+
+#: src/gnutls.c:259
+#, c-format
+msgid "Error initializing X509 certificate: %s\n"
+msgstr ""
+
+#: src/gnutls.c:268
+#, fuzzy
+msgid "No certificate found\n"
+msgstr "%s: N�or thaispe�in %s teastas ar bith.\n"
+
+#: src/gnutls.c:275
+#, fuzzy, c-format
+msgid "Error parsing certificate: %s\n"
+msgstr "Earr�id agus URL an seachfhreastala� %s � phars�il: %s.\n"
+
+#: src/gnutls.c:282
+#, fuzzy
+msgid "The certificate has not yet been activated\n"
+msgstr "  N�l an teastas eisithe bail� f�s.\n"
+
+#: src/gnutls.c:287
+#, fuzzy
+msgid "The certificate has expired\n"
+msgstr "  T� an teastas imithe as feidhm.\n"
+
+#: src/gnutls.c:293
+#, fuzzy, c-format
+msgid "The certificate's owner does not match hostname '%s'\n"
+msgstr ""
+"%s: n�l ainm coitianta an teastais `%s' comhoiri�nach leis an �stainm "
+"iarrtha `%s'.\n"
+
+#: src/host.c:358
 msgid "Unknown host"
 msgstr "�str�omhaire anaithnid"
 
-#: src/host.c:352
+#: src/host.c:362
 msgid "Temporary failure in name resolution"
 msgstr "Teip shealadach ar r�iteach na n-ainmneacha"
 
-#: src/host.c:354
+#: src/host.c:364
 msgid "Unknown error"
 msgstr "Earr�id anaithnid"
 
-#: src/host.c:715
+#: src/host.c:737
 #, c-format
 msgid "Resolving %s... "
 msgstr "%s � r�iteach... "
 
-#: src/host.c:763
+#: src/host.c:789
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr "teipthe: Gan seoladh IPv4/IPv6 don �str�omhaire.\n"
 
-#: src/host.c:786
+#: src/host.c:812
 msgid "failed: timed out.\n"
 msgstr "teipthe: thar am.\n"
 
-#: src/html-url.c:289
+#: src/html-url.c:286
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: N� f�idir nasc %s neamhioml�n a r�iteach.\n"
 
-#: src/html-url.c:696
+#: src/html-url.c:762
 #, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: URL neamhbhail� %s: %s\n"
 
-#: src/http.c:368
+#: src/http.c:377
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Theip ar scr�obh iarratais HTTP: %s.\n"
 
-#: src/http.c:745
+#: src/http.c:754
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Gan cheannt�sca, glac le HTTP/0.9"
 
-#: src/http.c:1430
+#: src/http.c:1456
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "SSL � dh�chumas� de bharr earr�id�.\n"
 
-#: src/http.c:1548
+#: src/http.c:1576
 #, fuzzy, c-format
 msgid "POST data file %s missing: %s\n"
 msgstr "Comhad sonra� POST `%s' ar iarraidh: %s\n"
 
-#: src/http.c:1632
+#: src/http.c:1660
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Ag baint ath�s�id as an gceangal le %s:%d.\n"
 
-#: src/http.c:1701
+#: src/http.c:1729
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Theip ar l�amh freagra �n seachfhreastala�: %s\n"
 
-#: src/http.c:1721
+#: src/http.c:1750
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Theip ar tholl�n� seachfhreastala�: %s"
 
-#: src/http.c:1766
+#: src/http.c:1795
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "Iarratas %s seolta, ag fanacht le freagra... "
 
-#: src/http.c:1777
+#: src/http.c:1806
 msgid "No data received.\n"
 msgstr "N�or glacadh aon sonra.\n"
 
-#: src/http.c:1784
+#: src/http.c:1813
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Earr�id (%s) ag l�amh na gceannt�sc.\n"
 
-#: src/http.c:1831 src/http.c:2385
+#: src/http.c:1884
+msgid "Unknown authentication scheme.\n"
+msgstr "Sc�im anaithnid fh�ordheimhnithe.\n"
+
+#: src/http.c:1918
+msgid "Authorization failed.\n"
+msgstr "Theip ar �dar�.\n"
+
+#: src/http.c:1956 src/http.c:2466
 #, fuzzy, c-format
 msgid ""
 "File %s already there; not retrieving.\n"
