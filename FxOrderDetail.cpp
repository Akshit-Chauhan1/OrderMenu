#include"FxOrderDetail.h"

CFxOrderDetail::CFxOrderDetail( std::map<int,std::vector<ItemInfo>>& itemInfoMap, QWidget *parent ) : QDialog(parent)
{
    m_itemInfoMap = itemInfoMap;
    m_Maingrid = new QGridLayout;
    setLayout( m_Maingrid );
    m_pVertical = new QVBoxLayout;

    QHBoxLayout *horizontal =new QHBoxLayout;
    QLabel* ordernumber = new QLabel("Enter Oder Id: ");
    ordernumber->setMinimumWidth(120);
    horizontal->addWidget(ordernumber);
    m_pEnterId = new QLineEdit;
    horizontal->addWidget(m_pEnterId);
    QPushButton* button=new QPushButton(" Submit ");
    horizontal->addWidget(button);
    m_pVertical->addLayout(horizontal);
    m_Maingrid->addLayout (m_pVertical,0,0);
    connect( button,SIGNAL( clicked() ),this,SLOT( sl_submit() ) );

}
void CFxOrderDetail::sl_submit()
{
   Clear();
   QString str= m_pEnterId->text();
   int iOrderId= str.toInt();
   auto itemList= m_itemInfoMap[iOrderId];
   auto itr =itemList.begin();
   while(itr!=itemList.end())
   {
       QHBoxLayout *horizontal =new QHBoxLayout;
       QLabel* itemname = new QLabel;
       itemname->setText( itr->ItemName );
       itemname->setMinimumWidth(120);
       horizontal->addWidget( itemname );
       QLabel* quantityperkg = new QLabel;
       quantityperkg->setMinimumWidth(120);
       quantityperkg->setText( itr->perKg );
       horizontal->addWidget( quantityperkg );
       QLabel* Qutantity = new QLabel;
       Qutantity->setMinimumWidth(120);
       Qutantity->setText( itr->quantity + "KG" );
       horizontal->addWidget( Qutantity );
       QLabel* totalamt = new QLabel;
       totalamt->setMinimumWidth(120);
       totalamt->setText( itr->totalAmt + "rs" );
       horizontal->addWidget( totalamt );
       m_pVertical->addLayout(horizontal);
       m_horizontalDetail.push_back(horizontal);
       m_List.push_back( std::make_tuple( itemname, quantityperkg, Qutantity, totalamt ) );
       itr++;

   }

}
CFxOrderDetail::~CFxOrderDetail()
{

}
void CFxOrderDetail :: Clear()
{
    auto iterator =m_List.begin();
    while( iterator!=m_List.end() )
    {
       delete std::get<0>( *iterator );
       delete std::get<1>( *iterator );
       delete std::get<2>( *iterator );
       delete std::get<3>( *iterator );
       iterator++;
    }
    m_List.clear();
    auto itr =  m_horizontalDetail.begin();
    while( itr!=m_horizontalDetail.end() )
    {
        delete *itr;
        itr++;
    }
    m_horizontalDetail.clear();

}
