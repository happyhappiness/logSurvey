 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 */
#include "squid.h"
#include "cache_snmp.h"

#define SNMP_REQUEST_SIZE 4096
#define MAX_PROTOSTAT 5

struct _mib_tree_entry {
	oid	*name;
	int	len;
	oid_ParseFn *parsefunction;
	int	children;
	struct _mib_tree_entry **leaves;
	struct _mib_tree_entry *parent;
};

struct _snmpUdpData {
    struct sockaddr_in address;
    void *msg;
    int len;
    struct _snmpUdpData *next;
};

typedef struct _snmpUdpData snmpUdpData;
typedef struct _mib_tree_entry mib_tree_entry;

mib_tree_entry *mib_tree_head;
snmpUdpData *snmpUdpHead = NULL;
snmpUdpData *snmpUdpTail = NULL;

extern void (*snmplib_debug_hook) (int, char *);

static void snmpDecodePacket(snmp_request_t * rq);
static void snmpConstructReponse(snmp_request_t * rq, struct snmp_session *Session);
static struct snmp_pdu* snmpAgentResponse(struct snmp_pdu *PDU);

static void snmpUdpSend(int, const struct sockaddr_in *, void *, int);
static void snmpUdpReply(int, void *);
static void snmpAppendUdp(snmpUdpData *);


static mib_tree_entry* snmpAddNode(oid *name, int len, oid_ParseFn *parsefunction, int children, ...);
static oid_ParseFn *snmpTreeNext(oid *Current, snint CurrentLen, oid **Next, snint *NextLen);
static mib_tree_entry* snmpTreeEntry(oid entry, snint len, mib_tree_entry *current);

static oid* snmpCreateOid(int length, ...);
static oid* snmpOidDup(oid * A, snint ALen);                       
static void snmpSnmplibDebug(int lvl, char *buf);


/*
 * The functions used during startup:
 * snmpInit
 * snmpConnectionOpen
 * snmpConnectionShutdown
 * snmpConnectionClose
 */

