#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:511
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr "%s: Aviso: a resoluci�n inversa do enderezo local non devolveu un FQDN\n"

#: src/host.c:539
msgid "Host not found"
msgstr "Servidor non atopado"

#: src/host.c:541
msgid "Unknown error"
msgstr "Erro desco�ecido"

#: src/html.c:439 src/html.c:441
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "�ndice de /%s en %s:%d"

#: src/html.c:463
msgid "time unknown       "
msgstr "data desco�ecida   "

#: src/html.c:467
msgid "File        "
msgstr "Ficheiro    "

#: src/html.c:470
msgid "Directory   "
msgstr "Directorio  "

#: src/html.c:473
msgid "Link        "
msgstr "Ligaz�n     "

#: src/html.c:476
msgid "Not sure    "
msgstr "Non seguro  "

#: src/html.c:494
#, c-format
msgid " (%s bytes)"
msgstr " (%s bytes)"

#: src/http.c:492
msgid "Failed writing HTTP request.\n"
msgstr "Fallo ao escribir unha petici�n HTTP.\n"

#: src/http.c:497
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Petici�n %s enviada, agardando unha resposta... "

#: src/http.c:536
msgid "End of file while parsing headers.\n"
msgstr "Fin de ficheiro mentres se analizaban as cabeceiras.\n"

#: src/http.c:547
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Erro ao ler (%s) nas cabeceiras.\n"

#: src/http.c:587
msgid "No data received"
msgstr "Non se recibiron datos"

#: src/http.c:589
msgid "Malformed status line"
msgstr "Li�a de estado mal formada"

#: src/http.c:594
msgid "(no description)"
msgstr "(sen descripci�n)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:678
msgid "Authorization failed.\n"
msgstr "Fallo na autorizaci�n.\n"

#: src/http.c:685
msgid "Unknown authentication scheme.\n"
msgstr "Sistema de autenticaci�n desco�ecido.\n"

#: src/http.c:748
#, c-format
msgid "Location: %s%s\n"
msgstr "Lugar: %s%s\n"

#: src/http.c:749 src/http.c:774
msgid "unspecified"
msgstr "non especificado"

#: src/http.c:750
msgid " [following]"
msgstr " [seguindo]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:764
msgid "Length: "
msgstr "Lonxitude: "

#: src/http.c:769
#, c-format
msgid " (%s to go)"
msgstr " (%s para rematar)"

#: src/http.c:774
msgid "ignored"
msgstr "ignorado"

#: src/http.c:857
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Aviso: comod�ns non soportados en HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:872
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "O ficheiro `%s' xa est� a�, non ha ser descargado.\n"

#: src/http.c:978
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Non se pode escribir en `%s' (%s).\n"

#: src/http.c:988
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERROR: Redirecci�n (%d) sen destino.\n"

#: src/http.c:1011
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERRO %d: %s.\n"

#: src/http.c:1023
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Falta a cabeceira Last-modified -- marcas de data e hora desactivadas.\n"

#: src/http.c:1031
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Cabeceira Last-modified incorrecta -- a marca de data e hora foi ignorada.\n"

#: src/http.c:1064
msgid "Remote file is newer, retrieving.\n"
msgstr "O ficheiro remoto � m�is novo, descargando.\n"

#: src/http.c:1098
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - `%s' gardado [%ld/%ld]\n\n"

#: src/http.c:1130
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Conexi�n pechada no byte %ld. "

#: src/http.c:1138
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - `%s' gardado [%ld/%ld])\n\n"

#: src/http.c:1150
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Conexi�n pechada no byte %ld/%ld. "

#: src/http.c:1161
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Erro de lectura no byte %ld (%s)."

#: src/http.c:1169
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Erro de lectura no byte %ld/%ld (%s). "

#: src/init.c:312 src/netrc.c:250
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Non se pode ler %s (%s).\n"

#: src/init.c:333 src/init.c:339
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Erro en %s na li�a %d.\n"

#: src/init.c:370
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Aviso: Os ficheiros wgetrc do sistema e do usuario apuntan a `%s'.\n"

#: src/init.c:458
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: BUG: comando desco�ecido `%s', valor `%s'.\n"

#: src/init.c:485
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Por favor, especifique `on' ou `off'.\n"

#: src/init.c:503 src/init.c:760 src/init.c:782 src/init.c:855
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Especificaci�n `%s' non v�lida.\n"

#: src/init.c:616 src/init.c:638 src/init.c:660 src/init.c:686
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Especificaci�n `%s' non v�lida\n"

#: src/main.c:101
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Uso: %s [OPCI�N]... [URL]...\n"

#: src/main.c:109
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, un descargador de ficheiros de rede non interactivo.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:114
msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
msgstr "\nOs argumentos obrigatorios nas opci�ns largas sono tam�n nas curtas.\n\n"

#: src/main.c:117
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
"  -h,  --help              print this help.\n"
"  -b,  --background        go to background after startup.\n"
"  -e,  --execute=COMMAND   execute a `.wgetrc' command.\n"
"\n"
msgstr ""
"Comezo:\n"
