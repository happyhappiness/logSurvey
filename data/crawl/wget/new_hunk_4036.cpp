msgid "ignored"
msgstr "ignorado"

#: src/http.c:858
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Aviso: wildcards n�o suportados para HTTP.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:873
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Arquivo `%s' j� presente, n�o ser� baixado.\n"

# , c-format
#: src/http.c:1015
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "N�o foi poss�vel escrever em `%s' (%s).\n"

# , c-format
#: src/http.c:1025
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERRO: Redire��o (%d) sem Location.\n"

# , c-format
#: src/http.c:1048
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERRO %d: %s.\n"

#: src/http.c:1060
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Header Last-modified n�o recebido -- time-stamps desligados.\n"

#: src/http.c:1068
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Header Last-modified inv�lido -- time-stamp ignorado.\n"

#. We can't collapse this down into just one logprintf()
#. call with a variable set to u->local or the .orig
#. filename because we have to malloc() space for the
#. latter, and because there are multiple returns above (a
#. coding style no-no by many measures, for reasons such as
#. this) we'd have to remember to free() the string at each
#. one to avoid a memory leak.
#: src/http.c:1099
#, c-format
msgid ""
"Server file no newer than local file `%s.orig' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:1113
msgid "Remote file is newer, retrieving.\n"
msgstr "Arquivo remoto � mais novo, buscando.\n"

# , c-format
#: src/http.c:1147
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