/*
	Turns the MIB into a Tree structure. Called during the startup process.
*/
void
snmpInit(void)
{
    debug(49, 5) ("snmpInit: Called.\n");

    debug(49, 5) ("snmpInit: Building SNMP mib tree structure\n");

    snmplib_debug_hook = snmpSnmplibDebug;

    mib_tree_head = snmpAddNode(snmpCreateOid(1, 1),
	1, NULL, 1,
	snmpAddNode(snmpCreateOid(2, 1, 3),
	    2, NULL, 1,
	    snmpAddNode(snmpCreateOid(3, 1, 3, 6),
		3, NULL, 1,
		snmpAddNode(snmpCreateOid(4, 1, 3, 6, 1),
		    4, NULL, 1,
		    snmpAddNode(snmpCreateOid(5, 1, 3, 6, 1, 4),
			5, NULL, 1,
			snmpAddNode(snmpCreateOid(6, 1, 3, 6, 1, 4, 1),
			    6, NULL, 1,
			    snmpAddNode(snmpCreateOid(7, 1, 3, 6, 1, 4, 1, 3495),
				7, NULL, 1,
				snmpAddNode(snmpCreateOid(LEN_SQUIDMIB, SQUIDMIB),
				    8, NULL, 5,
				    snmpAddNode(snmpCreateOid(LEN_SQ_SYS, SQ_SYS),
					LEN_SQ_SYS, NULL, 3,
					snmpAddNode(snmpCreateOid(LEN_SQ_SYS + 1, SQ_SYS, 1),
					    LEN_SQ_SYS + 1, snmp_sysFn, 0),
					snmpAddNode(snmpCreateOid(LEN_SQ_SYS + 1, SQ_SYS, 2),
					    LEN_SQ_SYS + 1, snmp_sysFn, 0),
					snmpAddNode(snmpCreateOid(LEN_SQ_SYS + 1, SQ_SYS, 3),
					    LEN_SQ_SYS + 1, snmp_sysFn, 0)),
				    snmpAddNode(snmpCreateOid(LEN_SQ_CONF, SQ_CONF),
					LEN_SQ_CONF, NULL, 5,
					snmpAddNode(snmpCreateOid(LEN_SQ_CONF + 1, SQ_CONF, 1),
					    LEN_SQ_CONF + 1, snmp_confFn, 0),
					snmpAddNode(snmpCreateOid(LEN_SQ_CONF + 1, SQ_CONF, 2),
					    LEN_SQ_CONF + 1, snmp_confFn, 0),
					snmpAddNode(snmpCreateOid(LEN_SQ_CONF + 1, SQ_CONF, 3),
					    LEN_SQ_CONF + 1, snmp_confFn, 0),
					snmpAddNode(snmpCreateOid(LEN_SQ_CONF + 1, SQ_CONF, 4),
					    LEN_SQ_CONF + 1, snmp_confFn, 0),
					snmpAddNode(snmpCreateOid(LEN_SQ_CONF + 1, SQ_CONF, 5),
					    LEN_SQ_CONF + 1, NULL, 6,
					    snmpAddNode(snmpCreateOid(LEN_SQ_CONF + 2, SQ_CONF, 5, 1),
						LEN_SQ_CONF + 2, snmp_confFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_CONF + 2, SQ_CONF, 5, 2),
						LEN_SQ_CONF + 2, snmp_confFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_CONF + 2, SQ_CONF, 5, 3),
						LEN_SQ_CONF + 2, snmp_confFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_CONF + 2, SQ_CONF, 5, 4),
						LEN_SQ_CONF + 2, snmp_confFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_CONF + 2, SQ_CONF, 5, 5),
						LEN_SQ_CONF + 2, snmp_confFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_CONF + 2, SQ_CONF, 5, 6),
						LEN_SQ_CONF + 2, snmp_confFn, 0))),
				    snmpAddNode(snmpCreateOid(LEN_SQ_PRF, SQ_PRF),
					LEN_SQ_PRF, snmp_confFn, 2,
					snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 1, SQ_PRF, 1),
					    LEN_SQ_PRF + 1, snmp_sysFn, 11,
					    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 2, SQ_PRF, 1, 1),
						LEN_SQ_PRF + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 2, SQ_PRF, 1, 2),
						LEN_SQ_PRF + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 2, SQ_PRF, 1, 3),
						LEN_SQ_PRF + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 2, SQ_PRF, 1, 4),
						LEN_SQ_PRF + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 2, SQ_PRF, 1, 5),
						LEN_SQ_PRF + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 2, SQ_PRF, 1, 6),
						LEN_SQ_PRF + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 2, SQ_PRF, 1, 7),
						LEN_SQ_PRF + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 2, SQ_PRF, 1, 8),
						LEN_SQ_PRF + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 2, SQ_PRF, 1, 9),
						LEN_SQ_PRF + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 2, SQ_PRF, 1, 10),
						LEN_SQ_PRF + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 2, SQ_PRF, 1, 11),
						LEN_SQ_PRF + 2, snmp_sysFn, 0)),
					snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 1, SQ_PRF, 2),
					    LEN_SQ_PRF + 1, snmp_sysFn, 2,
					    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 2, SQ_PRF, 2, 1),
						LEN_SQ_PRF + 2, snmp_sysFn, 14,
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 1, 1),
						    LEN_SQ_PRF + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 1, 2),
						    LEN_SQ_PRF + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 1, 3),
						    LEN_SQ_PRF + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 1, 4),
						    LEN_SQ_PRF + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 1, 5),
						    LEN_SQ_PRF + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 1, 6),
						    LEN_SQ_PRF + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 1, 7),
						    LEN_SQ_PRF + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 1, 8),
						    LEN_SQ_PRF + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 1, 9),
						    LEN_SQ_PRF + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 1, 10),
						    LEN_SQ_PRF + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 1, 11),
						    LEN_SQ_PRF + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 1, 12),
						    LEN_SQ_PRF + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 1, 13),
						    LEN_SQ_PRF + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 1, 14),
						    LEN_SQ_PRF + 3, snmp_sysFn, 0)),
					    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 2, SQ_PRF, 2, 2),
						LEN_SQ_PRF + 2, snmp_sysFn, 1,
						snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 3, SQ_PRF, 2, 2, 1),
						    LEN_SQ_PRF + 3, snmp_sysFn, 8,
						    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 4, SQ_PRF, 2, 2, 1, 1),
							LEN_SQ_PRF + 4, snmp_sysFn, 0),
						    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 4, SQ_PRF, 2, 2, 1, 2),
							LEN_SQ_PRF + 4, snmp_sysFn, 0),
						    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 4, SQ_PRF, 2, 2, 1, 3),
							LEN_SQ_PRF + 4, snmp_sysFn, 0),
						    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 4, SQ_PRF, 2, 2, 1, 4),
							LEN_SQ_PRF + 4, snmp_sysFn, 0),
						    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 4, SQ_PRF, 2, 2, 1, 5),
							LEN_SQ_PRF + 4, snmp_sysFn, 0),
						    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 4, SQ_PRF, 2, 2, 1, 6),
							LEN_SQ_PRF + 4, snmp_sysFn, 0),
						    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 4, SQ_PRF, 2, 2, 1, 7),
							LEN_SQ_PRF + 4, snmp_sysFn, 0),
						    snmpAddNode(snmpCreateOid(LEN_SQ_PRF + 4, SQ_PRF, 2, 2, 1, 8),
							LEN_SQ_PRF + 4, snmp_sysFn, 0))))),
				    snmpAddNode(snmpCreateOid(LEN_SQ_NET, SQ_NET),
					LEN_SQ_NET, snmp_confFn, 3,
					snmpAddNode(snmpCreateOid(LEN_SQ_NET + 1, SQ_NET, 1),
					    LEN_SQ_NET + 1, snmp_sysFn, 9,
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 1, 1),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 1, 2),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 1, 3),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 1, 4),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 1, 5),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 1, 6),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 1, 7),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 1, 8),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 1, 9),
						LEN_SQ_NET + 2, snmp_sysFn, 0)),
					snmpAddNode(snmpCreateOid(LEN_SQ_NET + 1, SQ_NET, 2),
					    LEN_SQ_NET + 1, snmp_sysFn, 8,
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 2, 1),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 2, 2),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 2, 3),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 2, 4),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 2, 5),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 2, 6),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 2, 7),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 2, 8),
						LEN_SQ_NET + 2, snmp_sysFn, 0)),
					snmpAddNode(snmpCreateOid(LEN_SQ_NET + 1, SQ_NET, 3),
					    LEN_SQ_NET + 1, snmp_sysFn, 3,
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 3, 1),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 3, 2),
						LEN_SQ_NET + 2, snmp_sysFn, 0),
					    snmpAddNode(snmpCreateOid(LEN_SQ_NET + 2, SQ_NET, 3, 3),
						LEN_SQ_NET + 2, snmp_sysFn, 0))),
				    snmpAddNode(snmpCreateOid(LEN_SQ_MESH, SQ_MESH),
					LEN_SQ_MESH, snmp_confFn, 2,
					snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 1, SQ_MESH, 1),
					    LEN_SQ_MESH + 1, snmp_sysFn, 1,
					    snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 2, SQ_MESH, 1, 1),
						LEN_SQ_MESH + 2, snmp_sysFn, 13,
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 1, 1, 1),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 1, 1, 2),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 1, 1, 3),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 1, 1, 4),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 1, 1, 5),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 1, 1, 6),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 1, 1, 7),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 1, 1, 8),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 1, 1, 9),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 1, 1, 10),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 1, 1, 11),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 1, 1, 12),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 1, 1, 13),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0))),
					snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 1, SQ_MESH, 2),
					    LEN_SQ_MESH + 1, snmp_sysFn, 1,
					    snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 2, SQ_MESH, 2, 1),
						LEN_SQ_MESH + 2, snmp_sysFn, 9,
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 2, 1, 1),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 2, 1, 2),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 2, 1, 3),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 2, 1, 4),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 2, 1, 5),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 2, 1, 6),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 2, 1, 7),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 2, 1, 8),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0),
						snmpAddNode(snmpCreateOid(LEN_SQ_MESH + 3, SQ_MESH, 2, 1, 9),
						    LEN_SQ_MESH + 3, snmp_sysFn, 0))))
				)
			    )
			)
		    )
		)
	    )
	)
	);

    debug(49, 9) ("snmpInit: Completed SNMP mib tree structure\n");
}

