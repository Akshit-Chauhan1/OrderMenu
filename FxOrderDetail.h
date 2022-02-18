#ifndef FXORDERDETAIL_H
#define FXORDERDETAIL_H
#include"FxOrderHeader.h"
#include<QDialog>
#include<QDialog>
#include<QHBoxLayout>
#include<QComboBox>
#include<QLabel>
#include<QLineEdit>
#include<QSpacerItem>
#include<QPushButton>



class CFxOrderDetail : public QDialog
{
   Q_OBJECT
public:
    CFxOrderDetail(std::map<int,std::vector<ItemInfo>>& itemInfoMap, QWidget *parent = nullptr);
    ~CFxOrderDetail();

private:
    std::map<int,std::vector<ItemInfo>> m_itemInfoMap;
    std::vector<QHBoxLayout*> m_horizontalDetail;
    std::vector<std::tuple<QLabel*,QLabel*,QLabel*,QLabel*>> m_List;
    QVBoxLayout* m_pVertical;
    QLineEdit* m_pEnterId;
    QGridLayout* m_Maingrid;
      void Clear();

public slots:
    void sl_submit();
};

#endif // FXORDERDETAIL_H
