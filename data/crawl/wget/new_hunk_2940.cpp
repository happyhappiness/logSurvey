# Es la funci�n bind(2), que asigna una direcci�n a un socket.
# Me parece que decir lo de la funci�n es mejor. (nl)
#
#: src/ftp.c:752
#, c-format
msgid "Bind error (%s).\n"
msgstr "Error en la llamada `bind' (%s).\n"

# Ya no est� "prohibido" usar esta palabra. sv
#: src/ftp.c:759
msgid "Invalid PORT.\n"
msgstr "PUERTO inv�lido.\n"

#: src/ftp.c:810
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"El comando REST no funcion�, se empezar� desde el principio\n"

#: src/ftp.c:875
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"No existe el fichero `%s'.\n"
"\n"

#: src/ftp.c:927
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"No existe el fichero o directorio `%s'.\n"
"\n"

#. We cannot just invent a new name and use it (which is
#. what functions like unique_create typically do)
#. because we told the user we'd use this name.
#. Instead, return and retry the download.
#: src/ftp.c:992 src/http.c:1847
#, c-format
msgid "%s has sprung into existence.\n"
msgstr ""

# He a�adido el art�culo a `conexi�n' - cll
#
#: src/ftp.c:1054
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, cerrando la conexi�n de control.\n"

#: src/ftp.c:1062
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Conexi�n de datos: %s; "

#: src/ftp.c:1077
msgid "Control connection closed.\n"
msgstr "Conexi�n de control cerrada.\n"

#: src/ftp.c:1095
msgid "Data transfer aborted.\n"
msgstr "Trasferencia de datos abortada.\n"

# `no recuperando' no me suena muy espa�ol, te propongo la alternativa
# m�s "humanizada", `no se recupera' - cll
#
#: src/ftp.c:1160
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "El fichero `%s' ya est� ah�, no se recupera.\n"
