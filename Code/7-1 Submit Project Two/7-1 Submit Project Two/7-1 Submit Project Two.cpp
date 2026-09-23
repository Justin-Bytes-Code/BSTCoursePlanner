//----------------
//  Justin Perez
//  7-1
//----------------

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

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

        std::cout << node->data.code << ", "
            << node->data.title << std::endl;

        inOrder(node->right);
    }

    // Save the tree back into the CSV file
    void saveInOrder(Node* node, std::ofstream& file) const {
        if (!node) return;

        saveInOrder(node->left, file);

        file << node->data.code << ","
            << node->data.title;

        for (const std::string& prerequisite : node->data.prerequisites) {
            file << "," << prerequisite;
        }

        file << std::endl;

        saveInOrder(node->right, file);
    }

    // Find the smallest node in a subtree
    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }

        return node;
    }

    // Delete a course from the BST
    Node* deleteNode(Node* node, const std::string& courseCode) {
        if (!node) {
            return nullptr;
        }

        // Search the left side
        if (courseCode < node->data.code) {
            node->left = deleteNode(node->left, courseCode);
        }

        // Search the right side
        else if (courseCode > node->data.code) {
            node->right = deleteNode(node->right, courseCode);
        }

        // Course found
        else {

            // Node has no children
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }

            // Node only has a right child
            else if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // Node only has a left child
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node has two children
            else {
                Node* temp = findMin(node->right);

                node->data = temp->data;

                node->right =
                    deleteNode(node->right, temp->data.code);
            }
        }

        return node;
    }

    // Binary Search Tree
public:
    CourseTree() : root(nullptr) {}

    void addCourse(const Course& course) {
        if (!root) {
            root = new Node(course);
            return;
        }

        Node* current = root;

        while (current) {
            if (course.code < current->data.code) {
                if (!current->left) {
                    current->left = new Node(course);
                    return;
                }

                current = current->left;
            }
            else {
                if (!current->right) {
                    current->right = new Node(course);
                    return;
                }

                current = current->right;
            }
        }
    }

    void displayInOrder() const {
        inOrder(root);
    }

    Course findCourse(const std::string& courseCode) const {
        Node* current = root;

        while (current) {
            if (current->data.code == courseCode)
                return current->data;

            current = (courseCode < current->data.code)
                ? current->left
                : current->right;
        }

        return Course(); // Not found
    }

    // Delete a course from the tree
    bool deleteCourse(const std::string& courseCode) {
        if (findCourse(courseCode).code.empty()) {
            return false;
        }

        root = deleteNode(root, courseCode);
        return true;
    }

    // Save the entire tree back to the CSV file
    void saveToFile(const std::string& fileName) const {
        std::ofstream file(fileName);

        if (!file.is_open()) {
            std::cout << "Error: Could Not Open File "
                << fileName << std::endl;
            return;
        }

        saveInOrder(root, file);

        file.close();

        std::cout << "File updated successfully!"
            << std::endl;
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
        else {
            temp += ch;
        }
    }

    return tokens;
}


// Load courses from CSV into the tree
void loadCourses(const std::string& csvFile, CourseTree* tree) {
    std::ifstream file(csvFile);

    if (!file.is_open()) {
        std::cout << "Error: Could Not Open File "
            << csvFile << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        auto tokens = splitCSVLine(line);

        if (tokens.size() < 2) {
            std::cout << "Warning!!! Skipping Bad Line"
                << std::endl;
            continue;
        }

        Course course;

        course.code = tokens[0];
        course.title = tokens[1];

        for (size_t i = 2; i < tokens.size(); ++i) {
            course.prerequisites.push_back(tokens[i]);
        }

        tree->addCourse(course);
    }

    std::cout << "Data loaded successfully from "
        << csvFile << "!" << std::endl;
}


// Display Course Details
void displayCourse(const Course& course) {
    std::cout << course.code << ", "
        << course.title << std::endl;

    if (!course.prerequisites.empty()) {
        std::cout << "Prerequisites: ";

        for (size_t i = 0; i < course.prerequisites.size(); ++i) {
            std::cout << course.prerequisites[i];

            if (i + 1 < course.prerequisites.size())
                std::cout << ", ";
        }

        std::cout << std::endl;
    }
}


