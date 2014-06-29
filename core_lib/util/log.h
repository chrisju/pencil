#ifndef LOG_H
#define LOG_H

#if QT_VERSION > QT_VERSION_CHECK( 5, 3, 0 )
	#include<QLoggingCategory>
#endif

#if QT_VERSION < QT_VERSION_CHECK( 5, 3, 0 )
    #define QLoggingCategory QString
    #define qCDebug( C ) qDebug()
#endif

#endif // LOG_H
