 "Downloaded: %s bytes in %d files\n"
 msgstr ""
 "\n"
-"KONEC --%s--\n"
-"Celkem na��tan�ch %s bytov v %d s�boroch\n"
+"UKON�EN� --%s--\n"
+"Stiahnutych %s bajtov v %d s�boroch\n"
 
 # , c-format
-#: src/main.c:842
+#: src/main.c:851
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
-msgstr "Prekro�en� limit objemu ulo�en�ch d�t (%s bytov)!\n"
+msgstr "PREKRO�EN� limit objemu stiahnutych d�t (%s bajtov)!\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:876
-#, c-format
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "Zachyten� sign�l %s , v�stup presmerovan� do `%%s'.\n"
-
-# , c-format
-#: src/mswindows.c:89
-#, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"Stla�en� CTRL+Break, v�stup bol presmerovan� do `%s'\n"
-"Program pokra�uje v behu na pozad�.\n"
-"Wget je mo�n� zastavi� stla�en�m CTRL+ALT+DELETE.\n"
-
-#. parent, no error
-#: src/mswindows.c:106 src/utils.c:458
+#: src/mswindows.c:120
 msgid "Continuing in background.\n"
 msgstr "Pokra�ujem v behu na pozad�.\n"
 
 # , c-format
-#: src/mswindows.c:108 src/utils.c:460
+#: src/mswindows.c:122 src/utils.c:457
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "V�stup bude zap�san� do `%s'.\n"
 
 # , c-format
-#: src/mswindows.c:188
+#: src/mswindows.c:202
 #, c-format
 msgid "Starting WinHelp %s\n"
 msgstr "Sp���am WinHelp %s\n"
 
-#: src/mswindows.c:215 src/mswindows.c:222
+#: src/mswindows.c:229 src/mswindows.c:236
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Nem��em n�js� pou�ite�n� ovl�da� soketov.\n"
 
 # , c-format
-#: src/netrc.c:367
+#: src/netrc.c:365
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
-msgstr ""
-"%s: %s:%d varovanie: token \"%s\" je uveden� e�te pred ak�mko�vek\n"
-"      n�zvom po��ta�a\n"
+msgstr "%s: %s:%d varovanie: token \"%s\" je uveden� pred ak�mko�vek n�zvom po��ta�a\n"
 
 # , c-format
-#: src/netrc.c:398
+#: src/netrc.c:396
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: nezn�my token \"%s\"\n"
 
 # , c-format
-#: src/netrc.c:462
+#: src/netrc.c:460
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
-msgstr "Pou�itie: %s NETRC [N�ZOV PO��TA�A]\n"
+msgstr "Pou�itie: %s NETRC [N�ZOV_PO��TA�A]\n"
 
 # , c-format
-#: src/netrc.c:472
+#: src/netrc.c:470
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: volanie `stat %s' skon�ilo s chybou: %s\n"
 
 # , c-format
-#: src/recur.c:484
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:224
 #, c-format
-msgid "Removing %s since it should be rejected.\n"
-msgstr "Ma�e sa %s, preto�e tento s�bor nie je po�adovan�.\n"
+msgid "\n%*s[ skipping %dK ]"
+msgstr "\n%*s[ preskakujem %dK ]"
 
-#: src/recur.c:679
-msgid "Loading robots.txt; please ignore errors.\n"
-msgstr "Na��tavam `robots.txt'. Chybov� hl�senia ignorujte, pros�m.\n"
+# , c-format
+#: src/progress.c:391
+#, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "Neplatn� bodkov� �pecifik�cia `%s'; ponech�vam nezmenen�.\n"
 
 # , c-format
-#: src/retr.c:227
+#: src/recur.c:350
 #, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ preskakujem %dK ]"
