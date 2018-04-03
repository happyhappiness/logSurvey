 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 * 
 * $Id: snmp-internal.h,v 1.1 1998/02/22 11:48:41 kostas Exp $
 * 
 **********************************************************************/

#define SNMP_PORT	    161
#define SNMP_TRAP_PORT	    162
#define SNMP_MAX_LEN	    484

#ifdef DEBUG
#define ERROR(string)	printf("%s(%d): %s\n",__FILE__, __LINE__, string);
#else
#define ERROR(string)
#endif

#endif /* _SNMP_INTERNAL_H_ */