#include "ICP.h"
#include "icp_opcode.h"

#define STUB { fatal("icp_*.cc required."); }
#define STUB_RETVAL(x) { fatal("icp_*.cc required."); return (x); }
//#define STUB_RETREF(x) { fatal("icp_*.cc required."); static x v; return v; }

#ifdef __cplusplus
_icp_common_t::_icp_common_t() STUB
