#include "Include/App.h"

int main()
{
    // Create a new instance of the application
    Chessie::Application* app = new Chessie::Application();

    // Run the application
    app->Run();

    // Delete the application
    delete app;

    return NULL;
}