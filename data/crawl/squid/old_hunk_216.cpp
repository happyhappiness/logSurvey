#include "squid.h"
#include "parser/BinaryTokenizer.h"
#include "security/Handshake.h"
#if USE_OPENSSL
#include "ssl/support.h"
#endif

Security::FieldGroup::FieldGroup(BinaryTokenizer &tk, const char *description) {
    tk.context = description;
}

void
Security::FieldGroup::commit(BinaryTokenizer &tk) {
    tk.commit();
    tk.context = "";
}

Security::ProtocolVersion::ProtocolVersion(BinaryTokenizer &tk):
    vMajor(tk.uint8(".vMajor")),
    vMinor(tk.uint8(".vMinor"))
{
}

Security::TLSPlaintext::TLSPlaintext(BinaryTokenizer &tk):
    FieldGroup(tk, "TLSPlaintext"),
    type(tk.uint8(".type")),
    version(tk),
    length(tk.uint16(".length")),
    fragment(tk.area(length, ".fragment"))
{
    commit(tk);
}

Security::Handshake::Handshake(BinaryTokenizer &tk):
    FieldGroup(tk, "Handshake"),
    msg_type(tk.uint8(".msg_type")),
    length(tk.uint24(".length")),
    body(tk.area(length, ".body"))
{
    commit(tk);
}

Security::Alert::Alert(BinaryTokenizer &tk):
    FieldGroup(tk, "Alert"),
    level(tk.uint8(".level")),
    description(tk.uint8(".description"))
{
    commit(tk);
}

Security::P24String::P24String(BinaryTokenizer &tk, const char *description):
    FieldGroup(tk, description),
    length(tk.uint24(".length")),
    body(tk.area(length, ".body"))
{
    commit(tk);
}

/// debugging helper to print various parsed records and messages
class DebugFrame
{
public:
    DebugFrame(const char *aName, uint64_t aType, uint64_t aSize):
        name(aName), type(aType), size(aSize) {}

    const char *name;
    uint64_t type;
    uint64_t size;
};

inline std::ostream &
operator <<(std::ostream &os, const DebugFrame &frame)
{
    return os << frame.size << "-byte type-" << frame.type << ' ' << frame.name;
}

/// parses a single TLS Record Layer frame
void
Security::HandshakeParser::parseRecord()
{
    const TLSPlaintext record(tkRecords);

    Must(record.length <= (1 << 14)); // RFC 5246: length MUST NOT exceed 2^14

    // RFC 5246: MUST NOT send zero-length [non-application] fragments
    Must(record.length || record.type == ContentType::ctApplicationData);

    if (currentContentType != record.type) {
        Must(tkMessages.atEnd()); // no currentContentType leftovers
        fragments = record.fragment;
        tkMessages.reset(fragments);
        currentContentType = record.type;
    } else {
        fragments.append(record.fragment);
        tkMessages.reinput(fragments);
        tkMessages.rollback();
    }
    parseMessages();
