 msgid "memory exhausted"
 msgstr ""
 
-#: src/connect.c:198
-#, c-format
+#: src/connect.c:207
+#, fuzzy, c-format
 msgid "%s: unable to resolve bind address %s; disabling bind.\n"
 msgstr ""
+"%s: não foi possível resolver endereço de associação \"%s\"; desabilitando a "
+"associação.\n"
 
-#: src/connect.c:270
-#, fuzzy, c-format
+#: src/connect.c:291
+#, c-format
 msgid "Connecting to %s|%s|:%d... "
-msgstr "Conectando-se � %s[%s]:%hu... "
+msgstr "Conectando-se a %s|%s|:%d... "
 
-#: src/connect.c:273
-#, fuzzy, c-format
+#: src/connect.c:298
+#, c-format
 msgid "Connecting to %s:%d... "
-msgstr "Conectando-se a %s:%hu... "
+msgstr "Conectando-se a %s:%d... "
 
-#: src/connect.c:333
+#: src/connect.c:358
 msgid "connected.\n"
-msgstr "conectado!\n"
+msgstr "conectado.\n"
 
-#: src/connect.c:345 src/host.c:754 src/host.c:783
+#: src/connect.c:370 src/host.c:780 src/host.c:809
 #, c-format
 msgid "failed: %s.\n"
-msgstr "falha: %s.\n"
+msgstr "falhou: %s.\n"
 
-#: src/connect.c:369 src/http.c:1646
-#, c-format
+#: src/connect.c:394 src/http.c:1674
+#, fuzzy, c-format
 msgid "%s: unable to resolve host address %s\n"
-msgstr ""
+msgstr "%s: não foi possível resolver endereço de máquina \"%s\"\n"
 
-#: src/convert.c:170
-#, fuzzy, c-format
+#: src/convert.c:185
+#, c-format
 msgid "Converted %d files in %s seconds.\n"
-msgstr "convertendo %d arquivos em %.2f segundos.\n"
+msgstr "%d arquivos convertidos em %s segundos.\n"
 
-#: src/convert.c:197
+#: src/convert.c:213
 #, c-format
 msgid "Converting %s... "
 msgstr "Convertendo %s... "
 
-#: src/convert.c:210
+#: src/convert.c:226
 msgid "nothing to do.\n"
 msgstr "nada a ser feito.\n"
 
 # , c-format
-#: src/convert.c:218 src/convert.c:242
+#: src/convert.c:234 src/convert.c:258
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
-msgstr "N�o foi poss�vel converter links em %s: %s\n"
+msgstr "Não foi possível converter links em %s: %s\n"
 
 # , c-format
-#: src/convert.c:233
+#: src/convert.c:249
 #, fuzzy, c-format
 msgid "Unable to delete %s: %s\n"
-msgstr "N�o foi poss�vel apagar `%s': %s\n"
+msgstr "Não foi possível excluir \"%s\": %s\n"
 
 # , c-format
-#: src/convert.c:442
+#: src/convert.c:464
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
-msgstr "N�o foi poss�vel copiar %s como %s: %s\n"
+msgstr "Não foi possível fazer uma cópia de segurança de %s como %s: %s\n"
 
 #: src/cookies.c:443
 #, c-format
 msgid "Syntax error in Set-Cookie: %s at position %d.\n"
-msgstr "Erro de sintax em Set-Cookie: %s na posi��o %d.\n"
+msgstr "Erro de sintaxe em Set-Cookie: %s na posição %d.\n"
 
 #: src/cookies.c:686
 #, c-format
 msgid "Cookie coming from %s attempted to set domain to %s\n"
-msgstr ""
+msgstr "Cookie vindo de %s tentou designar domínio como %s\n"
 
 #: src/cookies.c:1134 src/cookies.c:1252
 #, fuzzy, c-format
 msgid "Cannot open cookies file %s: %s\n"
-msgstr "N�o foi poss�vel abrir arquivo de cookies %s: %s\n"
+msgstr "Não foi possível abrir o arquivo de cookies \"%s\": %s\n"
 
 # , c-format
 #: src/cookies.c:1289
 #, fuzzy, c-format
 msgid "Error writing to %s: %s\n"
-msgstr "Erro ao gravar em `%s' %s.\n"
+msgstr "Erro ao gravar em \"%s\": %s.\n"
 
 #: src/cookies.c:1292
 #, fuzzy, c-format
 msgid "Error closing %s: %s\n"
-msgstr "Erro ao fechar `%s': %s\n"
+msgstr "Erro ao fechar \"%s\": %s\n"
 
-#: src/ftp-ls.c:836
+#: src/ftp-ls.c:1065
 msgid "Unsupported listing type, trying Unix listing parser.\n"
-msgstr "Tipo de listagem n�o suportado. Tentando listagem UNIX.\n"
+msgstr ""
+"Sem suporte ao tipo de listagem. Tentando usar interpretador de listagem "
+"UNIX.\n"
 
 # , c-format
-#: src/ftp-ls.c:882 src/ftp-ls.c:884
+#: src/ftp-ls.c:1116 src/ftp-ls.c:1118
 #, c-format
 msgid "Index of /%s on %s:%d"
-msgstr "�ndice de /%s em %s:%d"
+msgstr "Índice de /%s em %s:%d"
 
-#: src/ftp-ls.c:907
+#: src/ftp-ls.c:1143
 #, c-format
 msgid "time unknown       "
-msgstr "hor�rio desconhecido "
+msgstr "horário desconhecido "
 
-#: src/ftp-ls.c:911
+#: src/ftp-ls.c:1147
 #, c-format
 msgid "File        "
 msgstr "Arquivo     "
 
-#: src/ftp-ls.c:914
+#: src/ftp-ls.c:1150
 #, c-format
 msgid "Directory   "
-msgstr "Diret�rio   "
+msgstr "Diretório   "
 
-#: src/ftp-ls.c:917
+#: src/ftp-ls.c:1153
 #, c-format
 msgid "Link        "
 msgstr "Link        "
 
-#: src/ftp-ls.c:920
+#: src/ftp-ls.c:1156
 #, c-format
 msgid "Not sure    "
-msgstr "Sem certeza "
+msgstr "Incerto     "
 
 # , c-format
-#: src/ftp-ls.c:938
+#: src/ftp-ls.c:1179
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s bytes)"
 
 # , c-format
-#: src/ftp.c:214
+#: src/ftp.c:220
 #, c-format
 msgid "Length: %s"
 msgstr "Tamanho: %s"
 
-#: src/ftp.c:220 src/http.c:2199
+#: src/ftp.c:226 src/http.c:2248
 #, c-format
 msgid ", %s (%s) remaining"
-msgstr ""
+msgstr ", %s (%s) restantes"
 
-#: src/ftp.c:224 src/http.c:2203
+#: src/ftp.c:230 src/http.c:2252
 #, c-format
 msgid ", %s remaining"
-msgstr ""
+msgstr ", %s restantes"
 
-#: src/ftp.c:227
+#: src/ftp.c:233
 msgid " (unauthoritative)\n"
 msgstr " (sem autoridade)\n"
 
 # , c-format
-#: src/ftp.c:305
+#: src/ftp.c:311
 #, c-format
 msgid "Logging in as %s ... "
-msgstr "Logando como %s ... "
+msgstr "Acessando como %s ... "
 
-#: src/ftp.c:319 src/ftp.c:365 src/ftp.c:394 src/ftp.c:446 src/ftp.c:559
-#: src/ftp.c:606 src/ftp.c:635 src/ftp.c:692 src/ftp.c:753 src/ftp.c:839
-#: src/ftp.c:886
+#: src/ftp.c:325 src/ftp.c:371 src/ftp.c:400 src/ftp.c:465 src/ftp.c:695
+#: src/ftp.c:748 src/ftp.c:777 src/ftp.c:834 src/ftp.c:895 src/ftp.c:987
+#: src/ftp.c:1034
 msgid "Error in server response, closing control connection.\n"
-msgstr "Erro na resposta do servidor, fechando a conex�o de controle.\n"
+msgstr "Erro na resposta do servidor, fechando a conexão de controle.\n"
 
-#: src/ftp.c:326
+#: src/ftp.c:332
 msgid "Error in server greeting.\n"
-msgstr "Erro na sauda��o do servidor.\n"
+msgstr "Erro na saudação do servidor.\n"
 
-#: src/ftp.c:333 src/ftp.c:454 src/ftp.c:567 src/ftp.c:643 src/ftp.c:702
-#: src/ftp.c:763 src/ftp.c:849 src/ftp.c:896
+#: src/ftp.c:339 src/ftp.c:473 src/ftp.c:703 src/ftp.c:785 src/ftp.c:844
+#: src/ftp.c:905 src/ftp.c:997 src/ftp.c:1044
 msgid "Write failed, closing control connection.\n"
-msgstr "Falha de escrita, fechando a conex�o de controle.\n"
+msgstr "Falha de escrita, fechando a conexão de controle.\n"
 
-#: src/ftp.c:339
+#: src/ftp.c:345
 msgid "The server refuses login.\n"
-msgstr "O servidor recusou o login.\n"
+msgstr "O servidor recusou o acesso.\n"
 
-#: src/ftp.c:345
+#: src/ftp.c:351
 msgid "Login incorrect.\n"
-msgstr "Login incorreto.\n"
+msgstr "Identificação incorreta.\n"
 
-#: src/ftp.c:351
+#: src/ftp.c:357
 msgid "Logged in!\n"
-msgstr "Logado!\n"
+msgstr "Acesso autorizado!\n"
 
-#: src/ftp.c:373
+#: src/ftp.c:379
 msgid "Server error, can't determine system type.\n"
-msgstr "Erro do servidor, imposs�vel determinar tipo de sistema.\n"
+msgstr "Erro do servidor, não foi possível determinar tipo de sistema.\n"
 
