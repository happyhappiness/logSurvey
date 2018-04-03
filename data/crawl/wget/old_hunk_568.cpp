msgid "memory exhausted"
msgstr ""

#: src/connect.c:198
#, c-format
msgid "%s: unable to resolve bind address %s; disabling bind.\n"
msgstr ""

#: src/connect.c:270
#, fuzzy, c-format
msgid "Connecting to %s|%s|:%d... "
msgstr "Conectando-se à %s[%s]:%hu... "

#: src/connect.c:273
#, fuzzy, c-format
msgid "Connecting to %s:%d... "
msgstr "Conectando-se a %s:%hu... "

#: src/connect.c:333
msgid "connected.\n"
msgstr "conectado!\n"

#: src/connect.c:345 src/host.c:754 src/host.c:783
#, c-format
msgid "failed: %s.\n"
msgstr "falha: %s.\n"

#: src/connect.c:369 src/http.c:1646
#, c-format
msgid "%s: unable to resolve host address %s\n"
msgstr ""

#: src/convert.c:170
#, fuzzy, c-format
msgid "Converted %d files in %s seconds.\n"
msgstr "convertendo %d arquivos em %.2f segundos.\n"

#: src/convert.c:197
#, c-format
msgid "Converting %s... "
msgstr "Convertendo %s... "

#: src/convert.c:210
msgid "nothing to do.\n"
msgstr "nada a ser feito.\n"

# , c-format
#: src/convert.c:218 src/convert.c:242
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "Não foi possível converter links em %s: %s\n"

# , c-format
#: src/convert.c:233
#, fuzzy, c-format
msgid "Unable to delete %s: %s\n"
msgstr "Não foi possível apagar `%s': %s\n"

# , c-format
#: src/convert.c:442
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "Não foi possível copiar %s como %s: %s\n"

#: src/cookies.c:443
#, c-format
msgid "Syntax error in Set-Cookie: %s at position %d.\n"
msgstr "Erro de sintax em Set-Cookie: %s na posição %d.\n"

#: src/cookies.c:686
#, c-format
msgid "Cookie coming from %s attempted to set domain to %s\n"
msgstr ""

#: src/cookies.c:1134 src/cookies.c:1252
#, fuzzy, c-format
msgid "Cannot open cookies file %s: %s\n"
msgstr "Não foi possível abrir arquivo de cookies %s: %s\n"

# , c-format
#: src/cookies.c:1289
#, fuzzy, c-format
msgid "Error writing to %s: %s\n"
msgstr "Erro ao gravar em `%s' %s.\n"

#: src/cookies.c:1292
#, fuzzy, c-format
msgid "Error closing %s: %s\n"
msgstr "Erro ao fechar `%s': %s\n"

#: src/ftp-ls.c:836
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Tipo de listagem não suportado. Tentando listagem UNIX.\n"

# , c-format
#: src/ftp-ls.c:882 src/ftp-ls.c:884
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Índice de /%s em %s:%d"

#: src/ftp-ls.c:907
#, c-format
msgid "time unknown       "
msgstr "horário desconhecido "

#: src/ftp-ls.c:911
#, c-format
msgid "File        "
msgstr "Arquivo     "

#: src/ftp-ls.c:914
#, c-format
msgid "Directory   "
msgstr "Diretório   "

#: src/ftp-ls.c:917
#, c-format
msgid "Link        "
msgstr "Link        "

#: src/ftp-ls.c:920
#, c-format
msgid "Not sure    "
msgstr "Sem certeza "

# , c-format
#: src/ftp-ls.c:938
#, c-format
msgid " (%s bytes)"
msgstr " (%s bytes)"

# , c-format
#: src/ftp.c:214
#, c-format
msgid "Length: %s"
msgstr "Tamanho: %s"

#: src/ftp.c:220 src/http.c:2199
#, c-format
msgid ", %s (%s) remaining"
msgstr ""

#: src/ftp.c:224 src/http.c:2203
#, c-format
msgid ", %s remaining"
msgstr ""

#: src/ftp.c:227
msgid " (unauthoritative)\n"
msgstr " (sem autoridade)\n"

# , c-format
#: src/ftp.c:305
#, c-format
msgid "Logging in as %s ... "
msgstr "Logando como %s ... "

