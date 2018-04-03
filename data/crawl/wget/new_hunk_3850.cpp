"Content-Transfer-Encoding: 8-bit\n"

# , c-format
#: src/ftp-ls.c:698 src/ftp-ls.c:700
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Índice de /%s em %s:%d"

#: src/ftp-ls.c:722
msgid "time unknown       "
msgstr "horário desconhecido "

#: src/ftp-ls.c:726
msgid "File        "
msgstr "Arquivo     "

#: src/ftp-ls.c:729
msgid "Directory   "
msgstr "Diretório   "

#: src/ftp-ls.c:732
msgid "Link        "
msgstr "Link        "

#: src/ftp-ls.c:735
msgid "Not sure    "
msgstr "Sem certeza "

# , c-format
#: src/ftp-ls.c:753
#, c-format
msgid " (%s bytes)"
msgstr " (%s bytes)"

# , c-format
#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:152 src/http.c:582
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Conectando-se a %s:%hu... "

# , c-format
#: src/ftp.c:174 src/ftp.c:520 src/http.c:599
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Conexão para %s:%hu recusada.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:195 src/http.c:610
msgid "connected!\n"
msgstr "conectado!\n"

# , c-format
#: src/ftp.c:196
#, c-format
msgid "Logging in as %s ... "
msgstr "Logando como %s ... "

#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:289 src/ftp.c:314 src/ftp.c:410
#: src/ftp.c:462 src/ftp.c:556 src/ftp.c:629 src/ftp.c:677 src/ftp.c:725
msgid "Error in server response, closing control connection.\n"
msgstr "Erro na resposta do servidor, fechando a conexão de controle.\n"

#: src/ftp.c:213
msgid "Error in server greeting.\n"
msgstr "Erro na saudação do servidor.\n"

#: src/ftp.c:221 src/ftp.c:323 src/ftp.c:419 src/ftp.c:471 src/ftp.c:566
#: src/ftp.c:639 src/ftp.c:687 src/ftp.c:735
msgid "Write failed, closing control connection.\n"
msgstr "Falha de escrita, fechando a conexão de controle.\n"

#: src/ftp.c:228
msgid "The server refuses login.\n"
msgstr "O servidor recusou o login.\n"

#: src/ftp.c:235
msgid "Login incorrect.\n"
msgstr "Login incorreto.\n"

#: src/ftp.c:242
msgid "Logged in!\n"
msgstr "Logado!\n"

#: src/ftp.c:267
msgid "Server error, can't determine system type.\n"
msgstr ""

#: src/ftp.c:277 src/ftp.c:541 src/ftp.c:613 src/ftp.c:657
msgid "done.    "
msgstr "feito.   "

#: src/ftp.c:303 src/ftp.c:440 src/ftp.c:708 src/ftp.c:756 src/url.c:1432
msgid "done.\n"
msgstr "feito.\n"

# , c-format
#: src/ftp.c:331
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tipo `%c' desconhecido, fechando a conexão de controle.\n"

#: src/ftp.c:344
msgid "done.  "
msgstr "feito. "

#: src/ftp.c:350
msgid "==> CWD not needed.\n"
msgstr "==> CWD não necessário.\n"

# , c-format
#: src/ftp.c:426
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Diretório `%s' não encontrado.\n"
"\n"

#. do not CWD
#: src/ftp.c:444
msgid "==> CWD not required.\n"
msgstr "==> CWD não requerido.\n"

#: src/ftp.c:478
msgid "Cannot initiate PASV transfer.\n"
msgstr "Não foi possível iniciar transferência PASV.\n"

#: src/ftp.c:482
msgid "Cannot parse PASV response.\n"
msgstr "Não foi possível entender resposta do comando PASV.\n"

# , c-format
#: src/ftp.c:496
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Tentando conectar-se a %s:%hu.\n"

# , c-format
#: src/ftp.c:583
#, c-format
msgid "Bind error (%s).\n"
msgstr "Erro no bind (%s).\n"

#: src/ftp.c:599
msgid "Invalid PORT.\n"
msgstr "PORT inválido.\n"

#: src/ftp.c:646
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST falhou, recomeçando do zero.\n"

# , c-format
#: src/ftp.c:695
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Arquivo `%s' não encontrado.\n"
"\n"

# , c-format
#: src/ftp.c:743
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Arquivo ou diretório `%s' não encontrado.\n"
"\n"

# , c-format
#: src/ftp.c:819 src/ftp.c:826
#, c-format
msgid "Length: %s"
msgstr "Tamanho: %s"

# , c-format
#: src/ftp.c:821 src/ftp.c:828
#, c-format
msgid " [%s to go]"
msgstr " [%s para terminar]"

#: src/ftp.c:830
msgid " (unauthoritative)\n"
msgstr " (sem autoridade)\n"

# , c-format
#: src/ftp.c:856
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, fechando conexão de controle.\n"

# , c-format
#: src/ftp.c:864
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Conexão de dados: %s; "

#: src/ftp.c:881
msgid "Control connection closed.\n"
msgstr "Conexão de controle fechada.\n"

#: src/ftp.c:899
msgid "Data transfer aborted.\n"
msgstr "Transferência dos dados abortada.\n"

# , c-format
#: src/ftp.c:963
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Arquivo `%s' já existente, não será baixado.\n"

# , c-format
#: src/ftp.c:1024 src/http.c:1358
#, c-format, ycp-format
msgid "(try:%2d)"
msgstr "(tentativa:%2d)"

# , c-format
#: src/ftp.c:1088 src/http.c:1585
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' recebido [%ld]\n"
"\n"

# , c-format
#: src/ftp.c:1130 src/main.c:771 src/recur.c:505 src/retr.c:580
#, c-format
msgid "Removing %s.\n"
msgstr "Removendo %s.\n"

# , c-format
#: src/ftp.c:1171
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Usando `%s' como arquivo temporário de listagem.\n"

# , c-format
#: src/ftp.c:1183
#, c-format
msgid "Removed `%s'.\n"
msgstr "Removido `%s'.\n"

# , c-format
#: src/ftp.c:1219
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Nível de recursão %d excede nível máximo %d.\n"

#: src/ftp.c:1271 src/http.c:1512
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""

#: src/ftp.c:1279
msgid "Cannot compare sizes, remote system is VMS.\n"
msgstr ""

# , c-format
#: src/ftp.c:1285 src/http.c:1520
#, fuzzy, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Os tamanhos não são iguais (local %ld), baixando.\n"

#: src/ftp.c:1303
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Nome inválido do link simbólico, ignorando.\n"

# , c-format
#: src/ftp.c:1320
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"Link simbólico já está correto %s -> %s\n"
"\n"

# , c-format
#: src/ftp.c:1328
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Criando link simbólico %s -> %s\n"

# , c-format
#: src/ftp.c:1339
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Links simbólicos não suportados, %s será ignorado.\n"

# , c-format
#: src/ftp.c:1351
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Ignorando diretório `%s'.\n"

# , c-format
#: src/ftp.c:1360
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipo de arquivo desconhecido/não suportado.\n"

# , c-format
#: src/ftp.c:1377
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: horário (timestamp) inválido.\n"

# , c-format
#: src/ftp.c:1398
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""
"Não serão buscados diretórios, pois o nível de recursão é %d (max %d).\n"

# , c-format
#: src/ftp.c:1437
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Não descendo para `%s', pois está excluído/não incluído.\n"

# , c-format
#: src/ftp.c:1482
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Rejeitando `%s'.\n"
