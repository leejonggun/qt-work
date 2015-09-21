#ifndef CUSTOMLOGGER
#define CUSTOMLOGGER

#endif // CUSTOMLOGGER

enum DebugLevel
{
    INFO = 0,
    DEBUG,
    WARNING,
    CRITICAL,
    FATAL,
};

void customLog(int level, const char *message, ...)
{
    static char buf[4096];
    va_list a_list;
    va_start(a_list, message);
    vsnprintf(buf, sizeof(buf), message, a_list);
    va_end(a_list);
    switch(level)
    {
    case INFO:
        //qInfo("%s", buf);
        break;
    case DEBUG:
        qDebug("%s", buf);
        break;
    case WARNING:
        qWarning("%s", buf);
        break;
    case CRITICAL:
        qCritical("%s", buf);
        break;
    case FATAL:
        // Note: When qFatal is called, the application will be crashed.
        qFatal("%s", buf);
        break;
    default:
        break;
    }
}
