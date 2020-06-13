
#define NO_WARN_UNUSED(code) \
_Pragma("GCC diagnostic push")\
_Pragma("GCC diagnostic ignored \"-Wunused-but-set-variable\"")\
code \
_Pragma("GCC diagnostic pop")