#: src/ftp.c:319 src/ftp.c:365 src/ftp.c:394 src/ftp.c:446 src/ftp.c:559
#: src/ftp.c:606 src/ftp.c:635 src/ftp.c:692 src/ftp.c:753 src/ftp.c:839
#: src/ftp.c:886
msgid "Error in server response, closing control connection.\n"
msgstr "Erro na resposta do servidor, fechando a conexão de controle.\n"

#: src/ftp.c:326
msgid "Error in server greeting.\n"
msgstr "Erro na saudação do servidor.\n"

#: src/ftp.c:333 src/ftp.c:454 src/ftp.c:567 src/ftp.c:643 src/ftp.c:702
#: src/ftp.c:763 src/ftp.c:849 src/ftp.c:896
msgid "Write failed, closing control connection.\n"
msgstr "Falha de escrita, fechando a conexão de controle.\n"

#: src/ftp.c:339
msgid "The server refuses login.\n"
msgstr "O servidor recusou o login.\n"

#: src/ftp.c:345
msgid "Login incorrect.\n"
msgstr "Login incorreto.\n"

#: src/ftp.c:351
msgid "Logged in!\n"
msgstr "Logado!\n"

#: src/ftp.c:373
msgid "Server error, can't determine system type.\n"
msgstr "Erro do servidor, impossível determinar tipo de sistema.\n"

#: src/ftp.c:382 src/ftp.c:679 src/ftp.c:736 src/ftp.c:779
msgid "done.    "
msgstr "feito.   "

#: src/ftp.c:434 src/ftp.c:584 src/ftp.c:618 src/ftp.c:869 src/ftp.c:915
msgid "done.\n"
msgstr "feito.\n"

# , c-format
#: src/ftp.c:461
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tipo `%c' desconhecido, fechando a conexão de controle.\n"

#: src/ftp.c:473
msgid "done.  "
msgstr "feito. "

#: src/ftp.c:479
msgid "==> CWD not needed.\n"
msgstr "==> CWD não necessário.\n"

# , c-format
#: src/ftp.c:573
#, fuzzy, c-format
msgid ""
"No such directory %s.\n"
"\n"
msgstr ""
"Diretório `%s' não encontrado.\n"
"\n"

#: src/ftp.c:588
msgid "==> CWD not required.\n"
msgstr "==> CWD não requerido.\n"

#: src/ftp.c:649
msgid "Cannot initiate PASV transfer.\n"
msgstr "Não foi possível iniciar transferência PASV.\n"

#: src/ftp.c:653
msgid "Cannot parse PASV response.\n"
msgstr "Não foi possível entender resposta do comando PASV.\n"

#: src/ftp.c:670
#, fuzzy, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr "não foi possível conectar para %s:%hu: %s\n"

# , c-format
#: src/ftp.c:718
#, c-format
msgid "Bind error (%s).\n"
msgstr "Erro no bind (%s).\n"

#: src/ftp.c:724
msgid "Invalid PORT.\n"
msgstr "PORT inválido.\n"

#: src/ftp.c:770
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST falhou, recomeçando do zero.\n"

# , c-format
#: src/ftp.c:811
#, fuzzy, c-format
msgid "No such file %s.\n"
msgstr ""
"Arquivo `%s' não encontrado.\n"
"\n"

# , c-format
#: src/ftp.c:857
#, fuzzy, c-format
msgid ""
"No such file %s.\n"
"\n"
msgstr ""
"Arquivo `%s' não encontrado.\n"
"\n"

# , c-format
#: src/ftp.c:904
#, fuzzy, c-format
msgid ""
"No such file or directory %s.\n"
"\n"
msgstr ""
"Arquivo ou diretório `%s' não encontrado.\n"
"\n"

#: src/ftp.c:966 src/http.c:2261
#, c-format
msgid "%s has sprung into existence.\n"
msgstr ""

# , c-format
#: src/ftp.c:1018
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, fechando conexão de controle.\n"

# , c-format
#: src/ftp.c:1027
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Conexão de dados: %s; "

#: src/ftp.c:1042
msgid "Control connection closed.\n"
msgstr "Conexão de controle fechada.\n"

#: src/ftp.c:1060
msgid "Data transfer aborted.\n"
msgstr "Transferência dos dados abortada.\n"

# , c-format
#: src/ftp.c:1131
#, fuzzy, c-format
msgid "File %s already there; not retrieving.\n"
msgstr "Arquivo `%s' já existente, não será baixado.\n"

