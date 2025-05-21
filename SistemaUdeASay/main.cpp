#include <QApplication>
#include "mainwindow.h"
#include "sistemaudeasay.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Inicializar el sistema
    SistemaUdeASay sistema;
    
    // Configurar y mostrar la ventana principal
    MainWindow w(&sistema);
    w.show();
    
    return a.exec();
}