-#: src/ftp.c:382 src/ftp.c:679 src/ftp.c:736 src/ftp.c:779
+#: src/ftp.c:388 src/ftp.c:821 src/ftp.c:878 src/ftp.c:921
 msgid "done.    "
 msgstr "feito.   "
 
-#: src/ftp.c:434 src/ftp.c:584 src/ftp.c:618 src/ftp.c:869 src/ftp.c:915
+#: src/ftp.c:453 src/ftp.c:720 src/ftp.c:760 src/ftp.c:1017 src/ftp.c:1063
 msgid "done.\n"
 msgstr "feito.\n"
 
 # , c-format
-#: src/ftp.c:461
+#: src/ftp.c:480
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
-msgstr "Tipo `%c' desconhecido, fechando a conex�o de controle.\n"
+msgstr "Tipo \"%c\" é desconhecido, fechando a conexão de controle.\n"
 
-#: src/ftp.c:473
+#: src/ftp.c:492
 msgid "done.  "
 msgstr "feito. "
 
-#: src/ftp.c:479
+#: src/ftp.c:498
 msgid "==> CWD not needed.\n"
-msgstr "==> CWD n�o necess�rio.\n"
+msgstr "==> CWD não é necessário.\n"
 
 # , c-format
-#: src/ftp.c:573
+#: src/ftp.c:709
 #, fuzzy, c-format
 msgid ""
 "No such directory %s.\n"
 "\n"
 msgstr ""
-"Diret�rio `%s' n�o encontrado.\n"
+"O diretório \"%s\" não foi encontrado.\n"
 "\n"
 
-#: src/ftp.c:588
+#: src/ftp.c:730
 msgid "==> CWD not required.\n"
-msgstr "==> CWD n�o requerido.\n"
+msgstr "==> CWD não exigido.\n"
 
-#: src/ftp.c:649
+#: src/ftp.c:791
 msgid "Cannot initiate PASV transfer.\n"
-msgstr "N�o foi poss�vel iniciar transfer�ncia PASV.\n"
+msgstr "Não é possível iniciar transferência PASV.\n"
 
-#: src/ftp.c:653
+#: src/ftp.c:795
 msgid "Cannot parse PASV response.\n"
-msgstr "N�o foi poss�vel entender resposta do comando PASV.\n"
+msgstr "Não foi possível entender resposta do comando PASV.\n"
 
-#: src/ftp.c:670
-#, fuzzy, c-format
+#: src/ftp.c:812
+#, c-format
 msgid "couldn't connect to %s port %d: %s\n"
-msgstr "n�o foi poss�vel conectar para %s:%hu: %s\n"
+msgstr "não foi possível se conectar a %s porta %d: %s\n"
 
 # , c-format
-#: src/ftp.c:718
+#: src/ftp.c:860
 #, c-format
 msgid "Bind error (%s).\n"
-msgstr "Erro no bind (%s).\n"
+msgstr "Erro na associação (%s).\n"
 
-#: src/ftp.c:724
+#: src/ftp.c:866
 msgid "Invalid PORT.\n"
-msgstr "PORT inv�lido.\n"
+msgstr "PORT inválido.\n"
 
-#: src/ftp.c:770
+#: src/ftp.c:912
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
 msgstr ""
 "\n"
-"REST falhou, recome�ando do zero.\n"
+"REST falhou, recomeçando do zero.\n"
+
+#: src/ftp.c:953
+#, fuzzy, c-format
+msgid "File %s exists.\n"
+msgstr "O arquivo remoto existe.\n"
 
 # , c-format
-#: src/ftp.c:811
+#: src/ftp.c:959
 #, fuzzy, c-format
 msgid "No such file %s.\n"
 msgstr ""
-"Arquivo `%s' n�o encontrado.\n"
+"O arquivo \"%s\" não foi encontrado.\n"
 "\n"
 
 # , c-format
-#: src/ftp.c:857
+#: src/ftp.c:1005
 #, fuzzy, c-format
 msgid ""
 "No such file %s.\n"
 "\n"
 msgstr ""
-"Arquivo `%s' n�o encontrado.\n"
+"O arquivo \"%s\" não foi encontrado.\n"
 "\n"
 
 # , c-format
-#: src/ftp.c:904
+#: src/ftp.c:1052
 #, fuzzy, c-format
 msgid ""
 "No such file or directory %s.\n"
 "\n"
 msgstr ""
-"Arquivo ou diret�rio `%s' n�o encontrado.\n"
+"O arquivo ou o diretório \"%s\" não foi encontrado.\n"
 "\n"
 
-#: src/ftp.c:966 src/http.c:2261
+#: src/ftp.c:1183 src/http.c:2339
 #, c-format
 msgid "%s has sprung into existence.\n"
-msgstr ""
+msgstr "%s surgiu do nada.\n"
 
 # , c-format
-#: src/ftp.c:1018
+#: src/ftp.c:1235
 #, c-format
 msgid "%s: %s, closing control connection.\n"
-msgstr "%s: %s, fechando conex�o de controle.\n"
+msgstr "%s: %s, fechando conexão de controle.\n"
 
 # , c-format
-#: src/ftp.c:1027
+#: src/ftp.c:1244
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
-msgstr "%s (%s) - Conex�o de dados: %s; "
+msgstr "%s (%s) - Conexão de dados: %s; "
 
-#: src/ftp.c:1042
+#: src/ftp.c:1259
 msgid "Control connection closed.\n"
-msgstr "Conex�o de controle fechada.\n"
+msgstr "Conexão de controle fechada.\n"
 
-#: src/ftp.c:1060
+#: src/ftp.c:1277
 msgid "Data transfer aborted.\n"
-msgstr "Transfer�ncia dos dados abortada.\n"
+msgstr "Transferência dos dados abortada.\n"
 
 # , c-format
-#: src/ftp.c:1131
+#: src/ftp.c:1377
 #, fuzzy, c-format
 msgid "File %s already there; not retrieving.\n"
-msgstr "Arquivo `%s' j� existente, n�o ser� baixado.\n"
+msgstr "O arquivo \"%s\" já existe, não será baixado.\n"
 
 # , c-format
-#: src/ftp.c:1201 src/http.c:2441
+#: src/ftp.c:1443 src/http.c:2524
 #, c-format
 msgid "(try:%2d)"
 msgstr "(tentativa:%2d)"
 
 # , c-format
-#: src/ftp.c:1271 src/http.c:2774
+#: src/ftp.c:1518 src/http.c:2868
+#, fuzzy, c-format
+msgid ""
+"%s (%s) - written to stdout %s[%s]\n"
+"\n"
+msgstr ""
+"%s (%s) - \"%s\" salvo [%s/%s]\n"
+"\n"
+
+# , c-format
+#: src/ftp.c:1519 src/http.c:2869
 #, fuzzy, c-format
 msgid ""
 "%s (%s) - %s saved [%s]\n"
 "\n"
 msgstr ""
-"%s (%s) - `%s' recebido [%ld]\n"
+"%s (%s) - \"%s\" salvo [%s]\n"
 "\n"
 
 # , c-format
-#: src/ftp.c:1313 src/main.c:1060 src/recur.c:378 src/retr.c:860
+#: src/ftp.c:1564 src/main.c:1292 src/recur.c:438 src/retr.c:982
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Removendo %s.\n"
 
 # , c-format
-#: src/ftp.c:1355
+#: src/ftp.c:1606
 #, fuzzy, c-format
 msgid "Using %s as listing tmp file.\n"
-msgstr "Usando `%s' como arquivo tempor�rio de listagem.\n"
+msgstr "Usando \"%s\" como arquivo temporário de listagem.\n"
 
 # , c-format
-#: src/ftp.c:1369
+#: src/ftp.c:1623
 #, fuzzy, c-format
 msgid "Removed %s.\n"
-msgstr "Removido `%s'.\n"
+msgstr "Removeu \"%s\".\n"
 
 # , c-format
-#: src/ftp.c:1405
+#: src/ftp.c:1660
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
-msgstr "N�vel de recurs�o %d excede n�vel m�ximo %d.\n"
+msgstr "Nível de recursão %d excedeu o nível máximo %d.\n"
 
-#: src/ftp.c:1475
+#: src/ftp.c:1730
 #, fuzzy, c-format
 msgid "Remote file no newer than local file %s -- not retrieving.\n"
-msgstr "Arquivo remoto n�o � mais novo que o local `%s' -- ignorando.\n"
+msgstr "Arquivo remoto não é mais novo que o local \"%s\" -- ignorando.\n"
 
-#: src/ftp.c:1482
+#: src/ftp.c:1737
 #, fuzzy, c-format
 msgid ""
 "Remote file is newer than local file %s -- retrieving.\n"
 "\n"
 msgstr ""
-"Arquivo remoto � mais que o local `%s' -- baixando.\n"
+"Arquivo remoto é mais novo que o local \"%s\" -- baixando.\n"
 "\n"
 
-#: src/ftp.c:1489
-#, fuzzy, c-format
+#: src/ftp.c:1744
+#, c-format
 msgid ""
 "The sizes do not match (local %s) -- retrieving.\n"
 "\n"
 msgstr ""
-"Os tamanhos n�o s�o iguais (local %ld) -- baixando.\n"
+"Os tamanhos não coincidem (local %s) -- baixando.\n"
 "\n"
 
-#: src/ftp.c:1507
+#: src/ftp.c:1762
 msgid "Invalid name of the symlink, skipping.\n"
-msgstr "Nome inv�lido do link simb�lico, ignorando.\n"
+msgstr "Nome inválido da ligação simbólica, ignorando.\n"
 
 # , c-format
-#: src/ftp.c:1524
+#: src/ftp.c:1779
 #, c-format
 msgid ""
 "Already have correct symlink %s -> %s\n"
 "\n"
 msgstr ""
