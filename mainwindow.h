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
    void mainWindowInit();                          // 主窗体布局初始化
    void animationInit();                           // 天气显示相关初始化

public slots:
    void backward();
    void forward();
    void slotappExecTimertimeout();

private:
    /* 私有方法 */
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::MainWindow *ui;

    QWidget         *mainWidget;                    // 主Widget
    QWidget         *appWidgetParent;               // 存放app的父窗口
    QWidget         *appWidget;                     // 存放app的区域
    QWidget         *loopWidgetArr[17];             // 循环动画面板arr
    QWidget         *rightWidget;                   // 右边隐藏栏
    QPushButton     *iconPushButton[17];            // app图标按钮

    QWidget         *pageWidget[3];                 // 页面小圆点
    QLabel          *appNameLabel[17];              // app名字标签
    QLabel          *appMainInterface;              // app主界面label

    int loopCount;                                  // 循环次数

    QStringList     appPathStrList;                 // app路径定义
    QTimer          *appExecTimer;                  // 用于进入程序后过滤误触的点
    bool            flagAppExec;                    // 过滤标志位
    bool            scrollingFlag;                  // 判断app区域是否在移动

    QPropertyAnimation *propertyAnimation;

    QLabel          *messageLabel;                  //用于提示当前路径下有没有这个app
};
#endif // MAINWINDOW_H
