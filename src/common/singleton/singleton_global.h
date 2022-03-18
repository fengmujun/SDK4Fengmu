#ifndef SINGLETON_GLOBAL_H
#define SINGLETON_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SINGLETON_LIBRARY)
#  define SINGLETON_EXPORT Q_DECL_EXPORT
#else
#  define SINGLETON_EXPORT Q_DECL_IMPORT
#endif

#endif // SINGLETON_GLOBAL_H
