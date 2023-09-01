#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* ���ñ����ʽΪutf-8 Ĭ�ϵ������ �޷�ʶ������·�� �����������Ҫ����Ϊutf-8 */
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    /* ���ó���Ĺ���Ŀ¼Ϊ��ִ���ļ�����Ŀ¼ */
    QDir::setCurrent(QCoreApplication::applicationDirPath());

    MainWindow w;
    w.show();
    return a.exec();
}