# , c-format
#: src/ftp.c:1201 src/http.c:2441
#, c-format
msgid "(try:%2d)"
msgstr "(tentativa:%2d)"

# , c-format
#: src/ftp.c:1271 src/http.c:2774
#, fuzzy, c-format
msgid ""
"%s (%s) - %s saved [%s]\n"
"\n"
msgstr ""
"%s (%s) - `%s' recebido [%ld]\n"
"\n"

# , c-format
#: src/ftp.c:1313 src/main.c:1060 src/recur.c:378 src/retr.c:860
#, c-format
msgid "Removing %s.\n"
msgstr "Removendo %s.\n"

# , c-format
#: src/ftp.c:1355
#, fuzzy, c-format
msgid "Using %s as listing tmp file.\n"
msgstr "Usando `%s' como arquivo temporário de listagem.\n"

# , c-format
#: src/ftp.c:1369
#, fuzzy, c-format
msgid "Removed %s.\n"
msgstr "Removido `%s'.\n"

# , c-format
#: src/ftp.c:1405
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Nível de recursão %d excede nível máximo %d.\n"

#: src/ftp.c:1475
#, fuzzy, c-format
msgid "Remote file no newer than local file %s -- not retrieving.\n"
msgstr "Arquivo remoto não é mais novo que o local `%s' -- ignorando.\n"

#: src/ftp.c:1482
#, fuzzy, c-format
msgid ""
"Remote file is newer than local file %s -- retrieving.\n"
"\n"
msgstr ""
"Arquivo remoto é mais que o local `%s' -- baixando.\n"
"\n"

#: src/ftp.c:1489
#, fuzzy, c-format
msgid ""
"The sizes do not match (local %s) -- retrieving.\n"
"\n"
msgstr ""
"Os tamanhos não são iguais (local %ld) -- baixando.\n"
"\n"

#: src/ftp.c:1507
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Nome inválido do link simbólico, ignorando.\n"

# , c-format
#: src/ftp.c:1524
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"Link simbólico já está correto %s -> %s\n"
"\n"

# , c-format
#: src/ftp.c:1533
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Criando link simbólico %s -> %s\n"

# , c-format
#: src/ftp.c:1543
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "Links simbólicos não suportados, %s será ignorado.\n"

# , c-format
#: src/ftp.c:1555
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "Ignorando diretório `%s'.\n"

# , c-format
#: src/ftp.c:1564
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipo de arquivo desconhecido/não suportado.\n"

# , c-format
#: src/ftp.c:1591
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: horário (timestamp) inválido.\n"

# , c-format
#: src/ftp.c:1619
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""
"Não serão buscados diretórios, pois o nível de recursão é %d (max %d).\n"

# , c-format
#: src/ftp.c:1669
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "Não descendo para `%s', pois está excluído/não incluído.\n"

# , c-format
#: src/ftp.c:1735 src/ftp.c:1749
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "Rejeitando `%s'.\n"

# , c-format
#: src/ftp.c:1772
#, fuzzy, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Erro ao gravar em `%s' %s.\n"

# , c-format
#: src/ftp.c:1814
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Nada encontrado com o padrão `%s'.\n"

# , c-format
#: src/ftp.c:1880
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "Escrito index em formato HTML para `%s' [%ld].\n"

# , c-format
#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "Escrito índice em formato HTML para `%s'.\n"

#: src/host.c:348
#, fuzzy
msgid "Unknown host"
msgstr "Erro desconhecido"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:354
msgid "Unknown error"
msgstr "Erro desconhecido"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "Resolvendo %s... "

#: src/host.c:763
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:786
msgid "failed: timed out.\n"
msgstr "falha: tempo excedido.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Não foi possível resolver link incompleto %s.\n"

#: src/html-url.c:696
#, fuzzy, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: %s: Valor inválido `%s'.\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Falha ao enviar requisição HTTP: %s.\n"

#: src/http.c:745
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1430
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1548
#, c-format
msgid "POST data file %s missing: %s\n"
msgstr ""

#: src/http.c:1632
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Reutilizando conexão para %s:%hu.\n"

#: src/http.c:1701
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Falha ao enviar requisição HTTP: %s.\n"

#: src/http.c:1721
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

# , c-format
#: src/http.c:1766
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s requisição enviada, aguardando resposta... "

