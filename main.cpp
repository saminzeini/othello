#include "login_window.h"
int main(int argc,char* argv[]) {
    QApplication *app=new QApplication(argc,argv);
    login *a=new login(1000,700);
    return app->exec();
}