-"Link simb�lico j� est� correto %s -> %s\n"
+"Ligação simbólica já está correta %s -> %s\n"
 "\n"
 
 # , c-format
-#: src/ftp.c:1533
+#: src/ftp.c:1788
 #, c-format
 msgid "Creating symlink %s -> %s\n"
-msgstr "Criando link simb�lico %s -> %s\n"
+msgstr "Criando ligação simbólica %s -> %s\n"
 
 # , c-format
-#: src/ftp.c:1543
+#: src/ftp.c:1798
 #, fuzzy, c-format
 msgid "Symlinks not supported, skipping symlink %s.\n"
-msgstr "Links simb�licos n�o suportados, %s ser� ignorado.\n"
+msgstr "Não há suporte a ligações simbólicas, ignorando a ligação \"%s\".\n"
 
 # , c-format
-#: src/ftp.c:1555
+#: src/ftp.c:1810
 #, fuzzy, c-format
 msgid "Skipping directory %s.\n"
-msgstr "Ignorando diret�rio `%s'.\n"
+msgstr "Ignorando o diretório \"%s\".\n"
 
 # , c-format
-#: src/ftp.c:1564
+#: src/ftp.c:1819
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
-msgstr "%s: tipo de arquivo desconhecido/n�o suportado.\n"
+msgstr "%s: tipo de arquivo desconhecido/sem suporte.\n"
 
 # , c-format
-#: src/ftp.c:1591
+#: src/ftp.c:1856
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
-msgstr "%s: hor�rio (timestamp) inv�lido.\n"
+msgstr "%s: horário (timestamp) corrompido.\n"
 
 # , c-format
-#: src/ftp.c:1619
+#: src/ftp.c:1878
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr ""
-"N�o ser�o buscados diret�rios, pois o n�vel de recurs�o � %d (max %d).\n"
+"Não serão baixados os diretórios, pois o nível de recursão é %d (máx. %d).\n"
 
 # , c-format
-#: src/ftp.c:1669
+#: src/ftp.c:1928
 #, fuzzy, c-format
 msgid "Not descending to %s as it is excluded/not-included.\n"
-msgstr "N�o descendo para `%s', pois est� exclu�do/n�o inclu�do.\n"
+msgstr "Não descendo para \"%s\", pois está excluído/não incluído.\n"
 
 # , c-format
-#: src/ftp.c:1735 src/ftp.c:1749
+#: src/ftp.c:1994 src/ftp.c:2008
 #, fuzzy, c-format
 msgid "Rejecting %s.\n"
-msgstr "Rejeitando `%s'.\n"
+msgstr "Rejeitando \"%s\".\n"
 
 # , c-format
-#: src/ftp.c:1772
-#, fuzzy, c-format
+#: src/ftp.c:2031
+#, c-format
 msgid "Error matching %s against %s: %s\n"
-msgstr "Erro ao gravar em `%s' %s.\n"
+msgstr "Erro ao comparar %s com %s: %s.\n"
 
 # , c-format
-#: src/ftp.c:1814
+#: src/ftp.c:2073
 #, fuzzy, c-format
 msgid "No matches on pattern %s.\n"
-msgstr "Nada encontrado com o padr�o `%s'.\n"
+msgstr "Não há ocorrências para o padrão \"%s\".\n"
 
 # , c-format
-#: src/ftp.c:1880
+#: src/ftp.c:2144
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s [%s].\n"
-msgstr "Escrito index em formato HTML para `%s' [%ld].\n"
+msgstr "Escrito índice em formato HTML em \"%s\" [%s].\n"
 
 # , c-format
-#: src/ftp.c:1885
+#: src/ftp.c:2149
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s.\n"
-msgstr "Escrito �ndice em formato HTML para `%s'.\n"
+msgstr "Escrito índice em formato HTML em \"%s\".\n"
 
-#: src/host.c:348
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "ERROR"
+msgstr "ERRO"
+
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "WARNING"
+msgstr "AVISO"
+
+#: src/gnutls.c:225 src/openssl.c:504
+#, c-format
+msgid "%s: No certificate presented by %s.\n"
+msgstr "%s: Nenhum certificado apresentado por %s.\n"
+
+#: src/gnutls.c:233
+#, fuzzy, c-format
+msgid "%s: The certificate of %s is not trusted.\n"
+msgstr "%s: Nenhum certificado apresentado por %s.\n"
+
+#: src/gnutls.c:239
+#, c-format
+msgid "%s: The certificate of %s hasn't got a known issuer.\n"
+msgstr ""
+
+#: src/gnutls.c:245
+#, fuzzy, c-format
+msgid "%s: The certificate of %s has been revoked.\n"
+msgstr "  Certificado emitido expirou.\n"
+
+#: src/gnutls.c:259
+#, c-format
+msgid "Error initializing X509 certificate: %s\n"
+msgstr ""
+
+#: src/gnutls.c:268
 #, fuzzy
+msgid "No certificate found\n"
+msgstr "%s: Nenhum certificado apresentado por %s.\n"
+
+#: src/gnutls.c:275
+#, fuzzy, c-format
+msgid "Error parsing certificate: %s\n"
+msgstr "Erro ao analisar URL do proxy %s: %s\n"
+
+#: src/gnutls.c:282
+#, fuzzy
+msgid "The certificate has not yet been activated\n"
+msgstr "  Certificado emitido ainda não é válido.\n"
+
+#: src/gnutls.c:287
+#, fuzzy
+msgid "The certificate has expired\n"
+msgstr "  Certificado emitido expirou.\n"
+
+#: src/gnutls.c:293
+#, fuzzy, c-format
+msgid "The certificate's owner does not match hostname '%s'\n"
+msgstr ""
+"%s: nome comum no certificado \"%s\" não coincide com o nome de máquina "
+"solicitado por \"%s\".\n"
+
+#: src/host.c:358
 msgid "Unknown host"
-msgstr "Erro desconhecido"
+msgstr "Máquina desconhecida"
 
-#: src/host.c:352
+#: src/host.c:362
 msgid "Temporary failure in name resolution"
-msgstr ""
+msgstr "Falha temporária na resolução de nomes"
 
-#: src/host.c:354
+#: src/host.c:364
 msgid "Unknown error"
 msgstr "Erro desconhecido"
 
-#: src/host.c:715
+#: src/host.c:737
 #, c-format
 msgid "Resolving %s... "
 msgstr "Resolvendo %s... "
 
-#: src/host.c:763
+#: src/host.c:789
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
-msgstr ""
+msgstr "falha: Não há endereços IPv4/IPv6 para a máquina.\n"
 
-#: src/host.c:786
+#: src/host.c:812
 msgid "failed: timed out.\n"
 msgstr "falha: tempo excedido.\n"
 
-#: src/html-url.c:289
+#: src/html-url.c:286
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
-msgstr "%s: N�o foi poss�vel resolver link incompleto %s.\n"
+msgstr "%s: Não foi possível resolver o link incompleto %s.\n"
 
-#: src/html-url.c:696
-#, fuzzy, c-format
+#: src/html-url.c:762
+#, c-format
 msgid "%s: Invalid URL %s: %s\n"
-msgstr "%s: %s: Valor inv�lido `%s'.\n"
+msgstr "%s: URL inválido %s: %s.\n"
 
-#: src/http.c:368
+#: src/http.c:377
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
-msgstr "Falha ao enviar requisi��o HTTP: %s.\n"
+msgstr "Falhou em enviar requisição HTTP: %s.\n"
 
-#: src/http.c:745
+#: src/http.c:754
 msgid "No headers, assuming HTTP/0.9"
-msgstr ""
+msgstr "Não foram recebidos cabeçalhos, assumindo HTTP/0.9"
 
-#: src/http.c:1430
+#: src/http.c:1456
 msgid "Disabling SSL due to encountered errors.\n"
-msgstr ""
+msgstr "Desabilitando SSL devido aos erros encontrados.\n"
 
-#: src/http.c:1548
-#, c-format
+#: src/http.c:1576
+#, fuzzy, c-format
 msgid "POST data file %s missing: %s\n"
-msgstr ""
+msgstr "O arquivo \"%s\" de dados POST está faltando: %s\n"
 
-#: src/http.c:1632
-#, fuzzy, c-format
+#: src/http.c:1660
+#, c-format
 msgid "Reusing existing connection to %s:%d.\n"
-msgstr "Reutilizando conex�o para %s:%hu.\n"
+msgstr "Reaproveitando a conexão existente para %s:%d.\n"
 
-#: src/http.c:1701
-#, fuzzy, c-format
+#: src/http.c:1729
+#, c-format
 msgid "Failed reading proxy response: %s\n"
-msgstr "Falha ao enviar requisi��o HTTP: %s.\n"
+msgstr "Falhou em ler a resposta do proxy: %s.\n"
 
-#: src/http.c:1721
+#: src/http.c:1750
 #, c-format
 msgid "Proxy tunneling failed: %s"
-msgstr ""
+msgstr "Tunelamento pelo proxy falhou: %s"
 
 # , c-format
-#: src/http.c:1766
+#: src/http.c:1795
 #, c-format
 msgid "%s request sent, awaiting response... "
-msgstr "%s requisi��o enviada, aguardando resposta... "
+msgstr "Requisição %s enviada, aguardando resposta... "
 
-#: src/http.c:1777
-#, fuzzy
+#: src/http.c:1806
 msgid "No data received.\n"
-msgstr "Nenhum dado recebido"
+msgstr "Nenhum dado foi recebido.\n"
 
 # , c-format
-#: src/http.c:1784
+#: src/http.c:1813
 #, c-format
 msgid "Read error (%s) in headers.\n"