#: src/http.c:1777
#, fuzzy
msgid "No data received.\n"
msgstr "Nenhum dado recebido"

# , c-format
#: src/http.c:1784
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Erro de leitura (%s) nos headers.\n"

# , c-format
#: src/http.c:1831 src/http.c:2385
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
"\n"
msgstr "Arquivo `%s' já existente, não será baixado.\n"

#: src/http.c:1985
msgid "Unknown authentication scheme.\n"
msgstr "Esquema de autenticação desconhecido.\n"

#: src/http.c:2016
msgid "Authorization failed.\n"
msgstr "Autorização falhou.\n"

#: src/http.c:2030
msgid "Malformed status line"
msgstr "Linha de status inválida"

#: src/http.c:2032
msgid "(no description)"
msgstr "(sem descrição)"

# , c-format
#: src/http.c:2098
#, c-format
msgid "Location: %s%s\n"
msgstr "Localização: %s%s\n"

#: src/http.c:2099 src/http.c:2209
msgid "unspecified"
msgstr "nao especificado"

#: src/http.c:2100
msgid " [following]"
msgstr " [seguinte]"

#: src/http.c:2156
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    O arquivo já foi completamente obtido; nada a ser feito.\n"
"\n"

#: src/http.c:2189
msgid "Length: "
msgstr "Tamanho: "

#: src/http.c:2209
msgid "ignored"
msgstr "ignorado"

#: src/http.c:2280
#, c-format
msgid "Saving to: %s\n"
msgstr ""

#: src/http.c:2361
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Aviso: wildcards não suportados para HTTP.\n"

#: src/http.c:2430
msgid "Spider mode enabled. Check if remote file exists.\n"
msgstr ""

# , c-format
#: src/http.c:2515
#, fuzzy, c-format
msgid "Cannot write to %s (%s).\n"
msgstr "Não foi possível escrever em `%s' (%s).\n"

#: src/http.c:2524
msgid "Unable to establish SSL connection.\n"
msgstr "Não foi possível estabelecer conexão segura (SSL).\n"

# , c-format
#: src/http.c:2532
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERRO: Redireção (%d) sem Location.\n"

#: src/http.c:2578
msgid "Remote file does not exist -- broken link!!!\n"
msgstr ""

# , c-format
#: src/http.c:2583
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERRO %d: %s.\n"

#: src/http.c:2600
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Header Last-modified não recebido -- time-stamps desligados.\n"

#: src/http.c:2608
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Header Last-modified inválido -- time-stamp ignorado.\n"

#: src/http.c:2638
#, fuzzy, c-format
msgid ""
"Server file no newer than local file %s -- not retrieving.\n"
"\n"
msgstr ""
"Arquivo no servidor não é mais novo que o local `%s' -- não baixando.\n"
"\n"

#: src/http.c:2646
#, fuzzy, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "Os tamanhos não são iguais (local %ld) -- baixando.\n"

#: src/http.c:2653
msgid "Remote file is newer, retrieving.\n"
msgstr "Arquivo remoto é mais novo, buscando.\n"

#: src/http.c:2669
#, fuzzy
msgid ""
"Remote file exists and could contain links to other resources -- "
"retrieving.\n"
"\n"
msgstr ""
"Arquivo remoto é mais que o local `%s' -- baixando.\n"
"\n"

#: src/http.c:2674
#, fuzzy
msgid ""
"Remote file exists but does not contain any link -- not retrieving.\n"
"\n"
msgstr "Arquivo remoto não é mais novo que o local `%s' -- ignorando.\n"

#: src/http.c:2684
msgid ""
"Remote file exists and could contain further links,\n"
"but recursion is disabled -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:2690
#, fuzzy
msgid ""
"Remote file exists.\n"
"\n"
msgstr "Arquivo remoto é mais novo, buscando.\n"

# , c-format
#: src/http.c:2743
#, fuzzy, c-format
msgid ""
"%s (%s) - %s saved [%s/%s]\n"
"\n"
msgstr ""
"%s (%s) - `%s' recebido [%ld/%ld]\n"
"\n"

#: src/http.c:2798
#, fuzzy, c-format
msgid "%s (%s) - Connection closed at byte %s. "
msgstr "%s (%s) - Conexão fechada no byte %ld. "

#: src/http.c:2813
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s (%s)."
msgstr "%s (%s) - Erro de leitura no byte %ld (%s)."

