#include "engine.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	dsaProj::engine frm;
	Application::Run(% frm);
}

// next, prev, history, [max 5 open tabs], search

#include <string>

//int main() {
//    // Define the file name
//    std::string filename = "example.txt";
//    
//    // Create an ifstream object
//    std::ifstream inputFile(filename);
//    
//    // Check if the file is open
//    if (!inputFile.is_open()) {
//        std::cerr << "Failed to open the file: " << filename << std::endl;
//        return 1; // Return an error code
//    }
//    
//    // Read the file line by line
//    std::string line;
//    while (std::getline(inputFile, line)) {
//        // Output the line to the console
//        std::cout << line << std::endl;
//    }
//    
//    // Close the file
//    inputFile.close();
//    
//    return 0; // Indicate successful completion
//}