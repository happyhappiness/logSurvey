   && (ISSPACE (line[sizeof (string_constant) - 1])			\
       || !line[sizeof (string_constant) - 1]))

/* Retrieve a document through HTTP protocol.  It recognizes status
   code, and correctly handles redirections.  It closes the network
   socket.  If it receives an error from the functions below it, it