#: src/http.c:2822
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s/%s (%s). "
msgstr "%s (%s) - Erro de leitura no byte %ld/%ld (%s)."

#: src/init.c:391
#, c-format
msgid "%s: WGETRC points to %s, which doesn't exist.\n"
msgstr "%s: WGETRC aponta para %s, que não existe.\n"

#: src/init.c:454 src/netrc.c:265
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Não foi possível ler %s (%s).\n"

#: src/init.c:472
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Erro em %s na linha %d.\n"

#: src/init.c:478
#, fuzzy, c-format
msgid "%s: Syntax error in %s at line %d.\n"
msgstr "%s: Erro em %s na linha %d.\n"

# , c-format
#: src/init.c:483
#, fuzzy, c-format
msgid "%s: Unknown command %s in %s at line %d.\n"
msgstr "%s: BUG: comando desconhecido `%s', valor `%s'.\n"

#: src/init.c:528
#, fuzzy, c-format
msgid "%s: Warning: Both system and user wgetrc point to %s.\n"
msgstr ""
"%s: Aviso: os arquivos wgetrc do sistema e do usuário apontam para `%s'.\n"

#: src/init.c:681
#, fuzzy, c-format
msgid "%s: Invalid --execute command %s\n"
msgstr "%s: comando --execute é inválido `%s'\n"

#: src/init.c:726
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean %s; use `on' or `off'.\n"
msgstr "%s: %s: expressão inválida `%s', use `on' ou `off'.\n"

#: src/init.c:743
#, fuzzy, c-format
msgid "%s: %s: Invalid number %s.\n"
msgstr "%s: %s: Número inválido `%s'.\n"

#: src/init.c:974 src/init.c:993
#, fuzzy, c-format
msgid "%s: %s: Invalid byte value %s\n"
msgstr "%s: %s: Valor inválido do byte `%s'\n"

#: src/init.c:1018
#, fuzzy, c-format
msgid "%s: %s: Invalid time period %s\n"
msgstr "%s: %s: Período de tempo inválido `%s'\n"

#: src/init.c:1072 src/init.c:1162 src/init.c:1265 src/init.c:1290
#, fuzzy, c-format
msgid "%s: %s: Invalid value %s.\n"
msgstr "%s: %s: Valor inválido `%s'.\n"

#: src/init.c:1109
#, fuzzy, c-format
msgid "%s: %s: Invalid header %s.\n"
msgstr "%s: %s: Cabeçalho inválido `%s'.\n"

#: src/init.c:1175
#, fuzzy, c-format
msgid "%s: %s: Invalid progress type %s.\n"
msgstr "%s: %s: Tipo de progresso inválido `%s'.\n"

#: src/init.c:1234
#, fuzzy, c-format
msgid ""
"%s: %s: Invalid restriction %s, use [unix|windows],[lowercase|uppercase],"
"[nocontrol].\n"
msgstr "%s: %s: Restrição inválida `%s', use `unix' ou `windows'.\n"

#: src/log.c:784
#, fuzzy, c-format
msgid ""
"\n"
"%s received, redirecting output to %s.\n"
msgstr ""
"\n"
"%s recebido, redirecionando saída para `%s'.\n"

#: src/log.c:794
#, fuzzy, c-format
msgid ""
"\n"
"%s received.\n"
msgstr "Nenhum dado recebido"

#: src/log.c:795
#, c-format
msgid "%s: %s; disabling logging.\n"
msgstr "%s: %s; desabilitando log.\n"

#: src/main.c:361
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Uso: %s [OPÇÃO]... [URL]...\n"

#: src/main.c:373
#, fuzzy
msgid ""
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Argumentos obrigatórios para opções longas são também\n"
"obrigatórios para opções curtas.\n"
"\n"

#: src/main.c:375
msgid "Startup:\n"
msgstr ""

#: src/main.c:377
msgid "  -V,  --version           display the version of Wget and exit.\n"
msgstr ""

#: src/main.c:379
msgid "  -h,  --help              print this help.\n"
msgstr ""

#: src/main.c:381
msgid "  -b,  --background        go to background after startup.\n"
msgstr ""

#: src/main.c:383
msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
msgstr ""

#: src/main.c:387
msgid "Logging and input file:\n"
msgstr ""

#: src/main.c:389
msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
msgstr ""

