#include "highscore.h"
#include <QDebug>
#include <QFileInfo>
#include <QString>



Highscore::Highscore() {

    view= new QTableView;
    model = new QStandardItemModel(0,2);
   QMap<QString,int> map;
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Score")));
    view->setModel(model);
    qDebug()<<"readFromFile"<<endl;
    QFileInfo info("highscore.txt");
    qDebug()<<info.absoluteFilePath();
    QString filename= info.absoluteFilePath();
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"Error in file.open"<<endl;
    }
    if(file.open(QIODevice::ReadOnly));
    QTextStream stream(&file);
    int i=0;
    while(!stream.atEnd()){
       QString line=stream.readLine();
           int posplayer=line.indexOf("|");
           int posscore=line.length()-posplayer;
           QString player=line.left(posplayer);
           QString score= line.right(posscore-1);
           int sc=score.toInt();

           map.insert(player,sc);
  //  view->setColumnWidth(0,350);
    //view->setColumnWidth(1,350);
    int nW=view->columnWidth(0);
    int sW=view->columnWidth(1);

    view->sortByColumn(1,Qt::AscendingOrder);
    }
}

void Highscore::readFromFile(){
    qDebug()<<"readFromFile"<<endl;
    QFileInfo info("highscore.txt");
    qDebug()<<info.absoluteFilePath();
    QString filename= info.absoluteFilePath();
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"Error in file.open"<<endl;
    }
    if(file.open(QIODevice::ReadOnly));
    QTextStream stream(&file);
    int i=0;
    while(!stream.atEnd()){
       QString line=stream.readLine();
           int posplayer=line.indexOf("|");
           int posscore=line.length()-posplayer;
           QString player=line.left(posplayer);
           QString score= line.right(posscore-1);
           int sc=score.toInt();

           map.insert(player,sc);
       }
   // QMapIterator<QString,int> iter(map);
    /*while(iter.hasNext()){
        iter.next();
        qDebug() <<iter.key() <<" : " << iter.value();
    }*/

}

void Highscore::update() {
    readFromFile();
    QMapIterator<QString,int> it(map);
        int rows=0;
    while (it.hasNext())
    {
        it.next();
        QString player=it.key();
        int value= it.value();
        QString score= QString::number(value);
        QStandardItem * itemName= new QStandardItem(player);
        QStandardItem * itemScore= new QStandardItem(score);

        model->setItem(rows,0,itemName);
        model->setItem(rows,1,itemScore);
        //list.insert(rows,);
        //qDebug() << line << "Player : "<<player<<" Score: "<<score<<endl;
         rows++;

     }

    rows=0;
    view->setModel(model);
  view->setColumnWidth(0,349);
    view->setColumnWidth(1,349);
}
bool Highscore::fileContainsPlayer(QString string){
    QFileInfo info("highscore.txt");
    qDebug()<<info.absoluteFilePath();
    QString filename= info.absoluteFilePath();
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"Error in file.open"<<endl;
    }
    if(file.open(QIODevice::ReadOnly));
    QTextStream stream(&file);
    while(!stream.atEnd()){
       QString line=stream.readLine();
       if(line.contains(string))
       {

          return true;
       }
    }

    file.close();
    return false;

}
void Highscore::writeToFile(){
    QFileInfo info("highscore.txt");
    qDebug()<<info.absoluteFilePath();
    QString filename= info.absoluteFilePath();
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);
    QMapIterator<QString,int> itmap(map);
    while(itmap.hasNext()){
        itmap.next();
        QString player=itmap.key();
        int score=itmap.value();
        stream<<"  "<<player.toUtf8().constData()<<"|"<<score<<endl;
        qDebug() <<itmap.key() <<" : " << itmap.value();
    }
    file.close();


}
void Highscore::insertHighsore(QString string, int scoreNew) {


      if(map.contains(string)){
          map.value(string,scoreNew);
          qDebug ()<<"insert highscore map.contains(string) \n";
      }
      else {
          map.insert(string,scoreNew);
          writeToFile();
      }


      /*
      if(!fileContainsPlayer(string)){
      QFileInfo info("highscore.txt");
      qDebug()<<info.absoluteFilePath();
      QString filename= info.absoluteFilePath();
      QFile file(filename);

      if(!file.open(QIODevice::Append)){
          qDebug()<<"Error in file.open"<<endl;
      }
      if(file.open(QIODevice::Append));
      QTextStream stream(&file);
      qint64 last =stream.pos();
      stream.seek(last);
      stream<<"  "<<string.toUtf8().constData()<<"|"<<scoreNew<<endl;
      file.close();
    }
     else{
          QFileInfo info("highscore.txt");
          qDebug()<<info.absoluteFilePath();
          QString filename= info.absoluteFilePath();
          QFile file(filename);

          if(!file.open(QIODevice::ReadOnly)){
              qDebug()<<"Error in file.open"<<endl;
          }
          if(file.open(QIODevice::ReadOnly));
          QTextStream stream(&file);
          while(!stream.atEnd()){
             QString line=stream.readLine();
             if(line.contains(string))
             {
                 qDebug()<<" Highscore contains "<<string<<endl;
                // QString line2= stream.readLine();
                 int posplayer=line.indexOf("|");
                 int posscore=line.length()-posplayer;
                 QString player=line.left(posplayer);
                 QString score= line.right(posscore-1);
                 int sc=score.toInt();
                 qDebug()<<"Before Highscore contains "<<string<< "  Score: "<<sc<<endl;
                 sc=sc+scoreNew;
                 QString lineChange= player+"|"+sc;
              //   changeLine(line,lineChange);
                 qDebug()<<"After Highscore contains "<<string<< "  Score: "<<sc<<endl;
                break;
             }
          }

          file.close();
    */

}

void Highscore::settings(){

    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->setSelectionMode(QAbstractItemView::NoSelection);
    view->setFocusPolicy(Qt::NoFocus);

    //view->resize(400,400);
            //horizontalHeader()->setResizeMode(8, QHeaderView::Fixed);

 }