-msgstr "Erro de leitura (%s) nos headers.\n"
+msgstr "Erro de leitura (%s) nos cabeçalhos.\n"
+
+#: src/http.c:1884
+msgid "Unknown authentication scheme.\n"
+msgstr "Esquema de autenticação desconhecido.\n"
+
+#: src/http.c:1918
+msgid "Authorization failed.\n"
+msgstr "Autorização falhou.\n"
 
 # , c-format
-#: src/http.c:1831 src/http.c:2385
+#: src/http.c:1956 src/http.c:2466
 #, fuzzy, c-format
 msgid ""
 "File %s already there; not retrieving.\n"
 "\n"
-msgstr "Arquivo `%s' j� existente, n�o ser� baixado.\n"
-
-#: src/http.c:1985
-msgid "Unknown authentication scheme.\n"
-msgstr "Esquema de autentica��o desconhecido.\n"
-
-#: src/http.c:2016
-msgid "Authorization failed.\n"
-msgstr "Autoriza��o falhou.\n"
+msgstr ""
+"O arquivo \"%s\" já existe, não será baixado.\n"
+"\n"
 
-#: src/http.c:2030
+#: src/http.c:2070
 msgid "Malformed status line"
-msgstr "Linha de status inv�lida"
+msgstr "Linha de status inválida"
 
-#: src/http.c:2032
+#: src/http.c:2072
 msgid "(no description)"
-msgstr "(sem descri��o)"
+msgstr "(sem descrição)"
 
 # , c-format
-#: src/http.c:2098
+#: src/http.c:2149
 #, c-format
 msgid "Location: %s%s\n"
-msgstr "Localiza��o: %s%s\n"
+msgstr "Localização: %s%s\n"
 
-#: src/http.c:2099 src/http.c:2209
+#: src/http.c:2150 src/http.c:2258
 msgid "unspecified"
-msgstr "nao especificado"
+msgstr "não especificada"
 
-#: src/http.c:2100
+#: src/http.c:2151
 msgid " [following]"
-msgstr " [seguinte]"
+msgstr " [redirecionando]"
 
-#: src/http.c:2156
+#: src/http.c:2203
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 "\n"
-"    O arquivo j� foi completamente obtido; nada a ser feito.\n"
+"    O arquivo já foi completamente obtido; não há nada a ser feito.\n"
 "\n"
 
-#: src/http.c:2189
+#: src/http.c:2238
 msgid "Length: "
 msgstr "Tamanho: "
 
-#: src/http.c:2209
+#: src/http.c:2258
 msgid "ignored"
 msgstr "ignorado"
 
-#: src/http.c:2280
-#, c-format
+# , c-format
+#: src/http.c:2360
+#, fuzzy, c-format
 msgid "Saving to: %s\n"
-msgstr ""
+msgstr "Salvando para: \"%s\"\n"
 
-#: src/http.c:2361
+#: src/http.c:2442
 msgid "Warning: wildcards not supported in HTTP.\n"
-msgstr "Aviso: wildcards n�o suportados para HTTP.\n"
+msgstr "Aviso: Não há suporte para caracteres coringa no HTTP.\n"
 
-#: src/http.c:2430
+#: src/http.c:2513
 msgid "Spider mode enabled. Check if remote file exists.\n"
-msgstr ""
+msgstr "Modo aranha habilitado. Verifique se o arquivo remoto existe.\n"
 
 # , c-format
-#: src/http.c:2515
+#: src/http.c:2598
 #, fuzzy, c-format
 msgid "Cannot write to %s (%s).\n"
-msgstr "N�o foi poss�vel escrever em `%s' (%s).\n"
+msgstr "Não foi possível escrever em \"%s\" (%s).\n"
 
-#: src/http.c:2524
+#: src/http.c:2607
 msgid "Unable to establish SSL connection.\n"
-msgstr "N�o foi poss�vel estabelecer conex�o segura (SSL).\n"
+msgstr "Não foi possível estabelecer conexão segura (SSL).\n"
 
 # , c-format
-#: src/http.c:2532
+#: src/http.c:2615
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
-msgstr "ERRO: Redire��o (%d) sem Location.\n"
+msgstr "ERRO: Redirecionamento (%d) sem Location.\n"
 
-#: src/http.c:2578
+#: src/http.c:2663
 msgid "Remote file does not exist -- broken link!!!\n"
-msgstr ""
+msgstr "Arquivo remoto não existe -- link quebrado!!!\n"
 
 # , c-format
-#: src/http.c:2583
+#: src/http.c:2668
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s ERRO %d: %s.\n"
 
-#: src/http.c:2600
+#: src/http.c:2685
 msgid "Last-modified header missing -- time-stamps turned off.\n"
-msgstr "Header Last-modified n�o recebido -- time-stamps desligados.\n"
+msgstr "Está faltando o cabeçalho Last-modified -- horários desligados.\n"
 
-#: src/http.c:2608
+#: src/http.c:2693
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
-msgstr "Header Last-modified inv�lido -- time-stamp ignorado.\n"
+msgstr "O cabeçalho Last-modified é inválido -- horário ignorado.\n"
 
-#: src/http.c:2638
+#: src/http.c:2723
 #, fuzzy, c-format
 msgid ""
 "Server file no newer than local file %s -- not retrieving.\n"
 "\n"
 msgstr ""
-"Arquivo no servidor n�o � mais novo que o local `%s' -- n�o baixando.\n"
+"O arquivo no servidor não é mais novo que o local \"%s\" -- ignorando.\n"
 "\n"
 
-#: src/http.c:2646
-#, fuzzy, c-format
+#: src/http.c:2731
+#, c-format
 msgid "The sizes do not match (local %s) -- retrieving.\n"
-msgstr "Os tamanhos n�o s�o iguais (local %ld) -- baixando.\n"
+msgstr "Os tamanhos não coincidem (local %s) -- baixando.\n"
 
-#: src/http.c:2653
+#: src/http.c:2738
 msgid "Remote file is newer, retrieving.\n"
-msgstr "Arquivo remoto � mais novo, buscando.\n"
+msgstr "O arquivo remoto é mais novo, baixando.\n"
 
-#: src/http.c:2669
-#, fuzzy
+#: src/http.c:2755
 msgid ""
 "Remote file exists and could contain links to other resources -- "
 "retrieving.\n"
 "\n"
 msgstr ""
-"Arquivo remoto � mais que o local `%s' -- baixando.\n"
+"O arquivo remoto existe e pode conter links para outras fontes -- baixando.\n"
 "\n"
 
-#: src/http.c:2674
-#, fuzzy
+#: src/http.c:2761
 msgid ""
 "Remote file exists but does not contain any link -- not retrieving.\n"
 "\n"
-msgstr "Arquivo remoto n�o � mais novo que o local `%s' -- ignorando.\n"
+msgstr ""
+"O arquivo remoto existe mas não contém link algum -- ignorando.\n"
+"\n"
 
-#: src/http.c:2684
+#: src/http.c:2770
 msgid ""
 "Remote file exists and could contain further links,\n"
 "but recursion is disabled -- not retrieving.\n"
 "\n"
 msgstr ""
+"O arquivo remoto existe e poderia conter mais links,\n"
+"mas a recursão está desabilitada -- ignorando.\n"
+"\n"
 
-#: src/http.c:2690
-#, fuzzy
+#: src/http.c:2776
 msgid ""
 "Remote file exists.\n"
 "\n"
-msgstr "Arquivo remoto � mais novo, buscando.\n"
+msgstr "O arquivo remoto existe.\n"
 
 # , c-format
-#: src/http.c:2743
+#: src/http.c:2785
+#, fuzzy, c-format
+msgid "%s URL:%s %2d %s\n"
+msgstr "%s ERRO %d: %s.\n"
+
+# , c-format
+#: src/http.c:2832
 #, fuzzy, c-format
 msgid ""
-"%s (%s) - %s saved [%s/%s]\n"
+"%s (%s) - written to stdout %s[%s/%s]\n"
 "\n"
 msgstr ""
-"%s (%s) - `%s' recebido [%ld/%ld]\n"
+"%s (%s) - \"%s\" salvo [%s/%s]\n"
 "\n"
 
-#: src/http.c:2798
+# , c-format
+#: src/http.c:2833
 #, fuzzy, c-format
+msgid ""
+"%s (%s) - %s saved [%s/%s]\n"
+"\n"
+msgstr ""
+"%s (%s) - \"%s\" salvo [%s/%s]\n"
+"\n"
+
+#: src/http.c:2894
+#, c-format
 msgid "%s (%s) - Connection closed at byte %s. "
-msgstr "%s (%s) - Conex�o fechada no byte %ld. "
+msgstr "%s (%s) - Conexão fechada no byte %s. "
 
-#: src/http.c:2813
-#, fuzzy, c-format
+#: src/http.c:2917
+#, c-format
 msgid "%s (%s) - Read error at byte %s (%s)."
-msgstr "%s (%s) - Erro de leitura no byte %ld (%s)."
+msgstr "%s (%s) - Erro de leitura no byte %s (%s)."
 
-#: src/http.c:2822
-#, fuzzy, c-format
+#: src/http.c:2926
+#, c-format
 msgid "%s (%s) - Read error at byte %s/%s (%s). "
-msgstr "%s (%s) - Erro de leitura no byte %ld/%ld (%s)."
+msgstr "%s (%s) - Erro de leitura no byte %s/%s (%s). "
 
-#: src/init.c:391
+#: src/init.c:404
 #, c-format
 msgid "%s: WGETRC points to %s, which doesn't exist.\n"
-msgstr "%s: WGETRC aponta para %s, que n�o existe.\n"
+msgstr "%s: WGETRC aponta para %s, que não existe.\n"
 
-#: src/init.c:454 src/netrc.c:265
+#: src/init.c:508 src/netrc.c:282
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
-msgstr "%s: N�o foi poss�vel ler %s (%s).\n"
+msgstr "%s: Não foi possível ler %s (%s).\n"
 
