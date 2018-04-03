 # volcado de `core' no significa nada, que te parece si mejor dejamos
 # el core dumped, o bien volcado del núcleo o algo así. Por el momento
 # no cambio nada. mm
-#: job.c:199
+#: job.c:264
 msgid " (core dumped)"
 msgstr " (core dumped) [Núcleo vaciado a un archivo]"
 
+#: job.c:316
+msgid "Warning: Empty redirection\n"
+msgstr "Atención: redirección vacía\n"
+
+#: job.c:352
+msgid "Syntax error, still inside '\"'\n"
+msgstr "Error de sintáxis, aún se está dentro de '\"'\n"
+
 # Recibida o capturada, pero por Dios , no pongas
 # 'se tiene' . En vez de hijo pon proceso hijo , y quita lo
 # que tienes entre paréntesis em+
 # Lo del paréntesis era para escoger. mm
-#: job.c:234
+#: job.c:404
 #, c-format
-msgid "Got a SIGCHLD; %d unreaped children.\n"
-msgstr "Recibí una señal SIGCHLD; %d proceso hijo descarriado.\n"
+msgid "Got a SIGCHLD; %u unreaped children.\n"
+msgstr "Recibí una señal SIGCHLD; %u proceso hijo descarriado.\n"
 
 # ¿Y job -> trabajos? sv
 # Si, pero no hablas de una computadora multi-trabajos sino multi-tareas.
 # Por eso elegí tareas. Lo platicamos con más calma? mm
-#: job.c:265
+#: job.c:453
 msgid "*** Waiting for unfinished jobs...."
 msgstr "*** Se espera a que terminen otras tareas...."
 
 # ¿De verdad se dice "vivo"? Si es un proceso, se me ocurre "activo". sv
 # Me gusta lo de activo. mm
-#: job.c:290
+#: job.c:482
 #, c-format
-msgid "Live child 0x%08lx PID %d%s\n"
-msgstr "Hijo activo 0x%08lx PID %d%s\n"
+msgid "Live child 0x%08lx (%s) PID %ld %s\n"
+msgstr "Hijo activo 0x%08lx (%s) PID %ld %s\n"
 
-#: job.c:292 job.c:427 job.c:514 job.c:919
+#: job.c:484 job.c:644 job.c:742 job.c:1302
 msgid " (remote)"
 msgstr " (remoto)"
 
-# Protestar al autor. No hay forma de poner trabajo(s) desconocido(s)
-# con coherencia. sv
-# Si, si no tienen identificado a su padre. Ni modo. mm
-# Pongo /s em+
-# Ok. mm
-#: job.c:414
+# Lo mismo, pon Proceso hijo, y quita lo que hay
+# entre paréntesis em+
+#: job.c:641
+#, c-format
+msgid "Reaping losing child 0x%08lx PID %ld %s\n"
+msgstr "Se pierde al proceso hijo descarriado 0x%08lx PID %ld %s\n"
+
+# Lo mismo, pon Proceso hijo, y quita lo que hay
+# entre paréntesis em+
+#: job.c:642
 #, c-format
-msgid "Unknown%s job %d"
-msgstr "Trabajo%s desconocido/s %d"
+msgid "Reaping winning child 0x%08lx PID %ld %s\n"
+msgstr "Se gana al proceso hijo descarriado 0x%08lx PID %ld %s\n"
 
-#: job.c:414
-msgid " remote"
-msgstr " remoto"
+# Give up no es enfocar, es abandonar, o desistir em+
+# Si, metí la pata. mm
+#: job.c:647
+#, c-format
+msgid "Cleaning up temp batch file %s\n"
+msgstr "Se limpia el archivo temporal %s\n"
 
-#: job.c:419
+# Proceso hijo em+
+# Ok.
+#: job.c:740
 #, c-format
-msgid "%s finished."
-msgstr "%s terminado."
+msgid "Removing child 0x%08lx PID %ld %s from chain.\n"
+msgstr "Se elimina al proceso hijo 0x%08lx PID %ld %s de la cadena.\n"
+
+#: job.c:797
+msgid "write jobserver"
+msgstr "escribir en el servidor de tareas"
 
 # Lo mismo, pon Proceso hijo, y quita lo que hay
 # entre paréntesis em+
-#: job.c:424
+#: job.c:799
 #, c-format
-msgid "Reaping %s child 0x%08lx PID %d%s\n"
-msgstr "Proceso hijo %s descarriado 0x%08lx PID %d%s\n"
+msgid "Released token for child 0x%08lx (%s).\n"
+msgstr "Se libera el token para el proceso hijo 0x%08lx (%s).\n"
 
-#: job.c:425
-msgid "losing"
-msgstr "se pierde"
+#: job.c:1236 job.c:2226
+#, c-format
+msgid "process_easy() failed failed to launch process (e=%d)\n"
+msgstr "fallo en process_easy() al lanzar el proceso (e=%d)\n"
 
-#: job.c:425
-msgid "winning"
-msgstr "se gana"
+#: job.c:1240 job.c:2230
+#, c-format
+msgid "\nCounted %d args in failed launch\n"
+msgstr "\nSe contaron %d argumentos en el lanzamiento fallido\n"
 
 # Proceso hijo em+
 # Ok.