void
snmpConnectionOpen(void)
{
    u_short port;
    struct sockaddr_in xaddr;
    socklen_t len;
    int x;

	debug(49, 5) ("snmpConnectionOpen: Called\n");
    if ((port = Config.Port.snmp) > (u_short) 0) {
        enter_suid();
        theInSnmpConnection = comm_open(SOCK_DGRAM,
            0,
            Config.Addrs.snmp_incoming,
            port,
            COMM_NONBLOCKING,
            "SNMP Port");
        leave_suid();
        if (theInSnmpConnection < 0)
            fatal("Cannot open snmp Port");
        commSetSelect(theInSnmpConnection, COMM_SELECT_READ, snmpHandleUdp, NULL, 0);
        debug(1, 1) ("Accepting SNMP messages on port %d, FD %d.\n",
            (int) port, theInSnmpConnection);
        if (Config.Addrs.snmp_outgoing.s_addr != no_addr.s_addr) {
            enter_suid();
            theOutSnmpConnection = comm_open(SOCK_DGRAM,
                0,
                Config.Addrs.snmp_outgoing,
                port,
                COMM_NONBLOCKING,
                "SNMP Port");
            leave_suid();
            if (theOutSnmpConnection < 0)
                fatal("Cannot open Outgoing SNMP Port");
            commSetSelect(theOutSnmpConnection,
                COMM_SELECT_READ,
                snmpHandleUdp,
                NULL, 0);
            debug(1, 1) ("Outgoing SNMP messages on port %d, FD %d.\n",
                (int) port, theOutSnmpConnection);
            fd_note(theOutSnmpConnection, "Outgoing SNMP socket");
            fd_note(theInSnmpConnection, "Incoming SNMP socket");
        } else {
            theOutSnmpConnection = theInSnmpConnection;
        }
        memset(&theOutSNMPAddr, '\0', sizeof(struct in_addr));
        len = sizeof(struct sockaddr_in);
        memset(&xaddr, '\0', len);
        x = getsockname(theOutSnmpConnection,
            (struct sockaddr *) &xaddr, &len);
        if (x < 0)
            debug(51, 1) ("theOutSnmpConnection FD %d: getsockname: %s\n",
                theOutSnmpConnection, xstrerror());
        else 
            theOutSNMPAddr = xaddr.sin_addr;
    }
}

void
snmpConnectionShutdown(void)
{
    if (theInSnmpConnection < 0)
        return;
    if (theInSnmpConnection != theOutSnmpConnection) {
        debug(49, 1) ("FD %d Closing SNMP socket\n", theInSnmpConnection);
        comm_close(theInSnmpConnection);
    }
    /*
     * Here we set 'theInSnmpConnection' to -1 even though the SNMP 'in'
     * and 'out' sockets might be just one FD.  This prevents this
     * function from executing repeatedly.  When we are really ready to
     * exit or restart, main will comm_close the 'out' descriptor.
     */ theInSnmpConnection = -1;
    /*
     * Normally we only write to the outgoing SNMP socket, but we
     * also have a read handler there to catch messages sent to that
     * specific interface.  During shutdown, we must disable reading
