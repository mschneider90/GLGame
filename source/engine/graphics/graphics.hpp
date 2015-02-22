#include <utility> // std::pair
#include <string>

class GLFWwindow;

class Graphics
{
public:
    Graphics();
    ~Graphics();

    void openWindow(const std::string& title, const std::pair<int, int>& resolution);
    void closeWindow();
private:
    GLFWwindow* window;
};
