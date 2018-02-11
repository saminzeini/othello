
#include <iostream>
#include "game_page.h"
#include "result_menu.h"

game::game(int height, int width, QString name,int lvl, QWidget *parent) {
    QRect rec = QApplication::desktop() -> screenGeometry();
    this -> setGeometry(rec.width() / 2 - width / 2, rec.height() / 2 - height / 2, width, height);
    player_name="user";
    setStyleSheet("background-color: red");
    show();
}
void game::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPen p;
    p.setWidth(10);
    p.setColor(Qt::green);
    painter.setPen(p);
    QFont font;
    font.setPixelSize(30);
    painter.setFont(font);
    painter.drawText(10,50,player_name);
    std::string str=std::to_string(gameCore.score(1));
    painter.drawText(350,50,QString::fromStdString(str));
    p.setColor(Qt::black);
    painter.setPen(p);
    str=std::to_string(gameCore.score(2));
    painter.drawText(450,50,QString::fromStdString(str));
    painter.drawText(700,50,QString("CPU"));
    for(int i=0;i<9;i++)
    {
        p.setColor(Qt::green);
        p.setWidth(5);
        painter.setPen(p);
        painter.drawLine(100*i,200,100*i,1000); 
        painter.drawLine(0,100*i+200,800,100*i+200); 
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(gameCore.getBoard().a[i][j]==1)
            {
                QPen pen=painter.pen();
                pen.setWidth(5);
                pen.setColor(Qt::white);
                painter.setPen(pen);
                painter.setBrush(Qt::white);
                painter.drawEllipse(i*100+50-40,j*100+250-40,80,80);
            }

            if(gameCore.getBoard().a[i][j]==2)
            {
                QPen pen=painter.pen();
                pen.setWidth(4);
                pen.setColor(Qt::black);
                painter.setPen(pen);
                painter.setBrush(Qt::black);
                painter.drawEllipse(i*100+50-40,j*100+250-40,80,80);
            }

        }
    }
    std::vector<Suggestion> ss=gameCore.suggest(1);
    for(int i=0;i<ss.size();i++)
    {
        int x=ss[i].x;
        int y=ss[i].y;
        QPen pen=painter.pen();
        pen.setWidth(4);
        pen.setColor(Qt::red);
        painter.setPen(pen);
        painter.setBrush(Qt::red);
        painter.drawEllipse(x*100+50-10,y*100+250-10,20,20);
    }
}

}
//

