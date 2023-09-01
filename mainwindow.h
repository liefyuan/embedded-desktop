#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QHBoxLayout>
#include <QLabel>
#include <QDateTime>
#include <QTextCodec>
#include <QFileInfo>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPushButton>
#include <QSlider>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mainWindowInit();                          // �����岼�ֳ�ʼ��
    void animationInit();                           // ������ʾ��س�ʼ��

public slots:
    void backward();
    void forward();
    void slotappExecTimertimeout();

private:
    /* ˽�з��� */
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::MainWindow *ui;

    QWidget         *mainWidget;                    // ��Widget
    QWidget         *appWidgetParent;               // ���app�ĸ�����
    QWidget         *appWidget;                     // ���app������
    QWidget         *loopWidgetArr[17];             // ѭ���������arr
    QWidget         *rightWidget;                   // �ұ�������
    QPushButton     *iconPushButton[17];            // appͼ�갴ť

    QWidget         *pageWidget[3];                 // ҳ��СԲ��
    QLabel          *appNameLabel[17];              // app���ֱ�ǩ
    QLabel          *appMainInterface;              // app������label

    int loopCount;                                  // ѭ������

    QStringList     appPathStrList;                 // app·������
    QTimer          *appExecTimer;                  // ���ڽ�����������󴥵ĵ�
    bool            flagAppExec;                    // ���˱�־λ
    bool            scrollingFlag;                  // �ж�app�����Ƿ����ƶ�

    QPropertyAnimation *propertyAnimation;

    QLabel          *messageLabel;                  //������ʾ��ǰ·������û�����app
};
#endif // MAINWINDOW_H
