#include "splashscreen.h"


SplashScreen *SplashScreen::m_instance = nullptr;

SplashScreen::SplashScreen(const QPixmap &pixmap)
    : QSplashScreen(pixmap)
{

}

SplashScreen::~SplashScreen()
{}

SplashScreen *SplashScreen::getInstance()
{
    if(nullptr == m_instance)
    {
        m_instance = new SplashScreen(QPixmap(":/icons/images/space.png"));
    }
    return m_instance;
}

void SplashScreen::paintEvent (QPaintEvent *event)
{
    Q_UNUSED(event);
}
