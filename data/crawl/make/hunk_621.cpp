     printf ("define %s\n%s\nendef\n", v->name, v->value);
   else
     {
-      register char *p;
+      char *p;
 
       printf ("%s %s= ", v->name, v->recursive ? v->append ? "+" : "" : ":");
 
