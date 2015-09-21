#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QPainter>

class AnalogClock : public QWidget
{
    Q_OBJECT
public:
    explicit AnalogClock(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // ANALOGCLOCK_H