#: src/main.c:391
msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
msgstr ""

#: src/main.c:394
msgid "  -d,  --debug               print lots of debugging information.\n"
msgstr ""

#: src/main.c:398
msgid "       --wdebug              print Watt-32 debug output.\n"
msgstr ""

#: src/main.c:401
msgid "  -q,  --quiet               quiet (no output).\n"
msgstr ""

#: src/main.c:403
msgid "  -v,  --verbose             be verbose (this is the default).\n"
msgstr ""

#: src/main.c:405
msgid ""
"  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
msgstr ""

#: src/main.c:407
msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
msgstr ""

#: src/main.c:409
msgid "  -F,  --force-html          treat input file as HTML.\n"
msgstr ""

#: src/main.c:411
msgid ""
"  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
msgstr ""

#: src/main.c:415
msgid "Download:\n"
msgstr ""

#: src/main.c:417
msgid ""
"  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
"unlimits).\n"
msgstr ""

#: src/main.c:419
msgid "       --retry-connrefused       retry even if connection is refused.\n"
msgstr ""

#: src/main.c:421
msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
msgstr ""

#: src/main.c:423
msgid ""
"  -nc, --no-clobber              skip downloads that would download to\n"
"                                 existing files.\n"
msgstr ""

#: src/main.c:426
msgid ""
"  -c,  --continue                resume getting a partially-downloaded "
"file.\n"
msgstr ""

#: src/main.c:428
msgid "       --progress=TYPE           select progress gauge type.\n"
msgstr ""

#: src/main.c:430
msgid ""
"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
"                                 local.\n"
msgstr ""

#: src/main.c:433
msgid "  -S,  --server-response         print server response.\n"
msgstr ""

#: src/main.c:435
msgid "       --spider                  don't download anything.\n"
msgstr ""

#: src/main.c:437
msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
msgstr ""

#: src/main.c:439
msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
msgstr ""

#: src/main.c:441
msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
msgstr ""

#: src/main.c:443
msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
msgstr ""

#: src/main.c:445
msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
msgstr ""

#: src/main.c:447
msgid ""
"       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
"retrieval.\n"
msgstr ""

#: src/main.c:449
msgid ""
"       --random-wait             wait from 0...2*WAIT secs between "
"retrievals.\n"
msgstr ""

#: src/main.c:451
msgid "       --no-proxy                explicitly turn off proxy.\n"
msgstr ""

#: src/main.c:453
msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
msgstr ""

#: src/main.c:455
msgid ""
"       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
"host.\n"
msgstr ""

#: src/main.c:457
msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
msgstr ""

#: src/main.c:459
msgid "       --no-dns-cache            disable caching DNS lookups.\n"
msgstr ""

#: src/main.c:461
msgid ""
"       --restrict-file-names=OS  restrict chars in file names to ones OS "
"allows.\n"
msgstr ""

#: src/main.c:463
msgid ""
"       --ignore-case             ignore case when matching files/"
"directories.\n"
msgstr ""

#: src/main.c:466
msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
msgstr ""

#: src/main.c:468
msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
msgstr ""

#: src/main.c:470
msgid ""
"       --prefer-family=FAMILY    connect first to addresses of specified "
"family,\n"
"                                 one of IPv6, IPv4, or none.\n"
msgstr ""

#: src/main.c:474
msgid "       --user=USER               set both ftp and http user to USER.\n"
msgstr ""

#: src/main.c:476
msgid ""
"       --password=PASS           set both ftp and http password to PASS.\n"
msgstr ""

#: src/main.c:478
msgid "       --ask-password            prompt for passwords.\n"
msgstr ""

#: src/main.c:482
#, fuzzy
msgid "Directories:\n"
msgstr "Diretório   "

#: src/main.c:484
msgid "  -nd, --no-directories           don't create directories.\n"
msgstr ""

#: src/main.c:486
msgid "  -x,  --force-directories        force creation of directories.\n"
msgstr ""

#: src/main.c:488
msgid "  -nH, --no-host-directories      don't create host directories.\n"
msgstr ""

#: src/main.c:490
msgid "       --protocol-directories     use protocol name in directories.\n"
msgstr ""

#: src/main.c:492
msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
msgstr ""

#: src/main.c:494
msgid ""
"       --cut-dirs=NUMBER          ignore NUMBER remote directory "
"components.\n"
msgstr ""

