#include "analogclock.h"
#include "customlogger.h"

AnalogClock::AnalogClock(QWidget *parent) : QWidget(parent)
{
    this->parent = parent;
    QTimer *qtimer = new QTimer(this);
    connect(qtimer, SIGNAL(timeout()), this, SLOT(update()));
    qtimer->start(1000);
}

void AnalogClock::paintEvent(QPaintEvent *)
{
    static const QPoint hourHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -40)
    };
    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };
    static const QPoint secondHand[3] = {
        QPoint(2, 8),
        QPoint(-2, 8),
        QPoint(0, -100)
    };

    QColor hourColor(127, 0, 0);
    QColor minuteColor(0, 127, 0, 191);
    QColor secondColor(0, 0, 127, 127);

//    customLog(DEBUG, "width(%d), height(%d)", width(), height());
    int side = qMin(width(), height());
//    customLog(DEBUG, "parent: width(%d), height(%d)", parent->width(), parent->height());
    QTime time = QTime::currentTime();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    painter.setPen(Qt::DotLine);
    painter.setBrush(hourColor);

    painter.save();
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();

    painter.setPen(hourColor);

    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);

    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    painter.setPen(minuteColor);

    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);

//    painter.save(); // ??
    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(secondHand, 3);
//    painter.restore(); // ??

    painter.setPen(secondColor);

    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }
}

