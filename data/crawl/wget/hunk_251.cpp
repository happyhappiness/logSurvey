     return $list;
 }
 
+# 2013-10-17 Andrea Urbani (matfanjol)
+# It returns the behavior of the given name.
+# In this file I handle also the following behaviors:
+#  list_dont_clean_path  : if defined, the command
+#                           $path =~ s/^-[a-zA-Z0-9]+\s?//;
+#                          is not runt and the given path
+#                          remains the original one
+#  list_empty_if_list_a  : if defined, "LIST -a" returns an
+#                          empty content
+#  list_fails_if_list_a  : if defined, "LIST -a" returns an
+#                          error
+#  list_no_hidden_if_list: if defined, "LIST" doesn't return
+#                          hidden files.
+#                          To define an hidden file add
+#                            attr => "H"
+#                          to the url files
+#  syst_response         : if defined, its content is printed
+#                          out as SYST response
+sub GetBehavior {
+  my ($self, $name) = @_;
+  return $self->{'_behavior'}{$name};
+}
+
 1;
 
 # vim: et ts=4 sw=4