-#: src/init.c:472
+#: src/init.c:525
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: Erro em %s na linha %d.\n"
 
-#: src/init.c:478
-#, fuzzy, c-format
+#: src/init.c:531
+#, c-format
 msgid "%s: Syntax error in %s at line %d.\n"
-msgstr "%s: Erro em %s na linha %d.\n"
+msgstr "%s: Erro de sintaxe em %s na linha %d.\n"
 
 # , c-format
-#: src/init.c:483
+#: src/init.c:536
 #, fuzzy, c-format
 msgid "%s: Unknown command %s in %s at line %d.\n"
-msgstr "%s: BUG: comando desconhecido `%s', valor `%s'.\n"
+msgstr "%s: Comando desconhecido \"%s\" em %s na linha %d.\n"
 
-#: src/init.c:528
+#: src/init.c:585
 #, fuzzy, c-format
 msgid "%s: Warning: Both system and user wgetrc point to %s.\n"
 msgstr ""
-"%s: Aviso: os arquivos wgetrc do sistema e do usu�rio apontam para `%s'.\n"
+"%s: Aviso: os arquivos wgetrc do sistema e do usuário apontam para \"%s\".\n"
 
-#: src/init.c:681
+#: src/init.c:775
 #, fuzzy, c-format
 msgid "%s: Invalid --execute command %s\n"
-msgstr "%s: comando --execute � inv�lido `%s'\n"
+msgstr "%s: O comando --execute é inválido \"%s\"\n"
 
-#: src/init.c:726
+#: src/init.c:820
 #, fuzzy, c-format
 msgid "%s: %s: Invalid boolean %s; use `on' or `off'.\n"
-msgstr "%s: %s: express�o inv�lida `%s', use `on' ou `off'.\n"
+msgstr "%s: %s: valor inválido \"%s\", use \"on\" ou \"off\".\n"
 
-#: src/init.c:743
+#: src/init.c:837
 #, fuzzy, c-format
 msgid "%s: %s: Invalid number %s.\n"
-msgstr "%s: %s: N�mero inv�lido `%s'.\n"
+msgstr "%s: %s: Número inválido \"%s\".\n"
 
-#: src/init.c:974 src/init.c:993
+#: src/init.c:1042 src/init.c:1061
 #, fuzzy, c-format
 msgid "%s: %s: Invalid byte value %s\n"
-msgstr "%s: %s: Valor inv�lido do byte `%s'\n"
+msgstr "%s: %s: Valor inválido do byte \"%s\"\n"
 
-#: src/init.c:1018
+#: src/init.c:1086
 #, fuzzy, c-format
 msgid "%s: %s: Invalid time period %s\n"
-msgstr "%s: %s: Per�odo de tempo inv�lido `%s'\n"
+msgstr "%s: %s: Período de tempo inválido \"%s\"\n"
 
-#: src/init.c:1072 src/init.c:1162 src/init.c:1265 src/init.c:1290
+#: src/init.c:1140 src/init.c:1230 src/init.c:1333 src/init.c:1358
 #, fuzzy, c-format
 msgid "%s: %s: Invalid value %s.\n"
-msgstr "%s: %s: Valor inv�lido `%s'.\n"
+msgstr "%s: %s: Valor inválido \"%s\".\n"
 
-#: src/init.c:1109
+#: src/init.c:1177
 #, fuzzy, c-format
 msgid "%s: %s: Invalid header %s.\n"
-msgstr "%s: %s: Cabe�alho inv�lido `%s'.\n"
+msgstr "%s: %s: Cabeçalho inválido \"%s\".\n"
 
-#: src/init.c:1175
+#: src/init.c:1243
 #, fuzzy, c-format
 msgid "%s: %s: Invalid progress type %s.\n"
-msgstr "%s: %s: Tipo de progresso inv�lido `%s'.\n"
+msgstr "%s: %s: Tipo inválido de progresso \"%s\".\n"
 
-#: src/init.c:1234
+#: src/init.c:1302
 #, fuzzy, c-format
 msgid ""
 "%s: %s: Invalid restriction %s, use [unix|windows],[lowercase|uppercase],"
 "[nocontrol].\n"
-msgstr "%s: %s: Restri��o inv�lida `%s', use `unix' ou `windows'.\n"
+msgstr ""
+"%s: %s: Restrição inválida \"%s\", use [unix|windows].[lowercase|uppercase],"
+"[nocontrol].\n"
+
+#: src/iri.c:104
+#, c-format
+msgid "Encoding %s isn't valid\n"
+msgstr ""
+
+#: src/iri.c:132
+msgid "locale_to_utf8: locale is unset\n"
+msgstr ""
 
-#: src/log.c:784
+#: src/iri.c:142
+#, c-format
+msgid "Conversion from %s to %s isn't supported\n"
+msgstr ""
+
+#: src/iri.c:183
+msgid "Incomplete or invalide multibyte sequence encountered\n"
+msgstr ""
+
+#: src/iri.c:208
+#, c-format
+msgid "Unhandled errno %d\n"
+msgstr ""
+
+#: src/iri.c:237
+#, c-format
+msgid "idn_encode failed (%d): %s\n"
+msgstr ""
+
+#: src/iri.c:256
+#, c-format
+msgid "idn_decode failed (%d): %s\n"
+msgstr ""
+
+#: src/log.c:809
 #, fuzzy, c-format
 msgid ""
 "\n"
 "%s received, redirecting output to %s.\n"
 msgstr ""
 "\n"
-"%s recebido, redirecionando sa�da para `%s'.\n"
+"%s recebido, redirecionando saída para \"%s\".\n"
 
-#: src/log.c:794
-#, fuzzy, c-format
+#: src/log.c:819
+#, c-format
 msgid ""
 "\n"
 "%s received.\n"
-msgstr "Nenhum dado recebido"
+msgstr ""
+"\n"
+"%s recebido.\n"
 
-#: src/log.c:795
+#: src/log.c:820
 #, c-format
 msgid "%s: %s; disabling logging.\n"
-msgstr "%s: %s; desabilitando log.\n"
+msgstr "%s: %s; desabilitando registro.\n"
 
-#: src/main.c:361
+#: src/main.c:384
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
-msgstr "Uso: %s [OP��O]... [URL]...\n"
+msgstr "Uso: %s [OPÇÃO]... [URL]...\n"
 
-#: src/main.c:373
-#, fuzzy
+#: src/main.c:396
 msgid ""
 "Mandatory arguments to long options are mandatory for short options too.\n"
 "\n"
 msgstr ""
-"\n"
-"Argumentos obrigat�rios para op��es longas s�o tamb�m\n"
-"obrigat�rios para op��es curtas.\n"
+"Argumentos obrigatórios para opções longas também o são para as opções "
+"curtas.\n"
 "\n"
 
-#: src/main.c:375
+#: src/main.c:398
 msgid "Startup:\n"
-msgstr ""
+msgstr "Inicialização:\n"
 
-#: src/main.c:377
+#: src/main.c:400
 msgid "  -V,  --version           display the version of Wget and exit.\n"
-msgstr ""
+msgstr "  -V,  --version           mostra a versão do Wget e sai.\n"
 
-#: src/main.c:379
+#: src/main.c:402
 msgid "  -h,  --help              print this help.\n"
-msgstr ""
+msgstr "  -h,  --help              emite esta ajuda.\n"
 
-#: src/main.c:381
+#: src/main.c:404
 msgid "  -b,  --background        go to background after startup.\n"
 msgstr ""
+"  -b,  --background        vai para o plano de fundo depois de iniciar.\n"
 
-#: src/main.c:383
+#: src/main.c:406
 msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
-msgstr ""
+msgstr "  -e,  --execute=COMANDO   executa um comando no estilo \".wgetrc\".\n"
 
-#: src/main.c:387
+#: src/main.c:410
 msgid "Logging and input file:\n"
-msgstr ""
+msgstr "Arquivo de entrada e de registro:\n"
 
-#: src/main.c:389
+#: src/main.c:412
 msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
-msgstr ""
+msgstr "  -o,  --output-file=ARQ     envia as mensagens de log para ARQuivo.\n"
 
-#: src/main.c:391
+#: src/main.c:414
 msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
-msgstr ""
+msgstr "  -a,  --append-output=ARQ   anexa mensagens ao ARQuivo.\n"
 
-#: src/main.c:394
+#: src/main.c:417
 msgid "  -d,  --debug               print lots of debugging information.\n"
-msgstr ""
+msgstr "  -d,  --debug               emite muita informações de depuração.\n"
 
-#: src/main.c:398
+#: src/main.c:421
 msgid "       --wdebug              print Watt-32 debug output.\n"
-msgstr ""
+msgstr "       --wdebug              emite a saída de depuração Watt-32.\n"
 
-#: src/main.c:401
+#: src/main.c:424
 msgid "  -q,  --quiet               quiet (no output).\n"
-msgstr ""
+msgstr "  -q,  --quiet               silencioso (não emite nada).\n"
 
-#: src/main.c:403
+#: src/main.c:426
 msgid "  -v,  --verbose             be verbose (this is the default).\n"
-msgstr ""
+msgstr "  -v,  --verbose             detalhista (isto é o padrão).\n"
 
-#: src/main.c:405
+#: src/main.c:428
 msgid ""
 "  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
 msgstr ""
+"  -nv, --no-verbose          desativa o detalhamento, sem ser silencioso.\n"
 
-#: src/main.c:407
-msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
-msgstr ""
+#: src/main.c:430
+#, fuzzy
+msgid ""
+"  -i,  --input-file=FILE     download URLs found in local or external FILE.\n"
+msgstr "  -i,  --input-file=ARQ      baixa os URLs encontrados no ARQuivo.\n"
 
