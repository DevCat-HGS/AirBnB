#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(SistemaUdeASay* sistema, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , sistema(sistema)
{
    ui->setupUi(this);
    
    // Configurar título de la ventana
    setWindowTitle("Sistema UdeASay - Gestión de Alojamientos");
    
    // Verificar que el sistema esté inicializado
    if (!sistema) {
        QMessageBox::critical(this, "Error", "El sistema no está inicializado correctamente.");
        close();
        return;
    }
    
    // Inicializar la interfaz
    actualizarListaAlojamientos();
    actualizarListaHuespedes();
    actualizarListaReservaciones();
    mostrarEstadisticas();
}

MainWindow::~MainWindow()
{
    delete ui;
    // No eliminamos el sistema aquí, ya que se maneja externamente
}

// Slot para manejar el inicio de sesión
void MainWindow::on_btnLogin_clicked()
{
    if (sistema && sistema->login()) {
        QMessageBox::information(this, "Éxito", "Inicio de sesión exitoso.");
        // Actualizar la interfaz después del login
        actualizarListaAlojamientos();
        actualizarListaHuespedes();
        actualizarListaReservaciones();
    } else {
        QMessageBox::warning(this, "Error", "No se pudo iniciar sesión.");
    }
}

// Slot para registrar un nuevo alojamiento
void MainWindow::on_btnRegistrarAlojamiento_clicked()
{
    if (sistema) {
        sistema->registrarAlojamiento();
        actualizarListaAlojamientos();
        mostrarEstadisticas();
        QMessageBox::information(this, "Éxito", "Alojamiento registrado correctamente.");
    }
}

// Slot para realizar una reserva
void MainWindow::on_btnReservar_clicked()
{
    // Aquí iría el código para mostrar un diálogo de reserva
    // y procesar la reserva con el sistema
    QMessageBox::information(this, "Información", "Funcionalidad de reserva en desarrollo.");
}

// Slot para cancelar una reserva
void MainWindow::on_btnCancelarReserva_clicked()
{
    if (sistema) {
        sistema->cancelarReserva();
        actualizarListaReservaciones();
        mostrarEstadisticas();
        QMessageBox::information(this, "Éxito", "Reserva cancelada correctamente.");
    }
}

// Slot para consultar información
void MainWindow::on_btnConsultar_clicked()
{
    if (sistema) {
        sistema->consultar();
        // Aquí se podría mostrar un diálogo con los resultados de la consulta
    }
}

// Slot para salir de la aplicación
void MainWindow::on_btnSalir_clicked()
{
    // Preguntar si desea guardar cambios antes de salir
    QMessageBox::StandardButton respuesta = QMessageBox::question(this, "Salir",
        "¿Desea guardar los cambios antes de salir?",
        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    
    if (respuesta == QMessageBox::Cancel) {
        return; // Cancelar la operación de salida
    }
    
    if (respuesta == QMessageBox::Yes && sistema) {
        sistema->guardarDatos();
    }
    
    close(); // Cerrar la ventana principal
}

// Actualiza la lista de alojamientos en la interfaz
void MainWindow::actualizarListaAlojamientos()
{
    // Aquí se actualizaría un widget de lista con los alojamientos disponibles
    // Por ejemplo: ui->listaAlojamientos->clear();
    // Y luego se agregarían los elementos desde sistema->getAlojamientos()
}

// Actualiza la lista de huéspedes en la interfaz
void MainWindow::actualizarListaHuespedes()
{
    // Aquí se actualizaría un widget de lista con los huéspedes registrados
    // Por ejemplo: ui->listaHuespedes->clear();
    // Y luego se agregarían los elementos desde sistema->getHuespedes()
}

// Actualiza la lista de reservaciones en la interfaz
void MainWindow::actualizarListaReservaciones()
{
    // Aquí se actualizaría un widget de lista con las reservaciones
    // Por ejemplo: ui->listaReservaciones->clear();
    // Y luego se agregarían los elementos desde sistema->getReservaciones()
}

// Muestra estadísticas del sistema
void MainWindow::mostrarEstadisticas()
{
    if (sistema) {
        // Aquí se actualizarían widgets con estadísticas del sistema
        // Por ejemplo: ui->lblMemoria->setText(QString::number(sistema->getMonitor().obtenerMemoria()));
        // ui->lblInteracciones->setText(QString::number(sistema->getMonitor().obtenerInteracciones()));
    }
}