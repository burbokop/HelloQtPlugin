#ifndef HELLO_GLOBAL_H
#define HELLO_GLOBAL_H

#if defined(HELLO_LIBRARY)
#  define HELLO_EXPORT Q_DECL_EXPORT
#else
#  define HELLO_EXPORT Q_DECL_IMPORT
#endif

#endif // HELLO_GLOBAL_H
