msgid " (%s bytes)"
msgstr " (%s bytes)"

#: src/http.c:508
msgid "Failed writing HTTP request.\n"
msgstr "Falha na requisi��o HTTP.\n"

# , c-format
#: src/http.c:512
#, fuzzy, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s requisi��o enviada, buscando headers... "

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
msgstr "(sem descri��o)"

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
msgstr "Localiza��o: %s%s\n"

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

#: src/http.c:903
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Aviso: wildcards n�o suportados para HTTP.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:924
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Arquivo `%s' j� presente, n�o ser� baixado.\n"

# , c-format
#: src/http.c:1083
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "N�o foi poss�vel escrever em `%s' (%s).\n"

# , c-format
#: src/http.c:1094
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERRO: Redire��o (%d) sem Location.\n"

# , c-format
#: src/http.c:1119
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERRO %d: %s.\n"

#: src/http.c:1132
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Header Last-modified n�o recebido -- time-stamps desligados.\n"

#: src/http.c:1140
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Header Last-modified inv�lido -- time-stamp ignorado.\n"

#: src/http.c:1175
msgid "Remote file is newer, retrieving.\n"
msgstr "Arquivo remoto � mais novo, buscando.\n"

# , c-format
#: src/http.c:1210
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
