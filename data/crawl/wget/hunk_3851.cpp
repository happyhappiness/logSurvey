 #. that there can be valid reasons for the local host
 #. name not to be an FQDN, so I've decided to remove the
 #. annoying warning.
-#: src/host.c:511
+#: src/host.c:473
 #, c-format
 msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
 msgstr "%s: Aviso: resolu��o do endere�o local n�o resultou em FQDN!\n"
 
-#: src/host.c:539
+#: src/host.c:501
 msgid "Host not found"
 msgstr "Host n�o encontrado"
 
-#: src/host.c:541
+#: src/host.c:503
 msgid "Unknown error"
 msgstr "Erro desconhecido"
 
-# , c-format
-#: src/html.c:439 src/html.c:441
-#, c-format
-msgid "Index of /%s on %s:%d"
-msgstr "�ndice de /%s em %s:%d"
-
-#: src/html.c:463
-msgid "time unknown       "
-msgstr "hor�rio desconhecido "
-
-#: src/html.c:467
-msgid "File        "
-msgstr "Arquivo     "
-
-#: src/html.c:470
-msgid "Directory   "
-msgstr "Diret�rio   "
-
-#: src/html.c:473
-msgid "Link        "
-msgstr "Link        "
-
-#: src/html.c:476
-msgid "Not sure    "
-msgstr "Sem certeza "
+#: src/http.c:621 src/http.c:1433
+msgid "Unable to establish SSL connection.\n"
+msgstr ""
 
 # , c-format
-#: src/html.c:494
-#, c-format
-msgid " (%s bytes)"
-msgstr " (%s bytes)"
+#: src/http.c:629
+#, fuzzy, c-format
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Tentando conectar-se a %s:%hu.\n"
 
-#: src/http.c:492
-msgid "Failed writing HTTP request.\n"
+#: src/http.c:805
+#, fuzzy, c-format
+msgid "Failed writing HTTP request: %s.\n"
 msgstr "Falha na requisi��o HTTP.\n"
 
 # , c-format
-#: src/http.c:497
+#: src/http.c:810
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s requisi��o enviada, aguardando resposta... "
 
-#: src/http.c:536
+#: src/http.c:854
 msgid "End of file while parsing headers.\n"
 msgstr "Fim de arquivo durante a leitura dos headers.\n"
 
 # , c-format
-#: src/http.c:547
+#: src/http.c:865
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Erro de leitura (%s) nos headers.\n"
 
-#: src/http.c:587
+#: src/http.c:905
 msgid "No data received"
 msgstr "Nenhum dado recebido"
 
-#: src/http.c:589
+#: src/http.c:907
 msgid "Malformed status line"
 msgstr "Linha de status inv�lida"
 
-#: src/http.c:594
+#: src/http.c:912
 msgid "(no description)"
 msgstr "(sem descri��o)"
 
-#. If we have tried it already, then there is not point
-#. retrying it.
-#: src/http.c:678
+#: src/http.c:1030
 msgid "Authorization failed.\n"
 msgstr "Autoriza��o falhou.\n"
 
-#: src/http.c:685
+#: src/http.c:1037
 msgid "Unknown authentication scheme.\n"
 msgstr "Esquema de autentica��o desconhecido.\n"
 
 # , c-format
-#: src/http.c:748
+#: src/http.c:1127
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Localiza��o: %s%s\n"
 
-#: src/http.c:749 src/http.c:774
+#: src/http.c:1128 src/http.c:1153
 msgid "unspecified"
 msgstr "nao especificado"
 
-#: src/http.c:750
+#: src/http.c:1129
 msgid " [following]"
 msgstr " [seguinte]"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:764
+#: src/http.c:1143
 msgid "Length: "
 msgstr "Tamanho: "
 
 # , c-format
-#: src/http.c:769
+#: src/http.c:1148
 #, c-format
 msgid " (%s to go)"
 msgstr " (%s para o fim)"
 
-#: src/http.c:774
+#: src/http.c:1153
 msgid "ignored"
 msgstr "ignorado"
 
-#: src/http.c:857
+#: src/http.c:1254
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Aviso: wildcards n�o suportados para HTTP.\n"
 
 # , c-format
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:872
+#: src/http.c:1275
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Arquivo `%s' j� presente, n�o ser� baixado.\n"
 
 # , c-format
-#: src/http.c:978
+#: src/http.c:1425
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "N�o foi poss�vel escrever em `%s' (%s).\n"
 
 # , c-format
-#: src/http.c:988
+#: src/http.c:1443
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "ERRO: Redire��o (%d) sem Location.\n"
 
 # , c-format
-#: src/http.c:1011
+#: src/http.c:1468
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s ERRO %d: %s.\n"
 
-#: src/http.c:1023
+#: src/http.c:1481
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Header Last-modified n�o recebido -- time-stamps desligados.\n"
 
-#: src/http.c:1031
+#: src/http.c:1489
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "Header Last-modified inv�lido -- time-stamp ignorado.\n"
 
-#: src/http.c:1064
+#: src/http.c:1524
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Arquivo remoto � mais novo, buscando.\n"
 
 # , c-format