-#: src/main.c:409
+#: src/main.c:432
 msgid "  -F,  --force-html          treat input file as HTML.\n"
-msgstr ""
+msgstr "  -F,  --force-html          trata o arquivo de entrada como HTML.\n"
 
-#: src/main.c:411
+#: src/main.c:434
 msgid ""
 "  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
 msgstr ""
+"  -B,  --base=URL            prefixa com URL os links relativos no arquivo\n"
+"                               quando usadas as opções -F -i.\n"
 
-#: src/main.c:415
+#: src/main.c:438
 msgid "Download:\n"
-msgstr ""
+msgstr "Download:\n"
 
-#: src/main.c:417
+#: src/main.c:440
 msgid ""
 "  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
 "unlimits).\n"
 msgstr ""
+"  -t,  --tries=NÚMERO            define o número de tentativas como NÚMERO\n"
+"                                   (0 significa ilimitada).\n"
 
-#: src/main.c:419
+#: src/main.c:442
 msgid "       --retry-connrefused       retry even if connection is refused.\n"
 msgstr ""
+"       --retry-connrefused       tenta novamente mesmo se a conexão for\n"
+"                                   recusada.\n"
 
-#: src/main.c:421
+#: src/main.c:444
 msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
-msgstr ""
+msgstr "  -O,  --output-document=ARQ     escreve os documentos no ARQuivo.\n"
 
-#: src/main.c:423
+#: src/main.c:446
 msgid ""
 "  -nc, --no-clobber              skip downloads that would download to\n"
 "                                 existing files.\n"
 msgstr ""
+"  -nc, --no-clobber              ignora os downloads que sobrescreveriam\n"
+"                                   arquivos existentes.\n"
 
-#: src/main.c:426
+#: src/main.c:449
 msgid ""
 "  -c,  --continue                resume getting a partially-downloaded "
 "file.\n"
 msgstr ""
+"  -c,  --continue                retoma o download de um arquivo baixado\n"
+"                                   parcialmente.\n"
 
-#: src/main.c:428
+#: src/main.c:451
 msgid "       --progress=TYPE           select progress gauge type.\n"
 msgstr ""
+"       --progress=TIPO           seleciona o tipo de indicador de "
+"progresso.\n"
 
-#: src/main.c:430
+#: src/main.c:453
 msgid ""
 "  -N,  --timestamping            don't re-retrieve files unless newer than\n"
 "                                 local.\n"
 msgstr ""
+"  -N,  --timestamping            não tentar refazer o download de um "
+"arquivo,\n"
+"                                   a menos que ele seja mais novo que o "
+"local.\n"
 
-#: src/main.c:433
+#: src/main.c:456
 msgid "  -S,  --server-response         print server response.\n"
-msgstr ""
+msgstr "  -S,  --server-response         exibe a resposta do servidor.\n"
 
-#: src/main.c:435
+#: src/main.c:458
 msgid "       --spider                  don't download anything.\n"
-msgstr ""
+msgstr "       --spider                  não baixa nada.\n"
 
-#: src/main.c:437
+#: src/main.c:460
 msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
 msgstr ""
+"  -T,  --timeout=SEGUNDOS        define todos os valores de tempo de espera\n"
+"                                   como SEGUNDOS.\n"
 
-#: src/main.c:439
+#: src/main.c:462
 msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
 msgstr ""
+"       --dns-timeout=SEGUNDOS     define o tempo de espera de busca de DNS "
+"como\n"
+"                                    SEGUNDOS.\n"
 
-#: src/main.c:441
+#: src/main.c:464
 msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
 msgstr ""
+"       --connect-timeout=SEGS    define o tempo de espera da conexão como "
+"SEGS.\n"
 
-#: src/main.c:443
+#: src/main.c:466
 msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
 msgstr ""
+"       --read-timeout=SEGUNDOS   define o tempo de espera de leitura como\n"
+"                                   SEGUNDOS.\n"
 
-#: src/main.c:445
+#: src/main.c:468
 msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
 msgstr ""
+"  -w,  --wait=SEGUNDOS           espera SEGUNDOS entre as tentativas.\n"
 
-#: src/main.c:447
+#: src/main.c:470
 msgid ""
 "       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
 "retrieval.\n"
 msgstr ""
+"       --waitretry=SEGUNDOS      espera de 1 a SEGUNDOS entre as tentativas "
+"de\n"
+"                                   baixar.\n"
 
-#: src/main.c:449
+#: src/main.c:472
 msgid ""
 "       --random-wait             wait from 0...2*WAIT secs between "
 "retrievals.\n"
 msgstr ""
+"       --random-wait             espera de 0 a 2*ESPERA segundos entre os\n"
+"                                   downloads.\n"
 
-#: src/main.c:451
+#: src/main.c:474
 msgid "       --no-proxy                explicitly turn off proxy.\n"
-msgstr ""
+msgstr "       --no-proxy                desativa explicitamente o proxy.\n"
 
-#: src/main.c:453
+#: src/main.c:476
 msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
 msgstr ""
+"  -Q,  --quota=QUANTIDADE        define a cota de download como QUANTIDADE.\n"
 
-#: src/main.c:455
+#: src/main.c:478
 msgid ""
 "       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
 "host.\n"
 msgstr ""
+"       --bind-address=ENDEREÇO   associa à máquina local o ENDEREÇO (nome "
+"de\n"
+"                                   máquina ou número IP).\n"
 
-#: src/main.c:457
+#: src/main.c:480
 msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
-msgstr ""
+msgstr "       --limit-rate=TAXA         limita a taxa de download a TAXA.\n"
 
-#: src/main.c:459
+#: src/main.c:482
 msgid "       --no-dns-cache            disable caching DNS lookups.\n"
-msgstr ""
+msgstr "       --no-dns-cache            desabilita o cache da busca de DNS.\n"
 
-#: src/main.c:461
+#: src/main.c:484
 msgid ""
 "       --restrict-file-names=OS  restrict chars in file names to ones OS "
 "allows.\n"
 msgstr ""
+"       --restrict-file-names=SO  restringe os caracteres nos nomes de "
+"arquivos\n"
+"                                   aos que o SO (sistema operacional) "
+"permite.\n"
 
-#: src/main.c:463
+#: src/main.c:486
 msgid ""
 "       --ignore-case             ignore case when matching files/"
 "directories.\n"
 msgstr ""
+"       --ignore-case             ignora a maiusculização ao comparar "
+"arquivos/\n"
+"                                   diretórios.\n"
 
-#: src/main.c:466
+#: src/main.c:489
 msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
-msgstr ""
+msgstr "  -4,  --inet4-only              conecta apenas a endereços IPv4.\n"
 
-#: src/main.c:468
+#: src/main.c:491
 msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
-msgstr ""
+msgstr "  -6,  --inet6-only              conecta apenas a endereços IPv6.\n"
 
-#: src/main.c:470
+#: src/main.c:493
 msgid ""
 "       --prefer-family=FAMILY    connect first to addresses of specified "
 "family,\n"
 "                                 one of IPv6, IPv4, or none.\n"
 msgstr ""
+"       --prefer-family=FAMÍLIA   conecta primeiro a endereços da família\n"
+"                                   especificada: IPv6, IPv4 ou \"none"
+"\" (nenhum).\n"
 
-#: src/main.c:474
+#: src/main.c:497
 msgid "       --user=USER               set both ftp and http user to USER.\n"
-msgstr ""
+msgstr "       --user=USUÁRIO            define o usuário para HTTP e FTP.\n"
 
-#: src/main.c:476
+#: src/main.c:499
 msgid ""
 "       --password=PASS           set both ftp and http password to PASS.\n"
 msgstr ""
+"       --password=SENHA          define a senha a ser usada para HTTP e "
+"FTP.\n"
 
-#: src/main.c:478
+#: src/main.c:501
+#, fuzzy
 msgid "       --ask-password            prompt for passwords.\n"
 msgstr ""
+"       --password=SENHA          define a senha a ser usada para HTTP e "
+"FTP.\n"
 
-#: src/main.c:482
-#, fuzzy
+#: src/main.c:505
 msgid "Directories:\n"
-msgstr "Diret�rio   "
+msgstr "Diretórios:\n"
 
-#: src/main.c:484
+#: src/main.c:507
 msgid "  -nd, --no-directories           don't create directories.\n"
-msgstr ""
+msgstr "  -nd, --no-directories           não cria diretórios.\n"
 
-#: src/main.c:486
+#: src/main.c:509
 msgid "  -x,  --force-directories        force creation of directories.\n"
-msgstr ""
+msgstr "  -x,  --force-directories        força a criação de diretórios.\n"
 
-#: src/main.c:488
+#: src/main.c:511
 msgid "  -nH, --no-host-directories      don't create host directories.\n"
-msgstr ""
+msgstr "  -nH, --no-host-directories      não cria diretórios do servidor.\n"
 
-#: src/main.c:490
+#: src/main.c:513
 msgid "       --protocol-directories     use protocol name in directories.\n"
 msgstr ""
+"       --protocol-directories     usa o nome do protocolo nos diretórios.\n"
 
-#: src/main.c:492
+#: src/main.c:515
 msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
-msgstr ""
+msgstr "  -P,  --directory-prefix=PREFIXO  salva os arquivos em PREFIXO/...\n"
 
-#: src/main.c:494
+#: src/main.c:517
 msgid ""
 "       --cut-dirs=NUMBER          ignore NUMBER remote directory "
 "components.\n"
 msgstr ""
+"       --cut-dirs=QTD             ignora QTD componentes do diretório "
+"remoto.\n"
 
-#: src/main.c:498
+#: src/main.c:521
 msgid "HTTP options:\n"
-msgstr ""
+msgstr "Opções HTTP:\n"
 
