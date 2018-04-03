     my ($tex, $main, $opts) = @_;
 
     my (%tex_items, %main_items);
-    while ($tex =~ /^\@item\w*? \s+? --([\w\-]+)/gmx) {
+    while ($tex =~ /^\@item\w*? \s+? --([-a-z0-9]+)/gmx) {
         $tex_items{$1} = true;
     }
-    ($main) = $main =~ /(\nprint_help.*\n}\n)/s;
-    while ($main =~ /--([-a-z0-9]+)/g) {
+    my ($help) = $main =~ /\n print_help .*? \{\n (.*) \n\} \n/sx;
+    while ($help =~ /--([-a-z0-9]+)/g) {
         $main_items{$1} = true;
     }
+
     my @options;
     foreach my $opt (@$opts) {
-        find_documentation (\@options, $opt, \%tex_items, \%main_items);
+        next if $opt->{deprecated};
+        find_documentation(\@options, $opt, \%tex_items, \%main_items);
     }
 
-    local $" = "\n";
-    print <<EOT;
+    my ($opt, $not_found_in);
+
+format STDOUT_TOP =
 Undocumented options          Not In:
 ====================          ==================
-EOT
-    for my $opt (@options) {
-        printf("%-29s ", $opt->[0]);
-        print 'texinfo ' unless $opt->[1];
-        print 'nor ' unless $opt->[1] or $opt->[2];
-        print '--help ' unless $opt->[2];
-        print "\n";
+.
+
+format STDOUT =
+@<<<<<<<<<<<<<<<<<<<          @<<<<<<<<<<<<<<<<<
+$opt->{name},                 $not_found_in
+.
+    foreach $opt (@options) {
+        $not_found_in = join ' ', (
+            ! $opt->{tex}                  ? 'texinfo' : (),
+            !($opt->{tex} || $opt->{main}) ? 'nor'     : (),
+            ! $opt->{main}                 ? '--help'  : (),
+        );
+        write;
     }
 }
 