msgstr "Erro desco�ecido"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr "Non se puido estabrecer un contexto SSL\n"

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Non se puideron carga-los certificados de %s\n"

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr "Probando sen o certificado especificado\n"

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Non se puido obte-la clave do certificado de %s\n"

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr "Non se puido estabrece-la conexi�n SSL.\n"

#: src/http.c:671
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Reutilizando a conexi�n de %s:%hu.\n"

#: src/http.c:861
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Fallo ao escribir unha petici�n HTTP: %s.\n"

#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Petici�n %s enviada, agardando unha resposta... "

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr "Fin de ficheiro mentres se analizaban as cabeceiras.\n"

#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Erro ao ler (%s) nas cabeceiras.\n"

#: src/http.c:959
msgid "No data received"
msgstr "Non se recibiron datos"

#: src/http.c:961
msgid "Malformed status line"
msgstr "Li�a de estado mal formada"

#: src/http.c:966
msgid "(no description)"
msgstr "(sen descripci�n)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr "Fallo na autorizaci�n.\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr "Sistema de autenticaci�n desco�ecido.\n"

#: src/http.c:1136
#, c-format
msgid "Location: %s%s\n"
msgstr "Lugar: %s%s\n"

#: src/http.c:1137 src/http.c:1269
msgid "unspecified"
msgstr "non especificado"

#: src/http.c:1138
msgid " [following]"
msgstr " [segu�ndoo]"

#: src/http.c:1200
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    O ficheiro xa est� completo; non hai nada que facer.\n\n"

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"Non se puido continua-la descarga do ficheiro, o que � incompatible con `-c'.\n"
"Non se ha trunca-lo ficheiro existente `%s'.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1259
msgid "Length: "
msgstr "Lonxitude: "

#: src/http.c:1264
#, c-format
msgid " (%s to go)"
msgstr " (quedan %s por descargar)"

#: src/http.c:1269
msgid "ignored"
msgstr "ignorado"

#: src/http.c:1399
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Aviso: comod�ns non soportados en HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1417
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "O ficheiro `%s' xa est� a�, non se ha descargar.\n"

#: src/http.c:1585
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Non se pode escribir en `%s' (%s).\n"

#: src/http.c:1602
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERROR: Redirecci�n (%d) sen destino.\n"

#: src/http.c:1630
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERRO %d: %s.\n"

#: src/http.c:1642
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Falta a cabeceira Last-modified -- marcas de data e hora desactivadas.\n"

#: src/http.c:1650
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Cabeceira Last-modified incorrecta -- a marca de data e hora foi ignorada.\n"

#: src/http.c:1673
#, c-format
msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
msgstr "O ficheiro do servidor non � m�is novo c� ficheiro local `%s' -- non se descarga.\n\n"

#: src/http.c:1680
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Os tama�os non coinciden (local %ld) -- descargando.\n"

#: src/http.c:1684
msgid "Remote file is newer, retrieving.\n"
msgstr "O ficheiro remoto � m�is novo, descargando.\n"

#: src/http.c:1728
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - `%s' gardado [%ld/%ld]\n\n"

#: src/http.c:1774
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Conexi�n pechada no byte %ld. "

#: src/http.c:1782
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - `%s' gardado [%ld/%ld])\n\n"

#: src/http.c:1801
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Conexi�n pechada no byte %ld/%ld. "

#: src/http.c:1812
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Erro de lectura no byte %ld (%s)."

#: src/http.c:1820
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Erro de lectura no byte %ld/%ld (%s). "

#: src/init.c:349 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Non se pode ler %s (%s).\n"

#: src/init.c:367 src/init.c:373
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Erro en %s na li�a %d.\n"

#: src/init.c:405
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Aviso: Os ficheiros wgetrc do sistema e do usuario apuntan a `%s'.\n"

#: src/init.c:497
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: BUG: comando desco�ecido `%s', valor `%s'.\n"

#: src/init.c:529
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: Non se pode convertir `%s' a un enderezo IP.\n"

#: src/init.c:559
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Por favor, especifique `on' ou `off'.\n"

#: src/init.c:603
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Por favor, especifique always (sempre), on, off ou never (nunca).\n"

#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Especificaci�n `%s' non v�lida.\n"

#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Especificaci�n `%s' non v�lida\n"

#: src/main.c:120
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Uso: %s [OPCI�N]... [URL]...\n"

#: src/main.c:128
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, un descargador de ficheiros de rede non interactivo.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:133
msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
msgstr "\nOs argumentos obrigatorios nas opci�ns largas sono tam�n nas curtas.\n\n"

#: src/main.c:137
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
