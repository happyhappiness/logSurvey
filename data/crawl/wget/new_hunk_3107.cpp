#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1698
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Nada encontrado com o padr�o `%s'.\n"

# , c-format
#: src/ftp.c:1764
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "Escrito index em formato HTML para `%s' [%ld].\n"

# , c-format
#: src/ftp.c:1769
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Escrito �ndice em formato HTML para `%s'.\n"

#: src/gen_sslfunc.c:117
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr "N�o foi poss�vel gerar semente para OpenSSL; desabilitando SSL.\n"

# , c-format
#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: op��o `%s' � amb�gua\n"

# , c-format
#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: op��o `--%s' n�o permite argumento\n"

# , c-format
#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: op��o `%c%s' n�o permite argumento\n"

# , c-format
#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: op��o `%s' requer um argumento\n"

# , c-format
#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: op��o n�o reconhecida `--%s'\n"

# , c-format
#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: op��o n�o reconhecida `%c%s'\n"

# , c-format
#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: op��o ilegal -- %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: op��o inv�lida -- %c\n"

# , c-format
#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: op��o requer um argumento -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: op��o `-W %s' � amb�gua\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: op��o `-W %s' n�o permite argumentos\n"

#: src/host.c:636
#, c-format
msgid "Resolving %s... "
msgstr "Resolvendo %s... "

#: src/host.c:656 src/host.c:672
#, c-format
msgid "failed: %s.\n"
msgstr "falha: %s.\n"

#: src/host.c:674
msgid "failed: timed out.\n"
msgstr "falha: tempo excedido.\n"

#: src/host.c:762
msgid "Host not found"
msgstr "Host n�o encontrado"

#: src/host.c:764
msgid "Unknown error"
msgstr "Erro desconhecido"

#: src/html-url.c:293
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: N�o foi poss�vel resolver link incompleto %s.\n"

#. this is fatal
#: src/http.c:674
msgid "Failed to set up an SSL context\n"
msgstr "Falha ao definir um contexto SSL\n"

#: src/http.c:680
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Falha ao carregar certificados do %s\n"

#: src/http.c:684 src/http.c:692
msgid "Trying without the specified certificate\n"
msgstr "Tentando sem o certificado especificado\n"

#: src/http.c:688
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Falha ao obter a chave do certificado de %s\n"

#: src/http.c:761 src/http.c:1809
msgid "Unable to establish SSL connection.\n"
msgstr "N�o foi poss�vel estabelecer conex�o segura (SSL).\n"

#: src/http.c:770
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Reutilizando conex�o para %s:%hu.\n"

#: src/http.c:1034
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Falha ao enviar requisi��o HTTP: %s.\n"

# , c-format
#: src/http.c:1039
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s requisi��o enviada, aguardando resposta... "

#: src/http.c:1083
msgid "End of file while parsing headers.\n"
msgstr "Fim de arquivo durante a leitura dos headers.\n"

# , c-format
#: src/http.c:1093
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Erro de leitura (%s) nos headers.\n"

#: src/http.c:1128
msgid "No data received"
msgstr "Nenhum dado recebido"

#: src/http.c:1130
msgid "Malformed status line"
msgstr "Linha de status inv�lida"

#: src/http.c:1135
msgid "(no description)"
msgstr "(sem descri��o)"

#: src/http.c:1267
msgid "Authorization failed.\n"
msgstr "Autoriza��o falhou.\n"

#: src/http.c:1274
msgid "Unknown authentication scheme.\n"
msgstr "Esquema de autentica��o desconhecido.\n"

# , c-format
#: src/http.c:1314
#, c-format
msgid "Location: %s%s\n"
msgstr "Localiza��o: %s%s\n"

#: src/http.c:1315 src/http.c:1454
msgid "unspecified"
msgstr "nao especificado"

#: src/http.c:1316
msgid " [following]"
msgstr " [seguinte]"

#: src/http.c:1383
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    O arquivo j� foi completamente obtido; nada a ser feito.\n"
"\n"

#: src/http.c:1401
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"Continua��o de download falhou nesse arquivo, o qual conflita com `-c'.\n"
"Arquivo existente n�o ser� truncado: `%s'.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1444
msgid "Length: "
msgstr "Tamanho: "

# , c-format
#: src/http.c:1449
#, c-format
msgid " (%s to go)"
msgstr " (%s para o fim)"

#: src/http.c:1454
msgid "ignored"
msgstr "ignorado"

#: src/http.c:1598
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Aviso: wildcards n�o suportados para HTTP.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1628
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Arquivo `%s' j� presente, n�o ser� baixado.\n"

# , c-format
#: src/http.c:1800
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "N�o foi poss�vel escrever em `%s' (%s).\n"

# , c-format
#: src/http.c:1819
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERRO: Redire��o (%d) sem Location.\n"

# , c-format
#: src/http.c:1851
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERRO %d: %s.\n"

#: src/http.c:1864
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Header Last-modified n�o recebido -- time-stamps desligados.\n"

#: src/http.c:1872
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Header Last-modified inv�lido -- time-stamp ignorado.\n"

#: src/http.c:1895
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"Arquivo no servidor n�o � mais novo que o local `%s' -- n�o baixando.\n"
"\n"

#: src/http.c:1903
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Os tamanhos n�o s�o iguais (local %ld) -- baixando.\n"

#: src/http.c:1907
msgid "Remote file is newer, retrieving.\n"
msgstr "Arquivo remoto � mais novo, buscando.\n"

# , c-format
#: src/http.c:1948
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