-#: src/http.c:1098
+#: src/http.c:1559
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
-msgstr "%s (%s) - `%s' recebido [%ld/%ld]\n\n"
+msgid ""
+"%s (%s) - `%s' saved [%ld/%ld]\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' recebido [%ld/%ld]\n"
+"\n"
 
 # , c-format
-#: src/http.c:1130
+#: src/http.c:1607
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld. "
 msgstr "%s (%s) - Conex�o fechada no byte %ld. "
 
 # , c-format
-#: src/http.c:1138
+#: src/http.c:1615
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
-msgstr "%s (%s) - `%s' recebido [%ld/%ld])\n\n"
+msgid ""
+"%s (%s) - `%s' saved [%ld/%ld])\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' recebido [%ld/%ld])\n"
+"\n"
 
 # , c-format
-#: src/http.c:1150
+#: src/http.c:1635
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld/%ld. "
 msgstr "%s (%s) - Conex�o fechada no byte %ld/%ld. "
 
 # , c-format
-#: src/http.c:1161
+#: src/http.c:1646
 #, c-format
 msgid "%s (%s) - Read error at byte %ld (%s)."
 msgstr "%s (%s) - Erro de leitura no byte %ld (%s)."
 
 # , c-format
-#: src/http.c:1169
+#: src/http.c:1654
 #, c-format
 msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
 msgstr "%s (%s) - Erro de leitura no byte %ld/%ld (%s)."
 
 # , c-format
-#: src/init.c:312 src/netrc.c:250
+#: src/init.c:332 src/netrc.c:261
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: N�o foi poss�vel ler %s (%s).\n"
 
 # , c-format
-#: src/init.c:333 src/init.c:339
+#: src/init.c:350 src/init.c:356
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: Erro em %s na linha %d.\n"
 
 # , c-format
-#: src/init.c:370
+#: src/init.c:387
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
-msgstr "%s: Aviso: os arquivos wgetrc do sistema e do usu�rio apontam para `%s'.\n"
+msgstr ""
+"%s: Aviso: os arquivos wgetrc do sistema e do usu�rio apontam para `%s'.\n"
 
 # , c-format
-#: src/init.c:458
+#: src/init.c:479
 #, c-format
 msgid "%s: BUG: unknown command `%s', value `%s'.\n"
 msgstr "%s: BUG: comando desconhecido `%s', valor `%s'.\n"
 
 # , c-format
-#: src/init.c:485
+#: src/init.c:501
+#, fuzzy, c-format
+msgid "%s: Out of memory.\n"
+msgstr "%s: %s: Mem�ria insuficiente.\n"
+
+#: src/init.c:507
+#, fuzzy, c-format
+msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
+msgstr "%s: Aviso: n�o foi poss�vel resolver endere�o IP local.\n"
+
+# , c-format
+#: src/init.c:535
 #, c-format
 msgid "%s: %s: Please specify on or off.\n"
 msgstr "%s: %s: Por favor especifique on ou off.\n"
 
 # , c-format
-#: src/init.c:503 src/init.c:760 src/init.c:782 src/init.c:855
+#: src/init.c:579
+#, fuzzy, c-format
+msgid "%s: %s: Please specify always, on, off, or never.\n"
+msgstr "%s: %s: Por favor especifique on ou off.\n"
+
+# , c-format
+#: src/init.c:598 src/init.c:855 src/init.c:877 src/init.c:941
 #, c-format
 msgid "%s: %s: Invalid specification `%s'.\n"
 msgstr "%s: %s: Especifica��o inv�lida `%s'\n"
 
 # , c-format
-#: src/init.c:616 src/init.c:638 src/init.c:660 src/init.c:686
+#: src/init.c:711 src/init.c:733 src/init.c:755 src/init.c:781
 #, c-format
 msgid "%s: Invalid specification `%s'\n"
 msgstr "%s: Especifica��o inv�lida `%s'\n"
 
 # , c-format
-#: src/main.c:101
+#: src/main.c:119
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
 msgstr "Uso: %s [OP��O]... [URL]...\n"
 
 # , c-format
-#: src/main.c:109
+#: src/main.c:127
 #, c-format
 msgid "GNU Wget %s, a non-interactive network retriever.\n"
-msgstr "GNU Wget %s, um programa n�o interativo para buscar arquivos da rede.\n"
+msgstr ""
+"GNU Wget %s, um programa n�o interativo para buscar arquivos da rede.\n"
 
 #. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
 #. don't bitch.  Also, it makes translation much easier.
-#: src/main.c:114
-msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
+#: src/main.c:132
+msgid ""
+"\n"
+"Mandatory arguments to long options are mandatory for short options too.\n"
+"\n"
 msgstr ""
 "\n"
 "Argumentos obrigat�rios para op��es longas s�o tamb�m\n"
 "obrigat�rios para op��es curtas.\n"
 "\n"
 
-#: src/main.c:117
+#: src/main.c:135
+#, fuzzy
 msgid ""
 "Startup:\n"
 "  -V,  --version           display the version of Wget and exit.\n"
 "  -h,  --help              print this help.\n"
 "  -b,  --background        go to background after startup.\n"
-"  -e,  --execute=COMMAND   execute a `.wgetrc' command.\n"
+"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
 "\n"
 msgstr ""
 "In�cio:\n"
