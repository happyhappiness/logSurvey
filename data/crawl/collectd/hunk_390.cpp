 
 =back
 
+=head2 Plugin C<notify_email>
+
+The I<notify_email> plugin uses the I<ESMTP> library to send notifications to a
+configured email address.
+
+I<libESMTP> is available from L<http://www.stafford.uklinux.net/libesmtp/>.
+
+Available configuration options:
+
+=over 4
+
+=item B<From> I<Address>
+
+Email address from which the emails should appear to come from.
+
+Default: C<root@localhost>
+
+=item B<Recipient> I<Address>
+
+Configures the email address(es) to which the notifications should be mailed.
+May be repeated to send notifications to multiple addresses.
+
+At least one B<Recipient> must be present for the plugin to work correctly.
+
+=item B<SMTPServer> I<Hostname>
+
+Hostname of the SMTP server to connect to.
+
+Default: C<localhost>
+
+=item B<SMTPPort> I<Port>
+
+TCP port to connect to.
+
+Default: C<25>
+
+=item B<SMTPUser> I<Username>
+
+Username for ASMTP authentication. Optional.
+
+=item B<SMTPPassword> I<Password>
+
+Password for ASMTP authentication. Optional.
+
+=item B<Subject> I<Subject>
+
+Subject-template to use when sending emails. There must be exactly two
+string-placeholders in the subject, given in the standard I<printf(3)> syntax,
+i.E<nbsp>e. C<%s>. The first will be replaced with the severity, the second
+with the hostname.
+
+Default: C<Collectd notify: %s@%s>
+
+=back
+
 =head2 Plugin C<ntpd>
 
 =over 4