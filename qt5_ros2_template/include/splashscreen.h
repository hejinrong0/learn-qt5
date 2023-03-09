#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>
#include <QPropertyAnimation>

class SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit SplashScreen(const QPixmap &pixmap); //
    ~SplashScreen();
    static SplashScreen *getInstance();

protected:
    void paintEvent (QPaintEvent *event);
private:
    static SplashScreen *m_instance;
};

#endif // SPLASHSCREEN_H
