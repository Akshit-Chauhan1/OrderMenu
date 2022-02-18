#include "FxOrderList.h"
#include"FxOrderDetail.h"

int iOrderID = 1000;


std::map<int,std::vector<ItemInfo>> show_map;

CFxOrderList::CFxOrderList( QWidget *parent ) : QDialog(parent)
{
    QGridLayout *maingrid = new QGridLayout;
    setLayout( maingrid );
    m_pVertical = new QVBoxLayout;

    AddItem();

    QHBoxLayout *hori =new QHBoxLayout;
    QSpacerItem *spacer =new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed);
    hori->addSpacerItem( spacer );

    QPushButton *button = new QPushButton("ADD MORE");
    hori->addWidget( button );
    m_pVertical->addLayout( hori );

    QHBoxLayout *hori1 =new QHBoxLayout;
    QSpacerItem *spacer1 =new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed);
    hori1->addSpacerItem(spacer1);
    m_pTotalproduct=new QLabel("Total product");
    hori1->addWidget( m_pTotalproduct );

    QSpacerItem *spacer2 =new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed);
    hori1->addSpacerItem(spacer2);
    m_pTotalproductamt=new QLabel("Total Amount");
    hori1->addWidget(m_pTotalproductamt);
    m_pVertical->addLayout(hori1);

    QHBoxLayout *horizontal2 =new QHBoxLayout;
    QSpacerItem *spacer3 =new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed);
    horizontal2->addSpacerItem( spacer3 );
    QPushButton* checkOut =new QPushButton( "Check Out" );
    horizontal2->addWidget( checkOut );
    m_pVertical->addLayout( horizontal2 );

    QHBoxLayout *horizontal3 =new QHBoxLayout;
    m_pOrderId = new QLabel("Order ID");
    horizontal3->addWidget( m_pOrderId );
    QPushButton* show =new QPushButton( "Show Details" );
    horizontal3->addWidget( show );
    m_pVertical->addLayout( horizontal3 );

    maingrid->addLayout(m_pVertical,0,0);

    connect( button, SIGNAL( clicked() ), this, SLOT( sl_addmore() ) );
    connect( checkOut,SIGNAL( clicked() ),this,SLOT( sl_checkout() ) );
    connect( show,SIGNAL( clicked() ),this,SLOT( sl_showDetail() ) );
}

void CFxOrderList::AddItem()
{
    QHBoxLayout *horizontal = new QHBoxLayout;
    QComboBox* pComboBox =new QComboBox;
    pComboBox->addItem("Poha");
    pComboBox->addItem("Chai");
    pComboBox->addItem("Jeera");
    pComboBox->addItem("Wheats");
    pComboBox->addItem("Mustard Oil");
    pComboBox->addItem("Sugar");
    pComboBox->addItem("Tuar Dal");
    pComboBox->addItem("Turmeric Powder");
    horizontal->addWidget( pComboBox );

    QLabel* pPriceLabel = new QLabel("10/kg");
    horizontal->addWidget(pPriceLabel);

    QComboBox* pQuantitybox = new QComboBox;
    horizontal->addWidget( pQuantitybox );

    for( int i=0; i<10 ;i++ )
    {
        pQuantitybox->addItem( QString::number( i ) );
    }

    QLineEdit* pEdit = new QLineEdit;
    horizontal->addWidget( pEdit);
    m_pVertical->insertLayout( m_pVertical->count() - 4, horizontal );

    m_Map.insert( std::make_pair( pComboBox, pPriceLabel) );
    m_Map2.insert( std::make_pair( pQuantitybox, std::make_tuple( pEdit, pPriceLabel, pComboBox ) ) );
    m_List.push_back( std::make_tuple(pComboBox,pPriceLabel,pQuantitybox,pEdit) );
    m_horizontalList.push_back(horizontal);

    connect( pComboBox,SIGNAL( currentIndexChanged( int ) ),this,SLOT( sl_combobox() ) );
    connect( pQuantitybox,SIGNAL( currentIndexChanged( int ) ),this,SLOT( sl_totalBox() ) );

}

