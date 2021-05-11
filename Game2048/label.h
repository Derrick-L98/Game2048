#ifndef LABEL_H
#define LABEL_H

#include <QLabel>

class Label : public QLabel
{
    Q_OBJECT
public:
    explicit Label(QWidget *parent = 0);
    void setNum(int num);
    
signals:
    
public slots:
    
};

#endif // LABEL_H