#: src/main.c:498
msgid "HTTP options:\n"
msgstr ""

#: src/main.c:500
msgid "       --http-user=USER        set http user to USER.\n"
msgstr ""

#: src/main.c:502
msgid "       --http-password=PASS    set http password to PASS.\n"
msgstr ""

#: src/main.c:504
msgid "       --no-cache              disallow server-cached data.\n"
msgstr ""

#: src/main.c:506
msgid ""
"  -E,  --html-extension        save HTML documents with `.html' extension.\n"
msgstr ""

#: src/main.c:508
msgid "       --ignore-length         ignore `Content-Length' header field.\n"
msgstr ""

#: src/main.c:510
msgid "       --header=STRING         insert STRING among the headers.\n"
msgstr ""

#: src/main.c:512
msgid "       --max-redirect          maximum redirections allowed per page.\n"
msgstr ""

#: src/main.c:514
msgid "       --proxy-user=USER       set USER as proxy username.\n"
msgstr ""

#: src/main.c:516
msgid "       --proxy-password=PASS   set PASS as proxy password.\n"
msgstr ""

#: src/main.c:518
msgid ""
"       --referer=URL           include `Referer: URL' header in HTTP "
"request.\n"
msgstr ""

#: src/main.c:520
msgid "       --save-headers          save the HTTP headers to file.\n"
msgstr ""

#: src/main.c:522
msgid ""
"  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
msgstr ""

#: src/main.c:524
msgid ""
"       --no-http-keep-alive    disable HTTP keep-alive (persistent "
"connections).\n"
msgstr ""

#: src/main.c:526
msgid "       --no-cookies            don't use cookies.\n"
msgstr ""

#: src/main.c:528
msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
msgstr ""

#: src/main.c:530
msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
msgstr ""

#: src/main.c:532
msgid ""
"       --keep-session-cookies  load and save session (non-permanent) "
"cookies.\n"
msgstr ""

#: src/main.c:534
msgid ""
"       --post-data=STRING      use the POST method; send STRING as the "
"data.\n"
msgstr ""

#: src/main.c:536
msgid ""
"       --post-file=FILE        use the POST method; send contents of FILE.\n"
msgstr ""

#: src/main.c:538
msgid ""
"       --content-disposition   honor the Content-Disposition header when\n"
"                               choosing local file names (EXPERIMENTAL).\n"
msgstr ""

#: src/main.c:541
msgid ""
"       --auth-no-challenge     Send Basic HTTP authentication information\n"
"                               without first waiting for the server's\n"
"                               challenge.\n"
msgstr ""

#: src/main.c:548
msgid "HTTPS (SSL/TLS) options:\n"
msgstr ""

#: src/main.c:550
msgid ""
"       --secure-protocol=PR     choose secure protocol, one of auto, SSLv2,\n"
"                                SSLv3, and TLSv1.\n"
msgstr ""

#: src/main.c:553
msgid ""
"       --no-check-certificate   don't validate the server's certificate.\n"
msgstr ""

#: src/main.c:555
msgid "       --certificate=FILE       client certificate file.\n"
msgstr ""

#: src/main.c:557
msgid "       --certificate-type=TYPE  client certificate type, PEM or DER.\n"
msgstr ""

#: src/main.c:559
msgid "       --private-key=FILE       private key file.\n"
msgstr ""

#: src/main.c:561
msgid "       --private-key-type=TYPE  private key type, PEM or DER.\n"
msgstr ""

#: src/main.c:563
msgid "       --ca-certificate=FILE    file with the bundle of CA's.\n"
msgstr ""

#: src/main.c:565
msgid ""
"       --ca-directory=DIR       directory where hash list of CA's is "
"stored.\n"
msgstr ""

#: src/main.c:567
msgid ""
"       --random-file=FILE       file with random data for seeding the SSL "
"PRNG.\n"
msgstr ""

#: src/main.c:569
msgid ""
"       --egd-file=FILE          file naming the EGD socket with random "
"data.\n"
msgstr ""

#: src/main.c:574
msgid "FTP options:\n"
msgstr ""

#: src/main.c:576
msgid "       --ftp-user=USER         set ftp user to USER.\n"
msgstr ""

#: src/main.c:578
msgid "       --ftp-password=PASS     set ftp password to PASS.\n"
msgstr ""

