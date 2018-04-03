 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 */

#include "squid.h"
#include "RebuildState.h"
#include "SquidTime.h"
#include "StoreSwapLogData.h"
#include "UFSSwapLogParser.h"

CBDATA_NAMESPACED_CLASS_INIT(Fs::Ufs,RebuildState);

Fs::Ufs::RebuildState::RebuildState(RefCount<UFSSwapDir> aSwapDir) :
                sd (aSwapDir), LogParser(NULL), e(NULL), fromLog(true), _done (false)
{
    /*
     * If the swap.state file exists in the cache_dir, then
