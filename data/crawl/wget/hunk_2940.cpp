 # Es la funci�n bind(2), que asigna una direcci�n a un socket.
 # Me parece que decir lo de la funci�n es mejor. (nl)
 #
-#: src/ftp.c:591
+#: src/ftp.c:752
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Error en la llamada `bind' (%s).\n"
 
 # Ya no est� "prohibido" usar esta palabra. sv
-#: src/ftp.c:598
+#: src/ftp.c:759
 msgid "Invalid PORT.\n"
 msgstr "PUERTO inv�lido.\n"
 
-#: src/ftp.c:651
-#, c-format
-msgid "\nREST failed; will not truncate `%s'.\n"
-msgstr "\nEl comando REST no funcion�, no se truncar� `%s'.\n"
-
-#: src/ftp.c:658
-msgid "\nREST failed, starting from scratch.\n"
-msgstr "\nEl comando REST no funcion�, se empezar� desde el principio\n"
-
-#: src/ftp.c:707
-#, c-format
-msgid "No such file `%s'.\n\n"
-msgstr "No existe el fichero `%s'.\n\n"
+#: src/ftp.c:810
+msgid ""
+"\n"
+"REST failed, starting from scratch.\n"
+msgstr ""
+"\n"
+"El comando REST no funcion�, se empezar� desde el principio\n"
 
-#: src/ftp.c:755
+#: src/ftp.c:875
 #, c-format
-msgid "No such file or directory `%s'.\n\n"
-msgstr "No existe el fichero o directorio `%s'.\n\n"
+msgid ""
+"No such file `%s'.\n"
+"\n"
+msgstr ""
+"No existe el fichero `%s'.\n"
+"\n"
 
-#: src/ftp.c:839 src/ftp.c:847
+#: src/ftp.c:927
 #, c-format
-msgid "Length: %s"
-msgstr "Longitud: %s"
+msgid ""
+"No such file or directory `%s'.\n"
+"\n"
+msgstr ""
+"No existe el fichero o directorio `%s'.\n"
+"\n"
 
-#: src/ftp.c:841 src/ftp.c:849
+#. We cannot just invent a new name and use it (which is
+#. what functions like unique_create typically do)
+#. because we told the user we'd use this name.
+#. Instead, return and retry the download.
+#: src/ftp.c:992 src/http.c:1847
 #, c-format
-msgid " [%s to go]"
-msgstr " [%s para acabar]"
-
-# nota jjrs: Se agrega este mensaje cuando el wget no ha obtenido
-#   directamente el tama�o del archivo a transferir y esta usando la
-#   longitud que reporta el inicio de la transferencia.
-#
-# �Dabuti! Si no lo llegas a decir, ... �Lo estaba flipando! :) Pero
-# vamos, siendo como dices, a m� me suena perfect�simamente - cll
-#
-#: src/ftp.c:851
-msgid " (unauthoritative)\n"
-msgstr " (probablemente)\n"
+msgid "%s has sprung into existence.\n"
+msgstr ""
 
 # He a�adido el art�culo a `conexi�n' - cll
 #
-#: src/ftp.c:877
+#: src/ftp.c:1054
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, cerrando la conexi�n de control.\n"
 
-#: src/ftp.c:885
+#: src/ftp.c:1062
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - Conexi�n de datos: %s; "
 
-#: src/ftp.c:902
+#: src/ftp.c:1077
 msgid "Control connection closed.\n"
 msgstr "Conexi�n de control cerrada.\n"
 
-#: src/ftp.c:920
+#: src/ftp.c:1095
 msgid "Data transfer aborted.\n"
 msgstr "Trasferencia de datos abortada.\n"
 
 # `no recuperando' no me suena muy espa�ol, te propongo la alternativa
 # m�s "humanizada", `no se recupera' - cll
 #
-#: src/ftp.c:984
+#: src/ftp.c:1160
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "El fichero `%s' ya est� ah�, no se recupera.\n"
