#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1541
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Nada encontrado com o padrão `%s'.\n"

# , c-format
#: src/ftp.c:1605
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "Escrito index em formato HTML para `%s' [%ld].\n"

# , c-format
#: src/ftp.c:1610
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Escrito índice em formato HTML para `%s'.\n"

# , c-format
#: src/getopt.c:454
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: opção `%s' é ambígua\n"

# , c-format
#: src/getopt.c:478
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: opção `--%s' não permite argumento\n"

# , c-format
#: src/getopt.c:483
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: opção `%c%s' não permite argumento\n"

# , c-format
#: src/getopt.c:498
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: opção `%s' requer um argumento\n"

# , c-format
#. --option
#: src/getopt.c:528
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: opção não reconhecida `--%s'\n"

# , c-format
#. +option or -option
#: src/getopt.c:532
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: opção não reconhecida `%c%s'\n"

# , c-format
#. 1003.2 specifies the format of this message.
#: src/getopt.c:563
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: opção ilegal -- %c\n"

# , c-format
#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: opção requer um argumento -- %c\n"

#: src/host.c:394
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: Não foi possível determinar user-id.\n"

# , c-format
#: src/host.c:406
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: Aviso: falha em uname: %s\n"

#: src/host.c:418
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: Aviso: falha em gethostname\n"

#: src/host.c:446
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: Aviso: não foi possível determinar endereço IP local.\n"

#: src/host.c:460
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr "%s: Aviso: não foi possível resolver endereço IP local.\n"

#. This gets ticked pretty often.  Karl Berry reports
#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:473
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr "%s: Aviso: resolução do endereço local não resultou em FQDN!\n"

#: src/host.c:501
msgid "Host not found"
msgstr "Host não encontrado"

#: src/host.c:503
msgid "Unknown error"
msgstr "Erro desconhecido"

#. this is fatal
#: src/http.c:549
msgid "Failed to set up an SSL context\n"
msgstr ""

#: src/http.c:555
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr ""

#: src/http.c:559 src/http.c:567
msgid "Trying without the specified certificate\n"
msgstr ""

#: src/http.c:563
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr ""

#: src/http.c:657 src/http.c:1470
msgid "Unable to establish SSL connection.\n"
msgstr ""

# , c-format
#: src/http.c:665
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Tentando conectar-se a %s:%hu.\n"

#: src/http.c:841
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Falha na requisição HTTP.\n"

# , c-format
#: src/http.c:846
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s requisição enviada, aguardando resposta... "

#: src/http.c:890
msgid "End of file while parsing headers.\n"
msgstr "Fim de arquivo durante a leitura dos headers.\n"

# , c-format
#: src/http.c:901
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Erro de leitura (%s) nos headers.\n"

#: src/http.c:941
msgid "No data received"
msgstr "Nenhum dado recebido"

#: src/http.c:943
msgid "Malformed status line"
msgstr "Linha de status inválida"

#: src/http.c:948
msgid "(no description)"
msgstr "(sem descrição)"

#: src/http.c:1066
msgid "Authorization failed.\n"
msgstr "Autorização falhou.\n"

#: src/http.c:1073
msgid "Unknown authentication scheme.\n"
msgstr "Esquema de autenticação desconhecido.\n"

# , c-format
#: src/http.c:1163
#, c-format
msgid "Location: %s%s\n"
msgstr "Localização: %s%s\n"

#: src/http.c:1164 src/http.c:1189
msgid "unspecified"
msgstr "nao especificado"

#: src/http.c:1165
msgid " [following]"
msgstr " [seguinte]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1179
msgid "Length: "
msgstr "Tamanho: "

# , c-format
#: src/http.c:1184
#, c-format
msgid " (%s to go)"
msgstr " (%s para o fim)"

#: src/http.c:1189
msgid "ignored"
msgstr "ignorado"

#: src/http.c:1290
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Aviso: wildcards não suportados para HTTP.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1311
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Arquivo `%s' já presente, não será baixado.\n"

# , c-format
#: src/http.c:1462
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Não foi possível escrever em `%s' (%s).\n"

# , c-format
#: src/http.c:1480
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERRO: Redireção (%d) sem Location.\n"

# , c-format
#: src/http.c:1505
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERRO %d: %s.\n"

#: src/http.c:1518
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Header Last-modified não recebido -- time-stamps desligados.\n"

#: src/http.c:1526
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Header Last-modified inválido -- time-stamp ignorado.\n"

#: src/http.c:1549
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""

# , c-format
#: src/http.c:1557
#, fuzzy, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Os tamanhos não são iguais (local %ld), baixando.\n"

#: src/http.c:1561
msgid "Remote file is newer, retrieving.\n"
msgstr "Arquivo remoto é mais novo, buscando.\n"

# , c-format
#: src/http.c:1606
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
