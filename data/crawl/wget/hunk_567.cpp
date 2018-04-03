 "Os tamanhos não coincidem (local %s) -- a transferir.\n"
 "\n"
 
-#: src/ftp.c:1507
+#: src/ftp.c:1762
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Nome da ligação simbólica inválido, a ignorar.\n"
 
-#: src/ftp.c:1524
+#: src/ftp.c:1779
 #, c-format
 msgid ""
 "Already have correct symlink %s -> %s\n"
 "\n"
 msgstr "Já tem a ligação simbólica correcta %s -> %s\n"
 
-#: src/ftp.c:1533
+#: src/ftp.c:1788
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "A criar a ligação simbólica %s -> %s\n"
 
-#: src/ftp.c:1543
+#: src/ftp.c:1798
 #, fuzzy, c-format
 msgid "Symlinks not supported, skipping symlink %s.\n"
 msgstr ""
 "Ligações simbólicas não suportadas, a ignorar ligação simbólica '%s'.\n"
 
-#: src/ftp.c:1555
+#: src/ftp.c:1810
 #, fuzzy, c-format
 msgid "Skipping directory %s.\n"
 msgstr "A ignorar a pasta '%s'.\n"
 
-#: src/ftp.c:1564
+#: src/ftp.c:1819
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: tipo de ficheiro desconhecido ou não suportado.\n"
 
-#: src/ftp.c:1591
+#: src/ftp.c:1856
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: selo temporal corrompido.\n"
 
-#: src/ftp.c:1619
+#: src/ftp.c:1878
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr ""
 "As pastas não serão transferidas, uma ves que a profundidade é %d (máximo %"
 "d).\n"
 
-#: src/ftp.c:1669
+#: src/ftp.c:1928
 #, fuzzy, c-format
 msgid "Not descending to %s as it is excluded/not-included.\n"
 msgstr "A não descer para '%s', uma vez que está excluída.\n"
 
-#: src/ftp.c:1735 src/ftp.c:1749
+#: src/ftp.c:1994 src/ftp.c:2008
 #, fuzzy, c-format
 msgid "Rejecting %s.\n"
 msgstr "A rejeitar '%s'.\n"
 
-#: src/ftp.c:1772
+#: src/ftp.c:2031
 #, c-format
 msgid "Error matching %s against %s: %s\n"
 msgstr "Erro ao corresponder %s com %s: %s\n"
 
-#: src/ftp.c:1814
+#: src/ftp.c:2073
 #, fuzzy, c-format
 msgid "No matches on pattern %s.\n"
 msgstr "Não há correspondências com o padrão '%s'.\n"
 
-#: src/ftp.c:1880
+#: src/ftp.c:2144
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s [%s].\n"
 msgstr "Índice em HTML gravado para '%s' [%s].\n"
 
-#: src/ftp.c:1885
+#: src/ftp.c:2149
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s.\n"
 msgstr "Índice HTML gravado para '%s'.\n"
 
