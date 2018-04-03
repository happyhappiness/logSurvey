 "A tentar novamente.\n"
 "\n"
 
-#: src/url.c:626
+#: src/spider.c:137
+msgid ""
+"Found no broken links.\n"
+"\n"
+msgstr ""
+
+#: src/spider.c:144
+#, c-format
+msgid ""
+"Found %d broken link.\n"
+"\n"
+msgid_plural ""
+"Found %d broken links.\n"
+"\n"
+msgstr[0] ""
+msgstr[1] ""
+
+#: src/spider.c:154
+#, fuzzy, c-format
+msgid "%s referred by:\n"
+msgstr ""
+"\n"
+"%s recebido.\n"
+
+#: src/spider.c:159
+#, c-format
+msgid "    %s\n"
+msgstr ""
+
+#: src/url.c:619
 msgid "No error"
 msgstr "Sem erros"
 
-#: src/url.c:628
+#: src/url.c:621
 msgid "Unsupported scheme"
 msgstr "Esquema não suportado"
 
-#: src/url.c:630
+#: src/url.c:623
 msgid "Invalid host name"
 msgstr "Nome de máquina inválido"
 
-#: src/url.c:632
+#: src/url.c:625
 msgid "Bad port number"
 msgstr "Mau número de porto"
 
-#: src/url.c:634
+#: src/url.c:627
 msgid "Invalid user name"
 msgstr "Nome de utilizador inválido"
 
-#: src/url.c:636
+#: src/url.c:629
 msgid "Unterminated IPv6 numeric address"
 msgstr "Endereço numérico IPv6 não concluído"
 
-#: src/url.c:638
+#: src/url.c:631
 msgid "IPv6 addresses not supported"
 msgstr "Endereços IPv6 não suportados"
 
-#: src/url.c:640
+#: src/url.c:633
 msgid "Invalid IPv6 numeric address"
 msgstr "Endereço numérico IPv6 inválido"
 
 #. parent, no error
-#: src/utils.c:349
+#: src/utils.c:324
 #, c-format
 msgid "Continuing in background, pid %d.\n"
 msgstr "A continuar em segundo plano (fundo), pid %d.\n"
 
-#: src/utils.c:397
+#: src/utils.c:372
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Erro ao remover ligação simbólica '%s': %s\n"
 
-#: src/xmalloc.c:72
+#: src/xmalloc.c:62
 #, c-format
 msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
 msgstr "%s: %s: Falha ao reservar %ld bytes; memória insuficiente.\n"
+
+#~ msgid "Error in Set-Cookie, field `%s'"
+#~ msgstr "Erro em Set-Cookie, campo '%s'"
+
+#~ msgid "%s (%s) - Connection closed at byte %s/%s. "
+#~ msgstr "%s (%s) - Conexão fechada ao byte %s/%s. "
+
+#~ msgid ""
+#~ "%s: %s: Invalid extended boolean `%s';\n"
+#~ "use one of `on', `off', `always', or `never'.\n"
+#~ msgstr ""
+#~ "%s: %s: Valor lógico extendido '%s' inválido;\n"
+#~ "use 'always', 'on', 'off' ou 'never'.\n"
+
+#~ msgid ""
+#~ "This program is distributed in the hope that it will be useful,\n"
+#~ "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
+#~ "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
+#~ "GNU General Public License for more details.\n"
+#~ msgstr ""
+#~ "Este programa é distribuído na esperança que seja útil,\n"
+#~ "mas SEM QUALQUER GARANTIA; sem sequer a garantia implícita de\n"
+#~ "COMERCIALIZAÇÃO ou SERVIÇO DE PROPÓSITO PARTICULAR. Veja a\n"
+#~ "Licença Pública Geral GNU para mais detalhes.\n"
+
+#~ msgid "%s: Certificate verification error for %s: %s\n"
+#~ msgstr "%s: Erro de verificação de certificado para %s: %s\n"