-#: src/main.c:500
+#: src/main.c:523
 msgid "       --http-user=USER        set http user to USER.\n"
-msgstr ""
+msgstr "       --http-user=USUÁRIO     define o usuário do HTTP.\n"
 
-#: src/main.c:502
+#: src/main.c:525
 msgid "       --http-password=PASS    set http password to PASS.\n"
-msgstr ""
+msgstr "       --http-password=SENHA   define a senha a usar para HTTP.\n"
 
-#: src/main.c:504
+#: src/main.c:527
 msgid "       --no-cache              disallow server-cached data.\n"
 msgstr ""
+"       --no-cache              desautoriza dados em cache do servidor.\n"
+
+#: src/main.c:529
+msgid ""
+"       --default-page=NAME     Change the default page name (normally\n"
+"                               this is `index.html'.).\n"
+msgstr ""
 
-#: src/main.c:506
+#: src/main.c:532
 msgid ""
 "  -E,  --html-extension        save HTML documents with `.html' extension.\n"
 msgstr ""
+"  -E,  --html-extension        salva os documentos HTML com a extensão \"."
+"html\".\n"
 
-#: src/main.c:508
+#: src/main.c:534
 msgid "       --ignore-length         ignore `Content-Length' header field.\n"
 msgstr ""
+"       --ignore-length         ignora o campo de cabeçalho `Content-"
+"Length'.\n"
 
-#: src/main.c:510
+#: src/main.c:536
 msgid "       --header=STRING         insert STRING among the headers.\n"
-msgstr ""
+msgstr "       --header=TEXTO          insere TEXTO em meio aos cabeçalhos.\n"
 
-#: src/main.c:512
+#: src/main.c:538
 msgid "       --max-redirect          maximum redirections allowed per page.\n"
 msgstr ""
+"       --max-redirect          máximo redirecionamentos permitido por "
+"página.\n"
 
-#: src/main.c:514
+#: src/main.c:540
 msgid "       --proxy-user=USER       set USER as proxy username.\n"
-msgstr ""
+msgstr "       --proxy-user=USUÁRIO    define o nome de usuário do proxy.\n"
 
-#: src/main.c:516
+#: src/main.c:542
 msgid "       --proxy-password=PASS   set PASS as proxy password.\n"
-msgstr ""
+msgstr "       --proxy-password=SENHA  define a senha para o proxy.\n"
 
-#: src/main.c:518
+#: src/main.c:544
 msgid ""
 "       --referer=URL           include `Referer: URL' header in HTTP "
 "request.\n"
 msgstr ""
+"       --referer=URL           inclui o cabeçalho \"Referer: URL\" na "
+"requisição\n"
+"                                 HTTP.\n"
 
-#: src/main.c:520
+#: src/main.c:546
 msgid "       --save-headers          save the HTTP headers to file.\n"
-msgstr ""
+msgstr "       --save-headers          salva os cabeçalhos HTTP no arquivo.\n"
 
-#: src/main.c:522
+#: src/main.c:548
 msgid ""
 "  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
 msgstr ""
+"  -U,  --user-agent=AGENTE     se identifica como AGENTE em vez de Wget/"
+"VERSÃO.\n"
 
-#: src/main.c:524
+#: src/main.c:550
 msgid ""
 "       --no-http-keep-alive    disable HTTP keep-alive (persistent "
 "connections).\n"
 msgstr ""
+"       --no-http-keep-alive    desabilita o \"HTTP keep-alive\" (para "
+"conexões\n"
+"                                 persistentes).\n"
 
-#: src/main.c:526
+#: src/main.c:552
 msgid "       --no-cookies            don't use cookies.\n"
-msgstr ""
+msgstr "       --no-cookies            não usa cookies.\n"
 
-#: src/main.c:528
+#: src/main.c:554
 msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
 msgstr ""
+"       --load-cookies=ARQUIVO  carrega os cookies do ARQUIVO antes da "
+"sessão.\n"
 
-#: src/main.c:530
+#: src/main.c:556
 msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
 msgstr ""
+"       --save-cookies=ARQUIVO  salva os cookies no ARQUIVO depois da "
+"sessão.\n"
 
-#: src/main.c:532
+#: src/main.c:558
 msgid ""
 "       --keep-session-cookies  load and save session (non-permanent) "
 "cookies.\n"
 msgstr ""
+"       --keep-session-cookies  carrega e salva os cookies (não permanentes) "
+"da\n"
+"                                 sessão.\n"
 
-#: src/main.c:534
+#: src/main.c:560
 msgid ""
 "       --post-data=STRING      use the POST method; send STRING as the "
 "data.\n"
 msgstr ""
+"       --post-data=TEXTO       usa o método POST; envia o TEXTO como dados.\n"
 
-#: src/main.c:536
+#: src/main.c:562
 msgid ""
 "       --post-file=FILE        use the POST method; send contents of FILE.\n"
 msgstr ""
+"       --post-file=ARQUIVO     usa o método POST; envia o conteúdo de "
+"ARQUIVO.\n"
 
-#: src/main.c:538
+#: src/main.c:564
 msgid ""
 "       --content-disposition   honor the Content-Disposition header when\n"
 "                               choosing local file names (EXPERIMENTAL).\n"
 msgstr ""
+"       --content-disposition   honra o cabeçalho Content-Disposition ao\n"
+"                                 escolher os nomes do arquivo local\n"
+"                                 (EXPERIMENTAL).\n"
 
-#: src/main.c:541
+#: src/main.c:567
 msgid ""
 "       --auth-no-challenge     Send Basic HTTP authentication information\n"
 "                               without first waiting for the server's\n"
 "                               challenge.\n"
 msgstr ""
+"       --auth-no-challenge     Envia informações básicas de autenticação "
+"HTTP\n"
+"                                 sem antes aguardar pelo desafio do "
+"servidor.\n"
 
-#: src/main.c:548
+#: src/main.c:574
 msgid "HTTPS (SSL/TLS) options:\n"
-msgstr ""
+msgstr "Opções HTTPS (SSL/TLS):\n"
 
-#: src/main.c:550
+#: src/main.c:576
 msgid ""
 "       --secure-protocol=PR     choose secure protocol, one of auto, SSLv2,\n"
 "                                SSLv3, and TLSv1.\n"
 msgstr ""
+"       --secure-protocol=PR     escolhe entre um protocolo de segurança: "
+"auto\n"
+"                                  (automático), SSLv2, SSLv3 e TLSv1.\n"
 
-#: src/main.c:553
+#: src/main.c:579
 msgid ""
 "       --no-check-certificate   don't validate the server's certificate.\n"
 msgstr ""
+"       --no-check-certificate   não valida o certificado do servidor.\n"
 
-#: src/main.c:555
+#: src/main.c:581
 msgid "       --certificate=FILE       client certificate file.\n"
-msgstr ""
+msgstr "       --certificate=ARQUIVO    o arquivo de certificado do cliente.\n"
 
-#: src/main.c:557
+#: src/main.c:583
 msgid "       --certificate-type=TYPE  client certificate type, PEM or DER.\n"
 msgstr ""
+"       --certificate-type=TIPO  tipo de certificado do client: PEM ou DER.\n"
 
-#: src/main.c:559
+#: src/main.c:585
 msgid "       --private-key=FILE       private key file.\n"
-msgstr ""
+msgstr "       --private-key=ARQUIVO    arquivo de chave privada.\n"
 
-#: src/main.c:561
+#: src/main.c:587
 msgid "       --private-key-type=TYPE  private key type, PEM or DER.\n"
-msgstr ""
+msgstr "       --private-key-type=TIPO  tipo de chave privada: PEM ou DER.\n"
 
-#: src/main.c:563
+#: src/main.c:589
 msgid "       --ca-certificate=FILE    file with the bundle of CA's.\n"
-msgstr ""
+msgstr "       --ca-certificate=ARQUIVO arquivo com o maço de CA's.\n"
 
-#: src/main.c:565
+#: src/main.c:591
 msgid ""
 "       --ca-directory=DIR       directory where hash list of CA's is "
 "stored.\n"
 msgstr ""
+"       --ca-directory=DIR       diretório onde está a lista de hash das "
+"CA's.\n"
 
-#: src/main.c:567
+#: src/main.c:593
 msgid ""
 "       --random-file=FILE       file with random data for seeding the SSL "
 "PRNG.\n"
 msgstr ""
+"       --random-file=ARQUIVO    arquivo com dados aleatórios para semear o "
+"SSL\n"
+"                                  PRNG.\n"
 
-#: src/main.c:569
+#: src/main.c:595
 msgid ""
 "       --egd-file=FILE          file naming the EGD socket with random "
 "data.\n"
 msgstr ""
+"       --egd-file=ARQUIVO       arquivo nomeando o soquete EGD com dados\n"
+"                                  aleatórios.\n"
 
-#: src/main.c:574
+#: src/main.c:600
 msgid "FTP options:\n"
+msgstr "Opções FTP:\n"
+
+#: src/main.c:603
+msgid ""
+"       --ftp-stmlf             Use Stream_LF format for all binary FTP "
+"files.\n"
 msgstr ""
 
-#: src/main.c:576
+#: src/main.c:606
 msgid "       --ftp-user=USER         set ftp user to USER.\n"
-msgstr ""
+msgstr "       --ftp-user=USUÁRIO      define o usuário de FTP.\n"
 
-#: src/main.c:578
+#: src/main.c:608
 msgid "       --ftp-password=PASS     set ftp password to PASS.\n"
-msgstr ""
+msgstr "       --ftp-password=SENHA    define a senha para FTP.\n"
 
-#: src/main.c:580
+#: src/main.c:610
 msgid "       --no-remove-listing     don't remove `.listing' files.\n"
-msgstr ""
+msgstr "       --no-remove-listing     não exclui os arquivos \".listing\".\n"
 
