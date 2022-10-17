#include <gui/BallisticsApp.hpp>
#include <gui/MainWindow.hpp>

bool BallisticsApp::OnInit()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->Show(true);
    return true;
}
