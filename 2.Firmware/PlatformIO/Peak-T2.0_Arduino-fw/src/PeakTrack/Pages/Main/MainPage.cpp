#include "MainPage.h"

MainModel mainModel;


/* Page update timer */
void Timer_Update_Page(lv_timer_t * timer)
{  
    mainModel.UpdateData();
    mainModel.UpdateView();
}


void PageMain_init()
{
    ui_init();
    mainModel.IndevSetup();
    mainModel.Init();

    lv_timer_create(Timer_Update_Page, 500, NULL);
}
