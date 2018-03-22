 the operation of tar is more complicated.  @xref{Tar and Directories},
 the last section of this tutorial, for more information.
 
+If you don't specify the @samp{--file} option, then @code{tar} will use
+a default.  Usually this default is some physical tape drive attached to
+your machine.  If there is no tape drive attached, or the default is not
+meaningful, then tar will print an error message.  This error message
+might look roughly like one of the following:
+
+@example
+tar: can't open /dev/rmt8 : No such device or address
+tar: can't open /dev/rsmt0 : I/O error
+@end example
+
+If you get an error like this, mentioning a file you didn't specify
+(@file{/dev/rmt8} or @file{/dev/rsmt0} in the examples above), then @code{tar}
+is using a default value for @samp{--file}.  You should generally specify a
+@samp{--file} argument whenever you use @code{tar}, rather than relying
+on a default.
+
 @section Listing Archives
 
 Use @samp{tar --list} to print the names of members stored in an
 archive.  Use a @samp{--file} option just as with @samp{tar --create} to
 specify the name of the archive.  For example, the archive
-@file{my-archive} created in the last section could be examined with the
-command @samp{tar --list --file=my-archive}.  The output of tar would
+@file{afiles.tar} created in the last section could be examined with the
+command @samp{tar --list --file=afiles.tar}.  The output of tar would
 then be:
 
 @example
-foo
-bar
-baz
+apple
+angst
+asparagus
 @end example
 
-The archive @file{my-new-archive} would list as follows:
+The archive @file{bfiles.tar} would list as follows:
 
 @example
-./foo
-bar
-./baz
+./baloons
+baboon
+./bodacious
 @end example
 
-Note that, despite the identical contents of the two archives' members,
-the member names are different.  (Of course, @samp{tar --list
+(Of course, @samp{tar --list --file=empty-archive.tar} would produce no
+output.)
 
 If you use the @samp{--verbose} option with @samp{tar --list}, then tar
 will print out a listing reminiscent of @samp{ls -l}, showing owner,
