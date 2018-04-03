#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:516
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr "%s: Aviso: resolução do endereço local não resultou em FQDN!\n"

#: src/host.c:544
msgid "Host not found"
msgstr "Host não encontrado"

#: src/host.c:546
msgid "Unknown error"
msgstr "Erro desconhecido"

# , c-format
#: src/html.c:615 src/html.c:617
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Índice de /%s em %s:%d"

#: src/html.c:639
msgid "time unknown       "
msgstr "horário desconhecido "

#: src/html.c:643
msgid "File        "
msgstr "Arquivo     "

#: src/html.c:646
msgid "Directory   "
msgstr "Diretório   "

#: src/html.c:649
msgid "Link        "
msgstr "Link        "

#: src/html.c:652
msgid "Not sure    "
msgstr "Sem certeza "

# , c-format
#: src/html.c:670
#, c-format
msgid " (%s bytes)"
msgstr " (%s bytes)"

#: src/http.c:508
msgid "Failed writing HTTP request.\n"
msgstr "Falha na requisição HTTP.\n"

# , c-format
#: src/http.c:512
#, fuzzy, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s requisição enviada, buscando headers... "

#: src/http.c:551
msgid "End of file while parsing headers.\n"
msgstr "Fim de arquivo durante a leitura dos headers.\n"

# , c-format
#: src/http.c:562
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Erro de leitura (%s) nos headers.\n"

#: src/http.c:602
msgid "No data received"
msgstr ""

#: src/http.c:604
msgid "Malformed status line"
msgstr ""

#: src/http.c:609
msgid "(no description)"
msgstr "(sem descrição)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:693
msgid "Authorization failed.\n"
msgstr ""

#: src/http.c:700
msgid "Unknown authentication scheme.\n"
msgstr ""

# , c-format
#: src/http.c:783
#, c-format
msgid "Location: %s%s\n"
msgstr "Localização: %s%s\n"

#: src/http.c:784 src/http.c:809
msgid "unspecified"
msgstr "nao especificado"

#: src/http.c:785
msgid " [following]"
msgstr " [seguinte]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:799
msgid "Length: "
msgstr "Tamanho: "

# , c-format
#: src/http.c:804
#, c-format
msgid " (%s to go)"
msgstr " (%s para o fim)"

#: src/http.c:809
msgid "ignored"
msgstr "ignorado"

#: src/http.c:912
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Aviso: wildcards não suportados para HTTP.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:933
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Arquivo `%s' já presente, não será baixado.\n"

# , c-format
#: src/http.c:1099
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Não foi possível escrever em `%s' (%s).\n"

# , c-format
#: src/http.c:1110
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERRO: Redireção (%d) sem Location.\n"

# , c-format
#: src/http.c:1135
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERRO %d: %s.\n"

#: src/http.c:1148
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Header Last-modified não recebido -- time-stamps desligados.\n"

#: src/http.c:1156
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Header Last-modified inválido -- time-stamp ignorado.\n"

#: src/http.c:1191
msgid "Remote file is newer, retrieving.\n"
msgstr "Arquivo remoto é mais novo, buscando.\n"

# , c-format
#: src/http.c:1226
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' recebido [%ld/%ld]\n"
"\n"

# , c-format
#: src/http.c:1274
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Conexão fechada no byte %ld. "

# , c-format
#: src/http.c:1282
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - `%s' recebido [%ld/%ld])\n"
"\n"

# , c-format
#: src/http.c:1302
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Conexão fechada no byte %ld/%ld. "

# , c-format
#: src/http.c:1313
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Erro de leitura no byte %ld (%s)."

# , c-format
#: src/http.c:1321
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Erro de leitura no byte %ld/%ld (%s)."

# , c-format
#: src/init.c:329 src/netrc.c:260
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Não foi possível ler %s (%s).\n"

# , c-format
#: src/init.c:350 src/init.c:356
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Erro em %s na linha %d.\n"

# , c-format
#: src/init.c:387
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Aviso: os arquivos wgetrc do sistema e do usuário apontam para `%s'.\n"

# , c-format
#: src/init.c:475
#, fuzzy, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: Comando desconhecido `%s', valor `%s'.\n"

# , c-format
#: src/init.c:497
#, fuzzy, c-format
msgid "%s: Out of memory.\n"
msgstr "%s: %s: Memória insuficiente.\n"

#: src/init.c:503
#, fuzzy, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: Aviso: não foi possível resolver endereço IP local.\n"

# , c-format
#: src/init.c:531
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Por favor especifique on ou off.\n"

# , c-format
#: src/init.c:575
#, fuzzy, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Por favor especifique on ou off.\n"

# , c-format
#: src/init.c:594 src/init.c:851 src/init.c:873 src/init.c:937
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Especificação inválida `%s'\n"

# , c-format
#: src/init.c:707 src/init.c:729 src/init.c:751 src/init.c:777
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Especificação inválida `%s'\n"

# , c-format
#: src/main.c:105
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Uso: %s [OPÇÃO]... [URL]...\n"

# , c-format
#: src/main.c:113
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr ""
"GNU Wget %s, um programa não interativo para buscar arquivos da rede.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:118
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Argumentos obrigatórios para opções longas são também\n"
"obrigatórios para opções curtas.\n"
"\n"

#: src/main.c:121
#, fuzzy
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
"  -h,  --help              print this help.\n"
"  -b,  --background        go to background after startup.\n"
"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
"\n"
msgstr ""
"Início:\n"
