#ifndef GENERALDEV_GLOBAL_H
#define GENERALDEV_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GENERALDEV_LIBRARY)
#  define GENERALDEV_EXPORT Q_DECL_EXPORT
#else
#  define GENERALDEV_EXPORT Q_DECL_IMPORT
#endif

#endif // GENERALDEV_GLOBAL_H
