 msgid " (%s bytes)"
 msgstr " (%s bajtù)"
 
-#: src/http.c:507
+#: src/http.c:508
 msgid "Failed writing HTTP request.\n"
 msgstr "HTTP po¾adavek nebylo mo¾né odeslat.\n"
 
 # , c-format
-#: src/http.c:511
+#: src/http.c:512
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s po¾adavek odeslán, èekám na odpovìï ... "
 
-#: src/http.c:550
+#: src/http.c:551
 msgid "End of file while parsing headers.\n"
 msgstr "Hlavièka není úplná.\n"
 
 # , c-format
-#: src/http.c:561
+#: src/http.c:562
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Chyba (%s) pøi ètení hlavièek.\n"
 
-#: src/http.c:601
+#: src/http.c:602
 msgid "No data received"
 msgstr "Nepøi¹la ¾ádná data"
 
-#: src/http.c:603
+#: src/http.c:604
 msgid "Malformed status line"
 msgstr "Odpovìï serveru má zkomolený stavový øádek"
 
-#: src/http.c:608
+#: src/http.c:609
 msgid "(no description)"
 msgstr "(¾ádný popis)"
 
 #. If we have tried it already, then there is not point
 #. retrying it.
-#: src/http.c:692
+#: src/http.c:693
 msgid "Authorization failed.\n"
 msgstr "Autorizace selhala.\n"
 
-#: src/http.c:699
+#: src/http.c:700
 msgid "Unknown authentication scheme.\n"
 msgstr "Server po¾aduje neznámý zpùsob autentifikace.\n"
 
 # , c-format
-#: src/http.c:762
+#: src/http.c:783
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Pøesmìrováno na: %s%s\n"
 
-#: src/http.c:763 src/http.c:788
+#: src/http.c:784 src/http.c:809
 msgid "unspecified"
 msgstr "neudáno"
 
-#: src/http.c:764
+#: src/http.c:785
 msgid " [following]"
 msgstr " [následuji]"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:778
+#: src/http.c:799
 msgid "Length: "
 msgstr "Délka: "
 
 # , c-format
-#: src/http.c:783
+#: src/http.c:804
 #, c-format
 msgid " (%s to go)"
 msgstr " (%s zbývá)"
 
-#: src/http.c:788
+#: src/http.c:809
 msgid "ignored"
 msgstr "je ignorována"
 
-#: src/http.c:880
+#: src/http.c:903
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Varování: HTTP nepodporuje ¾olíkové znaky.\n"
 
 # , c-format
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:895
+#: src/http.c:924
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Soubor `%s' nebudu pøená¹et, je ji¾ zde.\n"
 
 # , c-format
-#: src/http.c:1048
+#: src/http.c:1083
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Nemohu zapsat do `%s' (%s).\n"
 
 # , c-format
-#: src/http.c:1058
+#: src/http.c:1094
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "CHYBA: Pøesmìrování (%d) bez udané nové adresy.\n"
 
 # , c-format
-#: src/http.c:1081
+#: src/http.c:1119
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s CHYBA %d: %s.\n"
 
-#: src/http.c:1093
+#: src/http.c:1132
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr ""
 "Nebudu pou¾ívat èasová razítka (`time-stamps'), proto¾e hlavièka\n"
 "\"Last-modified\" v odpovìdi serveru schází.\n"
 
-#: src/http.c:1101
+#: src/http.c:1140
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr ""
 "Ignoruji èasové razítko souboru (`time-stamp'), proto¾e hlavièka \n"
 "\"Last-modified\" obsahuje neplatné údaje.\n"
 
-#. We can't collapse this down into just one logprintf()
-#. call with a variable set to u->local or the .orig
-#. filename because we have to malloc() space for the
-#. latter, and because there are multiple returns above (a
-#. coding style no-no by many measures, for reasons such as
-#. this) we'd have to remember to free() the string at each
-#. one to avoid a memory leak.
-#: src/http.c:1132
-#, c-format
-msgid ""
-"Server file no newer than local file `%s.orig' -- not retrieving.\n"
-"\n"
-msgstr ""
-
-#: src/http.c:1146
+#: src/http.c:1175
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Vzdálený soubor je novìj¹ího data, pøená¹ím.\n"
 
 # , c-format
-#: src/http.c:1180
+#: src/http.c:1210
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld]\n"