// Convert string to uppercase
void toUpperCase(std::string& text) {
    for (char& ch : text) {
        if (isalpha(ch))
            ch = toupper(ch);
    }
}


// Main
int main() {

    CourseTree* myCourseTree = new CourseTree();

    Course selectedCourse;

    int menuChoice = 0;
    bool dataLoaded = false;
    std::string currentFile;

    std::cout << "Welcome To The Course Planner."
        << std::endl;

    while (menuChoice != 9) {

        std::cout << "\nMenu:" << std::endl;
        std::cout << "  1. Load Courses from File" << std::endl;
        std::cout << "  2. Print Course List" << std::endl;
        std::cout << "  3. Print Course" << std::endl;
        std::cout << "  4. Add Course" << std::endl;
        std::cout << "  5. Delete Course" << std::endl;
        std::cout << "  9. Exit" << std::endl;

        std::cout << "Enter choice: ";
        std::cin >> menuChoice;


        switch (menuChoice) {

        case 1: {
            std::cout << "Enter CSV file name "
                << "(HINT: with .csv extension): ";

            std::cin >> currentFile;

            loadCourses(currentFile, myCourseTree);

            dataLoaded = true;

            break;
        }


        case 2:

            if (dataLoaded)
                myCourseTree->displayInOrder();

            else
                std::cout << "Please Load Data First. "
                << "(HINT: Select Load Course From File)."
                << std::endl;

            break;


        case 3:

            if (dataLoaded) {

                std::string courseKey;

                std::cout << "What Course Do You Want "
                    << "To Know About? ";

                std::cin >> courseKey;

                toUpperCase(courseKey);

                selectedCourse =
                    myCourseTree->findCourse(courseKey);

                if (!selectedCourse.code.empty())
                    displayCourse(selectedCourse);

                else
                    std::cout << "Course not found."
                    << std::endl;
            }

            else {
                std::cout << "Please Load A Data First. "
                    << "(HINT: Select Load Course From File)."
                    << std::endl;
            }

            break;


        case 4:

            if (dataLoaded) {

                Course newCourse;

                std::cout << "Enter Course Code: ";
                std::cin >> newCourse.code;

                toUpperCase(newCourse.code);

                std::cin.ignore();

                std::cout << "Enter Course Title: ";
                std::getline(std::cin, newCourse.title);

                int prerequisiteCount;

                std::cout << "How many prerequisites? ";
                std::cin >> prerequisiteCount;

                for (int i = 0; i < prerequisiteCount; ++i) {

                    std::string prerequisite;

                    std::cout << "Enter prerequisite "
                        << i + 1 << ": ";

                    std::cin >> prerequisite;

                    toUpperCase(prerequisite);

                    newCourse.prerequisites.push_back(
                        prerequisite);
                }

                // Add the new course to the BST
                myCourseTree->addCourse(newCourse);
                myCourseTree->saveToFile(currentFile);
            }

            else {

                std::cout << "Please Load Data First. "
                    << "(HINT: Select Load Course From File)."
                    << std::endl;
            }

            break;


        case 5:

            if (dataLoaded) {

                std::string courseKey;

                std::cout << "Enter Course Code "
                    << "to Delete: ";

                std::cin >> courseKey;

                toUpperCase(courseKey);

                // Delete the course from the BST
                if (myCourseTree->deleteCourse(courseKey)) {

                    // Save the updated BST back to
                    // the same CSV file
                    myCourseTree->saveToFile(currentFile);

                    std::cout << courseKey
                        << " was deleted successfully."
                        << std::endl;
                }

                else {

                    std::cout << "Course "
                        << courseKey
                        << " was not found."
                        << std::endl;
                }
            }

            else {

                std::cout << "Please Load Data First. "
                    << "(HINT: Select Load Course From File)."
                    << std::endl;
            }

            break;


        case 9:

            std::cout << "Thank You For Using "
                << "Course Planner!"
                << std::endl;

            break;


        default:

            std::cout << menuChoice
                << " Is Not A Valid Option."
                << std::endl;

            break;
        }
    }

    return 0;
}