 "Found %d broken links.\n"
 "\n"
 msgstr[0] ""
+"Nalezen %d slepý odkaz.\n"
+"\n"
 msgstr[1] ""
+"Nalezeny %d slepé odkazy.\n"
+"\n"
+msgstr[2] ""
+"Nalezeno %d slepých odkazů.\n"
+"\n"
 
-#: src/spider.c:154
-#, c-format
-msgid "%s referred by:\n"
-msgstr ""
-
-#: src/spider.c:159
-#, c-format
-msgid "    %s\n"
-msgstr ""
+#: src/spider.c:90
+#, fuzzy, c-format
+msgid "%s\n"
+msgstr "    %s\n"
 
 #: src/url.c:619
-#, fuzzy
 msgid "No error"
-msgstr "Nezn�m� chyba"
+msgstr "Bez chyby"
 
 #: src/url.c:621
 msgid "Unsupported scheme"
-msgstr ""
+msgstr "Nepodporované schéma"
 
 #: src/url.c:623
 msgid "Invalid host name"
-msgstr "Neplatn� jm�no stroje"
+msgstr "Neplatné jméno stroje"
 
 #: src/url.c:625
 msgid "Bad port number"
-msgstr ""
+msgstr "Chybné číslo portu"
 
 #: src/url.c:627
-#, fuzzy
 msgid "Invalid user name"
-msgstr "Neplatn� jm�no stroje"
+msgstr "Neplatné jméno uživatele"
 
 #: src/url.c:629
 msgid "Unterminated IPv6 numeric address"
-msgstr ""
+msgstr "Neukončená číselní IPv6 adresa"
 
 #: src/url.c:631
 msgid "IPv6 addresses not supported"
-msgstr ""
+msgstr "IPv6 adresy nejsou podporovány"
 
 #: src/url.c:633
 msgid "Invalid IPv6 numeric address"
-msgstr ""
+msgstr "Chybná číselná IPv6 adresa"
 
-#. parent, no error
-#: src/utils.c:324
-#, fuzzy, c-format
+#: src/utils.c:327
+#, c-format
 msgid "Continuing in background, pid %d.\n"
-msgstr "Program pokra�uje v b�hu na pozad�.\n"
+msgstr "Program pokračuje v běhu na pozadí. pid %d\n"
 
-# , c-format
-#: src/utils.c:372
+#: src/utils.c:375
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
-msgstr "Nebylo mo�n� odstranit symbolick� odkaz `%s': %s\n"
+msgstr "Nebylo možné odstranit symbolický odkaz „%s“: %s\n"
 
 #: src/xmalloc.c:62
 #, c-format
 msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
-msgstr ""
+msgstr "%s: %s: alokace %ld bajtů selhala, paměť vyčerpána.\n"
+
+#~ msgid "%s referred by:\n"
+#~ msgstr "%s odkázán z:\n"
 
 #~ msgid "Error in Set-Cookie, field `%s'"
-#~ msgstr "Chyba v hlavi�ce Set-Cookie v poli `%s'"
+#~ msgstr "Chyba v hlavičce Set-Cookie v poli „%s“"
+
+#~ msgid ""
+#~ "%s: %s: Invalid extended boolean `%s';\n"
+#~ "use one of `on', `off', `always', or `never'.\n"
+#~ msgstr ""
+#~ "%s: %s: Chybná rozšířená pravdivostní hodnota „%s“;\n"
+#~ "zadejte jeden z: „on“ (zapnuto), „off“ (vypnuto), „always“ (vždy) nebo\n"
+#~ "„never“ (nikdy).\n"
+
+#~ msgid ""
+#~ "This program is distributed in the hope that it will be useful,\n"
+#~ "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
+#~ "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
+#~ "GNU General Public License for more details.\n"
+#~ msgstr ""
+#~ "Tento program je šířen v naději, že bude užitečný, avšak\n"
+#~ "BEZ JAKÉKOLI ZÁRUKY; neposkytují se ani odvozené záruky PRODEJNOSTI \n"
+#~ "anebo VHODNOSTI PRO URČITÝ ÚČEL. Další podrobnosti hledejte \n"
+#~ "v Obecné veřejné licenci GNU (GNU General Public License).\n"
+
+#~ msgid "%s: Certificate verification error for %s: %s\n"
+#~ msgstr "%s: Chyba ověřování certifikátu pro %s: %s\n"
 
 #~ msgid "Syntax error in Set-Cookie at character `%c'.\n"
-#~ msgstr "Syntaktick� chyba v hlavi�ce Set-Cookie na znaku `%c'.\n"
+#~ msgstr "Syntaktická chyba v hlavičce Set-Cookie na znaku „%c“.\n"
 
 # , c-format
 #~ msgid "Connection to %s:%hu refused.\n"
-#~ msgstr "Spojen� s %s:%hu odm�tnuto.\n"
+#~ msgstr "Spojení s %s:%hu odmítnuto.\n"
 
 # , c-format
 #~ msgid "Will try connecting to %s:%hu.\n"
-#~ msgstr "Program se pokus� spojit s %s:%hu.\n"
+#~ msgstr "Program se pokusí spojit s %s:%hu.\n"
 
 #~ msgid ""
 #~ "\n"
 #~ "REST failed; will not truncate `%s'.\n"
 #~ msgstr ""
 #~ "\n"
-#~ "P��kaz REST selhal, `%s' nebude zkr�ceno.\n"
+#~ "Příkaz REST selhal, „%s“ nebude zkráceno.\n"
 
 # , c-format
 #~ msgid " [%s to go]"
-#~ msgstr " [%s zb�v�]"
+#~ msgstr " [%s zbývá]"
 
 #~ msgid "Host not found"
-#~ msgstr "Po��ta� nebyl nalezen"
+#~ msgstr "Počítač nebyl nalezen"
 
 #~ msgid "Failed to set up an SSL context\n"
-#~ msgstr "Nebylo mo�n� nastavit SSL kontext\n"
+#~ msgstr "Nebylo možné nastavit SSL kontext\n"
 
 #~ msgid "Failed to load certificates from %s\n"
-#~ msgstr "SSL certifik�ty nebylo mo�n� ze souboru `%s' na��st.\n"
+#~ msgstr "SSL certifikáty nebylo možné ze souboru „%s“ načíst.\n"
 
 #~ msgid "Trying without the specified certificate\n"
-#~ msgstr "Program se pokus� pokra�ovat bez zadan�ho certifik�tu.\n"
+#~ msgstr "Program se pokusí pokračovat bez zadaného certifikátu.\n"
 
 #~ msgid "Failed to get certificate key from %s\n"
 #~ msgstr ""
-#~ "Ze souboru `%s' nebylo mo�n� kl�� k certifik�tu na��st.\n"
+#~ "Ze souboru „%s“ nebylo možné klíč k certifikátu načíst.\n"
 #~ "\n"
 
 #~ msgid "End of file while parsing headers.\n"
-#~ msgstr "Hlavi�ka nen� �pln�.\n"
+#~ msgstr "Hlavička není úplná.\n"
 
 #~ msgid ""
 #~ "\n"
