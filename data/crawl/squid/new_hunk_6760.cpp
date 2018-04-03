#define READ	    1
#define WRITE	    0

#define SNMP_RESERVE1    0
#define SNMP_RESERVE2    1
#define SNMP_COMMIT      2
#define SNMP_FREE        3

#define RONLY	0xAAAA	/* read access for everyone */
#define RWRITE	0xAABA	/* add write access for community private */
#define NOACCESS 0x0000	/* no access for anybody */

#define INTEGER	    ASN_INTEGER
#define STRING	    ASN_OCTET_STR
#define OBJID	    ASN_OBJECT_ID
#define NULLOBJ	    ASN_NULL


struct trapVar {
    oid	    *varName;
    int	    varNameLen;
    u_char  varType;
    int	    varLen;
    u_char  *varVal;
    struct trapVar *next;  
};

/* from snmp.c*/
extern u_char	sid[];	/* size SID_MAX_LEN */

#endif /* _SNMP_IMPL_H_ */