+msgid "Removing %s since it should be rejected.\n"
+msgstr "Odstra�ujem %s, preto�e by mal by� odmietnut�.\n"
+
+#: src/recur.c:935
+#, c-format
+msgid "Converted %d files in %.2f seconds.\n"
+msgstr "Skonvertovan�ch %d s�borov za %.2f sek�nd.\n"
+
+#: src/res.c:540
+msgid "Loading robots.txt; please ignore errors.\n"
+msgstr "Na��tavam robots.txt. Chybov� hl�senia ignorujte, pros�m.\n"
 
-#: src/retr.c:373
+#: src/retr.c:363
 msgid "Could not find proxy host.\n"
 msgstr "Nem��em n�js� proxy server.\n"
 
 # , c-format
-#: src/retr.c:387
+#: src/retr.c:375
 #, c-format
-msgid "Proxy %s: Must be HTTP.\n"
-msgstr "Proxy %s: Mus� by� HTTP.\n"
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "Chyba pri anal�ze proxy URL %s: %s\n"
 
 # , c-format
-#: src/retr.c:481
+#: src/retr.c:384
+#, c-format
+msgid "Error in proxy URL %s: Must be HTTP.\n"
+msgstr "Chyba v proxy URL %s: Mus� by� HTTP.\n"
+
+# , c-format
+#: src/retr.c:476
+#, c-format
+msgid "%d redirections exceeded.\n"
+msgstr "Prekro�en� limit %d presmerovan�.\n"
+
+# , c-format
+#: src/retr.c:491
 #, c-format
 msgid "%s: Redirection cycle detected.\n"
 msgstr "%s: V presmerovaniach bol zisten� cyklus.\n"
 
-#: src/retr.c:587
+#: src/retr.c:608
 msgid "Giving up.\n\n"
 msgstr "Vzd�vam to.\n\n"
 
-#: src/retr.c:587
+#: src/retr.c:608
 msgid "Retrying.\n\n"
-msgstr "Sk��am to znovu.\n\n"
+msgstr "Sk��am znova.\n\n"
 
 # , c-format
-#: src/url.c:1329
+#: src/url.c:1875
 #, c-format
 msgid "Converting %s... "
 msgstr "Konvertujem %s... "
 
-#: src/url.c:1342
+#: src/url.c:1888
 msgid "nothing to do.\n"
 msgstr "niet �o robi�.\n"
 
 # , c-format
-#: src/url.c:1350 src/url.c:1374
+#: src/url.c:1896 src/url.c:1920
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
-msgstr "Nedok�em previes� odkazy v %s: %s\n"
+msgstr "Nem��em previes� odkazy v %s: %s\n"
 
 # , c-format
-#: src/url.c:1365
+#: src/url.c:1911
 #, c-format
 msgid "Unable to delete `%s': %s\n"
-msgstr "Nebolo mo�n� zmaza� `%s': %s\n"
+msgstr "Nem��em zmaza� `%s': %s\n"
 
 # , c-format
-#: src/url.c:1555
+#: src/url.c:2117
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
-msgstr "Nedok�em uchova� z�lo�n� k�piu %s ako %s: %s\n"
+msgstr "Nem��em z�lohova� %s ako %s: %s\n"
 
 # , c-format
-#: src/utils.c:94
+#: src/utils.c:90
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: Nie je dos� pam�te.\n"
 
-#: src/utils.c:417
-msgid "Unknown/unsupported protocol"
-msgstr "Nezn�my/nepodporovan� protokol"
-
-#: src/utils.c:420
-msgid "Invalid port specification"
-msgstr "Neplatn� �pecifik�cia portu"
-
-#: src/utils.c:423
-msgid "Invalid host name"
-msgstr "Neplatn� meno stroja"
+#. parent, no error
+#: src/utils.c:455
+#, c-format
+msgid "Continuing in background, pid %d.\n"
+msgstr "Pokra�ujem v behu na pozad�, pid %d.\n"
 
 # , c-format
-#: src/utils.c:620
+#: src/utils.c:499
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
-msgstr "Nebylo mo�n� odstr�ni� symbolick� odkaz `%s': %s\n"
+msgstr "Nebolo mo�n� odstr�ni� symbolick� odkaz `%s': %s\n"
