#include <iostream>
#include <string>

struct LinkedQuestion{
    
    struct LinkedAnswer{
        char letter;
        std::string answerContent;
        bool correctAnswer;
        LinkedAnswer *prevChoice;
    };

    // Correct Answers
    bool isTrue;
    std::string targetWord;
    char correctLetter;
    /*
        BIG QUESTION:
        Should every question have every answer type?
            meaning -
            A T/F question has a linkedanswer list, but never calls itf
            A MCQ has a "true/false" answer, but the program looks for linkedanswer based on qType
        yeah, we can check qType first and then only look at relevant fields to keep the linked list simple.
    */
    enum QuestionType{
        TFQ,
        MCQ,
        WRQ
    };
    
    // Question parameters
    std::string questionContent;
    QuestionType questionType;
    double pointValue;

    // Not implemented

    // Student Progress
    bool isAnswered = false;
    std::string studentAnswer;

    // Linked List Pointers
    LinkedQuestion *nextQuestion = nullptr;
    LinkedAnswer *lastAnswer = nullptr;

    void generateAnswer(){
        if (questionType == MCQ) {
            std::cout << "Select correct answer: ";
            std::cin >> correctLetter;
            correctLetter = toupper(correctLetter);

            LinkedAnswer* curr = lastAnswer;
            while (curr != nullptr) {
                if (curr->letter == correctLetter) {
                    curr->correctAnswer = true;
                } 
                else {
                    curr->correctAnswer = false;
                }
                curr = curr->prevChoice;
            }
        }
        else if (questionType == TFQ) {
            std::string input;
            std::cout << "Select correct answer: ";
            std::cin >> input;
            while (input != "true" && input != "false") {
                std::cout << "[Answer not recognized, please try again!]\n";
                std::cout << "Select correct answer: ";
                std::cin >> input;
            }
            isTrue = (input == "true");
        }
        else if (questionType == WRQ) {
            std::cout << "Type correct answer: ";
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, targetWord);
        }
    }
};
