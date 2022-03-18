#ifndef SETTINGDB_GLOBAL_H
#define SETTINGDB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SETTINGDB_LIBRARY)
#  define SETTINGDB_EXPORT Q_DECL_EXPORT
#else
#  define SETTINGDB_EXPORT Q_DECL_IMPORT
#endif

#endif // SETTINGDB_GLOBAL_H
