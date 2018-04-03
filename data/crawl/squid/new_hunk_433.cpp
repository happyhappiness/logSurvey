#define HELPER_INPUT_BUFFER 8196

/* send OK result to Squid with a string parameter. */
#define SEND_OK(x)  std::cout << "OK " << x << std::endl

/* send ERR result to Squid with a string parameter. */
#define SEND_ERR(x) std::cout << "ERR " << x << std::endl

/* send ERR result to Squid with a string parameter. */
#define SEND_BH(x)  std::cout << "BH " << x << std::endl

/* send TT result to Squid with a string parameter. */
#define SEND_TT(x)  std::cout << "TT " << x << std::endl

#endif /* __SQUID_HELPERS_DEFINES_H */
