#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopWidget>
#include <QMessageBox>
#include <QDebug>
#include <QProcess>
#include <QPixmap>
#include <QGraphicsView>
#include <QFontDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainWindowInit();
    animationInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mainWindowInit()
{
    //this->setGeometry(0,0,QApplication::desktop()->screenGeometry().width(),QApplication::desktop()->screenGeometry().height());
    this->setGeometry(0,0,800,480);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet("QToolTip{border-radius:4;border:1px solid rgb(118, 118, 118); color:white; font-size:15px;}");
    flagAppExec = true;
    scrollingFlag = false;

    //��Wiget���������ñ���
    mainWidget = new QWidget(this);
    this->setCentralWidget(mainWidget);
//    if(this->width()<800)
//        mainWidget->setStyleSheet("border-image:url(:/icon/330822.png)");
//    else
        mainWidget->setStyleSheet("border-image:url(:/icon/abc.png)");
    mainWidget->installEventFilter(this);


    appWidgetParent = new QWidget(this);

    appWidgetParent->setGeometry((float)0/800*this->geometry().width(),(float)100/480*this->geometry().height(),
                                 this->geometry().width(),this->geometry().height());
    appWidgetParent->setStyleSheet("border-image:transparent");

    appWidget = new QWidget(appWidgetParent);
    appWidget->setGeometry(0,0,
                           4*this->geometry().width(),(float)400/800*this->geometry().width());
    appWidget->setStyleSheet("border-image:transparent");
    appWidget->installEventFilter(this);


    loopCount = 0;
    QStringList strList;

    QFont font ( "PangMenZhengDao", 20, 40);
    font.setBold(true);


    font.setPixelSize((float)18/800*this->geometry().width());
    strList<<"Music"<<"MediaPlayer"<<"Internet"<<"Weather"<<"Time"<<"File"<<"ImageViewer"<<"Calculator"<<"Reading"
          <<"Notebook"<<"Camera"<<"LED"<<"GraphView"<<"Calendar"<<"Recoder"<<"Temperature"<<"Test";


    /* ѭ���������Widgetλ�����Сȷ�� */
    for(int i = 0; i < 17; i++){
        loopWidgetArr[i] = new QWidget(appWidget);
        switch (i) {
        case 0://����
            loopWidgetArr[i]->setGeometry((float)25/800*this->geometry().width(),(float)0/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 1://ý�岥��
            loopWidgetArr[i]->setGeometry((float)180/800*this->geometry().width(),(float)0/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 2://����
            loopWidgetArr[i]->setGeometry((float)340/800*this->geometry().width(),(float)0/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 3://����
            loopWidgetArr[i]->setGeometry((float)500/800*this->geometry().width(),(float)0/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 4://ʱ��
            loopWidgetArr[i]->setGeometry((float)655/800*this->geometry().width(),(float)0/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 5://�ļ�
            loopWidgetArr[i]->setGeometry((float)25/800*this->geometry().width(),(float)140/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 6://���
            loopWidgetArr[i]->setGeometry((float)180/800*this->geometry().width(),(float)140/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 7://������
            loopWidgetArr[i]->setGeometry((float)340/800*this->geometry().width(),(float)140/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 8://�Ķ�
            loopWidgetArr[i]->setGeometry((float)500/800*this->geometry().width(),(float)140/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 9://���±�
            loopWidgetArr[i]->setGeometry((float)655/800*this->geometry().width(),(float)140/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 10://���
            loopWidgetArr[i]->setGeometry((float)825/800*this->geometry().width(),(float)0/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 11://LED
            loopWidgetArr[i]->setGeometry((float)980/800*this->geometry().width(),(float)0/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 12://ͼƬ�����
            loopWidgetArr[i]->setGeometry((float)1140/800*this->geometry().width(),(float)0/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 13://����
            loopWidgetArr[i]->setGeometry((float)1300/800*this->geometry().width(),(float)0/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 14://¼��
            loopWidgetArr[i]->setGeometry((float)1455/800*this->geometry().width(),(float)0/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 15://�¶�
            loopWidgetArr[i]->setGeometry((float)825/800*this->geometry().width(),(float)140/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        case 16://�ű�����
            loopWidgetArr[i]->setGeometry((float)980/800*this->geometry().width(),(float)140/480*this->geometry().height(),
                                          (float)120/800*this->geometry().width(),(float)170/480*this->geometry().height());
            break;
        default:
            break;
        }
        iconPushButton[i] = new QPushButton(loopWidgetArr[i]);
        iconPushButton[i]->setGeometry((float)15/800*this->geometry().width(),(float)0/480*this->geometry().height(),
                                       (float)90/800*this->geometry().width(),(float)90/800*this->geometry().width());

        iconPushButton[i]->setStyleSheet("border-image:url(:/icon/"+QString::number(i)+".png);background-color:transparent;outline:none;border-radius:8px;");

        loopWidgetArr[i]->setStyleSheet("border-image:transparent;background-color:transparent;outline:none");

        iconPushButton[i]->installEventFilter(this); // ��װ�¼�������
        appNameLabel[i] = new QLabel(loopWidgetArr[i]);
        appNameLabel[i]->setGeometry(0,(float)105/480*this->geometry().height(),loopWidgetArr[i]->geometry().width(),(float)25/480*this->geometry().height());
        appNameLabel[i]->setText(strList[i]);
        appNameLabel[i]->setAlignment(Qt::AlignCenter);
        appNameLabel[i]->setFont(font);
        appNameLabel[i]->setStyleSheet("color:rgba(255,255,255,80%);border-image:transparent;background-color:transparent;outline:none");
    }
    for(int i = 0; i < 3; i++){
        pageWidget[i] = new QWidget(mainWidget);
        if(i==0)
            pageWidget[i]->setStyleSheet("border-image:url(:/icon/page2.png)");
        else
            pageWidget[i]->setStyleSheet("border-image:url(:/icon/page1.png)");
    }
    pageWidget[0]->setGeometry((float)330/800*this->geometry().width(),(float)415/480*this->geometry().height(),
                               (float)15/800*this->geometry().width(),(float)15/800*this->geometry().width());
    pageWidget[1]->setGeometry((float)370/800*this->geometry().width(),(float)415/480*this->geometry().height(),
                               (float)15/800*this->geometry().width(),(float)15/800*this->geometry().width());
//    pageWidget[2]->setGeometry((float)410/800*this->geometry().width(),(float)415/480*this->geometry().height(),
//                               (float)15/800*this->geometry().width(),(float)15/800*this->geometry().width());
//    pageWidget[3]->setGeometry((float)450/800*this->geometry().width(),(float)415/480*this->geometry().height(),
//                               (float)15/800*this->geometry().width(),(float)15/800*this->geometry().width());

    appMainInterface = new QLabel(this);
    font.setPixelSize((float)15/800*this->geometry().width());
    appMainInterface->setGeometry((float)0/800*this->geometry().width(),(float)5/480*this->geometry().height(),
                                  (float)150/800*this->geometry().width(),(float)25/480*this->geometry().height());
    appMainInterface->setText("www.liefyuan.top");
    appMainInterface->setFont(font);
    appMainInterface->setStyleSheet("color:white");
    appMainInterface->setAlignment(Qt::AlignCenter);


    appPathStrList<<"../QMusicPlayer/QMusicPlayer"
                    <<"../QMediaPlayer/QMediaPlayer"
                    <<"../QWebBrowser/QWebBrowser"
                    <<"../QOnlineWeather/QOnlineWeather"
                    <<"../../QClock/bin/QClock.exe"
                    <<"../QFileView/QFileView"
                    <<"../QPictureViewer/QPictureViewer"
                    <<"../QCalculator/QCalculator"
                    <<"../QReader/QReader"
                    <<"../QNotepad/QNotepad"
                    <<"../QCamera/QCamera"
                    <<"../QLed/QLed"
                    <<"../QImageViewer/QImageViewer"
                    <<"../QCalendar/QCalendar"
                    <<"../QRecorder/QRecorder"
                    <<"../QTemperature/QTemperature"
                    <<"../QAutotest/QAutotest";


    appExecTimer = new QTimer(this);
    connect(appExecTimer,SIGNAL(timeout()),this,SLOT(slotappExecTimertimeout()));


    /* ��Ϣ��ʾ���жϵ�ǰĿ¼���Ƿ������app */
    messageLabel = new QLabel(this);
    messageLabel->setGeometry((float)350/800*this->geometry().width(),(float)190/480*this->geometry().height(),
                              (float)100/800*this->geometry().width(),(float)100/800*this->geometry().width());
    messageLabel->setStyleSheet("QLabel{border-radius: 5px;background-color:rgba(200,200,200,80%);color:white}");
    messageLabel->setText("APP \n Not \n Install!");
    messageLabel->setAlignment(Qt::AlignCenter);
    font.setPixelSize((float)13/800*this->geometry().width());
    messageLabel->setFont(font);
    messageLabel->hide();


    rightWidget = new QWidget(this);
    rightWidget->setGeometry((float)200/800*this->geometry().width(),(float)220/480*this->geometry().height(),
                             (float)400/800*this->geometry().width(),(float)110/480*this->geometry().height());
    rightWidget->setStyleSheet("border-image:transparent;background-color:rgba(40,40,40,50%);border-radius: 20px;");
      rightWidget->hide();

}

void MainWindow::animationInit()
{

    /* �󶨶������� */
    propertyAnimation = new QPropertyAnimation(appWidget, "pos");
    propertyAnimation->setDuration(200);//����������0.4s
}



void MainWindow::forward()
{
    qDebug()<<"forward"<<loopCount<<endl;
    flagAppExec = false;//app��������־λ
    appExecTimer->start(200);       // �����ڼ�200ms�ڣ����������
    static int widthValue = appWidgetParent->geometry().width();
    propertyAnimation->stop();
    propertyAnimation->setStartValue(QPoint(appWidget->pos().x(),0));
    switch (loopCount) {
    case 0:
        propertyAnimation->setEndValue(QPoint(-widthValue*1,0));
        break;
    case 1:
        propertyAnimation->setEndValue(QPoint(-widthValue*2,0));
        break;
//    case 2:
//        propertyAnimation->setEndValue(QPoint(-widthValue*3,0));
//        break;
//    default:
//        propertyAnimation->setEndValue(QPoint(-widthValue*2,0));
//        break;
    }

    propertyAnimation->start();
    loopCount++;

    if(loopCount >= 1)
        loopCount=1;

    for(int i=0;i<2;i++){
        if(i==qAbs(loopCount))
            pageWidget[i]->setStyleSheet("border-image:url(:/icon/page2.png)");
        else
            pageWidget[i]->setStyleSheet("border-image:url(:/icon/page1.png)");
    }
}

void MainWindow::backward()
{
    qDebug()<<"backward"<<loopCount<<endl;
    flagAppExec = false;//app��������־λ
    appExecTimer->start(200);       // �����ڼ�200ms�ڣ����������
    propertyAnimation->stop();
    propertyAnimation->setStartValue(QPoint(appWidget->pos().x(),0));
    static int widthValue = appWidgetParent->geometry().width();
    switch (loopCount) {
    case 1:
        propertyAnimation->setEndValue(QPoint(0,0));
        break;
//    case 2:
//        propertyAnimation->setEndValue(QPoint(-widthValue,0));
//        break;
//    case 3:
//        propertyAnimation->setEndValue(QPoint(-widthValue*2,0));
//        break;
//    default:
//        propertyAnimation->setEndValue(QPoint(0,0));
//        break;
    }
    propertyAnimation->start();
    loopCount--;
    if(loopCount <= 0)
        loopCount=0;
    for(int i=0;i<2;i++){
        if(i==qAbs(loopCount))
            pageWidget[i]->setStyleSheet("border-image:url(:/icon/page2.png)");
        else
            pageWidget[i]->setStyleSheet("border-image:url(:/icon/page1.png)");
    }
}


bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    static QGraphicsOpacityEffect  *opacityEffect = new QGraphicsOpacityEffect(); // ����ͼ��Ĳ�͸����
    static QPoint point;
    static QPoint point2;

    if(/*watched == mainWidget||*/watched == appWidget){
        switch (event->type()) {
        case QEvent::MouseButtonPress:
            qDebug()<<cursor().pos().x()<<cursor().pos().y()<<endl;
            point.setX(cursor().pos().x());      // ��¼���µ��x����
            point2.setX(cursor().pos().x());     // ��¼���µ��x����
            rightWidget->setVisible(false);
            messageLabel->setVisible(false);
            break;
        case QEvent::MouseButtonRelease:
        {
            appExecTimer->start(200);       // 200ms��scrollingFlagΪfalse���������Ҫ��
            qDebug()<<loopCount<<endl;
            int offsetx = cursor().pos().x() - point.x();
            int position = loopCount*appWidgetParent->geometry().width();
            if(qAbs(offsetx) >= 50 && flagAppExec == true){ // ����ֵ���󻬶��ľ��룬�˳�����1s�ڽ�ֹ����
                if(offsetx > 0)
                    backward(); // ������
                else
                    forward();  // ��ǰ����
            }else{
                propertyAnimation->stop();
                propertyAnimation->setStartValue(QPoint(appWidget->pos().x(),0));
                propertyAnimation->setEndValue(QPoint(-position,0));
                propertyAnimation->start();
            }
        }
            break;
        case QEvent::MouseMove:
        {
            int moveOffset = cursor().pos().x() - point2.x();
            appWidget->move(appWidget->pos().x()+moveOffset,0);
            point2.setX(cursor().pos().x());
            appExecTimer->stop();
            scrollingFlag = true;
        }

            break;
        default:
            break;
        }
    }
    for(int i = 0; i < 17; i++){
        if(watched == iconPushButton[i]){
            switch (event->type()) {
            case QEvent::MouseButtonPress:
                loopWidgetArr[i]->setGraphicsEffect(opacityEffect);
                opacityEffect->setOpacity(0.8);         // ����ͼ��80%͸��
                point.setX(cursor().pos().x());         // ��¼���µ��x1����
                point2.setX(cursor().pos().x());        // ��¼���µ��x2����
                break;
            case QEvent::Leave:
                opacityEffect->setOpacity(1);           // ����뿪��ͼ��Ϊ��ȫ��͸��
                break;
            case QEvent::MouseButtonRelease:
                appExecTimer->start(200);               // 200ms��scrollingFlagΪfalse���������Ҫ��
                opacityEffect->setOpacity(1);           // �ɿ�����Ϊ��ȫ��͸��
                if( flagAppExec == true && scrollingFlag == false){//�ж���Ļ�Ƿ��ڹ��������˳�����1s�ڲ��������
                    QFile file(appPathStrList[i]);
                    if (!file.exists()){                // �ж�·������û��app����
                        messageLabel->setVisible(true); // û�о���ʾ���app��ʱû����
                        appExecTimer->start(1000);
                    }else{
                        /* ���������Ļ���ڹ�������ôҲ��������� */
                        if(propertyAnimation->state() != QPropertyAnimation::Stopped)
                            return true;
                        this->hide();
                        flagAppExec = false;            // ��������־λ
                        QProcess appProcess;
                        appProcess.setParent(this);
                        appProcess.start(appPathStrList[i]);
                        appProcess.waitForFinished(-1);
                        appExecTimer->start(1000);      // �����˳�1s�󣬹��˵��������ĵ���¼�����ֹ�ٴν���
                        QCursor cursor;
                        cursor.setPos(this->geometry().width(),this->geometry().height());
                        this->show();
                    }
                }
            {
                int offsetx = cursor().pos().x() - point.x();
                //qDebug()<<loopCount<<endl;
                int position = loopCount*appWidgetParent->geometry().width();
                if(qAbs(offsetx) >= 50 && flagAppExec == true){ // ����ֵ���󻬶��ľ��룬�жϳ����˳�1s�ڱ�־λ
                    if(offsetx > 0)
                        backward(); // ������
                    else
                        forward();  // ��ǰ����
                }else{
                    propertyAnimation->stop();
                    propertyAnimation->setStartValue(QPoint(appWidget->pos().x(),0));
                    propertyAnimation->setEndValue(QPoint(-position,0));
                    propertyAnimation->start();
                }

            }

                break;
            case QEvent::MouseMove:
            {
                int moveOffset = cursor().pos().x() - point2.x();
                appWidget->move(appWidget->pos().x()+moveOffset,0);
                point2.setX(cursor().pos().x());
                appExecTimer->stop();
                scrollingFlag = true;//��Ļ�ڹ�������־λ
            }

                break;
            default:
                break;
            }
        }
    }

    if(watched == mainWidget){
        switch (event->type()) {
        case QEvent::MouseButtonPress:
            rightWidget->setVisible(false);
            messageLabel->setVisible(false);
            break;
        default:
            break;
        }
    }


    return QWidget::eventFilter(watched,event);//���¼����ݸ�����
}

void MainWindow::slotappExecTimertimeout()
{
    flagAppExec = true;
    scrollingFlag = false;
    appExecTimer->stop();
    messageLabel->hide();/*��ʾapp����ʱû����1s��ر�*/
}