void CFxOrderList::sl_combobox()
{
    QComboBox* pComboBox = static_cast<QComboBox*>( sender() );
    auto pPriceLabel = m_Map[pComboBox];

    QString str =  pComboBox->currentText();

    if( str.compare("Poha") == 0 )
    {
        pPriceLabel->setText("10/kg");
    }
    else if( str.compare("Chai") == 0 )
    {
        pPriceLabel->setText("140/kg");
    }
    else if( str.compare("Jeera") == 0 )
    {
         pPriceLabel->setText("1000/kg");
    }
    else if( str.compare("Wheats") == 0 )
    {
        pPriceLabel->setText("145/kg");
    }
    else if( str.compare("Mustard Oil") == 0 )
    {
        pPriceLabel->setText("200/kg");
    }
    else if( str.compare("Sugar") == 0 )
    {
        pPriceLabel->setText("40/kg");
    }
    else if( str.compare("Tuar Dal") == 0 )
    {
        pPriceLabel->setText("150/kg");
    }
    else if(str.compare("Turmeric Powder") == 0)
    {
        pPriceLabel->setText("500/kg");
    }
    else
    {
       pPriceLabel->setText(" oo ");
    }
}

void CFxOrderList::sl_totalBox()
{
    QComboBox* pQuantitybox = static_cast<QComboBox*>( sender() );
    auto controls =m_Map2[pQuantitybox];

    QLineEdit* pEdit = std::get<0>(controls);
    QComboBox* pComboBox=std::get<2>(controls);
    QString name = pComboBox->currentText();

    int totalweight = 0;
    int index = pQuantitybox->currentIndex();

    if( name.compare("Poha") == 0 )
    {
        totalweight = index*10;
        pEdit->setText(QString::number(totalweight));
    }
    else if( name.compare("Chai") == 0 )
    {
        totalweight = index*140;
        pEdit->setText(QString::number(totalweight));
    }
    else if( name.compare("Jeera") == 0 )
    {
        totalweight = index*1000;
        pEdit->setText(QString::number(totalweight));
    }
    else if( name.compare("Wheats") == 0 )
    {
        totalweight = index*145;
        pEdit->setText(QString::number(totalweight));
    }
    else if( name.compare("Mustard Oil") == 0 )
    {
        totalweight = index*200;
        pEdit->setText(QString::number(totalweight));

    }
    else if( name.compare("Sugar") == 0 )
    {
        totalweight = index*40;
        pEdit->setText(QString::number(totalweight));

    }
    else if( name.compare("Tuar Dal") == 0 )
    {
        totalweight = index*150;
        pEdit->setText(QString::number(totalweight));
    }
    else if( name.compare("Turmeric Powder") == 0 )
    {
        totalweight = index*500;
        pEdit->setText(QString::number(totalweight));
    }
    else
    {
        pEdit->setText(" rs");
    }

    UpdateAmount();
}

void CFxOrderList::sl_addmore()
{
    AddItem();
}

void CFxOrderList::UpdateAmount()
{
    int iTotalItemCount=0;
    double dAmount = 0;

    auto itr=m_Map2.begin();

    while( itr!=m_Map2.end() )
    {
       QString str= itr->first->currentText();
       int iItemCount=str.toInt();
       iTotalItemCount+= iItemCount;

       QString sAmt = std::get<0>(itr->second)->text();
       double dLineEditAmt=sAmt.toDouble();
       dAmount+= dLineEditAmt;
       itr++;
    }

     m_pTotalproduct->setText( QString::number( iTotalItemCount ) );
     m_pTotalproductamt->setText( QString::number( dAmount ) );
}

void CFxOrderList::sl_checkout()
{
    std::vector<ItemInfo> items;

    auto itr = m_List.begin();
    while(itr!=m_List.end())
    {
       ItemInfo itemInfo;
       itemInfo.ItemName = std::get<0>( *itr )->currentText();
       itemInfo.perKg= std::get<1>( *itr )->text();
       itemInfo.quantity= std::get<2>( *itr )->currentText();
       itemInfo.totalAmt= std::get<3>( *itr )->text();

       delete std::get<0>( *itr );
       delete std::get<1>( *itr );
       delete std::get<2>( *itr );
       delete std::get<3>( *itr );

       items.push_back( itemInfo );
       itr++;
    }

    m_Map.clear();
    m_Map2.clear();
    m_List.clear();
    auto itrator=m_horizontalList.begin();
    while(itrator!=m_horizontalList.end())
    {
        delete *itrator;
        itrator++;
    }

    m_horizontalList.clear();
    m_pTotalproductamt->setText("Total Amount");
    m_pTotalproduct->setText("Total Product");

    show_map.insert( std::make_pair( iOrderID, items ) );
    AddItem();
    m_pTotalproductamt->setText("Total Amount");
    m_pTotalproduct->setText("Total Product");
    m_pOrderId->setText(QString("Your order ID is: %1").arg( iOrderID++ ));
}

void CFxOrderList::sl_showDetail()
{
    CFxOrderDetail obj( show_map );
    obj.exec();
}

CFxOrderList::~CFxOrderList()
{
}

