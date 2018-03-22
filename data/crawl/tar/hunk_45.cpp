 # Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 # 02110-1301, USA.
 #
-# Author: Dustin J. Mitchell <dustin@zmanda.com>
+#
+# tar-snapshot-edit
 #
 # This script is capable of replacing values in the 'dev' field of an
 # incremental backup 'snapshot' file.  This is useful when the device
 # used to store files in a tar archive changes, without the files
 # themselves changing.  This may happen when, for example, a device
 # driver changes major or minor numbers.
+#
+# It can also run a check on all the field values found in the
+# snapshot file, printing out a detailed message when it finds values
+# that would cause an "Unexpected field value in snapshot file" error
+# if tar were run using that snapshot file as input.  (See the
+# comments included in the definition of the check_field_values
+# routine for more detailed information regarding these checks.)
+#
+#
+#
+# Author: Dustin J. Mitchell <dustin@zmanda.com>
+#
+# Modified Aug 25, 2011 by Nathan Stratton Treadway <nathanst AT ontko.com>:
+#   * update Perl syntax to work correctly with more recent versions of
+#     Perl.  (The original code worked with in the v5.8 timeframe but 
+#     not with Perl v5.10.1 and later.)
+#   * added a "-c" option to check the snapshot file for invalid field values.
+#   * handle NFS indicator character ("+") in version 0 and 1 files
+#   * preserve the original header/version line when editing version 1
+#     or 2 files.
+#   * tweak output formatting
+#
+#
 
 use Getopt::Std;
 
