#ifndef DIALOG_H
#define DIALOG_H

#include"FxOrderHeader.h"
#include<QDialog>
#include<QHBoxLayout>
#include<QComboBox>
#include<QLabel>
#include<QLineEdit>
#include<QSpacerItem>
#include<QPushButton>

class CFxOrderList : public QDialog
{
    Q_OBJECT

public:
    CFxOrderList(QWidget *parent = nullptr);
    ~CFxOrderList();

private:
    void AddItem();
    void UpdateAmount();


public slots:
    void sl_addmore();
    void sl_combobox();
    void sl_totalBox();
    void sl_checkout();
    void sl_showDetail();

private:
    std::map<QComboBox*,QLabel*> m_Map;
    std::map<QComboBox*,std::tuple<QLineEdit*,QLabel*,QComboBox*>> m_Map2;
    QVBoxLayout*  m_pVertical;
    QLabel* m_pTotalproduct;
    QLabel* m_pOrderId;
    QLabel* m_pTotalproductamt;
    std::vector<std::tuple<QComboBox*,QLabel*,QComboBox*,QLineEdit*>> m_List;
    std::vector<QHBoxLayout*> m_horizontalList;
};
#endif // DIALOG_H
