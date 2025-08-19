//----------------
//  Justin Perez
//  7-1
//----------------

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct Course {
    std::string code;                  // course code
    std::string title;                 // course title
    std::vector<std::string> prerequisites;  // list of prerequisites
};

// Forward declarations
void displayCourse(const Course& course);
void loadCourses(const std::string& csvFile, class CourseTree* tree);
std::vector<std::string> splitCSVLine(const std::string& line);
void toUpperCase(std::string& text);

// Custom Binary Search Tree for courses
class CourseTree {
private:
    struct Node {
        Course data;
        Node* left;
        Node* right;

        Node() : left(nullptr), right(nullptr) {}
        Node(const Course& course) : data(course), left(nullptr), right(nullptr) {}
    };
    Node* root;

    void inOrder(Node* node) const {
        if (!node) return;
        inOrder(node->left);
        std::cout << node->data.code << ", " << node->data.title << std::endl;
        inOrder(node->right);
    }

// Binary Search Tree
public:
    CourseTree() : root(nullptr) {}

    void addCourse(const Course& course) {
        if (!root) { root = new Node(course); return; }
        Node* current = root;
        while (current) {
            if (course.code < current->data.code) {
                if (!current->left) { current->left = new Node(course); return; }
                current = current->left;
            }
            else {
                if (!current->right) { current->right = new Node(course); return; }
                current = current->right;
            }
        }
    }

    void displayInOrder() const { inOrder(root); }

    Course findCourse(const std::string& courseCode) const {
        Node* current = root;
        while (current) {
            if (current->data.code == courseCode) return current->data;
            current = (courseCode < current->data.code) ? current->left : current->right;
        }
        return Course(); // Not found
    }
};

// Split CSV Line into Tokens
std::vector<std::string> splitCSVLine(const std::string& line) {
    std::vector<std::string> tokens;
    std::string temp;
    for (char ch : line + ',') { 
        if (ch == ',') {
            tokens.push_back(temp);
            temp.clear();
        }
        else temp += ch;
    }
    return tokens;
}


// Load courses from CSV into the tree
void loadCourses(const std::string& csvFile, CourseTree* tree) {
    std::ifstream file(csvFile);
    if (!file.is_open()) { std::cout << "Error: Could Not Open File " << csvFile << std::endl; return; }
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        auto tokens = splitCSVLine(line);
        if (tokens.size() < 2) { std::cout << "Warning!!! Skipping Bad Line" << std::endl; continue; }
        Course course;
        course.code = tokens[0];
        course.title = tokens[1];
        for (size_t i = 2; i < tokens.size(); ++i) course.prerequisites.push_back(tokens[i]);
        tree->addCourse(course);
    }
    std::cout << "Data loaded successfully from " << csvFile << "!" << std::endl;
}

// Display Course Details
void displayCourse(const Course& course) {
    std::cout << course.code << ", " << course.title << std::endl;

    // Only show prerequisites if they exist
    //TODO: Fix order in CSV 
    if (!course.prerequisites.empty()) {
        std::cout << "Prerequisites: ";
        for (size_t i = 0; i < course.prerequisites.size(); ++i) {
            std::cout << course.prerequisites[i];
            if (i + 1 < course.prerequisites.size()) std::cout << ", ";
        }
        std::cout << std::endl;
    }
}

// Convert string to uppercase
void toUpperCase(std::string& text) {
    for (char& ch : text) if (isalpha(ch)) ch = toupper(ch);
}

// Main
int main() {
    CourseTree* myCourseTree = new CourseTree();
    Course selectedCourse;
    int menuChoice = 0;
    bool dataLoaded = false;

    std::cout << "Welcome To The Course Planner." << std::endl;

    while (menuChoice != 9) {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "  1. Load Courses from File" << std::endl;
        std::cout << "  2. Print Course List" << std::endl;
        std::cout << "  3. Print Course" << std::endl;
        std::cout << "  9. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> menuChoice;

        switch (menuChoice) {
        case 1: {
            std::string fileInput;
            std::cout << "Enter CSV file name (HINT: with .csv extension): ";
            std::cin >> fileInput;
            loadCourses(fileInput, myCourseTree);
            dataLoaded = true;
            break;
        }

        case 2:
            if (dataLoaded) myCourseTree->displayInOrder();
            else std::cout << "Please Load Data First. (HINT: Select Load Course From File)." << std::endl;
            break;

        case 3:
            if (dataLoaded) {
                std::string courseKey;
                std::cout << "What Course Do You Want To Know About? ";
                std::cin >> courseKey;
                toUpperCase(courseKey);
                selectedCourse = myCourseTree->findCourse(courseKey);
                if (!selectedCourse.code.empty()) displayCourse(selectedCourse);
                else std::cout << "Course not found." << std::endl;
            }
            else std::cout << "Please Load A Data First. (HINT: Select Load Course From File)." << std::endl;
            break;

        case 9:
            std::cout << "Thank You For Using Course Planner!" << std::endl;
            break;

        default:
            std::cout << menuChoice << " Is Not A Valid Option." << std::endl;
            break;
        }
    }

    return 0;
}