#: src/main.c:580
msgid "       --no-remove-listing     don't remove `.listing' files.\n"
msgstr ""

#: src/main.c:582
msgid "       --no-glob               turn off FTP file name globbing.\n"
msgstr ""

#: src/main.c:584
msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
msgstr ""

#: src/main.c:586
msgid ""
"       --retr-symlinks         when recursing, get linked-to files (not "
"dir).\n"
msgstr ""

#: src/main.c:588
msgid "       --preserve-permissions  preserve remote file permissions.\n"
msgstr ""

#: src/main.c:592
msgid "Recursive download:\n"
msgstr ""

#: src/main.c:594
msgid "  -r,  --recursive          specify recursive download.\n"
msgstr ""

#: src/main.c:596
msgid ""
"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
"infinite).\n"
msgstr ""

#: src/main.c:598
msgid ""
"       --delete-after       delete files locally after downloading them.\n"
msgstr ""

#: src/main.c:600
msgid ""
"  -k,  --convert-links      make links in downloaded HTML point to local "
"files.\n"
msgstr ""

#: src/main.c:602
msgid ""
"  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
msgstr ""

#: src/main.c:604
msgid ""
"  -m,  --mirror             shortcut for -N -r -l inf --no-remove-listing.\n"
msgstr ""

#: src/main.c:606
msgid ""
"  -p,  --page-requisites    get all images, etc. needed to display HTML "
"page.\n"
msgstr ""

#: src/main.c:608
msgid ""
"       --strict-comments    turn on strict (SGML) handling of HTML "
"comments.\n"
msgstr ""

#: src/main.c:612
msgid "Recursive accept/reject:\n"
msgstr ""

#: src/main.c:614
msgid ""
"  -A,  --accept=LIST               comma-separated list of accepted "
"extensions.\n"
msgstr ""

#: src/main.c:616
msgid ""
"  -R,  --reject=LIST               comma-separated list of rejected "
"extensions.\n"
msgstr ""

#: src/main.c:618
msgid ""
"  -D,  --domains=LIST              comma-separated list of accepted "
"domains.\n"
msgstr ""

#: src/main.c:620
msgid ""
"       --exclude-domains=LIST      comma-separated list of rejected "
"domains.\n"
msgstr ""

#: src/main.c:622
msgid ""
"       --follow-ftp                follow FTP links from HTML documents.\n"
msgstr ""

#: src/main.c:624
msgid ""
"       --follow-tags=LIST          comma-separated list of followed HTML "
"tags.\n"
msgstr ""

#: src/main.c:626
msgid ""
"       --ignore-tags=LIST          comma-separated list of ignored HTML "
"tags.\n"
msgstr ""

#: src/main.c:628
msgid ""
"  -H,  --span-hosts                go to foreign hosts when recursive.\n"
msgstr ""

#: src/main.c:630
msgid "  -L,  --relative                  follow relative links only.\n"
msgstr ""

#: src/main.c:632
msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
msgstr ""

#: src/main.c:634
msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
msgstr ""

#: src/main.c:636
msgid ""
"  -np, --no-parent                 don't ascend to the parent directory.\n"
msgstr ""

#: src/main.c:640
msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
msgstr "Relatos de bugs e sugestões para <bug-wget@gnu.org>.\n"

#: src/main.c:645
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr ""
"GNU Wget %s, um programa não interativo para buscar arquivos da rede.\n"

#: src/main.c:685
#, c-format
msgid "Password for user %s: "
msgstr ""

#: src/main.c:687
#, c-format
msgid "Password: "
msgstr ""

#. TRANSLATORS: When available, an actual copyright character
#. (cirle-c) should be used in preference to "(C)".
#: src/main.c:697
#, fuzzy
msgid "Copyright (C) 2008 Free Software Foundation, Inc.\n"
msgstr "Copyright (C) 2003 Free Software Foundation, Inc.\n"

#: src/main.c:699
msgid ""
"License GPLv3+: GNU GPL version 3 or later\n"
"<http://www.gnu.org/licenses/gpl.html>.\n"
"This is free software: you are free to change and redistribute it.\n"
"There is NO WARRANTY, to the extent permitted by law.\n"
msgstr ""

#. TRANSLATORS: When available, please use the proper diacritics for
#. names such as this one. See en_US.po for reference.
#: src/main.c:706
msgid ""
"\n"
"Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
