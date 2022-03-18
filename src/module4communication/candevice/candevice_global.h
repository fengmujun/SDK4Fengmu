#ifndef CANDEVICE_GLOBAL_H
#define CANDEVICE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CANDEVICE_LIBRARY)
#  define CANDEVICE_EXPORT Q_DECL_EXPORT
#else
#  define CANDEVICE_EXPORT Q_DECL_IMPORT
#endif

#endif // CANDEVICE_GLOBAL_H
