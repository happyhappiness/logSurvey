msgid "Unknown error"
msgstr "Erro desconhecido"

#: src/http.c:621 src/http.c:1433
msgid "Unable to establish SSL connection.\n"
msgstr ""

# , c-format
#: src/http.c:629
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Tentando conectar-se a %s:%hu.\n"

#: src/http.c:805
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Falha na requisi��o HTTP.\n"

# , c-format
#: src/http.c:810
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s requisi��o enviada, aguardando resposta... "

#: src/http.c:854
msgid "End of file while parsing headers.\n"
msgstr "Fim de arquivo durante a leitura dos headers.\n"

# , c-format
#: src/http.c:865
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Erro de leitura (%s) nos headers.\n"

#: src/http.c:905
msgid "No data received"
msgstr "Nenhum dado recebido"

#: src/http.c:907
msgid "Malformed status line"
msgstr "Linha de status inv�lida"

#: src/http.c:912
msgid "(no description)"
msgstr "(sem descri��o)"

#: src/http.c:1030
msgid "Authorization failed.\n"
msgstr "Autoriza��o falhou.\n"

#: src/http.c:1037
msgid "Unknown authentication scheme.\n"
msgstr "Esquema de autentica��o desconhecido.\n"

# , c-format
#: src/http.c:1127
#, c-format
msgid "Location: %s%s\n"
msgstr "Localiza��o: %s%s\n"

#: src/http.c:1128 src/http.c:1153
msgid "unspecified"
msgstr "nao especificado"

#: src/http.c:1129
msgid " [following]"
msgstr " [seguinte]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1143
msgid "Length: "
msgstr "Tamanho: "

# , c-format
#: src/http.c:1148
#, c-format
msgid " (%s to go)"
msgstr " (%s para o fim)"

#: src/http.c:1153
msgid "ignored"
msgstr "ignorado"

#: src/http.c:1254
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Aviso: wildcards n�o suportados para HTTP.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1275
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Arquivo `%s' j� presente, n�o ser� baixado.\n"

# , c-format
#: src/http.c:1425
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "N�o foi poss�vel escrever em `%s' (%s).\n"

# , c-format
#: src/http.c:1443
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERRO: Redire��o (%d) sem Location.\n"

# , c-format
#: src/http.c:1468
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERRO %d: %s.\n"

#: src/http.c:1481
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Header Last-modified n�o recebido -- time-stamps desligados.\n"

#: src/http.c:1489
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Header Last-modified inv�lido -- time-stamp ignorado.\n"

#: src/http.c:1524
msgid "Remote file is newer, retrieving.\n"
msgstr "Arquivo remoto � mais novo, buscando.\n"

# , c-format
#: src/http.c:1559
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