-#: src/host.c:348
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "ERROR"
+msgstr "ERRO"
+
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "WARNING"
+msgstr "AVISO"
+
+#: src/gnutls.c:225 src/openssl.c:504
+#, c-format
+msgid "%s: No certificate presented by %s.\n"
+msgstr "%s: Certificado não apresentado por %s.\n"
+
+#: src/gnutls.c:233
+#, fuzzy, c-format
+msgid "%s: The certificate of %s is not trusted.\n"
+msgstr "%s: Certificado não apresentado por %s.\n"
+
+#: src/gnutls.c:239
+#, c-format
+msgid "%s: The certificate of %s hasn't got a known issuer.\n"
+msgstr ""
+
+#: src/gnutls.c:245
+#, fuzzy, c-format
+msgid "%s: The certificate of %s has been revoked.\n"
+msgstr "  Certificado emitido expirado.\n"
+
+#: src/gnutls.c:259
+#, c-format
+msgid "Error initializing X509 certificate: %s\n"
+msgstr ""
+
+#: src/gnutls.c:268
+#, fuzzy
+msgid "No certificate found\n"
+msgstr "%s: Certificado não apresentado por %s.\n"
+
+#: src/gnutls.c:275
+#, fuzzy, c-format
+msgid "Error parsing certificate: %s\n"
+msgstr "Erro ao analisar URL %s do 'proxy': %s.\n"
+
+#: src/gnutls.c:282
+#, fuzzy
+msgid "The certificate has not yet been activated\n"
+msgstr "  Certificado emitido ainda inválido.\n"
+
+#: src/gnutls.c:287
+#, fuzzy
+msgid "The certificate has expired\n"
+msgstr "  Certificado emitido expirado.\n"
+
+#: src/gnutls.c:293
+#, fuzzy, c-format
+msgid "The certificate's owner does not match hostname '%s'\n"
+msgstr ""
+"%s: o nome do certificado '%s' não corresponde ao nome da máquina requerida "
+"'%s'.\n"
+
+#: src/host.c:358
 msgid "Unknown host"
 msgstr "Máquina desconhecida"
 
-#: src/host.c:352
+#: src/host.c:362
 msgid "Temporary failure in name resolution"
 msgstr "Falha temporária na resolução de nome"
 
-#: src/host.c:354
+#: src/host.c:364
 msgid "Unknown error"
 msgstr "Erro desconhecido"
 
-#: src/host.c:715
+#: src/host.c:737
 #, c-format
 msgid "Resolving %s... "
 msgstr "A resolver %s..."
 
-#: src/host.c:763
+#: src/host.c:789
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr "falhou: Endereços IPv4/IPv6 inexistentes para a máquina.\n"
 
-#: src/host.c:786
+#: src/host.c:812
 msgid "failed: timed out.\n"
 msgstr "falhou: terminou o tempo.\n"
 
-#: src/html-url.c:289
+#: src/html-url.c:286
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Não é possível resolver a ligação incompleta %s.\n"
 
-#: src/html-url.c:696
+#: src/html-url.c:762
 #, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: Endereço '%s' inválido: %s\n"
 
-#: src/http.c:368
+#: src/http.c:377
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Falha ao escrever o pedido HTTP: %s.\n"
 
-#: src/http.c:745
+#: src/http.c:754
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Sem cabeçalhos, a assumir HTTP/0.9"
 
-#: src/http.c:1430
+#: src/http.c:1456
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "A desactivar o SSL devido a erros encontrados.\n"
 
-#: src/http.c:1548
+#: src/http.c:1576
 #, fuzzy, c-format
 msgid "POST data file %s missing: %s\n"
 msgstr "Ficheiro de dados POST '%s' em falta: %s\n"
 
-#: src/http.c:1632
+#: src/http.c:1660
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "A reutilizar a conexão existente com %s:%d.\n"
 
-#: src/http.c:1701
+#: src/http.c:1729
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Falha ao ler a resposta do procurador ('proxy'): %s\n"
 
-#: src/http.c:1721
+#: src/http.c:1750
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Falhou o 'túnel' com o procurador ('proxy'): %s"
 
-#: src/http.c:1766
+#: src/http.c:1795
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "Pedido %s enviado, a aguardar resposta..."
 
-#: src/http.c:1777
+#: src/http.c:1806
 msgid "No data received.\n"
 msgstr "Nenhuns dados recebidos.\n"
 
-#: src/http.c:1784
+#: src/http.c:1813
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Erro de leitura (%s) nos cabeçalhos.\n"
 
-#: src/http.c:1831 src/http.c:2385
+#: src/http.c:1884
+msgid "Unknown authentication scheme.\n"
+msgstr "Esquema de autenticação desconhecido.\n"
+
+#: src/http.c:1918
+msgid "Authorization failed.\n"
+msgstr "A autorização falhou.\n"
+
+#: src/http.c:1956 src/http.c:2466
 #, fuzzy, c-format
 msgid ""
 "File %s already there; not retrieving.\n"
