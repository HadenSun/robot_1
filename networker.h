#ifndef NETWORKER_H
#define NETWORKER_H

#include <QObject>
#include <QNetworkReply>

class QNetworkReply;

class NetWorker : public QObject
{
    Q_OBJECT
public:
    //NetWorker是一个单例类，因此它有一个instance()函数用来获得这唯一的实例。作为单例模式，要求构造函数、拷贝构造函数和赋值运算符都是私有的，因此我们将这三个函数都放在 private 块中。
    static NetWorker * instance();
    ~NetWorker();

    void get(const QString &url);

signals:
    void finished(QNetworkReply *reply);

private:
    class Private;
    friend class Private;
    Private *d;
    //以上部分二进制兼容

    explicit NetWorker(QObject *parent  = 0);
    //Q_DECL_EQ_DELETE宏。这个宏是 Qt5 新增加的，意思是将它所修饰的函数声明为 deleted（这是 C++11 的新特性）
    NetWorker(const NetWorker &) Q_DECL_EQ_DELETE;
    NetWorker& operator =(NetWorker rhs) Q_DECL_EQ_DELETE;
};

#endif // NETWORKER_H
