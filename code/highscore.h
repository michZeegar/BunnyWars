#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "QTableView"

#include <QFile>
#include <QStandardItemModel>
#include <QTextStream>



/*!
 *  \brief     This class sets and changes the Highscores.
 *  \details   For a won battle you recieve a fix amount of points.
 */
class Highscore {
public:
    // constructors
    Highscore();



    //methods
    void insertHighsore(QString string, int score);
    void update();
    void readFromFile();
    // attributes
    QTableView * view;
    QStandardItemModel * model;
    QMap<QString,int> map;

private:
    //methods
    void settings();
    void writeToFile();
    bool fileContainsPlayer(QString  string);
};



#endif // HIGHSCORE_H
