#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1778
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Não há correspondências com o padrão '%s'.\n"

#: src/ftp.c:1844
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Índice em HTML gravado para '%s' [%s].\n"

#: src/ftp.c:1849
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Índice HTML gravado para '%s'.\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: a opção '%s' é ambígua\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: a opção '--%s não permite um argumento\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: a opção '%c%s' não permite um argumento\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: a opção '%s' requere um argumento\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: opção '--%s' desconhecida\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: opção '%c%s' desconhecida\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: opção ilegal -- %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: opção inválida -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s a opção requere um argumento -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: a opção '-W %s' é ambígua\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: a opção '-W %s' não permite um argumento\n"

#: src/host.c:366
msgid "Unknown host"
msgstr "Máquina desconhecida"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:370
msgid "Temporary failure in name resolution"
msgstr "Falha temporária na resolução de nome"

#: src/host.c:372
msgid "Unknown error"
msgstr "Erro desconhecido"

#: src/host.c:751
#, c-format
msgid "Resolving %s... "
msgstr "A resolver %s..."

#: src/host.c:798
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "falhou: Endereços IPv4/IPv6 inexistentes para a máquina.\n"

#: src/host.c:821
msgid "failed: timed out.\n"
msgstr "falhou: terminou o tempo.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Não é possível resolver a ligação incompleta %s.\n"

#: src/html-url.c:705
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Endereço '%s' inválido: %s\n"

#: src/http.c:373
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Falha ao escrever o pedido HTTP: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr "Sem cabeçalhos, a assumir HTTP/0.9"

#: src/http.c:1204
msgid "Disabling SSL due to encountered errors.\n"
msgstr "A desactivar o SSL devido a erros encontrados.\n"

#: src/http.c:1374
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "Ficheiro de dados POST '%s' em falta: %s\n"

#: src/http.c:1423
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "A reutilizar a conexão existente com %s:%d.\n"

#: src/http.c:1492
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Falha ao ler a resposta do procurador ('proxy'): %s\n"

#: src/http.c:1512
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Falhou o 'túnel' com o procurador ('proxy'): %s"

#: src/http.c:1557
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Pedido %s enviado, a aguardar resposta..."

#: src/http.c:1568
msgid "No data received.\n"
msgstr "Nenhuns dados recebidos.\n"

#: src/http.c:1575
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Erro de leitura (%s) nos cabeçalhos.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1660
msgid "Unknown authentication scheme.\n"
msgstr "Esquema de autenticação desconhecido.\n"

#: src/http.c:1684
msgid "Authorization failed.\n"
msgstr "A autorização falhou.\n"

#: src/http.c:1698
msgid "Malformed status line"
msgstr "Linha de estado mal-formada"

#: src/http.c:1700
msgid "(no description)"
msgstr "(sem descrição)"

#: src/http.c:1763
#, c-format
msgid "Location: %s%s\n"
msgstr "Localização: %s%s\n"

#: src/http.c:1764 src/http.c:1871
msgid "unspecified"
msgstr "não especificado"

#: src/http.c:1765
msgid " [following]"
msgstr " [a seguir]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1821
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
