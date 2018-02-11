
#include "login_window.h"
login::login(int height,int width,QWidget * parent) :QWidget(parent) {
  this->setFixedSize(1000, 700);
    this->setGeometry(400,0,1000,700);
     QPalette color(palette());
    color.setColor(QPalette::Background,Qt::black);
    setAutoFillBackground(true);
    setPalette(color);
    QLabel *picture = new QLabel(this);
    picture->setStyleSheet(" QLabel{ background-color : yellow; color : yellow; }");
    picture->setPixmap(QPixmap("menu.jpg"));
    picture->setGeometry(0,0,1000,700);
    picture->setAlignment(Qt::AlignCenter);
    picture->setAttribute(Qt::WA_TranslucentBackground);
    QFont f("serif");
    f.setItalic(true);
    f.setPointSize(35);
    f.setBold(true);
    startButton=new QPushButton("start", this);
    startButton->setFont(f);
    startButton->setGeometry(380,480+20,200,50);
    startButton->setStyleSheet(" QPushButton{  color : DarkRed; }");

    exit=new QPushButton("exit", this);
    exit->setFont(f);
    exit->setGeometry(380,480+126,200,50);
    exit->setStyleSheet(" QPushButton{  color : DarkGreen; }");


  

    connect(startButton, SIGNAL(clicked()), this, SLOT(request_login()));
    connect(exit, SIGNAL(clicked()), QCoreApplication::instance(), SLOT(quit()));

    show();
}
void login::request_login() {
    this->deleteLater();
    game *mygame=new game(1000,800,"medium",0);


}
void login::quit() {
    this->deleteLater();
   // game *mygame=new game(1000,800,"medium",0);


}
//

