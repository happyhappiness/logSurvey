# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
# 02110-1301, USA.
#
# Author: Dustin J. Mitchell <dustin@zmanda.com>
#
# This script is capable of replacing values in the 'dev' field of an
# incremental backup 'snapshot' file.  This is useful when the device
# used to store files in a tar archive changes, without the files
# themselves changing.  This may happen when, for example, a device
# driver changes major or minor numbers.

use Getopt::Std;

