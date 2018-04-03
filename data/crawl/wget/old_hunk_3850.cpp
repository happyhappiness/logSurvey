"Content-Transfer-Encoding: 8-bit\n"

# , c-format
#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:147 src/http.c:346
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Conectando-se a %s:%hu... "

# , c-format
#: src/ftp.c:169 src/ftp.c:411 src/http.c:363
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Conex�o para %s:%hu recusada.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:190 src/http.c:374
msgid "connected!\n"
msgstr "conectado!\n"

# , c-format
#: src/ftp.c:191
#, c-format
msgid "Logging in as %s ... "
msgstr "Logando como %s ... "

#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
msgid "Error in server response, closing control connection.\n"
msgstr "Erro na resposta do servidor, fechando a conex�o de controle.\n"

#: src/ftp.c:208
msgid "Error in server greeting.\n"
msgstr "Erro na sauda��o do servidor.\n"

#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
msgid "Write failed, closing control connection.\n"
msgstr "Falha de escrita, fechando a conex�o de controle.\n"

#: src/ftp.c:223
msgid "The server refuses login.\n"
msgstr "O servidor recusou o login.\n"

#: src/ftp.c:230
msgid "Login incorrect.\n"
msgstr "Login incorreto.\n"

#: src/ftp.c:237
msgid "Logged in!\n"
msgstr "Logado!\n"

# , c-format
#: src/ftp.c:270
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tipo `%c' desconhecido, fechando a conex�o de controle.\n"

#: src/ftp.c:283
msgid "done.  "
msgstr "feito. "

#: src/ftp.c:289
msgid "==> CWD not needed.\n"
msgstr "==> CWD n�o necess�rio.\n"

# , c-format
#: src/ftp.c:317
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Diret�rio `%s' n�o encontrado.\n\n"

#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1431
msgid "done.\n"
msgstr "feito.\n"

#. do not CWD
#: src/ftp.c:335
msgid "==> CWD not required.\n"
msgstr "==> CWD n�o requerido.\n"

#: src/ftp.c:369
msgid "Cannot initiate PASV transfer.\n"
msgstr "N�o foi poss�vel iniciar transfer�ncia PASV.\n"

#: src/ftp.c:373
msgid "Cannot parse PASV response.\n"
msgstr "N�o foi poss�vel entender resposta do comando PASV.\n"

# , c-format
#: src/ftp.c:387
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Tentando conectar-se a %s:%hu.\n"

#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
msgid "done.    "
msgstr "feito.   "

# , c-format
#: src/ftp.c:474
#, c-format
msgid "Bind error (%s).\n"
msgstr "Erro no bind (%s).\n"

#: src/ftp.c:490
msgid "Invalid PORT.\n"
msgstr "PORT inv�lido.\n"

#: src/ftp.c:537
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST falhou, recome�ando do zero.\n"

# , c-format
#: src/ftp.c:586
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Arquivo `%s' n�o encontrado.\n\n"

# , c-format
#: src/ftp.c:634
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Arquivo ou diret�rio `%s' n�o encontrado.\n\n"

# , c-format
#: src/ftp.c:692 src/ftp.c:699
#, c-format
msgid "Length: %s"
msgstr "Tamanho: %s"

# , c-format
#: src/ftp.c:694 src/ftp.c:701
#, c-format
msgid " [%s to go]"
msgstr " [%s para terminar]"

#: src/ftp.c:703
msgid " (unauthoritative)\n"
msgstr " (sem autoridade)\n"

# , c-format
#: src/ftp.c:721
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, fechando conex�o de controle.\n"

# , c-format
#: src/ftp.c:729
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Conex�o de dados: %s; "

#: src/ftp.c:746
msgid "Control connection closed.\n"
msgstr "Conex�o de controle fechada.\n"

#: src/ftp.c:764
msgid "Data transfer aborted.\n"
msgstr "Transfer�ncia dos dados abortada.\n"

# , c-format
#: src/ftp.c:830
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Arquivo `%s' j� existente, n�o ser� baixado.\n"

# , c-format
#: src/ftp.c:896 src/http.c:922
#, c-format
msgid "(try:%2d)"
msgstr "(tentativa:%2d)"

# , c-format
#: src/ftp.c:955 src/http.c:1116
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' recebido [%ld]\n\n"

# , c-format
#: src/ftp.c:1001
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Usando `%s' como arquivo tempor�rio de listagem.\n"

# , c-format
#: src/ftp.c:1013
#, c-format
msgid "Removed `%s'.\n"
msgstr "Removido `%s'.\n"

# , c-format
#: src/ftp.c:1049
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "N�vel de recurs�o %d excede n�vel m�ximo %d.\n"

# , c-format
#: src/ftp.c:1096 src/http.c:1054
#, c-format
msgid "Local file `%s' is more recent, not retrieving.\n\n"
msgstr "Arquivo local `%s' � mais novo, n�o ser� baixado.\n\n"

# , c-format
#: src/ftp.c:1102 src/http.c:1060
#, c-format
msgid "The sizes do not match (local %ld), retrieving.\n"
msgstr "Os tamanhos n�o s�o iguais (local %ld), baixando.\n"

#: src/ftp.c:1119
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Nome inv�lido do link simb�lico, ignorando.\n"

# , c-format
#: src/ftp.c:1136
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Link simb�lico j� est� correto %s -> %s\n\n"

# , c-format
#: src/ftp.c:1144
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Criando link simb�lico %s -> %s\n"

# , c-format
#: src/ftp.c:1155
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Links simb�licos n�o suportados, %s ser� ignorado.\n"

# , c-format
#: src/ftp.c:1167
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Ignorando diret�rio `%s'.\n"

# , c-format
#: src/ftp.c:1176
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipo de arquivo desconhecido/n�o suportado.\n"

# , c-format
#: src/ftp.c:1193
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: hor�rio (timestamp) inv�lido.\n"

# , c-format
#: src/ftp.c:1213
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "N�o ser�o buscados diret�rios, pois o n�vel de recurs�o � %d (max %d).\n"

# , c-format
#: src/ftp.c:1252
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "N�o descendo para `%s', pois est� exclu�do/n�o inclu�do.\n"

# , c-format
#: src/ftp.c:1297
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Rejeitando `%s'.\n"