-#: src/main.c:582
+#: src/main.c:612
 msgid "       --no-glob               turn off FTP file name globbing.\n"
 msgstr ""
+"       --no-glob               desativa a pesquisa aproximada (glob search)\n"
+"                                 para nomes de arquivo no FTP.\n"
 
-#: src/main.c:584
+#: src/main.c:614
 msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
 msgstr ""
+"       --no-passive-ftp        desabilita o modo de transferência \"passivo"
+"\".\n"
 
-#: src/main.c:586
+#: src/main.c:616
 msgid ""
 "       --retr-symlinks         when recursing, get linked-to files (not "
 "dir).\n"
 msgstr ""
+"       --retr-symlinks         em uma recursão, obtém arquivos apontados "
+"por\n"
+"                                 ligação (não vale para diretórios).\n"
 
-#: src/main.c:588
+#: src/main.c:618
 msgid "       --preserve-permissions  preserve remote file permissions.\n"
 msgstr ""
+"       --preserve-permissions  preserva as permissões do arquivo remoto.\n"
 
-#: src/main.c:592
+#: src/main.c:622
 msgid "Recursive download:\n"
-msgstr ""
+msgstr "Download recursivo:\n"
 
-#: src/main.c:594
+#: src/main.c:624
 msgid "  -r,  --recursive          specify recursive download.\n"
-msgstr ""
+msgstr "  -r,  --recursive          especifica como download recursivo.\n"
 
-#: src/main.c:596
+#: src/main.c:626
 msgid ""
 "  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
 "infinite).\n"
 msgstr ""
+"  -l,  --level=NÚMERO       nível máximo da recursão (inf ou 0 para "
+"infinito).\n"
 
-#: src/main.c:598
+#: src/main.c:628
 msgid ""
 "       --delete-after       delete files locally after downloading them.\n"
 msgstr ""
+"       --delete-after       exclui os arquivos localmente depois de baixá-"
+"los.\n"
 
-#: src/main.c:600
+#: src/main.c:630
+#, fuzzy
 msgid ""
-"  -k,  --convert-links      make links in downloaded HTML point to local "
-"files.\n"
+"  -k,  --convert-links      make links in downloaded HTML or CSS point to\n"
+"                            local files.\n"
+msgstr ""
+"  -k,  --convert-links      faz os links no HTML baixado apontarem para\n"
+"                              os arquivos locais.\n"
+
+#: src/main.c:634
+#, fuzzy
+msgid ""
+"  -K,  --backup-converted   before converting file X, back up as X_orig.\n"
 msgstr ""
+"  -K,  --backup-converted   antes de converter o arquivo X, faz uma cópia "
+"de\n"
+"                              de segurança como X.orig.\n"
 
-#: src/main.c:602
+#: src/main.c:637
 msgid ""
 "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
 msgstr ""
+"  -K,  --backup-converted   antes de converter o arquivo X, faz uma cópia "
+"de\n"
+"                              de segurança como X.orig.\n"
 
-#: src/main.c:604
+#: src/main.c:640
 msgid ""
 "  -m,  --mirror             shortcut for -N -r -l inf --no-remove-listing.\n"
 msgstr ""
+"  -m,  --mirror             atalho para -N -r -l inf --no-remove-listing.\n"
 
-#: src/main.c:606
+#: src/main.c:642
 msgid ""
 "  -p,  --page-requisites    get all images, etc. needed to display HTML "
 "page.\n"
 msgstr ""
+"  -p,  --page-requisites    obtém todas as imagens, etc. necessárias para\n"
+"                              exibir a página HTML.\n"
 
-#: src/main.c:608
+#: src/main.c:644
 msgid ""
 "       --strict-comments    turn on strict (SGML) handling of HTML "
 "comments.\n"
 msgstr ""
+"       --strict-comments    ativa a manipulação estrita (SGML) dos "
+"comentários\n"
+"                              HTML.\n"
 
-#: src/main.c:612
+#: src/main.c:648
 msgid "Recursive accept/reject:\n"
-msgstr ""
+msgstr "Aceitação/Recusa de recursão:\n"
 
-#: src/main.c:614
+#: src/main.c:650
 msgid ""
 "  -A,  --accept=LIST               comma-separated list of accepted "
 "extensions.\n"
 msgstr ""
+"  -A,  --accept=LISTA              lista separada por vírgulas das "
+"extensões\n"
+"                                     aceitas.\n"
 
-#: src/main.c:616
+#: src/main.c:652
 msgid ""
 "  -R,  --reject=LIST               comma-separated list of rejected "
 "extensions.\n"
 msgstr ""
+"  -R,  --reject=LISTA              lista separada por vírgulas das "
+"extensões\n"
+"                                     rejeitadas.\n"
 
-#: src/main.c:618
+#: src/main.c:654
 msgid ""
 "  -D,  --domains=LIST              comma-separated list of accepted "
 "domains.\n"
 msgstr ""
+"  -D,  --domains=LISTA             lista separada por vírgulas dos domínios\n"
+"                                     aceitos.\n"
 
-#: src/main.c:620
+#: src/main.c:656
 msgid ""
 "       --exclude-domains=LIST      comma-separated list of rejected "
 "domains.\n"
 msgstr ""
+"       --exclude-domains=LISTA     lista separada por vírgulas dos domínios\n"
+"                                     rejeitados.\n"
 
-#: src/main.c:622
+#: src/main.c:658
 msgid ""
 "       --follow-ftp                follow FTP links from HTML documents.\n"
 msgstr ""
+"       --follow-ftp                segue os links FTP dos documentos HTML.\n"
 
-#: src/main.c:624
+#: src/main.c:660
 msgid ""
 "       --follow-tags=LIST          comma-separated list of followed HTML "
 "tags.\n"
 msgstr ""
+"       --follow-tags=LISTA         lista separada por vírgulas das tags "
+"HTML\n"
+"                                     permitidas.\n"
 
-#: src/main.c:626
+#: src/main.c:662
 msgid ""
 "       --ignore-tags=LIST          comma-separated list of ignored HTML "
 "tags.\n"
 msgstr ""
+"       --ignore-tags=LISTA         lista separada por vírgulas das tags "
+"HTML\n"
+"                                     ignoradas.\n"
 
-#: src/main.c:628
+#: src/main.c:664
 msgid ""
 "  -H,  --span-hosts                go to foreign hosts when recursive.\n"
 msgstr ""
+"  -H,  --span-hosts                vai para máquinas estrangeiras ao "
+"recursar.\n"
 
-#: src/main.c:630
+#: src/main.c:666
 msgid "  -L,  --relative                  follow relative links only.\n"
-msgstr ""
+msgstr "  -L,  --relative                  segue apenas links relativos.\n"
 
-#: src/main.c:632
+#: src/main.c:668
 msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
-msgstr ""
+msgstr "  -I,  --include-directories=LISTA  lista dos diretórios permitidos.\n"
 
-#: src/main.c:634
+#: src/main.c:670
 msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
-msgstr ""
+msgstr "  -X,  --exclude-directories=LISTA  lista dos diretórios excluídos.\n"
 
-#: src/main.c:636
+#: src/main.c:672
 msgid ""
 "  -np, --no-parent                 don't ascend to the parent directory.\n"
-msgstr ""
+msgstr "  -np, --no-parent                 não subir ao diretório-pai.\n"
 
-#: src/main.c:640
+#: src/main.c:676
 msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
-msgstr "Relatos de bugs e sugest�es para <bug-wget@gnu.org>.\n"
+msgstr "Relatos de problemas e sugestões para <bug-wget@gnu.org>.\n"
 
-#: src/main.c:645
+#: src/main.c:681
 #, c-format
 msgid "GNU Wget %s, a non-interactive network retriever.\n"
 msgstr ""
-"GNU Wget %s, um programa n�o interativo para buscar arquivos da rede.\n"
+"GNU Wget %s, um programa não interativo para baixar arquivos da rede.\n"
 
-#: src/main.c:685
+#: src/main.c:721
 #, c-format
 msgid "Password for user %s: "
 msgstr ""
 
-#: src/main.c:687
+#: src/main.c:723
 #, c-format
 msgid "Password: "
 msgstr ""
 
+#: src/main.c:773
+msgid "Wgetrc: "
+msgstr ""
+
+#: src/main.c:774
+msgid "Locale: "
+msgstr ""
+
+#: src/main.c:775
+msgid "Compile: "
+msgstr ""
+
+#: src/main.c:776
+msgid "Link: "
+msgstr ""
+
 #. TRANSLATORS: When available, an actual copyright character
 #. (cirle-c) should be used in preference to "(C)".
-#: src/main.c:697
-#, fuzzy
+#: src/main.c:836
 msgid "Copyright (C) 2008 Free Software Foundation, Inc.\n"
-msgstr "Copyright (C) 2003 Free Software Foundation, Inc.\n"
+msgstr "Copyright (C) 2008 Free Software Foundation, Inc.\n"
 
-#: src/main.c:699
+#: src/main.c:838
 msgid ""
 "License GPLv3+: GNU GPL version 3 or later\n"
 "<http://www.gnu.org/licenses/gpl.html>.\n"
 "This is free software: you are free to change and redistribute it.\n"
 "There is NO WARRANTY, to the extent permitted by law.\n"
 msgstr ""
+"Licença GPLv3+: GNU GPL versão 3 ou posterior\n"
+"<http://www.gnu.org/licenses/gpl.html>.\n"
+"Este é um software livre: você é livre para alterá-lo e redistribui-lo.\n"
+"Não há GARANTIAS, na extensão máxima permitida por lei.\n"
 
 #. TRANSLATORS: When available, please use the proper diacritics for
 #. names such as this one. See en_US.po for reference.
-#: src/main.c:706
+#: src/main.c:845
 msgid ""
 "\n"
 "Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
