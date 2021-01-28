#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include <QObject>
#include <QMediaPlayer>



/*!
 *  \brief     This class is used to create the sounds.
 *  \details   In the enumeration eSound the available sounds are listed.
 */
class SoundEngine : public QObject {
    Q_OBJECT
public:
    // constructors
    SoundEngine()
        :
        shot(new QMediaPlayer),
        move(new QMediaPlayer)
    {
        shot->setMedia(QUrl("qrc:code/Sounds/gun-gunshot-02.wav"));
        move->setMedia(QUrl("qrc:code/Sound/movement.wav"));

        shot->setVolume(80);
    }

    // attributes
    enum eSound {
        shotSound,
        moveSound
    };

public slots:
    void playSound(int soundNumber)
    {
        switch(soundNumber) {
        case shotSound:
            shot->play();
            break;
        case moveSound:
            move->play();
            break;
        default: break;
        }
    }

private:
    // attributes
    QScopedPointer<QMediaPlayer> shot;
    QScopedPointer<QMediaPlayer> move;
};



#endif // SOUNDENGINE_H
