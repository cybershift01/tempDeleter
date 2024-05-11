#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

static void deleteFolderContents(const std::string& folderPath) {
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        try {
            if (fs::is_directory(entry.path())) {
                fs::remove_all(entry.path());
            }
            else {
                fs::remove(entry.path()); 
            }
            std::cout << "Deleted: " << entry.path() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error deleting: " << entry.path() << " - " << e.what() << std::endl;
        }
    }
}

int main() {
    std::string folderPath = "C:\\Users\\$user$\\AppData\\Local\\Temp";
    std::string folderPath2 = "C:\\Windows\\Temp";
    try {
        deleteFolderContents(folderPath);
        deleteFolderContents(folderPath2);
        std::cout << "Folder contents deleted successfully." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cin.get();
        return 1;
    }

    std::cin.get();

    return 0;
}
