QT       += core gui
TEMPLATE = app
CONFIG += C++11
QT += multimedia
QMAKE_CXXFLAGS_RELEASE += -O2
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


SOURCES += code/main.cpp \
code/mainwindow.cpp \
    code/bullet.cpp \
    code/player.cpp \
    code/lifepoint.cpp \
    code/battlefield.cpp \
    code/level1.cpp \
    code/obstacle.cpp \
    code/highscore.cpp \
    code/interface.cpp \
    code/wind.cpp \
    code/game.cpp \
    code/level2.cpp \
    code/level3.cpp \
    code/weaponlabels.cpp \
    code/anglearrow.cpp \
    code/button.cpp

HEADERS += code/mainwindow.h \
    code/bullet.h \
    code/player.h \
    code/soundengine.h \
    code/lifepoint.h \
    code/battlefield.h \
    code/level1.h \
    code/soundengine.h \
    code/highscore.h \
    code/interface.h \
    code/wind.h \
    code/obstacle.h \
    code/game.h \
    code/level2.h \
    code/level3.h \
    code/weaponlabels.h \
    code/anglearrow.h \
    code/button.h

FORMS    += code/mainwindow.ui \
    code/mainwindow.ui



RESOURCES += \
    resources.qrc

DISTFILES += \
    code/Sounds/gun-gunshot-02.wav \
    code/Images/BunnySmall.png \
    code/Images/carrot.png \
    code/Images/FullHeartSmall.png \
    code/Images/HeartSmall.png \
    code/Images/HeartWithEarsSmall.png \
    code/Images/Interface.png \
    code/Images/InvertedBunnySmall.png \
    code/Images/lifePoints.png \
    code/Sounds/gun-gunshot-02.wav \
    code/Images/BunnySmall.png \
    code/Images/carrot.png \
    code/Images/FullHeartSmall.png \
    code/Images/HeartSmall.png \
    code/Images/HeartWithEarsSmall.png \
    code/Images/Interface.png \
    code/Images/InvertedBunnySmall.png \
    code/Images/lifePoints.png \
    code/highscore.txt \
    code/Images/SquareFrame.png \
    code/Images/SprayB_W.png \
    code/Images/MachineGunSquareB_W.png \
    code/Images/EggsplosiveSquareB_W.png \
    code/Images/MinigunSquareB_W.png \
    code/Images/MachineGunSquare.png \
    code/Images/CarrotSquare.png \
    code/Images/Spray.png \
    code/Images/MinigunSquare.png \
    code/Images/EggsplosiveSquare.png
