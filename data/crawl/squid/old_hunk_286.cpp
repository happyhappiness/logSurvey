#include "squid.h"
#include "parser/BinaryTokenizer.h"
#include "security/Handshake.h"
#if USE_OPENSSL
#include "ssl/support.h"
#endif

Security::ProtocolVersion::ProtocolVersion(BinaryTokenizer &tk):
    context(tk, ".version"),
    vMajor(tk.uint8(".major")),
    vMinor(tk.uint8(".minor"))
{
    context.success();
}

Security::TLSPlaintext::TLSPlaintext(BinaryTokenizer &tk):
    context(tk, "TLSPlaintext"),
    type(tk.uint8(".type")),
    version(tk),
    length(tk.uint16(".length"))
{
    Must(version.vMajor == 3 && version.vMinor <= 3);
    Must(type >= ctChangeCipherSpec && type <= ctApplicationData);
    fragment = tk.area(length, ".fragment");
    context.success();
}

Security::Handshake::Handshake(BinaryTokenizer &tk):
    context(tk, "Handshake"),
    msg_type(tk.uint8(".msg_type")),
    length(tk.uint24(".length")),
    body(tk.area(length, ".body"))
{
    context.success();
}

Security::Alert::Alert(BinaryTokenizer &tk):
    context(tk, "Alert"),
    level(tk.uint8(".level")),
    description(tk.uint8(".description"))
{
    context.success();
}

Security::Extension::Extension(BinaryTokenizer &tk):
    context(tk, "Extension"),
    type(tk.uint16(".type")),
    length(tk.uint16(".length")),
    body(tk.area(length, ".body"))
{
    context.success();
}

Security::Sslv2Record::Sslv2Record(BinaryTokenizer &tk):
    context(tk, "Sslv2Record"),
    length(0)
{
    const uint16_t head = tk.uint16(".head");
    length = head & 0x7FFF;
    Must((head & 0x8000) && length); // SSLv2 message [without padding]
    fragment = tk.area(length, ".fragment");
    context.success();
