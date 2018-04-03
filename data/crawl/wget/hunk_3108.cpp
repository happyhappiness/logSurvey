 "Baixados: %s bytes em %d arquivos\n"
 
 # , c-format
-#: src/main.c:821
+#: src/main.c:920
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
 msgstr "EXCEDIDA a quota (%s bytes) de recepção!\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:851
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "%s recebido, redirecionando saída para `%%s'.\n"
-
-# , c-format
-#: src/mswindows.c:123
-#, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"CTRL+Break recebido, redirecionando saída para `%s'.\n"
-"Execução continuará em background.\n"
-"Você pode parar o Wget pressionando CTRL+ALT+DELETE.\n"
-
-#. parent, no error
-#: src/mswindows.c:140 src/utils.c:451
+#: src/mswindows.c:147
 msgid "Continuing in background.\n"
 msgstr "Continuando em background.\n"
 
 # , c-format
-#: src/mswindows.c:142 src/utils.c:453
+#: src/mswindows.c:149 src/utils.c:487
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "Saída será escrita em `%s'.\n"
 
 # , c-format
-#: src/mswindows.c:232
+#: src/mswindows.c:245
 #, c-format
 msgid "Starting WinHelp %s\n"
 msgstr "Disparando WinHelp %s\n"
 
-#: src/mswindows.c:259 src/mswindows.c:267
+#: src/mswindows.c:272 src/mswindows.c:279
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Não foi possivel encontrar um driver de sockets usável.\n"
 
 # , c-format
-#: src/netrc.c:367
+#: src/netrc.c:380
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
-msgstr ""
-"%s: %s:%d: aviso: token \"%s\" aparece antes de qualquer nome de máquina\n"
+msgstr "%s: %s:%d: aviso: token \"%s\" aparece antes de qualquer nome de máquina\n"
 
 # , c-format
-#: src/netrc.c:398
+#: src/netrc.c:411
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: token desconhecido \"%s\"\n"
 
 # , c-format
-#: src/netrc.c:462
+#: src/netrc.c:475
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Uso: %s NETRC [NOME DO HOST]\n"
 
 # , c-format
-#: src/netrc.c:472
+#: src/netrc.c:485
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: não foi possível acessar %s: %s\n"
 
 # , c-format
-#: src/recur.c:510
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:234
+#, c-format
+msgid ""
+"\n"
+"%*s[ skipping %dK ]"
+msgstr ""
+"\n"
+"%*s[ ignorando %dK ]"
+
+# , c-format
+#: src/progress.c:401
+#, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "Especificação de estilo inválida `%s'; mantendo inalterado.\n"
+
+# , c-format
+#: src/recur.c:378
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Removendo %s pois ele deve ser rejeitado.\n"
 
-#: src/recur.c:684
+#: src/res.c:549
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Buscando robots.txt; por favor ignore qualquer erro.\n"
 
-# , c-format
-#: src/retr.c:229
+#: src/retr.c:400
 #, c-format
-msgid ""
-"\n"
-"          [ skipping %dK ]"
-msgstr ""
-"\n"
-"          [ aproveitando %dK ]"
-
-#: src/retr.c:421
-msgid "Could not find proxy host.\n"
-msgstr "Não foi possível encontrar o proxy.\n"
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "Erro analisando URL do proxy %s: %s\n"
 
 # , c-format
-#: src/retr.c:435
+#: src/retr.c:408
 #, c-format
-msgid "Proxy %s: Must be HTTP.\n"
-msgstr "Proxy %s: Deve ser HTTP.\n"
+msgid "Error in proxy URL %s: Must be HTTP.\n"
+msgstr "Erro na URL do proxy %s. Deve ser HTTP.\n"
 
 # , c-format
-#: src/retr.c:529
-#, fuzzy, c-format
-msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: Redireção para si mesmo.\n"
+#: src/retr.c:493
+#, c-format
+msgid "%d redirections exceeded.\n"
+msgstr "%d redirecionamentos excedidos.\n"
 
-#: src/retr.c:623
+#: src/retr.c:617
 msgid ""
 "Giving up.\n"
 "\n"
