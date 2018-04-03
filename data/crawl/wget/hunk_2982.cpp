 msgid "%s: option `-W %s' doesn't allow an argument\n"
 msgstr "%s: opção `-W %s' não permite argumentos\n"
 
-#: src/host.c:636
+#: src/host.c:368
+#, fuzzy
+msgid "Unknown host"
+msgstr "Erro desconhecido"
+
+#. Message modeled after what gai_strerror returns in similar
+#. circumstances.
+#: src/host.c:372
+msgid "Temporary failure in name resolution"
+msgstr ""
+
+#: src/host.c:374
+msgid "Unknown error"
+msgstr "Erro desconhecido"
+
+#: src/host.c:748
 #, c-format
 msgid "Resolving %s... "
 msgstr "Resolvendo %s... "
 
-#: src/host.c:656 src/host.c:672
+#: src/host.c:792 src/host.c:839
 #, c-format
 msgid "failed: %s.\n"
 msgstr "falha: %s.\n"
 
-#: src/host.c:674
+#: src/host.c:801
+msgid "failed: No IPv4/IPv6 addresses for host.\n"
+msgstr ""
+
+#: src/host.c:842
 msgid "failed: timed out.\n"
 msgstr "falha: tempo excedido.\n"
 
-#: src/host.c:762
-msgid "Host not found"
-msgstr "Host não encontrado"
-
-#: src/host.c:764
-msgid "Unknown error"
-msgstr "Erro desconhecido"
-
-#: src/html-url.c:293
+#: src/html-url.c:297
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Não foi possível resolver link incompleto %s.\n"
 
+#: src/http.c:349 src/http.c:1504
+#, c-format
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Falha ao enviar requisição HTTP: %s.\n"
+
+#: src/http.c:663
+msgid "No headers, assuming HTTP/0.9"
+msgstr ""
+
 #. this is fatal
-#: src/http.c:674
+#: src/http.c:1151
 msgid "Failed to set up an SSL context\n"
 msgstr "Falha ao definir um contexto SSL\n"
 
-#: src/http.c:680
+#: src/http.c:1156
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "Falha ao carregar certificados do %s\n"
 
-#: src/http.c:684 src/http.c:692
+#: src/http.c:1159 src/http.c:1166
 msgid "Trying without the specified certificate\n"
 msgstr "Tentando sem o certificado especificado\n"
 
-#: src/http.c:688
+#: src/http.c:1163
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "Falha ao obter a chave do certificado de %s\n"
 
-#: src/http.c:761 src/http.c:1809
-msgid "Unable to establish SSL connection.\n"
-msgstr "Não foi possível estabelecer conexão segura (SSL).\n"
-
-#: src/http.c:770
-#, c-format
-msgid "Reusing connection to %s:%hu.\n"
+#: src/http.c:1382
+#, fuzzy, c-format
+msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Reutilizando conexão para %s:%hu.\n"
 
-#: src/http.c:1034
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
+#: src/http.c:1434
+#, fuzzy, c-format
+msgid "Failed writing to proxy: %s.\n"
+msgstr "Falha ao enviar requisição HTTP: %s.\n"
+
+#: src/http.c:1443
+#, fuzzy, c-format
+msgid "Failed reading proxy response: %s\n"
 msgstr "Falha ao enviar requisição HTTP: %s.\n"
 
+#: src/http.c:1463
+#, c-format
+msgid "Proxy tunneling failed: %s"
+msgstr ""
+
 # , c-format
-#: src/http.c:1039
+#: src/http.c:1510
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s requisição enviada, aguardando resposta... "
 
-#: src/http.c:1083
-msgid "End of file while parsing headers.\n"
-msgstr "Fim de arquivo durante a leitura dos headers.\n"
+#: src/http.c:1521
+#, fuzzy
+msgid "No data received.\n"
+msgstr "Nenhum dado recebido"
 
 # , c-format
-#: src/http.c:1093
+#: src/http.c:1528
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Erro de leitura (%s) nos headers.\n"
 
-#: src/http.c:1128
-msgid "No data received"
-msgstr "Nenhum dado recebido"
+#. If we have tried it already, then there is not point
+#. retrying it.
+#: src/http.c:1595
+msgid "Authorization failed.\n"
+msgstr "Autorização falhou.\n"
 
-#: src/http.c:1130
+#: src/http.c:1609
+msgid "Unknown authentication scheme.\n"
+msgstr "Esquema de autenticação desconhecido.\n"
+
+#: src/http.c:1634
 msgid "Malformed status line"
 msgstr "Linha de status inválida"
 
-#: src/http.c:1135
+#: src/http.c:1636
 msgid "(no description)"
 msgstr "(sem descrição)"
 
-#: src/http.c:1267
-msgid "Authorization failed.\n"
-msgstr "Autorização falhou.\n"
-
-#: src/http.c:1274
-msgid "Unknown authentication scheme.\n"
-msgstr "Esquema de autenticação desconhecido.\n"
-
 # , c-format
-#: src/http.c:1314
+#: src/http.c:1700
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Localização: %s%s\n"
 
-#: src/http.c:1315 src/http.c:1454
+#: src/http.c:1701 src/http.c:1801
 msgid "unspecified"
 msgstr "nao especificado"
 
-#: src/http.c:1316
+#: src/http.c:1702
 msgid " [following]"
 msgstr " [seguinte]"
 
-#: src/http.c:1383
+#. If `-c' is in use and the file has been fully downloaded (or
+#. the remote file has shrunk), Wget effectively requests bytes
+#. after the end of file and the server response with 416.
+#: src/http.c:1751
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