-#: job.c:512
+#: job.c:1300
 #, c-format
-msgid "Removing child 0x%08lx PID %d%s from chain.\n"
-msgstr "Se elimina al proceso hijo 0x%08lx PID %d%s de la cadena.\n"
+msgid "Putting child 0x%08lx (%s) PID %ld%s on the chain.\n"
+msgstr "Se pone al proceso hijo 0x%08lx (%s) PID %ld%s en la cadena.\n"
 
-# Proceso hijo em+
-# Ok.
-#: job.c:917
+# Lo mismo, pon Proceso hijo, y quita lo que hay
+# entre paréntesis em+
+#: job.c:1498
 #, c-format
-msgid "Putting child 0x%08lx PID %05d%s on the chain.\n"
-msgstr "Se pone al proceso hijo 0x%08lx PID %05d%s en la cadena.\n"
+msgid "Obtained token for child 0x%08lx (%s).\n"
+msgstr "Se obtiene el token para el proceso hijo 0x%08lx (%s).\n"
+
+#: job.c:1504
+msgid "read jobs pipe"
+msgstr "tubería de trabajos leídos"
 
-#: job.c:1140
+#: job.c:1574
 msgid "cannot enforce load limits on this operating system"
 msgstr "no se pueden forzar los límites de carga en este sistema operativo"
 
-#: job.c:1142
+#: job.c:1576
 msgid "cannot enforce load limit: "
 msgstr "no se puede forzar la carga límite: "
 
-#: job.c:1244
+#: job.c:1679
+#, c-format
+msgid "internal error: `%s' command_state"
+msgstr "error interno: `%s' command_state"
+
+#: job.c:1764
+msgid "-warning, CTRL-Y will leave sub-process(es) around.\n"
+msgstr "-atención, CTRL-Y dejará vivos a los subprocesos.\n"
+
+#: job.c:1781
+msgid "-warning, you may have to re-enable CTRL-Y handling from DCL.\n"
+msgstr "-atención, deberás rehabilitar el manejo del CTRL-Y desde el DCL.\n"
+
+#: job.c:1894
+#, c-format
+msgid "BUILTIN [%s][%s]\n"
+msgstr "INTERCONSTRUIDO [%s][%s]\n"
+
+#: job.c:1905
+#, c-format
+msgid "BUILTIN CD %s\n"
+msgstr "CD INTERCONSTRUIDO %s\n"
+
+#: job.c:1923
+#, c-format
+msgid "BUILTIN RM %s\n"
+msgstr "RM INTERCONSTRUIDO %s\n"
+
+# Por defecto, como haces arriba em+
+# en efecto, mm
+#: job.c:1944
+#, c-format
+msgid "Unknown builtin command '%s'\n"
+msgstr "Instrucción interconstruida desconocida `%s'.\n"
+
+#: job.c:1966
+msgid "Error, empty command\n"
+msgstr "Error, comando vacío\n"
+
+#: job.c:1973 main.c:1307
+msgid "fopen (temporary file)"
+msgstr "fopen (archivo temporal)"
+
+#: job.c:1978
 #, c-format
-msgid "internal error: `%s' command_state %d in child_handler"
-msgstr "error interno: `%s' command_state %d en el child_handler"
+msgid "Redirected input from %s\n"
+msgstr "Entrada redirigida desde %s\n"
+
+# Probablemente sea aquí donde haya que ponerle el "el" para que "Entering"
+# concuerde bien con esta frase y con la anterior simultáneamente. sv
+# No. Ya revisé el fuente y transcribo el trozo pertinente:
+#  char *message = entering ? "Entering" : "Leaving";
+#  if (makelevel == 0)
+#    printf ("%s: %s ", program, message);
+#  else
+#    printf ("%s[%u]: %s ", program, makelevel, message);
+# Como notarás lo del directorio va en otro lado.
+#: job.c:1985
+#, c-format
+msgid "Redirected error to %s\n"
+msgstr "Se redirecciona el error a %s\n"
+
+#: job.c:1992
+#, c-format
+msgid "Redirected output to %s\n"
+msgstr "Salida redirigida a %s\n"
 
 # "en sustituto" me suena muy raro. Propongo: "en su lugar" en su lugar :-) sv
 # Ok. mm
-#: job.c:1350
+#: job.c:2055
 #, c-format
 msgid "Executing %s instead\n"
 msgstr "En su lugar, se ejecuta %s\n"
 
-#: job.c:1381
+#: job.c:2152
 #, c-format
 msgid "Error spawning, %d\n"
 msgstr "Error al lanzar el proceso %d\n"
 
-#: job.c:1442
+#: job.c:2255
+#, c-format
+msgid "make reaped child pid %d, still waiting for pid %d\n"
+msgstr "hacer un hijo descarriado %d, aún esperando el pid %d\n"
+
+#: job.c:2274
 #, c-format
 msgid "%s: Command not found"
 msgstr "%s: No se encontró el programa"
