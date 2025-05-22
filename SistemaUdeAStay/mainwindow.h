#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sistemaudeasay.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(SistemaUdeASay* sistema = nullptr, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Slots para manejar eventos de la interfaz
    void on_btnLogin_clicked();
    void on_btnRegistrarAlojamiento_clicked();
    void on_btnReservar_clicked();
    void on_btnCancelarReserva_clicked();
    void on_btnConsultar_clicked();
    void on_btnSalir_clicked();

private:
    Ui::MainWindow *ui;
    SistemaUdeASay* sistema; // Puntero al sistema principal
    
    // Métodos privados para actualizar la interfaz
    void actualizarListaAlojamientos();
    void actualizarListaHuespedes();
    void actualizarListaReservaciones();
    void mostrarEstadisticas();
};
#endif // MAINWINDOW_H