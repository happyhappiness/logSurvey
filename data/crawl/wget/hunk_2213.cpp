 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Reutilizando conex�o para %s:%hu.\n"
 
-#: src/http.c:1684
+#: src/http.c:1683
 #, fuzzy, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Falha ao enviar requisi��o HTTP: %s.\n"
 
-#: src/http.c:1704
+#: src/http.c:1703
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr ""
 
 # , c-format
-#: src/http.c:1749
+#: src/http.c:1748
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s requisi��o enviada, aguardando resposta... "
 
-#: src/http.c:1760
+#: src/http.c:1759
 #, fuzzy
 msgid "No data received.\n"
 msgstr "Nenhum dado recebido"
 
 # , c-format
-#: src/http.c:1767
+#: src/http.c:1766
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Erro de leitura (%s) nos headers.\n"
 
 # , c-format
-#. If opt.noclobber is turned on and file already exists, do not
-#. retrieve the file
-#: src/http.c:1813
+#: src/http.c:1812
 #, fuzzy, c-format
 msgid ""
 "File `%s' already there; not retrieving.\n"
 "\n"
 msgstr "Arquivo `%s' j� existente, n�o ser� baixado.\n"
 
-#. If the authentication header is missing or
-#. unrecognized, there's no sense in retrying.
-#: src/http.c:1966
+#: src/http.c:1965
 msgid "Unknown authentication scheme.\n"
 msgstr "Esquema de autentica��o desconhecido.\n"
 
-#: src/http.c:1997
+#: src/http.c:1996
 msgid "Authorization failed.\n"
 msgstr "Autoriza��o falhou.\n"
 
-#: src/http.c:2011
+#: src/http.c:2010
 msgid "Malformed status line"
 msgstr "Linha de status inv�lida"
 
-#: src/http.c:2013
+#: src/http.c:2012
 msgid "(no description)"
 msgstr "(sem descri��o)"
 
 # , c-format
-#: src/http.c:2076
+#: src/http.c:2075
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Localiza��o: %s%s\n"
 
-#: src/http.c:2077 src/http.c:2184
+#: src/http.c:2076 src/http.c:2183
 msgid "unspecified"
 msgstr "nao especificado"
 
-#: src/http.c:2078
+#: src/http.c:2077
 msgid " [following]"
 msgstr " [seguinte]"
 
-#. If `-c' is in use and the file has been fully downloaded (or
-#. the remote file has shrunk), Wget effectively requests bytes
-#. after the end of file and the server response with 416.
-#: src/http.c:2134
+#: src/http.c:2133
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
